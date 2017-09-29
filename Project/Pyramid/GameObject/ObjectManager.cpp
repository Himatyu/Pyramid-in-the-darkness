/**
* @file		ObjectManager.cpp
* @brief	オブジェクトを管理する
* @author	S.OIKAWA
* @date		2016.02.20
* @date		2016.05.09
* @date		2016.05.28	バッチング無効化
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectManager.h"
#include"Observers/ObjectEffectiveStateObserver.h"
#include"Observers/ObjectPriorityStateObserver.h"
#include"Observers/ObjectUpdataStateObserver.h"
#include"Observers/ObjectRenderStateObserver.h"
#include"Object.h"
#include"Estd.h"
#pragma endregion

namespace Pyramid
{
	namespace GameObject
	{
		using namespace std;
		using namespace Observers;
		using namespace Utility::Estd;
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		ObjectManager::ObjectManager()
		{
			//開放するのに便利ってだけで配列にしてみた
			m_ObjectStateObservers[EffectiveState] = new ObjectEffectiveStateObserver(*this);
			m_ObjectStateObservers[PriorityState] = new ObjectPriorityStateObserver(*this);
			m_ObjectStateObservers[UpdataState] = new ObjectUpdataStateObserver(*this);
			m_ObjectStateObservers[DrawState] = new ObjectRenderStateObserver(*this);
		}
		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		ObjectManager::~ObjectManager()
		{
			for_each(m_ObjectStateObservers, [](auto& _) {SAFE_DELETE(_); });
			for_each(m_DynamicObjects, [](auto& _) {SAFE_DELETE(_); });
		}
		//-----------------------------------------------------------
		// updata
		//-----------------------------------------------------------
		void ObjectManager::CallUpdatas()
		{
			m_UpdatableObjects.Apply();
			auto& updataList = m_UpdatableObjects.Vector;
			for_each(updataList, [](auto& _) {_->FastUpdata(); });
			for_each(updataList, [](auto& _) {_->Updata(); });
			for_each(updataList, [](auto& _) {_->LateUpdata(); });

			___DEBUG_CALL(DebugUpdata(updataList));
		}

		//-----------------------------------------------------------
		// draw
		//-----------------------------------------------------------
		void ObjectManager::CallPreDraw()
		{
			m_DrawbleObjects.Apply();
			for_each(m_DrawbleObjects.Vector, [](auto& _) {_->PreDraw(); });
		}

		//-----------------------------------------------------------
		// Register : 登録
		//-----------------------------------------------------------
		void ObjectManager::Register(Object* _pObj, bool _isDynamic)
		{
			if (m_AllObjects.end() != find(m_AllObjects, _pObj))
			{
				//スタック→ヒープの順に関数が呼ばれる
				if (_isDynamic)
				{
					m_DynamicObjects.push_back(_pObj);
				}
				return;
			}

			m_AllObjects.push_back(_pObj);

			for (int i = 0; i < SubjectMax; i++)
			{
				_pObj->StateSubjects[i].Attach(m_ObjectStateObservers[i]);
			}

			if (_pObj->UpdataQuery())
			{
				m_UpdatableObjects.AddRequest(_pObj);
			}

			if (_pObj->DrawQuery())
			{
				m_DrawbleObjects.AddRequest(_pObj);
			}

			if (!_isDynamic)
			{
				return;
			}
			m_DynamicObjects.push_back(_pObj);
		}

		//-----------------------------------------------------------
		// UnRegist
		//-----------------------------------------------------------
		void ObjectManager::UnRegist(Object* _pObj)
		{
			m_AllObjects.remove(_pObj);
			m_DynamicObjects.remove(_pObj);
			m_DrawbleObjects.RemoveRequest(_pObj);
			m_UpdatableObjects.RemoveRequest(_pObj);
		}



		//-----------------------------------------------------------
		// Debug
		//-----------------------------------------------------------

		___DEBUG_DEFINE
		(
			void ObjectManager::DebugUpdata(std::vector<Object*> _objs)
			{
				for_each(_objs, [](auto& _) {_->DebugUpdata(); });

			}
		)
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------