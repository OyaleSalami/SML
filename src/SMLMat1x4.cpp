#include "SMLMat1x4.h"
#include "SMLMat4x1.h"
#include "SMLMat4x4.h"

SML::Mat1x4::Mat1x4(const float& A, const float& B, const float& C, const float& D)
{
	a = A;
	b = B;
	c = C;
	d = D;
}

SML::Mat1x4::Mat1x4(const Vector& v)
{
	a = v.x;
	b = v.y;
	c = v.z;
}

SML::Mat1x4::Mat1x4(const Point& v)
{
	a = v.x;
	b = v.y;
	c = v.z;
	d = 1;
}

SML::Mat1x4 SML::Mat1x4::operator*(const float& s) const
{
	return Mat1x4(s * a, s * b, s * c, s * d);
}

SML::Mat1x4 SML::Mat1x4::operator/(const float& s) const
{
	return Mat1x4(a / s, b / s, c / s, d / s);
}

SML::Mat1x4 SML::Mat1x4::operator+(const Mat1x4& m) const
{
	return Mat1x4(a + m.a, b + m.b, c + m.c, d + m.d);
}

SML::Mat1x4 SML::Mat1x4::operator-(const Mat1x4& m) const
{
	return Mat1x4(a - m.a, b - m.b, c - m.c, d - m.d);
}

SML::Mat1x4 SML::Mat1x4::operator*(const Mat4x4& m) const
{
	return Mat1x4
	(
		(a * m.m[0][0] + b * m.m[1][0] + c * m.m[2][0] + d * m.m[3][0]),
		(a * m.m[0][1] + b * m.m[1][1] + c * m.m[2][1] + d * m.m[3][1]),
		(a * m.m[0][2] + b * m.m[1][2] + c * m.m[2][2] + d * m.m[3][2]),
		(a * m.m[0][3] + b * m.m[1][3] + c * m.m[2][3] + d * m.m[3][3])
	);
}

SML::Mat4x1 SML::Mat1x4::transpose() const
{
	return Mat4x1(a, b, c, d);
}

std::string SML::Mat1x4::toString() const
{
	std::string result;
	result += std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d);

	return result;
}
