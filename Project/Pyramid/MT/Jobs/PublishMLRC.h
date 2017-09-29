/**
* @file		PublishMLRC.h
* @brief	�񓯊���MLRC���s���R�[�����āA�W�v����
* @author	S.OIKAWA
* @date		2016.11.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IThreadJob.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#include"../Rendering/Detail/Optimize/MLRCPublisher.h"
#include<list>
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
		namespace Jobs
		{
			/// <summary>
			/// �񓯊���MLRC���s���R�[�����āA�W�v����
			/// </summary>
			class PublishMLRC final :
				public IThreadJob
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				PublishMLRC() = default;
				virtual ~PublishMLRC() = default;

				PublishMLRC(const PublishMLRC&) = default;
				PublishMLRC(PublishMLRC&&) = default;

				PublishMLRC& operator=(const PublishMLRC&) = default;
				PublishMLRC& operator=(PublishMLRC&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// MLRC���s�W�v����
				/// </summary>
				virtual void Job() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF_R_ONLY(m_MLRCList, MLRCList, ::std::list<Rendering::Detail::Optimize::MLRC*>);
				PROPERTY_REF(m_pOrders, pJobs, ::std::list<Rendering::Detail::Optimize::MLRCPublisher*>);

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				::std::list<Rendering::Detail::Optimize::MLRCPublisher*>		m_pOrders;
				::std::list<Rendering::Detail::Optimize::MLRC*>					m_MLRCList;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------