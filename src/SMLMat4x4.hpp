#include "SMLMat4x4.h"

SML::Mat4x4::Mat4x4(const Mat4x4& a)
{
	m[0][0] = a.m[0][0]; m[0][1] = a.m[0][1]; m[0][2] = a.m[0][2]; m[0][3] = a.m[0][3];

	m[1][0] = a.m[1][0]; m[1][1] = a.m[1][1]; m[1][2] = a.m[1][2]; m[1][3] = a.m[1][3];

	m[2][0] = a.m[2][0]; m[2][1] = a.m[2][1]; m[2][2] = a.m[2][2]; m[2][3] = a.m[2][3];

	m[3][0] = a.m[3][0]; m[3][1] = a.m[3][1]; m[3][2] = a.m[3][2]; m[3][3] = a.m[3][3];
}

SML::Mat4x4::Mat4x4(const float& m1, const float& m2, const float& m3, const float& m4, const float& m5, const float& m6, const float& m7, const float& m8, const float& m9, const float& m10, const float& m11, const float& m12, const float& m13, const float& m14, const float& m15, const float& m16)
{
	m[0][0] = m1; m[0][1] = m2; m[0][2] = m3; m[0][3] = m4;

	m[1][0] = m5; m[1][1] = m6; m[1][2] = m7; m[1][3] = m8;

	m[2][0] = m9; m[2][1] = m10; m[2][2] = m11; m[2][3] = m12;

	m[3][0] = m13; m[3][1] = m14; m[3][2] = m15; m[3][3] = m16;
}

SML::Mat4x4::Mat4x4(const Vec3f& r1, const Vec3f& r2, const Vec3f& r3, const Vec3f& t)
{
	m[0][0] = r1.x; m[0][1] = r1.y; m[0][2] = r1.z;		 //m[0][3] = m4;

	m[1][0] = r2.x; m[1][1] = r2.y; m[1][2] = r2.z;		 //m[1][3] = m8;

	m[2][0] = r3.x; m[2][1] = r3.y; m[2][2] = r3.z;		 //m[2][3] = m12;

	m[3][0] = t.x;  m[3][1] = t.y;  m[3][2] = t.z;		 m[3][3] = 1;
}

SML::Mat4x4::Mat4x4(const Mat3x3& r, const Vec3f& t)
{
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2];		 //m[0][3] = m4;

	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2];		 //m[1][3] = m8;

	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2];		 //m[2][3] = m12;

	m[3][0] = t.x;  m[3][1] = t.y;  m[3][2] = t.z;						   m[3][3] = 1;
}

SML::Mat4x4 SML::Mat4x4::operator/(const float& s) const
{
	return Mat4x4(m[0][0] / s, m[0][1] / s, m[0][2] / s, m[0][3] / s,
		m[1][0] / s, m[1][1] / s, m[1][2] / s, m[1][3] / s,
		m[2][0] / s, m[2][1] / s, m[2][2] / s, m[2][3] / s,
		m[3][0] / s, m[3][1] / s, m[3][2] / s, m[3][3] / s);
}

SML::Mat4x4 SML::Mat4x4::operator+(const Mat4x4& v) const
{
	return Mat4x4(
		m[0][0] + v.m[0][0], m[0][1] + v.m[0][1], m[0][2] + v.m[0][2], m[0][3] + v.m[0][3],

		m[1][0] + v.m[1][0], m[1][1] + v.m[1][1], m[1][2] + v.m[1][2], m[1][3] + v.m[1][3],

		m[2][0] + v.m[2][0], m[2][1] + v.m[2][1], m[2][2] + v.m[2][2], m[2][3] + v.m[2][3],

		m[3][0] + v.m[3][0], m[3][1] + v.m[3][1], m[3][2] + v.m[3][2], m[3][3] + v.m[3][3]);
}

SML::Mat4x4 SML::Mat4x4::operator-(const Mat4x4& v) const
{
	return Mat4x4(
		m[0][0] - v.m[0][0], m[0][1] - v.m[0][1], m[0][2] - v.m[0][2], m[0][3] - v.m[0][3],

		m[1][0] - v.m[1][0], m[1][1] - v.m[1][1], m[1][2] - v.m[1][2], m[1][3] - v.m[1][3],

		m[2][0] - v.m[2][0], m[2][1] - v.m[2][1], m[2][2] - v.m[2][2], m[2][3] - v.m[2][3],

		m[3][0] - v.m[3][0], m[3][1] - v.m[3][1], m[3][2] - v.m[3][2], m[3][3] - v.m[3][3]);
}

