#version 330 core
// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture coordinates
layout (location = 2) in vec2 aTex;

// Outputs the color for Fragment Shader
out vec3 color;
// Outputs the texture coordinates for Fragment Shader
out vec2 texCoord;

// Controls the scale of the vertices
uniform float scale;

// Camera uniform
uniform mat4 camMatrix;

void main()
{
	// Outputs the positions/coordinates of all vertices
	gl_Position = camMatrix * vec4(aPos,1.0);
	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord" 
	texCoord = aTex;
};