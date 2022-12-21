#pragma once
#include <math.h>
#include <string>
#include <mmintrin.h>
#include <xmmintrin.h>
#include "SMLMat3x3.h"

namespace SML
{
	class Vector3
	{
	public:
		Vector3() {}
		Vector3(const Vector3& a);
		Vector3(const float& X, const float& Y, const float& Z);

		float x = 0, y = 0, z = 0;

		float Length() const;
		float LengthSqr() const;
		float dot(const Vector3& a) const;

		Vector3 Normalized() const;
		Vector3 Cross(const Vector3& a) const;

		Vector3 operator+(const Vector3& a) const;
		Vector3 operator-(const Vector3& a) const;

		Vector3 operator/(const float& a) const;
		Vector3 operator*(const float& a) const;

		Vector3 operator*(const Mat3x3& a) const;

		Vector3 Scale(const float& a, const float& b, const float& c) const;
	};

	class Vector2
	{
	public:
		Vector2() {}
		Vector2(const Vector2& a);
		Vector2(const float& X, const float& Y);

		float x = 0, y = 0;

		float Length() const;
		float LengthSqr() const;
		float dot(const Vector2& a) const;

		Vector2 Normalized() const;
		Vector2 Cross(const Vector2& a) const;

		Vector2 operator+(const Vector2& a) const;
		Vector2 operator-(const Vector2& a) const;

		Vector2 operator/(const float& a) const;
		Vector2 operator*(const float& a) const;

		Vector2 operator*(const Mat3x3& a) const;

		Vector2 Scale(const float& a, const float& b) const;
	};

	class Point3
	{
	public:
		Point3() {}
		Point3(const Point3& a);
		Point3(const float& X, const float& Y, const float& Z);

		float x = 0, y = 0, z = 0;

		Vector3 operator-(const Point3& a) const;
		Point3 operator+(const Vector3& a) const;

		float Length() const;
		float LengthSqr() const;
		float dot(const Point3& a) const;
		float dot(const Vector3& a) const;

		Point3 Normalized() const;
		Point3 Cross(const Point3& a) const;

		Point3 operator/(const float& a) const;
		Point3 operator*(const float& a) const;

		Point3 operator*(const Mat3x3& a) const;
	};
}
