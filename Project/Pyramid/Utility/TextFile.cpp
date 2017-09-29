/**
* @file	TextFile.cpp
* @brief	TextFile実装
* @author	S.OIKAWA
* @date	2016/4/22
*/

//-----------------------------------------------------------
// インクルード
//-----------------------------------------------------------
#include<fstream>
#include "TextFile.h"

//-----------------------------------------------------------
// 宣言
//-----------------------------------------------------------
namespace Utility
{
	using namespace std;

	//-----------------------------------------------------------
	// コンストラクタ
	//-----------------------------------------------------------

	TextFile::TextFile(std::string _Path) :
		File(_Path) {	}


	//-----------------------------------------------------------
	//	読み込み
	//-----------------------------------------------------------
	void TextFile::Read(std::string _path)
	{
		SetFilePathInfo(_path);
		ifstream ifs(m_FilePath);

		if (ifs.fail())
		{//失敗
			___THROW_EXCEPTION_POINT(Exception, "ファイルストリームの生成に失敗 : " + m_FileName);
		}

		//ファイルの開始から終了までをバッファにセット
		istreambuf_iterator<char> it(ifs);
		istreambuf_iterator<char> last;
		m_Buffer = string(it, last);
	}

	//-----------------------------------------------------------
	// 書き込み
	//-----------------------------------------------------------
	void TextFile::Write(std::string _path)
	{
		SetFilePathInfo(_path);
		//一気に書き出し
		if (m_Buffer.empty())
		{
			return;
		}
		ofstream ofs(m_FilePath);
		ofs << m_Buffer << endl;
	}
}
//-----------------------------------------------------------
//　EOF
//-----------------------------------------------------------
