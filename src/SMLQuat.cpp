#include "SMLQuat.h"
#include "SMLVector.h"

SML::Quat::Quat()
{
	x = y = z = 0;
}

SML::Quat::Quat(Vector3& axis, float& angle)
{
	x = axis.x * sin(angle / 2);
	y = axis.y * sin(angle / 2);
	z = axis.z * sin(angle / 2);

	w = cos(angle / 2);
}

float SML::Quat::magnitude() const
{
	return (sqrt(double(x * x) + double(y * y) + double(z * z) + double(w * w)));
}

SML::Quat SML::Quat::operator+(const Quat& q) const
{
	Quat result;
	result.x = x + q.x;
	result.y = y + q.y;
	result.z = z + q.z;
	result.w = w + q.w;
	return result;
}

SML::Quat SML::Quat::operator-(const Quat& q) const
{
	Quat result;
	result.x = x - q.x;
	result.y = y - q.y;
	result.z = z - q.z;
	result.w = w - q.w;
	return result;
}

