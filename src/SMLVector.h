#pragma once
#include <math.h>

class Mat3x3;
class Mat2x2;

namespace SML
{
	template <class T>
	class Vec2
	{
	public:
		T x, y;

		/// <summary>Default constructor, everything is zeroed</summary>
		Vec2() { x = T(0); y = T(0); }
		/// <summary>Constructs a vector from the referenced one</summary>
		Vec2(const Vec2<T>& a);
		/// <summary>Constructs a vector from individual values</summary>
		Vec2(const T& X, const T& Y);

		/// <summary>Returns the magnitude of the vector</summary>
		float magnitude() const;
		/// <summary>Returns the square of the magnitude of the vector</summary>
		float magnitudeSqr() const;
		/// <summary>Returns the dot product of the vector with a</summary>
		float dot(const Vec2& a) const;

		/// <summary>Returns the vector normalized</summary>
		Vec2 normalized() const;

		/// <summary>Add a vector</summary>
		Vec2 operator+(const Vec2& a) const;
		/// <summary>Subtract a vector</summary>
		Vec2 operator-(const Vec2& a) const;

		/// <summary>Divide the vector by a(int)</summary>
		Vec2 operator/(const int& a) const;
		/// <summary>Divide the vector by a(float)</summary>
		Vec2 operator/(const float& a) const;
		/// <summary>Divide the vector by a(double)</summary>
		Vec2 operator/(const double& a) const;

		/// <summary>Multiply the Vector by a(int)</summary>
		Vec2 operator*(const int& a) const;
		/// <summary>Multiply the Vector by a(float)</summary>
		Vec2 operator*(const float& a) const;
		/// <summary>Multiply the Vector by a(double)</summary>
		Vec2 operator*(const double& a) const;

		//TODO: /// <summary>Multiply the Vector by a 3x3 Matrix</summary>
		Vec2 operator*(const Mat2x2& a) const;

		/// <summary>Returns a vector that has been scaled by the params(int)</summary>
		Vec2 scale(const int& a, const int& b) const;
		/// <summary>Returns a vector that has been scaled by the params(float)</summary>
		Vec2 scale(const float& a, const float& b) const;
		/// <summary>Returns a vector that has been scaled by the params(double)</summary>
		Vec2 scale(const double& a, const double& b) const;
	};

	template <class T>
	class Vec3
	{
	public:
		T x, y, z;
		
		/// <summary>Default constructor, everything is zeroed</summary>
		Vec3(){ x = T(0); y = T(0); z = T(0);}
		/// <summary>Constructs a vector from the referenced one</summary>
		Vec3(const Vec3& a);
		/// <summary>Constructs a vector from individual values</summary>
		Vec3(const T& X, const T& Y, const T& Z);

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

		/// <summary>Adds a vector</summary>
		Vec3 operator+(const Vec3& a) const;
		/// <summary>Subtract a vector</summary>
		Vec3 operator-(const Vec3& a) const;

		/// <summary>Divide the vector by a(int)</summary>
		Vec3 operator/(const int& a) const;
		/// <summary>Divide the vector by a(float)</summary>
		Vec3 operator/(const float& a) const;
		/// <summary>Divide the vector by a(double)</summary>
		Vec3 operator/(const double& a) const;

		/// <summary>Multiply the Vector by a(int)</summary>
		Vec3 operator*(const int& a) const;
		/// <summary>Multiply the Vector by a(float)</summary>
		Vec3 operator*(const float& a) const;
		/// <summary>Multiply the Vector by a(double)</summary>
		Vec3 operator*(const double& a) const;

		/// <summary>Multiple the vector by a 3x3 Matrix</summary>
		Vec3 operator*(const Mat3x3& a) const;

		/// <summary>Returns a vector that has been scaled by the params(int)</summary>
		Vec3 scale(const int& a, const int& b, const int& c) const;
		/// <summary>Returns a vector that has been scaled by the params(float)</summary>
		Vec3 scale(const float& a, const float& b, const float& c) const;
		/// <summary>Returns a vector that has been scaled by the params(double)</summary>
		Vec3 scale(const double& a, const double& b, const double& c) const;
	};

	#pragma region Typedefs
	/// <summary>Vector 3(int)</summary>
	typedef Vec3<int> Vec3i;
	/// <summary>Vector 3(float)</summary>
	typedef Vec3<float> Vec3f;
	/// <summary>Vector 3(double)</summary>
	typedef Vec3<double> Vec3d;

	/// <summary>Vector 2(int)</summary>
	typedef Vec2<int> Vec2i;
	/// <summary>Vector 2(float)</summary>
	typedef Vec2<float> Vec2f;
	/// <summary>Vector 2(double)</summary>
	typedef Vec2<double> Vec2d;
	#pragma endregion
}
