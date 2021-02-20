#include "Tema3.h"

using namespace std;

Tema3::Tema3()
{
}

Tema3::~Tema3()
{
}

void Tema3::SpawnInitial() {
	if (initGame) {
		for (int i = 0; i < initialRows * 3; i++) {
			initialPlatformsPositions.push_back(glm::vec3(i % 3 - 1, 0.5f, -(int(i / 3) * 3)));
			initialPlatformsColors.push_back(black);
			nrInitPlatforms++;
		}
		for (int i = 0; i < initialRows; i++) {
			/*decorations.push_back(glm::vec3(2, 0.5f, -i * 3 - 1));
			decorations.push_back(glm::vec3(-2, 0.5f, -i * 3 - 1));*/
			decorations.push_back(glm::vec3(2, 0.5f, -i * 3));
			decorations.push_back(glm::vec3(-2, 0.5f, -i * 3));
			/*decorations.push_back(glm::vec3(2, 0.5f, -i * 3 + 1));
			decorations.push_back(glm::vec3(-2, 0.5f, -i * 3 + 1));*/
		}
	}
	initGame = false;
	
	for (int i = 0; i < nrInitPlatforms; i++) {
		glm::vec3 pos = initialPlatformsPositions.at(i);
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, pos);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.05f, 3));
		apply_texture = 1;
		RenderSimpleMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, initialPlatformsColors.at(i), textures["sand"]);
	}

	for (int i = 0; i < decorations.size(); i++) {
		glm::vec3 pos = decorations.at(i);
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, pos);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5, 0.5, 0.5));
		apply_texture = 1;
		RenderSimpleMesh(meshes["pyramid"], shaders["ShaderTema3"], modelMatrix, black, textures["pyramid"]);
	}
	
}

void Tema3::SpawnNextWave() {
	if (platformsPositions.empty()) {
		glm::vec3 last_platform = initialPlatformsPositions.back();
		platformsPositions.push_back(glm::vec3(0, 0.5f, last_platform.z - 3));
		platformsPositions.push_back(glm::vec3(1, 0.5f, last_platform.z - 3));
		platformsPositions.push_back(glm::vec3(-1, 0.5f, last_platform.z - 3));
		nrPlatforms += 3;
		platformsColors.push_back(black);
		platformsColors.push_back(black);
		platformsColors.push_back(black);

		decorations.push_back(glm::vec3(2, 0.5f, last_platform.z));
		decorations.push_back(glm::vec3(-2, 0.5f, last_platform.z));

	} else {
		glm::vec3 last_platform = platformsPositions.back();

		decorations.push_back(glm::vec3(2, 0.5f, last_platform.z));
		decorations.push_back(glm::vec3(-2, 0.5f, last_platform.z));

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 100);
		if (dis(gen) == 10) {
			colectibles.push_back(glm::vec3(0, 0.6f, last_platform.z));
			colectibles_sign.push_back(1);
		}
		if (last_platform.z > -(initialRows  - 1) * 3) {
			uniform_int_distribution<> dis1(0, 2);
			uniform_int_distribution<> dis2(0, 200);
			uniform_int_distribution<> dis3(0, 50);
			uniform_int_distribution<> dis4(0, 30);
			if (dis1(gen) != 0) {
				platformsPositions.push_back(glm::vec3(0, 0.5f, last_platform.z - 3));
				if (dis2(gen) == 0) {
					platformsColors.push_back(red); // rosu
				}
				else if (dis3(gen) == 0) {
					platformsColors.push_back(green); // verde
				}
				else if (dis3(gen) == 10) {
					platformsColors.push_back(yellow); // galben
				}
				else if (dis3(gen) == 20) {
					platformsColors.push_back(orange); // portocaliu
				}
				else {
					platformsColors.push_back(black); // albastru
				}
				if (dis4(gen) == 10) {
					int v = rand() % 3 + 3;
					if (v == 5) {
						obst_text.push_back(textures["sarcofag"]);
					}
					else {
						string zeu = "zeu" + std::to_string(v);
						obst_text.push_back(textures[zeu]);
					}
					obstacles.push_back(glm::vec3(0, 0.5f, last_platform.z - 3));
				}
				nrPlatforms++;
			}

			if (dis1(gen) != 1) {
				platformsPositions.push_back(glm::vec3(1, 0.5f, last_platform.z - 3));
				if (dis2(gen) == 0) {
					platformsColors.push_back(red);
				}
				else if (dis3(gen) == 0) {
					platformsColors.push_back(green);
				}
				else if (dis3(gen) == 10) {
					platformsColors.push_back(yellow);
				}
				else if (dis3(gen) == 20) {
					platformsColors.push_back(orange);
				}
				else {
					platformsColors.push_back(black);
				}

				if (dis4(gen) == 20) {
					int v = rand() % 3 + 3;
					if (v == 5) {
						obst_text.push_back(textures["sarcofag"]);
					}
					else {
						string zeu = "zeu" + std::to_string(v);
						obst_text.push_back(textures[zeu]);
					}
					obstacles.push_back(glm::vec3(1, 0.5f, last_platform.z - 3));
				}

				nrPlatforms++;
			}

			if (dis1(gen) != 2) {
				platformsPositions.push_back(glm::vec3(-1, 0.5f, last_platform.z - 3));
				if (dis2(gen) == 0) {
					platformsColors.push_back(red);
				}
				else if (dis3(gen) == 0) {
					platformsColors.push_back(green);
				}
				else if (dis3(gen) == 10) {
					platformsColors.push_back(yellow);
				}
				else if (dis3(gen) == 20) {
					platformsColors.push_back(orange);
				}
				else {
					platformsColors.push_back(black);
				}

				if (dis4(gen) == 30) {
					int v = rand() % 3 + 3;
					if (v == 5) {
						obst_text.push_back(textures["sarcofag"]);
					}
					else {
						string zeu = "zeu" + std::to_string(v);
						obst_text.push_back(textures[zeu]);
					}
					obstacles.push_back(glm::vec3(-1, 0.5f, last_platform.z - 3));
				}

				nrPlatforms++;
			}

		}
	}

}

