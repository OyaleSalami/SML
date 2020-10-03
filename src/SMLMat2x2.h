#pragma once
#include<math.h>
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
		Mat2x2(const Vector& r1, const Vector& r2);

		float det()const;

		Mat2x2 operator+(const Mat2x2& v)const;
		Mat2x2 operator-(const Mat2x2& v)const;
		Mat2x2 operator*(const Mat2x2& v)const;

		Mat2x2 operator*(const float& s)const;
		Mat2x2 operator/(const float& s)const;

		Mat2x2 Transpose() const;
		Mat2x2 Identity() const;
	};
}
