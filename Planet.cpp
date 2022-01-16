#include "Planet.h"
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

Planet::Planet( float mass, float radius, unsigned int rings, unsigned int sectors)
{
	Planet::mass = mass;

//sphere vertex stuff
	float const R = 1. / (float)(rings - 1);
	float const S = 1. / (float)(sectors - 1);


	// coords colors texCoords normals

	//Planet::vertices.resize(rings * sectors * 12);
	//std::vector<Vertex>::iterator itr = vertices.begin();
	int i = 0;
	for (int r = 0; r < rings; r++) for (int s = 0; s < sectors; s++)
	{
		float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
		float const y = sin(-M_PI_2 + M_PI * r * R);
		float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

		glm::vec3 coords = { x * radius, y * radius, z * radius };
		glm::vec3 colors = { 1.0f, 100.0f, 1.0f };
		glm::vec2 texCoords = { s * S, r * R };
		glm::vec3 normals = { x , y, z };

		Planet::vertices[i] = Vertex{ coords, colors, normals, texCoords };

		i++;
	}
	Planet::verts = { Planet::vertices, Planet::vertices + sizeof(Planet::vertices) / sizeof(Vertex) };

	i = 0;
	for (int r = 0; r < rings; r++) for (int s = 0; s < sectors; s++)
	{

		//indices[i++] = r * sectors + s;
		//indices[i++] = r * sectors + s + 1;
		//indices[i++] = (r + 1) * sectors + s + 1;
		//indices[i++] = (r + 1) * sectors + s;

		Planet::indices[i++] = r * sectors + s;
		Planet::indices[i++] = (r + 1) * sectors + s;
		Planet::indices[i++] = (r + 1) * sectors + (s + 1);
		Planet::indices[i++] = r * sectors + s;
		Planet::indices[i++] = (r + 1) * sectors + (s + 1);
		Planet::indices[i++] = r * sectors + (s + 1);



	}
	Planet::ind = { Planet::indices, Planet::indices + sizeof(Planet::indices) / sizeof(GLuint) };

}