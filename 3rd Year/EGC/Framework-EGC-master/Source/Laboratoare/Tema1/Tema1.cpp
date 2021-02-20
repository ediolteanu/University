#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{

}

// Translate matrix
inline glm::mat3 Translate(float translateX, float translateY)
{
	// TODO implement translate matrix
	return glm::transpose(glm::mat3(1, 0, translateX,
		0, 1, translateY,
		0, 0, 1));
}

// Scale matrix
inline glm::mat3 Scale(float scaleX, float scaleY)
{
	// TODO implement scale matrix
	return glm::transpose(glm::mat3(scaleX, 0, 0,
		0, scaleY, 0,
		0, 0, 1));
}

// Rotate matrix
inline glm::mat3 Rotate(float radians)
{
	// TODO implement rotate matrix
	return glm::transpose(glm::mat3(cos(radians), -sin(radians), 0,
		sin(radians), cos(radians), 0,
		0, 0, 1));
}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	bow_angle = 0;
	bow_centerY = 0;
	triangles = 1000;
	bow_speed = 400;
	screen_limit = 30;
	handleX = 100;
	handleY = 275;
	handle_sizeX = 50;
	handle_sizeY = 75;
	ropeX = 100;
	ropeY = 200;
	rope_sizeX = 1;
	rope_sizeY = 150;
	body_sizeX = 75;
	body_sizeY = 4;
	initial_bodyX = ropeX;
	initial_bodyY = ropeY + rope_sizeY / 2 - body_sizeY / 2;
	bodyX = initial_bodyX;
	bodyY = initial_bodyY;
	tip_sizeX = 15;
	tip_sizeY = 15;
	initial_tipX = bodyX + body_sizeX;
	initial_tipY = bodyY + body_sizeY / 2 - tip_sizeY / 2;
	tipX = initial_tipX;
	tipY = initial_tipY;
	initial_shurikenX = resolution.x;
	initial_shurikenY = 0;
	shurikenX = initial_shurikenX;
	shurikenY = initial_shurikenY;
	shuriken_sizeX = 20;
	shuriken_sizeY = 20;
	shuriken_rotation = 1000;
	fall_speed = 500;
	min_shuriken_speed = 200;
	nr_shurikens = 0;
	max_shurikens = 5;

	balloon_sizeX = 25;
	balloon_sizeY = 35;

	nr_balloons = 0;
	max_balloons = 20;
	initial_balloonY = -500;
	initial_balloonX = 0;
	balloonX = initial_balloonX;
	balloonY = initial_balloonY;
	min_balloon_speed = 100;
	left_limit = 300;
	thread_distance = 35;
	thread_sizeX = 15;
	thread_sizeY = 15;
	initial_arrow_speed = 700;
	arrow_speed = initial_arrow_speed;
	max_arrow_speed = 1700;
	mouse_posX = 0;
	mouse_posY = 0;
	shoot_arrow = false;

	power_barX = 20;
	power_barY = 10;
	full_power_bar_sizeX = 100;
	full_power_bar_sizeY = 10;
	power_bar_sizeX = 0;
	power_bar_sizeY = 10;

	score = 0;
	nr_lives = 3;
	time = 0;
	flyingTime = 0;

	//bow
	{
		//rope
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(1, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(1, 1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0, 0, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,
			0, 2, 3,
		};

		Mesh *line = new Mesh("line");
		line->InitFromData(vertices, indices);
		line->SetDrawMode(GL_TRIANGLES);
		AddMeshToList(line);

		vertices.clear();
		indices.clear();

		//handle
		vertices.emplace_back(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		for (int i = 0; i <= triangles / 2 + 1; i++) {
			double radians = 2 * M_PI * i / triangles - M_PI / 2;
			vertices.emplace_back(glm::vec3(cos(radians), sin(radians), 0), glm::vec3(0, 0, 0));
			indices.push_back(i);
		}
		indices.push_back(triangles);
		indices.push_back(0);

		Mesh *curved_line = new Mesh("curved_line");
		curved_line->InitFromData(vertices, indices);
		glEnable(GL_LINE_SMOOTH);
		curved_line->SetDrawMode(GL_LINE_LOOP);
		AddMeshToList(curved_line);
	}

	//arrow
	{
		//body is drawn using same line as the bow handle
		//tip
		vector<VertexFormat> vertices = 
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(1, 0.5f, 0), glm::vec3(0, 0, 0)),
			
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,
		};

		Mesh *line = new Mesh("triangle");
		line->InitFromData(vertices, indices);
		line->SetDrawMode(GL_TRIANGLES);
		AddMeshToList(line);
	}

	//ballon
	{
		//red circle
		vector<VertexFormat> vertices;
		vector<unsigned short> indices;

		vertices.emplace_back(glm::vec3(0, 0, 0), glm::vec3(1, 0, 0));
		for (int i = 0; i < triangles; i++) {
			double radians = 2 * M_PI * i / triangles;
			vertices.emplace_back(glm::vec3(cos(radians), sin(radians), 0), glm::vec3(1, 0, 0));
			indices.push_back(i);
		}

		indices.push_back(triangles);
		indices.push_back(1);


		Mesh *circleR = new Mesh("circleR");
		circleR->InitFromData(vertices, indices);
		circleR->SetDrawMode(GL_TRIANGLE_FAN);
		AddMeshToList(circleR);

		vertices.clear();
		indices.clear();

		//yellow circle
		vertices.emplace_back(glm::vec3(0, 0, 0), glm::vec3(1, 1, 0));
		for (int i = 0; i < triangles; i++) {
			double radians = 2 * M_PI * i / triangles;
			vertices.emplace_back(glm::vec3(cos(radians), sin(radians), 0), glm::vec3(1, 1, 0));
			indices.push_back(i);
		}

		indices.push_back(triangles);
		indices.push_back(1);

		Mesh *circleY = new Mesh("circleY");
		circleY->InitFromData(vertices, indices);
		circleY->SetDrawMode(GL_TRIANGLE_FAN);
		AddMeshToList(circleY);

		//thread
		vertices.clear();
		indices.clear();

		vertices =
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(-0.5f, -0.5f, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0.5f, -1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(-0.5f, -1.5f, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0.5f, -2, 0), glm::vec3(0, 0, 0))
		};

		indices =
		{
			0, 1,
			1, 2,
			2, 3,
			3, 4
		};

		Mesh *zigzag = new Mesh("zigzag");
		zigzag->InitFromData(vertices, indices);
		zigzag->SetDrawMode(GL_LINES);
		AddMeshToList(zigzag);
	}

	//shuriken
	{
		vector<VertexFormat> vertices =
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(-1, 1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(-1, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(-1, -1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0, -1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(1, -1, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(1, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(1, 1, 0), glm::vec3(0, 0, 0)),

		};

		vector<unsigned short> indices =
		{
			0, 1, 2,
			0, 3, 4,
			0, 5, 6,
			0, 7, 8
		};


		Mesh *shuriken = new Mesh("shuriken");
		shuriken->InitFromData(vertices, indices);
		shuriken->SetDrawMode(GL_TRIANGLES);
		AddMeshToList(shuriken);
	}

	//full power bar
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 0.4f, 0.2f)),
			VertexFormat(glm::vec3(1, 0, 0), glm::vec3(0, 0.4f, 0.2f)),
			VertexFormat(glm::vec3(1, 1, 0), glm::vec3(0, 0.4f, 0.2f)),
			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0, 0.4f, 0.2f)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,
			0, 2, 3,
		};

		Mesh *full_power_bar = new Mesh("full_power_bar");
		full_power_bar->InitFromData(vertices, indices);
		full_power_bar->SetDrawMode(GL_TRIANGLES);
		AddMeshToList(full_power_bar);
	}

	//power bar
	vector<VertexFormat> vertices
	{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(1, 1, 0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)),
	};

	vector<unsigned short> indices =
	{
		0, 1, 2,
		0, 2, 3,
	};

	Mesh *power_bar = new Mesh("power_bar");
	power_bar->InitFromData(vertices, indices);
	power_bar->SetDrawMode(GL_TRIANGLES);
	AddMeshToList(power_bar);

	cout << "Score: " << score << endl;
	cout << "Lives: " << nr_lives << endl;
}

