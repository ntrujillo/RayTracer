#include "Triangle.h"


Triangle::Triangle(glm::vec3 v0, glm::vec3 n0, glm::vec3 v1, glm::vec3 n1, glm::vec3 v2, glm::vec3 n2, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n)
{
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    normals[0] = n0;
    normals[1] = n1;
    normals[2] = n2;
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->km = km;
    this->n = n;
}

Triangle::~Triangle()
{
}

float Triangle::intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1) {

    glm::vec3 v0v1 = v[1] - v[0]; 
    glm::vec3 v0v2 = v[2] - v[0]; 
    glm::vec3 P = cross(direction, v0v2);
    float determinant = dot(v0v1, P);

    // ray paralell with triangle if det is close to 0
    if (fabs(determinant) < 0.0000001) return -1; // return false

    // back facing triangle or ray misses triangle if det is negative
    if (determinant < 0.0000001) return -1; // return false

    float invDeterminant = 1 / determinant; 

    glm::vec3 tvec = origin - v[0]; 
    alpha = dot(tvec, P) * invDeterminant; // alpha!
    if (alpha < 0 || alpha > 1) return -1; // return false

    glm::vec3 Q = cross(tvec, v0v1);
    beta = dot(direction, Q) * invDeterminant; // beta !
    if (beta < 0 || alpha + beta > 1) return -1; // return false

    gamma = 1 - alpha - beta; // gamma!

    // std::cout << "(alpha, beta, gamma) " << "(" << alpha << ", " << beta << ", " <<  gamma << ")" << std::endl;

    float t = dot(v0v2, Q) * invDeterminant;

    return t; // return true
}

Record Triangle::getRecord() {
    Record rec;
    rec.ka = ka;
    rec.kd = kd;
    rec.ks = ks; 
    rec.km = km;
    rec.n = n;
    return rec;
}


glm::vec3 Triangle::getNormal(glm::vec3 hitPoint) {
    glm::vec3 normal = normals[0] * gamma + normals[1] * alpha + normals[2] * beta;
    
    return normal;
}
