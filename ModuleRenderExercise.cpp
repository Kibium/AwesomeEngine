#include "Globals.h"
#include "Application.h"
#include "ModuleRenderExercise.h"

ModuleRenderExercise::ModuleRenderExercise() {}
ModuleRenderExercise::~ModuleRenderExercise() {}

bool ModuleRenderExercise::Init() {

	static const GLfloat tri1 []= {-1.f, -1.f, 0.0f,
									-0.5f, -1.f, 0.0f,
									-0.75f, -0.50f, 0.0f };

	static const GLfloat tri2[] = { -0.5f, -1.f, 0.0f,
									0.f, -1.f, 0.0f,
									-0.25f, -0.5f, 0.0f };

	static const GLfloat tri3[] = { -1.f, -1.f, 0.0f,
									1.0f, -1.f, 0.0f,
									0.0f, 1.f, 0.0f };

	//Creates a new vbo
	glGenBuffers(2, &vbo); 

	//Setting buffer to be used
	glBindBuffer(GL_ARRAY_BUFFER, vbo); 

	//Assigns data to buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri1), tri1, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);



	

	return true;
}


update_status ModuleRenderExercise::Update() {
	
	//Set the format of the vertex's data.
	//We gonna tell opengl, what we wanna draw

	glEnableVertexAttribArray(0); // attribute 0            
	glBindBuffer(GL_ARRAY_BUFFER, vbo);            
	glVertexAttribPointer(0,                  // attribute 0                    
						  3,                  // number of componentes (3 floats)                    
						  GL_FLOAT,           // data type                    
						  GL_FALSE,           // should be normalized?                    
						  0,                  // stride                    
						  (void*)0);            // array buffer offset   

	glColor3f(204, 204, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3); // start at 0 and 3 tris            
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	
	return UPDATE_CONTINUE;
}

bool ModuleRenderExercise::CleanUp() {

	
	return true;
}
