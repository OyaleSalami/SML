#pragma once
#include <math.h>

namespace SML
{
	class Vector;
	class Quat
	{
	public:
		Quat();
		Quat(Vector& axis, float& angle);
		float x, y, z, w;

		float magnitude() const;

		Quat operator+(const Quat& q) const;
		Quat operator-(const Quat& q) const;


	};
}