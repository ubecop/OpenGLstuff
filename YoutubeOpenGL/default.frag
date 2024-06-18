#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// Inputs the color from the Vertex Shader
in vec3 color;

// Inputs texture coordinates from Vertex Shader
in vec2 texCoord;

// Imports the normal from Vertex Shader
in vec3 Normal;

// Imports the current position from the Vertex Shader
in vec3 crntPos;

// Gets Texture Unit from the main function
uniform sampler2D tex0;
// Gets the color of the light from the main function
uniform vec4 lightColor;
// Gets the postion of the light from the main function
uniform vec3 lightPos;
// Gets the postion of the camera from the main function
uniform vec3 camPos;


void main()
{
   // Difficult to calculate brightness of unlit surfaces, so we're putting a base ambient light
   // Remove ambient to get no ambient light
   float ambient = 0.20f;

   // diffuse lighting
   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(lightPos - crntPos);
   float diffuse = max(dot(normal, lightDirection), 0.0f);

   // specular lighting
   float specularLight = 0.50f;
   vec3 viewDirection = normalize(camPos - crntPos);
   vec3 reflectionDirection = reflect(-lightDirection, normal);
   float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
   float specular = specAmount * specularLight;


   // Outputs final color
   FragColor = texture(tex0, texCoord) * lightColor * (diffuse + ambient + specular);
}