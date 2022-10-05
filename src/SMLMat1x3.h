#pragma once

#include "SMLVector.h"

namespace SML
{
	class Mat3x1;
	class Mat3x3;

	class Mat1x3
	{
	public:
		Mat1x3() {}
		Mat1x3(const float& A, const float& B, const float& C);
		Mat1x3(const Vector3& v);
		Mat1x3(const Point3& v);

		float a = 0, b = 0, c = 0;

		Mat1x3 operator*(const float& s)const;
		Mat1x3 operator/(const float& s)const;

		Mat1x3 operator+(const Mat1x3& m) const;
		Mat1x3 operator-(const Mat1x3& m) const;

		Mat1x3 operator*(const Mat3x3& m)const;

		Mat3x1 transpose() const;

		std::string toString()const;
	};

}