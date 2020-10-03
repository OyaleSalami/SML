#include "SMLFunc.h"

Vector addVector(Vector& a, Vector& b)
{
	Vector result;
	_declspec(align(16)) Vector x;
	_declspec(align(16)) Vector y;

	__m128 a128;
	__m128 b128;

	a128 = _mm_load_ps(&a.x);
	b128 = _mm_load_ps(&b.x);

	__m128 r = _mm_add_ps(a128, b128);
	_mm_store_ps(&result.x, r);

	return result;

}


Vector LERP(Vector a, Vector b, float val)
{
	return Vector(a * (1 - val) + b * val);
}

Vector rotatex(Vector v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);
	SML::Mat4x4 m(1,0,0,0,0, cos(angle), sin(angle), 0,0,-sin(angle),cos(angle),0,0,0,0,1);
	return Vector((T * m).a, (T * m).b, (T * m).c);
}

Vector rotatey(Vector v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);
	SML::Mat4x4 m(cos(angle), sin(angle),0,0,-sin(angle), cos(angle),0,0,0,0,1,0,0,0,0,1);
	return Vector((T * m).a, (T * m).b, (T * m).c);

}

Vector rotatez(Vector v, float angle)
{
	SML::Mat1x4 T(v.x, v.y, v.z, 1);
	SML::Mat4x4 m(cos(angle), 0, -sin(angle),0,0,1,0,0,sin(angle),0,cos(angle),0,0,0,0,1);
	return Vector((T * m).a, (T * m).b, (T * m).c);

}


void MatrixToQuat(const float R[3][3], float q[/*4*/])
{
	float trace = R[0][0] + R[1][1] + R[2][2];

	if (trace > 0.0f)
	{
		float s = sqrt((double)trace + 1.0f);
		q[3] = s * 0.5f;
		float t = 0.5f / s;
		q[0] = (R[2][1] - R[1][2]) * t;
		q[1] = (R[0][2] - R[2][0]) * t;
		q[2] = (R[1][0] - R[0][1]) * t;
	}
	else
	{
		// diagonal is negative
		int i = 0;
		if (R[1][1] > R[0][0]) i = 1;
		if (R[2][2] > R[i][i]) i = 2;
		static const int NEXT[3] = { 1, 2, 0 };
		auto j = NEXT[i];
		auto k = NEXT[j];
		float s = sqrt(((double)R[i][i] - ((double)R[j][j] + (double)R[k][k])) + 1.0f);
		q[i] = s * 0.5f;
		float t;
		if (s != 0.0) t = 0.5f / s;
		else t = s;

		q[3] = (R[k][j] - R[j][k]) * t;
		q[j] = (R[j][i] + R[i][j]) * t;
		q[k] = (R[k][i] + R[i][k]) * t;
	}
}