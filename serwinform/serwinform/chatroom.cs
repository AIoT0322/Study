using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace serwinform
{
    public class chatroom
    {
        public string RoomId { get; private set; } // 채팅방 고유 식별자
        public List<ClientInfo> Clients { get; private set; } // 현재 참여 중인 클라이언트 목록
        public List<string> Messages { get; private set; } // 채팅 메시지 목록

        public chatroom(string roomId) // 생성자: 채팅방을 초기화하고 고유한 RoomId를 설정
        {
            RoomId = roomId;
            Clients = new List<ClientInfo>();
            Messages = new List<string>();
        }

        public void AddClient(ClientInfo client) // 클라이언트를 채팅방에 추가
        {
            Clients.Add(client);
        }

        public void RemoveClient(ClientInfo client) // 클라이언트를 채팅방에서 제거
        {
            Clients.Remove(client);
        }

        public void SendMessage(string message, ClientInfo sender) // 채팅 메시지를 전송하고 Messages 목록에 추가
        {
            string formattedMessage = $"{sender.Name}: {message}";
            Messages.Add(formattedMessage);
        }
    }
}