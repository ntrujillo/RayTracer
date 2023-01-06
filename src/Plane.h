#pragma once
#include "Shape.h"


class Plane :
	public Shape
{
public:
	Plane(glm::vec3 center, glm::vec3 normal, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n);
	~Plane();
	float intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1);
	Record getRecord();
	glm::vec3 getNormal(glm::vec3 hitPoint);

private:

	glm::vec3 center;
	glm::vec3 normal;
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	glm::vec3 km;
	float n;

};
