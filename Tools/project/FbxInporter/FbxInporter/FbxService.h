/**
	  * @file	FbxService
	  * @brief	FbxSDKのオーバーラップ
	  * @author	S.OIKAWA
	  * @date	2016.08.01
	  */
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#include<fbxsdk.h>
#include"singleton.h"
#include"Macro.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// Fbx管理情報
/// </summary>
class FBXServer : public Singleton<FBXServer>
{
public:
//-----------------------------------------------------------
// default
//-----------------------------------------------------------
	~FBXServer();

	FBXServer(const FBXServer&) = default;
	FBXServer(FBXServer&&) = default;

	FBXServer&operator=(const FBXServer&) = default;
	FBXServer&operator=(FBXServer&&) = default;

//-----------------------------------------------------------
// ctor 
//-----------------------------------------------------------
public:
	FBXServer();

//-----------------------------------------------------------
// property
//-----------------------------------------------------------
	PROPERTY(m_pManager, pManager, fbxsdk::FbxManager*);

private:

//-----------------------------------------------------------
// val
//-----------------------------------------------------------
	int lSDKMajor, lSDKMinor, lSDKRevision;

	fbxsdk::FbxManager*		m_pManager;
	fbxsdk::FbxIOSettings*	m_ios;
	fbxsdk::FbxString		m_AppPath;	
};

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

