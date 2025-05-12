#include <cmath>
#include "./vector.h"

Vec3::Vec3(float x, float y, float z) :x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& other) const {
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const {
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::mul(const Vec3& other) const {
	return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 Vec3::neg()const {
	return Vec3(-x, -y, -z);
}

Vec3 Vec3::scale(float scalar) const {
	return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::cross(const Vec3& other) const {
	return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

Vec3 Vec3::normalize() const {
	float len = length();
	return Vec3(x / len, y / len, z / len);
}

float Vec3::dot(const Vec3& other) const {
	return x * other.x + y * other.y + z * other.z;
}

float Vec3::length() const {
	return std::sqrt(x * x + y * y);
}

Vec4 Vec3::toVec4() const {
	return Vec4(x, y, z, 1.0f);
}

Vec4::Vec4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}

Vec3 Vec4::toVec3() const {
	return Vec3(x, y, z);
}

std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Vec4& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
	return os;
}