#include "FbxModelFile.h"
#include"Macro.h"
#include<algorithm>
#include "DateObject\FbxInnerMesh.h"
using namespace std;

//-----------------------------------------------------------
// dtor
//-----------------------------------------------------------
FbxModelFile::~FbxModelFile()
{
	___FOREACH(meshs, [](auto& _) {SAFE_DELETE(_); });
}


FbxInnerMesh::~FbxInnerMesh()
{
	___FOREACH(m_Materials, [](auto& _) {SAFE_DELETE(_); });
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

