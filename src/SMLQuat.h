#pragma once
#include "SMLVector.h"

namespace SML
{
	class Quat
	{
	public:
		Quat();
		Quat(const Vec3f& axis, const float& angle);
		float x, y, z, w;

		float magnitude() const;

		Quat operator+(const Quat& q) const;
		Quat operator-(const Quat& q) const;
	};
}