void Tema3::CreatePlatforms() {
	SpawnNextWave();
}

void Tema3::MovePlatforms(float deltaTimeSeconds) {
	for (int i = 0; i < nrInitPlatforms; i++) {
		initialPlatformsPositions.at(i).z += currentSpeed * deltaTimeSeconds;
	}
	for (int i = 0; i < decorations.size(); i++) {
		decorations.at(i).z += currentSpeed * deltaTimeSeconds;
	}

	for (int i = 0; i < nrPlatforms; i++) {
		platformsPositions.at(i).z += currentSpeed * deltaTimeSeconds;
		glm::vec3 pos = platformsPositions.at(i);
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, pos);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.05f, 3));
		apply_texture = 1;
		RenderSimpleMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, platformsColors.at(i), textures["sand"]);
	}

	for (int i = 0; i < obstacles.size(); i++) {
		obstacles.at(i).z += currentSpeed * deltaTimeSeconds;
		glm::vec3 pos = obstacles.at(i);
		glm::mat4 modelMatrix = glm::mat4(1);
		
		if (obst_text.at(i) == textures["sarcofag"]) {
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.25f, 0));
			modelMatrix = glm::translate(modelMatrix, pos);
			modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.01f, 0.5f));
			apply_texture = 1;
			RenderSimpleMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, glm::vec3(0, 0, 0), obst_text.at(i));
		}
		else {
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1.f, 0));
			modelMatrix = glm::translate(modelMatrix, pos);
			modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.01f, 2));
			apply_texture = 1;
			RenderSimpleMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, black, obst_text.at(i));
		}
	}
	for (int i = 0; i < colectibles.size(); i++) {
		colectibles.at(i).z += currentSpeed * deltaTimeSeconds;
		if (colectibles.at(i).x > 1) {
			colectibles_sign.at(i) = -1;
		}
		if (colectibles.at(i).x < -1) {
			colectibles_sign.at(i) = 1;
		}
		colectibles.at(i).x += colectibles_sign.at(i) * deltaTimeSeconds;
		glm::mat4 modelMatrix = glm::mat4(1);
		glm::vec3 pos = colectibles.at(i);
		modelMatrix = glm::translate(modelMatrix, pos);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
		apply_texture = 0;
		RenderSimpleMesh(meshes["lamp"], shaders["ShaderTema3"], modelMatrix, yellow);
	}
}

