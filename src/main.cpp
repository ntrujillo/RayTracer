#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <chrono>
#include <iostream>
#include "Camera.h"
#include "Scene.h"

/* for loading bunny object */
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

/* glm */
#include <glm/glm.hpp>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1200

/* camera */
glm::vec3 eye(0.0f, 0.0f, 7.0f);
glm::vec3 lookAt(0.0f, 0.0f, 0.0f);
glm::vec3 up(0.0f, 1.0f, 0.0f);
float fovY = 45.0f;
float focalDistance = 1.0f;

/* scene */
bool bunnyRender = false;

float frameBuffer[WINDOW_HEIGHT][WINDOW_WIDTH][3];
GLFWwindow *window;

std::vector<Shape*> shapes;
std::vector<Light*> lights;

void ClearFrameBuffer()
{
	memset(&frameBuffer, 0, WINDOW_HEIGHT * WINDOW_WIDTH * 3 * sizeof(float));
}

void Display()
{	
	glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_FLOAT, frameBuffer);
}

// Load the geometry
void LoadModel(char* name, std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &norBuff)
{
	// Taken from Shinjiro Sueda with slight modification
	std::string meshName(name);
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string errStr;
	bool rc = tinyobj::LoadObj(&attrib, &shapes, &materials, &errStr, meshName.c_str());
	if (!rc) {
		std::cerr << errStr << std::endl;
	}
	else {
		// Some OBJ files have different indices for vertex positions, normals,
		// and texture coordinates. For example, a cube corner vertex may have
		// three different normals. Here, we are going to duplicate all such
		// vertices.
		// Loop over shapes
		for (size_t s = 0; s < shapes.size(); s++) {
			// Loop over faces (polygons)
			size_t index_offset = 0;
			for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
				size_t fv = shapes[s].mesh.num_face_vertices[f];
				// Loop over vertices in the face.
				for (size_t v = 0; v < fv; v++) {
					// access to vertex
					tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
					vertices.push_back(glm::vec3(attrib.vertices[3 * idx.vertex_index + 0],
												 attrib.vertices[3 * idx.vertex_index + 1],
												 attrib.vertices[3 * idx.vertex_index + 2]));
					norBuff.push_back(glm::vec3(attrib.normals[3 * idx.normal_index + 0],
												 attrib.normals[3 * idx.normal_index + 1],
												 attrib.normals[3 * idx.normal_index + 2]));
				}
				index_offset += fv;
			}
		}
	}
}

void Init()
{
	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_FALSE); // fix for mac resizing
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Assignment5 - Nathaniel Trujillo", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	ClearFrameBuffer();

	Scene scene;

	if (bunnyRender) {
		/* object name */
		std::string objName = "../obj/bunny.obj";
		char *obj = new char[objName.length() + 1];
		strcpy(obj, objName.c_str());

		/* triangle vertices */
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> norBuff;

		/* load model into triangles */
		LoadModel(obj, vertices, norBuff);
		delete [] obj;
		
		scene = Scene(vertices, norBuff);
	} else {
		scene = Scene();
	}

	Camera camera = Camera(WINDOW_WIDTH, WINDOW_HEIGHT, eye, lookAt, up, fovY, focalDistance); // modify to pass all necessary information
	
	auto start = std::chrono::high_resolution_clock::now();
	camera.TakePicture(&scene); // take picture of the scene using ray tracing (main loop of the ray tracer)
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Time passed (ms): " << duration.count() << std::endl;
	
	float *renderedImage = camera.GetRenderedImage(); // grab private variable of image
	memcpy(frameBuffer, renderedImage, sizeof(float) * WINDOW_HEIGHT * WINDOW_WIDTH * 3);
}


int main(int argc, char* argv[])
{	
	// if any arguments are present, render bunny
	if (argc > 1) {
		bunnyRender = true;
	}

	Init();
	while ( glfwWindowShouldClose(window) == 0) 
	{
		glClear(GL_COLOR_BUFFER_BIT);
		Display();
		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}