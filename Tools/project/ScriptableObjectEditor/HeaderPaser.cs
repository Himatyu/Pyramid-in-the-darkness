using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ScriptableObjectEditor
{
    public class HeaderPaser
    {
        public void Run(string _path)
        {
            if(null!=m_Pased)
            {
                m_Pased.Item3.Clear();
            }
            using (var sr = new StreamReader(_path))
            {
                List<Tuple<string, string>> list = new List<Tuple<string, string>>();
                while (!sr.EndOfStream)
                {
                    var result = Parse(sr.ReadLine());
                    if(null == result)
                    {
                        continue;
                    }
                    list.Add(result);
                }
                m_Pased = 
                    Tuple.Create<string, int, List<Tuple<string, string>>>(
                        _path, list.Count, list);
            }
        }

        Tuple<string, string> Parse(string _line)
        {
            //ブロックコメント判定
            //コメント切り分け
            //定義判定

            //構文解析しないから多少の粗はしょうがない
            if(-1 != _line.IndexOf(')') || -1 != _line.IndexOf('(') ||
                -1 != _line.IndexOf('}') || -1 != _line.IndexOf('{'))
            {
                return null;
            }

            var cmIt = _line.IndexOf("*/");
            if (-1 != cmIt)
            {
                m_IsIgnoreBlock = false;
                _line = _line.Substring( cmIt, _line.Length-1);
            }

            if (m_IsIgnoreBlock)
            {
                return null;
            }

            cmIt = _line.IndexOf("/*");
            if (-1 != cmIt)
            {
                _line = _line.Substring(0, cmIt);
                m_IsIgnoreBlock = true;
            }

            cmIt = _line.IndexOf("//");
            if(-1 != cmIt)
            {
                _line = _line.Substring(0, cmIt);
            }

            var it = _line.IndexOf(';');
            if (-1 == it || 0 == _line.Length)
            {
                return null;
            }
            _line = _line.Substring(0, it);

            //タブ・スペース変換
            string convered = null;

            foreach (var _ in _line)
            {
                if(_ == '\t')
                {
                    convered += ' ';
                    continue;
                }
                convered += _;
            }

            _line = convered;

            //連続スペース削除
            var list = new List<int>();
            char? buffer = null;
            int index = 0;

            foreach(var _ in _line)
            {                
                if (null == buffer)
                {
                    buffer = _;
                    index++;
                    continue;
                }

                if (buffer == ' '&& buffer == _)
                {
                    list.Add(index);
                }
                buffer = _;
                index++;
            }

            int removeCount = 0;

            foreach (var _ in list)
            {
                _line = _line.Remove(_ - removeCount,1);
                removeCount++;
            }

            var splited = _line.Split(' ');
            
            string first =null, second = null;
            bool isHead = true;
            foreach (var _ in splited)
            {
                if (_ == "" || _ == " " ||
                    _ == "static" || _ =="const" || _ == "constexpr")
                {
                    continue;
                }
                
                if (isHead)
                {
                    if (null == first)
                    {
                        var size1 = _.Where((char str) => { return str == '<'; }).Count();
                        var size2 = _.Where((char str) => { return str == '>'; }).Count();

                        if (size1 == size2)
                        {
                            first = _;
                            isHead = false;
                        }
                    }
                    else
                    {
                        first += _;
                        var size1 = first.Where((char str) => { return str == '<'; }).Count();
                        var size2 = first.Where((char str) => { return str == '>'; }).Count();

                        if (size1 == size2)
                        {
                            isHead = false;
                        }
                    }
                }else
                {
                    second = _;
                    break;
                }
            }

            if ("class" == first ||
                "struct" == first || 
                "friend" == first ||
                "using" == first ||
                null == first || 
                null == second)
            {
                return null;
            }
            return Tuple.Create<string, string>(first, second);
        }

        Tuple<string, int, List<Tuple<string, string>>> m_Pased ;
        public Tuple<string, int, List<Tuple<string, string>>> Pased
        {
            get { return m_Pased; }
        }
        bool m_IsIgnoreBlock = true;
    }
}
