/**
* @file		TaskContainer.h
* @brief	�ϒ�2�����z��̃^�X�N�R���e�i
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class IExecuteable;
}

#pragma endregion
namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			class TaskLine;
			using MTJob = ::Utility::IExecuteable;

			/// <summary>
			/// �ϒ�2�����z��̃^�X�N�R���e�i.
			/// </summary>
			class TaskContainer final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				TaskContainer();
				TaskContainer(u_int _reserve);
				~TaskContainer();

				TaskContainer(const TaskContainer&) = default;
				TaskContainer(TaskContainer&&) = default;

				TaskContainer& operator=(const TaskContainer&) = default;
				TaskContainer& operator=(TaskContainer&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �ǉ�.
				/// ���C�����Ȃ���΍쐬.
				/// </summary>
				void Add(MTJob* _pJob, u_int _lineID);

				/// <summary>
				/// �v�f�폜.
				/// </summary>
				void Remove(MTJob* _pJob, u_int _lineID);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_pJobLines, pJobLines, std::vector<TaskLine*>);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<TaskLine*> m_pJobLines;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
