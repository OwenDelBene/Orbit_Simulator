#include "Sat.h"

Sat::Sat(float mass, float length, float width, float height, glm::vec3 Pos)
{
	Sat::mass = mass; 
	Sat::pos = Pos; 
	 
	
	Sat::vertices[0] = Vertex{ glm::vec3(-0.1f * length, -0.1f * width,  0.1f * height) };
	Sat::vertices[1] = Vertex{ glm::vec3(-0.1f * length, -0.1f * width, -0.1f * height) };
	Sat::vertices[2] = Vertex{ glm::vec3(0.1f * length, -0.1f * width, -0.1f * height) };
	Sat::vertices[3] = Vertex{ glm::vec3(0.1f * length, -0.1f * width,  0.1f * height) };
	Sat::vertices[4] = Vertex{ glm::vec3(-0.1f * length,  0.1f * width,  0.1f * height) };
	Sat::vertices[5] = Vertex{ glm::vec3(-0.1f * length,  0.1f * width, -0.1f * height) };
	Sat::vertices[6] = Vertex{ glm::vec3(0.1f * length,  0.1f * width, -0.1f * height) };
	Sat::vertices[7] = Vertex{ glm::vec3(0.1f * length,  0.1f * width,  0.1f * height) };

	Sat::verts = { Sat::vertices, Sat::vertices + sizeof(Sat::vertices) / sizeof(Vertex) };
	Sat::ind = { Sat::indices, Sat::indices + sizeof(Sat::indices) / sizeof(GLuint) };
	
}