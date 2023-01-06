#include "Scene.h"

Scene::~Scene()
{
}

Scene::Scene()
{
    /* spheres */

    glm::vec3 position1(-1.0f, -0.7f, 3.0f);
    float radius1 = 0.3f;
    glm::vec3 sphere_ka1(0.1f, 0.1f, 0.1f);
    glm::vec3 sphere_kd1(0.2f, 1.0f, 0.2f);
    glm::vec3 sphere_ks1(1.0f, 1.0f, 1.0f);
    glm::vec3 sphere_km1(0.0f, 0.0f, 0.0f);
    float sphere_n1 = 100.0f;
    Shape* sphere1 = new Sphere(position1, radius1, sphere_ka1, sphere_kd1, sphere_ks1, sphere_km1, sphere_n1); // sphere 1
    this->shapes.push_back(sphere1);

    glm::vec3 position2(1.0f, -0.5f, 3.0f);
    float radius2 = 0.5f;
    glm::vec3 sphere_ka2(0.1f, 0.1f, 0.1f);
    glm::vec3 sphere_kd2(0.0f, 0.0f, 1.0f);
    glm::vec3 sphere_ks2(1.0f, 1.0f, 1.0f);
    glm::vec3 sphere_km2(0.0f, 0.0f, 0.0f);
    float sphere_n2 = 10.0f;
    Shape* sphere2 = new Sphere(position2, radius2, sphere_ka2, sphere_kd2, sphere_ks2, sphere_km2, sphere_n2); // sphere 2
    this->shapes.push_back(sphere2);

    glm::vec3 position3(-1.0f, 0.0f, 0.0f);
    float radius3 = 1.0f;
    glm::vec3 sphere_ka3(0.0f, 0.0f, 0.0f);
    glm::vec3 sphere_kd3(0.0f, 0.0f, 0.0f);
    glm::vec3 sphere_ks3(0.0f, 0.0f, 0.0f);
    glm::vec3 sphere_km3(1.0f, 1.0f, 1.0f);
    float sphere_n3 = 0.0f;
    Shape* sphere3 = new Sphere(position3, radius3, sphere_ka3, sphere_kd3, sphere_ks3, sphere_km3, sphere_n3); // sphere 3 (reflective)
    this->shapes.push_back(sphere3);

    glm::vec3 position4(1.0f, 0.0f, -1.0f);
    float radius4 = 1.0f;
    glm::vec3 sphere_ka4(0.0f, 0.0f, 0.0f);
    glm::vec3 sphere_kd4(0.0f, 0.0f, 0.0f);
    glm::vec3 sphere_ks4(0.0f, 0.0f, 0.0f);
    glm::vec3 sphere_km4(0.8f, 0.8f, 0.8f);
    float sphere_n4 = 0.0f;
    Shape* sphere4 = new Sphere(position4, radius4, sphere_ka4, sphere_kd4, sphere_ks4, sphere_km4, sphere_n4); // sphere 4 (reflective)
    this->shapes.push_back(sphere4);

    /* planes */

    glm::vec3 center1(0.0f, -1.0f, 0.0f);
    glm::vec3 normal1(0.0f, 1.0f, 0.0f);
    glm::vec3 plane_ka1(0.1f, 0.1f, 0.1f);
    glm::vec3 plane_kd1(1.0f, 1.0f, 1.0f);
    glm::vec3 plane_ks1(0.0f, 0.0f, 0.0f);
    glm::vec3 plane_km1(0.0f, 0.0f, 0.0f);
    float plane_n1 = 0.0f;
    Shape* plane1 = new Plane(center1, normal1, plane_ka1, plane_kd1, plane_ks1, plane_km1, plane_n1); // plane 1
    this->shapes.push_back(plane1);
    
    glm::vec3 center2(0.0f, 0.0f, -3.0f);
    glm::vec3 normal2(0.0f, 0.0f, 1.0f);
    glm::vec3 plane_ka2(0.1f, 0.1f, 0.1f);
    glm::vec3 plane_kd2(1.0f, 1.0f, 1.0f);
    glm::vec3 plane_ks2(0.0f, 0.0f, 0.0f);
    glm::vec3 plane_km2(0.0f, 0.0f, 0.0f);
    float n2 = 0.0f;
    Shape* plane2 = new Plane(center2, normal2, plane_ka2, plane_kd2, plane_ks2, plane_km2, n2); // plane 2
    this->shapes.push_back(plane2);

    /* lights */

    glm::vec3 light1_position(0.0f, 3.0f, -2.0f);
    glm::vec3 color1(0.2f, 0.2f, 0.2f);
    Light* light1 = new Light(light1_position, color1); // light 1
    this->lights.push_back(light1);

    glm::vec3 light2_position = {-2.0f, 1.0f, 4.0f};
    glm::vec3 color2(0.5f, 0.5f, 0.5f);
    Light* light2 = new Light(light2_position, color2); // light 2
    this->lights.push_back(light2);
}

