#include "BVHtree.h"

bool compareByXaxis(const triangleInfo &a, const triangleInfo &b)
{
    return a.avg.x < b.avg.x;
}

bool compareByYaxis(const triangleInfo &a, const triangleInfo &b)
{
    return a.avg.x < b.avg.x;
}

bool compareByZaxis(const triangleInfo &a, const triangleInfo &b)
{
    return a.avg.x < b.avg.x;
}

void BVHtree::BuildTree(char axis, BVH *node, std::vector<Triangle> &tri, std::vector<triangleInfo> &triInfo) {
    /* check if requirement is met */
    int start_index = node->getStartIndex(); 
    int end_index = node->getEndIndex();
    int mid_index = start_index + (end_index - start_index) / 2;
    int numShapes = end_index - start_index + 1;

    // std::cout << "END INDEX: " << end_index << ", START INDEX: " << start_index << std::endl;
    if (numShapes <= maxShapesInNode) {
        // don't split any more, mark as leaf, and return
        node->setLeafTrue();
        // std::cout << "criteria met" << std::endl;
        return;

    } else {
        // std::cout << "criteria not met, " << numShapes << " is not <= " << maxShapesInNode << std::endl;

        /* sort triangle info vector by specified axis and start/stop indices */
        std::vector<triangleInfo>::iterator begin = triInfo.begin() + start_index;
        std::vector<triangleInfo>::iterator end = triInfo.begin() + end_index;
        switch(axis) {
        case 'x':
            std::sort(begin, end, compareByXaxis);
            break;
        case 'y':
            std::sort(begin, end, compareByYaxis);
            break;
        case 'z':
            std::sort(begin, end, compareByZaxis);
            break;
        }

        /* construct left child with first half of triangles */
        BVH* leftChild = new BVH(tri, triInfo, start_index, mid_index);

        /* construct right child with second half of triangles */
        BVH* rightChild = new BVH(tri, triInfo, mid_index + 1, end_index);

        /* populate root */
        node->setLeft(leftChild);
        node->setRight(rightChild);

        /* determine next axis */
        char new_axis;
        if (axis == 'x') {
            new_axis = 'y';
            // std::cout << "axis change: " << axis << " -> " << new_axis << std::endl;
        }
        if (axis == 'y') {
            new_axis = 'z';
            // std::cout << "axis change: " << axis << " -> " << new_axis << std::endl;
        }
        if (axis == 'z') {
            new_axis = 'x';
            // std::cout << "axis change: " << axis << " -> " << new_axis << std::endl;
        }

        /* call BuildTree on left child */
        BuildTree(new_axis, leftChild, tri, triInfo);
        // std::cout << "done building LEFT tree" << std::endl;

        /* call BuildTree on right child*/
        BuildTree(new_axis, rightChild, tri, triInfo);
        // std::cout << "done building RIGHT tree" << std::endl;
    }
}

BVHtree::BVHtree(std::vector<Triangle> &t, int n)
{
    /* initialize variables */
    triangles = t;
    maxShapesInNode = n;

    /* constrict triangleInfo vector */
    for (int i = 0; i < triangles.size(); i++) {
        glm::vec3 axisAvg;
        axisAvg.x = triangles.at(i).getXavg();
        axisAvg.y = triangles.at(i).getYavg();
        axisAvg.z = triangles.at(i).getZavg();

        triangleInfo info;
        info.avg = axisAvg;
        info.triangleIndex = i;

        triangleInfoVector.push_back(info);
    }

    /* construct root node */
    int nTriangles = t.size();
    root = new BVH(t, triangleInfoVector, 0, nTriangles - 1);
    std::cout << "initialized root node with " << nTriangles  << " triangles" << std::endl;

    /* build tree */
    // std::cout << "calling BuildTree on root node with starting x axis" << std::endl;
    BuildTree('x', root, t, triangleInfoVector);
}

BVHtree::~BVHtree()
{
}

float BVHtree::findIntersectionLeaf(BVH* node, glm::vec3 &origin, glm::vec3 &direction, float t0, float t1) {
    // std::cout << "BVHtree findIntersectionLeaf() start" << std::endl;

    if (node == nullptr) {
        std::cout << "error: node is nullptr!" << std::endl;
    }

    /* check to see if root intersect happens */
    float t = node->intersect(origin, direction, t0, t1);
    // std::cout << "found t: " << t << std::endl;

    if (t == -1) {
        return -1;
    }

    /* if leaf */
    if (node->getIsLeaf() == true) {
        /* check for intersection*/
        if (t != -1) {
            hitNode = node;
            return t; // HIT!
        } else { 
            return -1; // no intersection
        }
    }

    /* root is not a leaf so check left and right children */
    float checkLeft, checkRight;
    checkLeft = findIntersectionLeaf(node->getLeft(), origin, direction, t0, t1);

    /* if left intersects then return left */
    if (checkLeft != -1) {
        // std::cout << "we found an intersection in left child!" << std::endl;
        hitNode = node; /* store triangle index */
        // std::cout << "BVHtree findIntersectionLeaf() end -> left child intersect!" << std::endl;
        return checkLeft; // intersection in left sub tree
    }

    checkRight = findIntersectionLeaf(node->getRight(), origin, direction, t0, t1);
    
    /* if right intersects then return right*/
    if (checkRight != -1) {
        // std::cout << "we found an intersection in right child!" << std::endl;
        hitNode = node; /* store triangle index */
        // std::cout << "BVHtree findIntersectionLeaf() end -> right child intersect!" << std::endl;
        return checkRight; // intersection in right sub tree
    }

    /* if both sub-trees don't intersect then no intersection happens */
    if (checkLeft == -1 && checkRight == -1) {
        // std::cout << "BVHtree findIntersectionLeaf() end -> both children don't intersect" << std::endl;
        return -1; // no intersection
    }

    // std::cout << "BVHtree findIntersectionLeaf() end -> ERROR CATCH ALL" << std::endl;
    return -1; // catch all
}

float BVHtree::intersect(glm::vec3 &origin, glm::vec3 &direction, float t0, float t1)
{
    // std::cout << "BVHtree intersection() start" << std::endl;
    float t = findIntersectionLeaf(root, origin, direction, t0, t1);
    // std::cout << "BVHtree intersection() end" << std::endl;
    return t;
}

Record BVHtree::getRecord()
{
    Record rec;

    glm::vec3 hitPoint(0.0f); /* hit point doens't matter */

    rec = hitNode->getRecord();
    rec.normal = hitNode->getNormal(hitPoint);

    // std::cout << "transfered record: "
    //  << " kd(" << rec.kd[0] << ", " << rec.kd[1] << ", " << rec.kd[2] << ")"
    //  << " km(" << rec.km[0] << ", " << rec.km[1] << ", " << rec.km[2] << ")"
    //  << " ks(" << rec.ks[0] << ", " << rec.ks[1] << ", " << rec.ks[2] << ")"
    //  << " n(" << rec.n << ")"
    //  << " normal(" << rec.normal[0] << ", " << rec.normal[1] << ", " << rec.normal[2] << ")"
    //  << std::endl;

    return rec;
}

glm::vec3 BVHtree::getNormal(glm::vec3 hitPoint)
{
    return hitNode->getNormal(hitPoint);
}
