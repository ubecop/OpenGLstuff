# 3D model of satellite using OpenGL 3.3 in C++ on Visual Studio 2015

This project provides a code that modelizes a satellite (SES25) in 3D with a light source.

## Installation and Setup

The project was done on a computer with Windows 10 Home, Version 1909. 
Install Visual Studio (VS) 2015 Community.
Install GLAD Library with this link : https://glad.dav1d.de/
In the API options, select 3.3 for gl. Select Core for Profile (this keeps only non-deprecated functions).
Click generate button, then download glad.zip.
Install source package for GLFW on : https://www.glfw.org/download.html
Download 64-bit installer for CMake : https://cmake.org/download/
Under "Binary distributions", click on the files for "Windows X64 Installer".

For more information on the installation and the code, use this OpenGL playlist from Victor Gordan :
https://www.youtube.com/playlist?list=PLPaoO-vpZnumdcb4tZc4x5Q-v7CkrQ6M-

The video "OpenGL Tutorial 0 - Install" shows how to import the necessary libraries in detail and how to build the solution.


## Features

For a more detailed explanation of the OpenGL rasterization pipeline, please watch this video by media.ccc.de :
https://www.youtube.com/watch?v=fL957hgX9kA
Title : Introduction to OpenGLES and GLSL programming
The entire playlist is also a good tutorial for learning OpenGL.

The code is separated into different classes in order to make the Main class more compact.

A vertex is a data structure contains different kinds of attributes such as position (2D or 3D), texture coordinates,
color coordinates and normal coordinates. It typically takes the form of a large array, such as :
 //     COORDINATES              /        COLORS          /   TexCoord      /     NORMALS          //
	1.42E-01, -6.00E-01, 2.63E+00,  0.83f, 0.70f, 0.44f,    0.0f, 0.0f,       0.0f, 1.0f, 0.0f

These coordinates are placed in a buffer of memory on the GPU. This is called a Vertex Buffer, hence the Vertex Buffer Object, or VBO, class.
The Vertex Array Object (VAO) class ties a layout to the buffer of memory - for example, the amount of bytes dedicated to each attribute. 
A VAO can hold several VBOs.

The EBO class allows the use of indices, which allows the repetition of vertices in any order.

The Texture class loads the images used as textures for generated surfaces.

The Camera class defines the controls for moving the camera in the generated video.

The Shader class grabs the contents of vertex shader files and fragment shader files. 

The adjusted_positions.txt and triangle_indices.txt were derived from an OFF file holding all the vertices and indices using a Python script.
This OFF file was itself created using data from a GEO file of the satellite. The indices were initially in groups of 4, like in the OFF file.
However, keeping the indices in groups of 4 resulted in a faulty modelization of the satellite model, where many rectangular surfaces were missing half of their area
and formed as triangles. 
So each group of 4 indices was turned into 2 groups of 3 indices to keep the rectangles intact (hence the triangle_indices.txt). 
Example : 0 1 2 3 -> 0 1 2 and 0 2 3


# Python Codes

geo2off.py takes a GEO file and changes it to the OFF format. index_changer.py takes an OFF files indices and changes their grouping. 
In this case, it takes each group of 4 indices from the original and turns it into 2 triplets (see example above).


