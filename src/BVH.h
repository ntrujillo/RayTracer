#pragma once
#include "Shape.h"
#include "Triangle.h"
#include <vector>


class BVH :
	public Shape
{
public:
	// BVH(std::vector<Triangle> &triangles);
	BVH(std::vector<Triangle> &triangles, std::vector<triangleInfo> &info, int startIndex, int endIndex);
	~BVH();
	float intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1);
	Record getRecord();
	glm::vec3 getNormal(glm::vec3 hitPoint);

	int getEndIndex() {return endIndex;}
	int getStartIndex() {return startIndex;}
	void setLeafTrue() {isLeaf = true;}
	bool getIsLeaf() {return isLeaf;}
	std::vector<Triangle> getTriangles() {return triangles;}
	std::vector<triangleInfo> getTriangleInfo() {return triangleInfoVector;}
	void setLeft(BVH* child) {leftChild = child;}
	void setRight(BVH* child) {rightChild = child;}
	BVH* getLeft() {return leftChild;}
	BVH* getRight() {return rightChild;}
	int getHitIndex() {return hitIndex;}

private:
	std::vector<Triangle> triangles;
	glm::vec3 center;
    glm::vec3 normal = {0.0f, 0.0f, 1.0f}; // perpendicular to camera
	int hitIndex;

	glm::vec3 max;
	glm::vec3 min;

	/* tree variables */
	std::vector<triangleInfo> triangleInfoVector;
	int startIndex;
	int endIndex;
	bool isLeaf;
	BVH* leftChild;
	BVH* rightChild;
	
};
