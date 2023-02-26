#pragma once
#include <math.h>

namespace SML
{
	class Vec3;
	class Quat
	{
	public:
		Quat();
		Quat(const Vec3& axis, const float& angle);
		float x, y, z, w;

		float magnitude() const;

		Quat operator+(const Quat& q) const;
		Quat operator-(const Quat& q) const;


	};
}