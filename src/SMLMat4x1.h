#pragma once
#include "SMLVector.h"

namespace SML
{

	class Mat1x4;
	class Mat4x1
	{
	public:
		Mat4x1() {}
		Mat4x1(const float& A, const float& B, const float& C, const float& D);
		Mat4x1(const Vector& v);
		Mat4x1(const Point& v);

		float a = 0, b = 0, c = 0, d = 0;

		Mat4x1 operator*(const float& s)const;
		Mat4x1 operator/(const float& s)const;

		Mat4x1 operator+(const Mat4x1& m) const;
		Mat4x1 operator-(const Mat4x1& m) const;

		Mat1x4 transpose() const;

		std::string toString()const;
	};
}