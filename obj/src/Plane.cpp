#include "Plane.h"


Plane::Plane(glm::vec3 center, glm::vec3 normal, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n)
{
    this->center = center;
    this->normal = normal;
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->km = km;
    this->n = n;
}

Plane::~Plane()
{
}

float Plane::intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1) {
    // assuming vectors are all normalized
    float denominator = dot(normal, direction); 
    glm::vec3 p_prime = center; 
    float t = dot((p_prime - origin), normal) / denominator; 

    if (t < t1 && t >= t0) {
        return t;
    } else {
        return -1;
    }
}

Record Plane::getRecord() {
    Record rec;
    rec.ka = ka;
    rec.kd = kd;
    rec.ks = ks; 
    rec.km = km;
    rec.n = n;
    rec.center = center;
    return rec;
}


glm::vec3 Plane::getNormal(glm::vec3 hitPoint) {
    return normal;
}
