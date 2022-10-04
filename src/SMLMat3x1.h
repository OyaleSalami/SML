#pragma once
#include "SMLVector.h"

namespace SML
{
	class Mat1x3;

	class Mat3x1
	{
	public:
		Mat3x1() {}
		Mat3x1(float A, float B, float C);
		Mat3x1(Vector v);

		float a = 0, b = 0, c = 0;

		Mat3x1 operator*(const float& s)const;
		Mat3x1 operator/(const float& s)const;

		Mat3x1 operator+(const Mat3x1 m) const;
		Mat3x1 operator-(const Mat3x1 m) const;

		Mat1x3 transpose();

		std::string toString()const;
	};
}