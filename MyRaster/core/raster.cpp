#include <graphics.h>
#include <filesystem>
#include <algorithm>

#include "raster.h"
#include "../math/matrix.h"
#include "../model/objModel.h"

static float identityData[16] = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};


Raster::Raster(int width, int height) : width(width), height(height), modelMatrix(identityData), viewMatrix(identityData), projectionMatrix(identityData), viewportMatrix(identityData) {

	// 初始窗口
	initgraph(width, height);
	Raster::frameBuffer = (int*)GetImageBuffer();
	BeginBatchDraw();

	// 初始模型
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

	// 清理缓冲区
	Raster::clear();


	// 重置矩阵
	Raster::resetMatrix();

	// 绘制模型
	float halfWidth = (width / 2.0f) - 1.0f;
	float halfHeight = (height / 2.0f) - 1.0f;

	for (const Face& face : Raster::model->faces) {
		for (const int& idx : face.vertexIndices) {

			Vec3& vertex = Raster::model->vertices[idx];
			Vec4 vec = Raster::modelMatrix.multiplyVec4(vertex.toVec4());
			Raster::setPixel(vec.x, vec.y, BGR(RGB(0x00, 0xff, 0x00)));
		}
	}

	// 刷新缓冲区
	FlushBatchDraw();
}

void Raster::setPixel(float x, float y, int color) {
	int x1 = (int)x;
	int y1 = (int)y;
	if (x1 < 0 || x1 >= width || y1 < 0 || y1 >= height) {
		std::cerr << "警告：顶点坐标超出预期范围 [-1,1]" << std::endl;
	}
	Raster::frameBuffer[y1 * width + x1] = color;
}

void Raster::resetMatrix() {

	//模型矩阵
	float halfWidth = (width / 2.0f) - 1.0f;
	float halfHeight = (height / 2.0f) - 1.0f;
	float min = std::min<float>(halfWidth, halfHeight);

	Raster::modelMatrix.setRow(0, { min,0.0f,0.0f,halfWidth });
	Raster::modelMatrix.setRow(1, { 0.0f,min,0.0f,halfHeight });
	Raster::modelMatrix.setRow(2, { 0.0f,0.0f,min,0.0f });
	Raster::modelMatrix.setRow(3, { 0.0f,0.0f,0.0f,1.0f });

	// 不推荐，右值临时值，会触发拷贝构造函数(浅拷贝，需要重写对指针成员进行拷贝)，浪费内存
	//Raster::modelMatrix = Matrix44({
	//	min, 0.0f, 0.0f, halfWidth,
	//	0.0f, min, 0.0f, halfHeight,
	//	0.0f, 0.0f, min, 0.0f,
	//	0.0f, 0.0f, 0.0f, 1.0f
	//	});

}