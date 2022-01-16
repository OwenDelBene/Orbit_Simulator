#include "Orbit.h"


void Orbit::CircularOrbit(float mass, glm::vec3 Pos, glm::vec4 Color, Shader shader)
{
	float scale = 100000000.0f;
	//TODO: R is hardcoded for altitude of 400km for aggiesat6
	// F = Gmm/r^2
	// V = sqrt(GM/R) 
	// Tangential velocity unit vector = Orthogonal complement = <-z,x>
	// Centripetal force unit vector = cross product of tangent unit vector and y axis
	float G = 6.67430 * pow(10, -11);
	float velocity = sqrt(G* mass/ 6356400) / scale; 
	float CentripetalForce = G * mass * this->mass / (pow(6356400, 2)) /scale;
	glm::vec3 Tangent = velocity * glm::vec3(-this->pos.z, this->pos.y, this->pos.x);

 	//this->pos = glm::vec3(this->pos.x, this->pos.y + 0.0001f, this->pos.z); 
	this->pos = (this->pos + Tangent + CentripetalForce*glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), Tangent)); 
	
	glm::mat4 model = glm::mat4(1.0f); 
	model = glm::translate(model, this->pos); 
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), Color.x,Color.y, Color.z, Color.w);
	glUniform3f(glGetUniformLocation(shader.ID, "lightPos"), Pos.x, Pos.y, Pos.z);




}