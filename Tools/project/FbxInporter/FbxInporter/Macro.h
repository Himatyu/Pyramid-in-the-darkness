/**
* @file		Macro.h
* @brief	�}�N����`�w�b�_
* @author	S.OIKAWA
* @date	2016.02.19
*			2016.4.22	�R�����g��DoxyGen�ɑΉ��A�R���X�g�E�Q�Ƃ�ǉ������v���p�e�B�쐬
*/
#pragma once

#include <crtdbg.h>
#include <windows.h>
#include <tchar.h>
#include<stdio.h>
#include<mutex>


//-----------------------------------------------------------
//�@�l�[���X�y�[�X
//-----------------------------------------------------------

/** @def NS_BEGIN
* �l�[���X�y�[�X�J�n
*/
#define NS_BEGIN(_name)\
	namespace _name \
	{	/*_name*/

/** @def NS_END
* �l�[���X�y�[�X�I��
*/
#define NS_END(_name)	\
	} /*_name*/



#define NS_NEST1_BEGIN(_name1)\
		namespace _name1{
#define NS_NEST2_BEGIN(_name1,_name2)\
		namespace _name1{ NS_NEST1_BEGIN(_name2)
#define NS_NEST3_BEGIN(_name1,_name2,_name3)\
		namespace _name1{ NS_NEST2_BEGIN(_name2,_name3)
#define NS_NEST4_BEGIN(_name1,_name2,_name3,_name4)\
		namespace _name1{ NS_NEST3_BEGIN(_name2,_name3,_name4)
#define NS_NEST5_BEGIN(_name1,_name2,_name3,_name4,_name5)\
		namespace _name1{ NS_NEST4_BEGIN(_name2,_name3,_name4,_name5)
#define NS_NEST6_BEGIN(_name1,_name2,_name3,_name4,_name5,_name6)\
		namespace _name1{ NS_NEST5_BEGIN(_name2,_name3,_name4,_name5,_name6)
#define NS_NEST7_BEGIN(_name1,_name2,_name3,_name4,_name5,_name6,_name7)\
		namespace _name1{ NS_NEST6_BEGIN(_name2,_name3,_name4,_name5,_name6,_name7)
#define NS_NEST8_BEGIN(_name1,_name2,_name3,_name4,_name5,_name6,_name7,_name8)\
		namespace _name1{ NS_NEST7_BEGIN(_name2,_name3,_name4,_name5,_name6,_name7,_name8)
#define NS_NEST9_BEGIN(_name1,_name2,_name3,_name4,_name5,_name6,_name7,_name8,_name9)\
		namespace _name1{ NS_NEST8_BEGIN(_name2,_name3,_name4,_name5,_name6,_name7,_name8,_name9)


#define NS_NEST1_END()}
#define NS_NEST2_END()}}
#define NS_NEST3_END()}}}
#define NS_NEST4_END()}}}}
#define NS_NEST5_END()}}}}}
#define NS_NEST6_END()}}}}}}
#define NS_NEST7_END()}}}}}}}
#define NS_NEST8_END()}}}}}}}}
#define NS_NEST9_END()}}}}}}}}}


//-----------------------------------------------------------
// �A�N�Z�X�v���p�e�B
//-----------------------------------------------------------
/** @def PROPERTY
* �ǂݏ����\�ȃv���p�e�B�B�l�n��
*/
#define PROPERTY(var,propertyName,type) 	\
		void Seter_##propertyName(type _val) { var = _val;} \
		type Geter_##propertyName() const {return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_Ref
* �ǂݏ����\�ȃv���p�e�B�B�Q�Ɠn��
*/
#define PROPERTY_REF(var,propertyName,type) 	\
		void Seter_##propertyName(const type& _val){ var = _val;} \
		type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName, put =Seter_##propertyName)) type propertyName

/** @def PROPERTY_MOVE
* �ǂݏ����\�ȃv���p�e�B�B�E�Ӓl�n��
*/
#define PROPERTY_MOVE(var,propertyName,type) 	\
		void Seter_##propertyName(const type& _val){ var = std::move(_val);} \
		type&& Geter_##propertyName() {return std::move(var);} \
		__declspec(property(get = Geter_##propertyName, put =Seter_##propertyName)) type propertyName

/** @def PROPERTY_Static_Ref
* �ǂݏ����\�ȐÓI�v���p�e�B�B�Q�Ɠn��
*/
#define PROPERTY_STATIC_REF(var,propertyName,type) 	\
		static void Seter_##propertyName(const type& _val){ var = _val;} \
		static type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName, put =Seter_##propertyName)) static type propertyName

/** @def THREAD_SAFE_PROPERTY
* �ǂݏ����\�ȃv���p�e�B�B�l�n��,�X���b�h�Z�[�t
*/
#define THREAD_SAFE_PROPERTY(var,propertyName,type,mtx) 	\
		void Seter_##propertyName(type _val){ std::lock_guard<std::mutex> lk(mtx); var = _val;} \
		type Geter_##propertyName() {std::lock_guard<std::mutex> lk(mtx); return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def THREAD_SAFE_REF_PROPERTY
* �ǂݏ����\�ȃv���p�e�B�B�Q�Ɠn��,�X���b�h�Z�[�t
*/
#define THREAD_SAFE_REF_PROPERTY(var,propertyName,type,mtx) 	\
		void Seter_##propertyName(const type& _val){ std::lock_guard<std::mutex> lk(mtx); var = _val;} \
		type& Geter_##propertyName() {std::lock_guard<std::mutex> lk(mtx); return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_R_ONLY
* �ǂݐ�p�ȃv���p�e�B�B�l�n��
*/
#define PROPERTY_R_ONLY(var,propertyName,type) 	\
		type Geter_##propertyName() const{return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName

/** @def PROPERTY_REF_R_ONLY
* �ǂݐ�p�ȃv���p�e�B�B�Q�ƕԂ�
*/
#define PROPERTY_REF_R_ONLY(var,propertyName,type) 	\
		type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName

/** @def PROPERTY_CR_R_ONLY
* �ǂݐ�p�ȃv���p�e�B�B�R���X�g�Q�ƕԂ�
*/
#define PROPERTY_CR_R_ONLY(var,propertyName,type) 	\
		const type& Geter_##propertyName() const {return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName

/** @def THREAD_SAFE_PROPERTY
* �ǂݐ�p�ȃv���p�e�B�B�l�n��,�X���b�h�Z�[�t
*/
#define THREAD_SAFE_PROPERTY_R_ONLY(var,propertyName,type,mtx) 	\
		type Geter_##propertyName() {std::lock_guard<std::mutex> lk(mtx); return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName


/** @def PROPERTY_Static_Ref
* �ǂݏ����\�ȐÓI�v���p�e�B�B�Q�Ɠn��
*/
#define PROPERTY_STATIC_R_ONLY(var,propertyName,type) 	\
		static type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName)) static type propertyName

/** @def PROPERTY_W_ONLY
* ������p�ȃv���p�e�B�B�l�n��
*/
#define PROPERTY_W_ONLY(var,propertyName,type) 	\
		void Seter_##propertyName(type _val){ var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_REF_W_ONLY
* ������p�ȃv���p�e�B�B�R���X�g�Q��
*/
#define PROPERTY_REF_W_ONLY(var,propertyName,type) 	\
		void Seter_##propertyName(type& _val){ var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_W_ONLY
* ������p�ȃv���p�e�B�B�R���X�g�Q��
*/
#define PROPERTY_CR_W_ONLY(var,propertyName,type) 	\
		void Seter_##propertyName(const type& _val){ var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def THREAD_SAFE_PROPERTY
* ������p�ȃv���p�e�B�B�l�n��,�X���b�h�Z�[�t
*/
#define THREAD_SAFE_PROPERTY_W_ONLY(var,propertyName,type,mtx) 	\
		void Seter_##propertyName(type _val){ std::lock_guard<std::mutex> lk(mtx); var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_HOOKABLE
* �ǂݏ����\�ȃv���p�e�B�B�l�n��
* �t�b�N�ł��邪����p�̖����悤�ɗ���.
*/
#define PROPERTY_HOOKABLE(var,propertyName,type,hook) 	\
		void Seter_##propertyName(type _val) { var = _val;hook();} \
		type Geter_##propertyName() const {return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_REF_HOOKABLE
* �ǂݏ����\�ȃv���p�e�B.�Q�Ɠn��
* �t�b�N�ł��邪����p�̖����悤�ɗ���.
*/
#define PROPERTY_REF_HOOKABLE(var,propertyName,type,hook) 	\
		void Seter_##propertyName(const type& _val) { var = _val;hook();} \
		type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName


//-----------------------------------------------------------
// String�ϊ��}�N��
//-----------------------------------------------------------
/** @def ___GET_THIS_NAME
* �f�B�X�|�C���^����`���擾
*/
#define ___GET_THIS_NAME(pthis)					\
		 std::string(typeid(*pthis).name())

/** @def ___TYPE_TO_STRING
*	�^��string�ɕϊ�
*/
#define ___TYPE_TO_STRING(type)					\
		std::string(typeid(type).name())

/** @def ___CODE_TO_STRING
* �R�[�h�𕶎���
*/
#define ___CODE_TO_STRING(_code)				\
		std::string(#_code)

//-----------------------------------------------------------
// ASSERT
//-----------------------------------------------------------

//!< ���d�錾�}�N�� �x������
#pragma warning ( disable : 4005 )
//!< �x��Lv3 �x������
#pragma warning ( disable : 4996 )

/**
@def _ASSERT_EXPR
@brief expr�̏�������������Ȃ�������A��2�����ɓn�������b�Z�[�W���f�o�b�O���|�[�g�E�B���h�E�ɕ\�L����}�N��
@param [in]expr ����(�ے�)
@param [in]msg ���b�Z�[�W
@note ��F_ASSERT_EXPR( isClear == true, _T("���b�Z�[�W") );
*/
#ifdef _DEBUG
#define _ASSERT_EXPR(expr, msg) \
	(void) ((!!(expr)) || \
	(1 != _CrtDbgReportW(_CRT_ASSERT, _CRT_WIDE(__FILE__), __LINE__, NULL, msg)) || \
	(_CrtDbgBreak(), 0))
#else
#    define _ASSERT_EXPR(expr, msg) {}// �����
#endif


#ifdef _DEBUG
#ifndef _ASSERT
#define _ASSERT(expr) _ASSERT_EXPR((expr), NULL)
#endif
#else
#    define _ASSERT(expr) {}// �����
#endif

#ifdef _DEBUG
#ifndef _ASSERTE
#define _ASSERTE(expr) _ASSERT_EXPR((expr), _CRT_WIDE(#expr))
#endif
#else
#    define _ASSERTE(expr) {}// �����
#endif


//-----------------------------------------------------------
//�f�o�b�O������o��
//-----------------------------------------------------------
/**
@def DOM
@brief �����t���f�o�b�O������o�� OutputDebugString( _T("���b�Z�[�W�I\n") )�̏㏑���}�N��
@param [in] str �\��������t�H�[�}�b�g
@param [in] ... ����
@return ����
@note ��FMyOutputDebugString( "���݂̃x�N�g����(%f, %f) \n", vec.x, vec.y )
*/
#ifdef _DEBUG
#   define DOM( str, ... ) \
      { \
        TCHAR c[2048]; \
        _stprintf( c, str, __VA_ARGS__ ); \
        OutputDebugString( c ); \
      }

#else
#    define DOM( str, ... ) {}// �����
#endif

/**
@def SET_TITLE
@brief �^�C�g���o�[�ɕ����Z�b�g
@param [in] str �\��������t�H�[�}�b�g
@param [in] ... ����
@return ����
*/
#ifdef _DEBUG
#define SET_TITLE(str , ...)	\
		{								\
			TCHAR c[2048];					\
			_stprintf( c, str, __VA_ARGS__ ); \
			SetWindowText(FindWindow("StudXAPP",NULL),c); \
		}
#else
#define SET_TITLE(str , ...) {}
#endif // !_DEBUG


//-----------------------------------------------------------
// �������֌W
//-----------------------------------------------------------

/** @def ON_SEARCH_LEAK
* ���������[�N���o
*/
#ifdef _DEBUG
#define ON_SEARCH_LEAK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) 
#else
#define  ON_SEARCH_LEAK
#endif // !_DEBUG

/** @def ON_BREAK_ALLOC
* �������m�ێ��u���C�N
*/
#ifdef _DEBUG
#define ON_BREAK_ALLOC(no) _CrtSetBreakAlloc(no)
#else
#define  ON_BREAK_ALLOC
#endif

/** @def SAFE_RELEASE
* ���d�J���h�~
*/
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(ptr)			if(ptr){ ptr->Release(); ptr=nullptr; }
#endif
/** @def SAFE_DELETE
* ���d�J���h�~
*/
#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr)			if(ptr){ delete ptr; ptr=nullptr; }
#endif
/** @def SAFE_DELETE_ARRAY
* ���d�J���h�~
*/
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr)		if(ptr){ delete[] ptr; ptr=nullptr; }
#endif

//-----------------------------------------------------------
// �������x�v��
//-----------------------------------------------------------

/// <summary>
/// �����[�X���ɏ�����v���J�n
/// �I����ID�����킹�邱��
/// ID�͕ʃX�R�[�v�ł���Γ����\
/// </summary>
#ifdef _DEBUG
#define ___D_TIME_COUNT_BEGINE(_Id)\
		clock_t s_d##_Id = clock();
#else
#define	___D_TIME_COUNT_BEGINE(_Id)
#endif // !_DEBUG

/// <summary>
/// �����[�X���ɏ�����v���I��
/// �J�n��ID�����킹�邱��
/// ID�͕ʃX�R�[�v�ł���Γ����\
/// </summary>
#ifdef _DEBUG
#define ___D_TIME_COUNT_END(_Id)\
	___D_LOG(std::string(#_Id)+" : " + std::to_string((double)(clock() - s_d##_Id)));
#else
#define	___D_TIME_COUNT_END(_Id)
#endif // !_DEBUG


#define ___TIME_COUNT_BEGINE(_Id)\
		clock_t s_s##_Id = clock();

#define ___PROFILE_END(_Id)\
	___LOG(std::string(#_Id)+" : " + std::to_string((double)(clock() - s_s##_Id)));


//-----------------------------------------------------------
// std�g��
//-----------------------------------------------------------

//-----------------------------------------------------------
// ___RANGE_BASED
//-----------------------------------------------------------
#define ___RANGE_BASED(_cnt)\
	_cnt.begin(), _cnt.end()

//-----------------------------------------------------------
// ___FOREACH
//-----------------------------------------------------------
#define ___FOREACH(_container,action)\
	std::for_each(_container.begin(),_container.end(),action)
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------