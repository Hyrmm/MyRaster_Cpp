#include "objModel.h"

bool OBJModel::loadFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string type;
		iss >> type;

		if (type == "v") {  // 顶点数据
			Vertex vertex;
			iss >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if (type == "vt") {  // 纹理坐标
			TextureCoord texCoord;
			iss >> texCoord.u >> texCoord.v;
			textureCoords.push_back(texCoord);
		}
		else if (type == "vn") {  // 法线
			Normal normal;
			iss >> normal.x >> normal.y >> normal.z;
			normals.push_back(normal);
		}
		else if (type == "f") {  // 面数据
			Face face;
			std::string vertexStr;

			while (iss >> vertexStr) {
				std::istringstream viss(vertexStr);
				std::string token;

				// 解析顶点索引
				std::getline(viss, token, '/');
				if (!token.empty()) {
					face.vertexIndices.push_back(std::stoi(token) - 1);  // OBJ索引从1开始
				}

				// 解析纹理坐标索引
				std::getline(viss, token, '/');
				if (!token.empty()) {
					face.textureIndices.push_back(std::stoi(token) - 1);
				}

				// 解析法线索引
				std::getline(viss, token, '/');
				if (!token.empty()) {
					face.normalIndices.push_back(std::stoi(token) - 1);
				}
			}

			faces.push_back(face);
		}
	}

	file.close();
	return true;
}
