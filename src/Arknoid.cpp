#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "Game.h"
#include "GamePlay.h"
#include "Menu.h"
#include "Instructions.h"
#include "Splash.h"
#include "Credits.h"

#define WIDTH_SCREEN 800
#define HEIGHT_SCREEN 600

SDL_Event event;

Uint32 ini_milisegundos;
Uint32 fin_milisegundos;
Uint32 frametime;

Game *game;

bool quit;

/**
* Realiza el pintado de todos los graficos en pantalla y actualiza la logica de los sprites
*/
void update()
{
	if(game->getGameState() != game->getGameStateOld())
	{
		int gameState = game->getGameState();

		delete game;
		game = NULL;

		switch(gameState)
		{
		    case Game::SPLASH:
                game = new Splash();
		    break;
			case Game::MENU:
				game = new Menu(true);
			break;
			case Game::INSTRUCTIONS:
				game = new Instructions();
			break;
			case Game::CREDITS:
				game = new Credits();
			break;
			case Game::GAME_PLAY:
				game = new GamePlay();
			break;
			case Game::EXIT:
				quit = true;
			break;
		}
	}

	if(game != NULL)
	{
		game->update(event);
	}
}

/**
* Renderiza los objetos en pantalla
*/
void render()
{
	// Clear the screen before drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glColor4f(1.0f,1.0f,1.0f,1.0f);

	if(game != NULL)
	{
		game->render();
	}

	SDL_GL_SwapBuffers();
}

/**
* Destruye todo y libera la memoria ocupada
*/
void clean_up()
{
	delete game;

	Mix_CloseAudio();

	SDL_Quit();
}

/**
* Inicia SDL
*/
int init_SDL()
{
	SDL_Surface *screen;

	int videoFlags;

	const SDL_VideoInfo *videoInfo;

	// Slightly different SDL initialization
	if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	videoInfo = SDL_GetVideoInfo( );

    if (!videoInfo)
	{
	    fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
	    clean_up();
	}

	/* the flags to pass to SDL_SetVideoMode                            */
    videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL          */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering       */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    //videoFlags |= SDL_RESIZABLE;       /* Enable window resizing        */

    /* This checks to see if surfaces can be stored in memory */
    if ( videoInfo->hw_available )
		videoFlags |= SDL_HWSURFACE;
    else
		videoFlags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    if ( videoInfo->blit_hw )
		videoFlags |= SDL_HWACCEL;

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* get a SDL surface */
    screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 32, videoFlags);

	//screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 32, SDL_OPENGL|SDL_HWSURFACE);
	if ( !screen ) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}

	/* Enable key repeat */
    if (( SDL_EnableKeyRepeat( 100, SDL_DEFAULT_REPEAT_INTERVAL)))
	{
	    fprintf(stderr, "Setting keyboard repeat failed: %s\n", SDL_GetError());
	}

	if(TTF_Init() == -1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        return 2;
    }

	// Inicializamos SDL_mixer
	if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096)) {
	//if(Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) < 0){
		printf("No se puede inicializar SDL_mixer %s\n",Mix_GetError());
		return 3;
	}

	return 0;
}

/**
* Inicia OpenGL
*/
void init_GL()
{
	// Set the OpenGL state after creating the context with SDL_SetVideoMode
	glShadeModel(GL_SMOOTH);

	glClearDepth(1.0f);

    glDisable(GL_DEPTH_TEST);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glEnable(GL_TEXTURE_2D);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	glViewport(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, WIDTH_SCREEN, HEIGHT_SCREEN, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
* Inicializa los recursos del juego (sprites y estados del juego)
*/
void init()
{
	//game = new Menu(false);
	game = new Splash();
}

void ResetTimeBase()
{
	ini_milisegundos = SDL_GetTicks();
}

int CurrentTime()
{
	fin_milisegundos = SDL_GetTicks();

	return fin_milisegundos - ini_milisegundos;
}

/**
* Metodo main. Contiene el gameloop
*/
int main(int argc, char *argv[])
{
	//Make sure the program waits for a quit
	quit = false;

	init_SDL();
	init_GL();
	init();

	SDL_WM_SetCaption("Arkanoid", NULL);
	//SDL_WM_SetIcon(IMG_Load("images/asteroid.png"), NULL);

	while(quit == false)
	{
		ResetTimeBase();

		if(SDL_PollEvent(&event))
		{
			//If a key was pressed
			if(event.type == SDL_KEYDOWN)
			{
				//Adjust the velocity
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quit = true;
					break;
					default:
					break;
				}
			}
			else
			{
				if(event.type == SDL_QUIT)
					quit = true;
			}
		}//if SDL_PollEvent

		update();
		render();

		do {
			frametime = CurrentTime();
		}while(frametime < 20);
	}//while

	clean_up();
	return 0;
}