void Tema3::RemovePlatforms() {
	for (int i = 0; i < nrInitPlatforms; i++) {
		if (initialPlatformsPositions.at(i).z > 10) {
			initialPlatformsPositions.erase(initialPlatformsPositions.begin() + i);
			initialPlatformsColors.erase(initialPlatformsColors.begin() + i);
			nrInitPlatforms--;
		}
	}

	for (int i = 0; i < nrPlatforms; i++) {
		if (platformsPositions.at(i).z > 4) {
			platformsPositions.erase(platformsPositions.begin() + i);
			platformsColors.erase(platformsColors.begin() + i);
			nrPlatforms--;
		}
	}

	for (int i = 0; i < decorations.size(); i++) {
		if (decorations.at(i).z > 4) {
			decorations.erase(decorations.begin() + i);
		}
	}

	for (int i = 0; i < obstacles.size(); i++) {
		if (obstacles.at(i).z > 4) {
			obstacles.erase(obstacles.begin() + i);
			obst_text.erase(obst_text.begin() + i);
		}
	}

	for (int i = 0; i < colectibles.size(); i++) {
		if (colectibles.at(i).z > 4) {
			colectibles.erase(colectibles.begin() + i);
			colectibles_sign.erase(colectibles_sign.begin() + i);
		}
	}

}

void Tema3::CheckCollisions() {
	bool collision = false;
	bool obst_collision = false;
	for (int i = 0; i < nrPlatforms; i++) {
		if (!isJumping) {
			if (((playerPosition.x < platformsPositions.at(i).x + 0.5f) && (playerPosition.x > platformsPositions.at(i).x - 0.5f)) &&
				((playerPosition.z < platformsPositions.at(i).z + 1.5f) && (playerPosition.z > platformsPositions.at(i).z - 1.5f))) {
				//coliziune
				collision = true;
				if (platformsColors.at(i) == red) {
					platformsPositions.erase(platformsPositions.begin() + i);
					platformsColors.erase(platformsColors.begin() + i);
					nrPlatforms--;
					isDead = true;
					shouldFall = true;
				}
				else if (platformsColors.at(i) == yellow) {
					currentFuel -= 0.2f;
				}
				else if (platformsColors.at(i) == green) {
					currentFuel = min(currentFuel + 0.2f, maxFuel);
					currentSpeed = max(minSpeed, currentSpeed);
				}
				else if (platformsColors.at(i) == orange) {
					orangePowerUp = true;
					shouldTransform = 1;
					previousSpeed = currentSpeed;
					orangeTimestamp = time;
				}
				platformsColors.at(i) = amethist;
			}
		} 
	}

	for (int i = 0; i < nrInitPlatforms; i++) {
		if (playerPosition.y == 0.72f) {
			if (((playerPosition.x < initialPlatformsPositions.at(i).x + 0.5f) && (playerPosition.x > initialPlatformsPositions.at(i).x - 0.5f)) &&
				((playerPosition.z < initialPlatformsPositions.at(i).z + 1.5f) && (playerPosition.z > initialPlatformsPositions.at(i).z - 1.5f))) {
				initialPlatformsColors.at(i) = amethist;
				collision = true;
			}
		}
	}

	for (int i = 0; i < obstacles.size(); i++) {
		if (obst_text.at(i) == textures["sarcofag"]) {
			if (((playerPosition.x < obstacles.at(i).x + 0.72f) && (playerPosition.x > obstacles.at(i).x - 0.72f)) &&
				((playerPosition.z < obstacles.at(i).z + 0.225f) && (playerPosition.z > obstacles.at(i).z - 0.225f)) &&
				((playerPosition.y < obstacles.at(i).y + 0.47f))) {
				obst_collision = true;
			}
		}
		else {
			if (((playerPosition.x < obstacles.at(i).x + 0.72f) && (playerPosition.x > obstacles.at(i).x - 0.72f)) &&
				((playerPosition.z < obstacles.at(i).z + 0.225f) && (playerPosition.z > obstacles.at(i).z - 0.225f))) {
				obst_collision = true;
			}
		}
	}

	for (int i = 0; i < colectibles.size(); i++) {
		if (((playerPosition.x < colectibles.at(i).x + 0.72f) && (playerPosition.x > colectibles.at(i).x - 0.72f)) &&
			((playerPosition.z < colectibles.at(i).z + 0.225f) && (playerPosition.z > colectibles.at(i).z - 0.225f)) &&
			((playerPosition.y < colectibles.at(i).y + 0.47f))) {
			score += 10;
			colectibles.erase(colectibles.begin() + i);
			colectibles_sign.erase(colectibles_sign.begin() + i);
			cout << score << endl;
		}
	}

	if (!isJumping && !collision) {
		isDead = true;
		shouldFall = true;
	}

	if (obst_collision) {
		isDead = true;
	}
}

