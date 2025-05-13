#pragma once
#include <vector>
#include "./vector.h"

class Matrix {

public:
	float* data;
	int cols, rows;
};

class Matrix44 : public Matrix {

public:

	Matrix44(const float(&data)[16]);
	~Matrix44();

	void setCol(int col, const float(&data)[4]);
	void setRow(int row, const float(&data)[4]);

	Matrix44 transpose();
	Matrix44 operator * (const Matrix44& other);
	Matrix44& operator = (const Matrix44& other);

	Vec4 multiplyVec4(const Vec4& vec);

	static Matrix44 identity();
};

