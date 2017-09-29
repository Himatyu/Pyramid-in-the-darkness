/**
* @file		StdDelete.h
* @brief	delete‚Å”jŠü‚·‚é
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
			/// new‚Åì¬‚·‚éƒ|ƒŠƒV[
			/// </summary>
			template<class Ty>
			struct StdDelete
			{
				void Delete(Ty* _p) { delete _p; }
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------