/**
* @file		ObjectOptimizer.cpp
* @brief	オブジェクト単位で最適化する
* @author	S.OIKAWA
* @date		2017.03.24
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectOptimizer.h"
#include"../Common/WorldSpaceDivider.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				ObjectOptimizer::ObjectOptimizer(
					Common::WorldVolume & _volume,
					OptimizationRender* _pRender,
					UINT _priority) :
					m_Judgment(_volume),
					m_Publisher(_volume, _pRender)
				{
					m_Publisher.SetMLRCommand(_priority);
					
				}
				
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				ObjectOptimizer::
					ObjectOptimizer(const ObjectOptimizer & _other) :
					m_Judgment(_other.m_Judgment),
					m_Publisher(_other.m_Publisher)
				{
				}

				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				ObjectOptimizer::~ObjectOptimizer()
				{
					Common::WorldSpaceDivider::Instantiate()
						.UnRegister(m_Judgment);
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void ObjectOptimizer::Init()
				{
					m_Judgment.Add(m_Publisher);
					Common::WorldSpaceDivider::Instantiate()
						.Register(m_Judgment);
				}

				//-----------------------------------------------------------
				// Update
				//-----------------------------------------------------------
				void ObjectOptimizer::Update()
				{
					Common::WorldSpaceDivider::Instantiate()
						.ReRegister(m_Judgment);
				}

				//-----------------------------------------------------------
				// AddPublisher
				//-----------------------------------------------------------
				void ObjectOptimizer::AddPublisher(MLRCPublisher & _publisher)
				{
					m_Judgment.Add(_publisher);
				}

				//-----------------------------------------------------------
				// RemovePublisher
				//-----------------------------------------------------------
				void ObjectOptimizer::RemovePublisher(MLRCPublisher & _publisher)
				{
					m_Judgment.Remove(_publisher);
				}


				//-----------------------------------------------------------
				// SetMLRC
				//-----------------------------------------------------------
				void ObjectOptimizer::SetMLRC(UINT _priority)
				{
					m_Publisher.SetMLRCommand(_priority);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------