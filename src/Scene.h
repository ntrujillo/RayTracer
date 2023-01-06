#pragma once
#include <vector>
#include "Shape.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include "BVH.h"
#include "BVHtree.h"
#include "Light.h"
#include <iostream>

/* glm */
#include <glm/glm.hpp>

/* standard exceptions for debugging */
#include <stdexcept>

/* to-do */
/*

* STEP 2 *
* set up scene with the information provided in report by filling in the Shape and Light vectors
* in the scene class. THis can be done in the constructor of the scene class.
	* first add appropriate member variables to the shape, sphere, plane, and light classes
		* i.e. light class should at least have the position and color as member variables
		* note: shape is the base class for the sphere and the plane and has access to all their member variables

	* once all the classes are properly set up you can create instances of Sphere, Plane, and Light classes
	* based on the information provided above and then push them into the appropriate vector

*/

class Scene
{
public:
	Scene();
	Scene(std::vector<glm::vec3> &verticies, std::vector<glm::vec3> &norBuff);
	~Scene();

	bool Hit(glm::vec3 &rayOrigin, glm::vec3 &rayDirection, float &t, float t0, float t1, Record &rec);
	std::vector<Light*> getLights() {return lights;}
	std::vector<Triangle> CreateTriangleVector(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &norBuff, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n);

private:
	std::vector<Shape*> shapes;
	std::vector<Light*> lights;

};
