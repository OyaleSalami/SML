#pragma once
#include <math.h>
#include <xmmintrin.h>
#include <mmintrin.h>
#include "SMLDef.h"
#include "SMLMat1x4.h"
#include "SMLMat4x4.h"
#include "SMLVector.h"

//TODO: All non-class-belonging functions ......nb:this will definitely get messy and might
//need to be divided into multiple files.
//I cleaned it..XD

SML::Vec3f LERP(SML::Vec3f a, SML::Vec3f b, float val);

SML::Vec3f rotatex(SML::Vec3f v, float angle);
SML::Vec3f rotatey(SML::Vec3f v, float angle);
SML::Vec3f rotatez(SML::Vec3f v, float angle);