void Tema3::Init()
{
	{
		Mesh* mesh = new Mesh("platform");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("lamp");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mesh->GetMeshID()] = mesh;

	}

	// Create pyramid
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, 0,  1), glm::vec3(1), glm::vec3(1), glm::vec2(0, 0)),
			VertexFormat(glm::vec3(1, 0,  1), glm::vec3(1), glm::vec3(1), glm::vec2(1, 0)),
			VertexFormat(glm::vec3(1,  0, -1), glm::vec3(1), glm::vec3(1), glm::vec2(0, 0)),
			VertexFormat(glm::vec3(-1,  0,  -1), glm::vec3(1), glm::vec3(1), glm::vec2(1, 0)),
			VertexFormat(glm::vec3(0, 2, 0), glm::vec3(1), glm::vec3(1), glm::vec2(0.5f, 1)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		0, 2, 3,
			0, 1, 4,		
			1, 4, 2,		
			2, 3, 4,		
			3, 0, 4,			
		};

		Mesh *pyramid = new Mesh("pyramid");
		pyramid->InitFromData(vertices, indices);
		pyramid->SetDrawMode(GL_TRIANGLES);
		AddMeshToList(pyramid);
		vertices.clear();
		indices.clear();
	}

	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader *shader = new Shader("ShaderTema3");
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	//textures
	const string textureLoc = "Source/Laboratoare/Tema3/Textures/";
	{
		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "pyramid_texture.jpg").c_str(), GL_REPEAT);
			textures["pyramid"] = texture;
		}

		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "sand_texture.jpg").c_str(), GL_REPEAT);
			textures["sand"] = texture;
		}

		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "faraon.png").c_str(), GL_REPEAT);
			textures["mask"] = texture;
		}

		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "zeu3.jpg").c_str(), GL_REPEAT);
			textures["zeu3"] = texture;
		}

		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "zeu4.jpg").c_str(), GL_REPEAT);
			textures["zeu4"] = texture;
		}

		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "sarcofag.jpg").c_str(), GL_REPEAT);
			textures["sarcofag"] = texture;
		}

		{
			Texture2D* texture = new Texture2D();
			texture->Load2D((textureLoc + "desert_fundal.jpg").c_str(), GL_REPEAT);
			textures["fundal"] = texture;
		}

	}

	//initialize variables
	{
		score = 0;
		time = 0;
		initialPlayerPosition = glm::vec3(0, 0.72f, 0);
		playerPosition = initialPlayerPosition;
		nrInitPlatforms = 0;
		nrPlatforms = 0;
		initialRows = 15;
		startGame = false;
		initGame = true;
		minSpeed = 5;
		maxSpeed = 15;
		orangeSpeed = 25;
		currentSpeed = minSpeed;
		maxFuel = 1;
		currentFuel = maxFuel;
		percentFuel = 0.001;
		blue = glm::vec3(0, 0, 1);
		yellow = glm::vec3(1, 1, 0);
		red = glm::vec3(1, 0, 0);
		amethist = glm::vec3(0.533f, 0.302f, 0.655f);
		green = glm::vec3(0, 1, 0.2f);
		orange = glm::vec3(1, 0.55f, 0);
		black = glm::vec3(0, 0, 0);
		white = glm::vec3(1, 1, 1);
		isDead = false;
		orangePowerUp = false;
		shouldTransform = 0;
		orangeTime = 5;
		isJumping = false;
		jumpTime = 0.7f;
		isOutOfFuel = false;
		disappear = false;
		
		//camera
		fov = 50.f;
		right = 4.f;
		left = -2.f;
		bottom = -3.f;
		top = 5.f;

		isFirstPerson = false;
		shouldFall = false;
	}

	camera = new Laborator::Camera();
	camera->Set(glm::vec3(0, 1.5f, 2.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
	cameraUI = new Laborator::Camera();
	cameraUI->Set(glm::vec3(0, 1.5f, 2.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

	projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
}

void Tema3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(.2f, .2f, .2f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);	
}

void Tema3::Update(float deltaTimeSeconds)
{
	// Render the player
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, playerPosition);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4f));
		if (!isFirstPerson && !disappear) {
			apply_texture = 1;
			RenderSimpleMesh(meshes["sphere"], shaders["ShaderTema3"], modelMatrix, black, textures["mask"]);
		}
	}

	//fundal
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, -50));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(160, 80, 0.05f));
		apply_texture = 1;
		RenderSimpleMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, black, textures["fundal"]);
	}
	
	// Render fuel
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(4, 1, -4));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5, 3.9, 0.1));
		apply_texture = 0;
		RenderUIMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, white);

		if (currentFuel > 0) {
			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(4, -0.5f, -3.9));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.5f, 0));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5, currentFuel * 4, 0.1));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.5f, 0));
			apply_texture = 0;
			RenderUIMesh(meshes["platform"], shaders["ShaderTema3"], modelMatrix, yellow);
		}
	}
	time += deltaTimeSeconds;

	if (isJumping) {
		if (time - jumpTimestamp < jumpTime / 2) {
			playerPosition.y += deltaTimeSeconds * 2;
			if (isFirstPerson) {
				camera->TranslateUpword(deltaTimeSeconds * 2);
			}
		}
		else if (time - jumpTimestamp >= jumpTime / 2) {
			if (time - jumpTimestamp > jumpTime) {
				isJumping = false;
				playerPosition.y = initialPlayerPosition.y;
			}
			else {
				playerPosition.y = max(playerPosition.y - deltaTimeSeconds * 2, initialPlayerPosition.y);
				if (isFirstPerson) {
					camera->TranslateUpword(-max(deltaTimeSeconds * 2, initialPlayerPosition.y - playerPosition.y));
				}
			}
		} 
	}

	if (orangePowerUp && !isDead) {
		if (time - orangeTimestamp < orangeTime) {
			currentSpeed = orangeSpeed;
		}
		else {
			orangePowerUp = false;
			shouldTransform = 0;
			currentSpeed = previousSpeed;
		}
	}

	SpawnInitial();
	if (startGame) {
		MovePlatforms(deltaTimeSeconds);
		CreatePlatforms();
		RemovePlatforms();
		CheckCollisions();
		if (!orangePowerUp && currentFuel > 0) {
			currentFuel -= percentFuel * currentSpeed * deltaTimeSeconds;
			currentFuel = max(currentFuel, 0.f);
		}

		if (currentFuel <= 0) {
			isOutOfFuel = true;
			if (currentSpeed > 0 && isOutOfFuel) {
				currentSpeed -= deltaTimeSeconds * 5;
			}
			if (currentSpeed <= 0) {
				isDead = true;
			}
		}
		else {
			isOutOfFuel = false;
		}

		if (isDead) {
			currentSpeed = 0;
		}

		if (shouldFall) {
			playerPosition.y -= deltaTimeSeconds * 5;
			if (playerPosition.y < -10) {
				disappear = true;
			}
		}
	}
	
}

