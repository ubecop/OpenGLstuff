#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad\glad.h>
#include"VBO.h"

class VAO {
public:
	// ID reference for the Vertex Array Object
	GLuint ID;

	// Constructor that generates a VAO ID
	VAO();

	// Links VBO to the VAO using a certain layout
	void LinkVBO(VBO& VBO, GLuint layout);
	void Bind();
	void Unbind();
	void Delete();
};
#endif
