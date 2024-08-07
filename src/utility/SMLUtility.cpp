#include "SMLUtility.h"

namespace SML
{
    Vector3 Lerp(Vector3 a, Vector3 b, float value)
    {
        return Vector3(a * (b - a) * value);
    }
}