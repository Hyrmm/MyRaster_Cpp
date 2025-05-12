#include <iostream>
#include <vector>
#include "core/raster.h"
#include "math/matrix.h"

int main() {
	Raster raster(850, 480);


	Matrix44 mat1 = Matrix44::identity();
	Matrix44 mat2 = Matrix44::identity();


	Matrix44 result = mat1.multiply(mat2);


	while (true) {
		raster.render();
	}
	return 0;
}