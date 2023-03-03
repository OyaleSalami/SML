#include "SMLFunc.h"

namespace SML
{
	Vec3f addVec(Vec3f& a, Vec3f& b)
	{
		Vec3f result;
		_declspec(align(16)) Vec3f x;
		_declspec(align(16)) Vec3f y;

		__m128 a128;
		__m128 b128;

		a128 = _mm_load_ps(&a.x);
		b128 = _mm_load_ps(&b.x);

		__m128 r = _mm_add_ps(a128, b128);
		_mm_store_ps(&result.x, r);

		return result;

	}


	Vec3f LERP(Vec3f a, Vec3f b, float val)
	{
		return Vec3f(a * (1 - val) + b * val);
	}

	Vec3f rotatex(Vec3f v, float angle)
	{
		SML::Mat1x4 T(v.x, v.y, v.z, 1);

		SML::Mat4x4 m(1, 0, 0, 0,
			0, cos(angle), sin(angle), 0,
			0, -sin(angle), cos(angle), 0,
			0, 0, 0, 1);

		return Vec3f((T * m).a, (T * m).b, (T * m).c);
	}

	Vec3f rotatey(Vec3f v, float angle)
	{
		SML::Mat1x4 T(v.x, v.y, v.z, 1);

		SML::Mat4x4 m(cos(angle), sin(angle), 0, 0,
			-sin(angle), cos(angle), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);

		return Vec3f((T * m).a, (T * m).b, (T * m).c);
	}

	Vec3f rotatez(Vec3f v, float angle)
	{
		SML::Mat1x4 T(v.x, v.y, v.z, 1);

		SML::Mat4x4 m(cos(angle), 0, -sin(angle), 0,
			0, 1, 0, 0,
			sin(angle), 0, cos(angle), 0,
			0, 0, 0, 1);

		return Vec3f((T * m).a, (T * m).b, (T * m).c);
	}
}