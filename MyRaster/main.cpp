#include <iostream>
#include <vector>
#include "core/raster.h"
#include "math/matrix.h"

int main() {
	Raster raster(850, 480);

	while (true) {
		raster.render();
	}
	return 0;
}