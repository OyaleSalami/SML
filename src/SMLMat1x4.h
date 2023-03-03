#pragma once
#include <string>
#include "SMLVector.h"


namespace SML
{
	class Mat4x1;
	class Mat4x4;

	class Mat1x4
	{
	public:
		Mat1x4() {}
		Mat1x4(const float& A, const float& B, const float& C, const float& D);
		Mat1x4(const Vec3f& v);

		float a = 0, b = 0, c = 0, d = 0;

		Mat1x4 operator*(const float& s)const;
		Mat1x4 operator/(const float& s)const;

		Mat1x4 operator+(const Mat1x4& m) const;
		Mat1x4 operator-(const Mat1x4& m) const;

		Mat1x4 operator*(const Mat4x4& m) const;

		Mat4x1 transpose() const;

		std::string toString()const;
	};
}