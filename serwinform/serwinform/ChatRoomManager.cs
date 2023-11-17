using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace serwinform
{
    public class ChatRoomManager
    {
        private List<chatroom> chatRooms = new List<chatroom>(); // 모든 채팅방 목록

        public void CreateChatRoom(string roomId) // 채팅방을 생성하고 chatRooms 목록에 추가
        {
            chatroom chatRoom = new chatroom(roomId);
            chatRooms.Add(chatRoom);
        }

        public chatroom GetChatRoom(string roomId) // 특정 RoomId에 해당하는 채팅방을 가져옴
        {
            return chatRooms.Find(room => room.RoomId == roomId);
        }

        public List<chatroom> GetAllChatRooms() // 모든 채팅방 목록을 가져옴
        {
            return chatRooms;
        }
    }
}
