/**
* @file		MorphableMesh.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MorphableMesh.h"
#include"../Utility/Vector3.h"
#include"../DataObject/Entity/FbxFile.h"
#include"../Resource/Model/FbxFile.h"
#include<vector>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	using namespace DataObject::Entity;

	namespace Components
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		MorphableMesh::MorphableMesh(std::string _path):
			Mesh(_path)
		{
		}
		//-----------------------------------------------------------
		// Init
		//-----------------------------------------------------------
		void MorphableMesh::Init(Common::Sp<Transform>& _transforom)
		{
			Mesh::Init(_transforom);
			auto& meshs = m_Model.spResourceFile->Meshs;
					
			auto IniVec = D3DXVECTOR3(0, 0, 0);
			m_MorphOffset.resize(meshs.size());
			int it = 0;
			for (auto& offsets : m_MorphOffset)
			{
				offsets.resize(meshs[it]->VertexCount, IniVec);
			}

		}

		//-----------------------------------------------------------
		// PreDraw
		//-----------------------------------------------------------
		void MorphableMesh::PreDraw()
		{
			Mesh::PreDraw();
			auto& meshs = m_Model.spResourceFile->Meshs;
			auto offsetIt = m_MorphOffset.begin();

			//Hack マルチスレッドできんかな？遅そう
			Fbx::Mesh_Vertex* pIt;
			for (auto& _ : meshs)
			{
				_->VertexBuffer.Data->Lock(0,0, (void**)&pIt,0);
				
				auto size = _->VertexBuffer.Count;
				auto& vertexs = _->VertexArray;
				for (unsigned i = 0; i < size; i++)
				{
					auto zero = D3DXVECTOR3(0, 0, 0);
					if ((*offsetIt)[i] == zero)
					{
						continue;
					}
					pIt[i].pos = ((*offsetIt)[i]*m_Progress) + vertexs[i];
				}
				_->VertexBuffer.Data->Unlock();
				offsetIt++;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------