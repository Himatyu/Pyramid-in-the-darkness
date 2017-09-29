/**
* @file		Debug.h
* @brief	�f�o�b�N�@�\��񋟂���
* @author	S.OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#include<unordered_map>
#include"Macro.h"
#include"singleton.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------


namespace Utility
{
	/// <summary>
	/// �O����`
	/// </summary>
	class TextFile;

	/// <summary>
	/// ���O�o�̓f�B���N�g��
	/// </summary>
#ifdef _DEBUG
	const std::string g_FileDirectory("DebugOutput/");
#else
	const std::string g_FileDirectory("OutputLog/");
#endif // !_DEBUG


#ifdef _DEBUG

	/// <summary>
	/// �����[�X���ɌĂяo�����Ə�����֐�
	/// </summary>
#define ___D_CALL(function,...)\
		Debug::Instance().function(__VA_ARGS__);

	/// <summary>
	/// �����[�X���ɌĂяo�����Ə����郍�O
	/// </summary>
#define	___D_LOG(_msg) \
		::Utility::Debug::Instantiate().Log(_msg);

#define ___DEBUG_CALL(...) __VA_ARGS__
#define ___DEBUG_DEFINE(...) __VA_ARGS__
#else

#define	___D_CALL(function,...)
#define	___D_LOG(_msg)

#define ___DEBUG_CALL(...)
#define ___DEBUG_DEFINE(...)

#endif // !_DEBUG

	/// <summary>
	/// �����[�X���ɂ��c�郍�O
	/// </summary>
#define ___LOG(_msg) \
		::Utility::Debug::Instantiate().Log(_msg);

/// <summary>
/// �f�o�b�N�T�|�[�g�N���X
/// </summary>
	class Debug :
		public Singleton<Debug>
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Debug(const Debug& other) = delete;
		Debug(Debug && other) = delete;

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~Debug();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Debug();

	public:
		//-----------------------------------------------------------
		// operaotor
		//-----------------------------------------------------------
		Debug& operator=(const Debug& other) = delete;
		Debug& operator=(Debug&& other) = delete;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �o��.
		/// ��{��log.text�ɏo�́A���̃t�@�C���ɏo�͂������ꍇ�Ƀt�@�C�������w�肷��
		/// </summary>
		/// <param name="_msg">���O���b�Z�[�W</param>
		/// <param name="_mapKey">�t�@�C���L�[</param>
		void Log(const std::string& _msg, std::string _mapKey = std::string("Log"));

		/// <summary>
		/// �f�o�b�N�R���\�[�����g�p����
		/// </summary>
		/// <param name="_posX">X���W</param>
		/// <param name="_posY">Y���W</param>
		/// <param name="_width">����</param>
		/// <param name="_height">�c��</param>
		void UseDebugConsole(int _posX = 1000, int _posY = 400, int _width = 500, int _height = 400);

		/// <summary>
		/// �f�o�b�N�e�L�X�g�`��
		/// </summary>
		/// <param name="_msg">���e</param>
		/// <param name="_posX">X���W</param>
		/// <param name="_posY">y���W</param>
		/// <param name="_prosesName">�v���Z�X��</param>
		void DrawText
			(std::string _msg,
				int _posX = 20,
				int _posY = 20,
				std::string _prosesName = "Pyramid"
				);

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY(m_UseMSDebugString, MSDebugOutput, bool);
		PROPERTY(m_UseOutputLog, OutputLog, bool);
		PROPERTY_R_ONLY(m_UseDebugConsole, DebugConsole, bool);
		PROPERTY_R_ONLY(m_Directory, Directory, std::string);

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		using FileMap = std::unordered_map < std::string, TextFile* >;
		/// <summary>
		/// �t�@�C���}�b�v
		/// </summary>
		FileMap m_FileMap;

		/// <summary>
		/// �o�̓f�B���N�g��
		/// </summary>
		const std::string m_Directory;

		/// <summary>
		/// �R���\�[���n���h��
		/// </summary>
		int  m_hConsole;

		/// <summary>
		/// VS�̃f�o�b�N�E�B���h�ɕ\��
		/// </summary>
		bool m_UseMSDebugString;

		/// <summary>
		/// ���O�t�@�C���ɏo��
		/// </summary>
		bool m_UseOutputLog;

		/// <summary>
		/// �R���\�[���Ƀ��O�o��
		/// </summary>
		bool m_UseDebugConsole;

		/// <summary>
		/// �W���o�̓n���h��
		/// </summary>
		HANDLE m_StdOutput;

		/// <summary>
		/// �R���\�[���E�B���h�E�n���h��
		/// </summary>
		HWND	m_DebugConsoleWinddowHandel;

		/// <summary>
		/// �W���o�͐�
		/// </summary>
		FILE*	m_pStdOut;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


