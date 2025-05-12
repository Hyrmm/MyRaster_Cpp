#include <graphics.h>
#include <filesystem>
#include "raster.h"

Raster::Raster(int width, int height) : width(width), height(height) {

	// ��ʼ����
	initgraph(width, height);
	Raster::frameBuffer = (int*)GetImageBuffer();
	BeginBatchDraw();

	// ��ʼģ��
	Raster::model = new OBJModel();
	std::filesystem::path exeDir = std::filesystem::current_path();
	std::filesystem::path resourcePath = exeDir / "model/african_head.obj";
	model->loadFromFile(resourcePath.string());

}

Raster::~Raster() {
	delete Raster::frameBuffer;
	delete Raster::model;
	EndBatchDraw();
	closegraph();
}

void Raster::clear() {
	for (int offset = 0; offset < height * width; offset++) {
		Raster::frameBuffer[offset] = BGR(RGB(0x00, 0x00, 0x00));
	}
}

void Raster::render() {

	// ��������
	clear();

	// ����ģ��
	std::vector<Vertex>& vertices = Raster::model->vertices;
	float halfWidth = (width / 2.0f) - 1.0f;
	float halfHeight = (height / 2.0f) - 1.0f;

	for (const Face& face : Raster::model->faces) {

		for (const int& idx : face.vertexIndices) {
			Vertex& vertex = vertices[idx];
			Raster::setPixel((vertex.x * halfWidth) + halfWidth, (vertex.y * halfHeight) + halfHeight, BGR(RGB(0x00, 0xff, 0x00)));
		}
	}

	// ˢ�»�����
	FlushBatchDraw();
}

void Raster::setPixel(float x, float y, int color) {
	int x1 = (int)x;
	int y1 = (int)y;
	if (x1 < 0 || x1 >= width || y1 < 0 || y1 >= height) {
		std::cerr << "���棺�������곬��Ԥ�ڷ�Χ [-1,1]" << std::endl;
	}
	Raster::frameBuffer[y1 * width + x1] = color;
}