#include "SMLVector.h"

namespace SML
{
	#pragma region Vector2

	Vector2::Vector2(const Vector2& a)
	{
		x = a.x;
		y = a.y;
	}

	Vector2::Vector2(const float& X, const float& Y)
	{
		x = X;
		y = Y;
	}

	float Vector2::Length() const
	{
		return sqrt(double(x * x) + double(y * y));
	}

	float Vector2::LengthSqr() const
	{
		return ((x * x) + (y * y));
	}

	float Vector2::Dot(const Vector2& a) const
	{
		return ((x * a.x) + (y * a.y));
	}

	Vector2 Vector2::Normalized() const
	{
		return Vector2(*this / Length());
	}

	Vector2 Vector2::Cross(const Vector2& a) const
	{
		//TODO: Cross-Product of a Vector2 ???
		return Vector2();
	}

	Vector2 Vector2::operator+(const Vector2& a) const
	{
		return Vector2(x + a.x, y + a.y);
	}

	Vector2 Vector2::operator-(const Vector2& a) const
	{
		return Vector2(x - a.x, y - a.y);
	}

	Vector2 Vector2::operator/(const float& a) const
	{
		return Vector2(x / a, y / a);
	}

	Vector2 Vector2::operator*(const float& a) const
	{
		return Vector2(x * a, y * a);
	}

	Vector2 Vector2::Scale(const float& a, const float& b) const
	{
		return Vector2(x * a, y * b);
	}
	#pragma endregion

	#pragma region Point3

	Point3::Point3(const Point3& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
	}

	Point3::Point3(const float& X, const float& Y, const float& Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	Vector3 Point3::operator-(const Point3& a) const
	{
		Vector3 result;
		_declspec(align(16)) Point3 X(x, y, z);
		_declspec(align(16)) Point3 Y(a.x, a.y, a.z);

		_mm_store_ps(&result.x, _mm_sub_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

		return result;
	}

	Point3 Point3::operator+(const Vector3& a) const
	{
		Point3 result;
		_declspec(align(16)) Point3 X(x, y, z);
		_declspec(align(16)) Point3 Y(a.x, a.y, a.z);

		_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

		return result;
	}

	float Point3::Length() const
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	float Point3::LengthSqr() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	float Point3::dot(const Vector3& a) const
	{
		return ((x * a.x) + (y * a.y) + (z * a.z));
	}

	float Point3::dot(const Point3& a) const
	{
		return ((x * a.x) + (y * a.y) + (z * a.z));
	}

	Point3 Point3::Normalized() const
	{
		Point3 normalized;
		normalized = *this / LengthSqr();
		return normalized;
	}

	Point3 Point3::operator/(const float& a) const
	{
		return Point3(x / a, y / a, z / a);
	}

	Point3 Point3::operator*(const float& a) const
	{
		return Point3(x * a, y * a, z * a);
	}

	Point3 Point3::operator*(const Mat3x3& a) const
	{
		return Point3(
			((x * a.m[0][0]) + (y * a.m[1][0]) + (z * a.m[2][0])),
			((x * a.m[0][1]) + (y * a.m[1][1]) + (z * a.m[2][1])),
			((x * a.m[0][2]) + (y * a.m[1][2]) + (z * a.m[2][2]))
		);
	}

	Point3 Point3::Cross(const Point3& a) const
	{
		Point3 Cross;
		Cross.x = (y * a.z) - (z * a.y);
		Cross.y = (z * a.x) - (x * a.z);
		Cross.z = (x * a.y) - (y * a.x);
		return Cross;
	}

	#pragma endregion

	#pragma region Vector3

	Vector3::Vector3(const Vector3& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
	}

	Vector3::Vector3(const float& X, const float& Y, const float& Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	float Vector3::Length() const
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	float Vector3::LengthSqr() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	float Vector3::Dot(const Vector3& a) const
	{
		return ((x * a.x) + (y * a.y) + (z * a.z));
	}

	Vector3 Vector3::Normalized() const
	{
		return Vector3(*this / LengthSqr());
	}

	Vector3 Vector3::operator+(const Vector3& a) const
	{
		Vector3 result;
		_declspec(align(16)) Vector3 X(x, y, z);
		_declspec(align(16)) Vector3 Y(a.x, a.y, a.z);

		_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

		return result;
	}

	Vector3 Vector3::operator-(const Vector3& a) const
	{
		Vector3 result;
		_declspec(align(16)) Vector3 X(x, y, z);
		_declspec(align(16)) Vector3 Y(a.x, a.y, a.z);

		_mm_store_ps(&result.x, _mm_sub_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

		return result;
	}

	Vector3 Vector3::operator/(const float& a) const
	{
		return Vector3(x / a, y / a, z / a);
	}

	Vector3 Vector3::operator*(const float& a) const
	{
		return Vector3(x * a, y * a, z * a);
	}

	Vector3 Vector3::operator*(const Mat3x3& a) const
	{
		return Vector3(
			((x * a.m[0][0]) + (y * a.m[1][0]) + (z * a.m[2][0])),
			((x * a.m[0][1]) + (y * a.m[1][1]) + (z * a.m[2][1])),
			((x * a.m[0][2]) + (y * a.m[1][2]) + (z * a.m[2][2])));
	}

	Vector3 Vector3::Scale(const float& a, const float& b, const float& c) const
	{
		return Vector3(a * x, b * y, c * z);
	}

	Vector3 Vector3::Cross(const Vector3& a) const
	{
		return Vector3((y * a.z) - (z * a.y),
			(z * a.x) - (x * a.z),
			(x * a.y) - (y * a.x));
	}

	Vector3 Vector3::Zero() const
	{
		return Vector3(0, 0, 0);
	}

	Vector3 Vector3::One() const
	{
		return Vector3(1, 1, 1);
	}
	#pragma endregion
}