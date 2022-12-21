#include "SMLFunc.h"

Vector3 addVector(Vector3& a, Vector3& b)
{
	Vector3 result;
	_declspec(align(16)) Vector3 x;
	_declspec(align(16)) Vector3 y;

	__m128 a128;
	__m128 b128;

	a128 = _mm_load_ps(&a.x);
	b128 = _mm_load_ps(&b.x);

	__m128 r = _mm_add_ps(a128, b128);
	_mm_store_ps(&result.x, r);

	return result;

}


Vector3 LERP(Vector3 a, Vector3 b, float val)
{
	return Vector3(a * (1 - val) + b * val);
}

Vector3 rotatex(Vector3 v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);

	SML::Mat4x4 m(1,			  0,			  0, 0,
				  0, cos(angle),  sin(angle), 0, 
				  0, -sin(angle), cos(angle), 0,
				  0,			  0,			  0, 1);

	return Vector3((T * m).a, (T * m).b, (T * m).c);
}

Vector3 rotatey(Vector3 v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);

	SML::Mat4x4 m(cos(angle), sin(angle),  0, 0,
				  -sin(angle), cos(angle), 0, 0,
							   0,		       0, 1, 0, 
							   0,              0, 0, 1);
	
	return Vector3((T * m).a, (T * m).b, (T * m).c);
}

Vector3 rotatez(Vector3 v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);

	SML::Mat4x4 m(cos(angle),  0, -sin(angle), 0,
				              0,  1,               0, 0,
				  sin(angle),  0, cos(angle),  0,
		                      0,  0,               0, 1);
	
	return Vector3((T * m).a, (T * m).b, (T * m).c);
}
