/**
* @file		CollisionDetection.h
* @brief	衝突判定の実行方法を定義する
* @author	S.OIKAWA
* @date		2017.04.29
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		/// <summary>
		/// 衝突判定の精度
		/// </summary>
		enum class Detection : int
		{
			/// <summary>
			/// 現在位置衝突判定を行う。
			/// トンネリングは対策しない
			/// </summary>
			Discontinuity = 0, 

			/// <summary>
			/// Swept Volume Test
			/// 衝突図形のフレーム間ボリュームを生成し判定を行う
			/// 判定の際、フレーム間のどこで衝突したかを演算しない
			/// 衝突対象のObjectと現在のトランスフォームをイベントに流す
			/// 判定誤差はフレーム間の拡縮と回転量に比例して大きくなる
			/// 判定の際に回転・拡縮を無視できるが誤差が大きくなる
			/// </summary>
			SVT,

			/// <summary>
			/// 構造体のカウント
			/// 設定するとCollisionProviderでアサート
			/// </summary>
			Count,
		};
		
		/// <summary>
		/// 衝突判定の精度パラメータ
		/// </summary>
		class CollisionDetection final
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			CollisionDetection();
			~CollisionDetection() = default;

			CollisionDetection(const CollisionDetection&);
			CollisionDetection(CollisionDetection&&);

			CollisionDetection& operator=(const CollisionDetection&);
			CollisionDetection& operator=(CollisionDetection&&) ;
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
			PROPERTY_REF(m_Detection, Value, Detection);
			PROPERTY_REF(m_IsIgnoreRotateThenSVT,	IsIgnoreRotateThenSVT,	bool);
			PROPERTY_REF(m_IsIgnoreScaleThenSVT,	IsIgnoreScaleThenSVT,	bool);

#pragma endregion

#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Detection	m_Detection;

			bool		m_IsIgnoreRotateThenSVT;	
			bool		m_IsIgnoreScaleThenSVT;
#pragma endregion
		};

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------