SML::Mat4x4 SML::Mat4x4::operator*(const Mat4x4& B) const
{
	return Mat4x4(
		/*00*/(m[0][0] * B.m[0][0] + m[0][1] * B.m[1][0] + m[0][2] * B.m[2][0] + m[0][3] * B.m[3][0]),
		/*01*/(m[0][0] * B.m[0][1] + m[0][1] * B.m[1][1] + m[0][2] * B.m[2][1] + m[0][3] * B.m[3][1]),
		/*02*/(m[0][0] * B.m[0][2] + m[0][1] * B.m[1][2] + m[0][2] * B.m[2][2] + m[0][3] * B.m[3][2]),
		/*03*/(m[0][0] * B.m[0][3] + m[0][1] * B.m[1][3] + m[0][2] * B.m[2][3] + m[0][3] * B.m[3][3]),

		/*10*/(m[1][0] * B.m[0][0] + m[1][1] * B.m[1][0] + m[1][2] * B.m[2][0] + m[1][3] * B.m[3][0]),
		/*11*/(m[1][0] * B.m[0][1] + m[1][1] * B.m[1][1] + m[1][2] * B.m[2][1] + m[1][3] * B.m[3][1]),
		/*12*/(m[1][0] * B.m[0][2] + m[1][1] * B.m[1][2] + m[1][2] * B.m[2][2] + m[1][3] * B.m[3][2]),
		/*13*/(m[1][0] * B.m[0][3] + m[1][1] * B.m[1][3] + m[1][2] * B.m[2][3] + m[1][3] * B.m[3][3]),

		/*20*/(m[2][0] * B.m[0][0] + m[2][1] * B.m[1][0] + m[2][2] * B.m[2][0] + m[2][3] * B.m[3][0]),
		/*21*/(m[2][0] * B.m[0][1] + m[2][1] * B.m[1][1] + m[2][2] * B.m[2][1] + m[2][3] * B.m[3][1]),
		/*22*/(m[2][0] * B.m[0][2] + m[2][1] * B.m[1][2] + m[2][2] * B.m[2][2] + m[2][3] * B.m[3][2]),
		/*23*/(m[2][0] * B.m[0][3] + m[2][1] * B.m[1][3] + m[2][2] * B.m[2][3] + m[2][3] * B.m[3][3]),

		/*30*/(m[3][0] * B.m[0][0] + m[3][1] * B.m[1][0] + m[3][2] * B.m[2][0] + m[3][3] * B.m[3][0]),
		/*31*/(m[3][0] * B.m[0][1] + m[3][1] * B.m[1][1] + m[3][2] * B.m[2][1] + m[3][3] * B.m[3][1]),
		/*32*/(m[3][0] * B.m[0][2] + m[3][1] * B.m[1][2] + m[3][2] * B.m[2][2] + m[3][3] * B.m[3][2]),
		/*33*/(m[3][0] * B.m[0][3] + m[3][1] * B.m[1][3] + m[3][2] * B.m[2][3] + m[3][3] * B.m[3][3])

	);
}

SML::Mat4x4 SML::Mat4x4::operator*(const float& s) const
{
	return Mat4x4(m[0][0] * s, m[0][1] * s, m[0][2] * s, m[0][3] * s,
		m[1][0] * s, m[1][1] * s, m[1][2] * s, m[1][3] * s,
		m[2][0] * s, m[2][1] * s, m[2][2] * s, m[2][3] * s,
		m[3][0] * s, m[3][1] * s, m[3][2] * s, m[3][3] * s);
}

SML::Mat4x4 SML::Mat4x4::transpose() const
{
	return Mat4x4(
		m[0][0], m[1][0], m[2][0], m[3][0],

		m[0][1], m[1][1], m[2][1], m[3][1],

		m[0][2], m[1][2], m[2][2], m[3][2],

		m[0][3], m[1][3], m[2][3], m[3][3]);
}

std::string SML::Mat4x4::toString() const
{
	std::string result;

	result += std::to_string(m[0][0]) + " " + std::to_string(m[0][1]) + " " + std::to_string(m[0][2]) + " " + std::to_string(m[0][3]) + "\n";
	result += std::to_string(m[1][0]) + " " + std::to_string(m[1][1]) + " " + std::to_string(m[1][2]) + " " + std::to_string(m[1][3]) + "\n";
	result += std::to_string(m[2][0]) + " " + std::to_string(m[2][1]) + " " + std::to_string(m[2][2]) + " " + std::to_string(m[2][3]) + "\n";
	result += std::to_string(m[3][0]) + " " + std::to_string(m[3][1]) + " " + std::to_string(m[3][2]) + " " + std::to_string(m[3][3]) + "\n";

	return result;
}

SML::Mat4x4 SML::Mat4x4::Identity()
{
	return Mat4x4(1, 0, 0, 0,
				  0, 1, 0, 0,
				  0, 0, 1, 0,
				  0, 0, 0, 1);
}
