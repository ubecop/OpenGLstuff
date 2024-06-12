#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES                          /   COLORS               //
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,       0.8f, 0.3f, 0.02f,  // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,       0.8f, 0.3f, 0.02f,  // Lower right corner
	 0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,    1.0f, 0.6f, 0.32f,  // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) / 6, 0.0f,       0.9f, 0.45f,0.17f,  // Inner left
	 0.25f, 0.5f * float(sqrt(3)) / 6, 0.0f,       0.9f, 0.45f,0.17f,  // Inner right
	 0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,       0.8f, 0.3f, 0.02f   // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};



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
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);



	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");



	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*) 0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Get ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	/*
	float prev_time = float(glfwGetTime()); // Keeps track of time
	float angle = 0.0f; // Will control the color
	*/

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		glUniform1f(uniID, 0.5f);
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		//glfwSwapBuffers(window); If you want an epileptic seizure
		

		// To use this trigonometry section, remove the comment markers from prev_time and angle
		// And put the section of the loop above in comments 

		/*
		float time = float(glfwGetTime());
		if (time - prev_time >= 0.1f) // this is True every 0.1 seconds
		{
			angle += 0.1f; // Changes angle to change colors
			prev_time = time; // Resets prev_time to current time
		}

		// Use of trigonometry to nicely change colors
		glClearColor(float(sin(angle)), float(cos(angle)), float(tan(angle)), 1.0f);
		// Basic needed functions for changes to be visible
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		*/

		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}