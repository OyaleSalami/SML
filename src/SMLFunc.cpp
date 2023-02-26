#include "SMLFunc.h"

Vec3 addVec(Vec3& a, Vec3& b)
{
	Vec3 result;
	_declspec(align(16)) Vec3 x;
	_declspec(align(16)) Vec3 y;

	__m128 a128;
	__m128 b128;

	a128 = _mm_load_ps(&a.x);
	b128 = _mm_load_ps(&b.x);

	__m128 r = _mm_add_ps(a128, b128);
	_mm_store_ps(&result.x, r);

	return result;

}


Vec3 LERP(Vec3 a, Vec3 b, float val)
{
	return Vec3(a * (1 - val) + b * val);
}

Vec3 rotatex(Vec3 v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);

	SML::Mat4x4 m(1,			  0,			  0, 0,
				  0, cos(angle),  sin(angle), 0, 
				  0, -sin(angle), cos(angle), 0,
				  0,			  0,			  0, 1);

	return Vec3((T * m).a, (T * m).b, (T * m).c);
}

Vec3 rotatey(Vec3 v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);

	SML::Mat4x4 m(cos(angle), sin(angle),  0, 0,
				  -sin(angle), cos(angle), 0, 0,
							   0,		       0, 1, 0, 
							   0,              0, 0, 1);
	
	return Vec3((T * m).a, (T * m).b, (T * m).c);
}

Vec3 rotatez(Vec3 v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);

	SML::Mat4x4 m(cos(angle),  0, -sin(angle), 0,
				              0,  1,               0, 0,
				  sin(angle),  0, cos(angle),  0,
		                      0,  0,               0, 1);
	
	return Vec3((T * m).a, (T * m).b, (T * m).c);
}
