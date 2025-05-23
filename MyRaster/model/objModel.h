﻿#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../math/vector.h"

struct Face {
	std::vector<int> vertexIndices;
	std::vector<int> textureIndices;
	std::vector<int> normalIndices;
};

class OBJModel {
public:
	std::vector<Vec3> vertices;
	std::vector<Vec3> textureCoords;
	std::vector<Vec3> normals;
	std::vector<Face> faces;

	bool loadFromFile(const std::string& filename);
};

inline std::ostream& operator<<(std::ostream& os, const Face& face) {
	os << "Face:" << std::endl;
	os << "vertexIdx:";
	for (const auto& vertexIdx : face.vertexIndices) os << vertexIdx << " ";
	os << std::endl;
	os << "textureIdx:";
	for (const auto& textureIdx : face.textureIndices) os << textureIdx << " ";
	os << std::endl;
	os << "normalIdx:";
	for (const auto& normalIdx : face.normalIndices) os << normalIdx << " ";
	os << std::endl;
	return os;
}
inline std::ostream& operator<<(std::ostream& os, const std::vector<Face>& faces) {
	for (const auto& face : faces) os << face;
	return os;
}