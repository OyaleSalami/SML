#include "SMLVector.h"

namespace SML
{
	#pragma region Vec2
	template<class T>
	Vec2<T>::Vec2(const Vec2<T>& a)
	{
		x = a.x;
		y = a.y;
	}
	
	template<class T>
	SML::Vec2<T>::Vec2(const T& X, const T& Y)
	{
		x = X;
		y = Y;
	}

	template<class T>
	float Vec2<T>::magnitude() const
	{
		return sqrt(double(x * x) + double(y * y));
	}

	template<class T>
	float Vec2<T>::magnitudeSqr() const
	{
		return ((x * x) + (y * y));
	}

	template<class T>
	float Vec2<T>::dot(const Vec2& a) const
	{
		return ((x * a.x) + (y * a.y));
	}

	template<class T>
	Vec2<T> Vec2<T>::normalized() const
	{
		return Vec2(*this / Length());
	}

	template<class T>
	Vec2<T> Vec2<T>::operator+(const Vec2& a) const
	{
		return Vec2(x + a.x, y + a.y);
	}

	template<class T>
	Vec2<T> Vec2<T>::operator-(const Vec2& a) const
	{
		return Vec2(x - a.x, y - a.y);
	}

	template<class T>
	Vec2<T> Vec2<T>::operator/(const float& a) const
	{
		return Vec2(x / a, y / a);
	}

	template<class T>
	Vec2<T> Vec2<T>::operator*(const float& a) const
	{
		return Vec2(x * a, y * a);
	}

	template<class T>
	Vec2<T> Vec2<T>::Scale(const float& a, const float& b) const
	{
		return Vec2(x * a, y * b);
	}
	#pragma endregion

	#pragma region Vec3

	template<class T>
	Vec3<T>::Vec3(const Vec3& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
	}

	template<class T>
	Vec3<T>::Vec3(const T& X, const T& Y, const T& Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	template<class T>
	float Vec3<T>::magnitude() const
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	template<class T>
	float Vec3<T>::magnitudeSqr() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	template<class T>
	float Vec3<T>::dot(const Vec3& a) const
	{
		return ((x * a.x) + (y * a.y) + (z * a.z));
	}

	template<class T>
	Vec3<T> Vec3<T>::normalized() const
	{
		return Vec3(*this / LengthSqr());
	}

	template<class T>
	Vec3<T> Vec3<T>::operator+(const Vec3& a) const
	{
		Vec3 result;
		_declspec(align(16)) Vec3 X(x, y, z);
		_declspec(align(16)) Vec3 Y(a.x, a.y, a.z);

		_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

		return result;
	}

	template<class T>
	Vec3<T> Vec3<T>::operator-(const Vec3& a) const
	{
		Vec3 result;
		_declspec(align(16)) Vec3 X(x, y, z);
		_declspec(align(16)) Vec3 Y(a.x, a.y, a.z);

		_mm_store_ps(&result.x, _mm_sub_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));

		return result;
	}

	template<class T>
	Vec3<T> Vec3<T>::operator/(const float& a) const
	{
		return Vec3(x / a, y / a, z / a);
	}

	template<class T>
	Vec3<T> Vec3<T>::operator*(const float& a) const
	{
		return Vec3(x * a, y * a, z * a);
	}

	template<class T>
	Vec3<T> Vec3<T>::operator*(const Mat3x3& a) const
	{
		return Vec3(
			((x * a.m[0][0]) + (y * a.m[1][0]) + (z * a.m[2][0])),
			((x * a.m[0][1]) + (y * a.m[1][1]) + (z * a.m[2][1])),
			((x * a.m[0][2]) + (y * a.m[1][2]) + (z * a.m[2][2])));
	}


	template<class T>
	Vec3<T> Vec3<T>::scale(const float& a, const float& b, const float& c) const
	{
		return Vec3(a * x, b * y, c * z);
	}

	template<class T>
	Vec3<T> Vec3<T>::cross(const Vec3& a) const
	{
		return Vec3((y * a.z) - (z * a.y),
			(z * a.x) - (x * a.z),
			(x * a.y) - (y * a.x));
	}

	#pragma endregion

}
