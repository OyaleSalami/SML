#include "SMLEuler.h"

Euler::Euler()
{
	p = y = r = 0;
}

Euler::Euler(float& pitch, float& yaw, float& roll)
{
	p = pitch; y = yaw, r = roll;
}

SML::Vector3 Euler::ToVector() const
{
	SML::Vector3 result;
	result.x = cos(y) * cos(p);
	result.y = sin(p);
	result.z = sin(y) * cos(p);

	return result;
}

void Euler::Normalize()
{
	if (p > 89)
		p = 89;
	if (p < -89)
		p = -89;

	while (y < -180)
		y += 360;
	while (y > 180)
		y -= 360;
}