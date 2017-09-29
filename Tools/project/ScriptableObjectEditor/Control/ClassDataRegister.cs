using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.Control
{
    public class ClassDataRegister : TabBase
    {
        public ClassDataRegister(Main _main) : base(_main) 
        {
            m_View = new View.ClassDataRegister(this);
            m_Model = new Model.ClassDataRegister(this);
        }

        #region events

        public void EventOfSelect()
        {
            m_Model.ViewDataUpdata();
        }

        public void EventOfAccept()
        {
            m_Model.RegisterOfClassData();
        }

        #endregion


        View.ClassDataRegister m_View;
        public View.ClassDataRegister View
        {
            get { return m_View; }
        }

        Model.ClassDataRegister m_Model;
        public Model.ClassDataRegister Model
        {
            get { return m_Model; }
        }
    }
}
