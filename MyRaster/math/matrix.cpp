#include "matrix.h"

Matrix44::Matrix44(float(&data)[16]) {

	Matrix44::cols = 4;
	Matrix44::rows = 4;
	Matrix44::data = new float[16];

	std::copy(data, data + 16, Matrix44::data);
};

Matrix44::~Matrix44() {
	delete[] data;
};

void Matrix44::setCol(int col, float(&data)[4]) {
	this->data[(col + 0) * 4] = data[0];
	this->data[(col + 1) * 4] = data[1];
	this->data[(col + 2) * 4] = data[2];
	this->data[(col + 3) * 4] = data[3];
};

void Matrix44::setRow(int row, float(&data)[4]) {
	this->data[row * 4 + 0] = data[0];
	this->data[row * 4 + 1] = data[1];
	this->data[row * 4 + 2] = data[2];
	this->data[row * 4 + 3] = data[3];
};

Matrix44 identity() {

	float data[16] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return Matrix44(data);
};

Matrix44 Matrix44::multiply(Matrix44& other) {

	Matrix44 result = Matrix44::identity();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				result.data[i * 4 + j] += data[i * 4 + k] * other.data[k * 4 + j];
			}
		}
	}

	return result;

};

