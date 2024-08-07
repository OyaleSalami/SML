#pragma once
#include "../SMLVector.h"

namespace SML
{
	/// <summary>Linearly interpolates between two vectors</summary>
	/// <returns>Interpolated value equals to (a + (b - a) * value)</returns>
	Vector3 Lerp(Vector3 a, Vector3 b, float value);

	/// <summary>Linearly interpolates between two values</summary>
	/// <returns>Interpolated value equals to (a + (b - a) * value)</returns>
	float Lerp(float a, float b, float value);
}