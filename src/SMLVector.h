#pragma once
#include <math.h>
#include <mmintrin.h>
#include <xmmintrin.h>
#include "SMLMat3x3.h"

namespace SML
{
	class Vector
	{
	public:
		Vector() {}
		Vector(const Vector& a);
		Vector(const float& X, const float& Y);
		Vector(const float& X, const float& Y, const float& Z);

		float x = 0, y = 0, z = 0, w = 0;

		float Length() const;
		float LengthSqr() const;
		float dot(const Vector& a) const;

		Vector Normalized() const;
		Vector Cross(const Vector& a) const;

		Vector operator+(const Vector& a) const;
		Vector operator-(const Vector& a) const;

		Vector operator/(const float& a) const;
		Vector operator*(const float& a) const;

		Vector operator*(const Mat3x3& a) const;

		Vector Scale(float& a, float& b, float& c) const;

	};

	class Point
	{
	public:
		Point() {}
		Point(const Point& a);
		Point(const float& X, const float& Y);
		Point(const float& X, const float& Y, const float& Z);

		float x = 0, y = 0, z = 0, w = 1;

		Vector operator-(const Point& a) const;
		Point operator+(const Vector& a) const;

		float Length() const;
		float LengthSqr() const;
		float dot(const Point& a) const;
		float dot(const Vector& a) const;

		Point Normalized() const;
		Point Cross(const Point& a) const;

		Point operator/(const float& a) const;
		Point operator*(const float& a) const;

		Point operator*(const Mat3x3& a) const;
	};
}
