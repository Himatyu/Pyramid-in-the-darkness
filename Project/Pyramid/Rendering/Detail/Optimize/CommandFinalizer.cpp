/**
* @file		CommandFinalizer.cpp
* @brief	コマンドの最適化を行いレンダリングリストを確定させる
* @author	S.OIKAWA
* @date		2017.01.27
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"CommandFinalizer.h"
#include"ContinuityOptimizate.h"
#include"../../Viewer.h"
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
				CommandFinalizer::CommandFinalizer(Viewer ** _ppView) :
					m_ppCurrent(_ppView)
				{
				}

				//-----------------------------------------------------------
				// Run
				//-----------------------------------------------------------
				std::vector<IRenderable*>
					CommandFinalizer::Run(const std::list<OptimizationRender*>& _published)
				{
					std::vector<IRenderable*> result;
					result.reserve(_published.size());

					auto& cameraPos = (*m_ppCurrent)->EyePos;

					auto cmdCount = _published.size();
					if (0 == cmdCount)
					{
						return std::move(result);
					}

					if (1 == cmdCount)
					{
						auto pHead = _published.front();
						pHead->Optimize({ Continuity::None ,cameraPos});
						result.push_back(pHead);
						return std::move(result);
					}

					if (2 == cmdCount)
					{
						auto it = _published.begin();
						auto pRender = *it++;
						auto pNextRender = *it;

						auto isEqualId = pRender->RenderID == pNextRender->RenderID;

						if (isEqualId)
						{
							pRender->Optimize({Continuity::Head,cameraPos });
							pNextRender->Optimize({ Continuity::Tail,cameraPos });
						}
						else
						{
							pRender->Optimize({ Continuity::None,cameraPos });
							pNextRender->Optimize({ Continuity::None,cameraPos });
						}

						result.push_back(pRender);
						result.push_back(pNextRender);
						return std::move(result);
					}

					auto it = _published.begin();
					auto end = _published.end();

					auto pPrevRender = *it++;
					auto pRender = *it++;
					auto pNextRender = *it;
					auto continuity = Continuity::None;

					if (pPrevRender->RenderID == pRender->RenderID)
					{
						continuity = Continuity::Head;
					}
					else
					{
						continuity = Continuity::None;
					}
					pPrevRender->Optimize({ continuity,cameraPos });
					result.push_back(pPrevRender);

					while (true)
					{
						if (pNextRender->RenderID == pRender->RenderID &&
							pPrevRender->RenderID == pRender->RenderID)
						{
							continuity = Continuity::Middle;
						}
						else if (pPrevRender->RenderID == pRender->RenderID)
						{
							continuity = Continuity::Tail;
						}
						else if (pNextRender->RenderID == pRender->RenderID)
						{
							continuity = Continuity::Head;
						}
						else
						{
							continuity = Continuity::None;
						}

						pRender->Optimize({ continuity,cameraPos });
						result.push_back(pRender);
						pPrevRender = pRender;
						pRender = pNextRender;

						if (++it == end)
						{
							if (pPrevRender->RenderID == pRender->RenderID)
							{
								continuity = Continuity::Tail;
							}
							else
							{
								continuity = Continuity::None;
							}
							pRender->Optimize({ continuity,cameraPos });
							result.push_back(pRender);
							break;
						}
						pNextRender = *it;
					}

					return result;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------