/**
* @file		Object.cpp
* @brief	ベースオブジェクト
* @author	S.Oikawa
* @date		2016.02.20
*/
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectManager.h"
#include"Object.h"
#include"../GameObject/Detail/ComponentsPossession.h"
#include"../Components/Observers/ComponentEffectiveStateObserver.h"
#include"../Components/Observers/ComponentPriorityStateObserver.h"
#include"../Components/Observers/ComponentUpdataStateObserver.h"
#include"../Components/Observers/ComponentRenderStateObserver.h"
#include"Estd.h"

#include<algorithm>
#include<typeinfo>
#include<memory>
#include<list>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		using namespace std;
		using namespace Components;
		using namespace Utility::Estd;

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Object::Object(Blueprint::Level* _lv) :
			ComponentsPossession(this),
			m_ComponentStateObservers({ nullptr }),
			m_pOwner(_lv)
		{
			m_ComponentStateObservers[Observers::SubjectId::EffectiveState]
				= new Components::Observers::ComponentEffectiveStateObserver(*this);
			m_ComponentStateObservers[Observers::SubjectId::PriorityState]
				= new Components::Observers::ComponentPriorityStateObserver(*this);
			m_ComponentStateObservers[Observers::SubjectId::UpdataState]
				= new Components::Observers::ComponentUpdataStateObserver(*this);
			m_ComponentStateObservers[Observers::SubjectId::DrawState]
				= new Components::Observers::ComponentRenderStateObserver(*this);

			for_each(m_StateSubjects, [this](auto& _) {_.pOwner = this; });

			//スタック用 
			_lv->ObjectManager.Register(this);
		}

		//-----------------------------------------------------------
		// copy 
		//-----------------------------------------------------------
		Object::Object(const Object & _rhs) :
			ComponentsPossession(this),
			m_ComponentStateObservers({ nullptr })
		{
			Clone(_rhs);
		}

		//-----------------------------------------------------------
		// move 
		//-----------------------------------------------------------
		Object::Object(Object && _rhs) :
			ComponentsPossession(this)
		{
			Move(_rhs);
		}

		//-----------------------------------------------------------
		// =  
		//-----------------------------------------------------------
		Object & Object::operator=(const Object & _other)
		{
			Clone(_other);
			return *this;
		}

		//-----------------------------------------------------------
		// == 
		//-----------------------------------------------------------
		Object & Object::operator=(Object && _other)
		{
			Move(_other);
			return *this;
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		Object::~Object()
		{
			for_each(m_ComponentStateObservers, [](auto& _) {SAFE_DELETE(_); });
		}

		//-----------------------------------------------------------
		// 初期化
		//-----------------------------------------------------------
		void Object::Init()
		{
		}

		//-----------------------------------------------------------
		// FastUpdata 
		//-----------------------------------------------------------
		void Object::FastUpdata()
		{
			m_UpdatableComponents.Apply();
			for_each(m_UpdatableComponents.Vector, [](auto& _) {_->FastUpdata(); });
		}

		//-----------------------------------------------------------
		// 更新
		//-----------------------------------------------------------
		void Object::Updata()
		{
			m_UpdatableComponents.Apply();
			for_each(m_UpdatableComponents.Vector, [](auto& _) {_->Updata(); });
		}

		//-----------------------------------------------------------
		// LateUpdata
		//-----------------------------------------------------------
		void Object::LateUpdata()
		{
			m_UpdatableComponents.Apply();
			for_each(m_UpdatableComponents.Vector, [](auto& _) {_->LateUpdata(); });
		}

		//-----------------------------------------------------------
		// 描画
		//-----------------------------------------------------------
		void Object::PreDraw()
		{
			m_DrawbleComponents.Apply();
			for_each(m_DrawbleComponents.Vector, [](auto& _) {_->PreDraw(); });
		}

		//-----------------------------------------------------------
		// 終了処理
		//-----------------------------------------------------------
		void Object::Finit()
		{

		}

		//-----------------------------------------------------------
		// ModifyisActive
		//-----------------------------------------------------------
		void Object::ModifyisActive()
		{
			m_StateSubjects[Observers::EffectiveState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyisDestory
		//-----------------------------------------------------------
		void Object::ModifyisDestory()
		{
			m_StateSubjects[Observers::EffectiveState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyisUpdata
		//-----------------------------------------------------------
		void Object::ModifyisUpdata()
		{
			m_StateSubjects[Observers::UpdataState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyisDraw
		//-----------------------------------------------------------
		void Object::ModifyisDraw()
		{
			m_StateSubjects[Observers::DrawState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyPriority
		//-----------------------------------------------------------
		void Object::ModifyPriority()
		{
			m_StateSubjects[Observers::PriorityState].Notify();
		}

		//-----------------------------------------------------------
		// Clone
		//-----------------------------------------------------------
		void Object::Clone(const Object& _other)
		{
			if (&_other == this)
			{
				return;
			}

			//HACK cast時のコピーを防ぐ
			auto pObject = &const_cast<Object&>(_other);

			*static_cast<StateQueryable*>(this) =
				*static_cast<StateQueryable*>(pObject);

			//HACK ComponentsPossessionにCast時のコピーではpOqner(Object)のコピーがされないため
			*static_cast<ComponentsPossession*>(this) =
				*static_cast<ComponentsPossession*>(pObject);

			m_UpdataPriority = _other.m_UpdataPriority;
			m_pOwner = _other.m_pOwner;
			m_Tag = _other.m_Tag;

			auto& observer = pOwner->ObjectManager.ObjectStateObservers;
			auto& otherObserver = _other.pOwner->ObjectManager.ObjectStateObservers;
			for (int i = 0; i < Observers::SubjectMax; i++)
			{
				m_StateSubjects[i].Detach(observer[i]);
				m_StateSubjects[i].Attach(otherObserver[i]);
			}

			for_each(m_StateSubjects, [this](auto& _) {_.pOwner = this; });
			TypeApply<Object>();

			//スタック用 
			m_pOwner->ObjectManager.Register(this);
		}

		//-----------------------------------------------------------
		// Move
		//-----------------------------------------------------------
		void Object::Move(Object& _other)
		{
			if (&_other == this)
			{
				return;
			}

			//無駄なコピーが起きないようにポインタでキャスト
			(*static_cast<StateQueryable*>(this)) =
				move(*static_cast<StateQueryable*>(&_other));

			(*static_cast<ComponentsPossession*>(this)) =
				move(*static_cast<ComponentsPossession*>(&_other));

			m_StateSubjects = std::move(_other.m_StateSubjects);
			for_each(m_StateSubjects, [this](auto& _) {_.pOwner = this; });

			m_ComponentStateObservers = std::move(_other.m_ComponentStateObservers);
			for_each(m_ComponentStateObservers, [this](auto& _) {_->pOwner = this; });
			for_each(_other.m_ComponentStateObservers, [this](auto& _) {_ = nullptr; });

			m_UpdataPriority = std::move(_other.m_UpdataPriority);
			m_pOwner = std::move(_other.m_pOwner);
			m_Tag = std::move(_other.m_Tag);
		}

		___DEBUG_DEFINE
		(
			void Object::DebugUpdata()
			{
				for_each(m_UpdatableComponents.Vector, [](auto& _) {_->AdditionalUpdataOfDebug(); });
			}
			)

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------