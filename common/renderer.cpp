#include <common/renderer.h>

Renderer::Renderer(){
  window_width = SWIDTH;
  window_height = SHEIGHT;

  fullScreen = FULLSCREEN;

  fragment_shader	= SPRITEFRAGMENTSHADER;
  vertex_shader	= SPRITEVERTEXSHADER;

  programID = 0;
  matrixID = 0;
  vertexPosition_modelspaceID = 0;
  vertexUVID = 0;
  texture = 0;
  textureID = 0;

  this->initGL();
}

void Renderer::run(Scene* _scene, float deltaTime){
  scene = _scene;
  if (scene != NULL){
    int _width = 0;
    int _height = 0;
    glfwGetWindowSize	(window, &_width, &_height);

    if (window_width != _width || window_height != _height){
      window_width = _width;
      window_height = _height;
      setScreenSize(window_width,window_height,fullScreen);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Input::updateInput(window, scene->camera);
    scene->update(deltaTime);

    std::vector<Entity*> entities = scene->getEntities();

    int currenLayer = 0;
    bool needHigherLayer = true;

    while(needHigherLayer) {
      needHigherLayer = false;
      for (int i = 0; i < entities.size(); i++){
        if (entities[i]->getLayer() == currenLayer){
          entities[i]->update(deltaTime);
          glm::mat4 modelMatrix = glm::mat4(1.0f);
          renderEntity(modelMatrix,entities[i]);
        }
        if (entities[i]->getLayer() > currenLayer) {
          needHigherLayer = true;
        }
      }
      currenLayer++;
    }
    currenLayer = 0;
    needHigherLayer = true;

    swapBuffers();
  }
}

void Renderer::renderEntity(glm::mat4 modelMatrix, Entity* _entity){  // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
  // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
  scene->camera->computeMatricesFromInputs(window);

  // get from Camera (Camera position and direction)
  glm::mat4 viewMatrix = scene->camera->getViewMatrix();

  // get the modelMatrix
  modelMatrix *= getModelMatrix(_entity);
  // fill _worldpos in Entity
	glm::vec4 realpos = modelMatrix * glm::vec4(0,0,0,1);
	// send the real world position after these transforms back to Entity->worldpos
	_entity->setWorldPos(Vector2(realpos.x, realpos.y));

      if (_entity->getSprite() != NULL && testCulling(_entity)) {
          // create a MVP
          glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

          // Send our transformation to the currently bound shader,
          // in the "MVP" uniform
          glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

          // Bind our texture in Texture Unit 0
          glActiveTexture(GL_TEXTURE0);
          glBindTexture(GL_TEXTURE_2D, _entity->getSprite()->getTexture());
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
          // Set our "myTextureSampler" sampler to user Texture Unit 0
          glUniform1i(textureID, 0);

          // 1st attribute buffer : vertices
          glEnableVertexAttribArray(vertexPosition_modelspaceID);
          glBindBuffer(GL_ARRAY_BUFFER, _entity->getSprite()->getVertexbuffer());
          glVertexAttribPointer(
            vertexPosition_modelspaceID,  // The attribute we want to configure
            3,                            // size : x+y+z => 3
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
          );

          // 2nd attribute buffer : UVs
          glEnableVertexAttribArray(vertexUVID);
          glBindBuffer(GL_ARRAY_BUFFER, _entity->getSprite()->getUvbuffer());
          glVertexAttribPointer(
            vertexUVID,                   // The attribute we want to configure
            2,                            // size : U+V => 2
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
          );

          // Draw the triangles !
          glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

          glDisableVertexAttribArray(vertexPosition_modelspaceID);
          glDisableVertexAttribArray(vertexUVID);
      }

      // Render all Children (recursively)
    	std::vector<Entity*> children = _entity->getChildren();
	    std::vector<Entity*>::iterator child;
    	for (child = children.begin(); child != children.end(); child++) {
    		// Transform child's children...
    		this->renderEntity(modelMatrix, *child);
        }
}

glm::mat4 Renderer::getModelMatrix(Entity* _entity) {
  // Build the Model matrix
  glm::mat4 translationMatrix    = glm::translate(glm::mat4(1.0f), glm::vec3(_entity->position.x, _entity->position.y, 0.0f));
  glm::mat4 rotationMatrix       = glm::eulerAngleYXZ(0.0f, 0.0f, _entity->getRad());
  glm::mat4 scalingMatrix        = glm::scale(glm::mat4(1.0f), glm::vec3(_entity->scale.x, _entity->scale.y, 1.0f));

  // create modelMatrix
  glm::mat4 modelMat = translationMatrix * rotationMatrix * scalingMatrix;

  // return modelMatrix
  return modelMat;
}

void Renderer::setScreenSize(int _sWidth, int _sHeight, bool _wanted_fullSreen){ // set setScreenSize
  window_width  = _sWidth;
  window_height = _sHeight;
  fullScreen = _wanted_fullSreen;
  glfwSetWindowSize(window, window_width, window_height);
  #ifndef __APPLE__
		// Since apple does this automatically. This will cause some bugs where the viewport gets very small.

		// Set the glViewport to the width and height of the window.
		glViewport(0, 0, window_width, window_height);
	#endif
}

void Renderer::swapBuffers() {
  // Swap buffers at last
  glfwSwapBuffers(window);
}

bool Renderer::testCulling(Entity* _entity) {
	float tp = sqrt(_entity->getWidth() * _entity->getWidth() + _entity->getHeight() * _entity->getHeight());

	if (_entity->getWorldPosition().x + tp < -100 + scene->camera->getPosition().x + tp * DEBUG * 2 || _entity->getWorldPosition().x - tp >  100 + SWIDTH + scene->camera->getPosition().x - tp * DEBUG  * 2) {
		return false;
	}
	if (_entity->getWorldPosition().y + tp < -100 + scene->camera->getPosition().y + tp * DEBUG * 2 || _entity->getWorldPosition().y - tp > 100 + SHEIGHT + scene->camera->getPosition().y - tp * DEBUG  * 2) {
		return false;
	}
	return true;
}

int Renderer::initGL() {
  // Initialise GLFW
  if( !glfwInit() )
  {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  // Open a window and create its OpenGL context
  //window = glfwCreateWindow( window_width, window_height, "Demo", glfwGetPrimaryMonitor(), NULL);
  GLFWmonitor* primary = glfwGetPrimaryMonitor();
  if (fullScreen) {
    window = glfwCreateWindow( window_width, window_height, WINDOWNAME, primary, NULL);
  } else {
    window = glfwCreateWindow( window_width, window_height, WINDOWNAME, NULL, NULL);
  }
  if( window == NULL ){
    fprintf( stderr, "Failed to open GLFW window.\n" );
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // vsync (0=off, 1=on)
  glfwSwapInterval(VSYNC);

  // Initialize GLEW
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  #ifndef __APPLE__
		// Since apple does this automatically. This will cause some bugs where the viewport gets very small.
		// Set the glViewport to the width and height of the window.
		glViewport(0, 0, window_width, window_height);
	#endif

  // Cull triangles which normal is not towards the camera
  glEnable(GL_CULL_FACE);

  // Create and compile our GLSL program from the shaders
  // see: shader.h/cpp
  programID = loadShaders(vertex_shader.c_str(), fragment_shader.c_str());

  // Get a handle for our buffers
  vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
  vertexUVID = glGetAttribLocation(programID, "vertexUV");

  // Get a handle for our "MVP" uniform
  matrixID = glGetUniformLocation(programID, "MVP");
  // Get a handle for our "myTextureSampler" uniform
  textureID  = glGetUniformLocation(programID, "myTextureSampler");

  projectionMatrix = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, 0.1f, 100.0f);

  // Use our shader
  glUseProgram(programID);

  return 0;
} // init GL

bool Renderer::mustQuit(){
  return (glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS || glfwWindowShouldClose(window));
}// quit

Renderer::~Renderer(){
  // Cleanup VBO and shader
  glDeleteProgram(programID);
  glDeleteTextures(1, &textureID);
}
