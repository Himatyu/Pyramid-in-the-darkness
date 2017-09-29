/**
* @file		Collidee.inl
* @brief	衝突判定を受ける
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------


#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// ctor
/// </summary>
template<class ...Diagrams>
inline 
Collidee<Diagrams...>::Collidee(): 
	m_Judgment(m_OctVolume),
	m_IsStatic(false)
{
	Component::TypeApply<Collidee<Diagrams...>>();
	m_Judgment.Add(this);
	ParseRegister<DiagramList>();
}

/// <summary>
/// dtor
/// </summary>
template<class ...Diagrams>
inline 
Pyramid::Components::Collidee<Diagrams...>::~Collidee()
{
	m_Judgment.Remove(this);

	Common::WorldSpaceDivider::Instantiate()
		.UnRegister(m_Judgment);

	Collision::Detail::CollisionSystem::Instantiate()
		.WithdrawOfRequest(this);
}

/// <summary>
/// Init
/// </summary>
template<class ...Diagrams>
inline 
void 
Collidee<Diagrams...>::Init(Common::Sp<Transform>& _transform)
{
	m_spTransform = _transform;

	m_OctVolume.pPosition =	&m_spTransform->Position;
	for (auto& _ : m_BVList)
	{
		_->ReflectionOfTransfrom(m_spTransform);
	}

	Common::WorldSpaceDivider::Instantiate()
		.Register(m_Judgment);

	___DEBUG_CALL(AdditionalInit();)
}

/// <summary>
/// Updata
/// </summary>
template<class ...Diagrams>
inline void Collidee<Diagrams...>::Updata()
{
	UpdateTransform(m_spTransform);

	for (auto& _ : m_BVList)
	{
		_->ReflectionOfTransfrom(m_spTransform);
	}

	Common::WorldSpaceDivider::Instantiate()
		.ReRegister(m_Judgment);

	if (m_IsStatic)
	{
		return;
	}

	if (m_Judgment.SameSpaceList.empty())
	{
		return;
	}

	m_Judgment.ExcludesOtherTypeObjectInSameSpace();	
	std::list<Collision::Detail::ICollidee*> casted;
	for (auto& _ : m_Judgment.SameSpaceList)
	{
		Utility::Estd::combineList(
			casted,
			_->CastTo<Collision::Detail::JudgmentSameSpaceOfCollidee*>()
			->CollideeList);
	}

	auto& system =
		Collision::Detail::CollisionSystem::Instantiate();
	system.RequestOfCollision(this, casted);
}


//-----------------------------------------------------------
// AccessOfVolumeForIndex
//-----------------------------------------------------------
template<class ...Diagrams>
inline
Collision::IVolume*
Collidee<Diagrams...>::AccessOfVolumeForIndex(UINT _index)
{
	return m_BVList[_index];
}

//-----------------------------------------------------------
// AccessOfCastedVolumeForIndex
//-----------------------------------------------------------
template<class ...Diagrams>
template<unsigned Index>
inline
Collision::Volume
<
	typename Utility::ArgsAt
	<
		Index,
		typename Utility::Args<Diagrams...>
	>::Result
>*
Pyramid::Components::Collidee<Diagrams...>::AccessOfCastedVolumeForIndex()
{
	return m_BVList[Index]->
		CastTo<
			Collision::Volume
			<
				typename Utility::TypeAt<Index,DiagramList>::Result
			>*
		>();
}

#pragma region HitEvent

/// <summary>
/// OnCollisionEnter
/// </summary>
template<class ...Diagrams>
inline 
void 
Collidee<Diagrams...>::
OnCollisionEnter(Collision::HitResult _hit)
{
	for (auto& _ : m_Container)
	{
		_->OnCollisionEnter(_hit);
	}
}

/// <summary>
/// OnCollisionStay
/// </summary>
template<class ...Diagrams>
inline 
void 
Collidee<Diagrams...>::
OnCollisionStay(Collision::HitResult _hit)
{
	for (auto& _ : m_Container)
	{
		_->OnCollisionStay(_hit);
	}
}

/// <summary>
/// OnCollisionExit
/// </summary>
template<class ...Diagrams>
inline 
void 
Collidee<Diagrams...>::
OnCollisionExit(Collision::HitResult _hit)
{
	for (auto& _ : m_Container)
	{
		_->OnCollisionExit(_hit);
	}
}
#pragma endregion

#pragma region Divider
namespace
{
	//関数の部分特殊化回避
	template<class TyList>
	struct ListDivider
	{
		static void RegisterVolumeAfterTheDivision(
			std::vector< Common::Sp<Collision::IVolume>>& _list,
			Collision::Detail::ICollidee* _pCollidee)
		{
			_list.push_back(
				std::make_shared<Collision::Volume<TyList::Head>>(_pCollidee));

			ListDivider<TyList::Tail>::
				RegisterVolumeAfterTheDivision(_list, _pCollidee);
		};
	};

	template<>
	struct ListDivider<::Utility::NullType>
	{
		static void RegisterVolumeAfterTheDivision(
			std::vector<Common::Sp<Collision::IVolume>>&,
			Collision::Detail::ICollidee* )
		{
			return;
		};
	};
}
#pragma endregion


/// <summary>
/// ParseRegister
/// </summary>
template<class ...Diagrams>
template<class DiagramTypeList>
inline 
void 
Collidee<Diagrams...>::ParseRegister()
{
	ListDivider<DiagramTypeList>::
		RegisterVolumeAfterTheDivision(m_BVList,this);
}

//___DEBUG_DEFINE(

namespace
{
	template<class Ty>
	struct Model
	{
		static constexpr char* Path = "";
		static void ReflectTransform(
			Common::Sp<Mesh>& _spMesh,
			Common::Sp<Transform>& _spTransform,
			Common::Sp<Collision::IVolume> _spVolume)
		{}
	};

	template<>
	struct Model<Pyramid::Common::Diagram::AABB>
	{
		static constexpr char* Path = "Assets/Model/Debug/Box.bm";
		static void ReflectTransform(
			Common::Sp<Mesh>& _spMesh,
			Common::Sp<Transform>& _spTransform,
			Common::Sp<Collision::IVolume> _spVolume)
		{
			auto pVolume =
				_spVolume->CastTo<Collision::Volume<
							Pyramid::Common::Diagram::AABB>*>();

			auto& volume = pVolume->ScaledBV;			
			_spTransform->Scale = (volume.Max - volume.Min) / 2;
		}
	};

	template<>
	struct Model<Pyramid::Common::Diagram::OBB>
	{
		static constexpr char* Path = "Assets/Model/Debug/Box.bm";
		static void ReflectTransform(
			Common::Sp<Mesh>& _spMesh,
			Common::Sp<Transform>& _spTransform,
			Common::Sp<Collision::IVolume> _spVolume)
		{

			auto pVolume =
				_spVolume->CastTo<Collision::Volume<
									Pyramid::Common::Diagram::OBB>*>();

			_spTransform->Scale = pVolume->ScaledBV.Half; //図形単位の1と描画単位の1は同値
			//回転は今んとこ非対応
		}
	};

	template<>
	struct Model<Pyramid::Common::Diagram::Sphere>
	{
		static constexpr char* Path = "Assets/Model/Debug/Sphere.bm";
		static void ReflectTransform(
			Common::Sp<Mesh>& _spMesh,
			Common::Sp<Transform>& _spTransform,
			Common::Sp<Collision::IVolume> _spVolume)
		{
			auto pVolume = 
				_spVolume->CastTo<Collision::Volume<
							Pyramid::Common::Diagram::Sphere>*>();

			auto half = pVolume->ScaledBV.R;
			_spTransform->Scale = Utility::Vector3::once * half;
		}
	};

	/// <summary>
	/// デバック用のコンポーネントを追加、初期化する
	/// </summary>
	template<class TyList>
	struct Adder
	{
		static void 
			AddDebugMeshAfterTheInit(
				Pyramid::GameObject::Object* _pObj,unsigned _index)
		{
			auto trans = _pObj->AddComponent<Transform>();
			trans->Init();
			trans->Tag = 
				"DebugCollisionModelTransform" + std::to_string(_index);
			trans->IsFixingRotate =
				std::is_same<
					TyList::Head, 
					Pyramid::Common::Diagram::AABB>::value;

			auto& mesh =
				_pObj->AddComponent<Mesh>(
					Model<typename TyList::Head>::Path);
			mesh->Tag = "DebugCollisionModel" + std::to_string(_index);
			mesh->Init(trans);
			mesh->MeshRender.SetMLRC(Rendering::RendringPriority::Transparent);
			mesh->MeshRender.RenderID = 30000; //test
			mesh->IsRenderingAABB = false;

			Pyramid::Rendering::Materials::ColorValue emmit;
			emmit =
				Pyramid::Components::Constant::EmissiveOfDebugCollisinVolume[_index % 12];

			auto& material = mesh->Materials;
			for (auto& _ : material)
			{
				_->Diffuse.Value = { 0.5f,0,1,1.0f };
				_->Emissive.Value = emmit;
				_->Ambient.Value = { 0,0,0,0 };
				_->Transparency = 0.9f;
			}
			Adder<TyList::Tail>::AddDebugMeshAfterTheInit(_pObj, _index+1);
		}
	};

	template<>
	struct Adder<::Utility::NullType>
	{
		static void 
			AddDebugMeshAfterTheInit(
				Pyramid::GameObject::Object* _pObj, unsigned _index)
		{
		}
	};

	/// <summary>
	/// デバック用のコンポーネントを更新する
	/// </summary>
	template<class Ty>
	struct Updater
	{
		static void Update(
			Pyramid::GameObject::Object* _pObj,
			Common::Sp<Transform>& _spTransform,
			std::vector<Common::Sp<Collision::IVolume>>& _volume,
			unsigned _index)
		{
			auto& trans = 
				_pObj->GetComponentFromTag<Transform>(
						"DebugCollisionModelTransform"+std::to_string(_index));

			auto& mesh =
				_pObj->GetComponentFromTag<Mesh>(
						"DebugCollisionModel" + std::to_string(_index));

			trans->Position = 
				_spTransform->Position + _volume[_index]->Offset.Position;
			trans->Rotation = 
				_spTransform->Rotation + _volume[_index]->Offset.Rotation;
			trans->Scale = 
				_spTransform->Scale * _volume[_index]->Offset.Scale;

			Model<Ty::Head>::ReflectTransform(*mesh, *trans, _volume[_index]);
			Updater<Ty::Tail>::Update(_pObj, _spTransform, _volume, _index+1);
		}
	};

	template<>
	struct Updater<::Utility::NullType>
	{
		static void Update(
			Pyramid::GameObject::Object* _pObj,
			Common::Sp<Transform>& spTransform,
			std::vector<Common::Sp<Collision::IVolume>>& _volume,
			unsigned _index)
		{			
		}
	};

}

/// <summary>
/// AdditionalInit
/// </summary>
template<class ...Diagrams>
inline 
void Collidee<Diagrams...>::AdditionalInit()
{	
	Adder<DiagramList>::AddDebugMeshAfterTheInit(m_pOwner,0);
}

/// <summary>
/// AdditionalUpdataOfDebug
/// </summary>
template<class ...Diagrams>
inline
void Collidee<Diagrams...>::AdditionalUpdataOfDebug()
{
	Updater<DiagramList>::Update(m_pOwner,spTransform,m_BVList,0);
}

//)

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------