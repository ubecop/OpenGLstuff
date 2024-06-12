#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// Inputs the color from the Vertex Shader
in vec3 color;

// Inputs texture coordinates from Vertex Shader
in vec2 texCoord;

// Gets Texture Unit from the main function
uniform sampler2D tex0;

void main()
{
   FragColor = texture(tex0, texCoord);
}