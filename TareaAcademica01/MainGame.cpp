#include "MainGame.h"
#include "Sprite.h"

using namespace std;

MainGame::MainGame()
{
	window = NULL;
	width = 1000;
	height = 800;
	gameState = GameState::PLAY;
	tiempoInicio = 0;
	intervalo = 1500;
}

void MainGame::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("GAAAAAAAAAAA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//es valida si hubo un error
	glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//falta validar el estado del glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	initShaders();
}

MainGame::~MainGame()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
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
	time += 0.01;
	
	rectangles.draw();

	program.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::update()
{
	random_device aleatorio;
	default_random_engine eng(aleatorio());
	uniform_real_distribution<double> rango(-1, 1);

	while (gameState != GameState::EXIT) {		

		Uint32 currentTime = SDL_GetTicks();

		if (currentTime - tiempoInicio > intervalo) {
			Sprite* sprite = new Sprite();
			sprite->init(rango(eng), rango(eng), 0.1f, 0.1f);

			rectangles.addRectangles(sprite);

			tiempoInicio = currentTime;
		}

		draw();
		
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << " Posicion en X " << event.motion.x
				<< " Posicion en Y " << event.motion.y << endl;
			break;
		}
	}
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPoistion");
	program.addAtribute("vertexColor");

	program.linkShader();
}