void Tema1::SpawnBalloons() {
	glm::ivec2 resolution = window->GetResolution();
	balloonX = initial_balloonX;
	balloonY = initial_balloonY;
	
	int red = rand() % 6;
	if (red == 0) {
		balloons_color.push_back('y');
	}
	else {
		balloons_color.push_back('r');
	}
	
	balloons_hit.push_back(false);
	balloonX = left_limit + rand() % (resolution.x - left_limit);
	balloons_posX.push_back(balloonX);
	balloons_posY.push_back(balloonY);
	balloons_sizeX.push_back(balloon_sizeX);
	balloons_sizeY.push_back(balloon_sizeY);
	balloon_speed = min_balloon_speed + rand() % 200;
	balloons_speed.push_back(balloon_speed);

	nr_balloons++;

}

void Tema1::SpawnShurikens() {
	glm::ivec2 resolution = window->GetResolution();
	shurikenX = initial_shurikenX;
	shurikenY = initial_shurikenY;
	shurikenY = rand() % resolution.y;
	shurikens_posX.push_back(shurikenX);
	shurikens_posY.push_back(shurikenY);
	shurikens_hit.push_back(false);
	shuriken_speed = min_shuriken_speed + rand() % 300;
	shurikens_speed.push_back(shuriken_speed);

	nr_shurikens++;
}

