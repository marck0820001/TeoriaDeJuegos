#include "MainGame.h"
#include "Imagen.h"

MainGame::MainGame()
{
	window = nullptr;
	width = 1024;
	height = 768;
	gameState = GameState::PLAY;

	intervalo = 500;
	sprites = vector<Sprite*>();
}

void MainGame::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Multiples imagenes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//es validar si hubo un error
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		//falta validar el estado del glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAttribute("vertexPosition");
	program.addAttribute("vertexColor");
	program.addAttribute("vertexUV");
	program.linkShaders();
}

void MainGame::run()
{
	init();
	update();
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.0002f;

	for (auto& sprite : sprites)
	{
		sprite->draw();
	}

	program.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::update()
{
	random_device aleatorio;
	default_random_engine eng(aleatorio());
	uniform_real_distribution<double> rango(-0.9f, 0.9f);

	while (gameState != GameState::EXIT)
	{
		Uint32 currentTime = SDL_GetTicks();

		if (currentTime - tiempoInicio > intervalo) {
			Imagen* image = new Imagen(rango(eng), rango(eng), 0.4f, 0.4f, "/Images/a.jpg");
			sprites.push_back(image);

			cout << "Printing image" << endl;
			tiempoInicio = currentTime;
		}

		processInput();
		draw();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << "Posicion en X: " << event.motion.x << " Posicion en Y: " << event.motion.y << endl;
			break;
		}
	}
}

MainGame::~MainGame()
{
}