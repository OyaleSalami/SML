#include "SMLVector.h"

//
//definitions of the Point class....
//
SML::Point::Point(const Point& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
}

SML::Point::Point(const float& X, const float& Y)
{
	x = X;
	y = Y;
}

SML::Point::Point(const float& X, const float& Y, const float& Z)
{
	x = X;
	y = Y;
	z = Z;
}

SML::Vector SML::Point::operator-(const Point& a) const
{
	Vector result;
	_declspec(align(16)) Point X(x, y, z);
	_declspec(align(16)) Point Y(a.x, a.y, a.z);

	_mm_store_ps(&result.x, _mm_sub_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

	return result;
}

SML::Point SML::Point::operator+(const Vector& a) const
{
	Point result;
	_declspec(align(16)) Point X(x, y, z);
	_declspec(align(16)) Point Y(a.x, a.y, a.z);

	_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

	return result;
}

float SML::Point::Length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

float SML::Point::LengthSqr() const
{
	return (x * x) + (y * y) + (z * z);
}

float SML::Point::dot(const Vector& a) const
{
	return ((x * a.x) + (y * a.y) + (z * a.z));
}

float SML::Point::dot(const Point& a) const
{
	return ((x * a.x) + (y * a.y) + (z * a.z));
}

SML::Point SML::Point::Normalized() const
{
	Point normalized;
	normalized = *this / LengthSqr();
	return normalized;
}

SML::Point SML::Point::operator/(const float& a) const
{
	return Point(x / a, y / a, z / a);
}

SML::Point SML::Point::operator*(const float& a) const
{
	return Point(x * a, y * a, z * a);
}

SML::Point SML::Point::operator*(const Mat3x3& a) const
{
	return Point(
		((x * a.m[0][0]) + (y * a.m[1][0]) + (z * a.m[2][0])),
		((x * a.m[0][1]) + (y * a.m[1][1]) + (z * a.m[2][1])),
		((x * a.m[0][2]) + (y * a.m[1][2]) + (z * a.m[2][2]))
	);
}

SML::Point SML::Point::Cross(const Point& a) const
{
	Point Cross;
	Cross.x = (y * a.z) - (z * a.y);
	Cross.y = (z * a.x) - (x * a.z);
	Cross.z = (x * a.y) - (y * a.x);
	return Cross;
}

//
//Definitions for the Vector class......
//
SML::Vector::Vector(const Vector& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
}

SML::Vector::Vector(const float& X, const float& Y)
{
	x = X;
	y = Y;
}

SML::Vector::Vector(const float& X, const float& Y, const float& Z)
{
	x = X;
	y = Y;
	z = Z;
	w = 1;
}

float SML::Vector::Length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

float SML::Vector::LengthSqr() const
{
	return (x * x) + (y * y) + (z * z);
}

float SML::Vector::dot(const Vector& a) const
{
	return ((x * a.x) + (y * a.y) + (z * a.z));
}

SML::Vector SML::Vector::Normalized() const
{
	Vector normalized;
	normalized = *this / LengthSqr();
	return normalized;
}

SML::Vector SML::Vector::operator+(const Vector& a) const
{
	Vector result;
	_declspec(align(16)) Vector X(x, y, z);
	_declspec(align(16)) Vector Y(a.x, a.y, a.z);

	_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

	return result;
}

SML::Vector SML::Vector::operator-(const Vector& a) const
{
	Vector result;
	_declspec(align(16)) Vector X(x, y, z);
	_declspec(align(16)) Vector Y(a.x, a.y, a.z);

	_mm_store_ps(&result.x, _mm_sub_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

	return result;
}

SML::Vector SML::Vector::operator/(const float& a) const
{
	return Vector(x / a, y / a, z / a);
}

SML::Vector SML::Vector::operator*(const float& a) const
{
	return Vector(x * a, y * a, z * a);
}

SML::Vector SML::Vector::operator*(const Mat3x3& a) const
{
	return Vector(
		((x * a.m[0][0]) + (y * a.m[1][0]) + (z * a.m[2][0])),
		((x * a.m[0][1]) + (y * a.m[1][1]) + (z * a.m[2][1])),
		((x * a.m[0][2]) + (y * a.m[1][2]) + (z * a.m[2][2])));
}


SML::Vector SML::Vector::Scale(float& a, float& b, float& c) const
{
	return Vector(a*x, b*y, c*z);
}

SML::Vector SML::Vector::Cross(const Vector& a) const
{
	Vector Cross;
	Cross.x = (y * a.z) - (z * a.y);
	Cross.y = (z * a.x) - (x * a.z);
	Cross.z = (x * a.y) - (y * a.x);
	return Cross;
}