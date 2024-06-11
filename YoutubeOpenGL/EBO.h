#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad\glad.h>

class EBO
{
public:
	// ID reference of EBO
	GLuint ID;

	// Constructor Generating an EBO and links it to indices
	EBO(GLuint* indices, GLsizeiptr size);

	// Binds EBO
	void Bind();
	// Unbinds EBO
	void Unbind();
	// Deletes EBO
	void Delete();
};

#endif
