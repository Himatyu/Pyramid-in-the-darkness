/**
* @file		Buffer.h
* @brief	DirectXのレンダリングに使用するバッファ（Vertex,Index）
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer/CommonIncluder.h"

#pragma endregion

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Rendering
	{
		/// <summary>
		/// バッファ
		/// </summary>
		template<class Ty,
			template<class> class Create = Common::Policy::StdCreate,
			template<class> class Delete = Common::Policy::StdDelete>
		class Buffer final :
			public Create<Ty>,
			public Delete<Ty>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Buffer() = default;
			~Buffer() = default;

			Buffer(const Buffer&) = default;
			Buffer(Buffer&&) = default;

			Buffer& operator=(const Buffer&) = default;
			Buffer& operator=(Buffer&&) = default;
#pragma endregion
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			operator Ty() const;

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_Buffer, Data, Ty);
			PROPERTY_REF(m_Count, Count, size_t);
			PROPERTY_REF(m_TypeSize, TypeSize, size_t);

#pragma endregion
		private:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Ty				m_Buffer;
			size_t			m_Count;
			size_t			m_TypeSize;
#pragma endregion
		};
#include"Buffer.inl"

		//HACK ここに書くべきか？
		using DirectXVertexBuffer = Rendering::Buffer<
			LPDIRECT3DVERTEXBUFFER9, 
			Common::Policy::DirectXVertexBufferCreate, 
			Common::Policy::DirectXBufferDaleta>;

		using DirectXIndexBuffer = Rendering::Buffer<
			LPDIRECT3DINDEXBUFFER9, 
			Common::Policy::DirectXIndexBufferCreate,
			Common::Policy::DirectXBufferDaleta>;

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
