#pragma once
#include <vector>
#include "Scene.h"

/* glm */
#include <glm/glm.hpp>

/* to-do */
/*

* STEP 1 *
* fill in camera class to have necessary member variables
	* set up camera class with all camera parameters mentioned in report
	* currently it is only set up with width and height information

* STEP 2 *
* fill in the TakePicture function. In this function you should loop over all the pixels.
* for each pixel , you first create a ray pointing from the camera to the pixel. You then call a function
* to get the color of the ray. Most of the computations are done inside this recursive function. The returned color
* of the ray is then used to set the color of the renderedImage array at that pixel.

*/


/* suggestions */
/*
	* implement incremently
	* 1. Render a sphere without any shadows or recursive calls.
	* 2. Add a plane to the scene
	* 3. Shoot shadow rays to be able to render shadows.
	* 4. Implement the recursive reflection call and add a reflective sphere to the scene to test it

*/

class Camera
{
public:
	Camera();
	~Camera();

	Camera(int widthRes, int heightRes, glm::vec3 eye, glm::vec3 lookAt, glm::vec3 up, float fovY, float focalDistances);

	glm::vec3 computeRayColor(Scene *scene, glm::vec3 &rayOrigin, glm::vec3 &rayDirection, float t0, float t1, int &recursionLevel);
	void TakePicture(Scene *scene);
	float* GetRenderedImage() { return renderedImage; };

private:

	int widthRes;
	int heightRes;
	glm::vec3 eye;
	glm::vec3 lookAt;
	glm::vec3 up;
	float fovY;
	float focalDistance;


	float *renderedImage;


};
