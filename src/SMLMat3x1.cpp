#include "SMLMat3x1.h"
#include "SMLMat1x3.h"

SML::Mat3x1::Mat3x1(float A, float B, float C)
{
	a = A;
	b = B;
	c = C;
}

SML::Mat3x1::Mat3x1(Vector v)
{
	a = v.x;
	b = v.y;
	c = v.z;
}

SML::Mat3x1 SML::Mat3x1::operator*(const float& s) const
{
	return Mat3x1(s * a, s * b, s * c);
}

SML::Mat3x1 SML::Mat3x1::operator/(const float& s) const
{
	return Mat3x1(a / s, b / s, c / s);
}

SML::Mat3x1 SML::Mat3x1::operator+(const Mat3x1 m) const
{
	return Mat3x1(a + m.a, b + m.b, c + m.c);
}

SML::Mat3x1 SML::Mat3x1::operator-(const Mat3x1 m) const
{
	return Mat3x1(a - m.a, b - m.b, c - m.c);
}

SML::Mat1x3 SML::Mat3x1::transpose()
{
	return Mat1x3(a, b, c);
}
