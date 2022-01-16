#ifndef SAT_CLASS_H
#define SAT_CLASS_H
#include "Orbit.h"
class Sat: public Orbit
{
public:
	Vertex vertices[8];
	GLuint indices[36] = {
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
	};

	Sat(float mass, float length, float width, float height, glm::vec3 Pos); 
	

};

#endif
