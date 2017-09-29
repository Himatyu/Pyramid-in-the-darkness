using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
            var center = Model.ClassDataCenter.Instance;
            m_ControlOfRegister = new Control.ClassDataRegister(this);
            m_ControlOfCreater = new Control.ClassDataCreater(this);
            m_ClassDataChanger = new Control.ClassDataChanger(this);
        }

        Control.ClassDataRegister m_ControlOfRegister;
        Control.ClassDataCreater m_ControlOfCreater;
        Control.ClassDataChanger m_ClassDataChanger;
        public Control.ClassDataRegister dataRegister{ get{ return m_ControlOfRegister; } }
        public Control.ClassDataCreater dataCreater { get { return m_ControlOfCreater; } }
        public Control.ClassDataChanger dataChanger { get { return m_ClassDataChanger; } }

#region Register

//Register
private void RegistClassSelectButton_Click(object sender, EventArgs e)
        {    
            m_ControlOfRegister.View.SelectOfClass();
        }

        private void RegisterAccept_Click(object sender, EventArgs e)
        {
            m_ControlOfRegister.View.AcceptOfRegister();
        }
        #endregion

        #region Create

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_ControlOfCreater.View.SelectOfRegistedClass();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_ControlOfCreater.View.SelectOfRegistedClass();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void ClassMenberSelect_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_ControlOfCreater.View.SelectOfClassMenber();
        }

        private void CreateAccept_Click(object sender, EventArgs e)
        {
            m_ControlOfCreater.View.AcceptOfCreate();
        }

        #endregion

        private void ClassStructVeiw_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        #region Modify
        private void ClassMenberSelect_Modify_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_ClassDataChanger.View.SelectOfClassMenber();
        }

        private void ModifySelect_Click(object sender, EventArgs e)
        {
            m_ClassDataChanger.SelectOfModifyFile();
        }

        private void RegistedClassSelect_Modify_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_ClassDataChanger.View.SelectOfRegistedClass();
            m_ClassDataChanger.Model.SelectOfRegistedClass();
        }

        private void ModifyAccept_Click(object sender, EventArgs e)
        {
            m_ClassDataChanger.AcceptOfUpdata();
        }
        #endregion

        private void ValueData_Modify_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            m_ClassDataChanger.View.SaveOfClassMenber();
        }

        private void ValueData_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            m_ControlOfCreater.View.SaveOfClassMenber();

        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_ControlOfCreater.View.UpdataRegistedClassMenberView();
            m_ClassDataChanger.View.UpdataRegistedClassMenberView();
        }
    }
}
