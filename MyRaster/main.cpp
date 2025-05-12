#include <iostream>
#include "core/raster.h"

int main() {
	Raster raster(850, 480);

	while (true) {
		raster.render();	
	}
	return 0;
}