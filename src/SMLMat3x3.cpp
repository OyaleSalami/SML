#include "SMLMat3x3.h"
#include "SMLVector.h"

SML::Mat3x3::Mat3x3(const Mat3x3& v)
{
	m[0][0] = v.m[0][0];  m[0][1] = v.m[0][1];  m[0][2] = v.m[0][2];
	m[1][0] = v.m[1][0];  m[1][1] = v.m[1][1];  m[1][2] = v.m[1][2];
	m[2][0] = v.m[2][0];  m[2][1] = v.m[2][1];  m[2][2] = v.m[2][2];
}

SML::Mat3x3::Mat3x3(float A11, float A12, float A13, float A21, float A22, float A23, float A31, float A32, float A33)
{
	m[0][0] = A11; m[0][1] = A12; m[0][2] = A13;
	m[1][0] = A21; m[1][1] = A22; m[1][2] = A23;
	m[2][0] = A31; m[2][1] = A32; m[2][2] = A33;
}

SML::Mat3x3::Mat3x3(Vector v1, Vector v2, Vector v3)
{
	m[0][0] = v1.x; m[0][1] = v1.y; m[0][2] = v1.z;
	m[1][0] = v2.x; m[1][1] = v2.y; m[1][2] = v2.z;
	m[2][0] = v3.x; m[2][1] = v3.y; m[2][2] = v3.z;
}

SML::Mat3x3 SML::Mat3x3::operator*(const float& s)const
{
	return Mat3x3(m[0][0] * s, m[0][1] * s, m[0][2] * s, m[1][0] * s, m[1][1] * s, m[1][2] * s, m[2][0] * s, m[2][1] * s, m[2][2] * s);
}

SML::Mat3x3 SML::Mat3x3::operator/(const float& s)const
{
	return Mat3x3(m[0][0] / s, m[0][1] / s, m[0][2] / s, m[1][0] / s, m[1][1] / s, m[1][2] / s, m[2][0] / s, m[2][1] / s, m[2][2] / s);
}

SML::Mat3x3 SML::Mat3x3::operator+(const Mat3x3& v)const
{
	return Mat3x3(m[0][0] + v.m[0][0], m[0][1] + v.m[0][1], m[0][2] + v.m[0][2], m[1][0] + v.m[1][0], m[1][1] + v.m[1][1], m[1][2] + v.m[1][2], m[2][0] + v.m[2][0], m[2][1] + v.m[2][1], m[2][2] + v.m[2][2]);
}

SML::Mat3x3 SML::Mat3x3::operator-(const Mat3x3& v)const
{
	return Mat3x3(m[0][0] - v.m[0][0], m[0][1] - v.m[0][1], m[0][2] - v.m[0][2], m[1][0] - v.m[1][0], m[1][1] - v.m[1][1], m[1][2] - v.m[1][2], m[2][0] - v.m[2][0], m[2][1] - v.m[2][1], m[2][2] - v.m[2][2]);
}

SML::Mat3x3 SML::Mat3x3::Transpose() const
{
	return Mat3x3(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}

SML::Mat3x3 SML::Mat3x3::Identity() const
{
	return Mat3x3(1,0,0, 0,1,0, 0,0,1);
}

float SML::Mat3x3::det()const
{
	return float(m[0][0] * m[1][1] * m[2][2] - m[0][0] * m[2][1] * m[1][2] - m[0][1] * m[1][0] * m[2][2] - m[1][2] * m[2][0] * -m[0][1] + m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[2][0] * m[1][1]);
}