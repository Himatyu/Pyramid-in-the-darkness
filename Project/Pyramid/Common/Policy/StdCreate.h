/**
* @file		StdCreate.h
* @brief	new�ō쐬����|���V�[
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

namespace Pyramid
{
	namespace Common
	{
		namespace Policy
		{
			/// <summary>
			/// new�ō쐬����|���V�[
			/// </summary>
			template<class Ty>
			struct StdCreate
			{
				Ty* Create() { return new Ty; }
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------