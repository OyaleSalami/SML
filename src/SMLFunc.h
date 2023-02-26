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

SML::Vec3 LERP(Vec3 a, Vec3 b, float val);


SML::Vec3 rotatex(Vec3 v, float angle);
SML::Vec3 rotatey(Vec3 v, float angle);
SML::Vec3 rotatez(Vec3 v, float angle);