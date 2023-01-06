#pragma once
#include "Shape.h"
#include "Triangle.h"
#include "BVH.h"
#include <vector>
#include <algorithm>

class BVHtree :
	public Shape
{
public:
	BVHtree(std::vector<Triangle> &t, int n);
	~BVHtree();
	float intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1);
	Record getRecord();
	glm::vec3 getNormal(glm::vec3 hitPoint);

	void BuildTree(char axis, BVH *node, std::vector<Triangle> &triangles, std::vector<triangleInfo> &triangleInfoVector);
	float findIntersectionLeaf(BVH* node, glm::vec3 &origin, glm::vec3 &direction, float t0, float t1);

private:
    int maxShapesInNode;
    std::vector<Triangle> triangles;
	std::vector<triangleInfo> triangleInfoVector;
	BVH *root;
	BVH *hitNode;
};