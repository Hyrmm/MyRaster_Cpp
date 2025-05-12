#pragma once
#include <vector>
#include "./vector.h"

class Matrix {
protected:
	float* data;
public:
	int cols, rows;
};

class Matrix44 : private Matrix {



public:

	Matrix44(float(&data)[16]);
	~Matrix44();

	void setCol(int col, float(&data)[4]);
	void setRow(int row, float(&data)[4]);

	Matrix44 multiply(Matrix44& other);
	Matrix44 multiplyVec(Vec4& vec);

	static Matrix44 identity();
};