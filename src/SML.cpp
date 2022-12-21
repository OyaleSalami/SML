#include <iostream>
#include <math.h>
#include "SMLMath.h"
#include "SMLMat1x3.h"
#include "SMLMat3x1.h"
#include "SMLMat4x4.h"
#include "SMLDef.h"
#include "SMLFunc.h"

int main()
{
	SML::Mat4x4 mat1(1,2,3,4,5,6,7,8,8,9,0,8,7,6,5,4);
	SML::Mat4x4 mat2(1,2,3,4,5,6,7,8,8,9,0,8,7,6,5,4);

	std::cout << (mat1+ mat2).toString()  << std::endl;
	std::cout << "Hello From This Side Of The SML Library!" << std::endl;

	std::cin.get();
}