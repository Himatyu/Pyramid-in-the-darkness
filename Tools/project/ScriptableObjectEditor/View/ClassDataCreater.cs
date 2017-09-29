using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.View
{
    using ClassData =
    Tuple<string, int, List<Tuple<string, List<string>>>>;

    public class ClassDataCreater : IReceiveNoticeOfChangeData
    {
        public ClassDataCreater(Control.ClassDataCreater _control)
        {
            m_Control = _control;

            UpdataRegistedClassMenberView();
            SelectOfClassMenber();
            SelectOfRegistedClass();
            ScriptableObjectEditor
                .Model
                .ClassDataCenter
                .Instance
                .RegisterOfReceiver(this);
        }

        public void SelectOfRegistedClass()
        {
            string fileName = 
                (string)m_Control.m_Main.RegistedClassSelect.SelectedItem;

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

        /// <summary>
        /// GridViewを取得しデータの更新をする
        /// </summary>
        public void SelectOfClassMenber()
        {
            if (null != CechOfSelectString)
            {
                SaveOfClassMenber();
            }

            string selectMenberString =
                (string)m_Control.m_Main.ClassMenberSelect.SelectedItem;

            if (null == selectMenberString)
            {
                return;
            }

            var grid = m_Control.m_Main.ValueData;
            grid.Rows.Clear();

            var ins = TypeCenter.Instance;
            var typeList = ins.FindByTypeName(selectMenberString.Split(' ')[0]);

            if (typeList == null)
            {
                grid.Rows.Add("未登録の型","");
                CechOfSelectString = null;
                return;
            }

            var valueIns = Model.ClassDataCenter.Instance.ValueData;
            var selectClass = (string)m_Control.m_Main.RegistedClassSelect.SelectedItem;
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

        public void SaveOfClassMenber()
        {
            var valueIns = Model.ClassDataCenter.Instance.ValueData;
            var selectClass = 
                (string)m_Control.m_Main.RegistedClassSelect.SelectedItem;
            var menberList = 
                valueIns.Find(_ => _.Item1 == selectClass).Item3;

            var grid = m_Control.m_Main.ValueData;

            var member = menberList.Where(_ => CechOfSelectString == _.Item1).First();
            //TODO valueListにグリッドのデータを挿入
            for (int i = 0;i< member.Item2.Count;i++)
            {
                member.Item2[i] = (string)grid[1, i].Value;
            }
        }

        public void AcceptOfCreate()
        {
            if (null != CechOfSelectString)
            {
                SaveOfClassMenber();
            }

            var selectdClassName =
                    (string)m_Control.m_Main.RegistedClassSelect.SelectedItem;

            var classData = Model.ClassDataCenter.Instance.ValueData;
            var classValue =
                classData.Find(_ => _.Item1 == selectdClassName);

            SaveFileDialog sfd = new SaveFileDialog();

            sfd.FileName = "ScriptableObject.dat";
            sfd.InitialDirectory = @"C:\";
            sfd.Filter = "バイナリ|.dat";
            sfd.FilterIndex = 2;
            sfd.Title = "保存先のファイルを選択してください";
            sfd.RestoreDirectory = true;
            sfd.OverwritePrompt = true;
            sfd.CheckPathExists = true;


            if (sfd.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            CreateData(classValue, sfd.FileName);
        }

        public void Receive()
        {
            SelectOfClassMenber();
        }

        public void CreateData(ClassData _data,string _pass)
        {

            FileStream fs = new FileStream(_pass, FileMode.Create);
            BinaryWriter bw = new BinaryWriter(fs);

            var classMenbers =_data.Item3;

            if (null == classMenbers)
            {
                return;
            }

            var typeCenter = TypeCenter.Instance;
            foreach (var _ in classMenbers)
            {
                var splited = _.Item1.Split(' ');
                var menberType = splited[0];
                var menberList =
                        typeCenter.FindByTypeName(menberType);

                if (_.Item2.Count != menberList.Count)
                {
                    return;
                }

                for (int i = 0; i < menberList.Count; i++)
                {
                    var type = menberList[i];
                    var value = _.Item2[i];

                    int size = -1;
                    switch (type)
                    {
                        case "char": size = 1; break;
                        case "bool": size = 1; break;
                        case "int": size = 4; break;
                        case "float": size = 4; break;
                        case "long": size = 4; break;
                        case "double": size = 8; break;
                    }
                    if (size == -1)
                    {
                        MessageBox.Show("未登録型の使用",
                        "エラー",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Error);
                        return;
                    }

                    switch (type)
                    {
                        case "char": bw.Write(byte.Parse(value)); break;
                        case "bool": bw.Write(byte.Parse(value)); break;
                        case "int": bw.Write(int.Parse(value)); break;
                        case "float": bw.Write(float.Parse(value)); break;
                        case "long": bw.Write(int.Parse(value)); break;//C++はlongが4バイト
                        case "double": bw.Write(double.Parse(value)); break;
                    }
                }
            }

            bw.Close();
            fs.Close();
        }

        public void UpdataRegistedClassMenberView()
        {
            var data =
                ScriptableObjectEditor.Model.ClassDataCenter.Instance.Struct;

            var registed = m_Control.m_Main.RegistedClassSelect;
            registed.Items.Clear();
            foreach (var _ in data)
            {
                registed.Items.Add(_.Item1);
            }
        }

        void UpdataClassMenberView(List<Tuple<string,string>> _list)
        {
            var view = m_Control.m_Main.ClassMenberSelect;
            view.Items.Clear();

            foreach (var _ in _list)
            {
                m_Control
                    .m_Main
                    .ClassMenberSelect
                    .Items.Add(_.Item1 + " " + _.Item2);
            }
        }

        Control.ClassDataCreater m_Control;
        string CechOfSelectString = null;
    }
}