void Tema1::CheckCollisions(float flyingTime) {
	glm::ivec2 resolution = window->GetResolution();

	double arrow_tipX = ropeX + (body_sizeX + tip_sizeX + flyingTime * arrow_speed) * cos(arrow_angle);
	double arrow_tipY = shooting_centerY + body_sizeY / 2 + (body_sizeX + tip_sizeX + flyingTime * arrow_speed) * sin(arrow_angle);
	double dy, dx, distance;

	//coliziuni sageata-balon
	for (int i = 0; i < nr_balloons; i++) {
		if ((balloons_posY[i] > 0) && (balloons_hit[i] == false)) {
			dx = balloons_posX[i] - arrow_tipX;
			dy = balloons_posY[i] - arrow_tipY;
			distance = sqrt(dx * dx + dy * dy);
			if (distance <  balloon_sizeY) {
				//collision
				if (balloons_color[i] == 'r') {
					score += 10;
					cout << "Score: " << score << endl;
				}
				else {
					score -= 20;
					cout << "Score: " << score << endl;
				}
				balloons_hit[i] = true;
			}
		}
	}

	//coliziuni sageata-shuriken
	for (int i = 0; i < nr_shurikens; i++) {
		if ((shurikens_posX[i] < resolution.x) && (shurikens_hit[i] == false)) {
			dx = shurikens_posX[i] - arrow_tipX;
			dy = shurikens_posY[i] - arrow_tipY;
			distance = sqrt(dx * dx + dy * dy);
			if (distance < shuriken_sizeX * sqrt(2)) {
				//collision
				score += 25;
				cout << "Score: " << score << endl;
				shurikens_hit[i] = true;
			}
		}
	}

	//coliziuni shuriken-arc
	for (int i = 0; i < nr_shurikens; i++) {
		if ((shurikens_posX[i] < resolution.x) && (shurikens_posX[i] > handleX - shuriken_sizeX) && (shurikens_hit[i] == false)) {
			dx = shurikens_posX[i] - handleX;
			dy = shurikens_posY[i] - handleY;
			distance = sqrt(dx * dx + dy * dy);
			if (distance < (shuriken_sizeX * sqrt(2) + (handle_sizeY + handle_sizeX) / 2)) {
				shurikens_hit[i] = true;
				nr_lives--;
				cout << "Lives: " << nr_lives << endl;
				if (nr_lives == 0) {
					cout << "\nEND GAME!" << endl;
					cout << "Final Score: " << score << endl;
					window->Close();
				}
			}
		}
	}
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	
}

