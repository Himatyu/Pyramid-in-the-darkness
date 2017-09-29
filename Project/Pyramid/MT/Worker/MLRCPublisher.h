/**
* @file		MLRCPublisher.h
* @brief	PublishMLRC���R�[������
* @author	S.OIKAWA
* @date		2016.11.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../MT/Worker/JobExecuterBase.h"
#include"SafetyIterate.h"
#include"singleton.h"
#include<list>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		class RenderProvider;
		namespace Detail
		{
			namespace Optimize
			{
				class MLRC;
				class MLRCPublisher;
			}
		}
	}
	namespace MT
	{
		namespace Jobs
		{
			class PublishMLRC;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace MT
	{
		namespace Worker
		{
			/// <summary>
			/// �I�[�_�[���Ǘ�����,
			/// PublishMLRC���R�[������
			/// TODO �ӔC����
			/// </summary>
			class MLRCPublisher final :
				public JobExecuterBase,
				public ::Utility::Singleton<MLRCPublisher>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				MLRCPublisher();
				~MLRCPublisher();

				MLRCPublisher(const MLRCPublisher&) = default;
				MLRCPublisher(MLRCPublisher&&) = default;

				MLRCPublisher& operator=(const MLRCPublisher&) = default;
				MLRCPublisher& operator=(MLRCPublisher&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �R�}���h���s
				/// </summary>
				void Execution() override;

				/// <summary>
				/// ���s�Ώۓo�^
				/// </summary>
				void Order(Rendering::Detail::Optimize::MLRCPublisher*);

				/// <summary>
				/// ���s�Ώۓo�^
				/// </summary>
				void Order(::std::list<Rendering::Detail::Optimize::MLRCPublisher*>&);

				/// <summary>
				/// �o�^����
				/// </summary>
				void UnOrder(Rendering::Detail::Optimize::MLRCPublisher*);

			private:
				void ExecuteThisThread() override;
				void MergeCmd();
				void SortCmd();
				void TransmitRanderbleList();
				void CalculationDepth(Rendering::RenderProvider&);

#pragma endregion
			public:
#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_CR_R_ONLY(
					m_SortedRenders,
					SortedRenders,
					::std::list<Rendering::Detail::OptimizationRender*>);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				::std::vector<Jobs::PublishMLRC*>							m_Jobs;
				::std::list<Rendering::Detail::Optimize::MLRCPublisher*>	m_pOrders;
				::std::list<Rendering::Detail::Optimize::MLRC*>				m_PublishedCommand;
				::std::list<Rendering::Detail::OptimizationRender*>			m_SortedRenders;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------