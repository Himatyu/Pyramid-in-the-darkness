using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ScriptableObjectEditor
{
    public class TabBase
    {
        public TabBase(Main _main)
        {
            m_Main = _main;
        }
        public Main m_Main = null;
    }
}
