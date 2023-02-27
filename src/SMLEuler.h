#pragma once
#include "SMLVector.h"

#pragma 
class Euler
{
public:
	float p, y, r;
	Euler();
	Euler(float& pitch, float& yaw, float& roll);

	SML::Vec3f ToVec() const;
	void Normalize();
};