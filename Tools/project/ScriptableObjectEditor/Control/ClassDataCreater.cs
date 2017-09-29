using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.Control
{
    public class ClassDataCreater : TabBase
    {
        public ClassDataCreater(Main _main) : base(_main)
        {
            m_View = new View.ClassDataCreater(this);
        }

        public void EventOfClassSelect()
        {
        }

        public void EventOfClassMenberSelect()
        {
        }

        public void EventOfMenberValueModify()
        {
        }

        Model.ClassDataCreater m_Model = new Model.ClassDataCreater();
        public Model.ClassDataCreater Model { get { return m_Model; } }

        View.ClassDataCreater  m_View ;
        public View.ClassDataCreater View { get { return m_View; } }
    }    
}