void Tema1::Update(float deltaTimeSeconds)
{
	glLineWidth(3);
	glPointSize(5);
	glm::ivec2 resolution = window->GetResolution();

	bow_centerY = ropeY + rope_sizeY / 2;
	if (!shoot_arrow) {
		arrow_initY = bow_centerY;
	}
	
	cat1 = mouse_posX - ropeX;
	cat2 = mouse_posY - bow_centerY;
	ip = sqrt(cat1 * cat1 + cat2 * cat2);
	
	bow_angle = asin(cat2 / ip);

	//bow
	ropeMatrix = glm::mat3(1);
	ropeMatrix *= Translate(ropeX, ropeY);
	ropeMatrix *= Translate(rope_sizeX / 2, rope_sizeY / 2);
	ropeMatrix *= Rotate(bow_angle);
	ropeMatrix *= Translate(-rope_sizeX / 2, -rope_sizeY / 2);
	ropeMatrix *= Scale(rope_sizeX, rope_sizeY);
	RenderMesh2D(meshes["line"], shaders["VertexColor"], ropeMatrix);

	handleMatrix = glm::mat3(1);
	handleMatrix *= Translate(handleX, handleY);
	handleMatrix *= Rotate(bow_angle);
	handleMatrix *= Scale(handle_sizeX, handle_sizeY);
	RenderMesh2D(meshes["curved_line"], shaders["VertexColor"], handleMatrix);

	//initial arrow spawn
	bodyMatrix = glm::mat3(1);
	
	bodyMatrix *= Translate(ropeX, arrow_initY);
	if (shoot_arrow) {
		bodyMatrix *= Rotate(arrow_angle);
		bodyMatrix *= Translate(-ropeX, -arrow_initY);
		bodyMatrix *= Translate(bodyX, shooting_bodyY);
		bodyMatrix *= Scale(body_sizeX, body_sizeY);
	}
	else {
		bodyMatrix *= Rotate(bow_angle);
		bodyMatrix *= Translate(-ropeX, -arrow_initY);
		bodyMatrix *= Translate(bodyX, bodyY);
		bodyMatrix *= Scale(body_sizeX, body_sizeY);
	}
	
	RenderMesh2D(meshes["line"], shaders["VertexColor"], bodyMatrix);

	tipMatrix = glm::mat3(1);
	
	tipMatrix *= Translate(ropeX, arrow_initY);
	if (shoot_arrow) {
		tipMatrix *= Rotate(arrow_angle);
		tipMatrix *= Translate(-ropeX, -arrow_initY);
		tipMatrix *= Translate(tipX, shooting_tipY);
		tipMatrix *= Scale(tip_sizeX, tip_sizeY);
	}
	else {
		tipMatrix *= Rotate(bow_angle);
		tipMatrix *= Translate(-ropeX, -arrow_initY);
		tipMatrix *= Translate(tipX, tipY);
		tipMatrix *= Scale(tip_sizeX, tip_sizeY);
	}
	

	RenderMesh2D(meshes["triangle"], shaders["VertexColor"], tipMatrix);

	//next arrow spawn
	if ((bodyX > resolution.x || bodyY > resolution.y || bodyY < 0) && (shoot_arrow)) {
		bodyX = initial_bodyX;
		bodyY = ropeY + rope_sizeY / 2 - body_sizeY / 2;
		tipX = initial_tipX;
		tipY = bodyY + body_sizeY / 2 - tip_sizeY / 2;
		shoot_arrow = false;
		power_bar_sizeX = 0;
		arrow_speed = initial_arrow_speed;
		flyingTime = 0;
		bodyMatrix = glm::mat3(1);
		bodyMatrix *= Translate(bodyX, bodyY);
		bodyMatrix *= Scale(body_sizeX, body_sizeY);
		RenderMesh2D(meshes["line"], shaders["VertexColor"], bodyMatrix);

		tipMatrix = glm::mat3(1);
		tipMatrix *= Translate(tipX, tipY);
		tipMatrix *= Scale(tip_sizeX, tip_sizeY);
		RenderMesh2D(meshes["triangle"], shaders["VertexColor"], tipMatrix);
		
	}

	time += deltaTimeSeconds;
	
	//balloons
	if (nr_balloons < max_balloons) {
		SpawnBalloons();
	}

	for (int i = 0; i < nr_balloons; i++) {
		if (balloons_hit[i] == false) {
			circleMatrix = glm::mat3(1);
			balloons_posY[i] += balloons_speed[i] * deltaTimeSeconds;
			circleMatrix *= Translate(balloons_posX[i], balloons_posY[i]);
			circleMatrix *= Scale(balloon_sizeX, balloon_sizeY);

			if (balloons_color[i] == 'r') {
				RenderMesh2D(meshes["circleR"], shaders["VertexColor"], circleMatrix);
			}
			else {
				RenderMesh2D(meshes["circleY"], shaders["VertexColor"], circleMatrix);
			}
		
			zigzagMatrix = glm::mat3(1);
			zigzagMatrix *= Translate(balloons_posX[i], balloons_posY[i] - thread_distance);
			zigzagMatrix *= Scale(thread_sizeX, thread_sizeY);
			RenderMesh2D(meshes["zigzag"], shaders["VertexColor"], zigzagMatrix);
		}
		else { //resolve hit balloon
			circleMatrix = glm::mat3(1);
			balloons_posY[i] -= fall_speed * deltaTimeSeconds;
			balloons_sizeX[i] -= balloon_sizeX * 5 * deltaTimeSeconds;
			balloons_sizeY[i] -= balloon_sizeY * 5 * deltaTimeSeconds;
			if (balloons_sizeX[i] < 0) {
				balloons_sizeX[i] = 0;
				balloons_sizeY[i] = 0;
			}
			circleMatrix *= Translate(balloons_posX[i], balloons_posY[i]);
			circleMatrix *= Scale(balloons_sizeX[i], balloons_sizeY[i]);

			if (balloons_color[i] == 'r') {
				RenderMesh2D(meshes["circleR"], shaders["VertexColor"], circleMatrix);
			}
			else {
				RenderMesh2D(meshes["circleY"], shaders["VertexColor"], circleMatrix);
			}

			zigzagMatrix = glm::mat3(1);
			zigzagMatrix *= Translate(balloons_posX[i], balloons_posY[i] - thread_distance);
			zigzagMatrix *= Scale(thread_sizeX, thread_sizeY);
			RenderMesh2D(meshes["zigzag"], shaders["VertexColor"], zigzagMatrix);
		}

		//eliminate balloon information
		if ((balloons_posY[i] > resolution.y + 100) || ((balloons_sizeX[i] == 0) && (balloons_posY[i] < 0))) {
			balloons_posX.erase(balloons_posX.begin() + i);
			balloons_posY.erase(balloons_posY.begin() + i);
			balloons_speed.erase(balloons_speed.begin() + i);
			balloons_color.erase(balloons_color.begin() + i);
			balloons_sizeX.erase(balloons_sizeX.begin() + i);
			balloons_sizeY.erase(balloons_sizeY.begin() + i);
			balloons_hit.erase(balloons_hit.begin() + i);
			nr_balloons--;
		}
	}

	
	//shuriken
	if (nr_shurikens < max_shurikens) {
			SpawnShurikens();
	}
	
	if (time > 10) {
		for (int i = 0; i < nr_shurikens; i++) {
			if (!shurikens_hit[i]) {
				shurikenMatrix = glm::mat3(1);
				shurikens_posX[i] -= shurikens_speed[i] * deltaTimeSeconds;
				shurikenMatrix *= Translate(shurikens_posX[i], shurikens_posY[i]);
				shurikenMatrix *= Scale(shuriken_sizeX, shuriken_sizeY);
				shurikenMatrix *= Rotate(RADIANS(shuriken_rotation * time));
				RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], shurikenMatrix);
			}
			else { //resolve hit shuriken
				shurikenMatrix = glm::mat3(1);
				shurikens_posY[i] -= fall_speed * deltaTimeSeconds;
				shurikenMatrix *= Translate(shurikens_posX[i], shurikens_posY[i]);
				shurikenMatrix *= Scale(shuriken_sizeX, shuriken_sizeY);
				shurikenMatrix *= Rotate(RADIANS(shuriken_rotation * time));
				RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], shurikenMatrix);
			}
			
			//eliminate shuriken information
			if (shurikens_posX[i] < 0 || shurikens_posY[i] < 0) {
				shurikens_posX.erase(shurikens_posX.begin() + i);
				shurikens_posY.erase(shurikens_posY.begin() + i);
				shurikens_speed.erase(shurikens_speed.begin() + i);
				shurikens_hit.erase(shurikens_hit.begin() + i);
				nr_shurikens--;
			}
		}
	}
	
	//power bar
	powerBarMatrix = glm::mat3(1);
	powerBarMatrix *= Translate(power_barX, power_barY);
	powerBarMatrix *= Scale(power_bar_sizeX, power_bar_sizeY);
	RenderMesh2D(meshes["power_bar"], shaders["VertexColor"], powerBarMatrix);

	//full power bar
	powerBarMatrix = glm::mat3(1);
	powerBarMatrix *= Translate(power_barX, power_barY);
	powerBarMatrix *= Scale(full_power_bar_sizeX, full_power_bar_sizeY);
	RenderMesh2D(meshes["full_power_bar"], shaders["VertexColor"], powerBarMatrix);

	if (shoot_arrow) {
		bodyX += deltaTimeSeconds * arrow_speed;
		tipX += deltaTimeSeconds * arrow_speed;
		flyingTime += deltaTimeSeconds;
	}

	CheckCollisions(flyingTime);
}

