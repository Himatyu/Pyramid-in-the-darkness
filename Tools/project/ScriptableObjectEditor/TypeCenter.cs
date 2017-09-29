using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ScriptableObjectEditor
{
    using RegistableType = Tuple<string, int, List<string>>;
    public class TypeCenter
    {
        readonly string m_DataPath = "TypeData.txt";
        List<RegistableType> m_Data = new List<RegistableType>();

        public TypeCenter()
        {
            if (!System.IO.File.Exists(m_DataPath))
            {
                using (System.IO.File.CreateText(m_DataPath))
                {
                    return;
                }
            }
            using (var sr = new StreamReader(m_DataPath))
            {
                while (!sr.EndOfStream)
                {
                    var typeName = sr.ReadLine();
                    var size = int.Parse(sr.ReadLine());
                    var list = new List<string>();
                    for (int i = 0; i < size ; i++)
                    {
                        var type = sr.ReadLine();
                        list.Add(type);
                    }

                    m_Data.Add(
                        Tuple.Create<string, int, List<string>>(typeName, size, list));
                }
            }

            
        }
        ~TypeCenter()
        {
            using (var sw = new StreamWriter(m_DataPath, false))
            {
                foreach (var _ in m_Data)
                {
                    sw.WriteLine(_.Item1);
                    sw.WriteLine(_.Item2);
                    foreach (var data in _.Item3)
                    {
                        sw.WriteLine(data);                        
                    }
                }
            }
        }

        public List<string> FindByTypeName(string _name)
        {
            var result = m_Data.Where(_ => _.Item1 == _name);

            if (0 == result.Count())
            {
                return null;
            }
            return result.First().Item3;
        }

        public static TypeCenter Instance
        {
            get { return m_Instance; }
        }
        static TypeCenter m_Instance = new TypeCenter();
    }
}
