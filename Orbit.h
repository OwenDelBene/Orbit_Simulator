#ifndef ORBIT_CLASS_H
#define ORBIT_CLASS_H
#include "Mesh.h"
#include <vector>
#include <cmath>

class Orbit
{
public:

	float mass;
	glm::vec3 Velocity; 
	std::vector <Vertex> verts;
	std::vector <GLuint> ind; 
	glm::vec4 color; 
	glm::vec3 pos;
	

	void CircularOrbit(float mass, glm::vec3 Pos, glm::vec4 Color,  Shader shader); 

};


#endif