/**
* @file		ComponentsPossession.cpp
* @brief	コンポーネントを管理する.
* @author	S.OIKAWA
* @date		2016.09.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentsPossession.h"
#include"../Components/Component.h"
#include"../Components/Observers/ComponentEffectiveStateObserver.h"
#include"../Components/Observers/ComponentPriorityStateObserver.h"
#include"../Components/Observers/ComponentUpdataStateObserver.h"
#include"../Components/Observers/ComponentRenderStateObserver.h"
#include"../Components/Observers/ComponentStateSubject.h"
#include"Estd.h"
#include"../GameObject/Object.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		using namespace Utility::Estd;
		using namespace Components::Observers;
		//-----------------------------------------------------------
		// ctor 
		//-----------------------------------------------------------
		ComponentsPossession::ComponentsPossession(Object * _pObj) :
			m_pOwner(_pObj)
		{
		}

		//-----------------------------------------------------------
		// dtor 
		//-----------------------------------------------------------
		ComponentsPossession::~ComponentsPossession()
		{
		}

		//-----------------------------------------------------------
		// copy ctor
		//-----------------------------------------------------------
		ComponentsPossession::
			ComponentsPossession(const ComponentsPossession & _other)
		{
			*this = _other;
		}
		//-----------------------------------------------------------
		// move ctor
		//-----------------------------------------------------------
		ComponentsPossession::
			ComponentsPossession(ComponentsPossession && _other)
		{
			*this = std::move(_other);
		}

		//-----------------------------------------------------------
		// = Copy
		//-----------------------------------------------------------
		ComponentsPossession &
			ComponentsPossession::operator=(const ComponentsPossession & _other)
		{
			m_AllComponents.clear();

			auto& componentFactory =
				::Utility::Factory<spComponent>::Instantiate();
			auto& SrcComponentList = _other.AllComponents;

			for_each(SrcComponentList, [&](auto& _)
			{
				m_AllComponents.push_back(
					componentFactory.Create(**_->AccessOfIndex(0))); 
			});

			//コピーコンストラクタの場合オブザーバーが生成されてないのでここで生成する
			auto& observer = m_pOwner->ComponentStateObservers;
			for_each(observer, [](auto& _) {SAFE_DELETE(_); });

			observer[GameObject::Observers::SubjectId::EffectiveState]
				= new ComponentEffectiveStateObserver(*m_pOwner);
			observer[GameObject::Observers::SubjectId::PriorityState]
				= new ComponentPriorityStateObserver(*m_pOwner);
			observer[GameObject::Observers::SubjectId::UpdataState]
				= new ComponentUpdataStateObserver(*m_pOwner);
			observer[GameObject::Observers::SubjectId::DrawState]
				= new ComponentRenderStateObserver(*m_pOwner);

			std::list<spComponent>	 result;
			transform(
				m_AllComponents,
				SrcComponentList.begin(),
				std::back_inserter(result),
				[&](spComponent _this, spComponent _oth)
			{
				*_this = *_oth;
				_this->pOwner = m_pOwner;
				for (int i = 0; i < GameObject::Observers::SubjectMax; i++)
				{
					_this->StateSubjects[i].Ovservers.clear();
					_this->StateSubjects[i].Attach(observer[i]);
				}
				return _this;
			});
			m_AllComponents = move(result);

			m_UpdatableComponents.Vector.clear();
			m_DrawbleComponents.Vector.clear();

			for_each(
				m_AllComponents,
				[&](auto& _)
			{
				if (_->UpdataQuery())
				{
					m_UpdatableComponents.AddRequest(_.get());
				}
				if (_->DrawQuery())
				{
					m_DrawbleComponents.AddRequest(_.get());
				}
			});

			m_UpdatableComponents.Apply();
			m_DrawbleComponents.Apply();

			return *this;
		}

		//-----------------------------------------------------------
		// = Move 
		//-----------------------------------------------------------
		ComponentsPossession &
			ComponentsPossession::operator=(ComponentsPossession && _other)
		{
			m_AllComponents.clear();

			m_AllComponents = std::move(_other.m_AllComponents);
			for_each(m_AllComponents, [&](auto& _) {_->pOwner = m_pOwner; });
			_other.m_AllComponents.clear();

			m_UpdatableComponents = std::move(_other.m_UpdatableComponents);
			m_DrawbleComponents = std::move(_other.m_DrawbleComponents);

			return *this;
		}

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

