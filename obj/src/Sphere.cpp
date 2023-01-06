#include "Sphere.h"

Sphere::Sphere(glm::vec3 position, float radius, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, glm::vec3 km, float n)
{
    this->position = position;
    this->radius = radius;
    this->radius2 = pow(radius, 2);
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->km = km;
    this->n = n;
}

Sphere::~Sphere()
{
}

Record Sphere::getRecord() {
    Record rec;
    rec.ka = ka;
    rec.kd = kd;
    rec.ks = ks; 
    rec.km = km;
    rec.n = n;
    rec.center = position;
    return rec;
}

float Sphere::intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1) {

    // std::cout << "Ray Origin: (" << origin[0] << ", " << origin[1] << ", " << origin[2] << ")" << std::endl;
    // std::cout << "Ray Direction: (" << direction[0] << ", " << direction[1] << ", " << direction[2] << ")" << std::endl;

    float x0, x1;
    float t;

    glm::vec3 L = origin - position; 
    float a = dot(direction, direction); 
    float b = 2 * dot(direction, L); 
    float c = dot(L, L) - radius2; 

    // std::cout << "position: " << position[0] << ", " << position[1] << ", " << position[2] << std::endl;
    // std::cout << "(b2: " << pow(b, 2) << ") (4ac: " << 4 * a * c << ")" << std::endl;

    /* solve quadratic */
    float insideSqrt = pow(b, 2) - (4 * a * c); 

    if (insideSqrt < 0) {
        // std::cout << "quadratic can't be solved." << std::endl;
        return -1; // quadradic can't be solved
    } else if (insideSqrt == 0) {
        t = - 0.5 * b / a; 
        if (t < FLT_MAX && t >= 0) {
            return t;
        } else {
            return -1;
        }
    } else { 
        float q = (b > 0) ? 
            -0.5 * (b + sqrt(insideSqrt)): 
            -0.5 * (b - sqrt(insideSqrt)); 
        x0 = q / a; 
        x1 = c / q; 
    }

    if (x0 > x1) {
        // swap x0 and x1
        float temp = x0;
        x0 = x1;
        x1 = temp;
    }

    if (x0 < 0) { 
        x0 = x1;  //if t0 is negative, set as t1
        if (x0 < 0) {
            return -1;  // both t0 and t1 negative 
        }
    }

    t = x0;

    if (t < t1 && t >= t0) {
        return t;
    }
 
    return -1; 
}

glm::vec3 Sphere::getNormal(glm::vec3 hitPoint) {
    // find inverse normal
    glm::vec3 inverseNormal = hitPoint - position;

    // find normal
    normal = normalize(inverseNormal);

    return normal;
}

