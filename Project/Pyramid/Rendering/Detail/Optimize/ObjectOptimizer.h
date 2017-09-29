/**
* @file		ObjectOptimizer.h
* @brief	オブジェクト単位で最適化する
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
				/// オブジェクト単位で最適化する
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
					/// 視錐台再登録
					/// </summary>
					void Update() override;

					/// <summary>
					/// 最適化を行う
					/// Updateだけですむから特にない
					/// </summary>
					void RunOptimize(const Context&) override{};

				public:
					/// <summary>
					/// リスト追加
					/// </summary>
					void AddPublisher(MLRCPublisher&);

					/// <summary>
					/// リスト削除
					/// </summary>
					void RemovePublisher(MLRCPublisher&);

					/// <summary>
					///MLRCを設定する、現在はプライオリティのみ渡す
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