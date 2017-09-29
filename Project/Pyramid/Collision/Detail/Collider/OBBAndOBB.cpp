/**
* @file		OBBAndOBB.cpp
* @brief	OBBëŒOBBÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OBBAndOBB.h"
#include"../HitEventPublisher.h"
#include"../Components/Collidee.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Collider
			{
				//-----------------------------------------------------------
				// Collision
				//-----------------------------------------------------------
				Utility::Nullable<ResultPair> 
					OBBAndOBB::IsCollision(IVolume * _pOBBa, IVolume * _pOBBb)
				{
					auto diagrams = CastToVolume(_pOBBa, _pOBBb);

					auto& OBBa = diagrams.first->ScaledBV;
					auto& OBBb = diagrams.second->ScaledBV;

					auto& calcVectorLengthToCollidee =
						[&](
							Common::Diagram::OBB& _obb,
							int _index)
					{
						return 
							_obb.LocalAxis[_index] *
							_obb.Half.AccessByIndex(_index);
					};

					auto& getLocalAxisToCollidee = 
						[&](
							Common::Diagram::OBB& _obb,
							int _index
							)
					{
						return _obb.LocalAxis[_index];
					};

					auto ObbALocalX = calcVectorLengthToCollidee(OBBa, 0);
					auto ObbALocalY = calcVectorLengthToCollidee(OBBa, 1);
					auto ObbALocalZ = calcVectorLengthToCollidee(OBBa, 2);
					auto ObbBLocalX = calcVectorLengthToCollidee(OBBb, 0);
					auto ObbBLocalY = calcVectorLengthToCollidee(OBBb, 1);
					auto ObbBLocalZ = calcVectorLengthToCollidee(OBBb, 2);

					auto ObbANomalizedLocalX = getLocalAxisToCollidee(OBBa, 0);
					auto ObbANomalizedLocalY = getLocalAxisToCollidee(OBBa, 1);
					auto ObbANomalizedLocalZ = getLocalAxisToCollidee(OBBa, 2);
					auto ObbBNomalizedLocalX = getLocalAxisToCollidee(OBBb, 0);
					auto ObbBNomalizedLocalY = getLocalAxisToCollidee(OBBb, 1);
					auto ObbBNomalizedLocalZ = getLocalAxisToCollidee(OBBb, 2);

					auto Distance = OBBa.Center - OBBb.Center;
					
#pragma region BoxNormal

					//aX
					auto rA = ObbALocalX.GetLength();
					auto rB = OBBb.CalculateHalfProjectLengthOnSeparatAxis(ObbANomalizedLocalX);
					auto L = std::abs(Utility::Vector3::Dot(Distance, ObbANomalizedLocalX));

					if (L > rA + rB)
					{
						return Utility::NullType();
					}

					//aY
					rA = ObbALocalY.GetLength();
					rB = OBBb.CalculateHalfProjectLengthOnSeparatAxis(ObbANomalizedLocalY);
					L = std::abs(Utility::Vector3::Dot(Distance, ObbANomalizedLocalY));

					if (L > rA + rB)
					{
						return Utility::NullType();
					}

					//aZ
					rA = ObbALocalZ.GetLength();
					rB = OBBb.CalculateHalfProjectLengthOnSeparatAxis(ObbANomalizedLocalZ);
					L = std::abs(Utility::Vector3::Dot(Distance, ObbANomalizedLocalZ));

					if (L > rA + rB)
					{
						return Utility::NullType();
					}


					//bX
					rA = OBBa.CalculateHalfProjectLengthOnSeparatAxis(ObbBNomalizedLocalX);
					rB = ObbBLocalX.GetLength();
					L = std::abs(Utility::Vector3::Dot(Distance, ObbBNomalizedLocalX));

					if (L > rA + rB)
					{
						return Utility::NullType();
					}

					//bY
					rA = OBBa.CalculateHalfProjectLengthOnSeparatAxis(ObbBNomalizedLocalY);
					rB = ObbBLocalY.GetLength();
					L = std::abs(Utility::Vector3::Dot(Distance, ObbBNomalizedLocalY));

					if (L > rA + rB)
					{
						return Utility::NullType();
					}

					//bZ
					rA = OBBa.CalculateHalfProjectLengthOnSeparatAxis(ObbBNomalizedLocalZ);
					rB = ObbBLocalZ.GetLength();
					L = std::abs(Utility::Vector3::Dot(Distance, ObbBNomalizedLocalZ));

					if (L > rA + rB)
					{
						return Utility::NullType();
					}

#pragma endregion

					auto& IsSeparat = [&]
						(
							const Utility::Vector3& _obbAAxis,
							const Utility::Vector3& _obbBAxis
						)
					{
						auto cross = Utility::Vector3::Cross(_obbAAxis, _obbBAxis);
						auto l = std::abs(Utility::Vector3::Dot(Distance, cross));
						auto rA = OBBa.CalculateHalfProjectLengthOnSeparatAxis(cross);
						auto rB = OBBb.CalculateHalfProjectLengthOnSeparatAxis(cross);
						
						return (l > rA + rB);
					};

					//aX cross
					if (IsSeparat(ObbANomalizedLocalX, ObbBNomalizedLocalX))
					{
						return Utility::NullType();
					}

					if (IsSeparat(ObbANomalizedLocalX, ObbBNomalizedLocalY))
					{
						return Utility::NullType();
					}

					if (IsSeparat(ObbANomalizedLocalX, ObbBNomalizedLocalZ))
					{
						return Utility::NullType();
					}

					//aY cross
					if (IsSeparat(ObbANomalizedLocalY, ObbBNomalizedLocalX))
					{
						return Utility::NullType();
					}

					if (IsSeparat(ObbANomalizedLocalY, ObbBNomalizedLocalX))
					{
						return Utility::NullType();
					}

					if (IsSeparat(ObbANomalizedLocalY, ObbBNomalizedLocalZ))
					{
						return Utility::NullType();
					}

					//aZ cross
					if (IsSeparat(ObbANomalizedLocalZ, ObbBNomalizedLocalX))
					{
						return Utility::NullType();
					}

					if (IsSeparat(ObbANomalizedLocalZ, ObbBNomalizedLocalX))
					{
						return Utility::NullType();
					}

					if (IsSeparat(ObbANomalizedLocalZ, ObbBNomalizedLocalZ))
					{
						return Utility::NullType();
					}

					return CreateHitResultFromCastedPair(diagrams);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------