void Tema3::FrameEnd()
{
	//DrawCoordinatSystem();
}

void Tema3::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, const glm::vec3 &color, Texture2D *texture)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;
	if (orangePowerUp) shouldTransform = 1;
	if (mesh != meshes["sphere"] || shouldTransform != 1) shouldTransform = 0;
	float r1 = Engine::GetElapsedTime() + 1;
	float r2 = Engine::GetElapsedTime() + 3;
	float r3 = Engine::GetElapsedTime() + 5;
	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	glUniform1i(glGetUniformLocation(shader->GetProgramID(), "shouldTransform"), shouldTransform);
	glUniform1f(glGetUniformLocation(shader->GetProgramID(), "r1"), r1);
	glUniform1f(glGetUniformLocation(shader->GetProgramID(), "r2"), r2);
	glUniform1f(glGetUniformLocation(shader->GetProgramID(), "r3"), r3);


	GLint objectColorLoc = glGetUniformLocation(shader->GetProgramID(), "object_color");
	glUniform3fv(objectColorLoc, 1, glm::value_ptr(color));
	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->GetProgramID(), "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	
	// Bind view matrix
	glm::mat4 viewMatrix = camera->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->GetProgramID(), "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	int loc_projection_matrix = glGetUniformLocation(shader->GetProgramID(), "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	if (texture != NULL)
	{
		//printf("aplica_text");
		//glEnable( GL_TEXTURE_2D );
		// Activate texture location 0
		glActiveTexture(GL_TEXTURE0);

		// Bind the texture1 ID
		glBindTexture(GL_TEXTURE_2D, texture->GetTextureID());

		// Send texture uniform value
		glUniform1i(glGetUniformLocation(shader->GetProgramID(), "texture"), 0);
	}
	glUniform1i(glGetUniformLocation(shader->GetProgramID(), "apply_texture"), apply_texture);

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Tema3::RenderUIMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, const glm::vec3 &color) {
	if (!mesh || !shader || !shader->GetProgramID())
		return;
	if (orangePowerUp) shouldTransform = 1;
	if (mesh != meshes["sphere"] || shouldTransform != 1) shouldTransform = 0;
	float r1 = Engine::GetElapsedTime() + 1;
	float r2 = Engine::GetElapsedTime() + 3;
	float r3 = Engine::GetElapsedTime() + 5;
	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);
	apply_texture = 0;
	glUniform1i(glGetUniformLocation(shader->program, "apply_texture"), apply_texture);
	glUniform1i(glGetUniformLocation(shader->program, "shouldTransform"), shouldTransform);
	glUniform1f(glGetUniformLocation(shader->program, "r1"), r1);
	glUniform1f(glGetUniformLocation(shader->program, "r2"), r2);
	glUniform1f(glGetUniformLocation(shader->program, "r3"), r3);
	GLint objectColorLoc = glGetUniformLocation(shader->program, "object_color");
	glUniform3fv(objectColorLoc, 1, glm::value_ptr(color));
	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0, 1.5f, 2.5f), glm::vec3(0, 0, 0), glm::vec3(0, 10, 0));
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 orthoProjectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(orthoProjectionMatrix));

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

