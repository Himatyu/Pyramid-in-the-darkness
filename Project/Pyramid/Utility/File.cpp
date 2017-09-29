/**
* @file		File.cpp
* @brief	ファイルベースAPI
* @author	S.OIKAWA
* @date		2016.09.06
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	//-----------------------------------------------------------
	// ctor 
	//-----------------------------------------------------------
	File::File(std::string & _filePath)
	{
		SetFilePathInfo(_filePath);
	}

	//-----------------------------------------------------------
	// SetFilePathInfo
	//-----------------------------------------------------------
	void File::SetFilePathInfo(std::string _path)
	{
		if (_path.empty())
		{
			___THROW_EXCEPTION_POINT(Exception, "ファイル名が空");
		}

		auto fileExtensionIndex = _path.rfind(".") - 1;
		auto directoryIndex = _path.rfind("/") + 1;

		m_FileName = _path.substr(directoryIndex, fileExtensionIndex);
		m_FileDirectory = _path.substr(0, directoryIndex);
		m_FilePath = _path;
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

