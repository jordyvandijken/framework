#include <common/sprite.h>

Sprite::Sprite(std::string imagepath, int filter) {
	vertexbuffer = 0;
	uvbuffer = 0;
	texture = 0;

	_width = 0;
	_height = 0;
	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
  	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
  	loadTGA(imagepath.c_str(), filter);

	const GLfloat g_vertex_buffer_data[18] = {
    	0.5f * _width, -0.5f * _height, 0.0f,
   	   -0.5f * _width, -0.5f * _height, 0.0f,
   	   -0.5f * _width,  0.5f * _height, 0.0f,

       -0.5f * _width,  0.5f * _height, 0.0f,
     	0.5f * _width,  0.5f * _height, 0.0f,
     	0.5f * _width, -0.5f * _height, 0.0f
	};

	// Two UV coordinates for each vertex.
	const GLfloat g_uv_buffer_data[12] = {
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

void Sprite::loadTGA(const std::string& imagepath, int filter)
{
	FILE *file;
	unsigned char type[4];
	unsigned char info[6];

	file = fopen(imagepath.c_str(), "rb");

	if (!file) {
		std::cout << "error: unable to open file: " << imagepath << std::endl;
		return;
	}

	size_t s;
	s = fread (&type, sizeof (char), 3, file);
	fseek (file, 12, SEEK_SET);
	s = fread (&info, sizeof (char), 6, file);

	//image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		std::cout << "error: image type neither color or grayscale" << std::endl;
		fclose(file);
		return;
	}

    unsigned int imagesize;
    unsigned char* data;
    unsigned char bitdepth;

	this->_width = info[0] + info[1] * 256;
	this->_height = info[2] + info[3] * 256;
	bitdepth = info[4] / 8;

	std::cout << "~imagepath:" << imagepath << " width:" << this->_width << " height:" << this->_height << '\n';

	if (bitdepth != 1 && bitdepth != 3 && bitdepth != 4) {
		std::cout << "bytecount not 1, 3 or 4" << std::endl;
		fclose(file);
		return;
	}

  // Check if the image's width and height is a power of 2. No biggie, we can handle it.
	if ((this->_width & (this->_width - 1)) != 0) {
		std::cout << "warning: " << imagepath << "’s width is not a power of 2" << std::endl;
	}
	if ((this->_height & (this->_height - 1)) != 0) {
		std::cout << "warning: " << imagepath << "’s height is not a power of 2" << std::endl;
	}
	if (_width != _height) {
		std::cout << "warning: " << imagepath << " is not square" << std::endl;
	}

	imagesize = this->_width * this->_height * bitdepth;

    // Create a buffer
    data = new unsigned char [imagesize];

    // Read the actual data from the file into the buffer
    fread(data,1,imagesize,file);

    // Everything is in memory now, the file wan be closed
    fclose (file);

    // Create one OpenGL texture
    // Be sure to also delete it from where you called this with glDeleteTextures()
    GLuint textureID;

    glGenTextures(1, &textureID);


    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // filter the Texture
    switch (filter) {
        case 0:
            // No filtering.
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            break;
        case 1:
            // Linear filtering.
    		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            break;
        case 2:
            // Bilinear filtering.
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            glGenerateMipmap(GL_TEXTURE_2D);
            break;
        case 3:
            // Trilinear filtering.
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glGenerateMipmap(GL_TEXTURE_2D);
            break;
        default:
            // No filtering.
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            break;
    }

    // wrapping
    // GL_REPEAT, GL_MIRRORED_REPEAT or GL_CLAMP_TO_EDGE
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // handle transparency and grayscale and give the image to OpenGL
    switch (bitdepth) {
        case 4:
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_width, this->_height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
            break;
        case 3:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->_width, this->_height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
            break;
        case 1:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, this->_width, this->_height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
            break;
        default:
            std::cout << "error: bitdepth not 4, 3, or 1" << std::endl;
            break;
    }

    // OpenGL has now copied the data. Free our own version
    delete [] data;

    // Return the ID of the texture we just created
    this->texture = textureID;
}

Sprite::~Sprite(){
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteBuffers(1, &uvbuffer);
  glDeleteTextures(1, &texture); // attention: texture created in loadTGA() with glGenTextures()
}
