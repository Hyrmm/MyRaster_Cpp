#include "matrix.h"
#include <iostream>

Matrix44::Matrix44(const float(&data)[16]) {

	Matrix44::cols = 4;
	Matrix44::rows = 4;
	Matrix44::data = new float[16];

	std::copy(data, data + 16, Matrix44::data);

	std::cout << "Copied data: ";
	for (int i = 0; i < 16; ++i) {
		std::cout << Matrix44::data[i] << " ";
	}
	std::cout << std::endl;
};

Matrix44::~Matrix44() {
	delete[] data;
};

void Matrix44::setCol(int col, const float(&data)[4]) {
	this->data[(col + 0) * 4] = data[0];
	this->data[(col + 1) * 4] = data[1];
	this->data[(col + 2) * 4] = data[2];
	this->data[(col + 3) * 4] = data[3];
};

void Matrix44::setRow(int row, const float(&data)[4]) {
	this->data[row * 4 + 0] = data[0];
	this->data[row * 4 + 1] = data[1];
	this->data[row * 4 + 2] = data[2];
	this->data[row * 4 + 3] = data[3];
};

Matrix44 Matrix44::identity() {

	return Matrix44({
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		});
};

Matrix44 Matrix44::transpose() {

	Matrix44 result = Matrix44::identity();

	result.setCol(0, { data[0], data[1], data[2], data[3] });
	result.setCol(1, { data[4], data[5], data[6], data[7] });
	result.setCol(2, { data[8], data[9], data[10], data[11] });
	result.setCol(3, { data[12], data[13], data[14], data[15] });

	return result;
};

Matrix44 Matrix44::operator *(const Matrix44& other) {

	Matrix44 result = Matrix44::identity();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				result.data[i * 4 + j] += data[i * 4 + k] * other.data[k * 4 + j];
			}
		}
	}

	return result;
}

Matrix44& Matrix44::operator = (const Matrix44& other) {
	std::copy(other.data, other.data + 16, Matrix44::data);
	return *this;
};

Vec4 Matrix44::multiplyVec4(const Vec4& other) {
	float x = this->data[0] * other.x + this->data[1] * other.y + this->data[2] * other.z + this->data[3] * other.w;
	float y = this->data[4] * other.x + this->data[5] * other.y + this->data[6] * other.z + this->data[7] * other.w;
	float z = this->data[8] * other.x + this->data[9] * other.y + this->data[10] * other.z + this->data[11] * other.w;
	float w = this->data[12] * other.x + this->data[13] * other.y + this->data[14] * other.z + this->data[15] * other.w;
	return Vec4(x, y, z, w);
}



