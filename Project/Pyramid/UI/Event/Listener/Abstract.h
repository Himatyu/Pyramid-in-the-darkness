/**
* @file		Abstract.h
* @brief	���ۃC�x���g���X�i�[
* @author	S.OIKAWA
* @date		2017.06.02
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Holder.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Listener
			{
				template<class Ty>
				using InterfaceOfNonArgs = void (Ty::*)();
			}
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Listener
			{
				/// <summary>
				/// ���ۃC�x���g���X�i�[
				/// �o�C���h���ꂽ�C���^�[�t�F�[�X���p�����A
				/// ���^�̃C�x���g���X�i�[��o�^����
				/// </summary>
				template<class ...Interfaces>
				class Abstract :
					public Holder<Interfaces...>,
					public Interfaces...
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Abstract() = default;
					~Abstract() = default;

					Abstract(const Abstract&) = default;
					Abstract(Abstract&&) = default;

					Abstract& operator=(const Abstract&) = default;
					Abstract& operator=(Abstract&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
				protected:
					/// <summary>
					/// �C�x���g�������[����
					/// ��{�^�̈��������̃C���^�[�t�F�[�X�������[
					/// </summary>
					template<class Ty>
					void RelayEvent(InterfaceOfNonArgs<Ty> _func);

					/// <summary>
					/// �C�x���g�������[����
					/// �C�ӂ̈������󂯎��InterfaceType���`���ă����[
						///<sample>
							/// template<class Ty>
							/// using InterfaceOfOneInt = void (Ty::*)(int);
							///
							/// ___interface Foo{void foo(int);}
							///
							/// RelayEvent<Foo, InterfaceOfOneInt>(&Foo::foo,0);
						///</sample>
					/// </summary>
					template<class Ty, template<class> class InterfaceType, class ...Args>
					void RelayEvent(typename InterfaceType<Ty> _func, Args... args);
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
				};
#include"Abstract.inl"

			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------