#include "Camera.h"



Camera::Camera()
{
}

Camera::~Camera()
{
}

Camera::Camera(int widthRes, int heightRes, glm::vec3 eye, glm::vec3 lookAt, glm::vec3 up, float fovY, float focalDistance)
{
	this->widthRes = widthRes;
	this->heightRes = heightRes;
	this->eye = eye;
	this->lookAt = lookAt;
	this->up = up;
	this->fovY = fovY;
	this->focalDistance = focalDistance;
	renderedImage = new float[widthRes * heightRes * 3];
}

glm::vec3 Camera::computeRayColor(Scene *scene, glm::vec3 &rayOrigin, glm::vec3 &rayDirection, float t0, float t1, int &recursionLevel) {
	glm::vec3 color(0.0f, 0.0f, 0.0f);
	Record rec;
	float t;

	if (scene->Hit(rayOrigin, rayDirection, t, t0, t1, rec)) {
		// ambient color
		color = rec.ka;
		// std::cout << "Hit!" << std::endl;

		glm::vec3 hitPoint = rayOrigin + (rayDirection * t);

		for (int i = 0; i < 2; i ++) { // loop through the two lights
			float t_new;
			Record rec_new;
			glm::vec3 sray_direction = scene->getLights().at(i)->getPosition() - hitPoint;
			if (!scene->Hit(hitPoint, sray_direction, t_new, 0.001f, (1.0f + 0.001f), rec_new)) {
				// std::cout << "(" << rec.normal[0] << ", " << rec.normal[1] << ", " << rec.normal[2] << ")" << std::endl;
				glm::vec3 L = normalize(scene->getLights().at(i)->getPosition() - hitPoint);
				glm::vec3 R = normalize(2.0f * dot(L, rec.normal) * rec.normal - L);
				glm::vec3 E = normalize(rayOrigin - hitPoint);

				glm::vec3 diffuse = scene->getLights().at(i)->getColor() * rec.kd * fmax(0.0f, dot(L, rec.normal));
				glm::vec3 specular = scene->getLights().at(i)->getColor() * rec.ks * pow(fmax(0.0f, dot(R, E)), rec.n);

				color += specular + diffuse;
			}
		}

		glm::vec3 V = normalize(rayOrigin - hitPoint);
		glm::vec3 reflectionDirection = normalize(2.0f * dot(V, rec.normal) * rec.normal - V);
		glm::vec3 reflectionOrigin = hitPoint;

		if (recursionLevel == 4) {
			return color;
		} else {
			recursionLevel++;
			color += rec.km * computeRayColor(scene, reflectionOrigin, reflectionDirection, 0.001f, INFINITY, recursionLevel);
		}
	}



	return color;
}

void Camera::TakePicture(Scene *scene)
{
	memset(renderedImage, 0, sizeof(float) * widthRes * heightRes * 3);
	float imageAspectRatio = widthRes / (float)heightRes;

	for (int y = 0; y < heightRes; y++) { // for each pixel
		for (int x = 0; x < widthRes; x++) {

			/* compute primary ray */

			// compute u, v, and w
			glm::vec3 rayOrigin = eye;
			glm::vec3 center = lookAt;

			glm::vec3 a = eye - center;
			glm::vec3 b = up;
			glm::vec3 w = a / glm::length(a);
			glm::vec3 u = glm::cross(b, w) / (float)(glm::length(glm::cross(b, w)));
			glm::vec3 v = glm::cross(w, u);

			// compute ly
			float ly = 2.0f * focalDistance * (float)tan(glm::radians(fovY / 2.0f));

			// compute lx
			float lx = ly * imageAspectRatio;

			// compute pixel width
			float pixelWidth = ly / (float) heightRes;

			// calculate view direction
			glm::vec3 viewDirection = normalize(lookAt - eye);

			// calculate Ic
			glm::vec3 Ic = eye + viewDirection * focalDistance;

			// calculate pc origin
			glm::vec3 pcOrigin = Ic - (lx / 2.0f) * u - (ly / 2.0f) * v;

			// Pc
			glm::vec3 Pc = pcOrigin + pixelWidth * ((float) x + 0.5f) * u + pixelWidth * ((float) y + 0.5f) * v;

			// calculate ray direction
			glm::vec3 rayDirection = normalize(Pc - eye);

			/* compute ray color */
			float t0 = 0.0f;
			float t1 = INFINITY;
			int recursionLevel = 0;
			
			glm::vec3 rayColor = computeRayColor(scene, rayOrigin, rayDirection, t0, t1, recursionLevel);

			/* set the color of the pixel to the ray color */
			renderedImage[int(y) * widthRes * 3 + int(x) * 3 + 0] = rayColor[0]; // red
			renderedImage[int(y) * widthRes *  3 + int(x) * 3 + 1] = rayColor[1]; // blue
			renderedImage[int(y) * widthRes * 3 + int(x) * 3 + 2] = rayColor[2]; // green

		}
	}
}
