using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace form2
{
    public class ValueModel
    {
        private int _value;

        /// <summary>
        /// 이름
        /// </summary>
        public string Name { get; set; }
        /// <summary>
        /// 값
        /// </summary>
        public int Value 
        {
            get
            {
                return _value;
            }
            set
            {
                LastValue = _value;
                _value = value;
            }
        }
    
        public int LastValue { get; private set; }

        /// <summary>
        /// 생성자
        /// </summary>
        /// <param name="name"></param>
        /// <param name="value"></param>
        public ValueModel(string name, int value)
        {
            Name = name;
            Value = value;
        }

        public override string ToString()
        {
            return $"{Name} : {Value}";
        }
    }
}
