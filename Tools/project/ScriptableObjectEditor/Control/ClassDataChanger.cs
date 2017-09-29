using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.Control
{
    public class ClassDataChanger : TabBase
    {
        View.ClassDataChanger m_View;
        public View.ClassDataChanger View { get { return m_View; } }

        Model.ClassDataChanger m_Model;
        public Model.ClassDataChanger Model { get { return m_Model; } }

        public ClassDataChanger(Main _main) : base(_main)
        {
            m_View = new View.ClassDataChanger(this);
            m_Model = new Model.ClassDataChanger(this);
        }
        
        public void SelectOfModifyFile()
        {
            m_Model.SelectOfModifyFile();
            m_View.UpdataOfSelectFileLabel();
        }

        public void SelectOdRegistedClass()
        {

        }

        public void SelectOfClassMenber()
        {

        }

        public void AcceptOfUpdata()
        {
            m_Model.AcceptOfUpdata();
        }
    }
}
