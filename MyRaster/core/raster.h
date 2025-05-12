#pragma once
#include "../model/objModel.h"

class Raster
{
private:
	int* frameBuffer;
	int width, height;

	OBJModel* model;

public:

	Raster(int width, int height);
	~Raster();

	void clear();
	void render();
	void resetMatrix();
	void setPixel(float x, float y, int color);
};