/**
* @file		TaskOrder.inl
* @brief	コンポーネント・オブジェクトにタスクを登録する機能を提供
* @author	S.OIKAWA
* @date		2016.09.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TaskOrder.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

//-----------------------------------------------------------
// dtor
//-----------------------------------------------------------
template<class Type>
TaskOrder<Type>::~TaskOrder()
{
	Utility::Estd::for_each(m_OrderList,
		[](auto& _) {SAFE_DELETE(_->pJob); SAFE_DELETE(_); });
}

//-----------------------------------------------------------
// Order
//-----------------------------------------------------------
template<class Type>
template<class Func>
void TaskOrder<Type>::Order(
	Func && _func, 
	std::string _group, 
	u_int _lineID)
{
	auto pExe = new Utility::Executer<Type>();
	pExe->Register(_func, static_cast<Type*>(this));
	auto pData = new OrderData(
		static_cast<Utility::IExecuteable*>(pExe), _group, _lineID);
	m_OrderList.push_back(pData);

	auto& ins = OrderedJobReserver::Instantiate();
	ins.Register(pData->pJob, pData->Group, pData->LineID);
}

//-----------------------------------------------------------
// OrderCancel
//-----------------------------------------------------------
template<class Type>
void TaskOrder<Type>::OrderCancel(OrderData* _data)
{
	if (!_data)
	{
		return;
	}
	auto& ins = OrderedJobReserver::Instantiate();
	ins.UnRegister(_data->pJob, _data->Group, _data->LineID);
	m_OrderList.erase(Utility::Estd::find(m_OrderList, _data));
	SAFE_DELETE(_data->pJob);
	SAFE_DELETE(_data);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------