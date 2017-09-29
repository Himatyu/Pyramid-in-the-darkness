/**
* @file		ConvertProvider.h
* @brief	�R���o�[�^��񋟂���
* @author	S.OIKAWA
* @date		2017.04.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"IConverter.h"
#include"ICastable.h"
#include"TypeComparable.h"
#include"Nullable.h"
#include<vector>
#include<memory>

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			namespace Converter
			{
				/// <summary>
				///�R���o�[�^��񋟂���
				/// �������Ă邯�ǁE�E�E�R���o�[�^���I
				/// </summary>
				class ConvertProvider : 
					public Utility::Singleton<ConvertProvider>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					ConvertProvider();
					~ConvertProvider();

					ConvertProvider(const ConvertProvider&) = default;
					ConvertProvider(ConvertProvider&&) = default;

					ConvertProvider& operator=(const ConvertProvider&) = default;
					ConvertProvider& operator=(ConvertProvider&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					///�R���o�[�g����
					/// </summary>
					template<class Ty,class Result>
					Utility::Nullable<Result> Convert(Ty&);
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
				private:
					std::vector<IConverter*>		m_Converters;
#pragma endregion
				};
#include"ConvertProvider.inl"
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------