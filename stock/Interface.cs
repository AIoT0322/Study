using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace stock
{
    interface Interface
    {
        //상품 등록 함수 실행
        void RegisterItem(string code, string name, int cost, int price, string category);
    }
}
