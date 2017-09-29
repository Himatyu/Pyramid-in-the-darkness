using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ScriptableObjectEditor.View
{
    public class ClassDataChanger : IReceiveNoticeOfChangeData
    {
        Control.ClassDataChanger m_Control = null;
        string CechOfSelectString = null;

        public ClassDataChanger(Control.ClassDataChanger _cont)
        {
            m_Control = _cont;

            UpdataRegistedClassMenberView();
            ScriptableObjectEditor
                .Model
                .ClassDataCenter
                .Instance
                .RegisterOfReceiver(this);
        }

        public void UpdataOfSelectFileLabel()
        {
            m_Control.m_Main.SelectModify.Text = 
                        m_Control.Model.SelectFilePass;
        }

        public void Receive()
        {

            SelectOfClassMenber();
        }

        public void SelectOfRegistedClass()
        {
            string fileName =
                (string)m_Control.m_Main.RegistedClassSelect_Modify.SelectedItem;

            if (null == fileName)
            {
                return;
            }
            var dataCenter =
                    ScriptableObjectEditor
                    .Model
                    .ClassDataCenter
                    .Instance
                    .Struct;
            var data = dataCenter
                .Where(_ => _.Item1 == fileName)
                .First();
            UpdataClassMenberView(data.Item3);
        }
        public void SelectOfClassMenber()
        {
            if (null != CechOfSelectString)
            {
                SaveOfClassMenber();
            }

            string selectMenberString =
                (string)m_Control.m_Main.ClassMenberSelect_Modify.SelectedItem;

            if (null == selectMenberString)
            {
                return;
            }

            var grid = m_Control.m_Main.ValueData_Modify;
            grid.Rows.Clear();

            var ins = TypeCenter.Instance;
            var typeList = ins.FindByTypeName(selectMenberString.Split(' ')[0]);

            if (typeList == null)
            {
                grid.Rows.Add("未登録の型", "");
                CechOfSelectString = null;
                return;
            }

            var valueIns = Model.ClassDataCenter.Instance.ValueData;
            var selectClass = (string)m_Control.m_Main.RegistedClassSelect_Modify.SelectedItem;
            var valueList = valueIns.Find(_ => _.Item1 == selectClass).Item3;

            var classData = valueIns.Where(_ => _.Item1 == selectClass).First();
            var menberData = classData.Item3.Where(_ => _.Item1 == selectMenberString).First();

            foreach (var _ in
                menberData.Item2.Select((v, i) => new { Index = i, Value = v }))
            {
                grid.Rows.Add(typeList[_.Index], _.Value);
            }

            CechOfSelectString = selectMenberString;
        }

        void UpdataClassValue(string _Classpass)
        {

        }

        public void SaveOfClassMenber()
        {
            var valueIns = Model.ClassDataCenter.Instance.ValueData;
            var selectClass =
                (string)m_Control.m_Main.RegistedClassSelect_Modify.SelectedItem;
            var menberList =
                valueIns.Find(_ => _.Item1 == selectClass).Item3;

            var grid = m_Control.m_Main.ValueData_Modify;

            var member = menberList.Where(_ => CechOfSelectString == _.Item1).First();
            //TODO valueListにグリッドのデータを挿入
            for (int i = 0; i < member.Item2.Count; i++)
            {
                member.Item2[i] = (string)grid[1, i].Value;
            }
        }

        public void UpdataRegistedClassMenberView()
        {
            var data =
                ScriptableObjectEditor.Model.ClassDataCenter.Instance.Struct;

            var registed = m_Control.m_Main.RegistedClassSelect_Modify;
            registed.Items.Clear();
            foreach (var _ in data)
            {
                registed.Items.Add(_.Item1);
            }
        }

        void UpdataClassMenberView(List<Tuple<string, string>> _list)
        {
            var view = m_Control.m_Main.ClassMenberSelect_Modify;
            view.Items.Clear();

            foreach (var _ in _list)
            {
                view.Items.Add(_.Item1 + " " + _.Item2);
            }
        }

    }
}
