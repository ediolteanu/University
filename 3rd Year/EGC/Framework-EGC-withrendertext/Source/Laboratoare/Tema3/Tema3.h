#pragma once

#include <Component/SimpleScene.h>
#include <Component/Transform/Transform.h>
#include <Core/GPU/Mesh.h>
#include <Core/Engine.h>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include "LabCamera.h"
#include <TextRenderer/TextRenderer.h>

class Tema3 : public SimpleScene
{
	public:
		Tema3();
		~Tema3();

		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, const glm::vec3 &color = glm::vec3(1), Texture2D *texture = NULL);
		void RenderUIMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, const glm::vec3 &color = glm::vec3(1));

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

		void CreatePlatforms();
		void SpawnNextWave();
		void SpawnInitial();
		void MovePlatforms(float deltaTimeSeconds);
		void RemovePlatforms();
		void CheckCollisions();

	protected:
		Laborator::Camera *camera, *cameraUI;
		GLfloat fov;
		GLfloat right, left, bottom, top;
		GLfloat zNear = 0.1f, zFar = 50.f;
		glm::mat4 projectionMatrix;

		glm::vec3 initialPlayerPosition;
		glm::vec3 playerPosition;
		glm::vec3 playerColor;
		std::vector<glm::vec3> initialPlatformsPositions;
		std::vector<glm::vec3> initialPlatformsColors;
		int nrInitPlatforms;

		std::vector<glm::vec3> platformsPositions;
		std::vector<glm::vec3> platformsColors;
		glm::vec3 blue, green, amethist, red, yellow, orange, black, white;
		int nrPlatforms;

		std::vector<glm::vec3> decorations;
		std::vector<glm::vec3> obstacles;
		std::vector<Texture2D*> obst_text;
		std::vector<glm::vec3> colectibles;
		std::vector<int> colectibles_sign;

		std::unordered_map<std::string, Texture2D*> textures;

		int initialRows;
		float minSpeed;
		float maxSpeed;
		float currentSpeed;
		float time;
		bool startGame;
		bool initGame;
		float maxFuel;
		float currentFuel;
		float percentFuel;
		bool isDead;
		bool orangePowerUp;
		float orangeTimestamp;
		float orangeTime;
		float orangeSpeed;
		float previousSpeed;
		bool isJumping;
		float jumpTimestamp;
		float jumpTime;
		float isOutOfFuel;
		bool isFirstPerson;
		int shouldTransform;
		bool shouldFall;
		bool disappear;
		int apply_texture;
		int score;
		
		TextRenderer  *Text;
		std::vector<glm::vec3> lightPositions;
		glm::vec3 lightDirection;
		unsigned int materialShininess;
		float materialKd;
		float materialKs;
		int spotlight;
		float cutoffAngle;
};