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

		if (type == "v") {  // ��������
			Vertex vertex;
			iss >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if (type == "vt") {  // ��������
			TextureCoord texCoord;
			iss >> texCoord.u >> texCoord.v;
			textureCoords.push_back(texCoord);
		}
		else if (type == "vn") {  // ����
			Normal normal;
			iss >> normal.x >> normal.y >> normal.z;
			normals.push_back(normal);
		}
		else if (type == "f") {  // ������
			Face face;
			std::string vertexStr;

			while (iss >> vertexStr) {
				std::istringstream viss(vertexStr);
				std::string token;

				// ������������
				std::getline(viss, token, '/');
				if (!token.empty()) {
					face.vertexIndices.push_back(std::stoi(token) - 1);  // OBJ������1��ʼ
				}

				// ����������������
				std::getline(viss, token, '/');
				if (!token.empty()) {
					face.textureIndices.push_back(std::stoi(token) - 1);
				}

				// ������������
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
