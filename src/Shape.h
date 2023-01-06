#pragma once

/* glm */
#include <glm/glm.hpp>
#include <iostream>

struct Record {
    glm::vec3 ka;
    glm::vec3 kd; 
    glm::vec3 ks; 
    glm::vec3 km; 
    glm::vec3 center;
    glm::vec3 normal;
    float n; 
};

struct triangleInfo {
    glm::vec3 avg;
    int triangleIndex;
};

class Shape
{
public:
	Shape(void);
	virtual ~Shape(void);

	virtual float intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1) {

    }

	virtual Record getRecord() {

	}

    virtual glm::vec3 getNormal(glm::vec3 hitPoint) {

    }

private:
	
};