// Create a vector of triangles. Considers the texture coordinates if they are available.
std::vector<Triangle> Scene::CreateTriangleVector(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &norBuff, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n)
{
    std::vector<Triangle> triangles;
    for (int i = 0; i < vertices.size() / 3; i++)
    {
        Triangle triangle(vertices[i * 3 + 0], norBuff[i * 3 + 0], vertices[i * 3 + 1], norBuff[i * 3 + 1], vertices[i * 3 + 2], norBuff[i * 3 + 2], ka, kd, ks, km, n);
        triangles.push_back(triangle);
    }

    return triangles;
}

/* constructor for bunny rendering */
Scene::Scene(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &norBuff) {
    /* define object properties */
    glm::vec3 ka(0.1f, 0.1f, 0.1f);
    glm::vec3 kd(0.0, 0.0, 1.0);
    glm::vec3 ks(1.0, 1.0, 0.5);
    glm::vec3 km(0.0, 0.0, 0.0);
    float n = 100.0f;

    /* create a vector of triangles */
    std::vector<Triangle> triangles = CreateTriangleVector(vertices, norBuff, ka, kd, ks, km, n); 

    // /* create BHV */
    // Shape* bvh = new BVH(triangles);
    
    // /* add bvh to shapes vector */
    // shapes.push_back(bvh);

    /* create BHVtree */
    int maxShapesInNode = 3;
    std::cout << "Start building tree." << std::endl;
    Shape* bvhTree = new BVHtree(triangles, maxShapesInNode);
    std::cout << "Done building tree." << std::endl;
    
    /* add bvhTree to shapes vector */
    shapes.push_back(bvhTree);

    /* lights */
    glm::vec3 light1_position(0.0f, 3.0f, -2.0f);
    glm::vec3 color1(0.2f, 0.2f, 0.2f);
    Light* light1 = new Light(light1_position, color1); // light 1
    this->lights.push_back(light1);

    glm::vec3 light2_position = {-2.0f, 1.0f, 4.0f};
    glm::vec3 color2(0.5f, 0.5f, 0.5f);
    Light* light2 = new Light(light2_position, color2); // light 2
    this->lights.push_back(light2);
}

bool Scene::Hit(glm::vec3 &rayOrigin, glm::vec3 &rayDirection, float &t, float t0, float t1, Record &rec) {
        t = t1;
        float shapeIndex = 0;
        
        // std::cout << "hit function is running..." << std::endl;

        // iterate through all shapes to find the front-most shape
        for (int i = 0; i < shapes.size(); i++) {
            float new_t = shapes.at(i)->intersect(rayOrigin, rayDirection, t0, t1);

            /* update new lowest t if there is a hit */
            if (new_t <= t && new_t >=0) {
                t = new_t;
                shapeIndex = i;

                // find intersecton point
                glm::vec3 hitPoint = rayOrigin + (rayDirection * t);

                rec = shapes.at(shapeIndex)->getRecord();
                rec.normal = shapes.at(shapeIndex)->getNormal(hitPoint);
            }
        }

        if (t == t1) { /* there was no hit since t was never updated */
            return false;
        } else {
            return true;
        }
}