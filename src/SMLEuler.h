#pragma once
#include <math.h>
#include "SMLVector.h"

class Euler
{
public:
	float p, y, r;
	Euler();
	Euler(float& pitch, float& yaw, float& roll);

	SML::Vector3 ToVector() const;
	void Normalize();
};