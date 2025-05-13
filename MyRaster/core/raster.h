#pragma once
#include "../model/objModel.h"
#include "../math/matrix.h"

class Raster
{
private:
	int* frameBuffer;
	int width, height;

	Matrix44 modelMatrix;
	Matrix44 viewMatrix;
	Matrix44 projectionMatrix;
	Matrix44 viewportMatrix;

	OBJModel* model;

public:

	Raster(int width, int height);
	~Raster();

	void clear();
	void render();
	void resetMatrix();
	void setPixel(float x, float y, int color);
};