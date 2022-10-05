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

SML::Vector3 LERP(Vector3 a, Vector3 b, float val);


SML::Vector3 rotatex(Vector3 v, float angle);
SML::Vector3 rotatey(Vector3 v, float angle);
SML::Vector3 rotatez(Vector3 v, float angle);