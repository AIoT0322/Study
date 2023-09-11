using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace form2
{
    public class ValueModelColloction : IEnumerable<ValueModel> //이 클래스로 이루어진 배열
    {
        private List<ValueModel> _items = new List<ValueModel>();

        public int Count => _items.Count;

        public ValueModel this[int i] => _items[i];

        public IEnumerator<ValueModel> GetEnumerator() //foreach문에서 돌릴 때 쓰는 함수 
        {
            return _items.GetEnumerator();  //위의 리스트를 그대로 가져다 쓰겠다는 것
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return _items.GetEnumerator();
        }

        public void Add(ValueModel valueModel)
        {
            if (valueModel == null) return;
            if (_items.Contains(valueModel)) return;

            _items.Add(valueModel);
        }

        public void Remove(ValueModel valueModel)
        {
            if (valueModel == null) return;
            if (!_items.Contains(valueModel)) return;

            _items.Remove(valueModel);
        }
    }
}
