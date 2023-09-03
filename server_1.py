import socket
import threading


PORT = 9999
BUF_SIZE = 1024
lock = threading.Lock()
clnt_data = []  # 접속한 클라이언트 정보 대입
clnt_cnt = 0  # 접속한 클라이언트 수
chat = 1      # 채팅방 번호
your_num = -1
my_num = -1

def handle_clnt(clnt_sock):
    lock.acquire()
    for i in range(0, clnt_cnt):  # 연결된 클라이언트가 몇 번째로 연결된 클라이언트인지 찾기
        if clnt_data[i][0] == clnt_sock:
            clnt_num = i
            break
    lock.release()


    while True:
        clnt_msg = clnt_sock.recv(BUF_SIZE)

        if not clnt_msg:  # 받은 메시지 없으면 소켓 닫기
            print("client socket close")
            break

        clnt_msg = clnt_msg.decode()
        print("받은메세지 :" + clnt_msg)

        if clnt_msg.startswith('signup/'):  # 수신메시지에 따라 기능 수행
            clnt_msg = clnt_msg.replace('signup/', '')
            signup(clnt_msg)
        elif clnt_msg.startswith('login/'):
            clnt_msg = clnt_msg.replace('login/', '')
            login(clnt_num, clnt_msg)
        elif clnt_msg.startswith('idcheck/'):
            clnt_msg = clnt_msg.replace('idcheck/', '')
            idcheck(clnt_msg)
        elif clnt_msg.startswith('chat/'):
            chatting(clnt_msg)
        elif clnt_msg.startswith('invite/'):
            clnt_msg = clnt_msg.replace('invite/', '')
            invite(clnt_num, clnt_msg)
        elif your_num >= 0:
            acceptance(clnt_msg)
        else:
            continue

def signup(clnt_msg):
    print("id/pw/name: ", clnt_msg)

    lock.acquire()
    f = open("user.txt", 'a', encoding='UTF8')
    data = f'{clnt_msg}\n'
    f.write(data)
    f.close()
    lock.release()

def idcheck(clnt_msg):
    f = open("user.txt", 'r', encoding='UTF8')
    line = f.read()
    f.close()

    if clnt_msg == '':  # 입력값 없으면
        clnt_sock.send('null'.encode())
    elif line.find(clnt_msg) == -1:  # 같은 아이디 없으면
        clnt_sock.send('!OK'.encode())
    else:
        clnt_sock.send('NO'.encode())

def login(clnt_num, clnt_msg):
    clnt_sock = clnt_data[clnt_num][0]
    # login/member/id/pw
    input_data = clnt_msg.split('/')
    input_id = input_data[0]
    input_pw = input_data[1]
    f = open("user.txt", 'r', encoding='UTF8')
    data = f.readlines()
    f.close()

    user_data = {}
    user_names = ''

    if clnt_msg == '/':  # 입력값 없으면
        clnt_sock.send('null'.encode())

    for line in data:
        parts = line.strip().split('/')  # 파일에서 각 항목을 추출
        if len(parts) == 3:
            stored_id, stored_pw, stored_name = parts  # 각 항목을 아이디, 비밀번호, 이름으로 분할
            user_data[stored_id] = [stored_pw, stored_name]
            user_names += (user_data[stored_id][1] + '/')

    if input_id in list(user_data.keys()):
        if user_data[input_id][0] == input_pw:  # ID와 PW일치하면
            clnt_sock.send('!OK'.encode())
            name = user_data[input_id][1]
            clnt_data[clnt_num].append(name)  # 클라이언트의 이름 추가
            clnt_sock.send(name.encode())
            names = user_names[:-1]
            info_name = clnt_sock.recv(BUF_SIZE)
            info_name = info_name.decode()
            if 'getnames' in info_name:
                clnt_sock.send(names.encode())
        else:
            clnt_sock.send('not'.encode())  # 불일치하면
    else:
        clnt_sock.send('none'.encode())

def chatting(clnt_msg):
    sender_name = clnt_msg.split('/')[1]
    message = clnt_msg.split('/')[2]  # 메시지를 가져옴

    f = open("chat.txt", 'a', encoding='UTF8') # 채팅 내용 저장
    chat_data = f'{sender_name}:{message}\n'
    f.write(chat_data)
    f.close()

    print("채팅내용:", message)

    for i in range(clnt_cnt):
            clnt_data[i][0].send(f'chat/{sender_name}/{message}'.encode())

def invite(clnt_num, clnt_msg):
    global your_num
    global my_num
    name = clnt_msg
    for i in range(0, clnt_cnt):
        if clnt_data[i][1] == name: #your_name
            clnt_data[i][0].send('채팅 초대'.encode())
            your_num = i
            my_num = clnt_num
            break

def acceptance(clnt_msg):
    global chat, my_num, your_num
    print(clnt_msg)
    #채팅초대 받았을 때 답변 yes면
    if clnt_msg == 'yes':
        clnt_data[my_num][0].send('수락'.encode())
        # clnt_data[my_num][2] = chat
        # clnt_data[your_num][2] = chat
        # chat += 1
    else:
        clnt_data[my_num][0].send('거절'.encode())

    my_num = -1
    your_num = -1


if __name__ == '__main__':
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(('', PORT))
    sock.listen(5)

    while True:
        clnt_sock, addr = sock.accept()

        lock.acquire()
        clnt_data.insert(clnt_cnt, [clnt_sock])
        clnt_cnt += 1
        lock.release()
        thread = threading.Thread(target=handle_clnt, args=(clnt_sock,))
        thread.start()
