#pragma once
#include "Module.h"
#include "Globals.h"

#include <gl/glew.h>
#pragma comment (lib, "GLFW/lib-vc2017/glfw3.lib")

class ModuleRenderExercise : public Module
{
public:

	ModuleRenderExercise();
	~ModuleRenderExercise();

	bool Init();
	update_status Update();
	bool CleanUp();

	float* buffer_data = nullptr;
	GLuint vbo;

};