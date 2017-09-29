/**
* @file		ObjectOptimizer.h
* @brief	�I�u�W�F�N�g�P�ʂōœK������
* @author	S.OIKAWA
* @date		2017.03.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"JudgmentSameSpaceOfFrustum.h"
#include"MLRCPublisher.h"
#include"IOptimizer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				/// <summary>
				/// �I�u�W�F�N�g�P�ʂōœK������
				/// </summary>
				class ObjectOptimizer :
					public IOptimizer
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					ObjectOptimizer(
						Common::WorldVolume&,
						OptimizationRender*,
						UINT);
					virtual ~ObjectOptimizer();

					ObjectOptimizer(const ObjectOptimizer&);
					ObjectOptimizer(ObjectOptimizer&&) = default;

					ObjectOptimizer& operator=(const ObjectOptimizer&) = default;
					ObjectOptimizer& operator=(ObjectOptimizer&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
				protected:

					/// <summary>
					/// 
					/// </summary>
					void Init() override;

					/// <summary>
					/// ������ēo�^
					/// </summary>
					void Update() override;

					/// <summary>
					/// �œK�����s��
					/// Update�����ł��ނ�����ɂȂ�
					/// </summary>
					void RunOptimize(const Context&) override{};

				public:
					/// <summary>
					/// ���X�g�ǉ�
					/// </summary>
					void AddPublisher(MLRCPublisher&);

					/// <summary>
					/// ���X�g�폜
					/// </summary>
					void RemovePublisher(MLRCPublisher&);

					/// <summary>
					///MLRC��ݒ肷��A���݂̓v���C�I���e�B�̂ݓn��
					/// </summary>
					void SetMLRC(UINT);

#pragma endregion
				
#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF(m_Publisher.IsCommandPublish, IsCommandPublish, bool);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					JudgmentSameSpaceOfFrustum		m_Judgment;
					MLRCPublisher					m_Publisher;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------