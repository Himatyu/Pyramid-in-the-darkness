/**
* @file		TaskLine.h
* @brief	���s���čs���^�X�N�ϒ��z��
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<functional>
#include"IExecuteable.h"
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
			/// ���s���čs���^�X�N�ϒ��z��
			/// </summary>
			class TaskLine
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				TaskLine();
				~TaskLine() = default;

				TaskLine(const TaskLine&) = default;
				TaskLine(TaskLine&&) = default;

				TaskLine& operator=(const TaskLine&) = default;
				TaskLine& operator=(TaskLine&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �^�X�N�ǉ�.
				/// </summary>
				void Add(Utility::IExecuteable* _job);

				/// <summary>
				/// �^�X�N����.
				/// </summary>
				void Remove(Utility::IExecuteable* _job);

				/// <summary>
				/// ���s.
				/// ���s��.
				/// </summary>
				void Run();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(
					m_pJobList, 
					pJobList, 
					std::vector<Utility::IExecuteable*>);
#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<Utility::IExecuteable*> m_pJobList;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------