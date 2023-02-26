#pragma once
#include <math.h>
#include <mmintrin.h>
#include <xmmintrin.h>
#include "SMLMat3x3.h"

namespace SML
{
	template<class T>
	class Vec3
	{
	public:
		/// <summary>Default constructor, everything is zeroed</summary>
		Vec3() 
		{
			x = T(0);
			y = T(0);
			z = T(0);
		}
		/// <summary>Constructs a vector from another referenced one</summary>
		Vec3(const Vec3& a);
		/// <summary>Constructs a vector from individual values</summary>
		Vec3(const T& X, const T& Y, const T& Z);

		T x, y, z;
		/// <returns>The magnitude of vector</returns>
		float magnitude() const;
		/// <returns>The square of the magnitude of vector</returns>
		float magnitudeSqr() const;
		/// <summary>Returns the dot product of the vector with a</summary>
		float dot(const Vec3& a) const;

		/// <returns>A normalized form of the vector</returns>
		Vec3 normalized() const;
		/// <summary>Returns the cross product of the vector with a</summary>
		Vec3 cross(const Vec3& a) const;

		Vec3 operator+(const Vec3& a) const;
		Vec3 operator-(const Vec3& a) const;

		Vec3 operator/(const float& a) const;
		Vec3 operator*(const float& a) const;

		Vec3 operator*(const Mat3x3& a) const;

		Vec3 scale(const float& a, const float& b, const float& c) const;
	};

	template<class T>
	class Vec2
	{
	public:
		Vec2() {}
		Vec2(const Vec2<T>& a);
		Vec2(const T& X, const T& Y);

		T x, y;

		float magnitude() const;
		float magnitudeSqr() const;
		float dot(const Vec2& a) const;

		Vec2 normalized() const;

		Vec2 operator+(const Vec2& a) const;
		Vec2 operator-(const Vec2& a) const;

		Vec2 operator/(const int& a) const;
		Vec2 operator/(const float& a) const;

		Vec2 operator*(const int& a) const;
		Vec2 operator*(const float& a) const;

		Vec2 operator*(const Mat3x3& a) const;

		Vec2 Scale(const float& a, const float& b) const;
	};

	#pragma region Typdefs
	typedef Vec3<int> Vec3i;
	typedef Vec3<float> Vec3f;
	typedef Vec3<double> Vec3d;

	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;
	#pragma endregion
}
