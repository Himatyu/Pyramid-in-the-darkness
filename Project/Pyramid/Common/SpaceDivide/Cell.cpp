/**
* @file		Cell.cpp
* @brief	8分木を構築する空間
* @author	S.OIKAWA
* @date		2017.01.09
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Cell.h"
#include"OctreeRegistrableObject.h"
#include"Octree.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace SpaceDivide
		{
			//-----------------------------------------------------------
			// Register
			//-----------------------------------------------------------
			void Cell::Register(
				OctreeRegistrableObject & _obj, Octree* _pOct)
			{
				if (this == _obj.pCell)
				{
					return;
				}

				_obj.pCell = this;
				if (!m_pHead)
				{
					m_pHead = &_obj;
					_obj.pLast = &_obj;
					return;
				}

				if (!_pOct->IsEffectiveAddress(m_pHead))
				{
					_obj.pNext = m_pHead;
					_obj.pLast = &_obj;
					m_pHead = &_obj;
					return;
				}

				_obj.pNext = m_pHead;
				_obj.pLast = m_pHead->pLast;
				m_pHead->pPrev = &_obj;
				m_pHead =  &_obj;

			}

			//-----------------------------------------------------------
			// UnRegister
			//-----------------------------------------------------------
			void Cell::UnRegister(
				OctreeRegistrableObject & _obj, Octree* _pOct)
			{
				if (!_pOct->IsEffectiveAddress(m_pHead))
				{
					return;
				}

				if (&_obj == m_pHead->pLast)
				{
					auto it = m_pHead->pLast;
					while (it)	//pLast以前に仮想アドレスはない
					{
						it->pLast = _obj.pPrev;
						it = it->pPrev;
					}
				}

				if (&_obj == m_pHead)
				{
					m_pHead = m_pHead->pNext;
				}

				if(_obj.pPrev)
				{ 
					_obj.pPrev->pNext = _obj.pNext;
				}

				if (_obj.pNext)
				{
					_obj.pNext->pPrev = _obj.pPrev;
				}
				_obj.pNext = nullptr;
				_obj.pPrev = nullptr;
				_obj.pLast = nullptr;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------