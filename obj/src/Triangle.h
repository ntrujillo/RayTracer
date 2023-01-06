#pragma once
#include "Shape.h"


class Triangle :
	public Shape
{
public:
	Triangle(glm::vec3 v0, glm::vec3 n0, glm::vec3 v1, glm::vec3 n1, glm::vec3 v2, glm::vec3 n2, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n);
	~Triangle();
	float intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1);
	Record getRecord();
	glm::vec3 getNormal(glm::vec3 hitPoint);

	float getXavg() {
		float avg = (v[0].x + v[1].x + v[2].x) / 3;
		return avg;
	}

	float getYavg() {
		float avg = (v[0].y + v[1].y + v[2].y) / 3;
		return avg;
	}

	float getZavg() {
		float avg = (v[0].z + v[1].z + v[2].z) / 3;
		return avg;
	}

	float getXmax() {
		float xmax = fmax(v[0].x, v[1].x);
		xmax = fmax(xmax, v[2].x);
		return xmax;
	}

	float getXmin() {
		float xmin = fmin(v[0].x, v[1].x);
		xmin = fmin(xmin, v[2].x);
		return xmin;
	}

	float getYmax() {
		float ymax = fmax(v[0].y, v[1].y);
		ymax = fmax(ymax, v[2].y);
		return ymax;
	}

	float getYmin() {
		float ymin = fmin(v[0].y, v[1].y);
		ymin = fmin(ymin, v[2].y);
		return ymin;
	}

	float getZmax() {
		float zmax = fmax(v[0].z, v[1].z);
		zmax = fmax(zmax, v[2].z);
		return zmax;
	}

	float getZmin() {
		float zmin = fmin(v[0].z, v[1].z);
		zmin = fmin(zmin, v[2].z);
		return zmin;
	}

private:

	glm::vec3 v[3]; // Triangle vertices
	glm::vec3 normals[3]; // Triangle normals
	glm::vec3 normal;
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	glm::vec3 km;
	float alpha;
	float beta;
	float gamma;
	float n;

};
