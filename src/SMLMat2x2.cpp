#include "SMLMat2x2.h"

SML::Mat2x2::Mat2x2(const float& a, const float& b, const float& c, const float& d)
{
	m[0][0] = a;  m[0][1] = b;
	m[1][0] = c;  m[1][1] = d;
}

SML::Mat2x2::Mat2x2(const Vector& r1, const Vector& r2)
{
	m[0][0] = r1.x;  m[0][1] = r1.y;
	m[1][0] = r2.x;  m[1][1] = r2.y;
}

SML::Mat2x2::Mat2x2(const Mat2x2& v)
{
	m[0][0] = v.m[0][0];  m[0][1] = v.m[0][1];
	m[1][0] = v.m[1][0];  m[1][1] = v.m[1][1];
}

float SML::Mat2x2::det()const
{
	return(m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

SML::Mat2x2 SML::Mat2x2::operator+(const Mat2x2& v)const
{
	return Mat2x2(m[0][0] + v.m[0][0], m[0][1] + v.m[0][1], m[1][0] + v.m[1][0], m[1][1] + v.m[1][1]);
	/*Vector result;
	_declspec(align(16)) Vector X(m[0][0], m[][], m[][]);
	_declspec(align(16)) Vector Y(v.m[][], v.m[][], v.m[][]);

	_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

	return result;*/
}

SML::Mat2x2 SML::Mat2x2::operator-(const Mat2x2& v)const
{
	return Mat2x2(m[0][0] - v.m[0][0], m[0][1] - v.m[0][1], m[1][0] - v.m[1][0], m[1][1] - v.m[1][1]);
}

SML::Mat2x2 SML::Mat2x2::operator*(const float& s)const
{
	return Mat2x2(m[0][0] * s, m[0][1] * s, m[1][0] * s, m[1][1] * s);
}

SML::Mat2x2 SML::Mat2x2::operator/(const float& s)const
{
	return Mat2x2(m[0][0] / s, m[0][1] / s, m[1][0] / s, m[1][1] / s);
}

SML::Mat2x2 SML::Mat2x2::Transpose() const
{
	return Mat2x2(m[0][0], m[1][0], m[0][1], m[1][1]);
}

SML::Mat2x2 SML::Mat2x2::Identity()
{
	return Mat2x2(1, 0,
				  0, 1);
}

std::string SML::Mat2x2::toString() const
{
	std::string result;

	result += std::to_string(m[0][0]) + ", " + std::to_string(m[1][0]) + "\n" +
		std::to_string(m[0][1]) + ", " + std::to_string(m[1][1]) + "\n";

	return result;
}

SML::Mat2x2 SML::Mat2x2::operator*(const Mat2x2& v)const
{
	return Mat2x2(m[0][0] * v.m[0][0] + m[0][1] * v.m[1][0], m[0][0] * v.m[0][1] + m[0][1] * v.m[1][1], m[1][0] * v.m[0][0] + m[1][1] * v.m[1][0], m[1][0] * v.m[0][1] + m[1][1] * v.m[1][1]);
}