void Tema3::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT) && !isDead)
	{
		if (window->KeyHold(GLFW_KEY_W) && currentSpeed < maxSpeed && !orangePowerUp && !isOutOfFuel) {
			currentSpeed += deltaTime * 10;
			currentSpeed = min(currentSpeed, maxSpeed);
		}

		if (window->KeyHold(GLFW_KEY_A) && playerPosition.x > -1) {
			playerPosition.x -= deltaTime * 6;
			camera->TranslateRight(-deltaTime * 6);
		}

		if (window->KeyHold(GLFW_KEY_S) && currentSpeed > minSpeed && !orangePowerUp && !isOutOfFuel) {
			currentSpeed -= deltaTime * 10;
			currentSpeed = max(currentSpeed, minSpeed);
		}

		if (window->KeyHold(GLFW_KEY_D) && playerPosition.x < 1) {
			playerPosition.x += deltaTime * 6;
			camera->TranslateRight(deltaTime * 6);
		}

		if (window->KeyHold(GLFW_KEY_P)) {
			startGame = true;
		}

		if (window->KeyHold(GLFW_KEY_SPACE) && !isJumping) {
			isJumping = true;
			jumpTimestamp = time;
		}

	}
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) {
		float cameraSpeed = 2.0f;

		if (window->KeyHold(GLFW_KEY_W)) {
			camera->TranslateForward(deltaTime * cameraSpeed);
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			camera->TranslateRight(-deltaTime * cameraSpeed);
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			camera->TranslateForward(-deltaTime * cameraSpeed);
		}

		if (window->KeyHold(GLFW_KEY_D)) {
			camera->TranslateRight(deltaTime * cameraSpeed);
		}

		if (window->KeyHold(GLFW_KEY_Q)) {
			camera->TranslateUpword(-deltaTime * cameraSpeed);
		}

		if (window->KeyHold(GLFW_KEY_E)) {
			camera->TranslateUpword(deltaTime * cameraSpeed);
		}
	}
}

void Tema3::OnKeyPress(int key, int mods)
{
	if (window->KeyHold(GLFW_KEY_V)) {
		if (isFirstPerson) {
			camera->Set(glm::vec3(0, 1.5f, 2.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
		}
		else {
			camera->Set(glm::vec3(0, 1, .5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
		}
		isFirstPerson = !isFirstPerson;
	}
}

void Tema3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float sensivityOX = 0.001f;
		float sensivityOY = 0.001f;

		if (window->GetSpecialKeyState() == 0) {
			camera->RotateFirstPerson_OX(-deltaY * sensivityOX);
			camera->RotateFirstPerson_OY(-deltaX * sensivityOY);
		}

		if (window->GetSpecialKeyState() && GLFW_MOD_CONTROL) {
			camera->RotateThirdPerson_OX(-deltaY * sensivityOX);
			camera->RotateThirdPerson_OY(-deltaX * sensivityOY);
		}
	}
}

void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema3::OnWindowResize(int width, int height)
{
}
