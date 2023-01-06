#pragma once

/* glm */
#include <glm/glm.hpp>

class Light
{
public:
	Light(glm::vec3 position, glm::vec3 color);
	~Light();

	glm::vec3 getPosition() {return position;}
	glm::vec3 getColor() {return color;}

private:

	glm::vec3 position;
	glm::vec3 color;

};
