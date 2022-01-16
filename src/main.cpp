#include <iostream>
#include"Mesh.h"
#include "Planet.h"
#include "Sat.h"


// X = left to right | Y= Down to Up | Z = back to front

//TODO ORBIT MECHANICS, SAT GEN, EARTH TEX, MOON?


const unsigned int width = 800;
const unsigned int height = 800;


// Vertices coordinates
//Vertex vertices[] =
////std::vector<Vertex> vertices=
//{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
//	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
//	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
//	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
//};



// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2,
//	0, 2, 3
//};



//Vertex lightVertices[] =
//{ //     COORDINATES     //
//	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
//	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
//	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
//	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
//};
//
//GLuint lightIndices[] =
//{
//	0, 1, 2,
//	0, 2, 3,
//	0, 4, 7,
//	0, 7, 3,
//	3, 7, 6,
//	3, 6, 2,
//	2, 6, 5,
//	2, 5, 1,
//	1, 5, 4,
//	1, 4, 0,
//	4, 5, 6,
//	4, 6, 7
//};
Planet Earth(5.97219 * pow(10,24),  0.5f, 12, 12);
Planet Sun(1000, 2.0f, 12, 12); 
Planet Moon(100, 0.25f, 12, 12); 
Sat AGS6(1.0f, 1.0f, 1.0f, 1.0f, glm::vec3(-1.0f, 0.0f, 0.0f));

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);




	// Texture data
	Texture textures[]
	{
		Texture("Earth.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("Earth2.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
		
	};





	

	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	Shader MoonShader("moon.vert", "default.frag");
	Shader SatShader("Sat.vert", "default.frag");
	// Store mesh data in vectors for the mesh
	/*std::vector <Vertex> verts(Earth.vertices, Earth.vertices + sizeof(Earth.vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(Earth.indices, Earth.indices + sizeof(Earth.indices) / sizeof(GLuint));*/
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	


	
	// Store mesh data in vectors for the mesh
	/*std::vector <Vertex> lightVerts(Sun.vertices, Sun.vertices + sizeof(Sun.vertices) / sizeof(Vertex));
	std::vector <GLuint> lightInd(Sun.indices, Sun.indices + sizeof(Sun.indices) / sizeof(GLuint));*/
	// Crate light mesh
	Mesh earth(Earth.verts, Earth.ind, tex);
	Mesh sun(Sun.verts, Sun.ind, tex);

	Mesh sat6(AGS6.verts, AGS6.ind, tex);

	Mesh moon(Moon.verts, Moon.ind, tex); 



	glm::vec4 SunColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 SunPos = glm::vec3(20.0f, 0.0f, 0.0f);
	glm::mat4 SunModel = glm::mat4(1.0f);
	

	glm::vec3 EarthPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 EarthModel = glm::mat4(1.0f);

	glm::vec3 SatPos = glm::vec3(0.0f, 0.0f,1.0f);
	glm::mat4 SatModel = glm::mat4(1.0f);

	glm::vec3 MoonPos = glm::vec3(-4.0f, 0.0f, 0.0f);
	glm::mat4 MoonModel = glm::mat4(1.0f);

	
	EarthModel = glm::translate(EarthModel, EarthPos);
	SunModel = glm::translate(SunModel, SunPos);
	SatModel = glm::translate(SatModel, SatPos); 
	MoonModel = glm::translate(MoonModel, MoonPos);
	


	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(EarthModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), SunColor.x, SunColor.y, SunColor.z, SunColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), SunPos.x, SunPos.y, SunPos.x); 

	SatShader.Activate(); 
	glUniformMatrix4fv(glGetUniformLocation(SatShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(SatModel));
	glUniform4f(glGetUniformLocation(SatShader.ID, "lightColor"), SunColor.x, SunColor.y, SunColor.z, SunColor.w);
	glUniform3f(glGetUniformLocation(SatShader.ID, "lightPos"), SunPos.x, SunPos.y, SunPos.x);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(SunModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), SunColor.x, SunColor.y, SunColor.z, SunColor.w);

	MoonShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(MoonShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(MoonModel));
	glUniform4f(glGetUniformLocation(MoonShader.ID, "lightColor"), SunColor.x, SunColor.y, SunColor.z, SunColor.w);
	glUniform3f(glGetUniformLocation(MoonShader.ID, "lightPos"), SunPos.x, SunPos.y, SunPos.x);






	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));


	

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		//SatPos = glm::vec3(SatPos.x, SatPos.y + 0.000001f, SatPos.z); 
		//glm::mat4 SatModel = glm::mat4(1.0f);
		//SatModel = glm::translate(SatModel, SatPos);
		//SatShader.Activate();
		//glUniformMatrix4fv(glGetUniformLocation(SatShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(SatModel));
		//glUniform4f(glGetUniformLocation(SatShader.ID, "lightColor"), SunColor.x, SunColor.y, SunColor.z, SunColor.w);
		//glUniform3f(glGetUniformLocation(SatShader.ID, "lightPos"), SunPos.x, SunPos.y, SunPos.x);
		//AGS6.CircularOrbit(Earth.mass,SunPos, SunColor, SatShader); 
		// Draws different meshes
		AGS6.CircularOrbit(Earth.mass, Sun.pos, Sun.color, SatShader); 
		earth.Draw(shaderProgram, camera);

		sun.Draw(lightShader, camera);

		sat6.Draw(SatShader, camera); 

		moon.Draw(MoonShader, camera); 


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	shaderProgram.Delete();
	lightShader.Delete();
	SatShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}


