#pragma once
#include "SMLVector.h"

namespace SML
{
	#pragma region Class Declaration
	template <class T>
	class Euler
	{
	public:
		T x, y, z;
		Euler() { x = T(0); y = T(0);  z = T(0); }
		Euler(T& pitch, T& yaw, T& roll);

		SML::Vec3f ToVec() const;
		void Normalize();
	};
	#pragma endregion

	#pragma region Class Definitions
	template <class T>
	Euler<T>::Euler(T& pitch, T& yaw, T& roll)
	{
		x = pitch; y = yaw; z = roll;
	}

	template <class T>
	Vec3f Euler<T>::ToVec() const
	{
		SML::Vec3f result;
		result.x = cos(y) * cos(x);
		result.y = sin(x);
		result.z = sin(y) * cos(x);

		return result;
	}

	template <class T>
	void Euler<T>::Normalize()
	{
		if (x > 89)
			x = 89;
		if (x < -89)
			x = -89;

		while (y < -180)
			y += 360;
		while (y > 180)
			y -= 360;
	}
	#pragma endregion
}