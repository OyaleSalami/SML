#pragma once

#define SML_ROW

#include "SMLVector.h"

#include <mmintrin.h>
#include <xmmintrin.h>

//void VectorAdd(const Vec3f& a) const
//{
//	Vec3f result;
//	_declspec(align(16)) Vec3f X(x, y, z);
//	_declspec(align(16)) Vec3f Y(a.x, a.y, a.z);
//
//	_mm_store_ps(&result.x, _mm_add_ps(_mm_load_ps(&X.x), _mm_load_ps(&Y.x)));
//
//	return result;
//}

