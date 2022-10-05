#include "SMLMat1x3.h"
#include "SMLMat3x1.h"
#include "SMLMat3x3.h"

SML::Mat1x3::Mat1x3(const float& A, const float& B, const float& C)
{
	a = A;
	b = B;
	c = C;
}

SML::Mat1x3::Mat1x3(const Vector3& v)
{
	a = v.x;
	b = v.y;
	c = v.z;
}

SML::Mat1x3::Mat1x3(const Point3& v)
{
	a = v.x;
	b = v.y;
	c = v.z;
}

SML::Mat1x3 SML::Mat1x3::operator*(const float& s) const
{
	return Mat1x3(s * a, s * b, s * c);
}

SML::Mat1x3 SML::Mat1x3::operator/(const float& s) const
{
	return Mat1x3(a / s, b / s, c / s);
}

SML::Mat1x3 SML::Mat1x3::operator+(const Mat1x3& m) const
{
	return Mat1x3(a + m.a, b + m.b, c + m.c);
}

SML::Mat1x3 SML::Mat1x3::operator-(const Mat1x3& m) const
{
	return Mat1x3(a - m.a, b - m.b, c - m.c);
}

SML::Mat1x3 SML::Mat1x3::operator*(const Mat3x3& m) const
{
	return Mat1x3(
		((a * m.m[0][0]) + (b * m.m[1][0]) + (c * m.m[2][0])),
		((a * m.m[0][1]) + (b * m.m[1][1]) + (c * m.m[2][1])),
		((a * m.m[0][2]) + (b * m.m[1][2]) + (c * m.m[2][2])));
}

SML::Mat3x1 SML::Mat1x3::transpose() const
{
	return Mat3x1(a, b, c);
}

std::string SML::Mat1x3::toString() const
{
	std::string result;
	result += std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c);

	return result;
}
