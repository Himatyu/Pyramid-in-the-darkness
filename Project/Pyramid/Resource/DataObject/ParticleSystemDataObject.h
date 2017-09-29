/**
* @file		ParticleSystemDataObject.h
* @brief	UnityÇ∆ìØÇ∂àµÇ¢
* @author	S.OIKAWA
* @date		2017.05.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDataObjectFile.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Resources
	{
		namespace DataObject
		{
			/// <summary>
			/// ParticleSystemÇÃÉpÉâÉÅÅ[É^
			/// </summary>
			class ParticleSystemDataObject : 
				public IDataObjectFile
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleSystemDataObject() = default;
				~ParticleSystemDataObject() = default;

				ParticleSystemDataObject(const ParticleSystemDataObject&) = default;
				ParticleSystemDataObject(ParticleSystemDataObject&&) = default;

				ParticleSystemDataObject& operator=(const ParticleSystemDataObject&) = default;
				ParticleSystemDataObject& operator=(ParticleSystemDataObject&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------