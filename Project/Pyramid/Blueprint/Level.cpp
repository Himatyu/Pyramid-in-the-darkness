/**
* @file		Level.cpp
* @brief		レベルベース
* @author		S.OIKAWA
* @date		2016/07/31
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Level.h"
#include"../GameObject/Object.h"
#include"../GameObject/ObjectManager.h"
#include"Estd.h"
#include<string>
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		using namespace GameObject;
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Level::Level()
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		Level::~Level()
		{
		}

		//-----------------------------------------------------------
		// Updata
		//-----------------------------------------------------------

		void Level::Updata()
		{
		}

		//-----------------------------------------------------------
		// Draw
		//-----------------------------------------------------------
		
		void Level::Draw()
		{
		}

		//-----------------------------------------------------------
		// Destory
		//-----------------------------------------------------------
		void Level::Destory(GameObject::Object * _pObj)
		{
			m_ObjectManager.UnRegist(_pObj);
		}

		//-----------------------------------------------------------
		// FindWithTag
		//-----------------------------------------------------------
		Utility::Nullable<GameObject::Object*>
			Level::FindWithTag(std::string _tag)
		{
			auto& Objects = m_ObjectManager.AllObjects;
			auto pred = [_tag](Object* _pObj)->bool {return(_pObj->Tag == _tag); };
			auto pObj = Utility::Estd::find_if(Objects, pred);
			std::vector<int>::iterator;
			if (Objects.end() == pObj)
			{
				return Utility::Nullable<GameObject::Object*>();
			}

			return Utility::Nullable<GameObject::Object*>(*pObj);
		}

		//-----------------------------------------------------------
		// FindObjectsWithTag
		//-----------------------------------------------------------
		Utility::Nullable<std::vector<GameObject::Object*>>
			Level::FindObjectsWithTag(std::string _tag)
		{
			Utility::Nullable<std::vector<GameObject::Object*>> result;
			for (auto& it : m_ObjectManager.AllObjects)
			{
				if (!(it->Tag == _tag))
				{
					continue;
				}
				result.Value.push_back(it);
			}
			return result;
		}

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------