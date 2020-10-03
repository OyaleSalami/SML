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
	Vector a(1.345, 1.23, 3.556);
	SML::Vector b(2.145, 7.089, 0.0000156);
	SML::Vector result(a + b);
	Vector subresult(a - b);

	std::cout << result.x << " " << result.y << " " << result.z << std::endl;
	std::cout << " . " << std::endl;
	std::cout << subresult.x << " " << subresult.y << " " << subresult.z << std::endl;
	std::cout << "Hello From This Side Of The SML Library!" << std::endl;

	std::cin.get();
}