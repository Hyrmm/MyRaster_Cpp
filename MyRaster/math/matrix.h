#pragma once
#include <vector>
#include "./vector.h"

class Matrix {
private:
	std::vector<float> data;
public:
	int cols, rows;
};

class Matrix44 : public Matrix {

public:
	Matrix44(float* data[16]);

	void setCol(int col, float* data[4]);
	void setRow(int row, float* data[4]);

	void multiply(Matrix44& other);
	void multiplyVec(Vec4& vec);
};