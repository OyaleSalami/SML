#pragma once
#include <string>
#include "SMLVector.h"

namespace SML
{
	class Mat2x2
	{
	public:
		float m[2][2] = { 0,0,0,0 };
		Mat2x2() {}
		Mat2x2(const Mat2x2& v);
		Mat2x2(const float& a, const float& b, const float& c, const float& d);
		Mat2x2(const Vec3f& r1, const Vec3f& r2);

		float det()const;

		Mat2x2 operator+(const Mat2x2& v)const;
		Mat2x2 operator-(const Mat2x2& v)const;
		Mat2x2 operator*(const Mat2x2& v)const;

		Mat2x2 operator*(const float& s)const;
		Mat2x2 operator/(const float& s)const;

		Mat2x2 Transpose() const;
		static Mat2x2 Identity();

		std::string toString()const;
	};
}
