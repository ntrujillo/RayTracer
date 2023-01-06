#include "BVH.h"
#include <algorithm>

// BVH::BVH(std::vector<Triangle> &triangles)
BVH::BVH(std::vector<Triangle> &triangles, std::vector<triangleInfo> &info, int start, int end)
{
    /* init startIndex and endIndex */
    startIndex = start;
    endIndex = end;

    /* init children */
    leftChild = nullptr;
    rightChild = nullptr;

    /* by default assume leaf is false */
    isLeaf = false;
    
    /* add triangles to collection */
    this->triangles = triangles;
    this->triangleInfoVector = info;

    max = {0.0f, 0.0f, 0.0f};
    min = {0.0f, 0.0f, 0.0f};

    // find bounding box
    for (int i = start; i < end + 1; i++) {
        float xmin_temp = triangles.at(info.at(i).triangleIndex).getXmin();
        if (xmin_temp < min.x) min.x = xmin_temp;

        float xmax_temp = triangles.at(info.at(i).triangleIndex).getXmax();
        if (xmax_temp > max.x) max.x = xmax_temp;

        float ymin_temp = triangles.at(info.at(i).triangleIndex).getYmin();
        if (ymin_temp < min.y) min.y = ymin_temp;

        float ymax_temp = triangles.at(info.at(i).triangleIndex).getYmax();
        if (ymax_temp > max.y) max.y = ymax_temp;

        float zmin_temp = triangles.at(info.at(i).triangleIndex).getZmin();
        if (zmin_temp < min.z) min.z = zmin_temp;

        float zmax_temp = triangles.at(info.at(i).triangleIndex).getZmax();
        if (zmax_temp > max.z) max.z = zmax_temp;
    }

    // std::cout << "Bounding box initialized: " << "x: " << min.x << " -> " << max.x << std::endl;
    // std::cout << "Bounding box initialized: " << "y: " << min.y << " -> " << max.y << std::endl;
    // std::cout << "Bounding box initialized: " << "z: " << min.z << " -> " << max.z << std::endl;

    // std::cout << "BVH successfully initialized." << std::endl;
}

BVH::~BVH()
{
}

float BVH::intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1) {

    // std::cout << "BVH instersect() start" << std::endl;

    // std::cout << "Checking intersection for (" << origin.x << ", " << origin.y << ", " << origin.z << ") + t * (" << direction.x << ", " << direction.y << ", " << direction.z << ")" << std::endl;

    bool intersect = false;

    /* check if ray intersects with bounding box */
    float tmin = (min.x - origin.x) / direction.x; 
    float tmax = (max.x - origin.x) / direction.x; 
 
    if (tmin > tmax) std::swap(tmin, tmax); 
 
    float tymin = (min.y - origin.y) / direction.y; 
    float tymax = (max.y - origin.y) / direction.y; 
 
    if (tymin > tymax) std::swap(tymin, tymax); 
 
    if ((tmin > tymax) || (tymin > tmax)) {
        // std::cout << "intersect fail case 1: ";
        // std::cout << tmin << " is <= " << tymax << ", or " << tymin << " is <= " << tmax << std::endl;
        intersect = false; 
    }
 
    if (tymin > tmin) 
        tmin = tymin; 
 
    if (tymax < tmax) 
        tmax = tymax; 
 
    float tzmin = (min.z - origin.z) / direction.z; 
    float tzmax = (max.z - origin.z) / direction.z; 
 
    if (tzmin > tzmax) std::swap(tzmin, tzmax); 
 
    if ((tmin > tzmax) || (tzmin > tmax)) {
        // std::cout << "intersect fail case 2: ";
        // std::cout << tmin << " is <= " << tzmax << ", or " << tzmin << " is <= " << tmax << std::endl;
        intersect = false; 
    } else {
        if (tzmin > tmin)
        tmin = tzmin; 
 
        if (tzmax < tmax) 
            tmax = tzmax; 

        intersect = true;
    }

    /* if ray is within the bounding box */
    if (intersect) {
        // std::cout << "intersect detected!" << std::endl;
        float t;
        
        /* iterate through all the triangles and determine a hit */
        t = t1;

        // iterate through all shapes to find the front-most shape
        // std::cout << "checking " << endIndex - startIndex + 1 << " triangles for intersection" << std::endl;
        for (int i = startIndex; i < endIndex + 1; i++) {
            
            float new_t = triangles.at(triangleInfoVector.at(i).triangleIndex).intersect(origin, direction, t0, t1);

            /* update new lowest t if there is a hit */
            if (new_t <= t && new_t >=0) {
                t = new_t;
                
                /* store the index of the triangle */
                hitIndex = i;
            }
        }

        if (t == t1) { /* there was no hit since t was never updated */
            // std::cout << "BVH instersect() end" << std::endl;
            return -1;
        } else {
            // std::cout << "BVH instersect() end" << std::endl;
            return t;
        }

    } else { /* otherwise */
        // std::cout << "BVH instersect() end" << std::endl;
        return -1; // no intersection
    }
}

Record BVH::getRecord() {
    Record rec;

    glm::vec3 hitPoint(0.0f); /* hit point doens't matter */

    rec = triangles.at(hitIndex).getRecord();
    rec.normal = triangles.at(hitIndex).getNormal(hitPoint);

    // std::cout << "original record: "
    //  << " kd(" << rec.kd[0] << ", " << rec.kd[1] << ", " << rec.kd[2] << ")"
    //  << " km(" << rec.km[0] << ", " << rec.km[1] << ", " << rec.km[2] << ")"
    //  << " ks(" << rec.ks[0] << ", " << rec.ks[1] << ", " << rec.ks[2] << ")"
    //  << " n(" << rec.n << ")"
    //  << " normal(" << rec.normal[0] << ", " << rec.normal[1] << ", " << rec.normal[2] << ")"
    //  << std::endl;

    return rec;
}

glm::vec3 BVH::getNormal(glm::vec3 hitPoint)
{
    return triangles.at(hitIndex).getNormal(hitPoint);
}
