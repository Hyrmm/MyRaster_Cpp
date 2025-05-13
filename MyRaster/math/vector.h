#pragma once
#include <ostream>

class Vec3;
class Vec4;

class Vec3 {

public:
	float x, y, z;

	Vec3(float x, float y, float z);

	Vec3 operator+(const Vec3& other) const;

	Vec3 operator-(const Vec3& other) const;

	Vec3 mul(const Vec3& other) const;

	Vec3 neg() const;

	Vec3 scale(float scalar) const;

	Vec3 cross(const Vec3& other) const;

	Vec3 normalize() const;

	float dot(const Vec3& other) const;

	float length() const;

	Vec4 toVec4() const;
};

class Vec4 {

public:

	float x, y, z, w;

	Vec4(float x, float y, float z, float w);

	Vec3 toVec3() const;
};

std::ostream& operator<<(std::ostream& os, const Vec3& vec);
std::ostream& operator<<(std::ostream& os, const Vec4& vec);