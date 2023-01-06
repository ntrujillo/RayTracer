#pragma once
#include "Shape.h"
#include <iostream>

class Sphere :
	public Shape
{
public:
	Sphere(glm::vec3 position, float radius, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n);
	~Sphere();
    float intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1);
	Record getRecord();
	glm::vec3 getNormal(glm::vec3 hitPoint);

private:

	glm::vec3 position;
	glm::vec3 normal;
	float radius;
	float radius2;
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	glm::vec3 km;
	float n;
};
