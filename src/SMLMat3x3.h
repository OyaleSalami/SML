#pragma once
#include <string>
#include "SMLVector.h"

namespace SML
{
	class Mat3x3
	{
	public:
		float m[3][3] = { 0,0,0, 0,0,0, 0,0,0 };

		Mat3x3() {}
		Mat3x3(const Mat3x3& v);
		Mat3x3(float A11, float A12, float A13, float A21, float A22, float A23, float A31, float A32, float A33);
		Mat3x3(Vec3f v1, Vec3f v2, Vec3f v3);

		Mat3x3 operator*(const float& s)const;
		Mat3x3 operator/(const float& s)const;

		Mat3x3 operator+(const Mat3x3& v)const;
		Mat3x3 operator-(const Mat3x3& v)const;
		//Mat3x3 operator*(const Mat3x3& M)const;

		Mat3x3 Transpose() const;
		static Mat3x3 Identity();

		float det()const;
		std::string toString()const;
	};
}