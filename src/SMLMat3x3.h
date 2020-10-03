#pragma once
#include <math.h>

namespace SML
{
	class Vector;
	class Mat3x3
	{
	public:
		float m[3][3] = { 0,0,0, 0,0,0, 0,0,0 };

		Mat3x3() {}
		Mat3x3(const Mat3x3& v);
		Mat3x3(float A11, float A12, float A13, float A21, float A22, float A23, float A31, float A32, float A33);
		Mat3x3(Vector v1, Vector v2, Vector v3);

		Mat3x3 operator*(const float& s)const;
		Mat3x3 operator/(const float& s)const;

		Mat3x3 operator+(const Mat3x3& v)const;
		Mat3x3 operator-(const Mat3x3& v)const;
		//Mat3x3 operator*(const Mat3x3& M)const;

		Mat3x3 Transpose() const;
		Mat3x3 Identity() const;

		float det()const;
	};
}