#ifndef PLANET_CLASS_H
#define PLANET_CLASS_H
#include "Orbit.h"
class Planet: public Orbit
{
public:
	Vertex vertices[1600];
	GLuint indices[1200];
	float radius; 
	unsigned int rings, sectors; 
	Planet( float mass, float radius, unsigned int rings, unsigned int sectors);
	
};

#endif