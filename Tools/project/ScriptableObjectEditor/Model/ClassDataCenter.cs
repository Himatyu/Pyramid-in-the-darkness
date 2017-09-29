using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ScriptableObjectEditor.Model
{

    //ファイルパス、データ量、データリスト（型名：変数名）
    using ClassStruct = 
        Tuple<string, int, List<Tuple<string, string>>>;

    //ファイルパス、データ量、データリスト(データシグネチャ「メンバ型名”\n”変数名」:データリスト)
    using ClassData = 
        Tuple<string, int, List<Tuple<string,List< string>>>>;

    /// <summary>
    /// クラスデータを集積する
    /// RAII準拠
    /// </summary>
    class ClassDataCenter
    {
        readonly string m_DataPath = "ClassDataRegister.txt";
        readonly string m_TempDataPath = "ClassDataRegisterTemp.txt";

        ClassDataCenter()
        {
            bool pred = false;
            if (!System.IO.File.Exists(m_DataPath))
            {                
                using (System.IO.File.CreateText(m_DataPath))
                {
                    pred = true;
                }
            }
            if (!System.IO.File.Exists(m_TempDataPath))
            {
                using (System.IO.File.CreateText(m_TempDataPath))
                {
                    pred = true;
                }
            }

            if(pred)
            {
                return;
            }

            using (var sr = new StreamReader(m_DataPath))
            {
                while (!sr.EndOfStream)
                {
                    var fileName = sr.ReadLine();
                    var size = int.Parse(sr.ReadLine());
                    var list = new List<Tuple<string, string>>();
                    for (int i = 0; i < size; i++)
                    {
                        var type = sr.ReadLine();
                        var name = sr.ReadLine();
                        list.Add(Tuple.Create<string, string>(type, name));
                    }
                    m_StructData.Add(Tuple
                        .Create<string, int, List<Tuple<string, string>>>(
                        fileName, size, list));
                    m_Receivers.ForEach(_ => _.Receive());

                }
            }

            using (var sr = new StreamReader(m_TempDataPath))
            {
                while (!sr.EndOfStream)
                {
                    var fileName = sr.ReadLine();
                    var size = int.Parse(sr.ReadLine());
                    var menberList = new List<Tuple<string, List<string>>>();
                    for (int i = 0; i < size; i++)
                    {
                        var valueName = sr.ReadLine();
                        var valueSize = int.Parse(sr.ReadLine());
                        var valueData = new List<string>();
                        for (int j = 0; j < valueSize; j++)
                        {
                            valueData.Add(sr.ReadLine());
                        }
                        menberList.Add(Tuple.Create<string, List<string>>(valueName, valueData));
                    }
                    m_ValueData.Add(Tuple
                        .Create<string, int, List<Tuple<string, List<string>>>>(
                        fileName, size, menberList));
                }
            }
        }
        ~ClassDataCenter()
        {
            using (var sw = new StreamWriter(m_DataPath, false))
            {
                foreach (var _ in m_StructData)
                {
                    sw.WriteLine(_.Item1);
                    sw.WriteLine(_.Item2);
                    foreach (var data in _.Item3)
                    {
                        sw.WriteLine(data.Item1);
                        sw.WriteLine(data.Item2);
                    }
                }
            }

            using (var sw = new StreamWriter(m_TempDataPath, false))
            {
                foreach (var _ in m_ValueData)
                {
                    sw.WriteLine(_.Item1);
                    sw.WriteLine(_.Item2);
                    foreach (var data in _.Item3)
                    {
                        sw.WriteLine(data.Item1);
                        sw.WriteLine(data.Item2.Count);
                        foreach(var value in data.Item2)
                        {
                            sw.WriteLine(value);
                        }
                    }
                }
            }

        }

        List<ClassData> m_ValueData = new List<ClassData>();
        public List<ClassData> ValueData { get { return m_ValueData; } }

        List<ClassStruct> m_StructData = new List<ClassStruct>();
        public List<ClassStruct> Struct { get{return m_StructData;} }

        public void Register(ClassStruct _data)
        {
            if(0 == m_StructData.Where(_ => _.Item1 == _data.Item1).Count() )
            {
                m_StructData.Add(_data);

                List<Tuple<string, List<string>>> dataList = 
                    new List<Tuple<string, List<string>>>();
                
                var typeCenter = TypeCenter.Instance;

                foreach(var _ in _data.Item3)
                {
                    var IniValue = new List<string>();
                    var types = typeCenter.FindByTypeName(_.Item1);
                    if (types == null)
                    {
                        continue;
                    }
                    foreach(var type in types)
                    {
                        IniValue.Add("0");
                    }
                    dataList.Add(Tuple.Create<string, List<string>>
                        (_.Item1 +" "+_.Item2, IniValue));
                }

                var tempData =
                    Tuple.Create<string, int, List<Tuple<string, List<string>>>>(
                        _data.Item1, _data.Item2, dataList);
                m_ValueData.Add(tempData);
                m_Receivers.ForEach(_ => _.Receive());
            }
        }

        List<IReceiveNoticeOfChangeData> m_Receivers = new List<IReceiveNoticeOfChangeData>();
        public void RegisterOfReceiver(IReceiveNoticeOfChangeData _)
        {
            m_Receivers.Add(_);
        }
        public void UnRegisterOfReceiver(IReceiveNoticeOfChangeData _)
        {
            m_Receivers.Remove(_);
        }

        public void NotifyToReceivers()
        {
            m_Receivers.ForEach(_ => _.Receive());
        }

        public static ClassDataCenter Instance
        {
            get { return m_Instance; }
        }
        static ClassDataCenter m_Instance = new ClassDataCenter();
    }
}
