/**
* @file		OrderedJobExcuter.h
* @brief	�^�X�N�����s����W���u������
* @author	S.OIKAWA
* @date		2016.11.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<unordered_map>
#include<string>
#include<utility>
#include"singleton.h"
#include"Nullable.h"
#include"../MT/Worker/IOrderedJobExecutable.h"
#include"../MT/Order/TaskContainer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			/// <summary>
			/// �W���u�����s����
			/// MTsystem���g�p�ł��Ȃ���΃��C���X���b�h�Ŏ��s����
			/// </summary>
			class OrderedJobExcuter final :
				public Utility::Singleton<OrderedJobExcuter>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OrderedJobExcuter() = default;
				~OrderedJobExcuter();

				OrderedJobExcuter(const OrderedJobExcuter&) = default;
				OrderedJobExcuter(OrderedJobExcuter&&) = default;

				OrderedJobExcuter& operator=(const OrderedJobExcuter&) = default;
				OrderedJobExcuter& operator=(OrderedJobExcuter&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// �R���e�i��Executer���^�O�t���œo�^����
				/// </summary>
				template<class ExcuterType,class ...Args>
				void Register(
					std::string,
					Args&&... args);

				/// <summary>
				/// �����ς݂�Executer���^�O�t���œo�^����
				/// </summary>
				template<class Ty>
				void Register(Ty* ,std::string);
				
				/// <summary>
				/// �o�^��������
				/// </summary>
				void UnRegister(const std::string&);

				/// <summary>
				/// Executer�����s����
				/// </summary>
				void Run(const std::string&);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				using pairData = std::pair<Worker::IOrderedJobExecutable* ,bool>;
				std::unordered_map<std::string,	pairData> m_Executers;
#pragma endregion
			};
#include"OrderedJobExcuter.inl"

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------