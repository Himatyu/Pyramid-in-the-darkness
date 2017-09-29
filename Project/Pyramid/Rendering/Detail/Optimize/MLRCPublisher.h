/**
* @file		MLRCPublisher.h
* @brief	��������s���A�K�v�ł���΃����_�����O���s��
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"VisibleDeterminer.h"
#include"../../RendringPriority.h"
#include"../../Detail/Optimize/MLRC.h"
#include"../MT/Order/IMLRCPublishable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			class OptimizationRender;
			class Frustum;
		}
	}
}

#pragma endregion
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				/// <summary>
				/// ��������s���A�K�v�ł���΃R�}���h�̔��s���s��
				/// OptimizationRender�Ή��Ȃ̂�MT�ōœK�����s���̂��O�񂾂���
				/// </summary>
				class MLRCPublisher :
					public MT::Order::IMLRCPublishable
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					MLRCPublisher(Common::WorldVolume&, OptimizationRender*);
					virtual ~MLRCPublisher() = default;

					MLRCPublisher(const MLRCPublisher&);
					MLRCPublisher(MLRCPublisher&&) = default;

					MLRCPublisher& operator=(const MLRCPublisher&);
					MLRCPublisher& operator=(MLRCPublisher&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// �R�}���h���s�̗L�����m�F����
					/// </summary>
					bool IsPublish(Frustum&);

					/// <summary>
					/// MLRC�̃R�}���h��ݒ肷��
					/// </summary>
					void SetMLRCommand(UINT);

					/// <summary>
					/// 
					/// </summary>
					MLRC* PublishMLRC() override;

#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF(m_IsCommandPublish, IsCommandPublish, bool);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					VisibleDeterminer			m_Determiner;
					MLRC						m_MLRC;
					bool						m_IsCommandPublish = true;
					OptimizationRender*			m_pRender;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------