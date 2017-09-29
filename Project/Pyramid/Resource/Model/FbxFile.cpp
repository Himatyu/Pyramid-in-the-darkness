/**
* @file		FbxModelFile.cpp
* @brief	モデルファイルベースの実装
* @author	S.OIKAWA
* @date		2016.09.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"FbxFile.h"
#include "../DataObject/Service.h"
#include "../DataObject/DAO/FbxFile.h"
#include "../DataObject/Entity/FbxFile.h"
#include"../Rendering/Graphics.h"
#include"../Rendering/Materials/MeshMaterial.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#define FVF_VERTEX_3D (D3DFVF_XYZ |D3DFVF_NORMAL| D3DFVF_TEX1 )
using namespace std;
namespace Pyramid
{
	namespace Resources
	{
		namespace Model
		{
			using namespace Blueprint;
			using namespace DataObject;
			/// <summary>
			/// メッシュ
			/// </summary>
			struct Mesh_Vertex
			{
				D3DXVECTOR3 pos;
				D3DXVECTOR3 normal;
				D3DXVECTOR2 uv;
			};

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			FbxFile::~FbxFile()
			{
				Discard();
			}

			//-----------------------------------------------------------
			// Read
			//-----------------------------------------------------------
			void FbxFile::Read(std::string _path)
			{
				SetFilePathInfo(_path);

				auto& ins = Service<Entity::FbxFile*, DAO::FbxFile>::Instantiate();
				m_pEntity = ins.Create(_path);
			}

			//-----------------------------------------------------------
			// DataCreateDependenceDevice
			//-----------------------------------------------------------
			void FbxFile::InitializeUseDaveice()
			{
				m_pEntity->InitializeUseDaveice();

				if (1 == m_pEntity->Meshs.size())
				{
					m_pEntity->Volume = m_pEntity->Meshs[0]->Volume;
					m_Volume = m_pEntity->Volume;
					return;
				}

				auto& vol = m_pEntity->Volume;
				for (auto& _ : m_pEntity->Meshs)
				{
					auto v = _->Volume;

					vol.Max.X = max(vol.Max.X, v.Max.X);
					vol.Max.Y = max(vol.Max.Y, v.Max.Y);
					vol.Max.Z = max(vol.Max.Z, v.Max.Z);

					vol.Min.X = min(vol.Min.X, v.Min.X);
					vol.Min.Y = min(vol.Min.Y, v.Min.Y);
					vol.Min.Z = min(vol.Min.Z, v.Min.Z);
				}
				m_Volume = m_pEntity->Volume;

			}

			//-----------------------------------------------------------
			// Discard
			//-----------------------------------------------------------
			void FbxFile::Discard()
			{
				SAFE_DELETE(m_pEntity);
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void FbxFile::SetMatrix(D3DXMATRIX & _mat)
			{
				m_pEntity->SetMatrix(_mat);
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			FbxInnerMesh::~FbxInnerMesh()
			{
				m_VertexBuffer.Delete(m_VertexBuffer.Data);
				m_IndexBuffer.Delete(m_IndexBuffer.Data);

				Utility::Estd::for_each(
					m_Materials, [](auto& _) {SAFE_DELETE(_); });
			}

			//-----------------------------------------------------------
			// IsHasUV
			//-----------------------------------------------------------
			bool FbxInnerMesh::IsHasUV()
			{
				return m_UVs.size();
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
