using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScriptableObjectEditor.Model
{
    public class ClassDataRegister 
    {
        public ClassDataRegister(Control.ClassDataRegister _control)
        {
            m_Control = _control;
        }
        ~ClassDataRegister()
        {
           
        }

        public void ViewDataUpdata()
        {
            var ofd = new OpenFileDialog();
            ofd.FileName = "default.h";
            ofd.InitialDirectory = @"C:\Users\HimaJin\Documents\Pyramid";
            ofd.Filter = ".hファイル(*.h)|*.h";
            ofd.FilterIndex = 2;
            ofd.Title = "開くヘッターを選択してください";
            ofd.RestoreDirectory = true;
            ofd.CheckFileExists = true;
            ofd.CheckPathExists = true;

            if (ofd.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            paser = new HeaderPaser();
            paser.Run(ofd.FileName);
            m_Control.View.UpdataSelectClassName(ofd.FileName);
            m_Control.View.UpdataClassStructVeiw(paser.Pased.Item3);

        }

        public void RegisterOfClassData()
        {
            var ins = ClassDataCenter.Instance;
            ins.Register(paser.Pased);
        }

        HeaderPaser paser;
        Control.ClassDataRegister m_Control = null;
    }
}
