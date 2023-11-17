using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;

namespace serwinform
{
    public class ClientInfo
    {
        public TcpClient ClientSocket { get; set; }
        public string Name { get; set; }
    }
}
