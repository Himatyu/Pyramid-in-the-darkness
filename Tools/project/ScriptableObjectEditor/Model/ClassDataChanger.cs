using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.Model
{
    using ClassData =
        Tuple<string, int, List<Tuple<string, List<string>>>>;

    public class ClassDataChanger
    {
        Control.ClassDataChanger m_Control = null;
        string m_SelectFilePass = null;
        public bool IsSelectClass= false;

        public string SelectFilePass { get { return m_SelectFilePass; } }

        public ClassDataChanger(Control.ClassDataChanger _cont)
        {
            m_Control = _cont;
        }

        public void SelectOfModifyFile()
        {
            var ofd = new OpenFileDialog();
            ofd.FileName = "default.dat";
            ofd.InitialDirectory = @"C:\Users\HimaJin\Documents\Pyramid";
            ofd.Filter = ".datファイル(*.dat)|*.dat";
            ofd.FilterIndex = 2;
            ofd.Title = "開くファイルを選択してください";
            ofd.RestoreDirectory = true;
            ofd.CheckFileExists = true;
            ofd.CheckPathExists = true;

            if (ofd.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            m_SelectFilePass = ofd.FileName;
            ReflectForDataCenter();
        }

        public void SelectOfRegistedClass()
        {
            IsSelectClass = true;
            ReflectForDataCenter();
        }

        public void SelectOfClassMenber()
        {

        }

        public void AcceptOfUpdata()
        {
            var dataCenter = ClassDataCenter.Instance;
            var selectClass =
                (string)m_Control.m_Main.RegistedClassSelect_Modify.SelectedItem;
            if(selectClass == null)
            {
                return;
            }
            var data = dataCenter.ValueData.Find(_ => _.Item1 == selectClass);
            m_Control.m_Main.dataCreater.View.CreateData(data,m_SelectFilePass);


        }

        void ReflectForDataCenter()
        {
            if(m_SelectFilePass == null ||
                m_Control.m_Main.RegistedClassSelect_Modify.SelectedItem == null)
            {
                return;
            }

            var dataCenter = ClassDataCenter.Instance;
            var selectClass = 
                (string)m_Control.m_Main.RegistedClassSelect_Modify.SelectedItem;
            var data = dataCenter.ValueData.Find(_=>_.Item1== selectClass);

            var typeCenter = TypeCenter.Instance;
            using (Stream stream = File.OpenRead(m_SelectFilePass))
            {
                using (BinaryReader reader = new BinaryReader(stream))
                {
                    foreach(var menber in data.Item3)
                    {
                        var splieted = menber.Item1.Split(' ')[0];
                        var menberTypes = typeCenter.FindByTypeName(splieted);
                        var menberValus = menber.Item2;

                        for (int i=0;i< menberTypes.Count;i++)
                        {
                            switch (menberTypes[i])
                            {
                                case "char":   menberValus[i] = reader.ReadChar().ToString();  break;
                                case "bool":   menberValus[i] = reader.ReadBoolean().ToString();  break;
                                case "int":    menberValus[i] = reader.ReadInt32().ToString();  break;
                                case "float":  menberValus[i] = reader.ReadSingle().ToString();  break;
                                case "long":   menberValus[i] = reader.ReadInt32().ToString();  break;//C++はlongが4バイト
                                case "double": menberValus[i] = reader.ReadDouble().ToString();  break;

                            }
                        }
                    }
                }
            }
            dataCenter.NotifyToReceivers();
        }
    }
}