void Tema1::FrameEnd()
{
	
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	glm::ivec2 resolution = window->GetResolution();
	if (window->KeyHold(GLFW_KEY_W)) {
		if (resolution.y > ropeY + rope_sizeY + screen_limit) {
			handleY += deltaTime * bow_speed;
			ropeY += deltaTime * bow_speed;
			if (!shoot_arrow) {
				bodyY += deltaTime * bow_speed;
				tipY += deltaTime * bow_speed;
			}
		}
	}

	if (window->KeyHold(GLFW_KEY_S)) {
		if (0 < ropeY - screen_limit) {
			handleY -= deltaTime * bow_speed;
			ropeY -= deltaTime * bow_speed;
			if (!shoot_arrow) {
				bodyY -= deltaTime * bow_speed;
				tipY -= deltaTime * bow_speed;
			}
		}
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_2) && (!shoot_arrow)) {
		if (arrow_speed < max_arrow_speed) {
			arrow_speed += deltaTime * 800;
			arrow_speed = min(max_arrow_speed, arrow_speed);
		}
		power_bar_sizeX = (arrow_speed - initial_arrow_speed) / (max_arrow_speed - initial_arrow_speed) * full_power_bar_sizeX;
		if (power_bar_sizeX > 100) {
			power_bar_sizeX = 100;
		}
	}
	
}

void Tema1::OnKeyPress(int key, int mods)
{
	
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	glm::ivec2 resolution = window->GetResolution();
	mouse_posX = max(ropeX, (double)mouseX);
	mouse_posY = resolution.y - mouseY;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	if ((IS_BIT_SET(button, GLFW_MOUSE_BUTTON_2)) && (!shoot_arrow)) {
		arrow_speed = initial_arrow_speed;
		power_bar_sizeX = 0;
	}
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_2) && (!shoot_arrow)) {
		shoot_arrow = true;
		arrow_angle = bow_angle;
		shooting_centerY = bow_centerY;
		shooting_tipY = tipY;
		shooting_bodyY = bodyY;
	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
