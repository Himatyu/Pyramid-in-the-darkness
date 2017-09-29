/**
* @file	FbxService.cpp
* @brief	FbxSDKのオーバーラップ
* @author	S.OIKAWA
* @date	2016.08.02
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxService.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
using namespace fbxsdk;

//-----------------------------------------------------------
// dtor 
//-----------------------------------------------------------
FBXServer::~FBXServer()
{
	pManager->Destroy();
}

//-----------------------------------------------------------
// FBXServer::ctor
//-----------------------------------------------------------
FBXServer::FBXServer()
{
	pManager = FbxManager::Create();

	m_ios = FbxIOSettings::Create(pManager, IOSROOT);
	pManager->SetIOSettings(m_ios);

	m_AppPath = FbxGetApplicationDirectory();
	pManager->LoadPluginsDirectory(m_AppPath.Buffer());
};

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------