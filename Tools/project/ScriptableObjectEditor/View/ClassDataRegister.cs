using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.View
{
    /// <summary>
    /// イベントをModelに投げる
    /// </summary>
    public class ClassDataRegister 
    {
        public ClassDataRegister(Control.ClassDataRegister _control)
        {
            m_Control = _control;

            var view = m_Control.m_Main.ClassStructVeiw;
            view.Clear();

            view.FullRowSelect = true;
            view.GridLines = true;
            view.Sorting = SortOrder.Ascending;
            view.View = System.Windows.Forms.View.Details;

            view.Columns.Clear();
            var chType = new ColumnHeader();
            chType.Text = "型名";
            chType.Width = 400;
            var chName = new ColumnHeader();
            chName.Text = "メンバ名";
            chName.Width = 400;
            ColumnHeader[] colHeaderRegValue = { chType, chName };
            view.Columns.AddRange(colHeaderRegValue);
        }

        #region events

        public void SelectOfClass()
        {
            isSelected = true;
            m_Control.EventOfSelect();
        }

        public void AcceptOfRegister()
        {
            if (!isSelected)
            {
                return;
            }
            m_Control.EventOfAccept();
            isSelected = false;
        }
        #endregion
        
        public void UpdataSelectClassName(string _name)
        {
            m_Control.m_Main.SelectClassName.Text = _name;
        }

        public void UpdataClassStructVeiw(List<Tuple<string,string>> _list)
        {
            var view = m_Control.m_Main.ClassStructVeiw;

            view.Items.Clear();
            foreach (var _ in _list)
            {
                string[] item = { _.Item1, _.Item2 };
                view.Items.Add(new ListViewItem(item));
            }
        }

        private bool isSelected = false;
        Control.ClassDataRegister m_Control;
    }
}
