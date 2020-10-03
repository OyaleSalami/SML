#pragma once
#include <math.h>
#include <xmmintrin.h>
#include <mmintrin.h>
#include "SMLDef.h"
#include "SMLMat1x4.h"
#include "SMLMat4x4.h"
#include "SMLVector.h"
//All non-class-belonging functions ......nb:this will definitely get messy and might
//need to be divided into multiple files.
//I cleaned it..XD

SML::Vector LERP(Vector a, Vector b, float val);


SML::Vector rotatex(Vector v, float angle);
SML::Vector rotatey(Vector v, float angle);
SML::Vector rotatez(Vector v, float angle);