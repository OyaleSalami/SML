#pragma once
#include <string>
#include <math.h>
#include "SMLVector.h"
#include "SMLMat3x3.h"

namespace SML
{
	class Mat4x4
	{
	public:
		float m[4][4] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };

		Mat4x4() {}
		Mat4x4(const Mat4x4& m);
		Mat4x4(const float& m1, const float& m2, const float& m3, const float& m4, const float& m5, const float& m6, const float& m7, const float& m8, const float& m9, const float& m10, const float& m11, const float& m12, const float& m13, const float& m14, const float& m15, const float& m16);
		Mat4x4(const Vector3& r1, const Vector3& r2, const Vector3& r3, const Vector3& t);
		Mat4x4(const Mat3x3& m33, const Vector3& t);

		Mat4x4 operator*(const float& s)const;
		Mat4x4 operator/(const float& s)const;

		Mat4x4 operator+(const Mat4x4& v)const;
		Mat4x4 operator-(const Mat4x4& v)const;
		Mat4x4 operator*(const Mat4x4& M)const;

		Mat4x4 transpose(/*to become column oriented*/) const;

		std::string toString()const;
		static Mat4x4 Identity();
	};

}