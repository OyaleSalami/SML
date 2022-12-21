#include "SMLMat4x1.h"
#include "SMLMat1x4.h"

SML::Mat4x1::Mat4x1(const float& A, const float& B, const float& C, const float& D)
{
	a = A;
	b = B;
	c = C;
	d = D;
}

SML::Mat4x1::Mat4x1(const Vector3& v)
{
	a = v.x;
	b = v.y;
	c = v.z;
}

SML::Mat4x1::Mat4x1(const Point3& v)
{
	a = v.x;
	b = v.y;
	c = v.z;
	d = 1;
}

SML::Mat4x1 SML::Mat4x1::operator*(const float& s) const
{
	return Mat4x1(s * a, s * b, s * c, s * d);
}

SML::Mat4x1 SML::Mat4x1::operator/(const float& s) const
{
	return Mat4x1(a / s, b / s, c / s, d / s);
}

SML::Mat4x1 SML::Mat4x1::operator+(const Mat4x1& m) const
{
	return Mat4x1(a + m.a, b + m.b, c + m.c, d + m.d);
}

SML::Mat4x1 SML::Mat4x1::operator-(const Mat4x1& m) const
{
	return Mat4x1(a - m.a, b - m.b, c - m.c, d - m.d);
}

SML::Mat1x4 SML::Mat4x1::transpose() const
{
	return Mat1x4(a, b, c, d);
}

std::string SML::Mat4x1::toString() const
{
	std::string result;
	result += std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d);

	return result;
}
