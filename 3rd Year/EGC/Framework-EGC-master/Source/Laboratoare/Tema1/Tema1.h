#pragma once

#include <Component/SimpleScene.h>
#include <Core/Engine.h>
#include <Core/GPU/Mesh.h>
#include <iostream>
#include <vector>
#include <math.h>

class Tema1 : public SimpleScene
{
	public:
		Tema1();
		~Tema1();

		void Init() override;

	private:
		//Mesh* CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;
		void SpawnBalloons();
		void SpawnShurikens();
		void CheckCollisions(float deltaTimeSeconds);

	protected:
		int triangles;
		glm::mat3 handleMatrix;
		glm::mat3 ropeMatrix;
		glm::mat3 bodyMatrix;
		glm::mat3 tipMatrix;
		glm::mat3 zigzagMatrix;
		glm::mat3 circleMatrix;
		glm::mat3 shurikenMatrix;
		glm::mat3 powerBarMatrix;
		double handleX, handleY, ropeX, ropeY, bodyX, bodyY, tipX, tipY;
		double handle_sizeX, handle_sizeY, rope_sizeX, rope_sizeY, body_sizeX, body_sizeY, tip_sizeX, tip_sizeY;
		double initial_bodyX, initial_bodyY, initial_tipX, initial_tipY;
		double arrow_speed, initial_arrow_speed, max_arrow_speed;
		bool shoot_arrow;
		double initial_shurikenX, initial_shurikenY, shurikenX, shurikenY;
		double shuriken_sizeX, shuriken_sizeY;
		double thread_sizeX, thread_sizeY;
		double shuriken_rotation;
		double shuriken_speed;
		double balloon_speed;
		double power_barX, power_barY;
		double power_bar_sizeX, power_bar_sizeY, full_power_bar_sizeX, full_power_bar_sizeY;
		double balloonX, balloonY, initial_balloonX, initial_balloonY, balloon_sizeX, balloon_sizeY;
		std::vector<glm::mat3> balloons, threads;
		std::vector<double> shurikens_posX, shurikens_posY, shurikens_speed;
		std::vector<double> balloons_posX, balloons_posY, balloons_speed, balloons_sizeX, balloons_sizeY;
		std::vector<char> balloons_color;
		std::vector<bool> balloons_hit, shurikens_hit;
		int fall_speed;
		double thread_distance;
		double time;
		int nr_balloons;
		int nr_shurikens;
		int max_ballons;
		int max_shurikens;
		int max_balloons;
		int min_shuriken_speed;
		int min_balloon_speed;
		int left_limit;
		int bow_speed;
		int screen_limit;
		int score;
		int nr_lives;
		double cat1, cat2, ip;
		double mouse_posX, mouse_posY;
		double bow_angle, bow_centerY, arrow_angle, shooting_centerY, shooting_tipY, shooting_bodyY, arrow_initY;
		double flyingTime;

		GLenum cullFace;
		GLenum polygonMode;
};
