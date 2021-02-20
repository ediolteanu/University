#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

const string objNames[] = { "box.obj", "teapot.obj", "sphere.obj" };
int cicle_index = 0;
float clcolor_red, clcolor_green, clcolor_blue, clcolor_alpha = 1, coordX = 4, coordY = 2, coordZ = 2;
// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;

		Mesh* mesh2 = new Mesh("sphere");
		mesh2->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh2->GetMeshID()] = mesh2;

		Mesh* loop_mesh = new Mesh("loop_obj");
		loop_mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[loop_mesh->GetMeshID()] = loop_mesh;
	}
}

void Laborator1::FrameStart()
{

}

void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	// sets the clear color for the color buffer
	glClearColor(clcolor_red, clcolor_green, clcolor_blue, clcolor_alpha);

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// render the object
	RenderMesh(meshes["box"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));

	// render the object again but with different properties
	RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));

	//ex2
	RenderMesh(meshes["sphere"], glm::vec3(-3, 0.5f, 0), glm::vec3(0.5f));

	//ex4+5
	RenderMesh(meshes["loop_obj"], glm::vec3(coordX, coordY, coordZ));
}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input
	if (window->KeyHold(GLFW_KEY_W)) { 
		coordX -= deltaTime; 
	}
	
	if (window->KeyHold(GLFW_KEY_A)) { 
		coordZ -= deltaTime; 
	}

	if (window->KeyHold(GLFW_KEY_S)) { 
		coordX += deltaTime;
	}

	if (window->KeyHold(GLFW_KEY_D)) { 
		coordZ += deltaTime; 
	}

	if (window->KeyHold(GLFW_KEY_E)) { 
		coordY += deltaTime; 
	}

	if (window->KeyHold(GLFW_KEY_Q)) { 
		coordY -= deltaTime; 
	}
};

void Laborator1::OnKeyPress(int key, int mods)
{
	// add key press event
	//ex3
	if (key == GLFW_KEY_F) {
		clcolor_red = (rand() % 255) / 255.f;
		clcolor_green = (rand() % 255) / 255.f;
		clcolor_blue = (rand() % 255) / 255.f;
		clcolor_alpha = (rand() % 255) / 255.f;
	}

	//ex4
	if (key == GLFW_KEY_C) {
		cicle_index = (cicle_index + 1) % 3;
		Mesh* next_mesh = new Mesh("loop_obj");
		next_mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", objNames[cicle_index]);
		meshes["loop_obj"]->ClearData();
		meshes[next_mesh->GetMeshID()] = next_mesh;

	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}
