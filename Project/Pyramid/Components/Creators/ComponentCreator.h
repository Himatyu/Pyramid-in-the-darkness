/**
* @file		ComponentCreator.h
* @brief	�R���|�[�l���g�̐����֐���񋟂���
* @author	S.OIKAWA
* @date		2016.02.19
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Creator.h"
#include"../Component.h"
#include<memory>

//-----------------------------------------------------------
// deffine
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		class Object;
	}
}

namespace Pyramid
{
	namespace Components
	{
		namespace Creators
		{

			/// <summary>
			///�R���|�[�l���g�̃N���G�C�^
			///�R���|�[�l���g���͂��̎q�𐶐�
			/// </summary> 
			///<typeparam name="Child">�����R���|�[�l���g�^</typeparam>
			///<typeparam name="Parent">�����^�X�}�|</typeparam>
			template<class Child,
				class Parent = std::shared_ptr<Component>>
				class ComponentCreator final :
				public Utility::Creator<Parent>
			{
			public:
				//-----------------------------------------------------------
				// ctor.dtor
				//-----------------------------------------------------------	
				ComponentCreator() = default;
				virtual ~ComponentCreator() = default;

				//-----------------------------------------------------------
				//  default
				//-----------------------------------------------------------

				ComponentCreator(const ComponentCreator&) = default;
				ComponentCreator(ComponentCreator&&) = default;

				ComponentCreator&operator=(const ComponentCreator&) = default;
				ComponentCreator&operator=(ComponentCreator&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
					/// <summary>Child�𐶐����X�}�|Parent�ŕԂ�</summary>
					///<returns>�e�����������R���|�[�l���g�̃X�}�|</returns>
				Parent Create() override;

				//-----------------------------------------------------------
				// Val
				//-----------------------------------------------------------
					/// <summary>
					/// �^���
					/// </summary>
				using ValueType = Child;
			};
#include"ComponentCreator.inl"

		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

