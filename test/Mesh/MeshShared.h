#ifndef _MESHSHARED__H_
#define _MESHSHARED__H_

//--------------------------------------------------------------------------

#include <gtest/gtest.h>
#include "mesh.h"


//--------------------------------------------------------------------------
// Using same vertices in all tests
//--------------------------------------------------------------------------
std::vector<glm::vec3> verts{   glm::vec3(0.0f, 0.0f, 0.0f),
                                glm::vec3(-1.0f, 0.0f, -1.0f),
                                glm::vec3(1.0f, 0.0f, -1.0f),
                                glm::vec3(-1.0f, 0.0f, 1.0f),
                                glm::vec3(1.0f, 0.0f, 1.0f)     };

std::vector<glm::vec3> norms{   glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f)),
                                glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)),
                                glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)),
                                glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)),
                                glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f))     };

std::vector<glm::ivec3> tris{};

//  3-----4
//  |\ 2 /|
//  | \ / |
//  |3 0 1|
//  | / \ |
//  |/ 0 \|
//  1-----2

//--------------------------------------------------------------------------


#endif //_MESHSHARED__H_
