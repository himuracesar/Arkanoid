#include "Game.h"

/**
* Constructor de la clase Game
*/
Game::Game()
{
    init();
}

/**
* Destructor de la clase Game
*/
Game::~Game()
{
	glDeleteTextures(1, &background);
}

/**
* Inicializa los recursos del juego
*/
void Game::init()
{
	texture = NULL;
	texture_format = NULL;
	background = NULL;
}

/**
* Actualiza los datos del juego. Este metodo debe ser sobre escrito
* en la clase hija
*/
void Game::update(SDL_Event event)
{

}

/**
* Limpia la pantalla y realiza el render del background. Este metodo debe ser sobre escrito
* en la clase hija
*/
void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);

	glTranslatef(0.0,0.0,0.0);

	if(background != NULL)
	{
		glBindTexture(GL_TEXTURE_2D, background);

        glBegin(GL_QUADS);
            // Top-left vertex (corner)
            glTexCoord2i(0, 0);
            glVertex2i(0, 0);

            // Top-right vertex (corner)
            glTexCoord2i(1, 0);
            glVertex2i(WIDTH_SCREEN, 0);

            // Bottom-right vertex (corner)
            glTexCoord2i(1, 1);
            glVertex2i(WIDTH_SCREEN, HEIGHT_SCREEN);

            // Bottom-left vertex (corner)
            glTexCoord2i(0, 1);
            glVertex2i(0, HEIGHT_SCREEN);
        glEnd();
	}

	glDisable(GL_TEXTURE_2D);
	glLoadIdentity();
}

/**
* Carga una imagen como el background del juego
*/
int Game::setBackground(char* img)
{
	SDL_Surface *bg; // this surface will tell us the details of the image

	if((bg = IMG_Load(img))){
	//if((bg = SDL_LoadBMP("bg.bmp"))){
		// Check that the image’s width is a power of 2
		if((bg->w & (bg->w - 1)) != 0){
			printf("warning: image.bmp’s width is not a power of 2\n");
		}

		// Also check if the height is a power of 2
		if((bg->h & (bg->h - 1)) != 0) {
			printf("warning: image.bmp’s height is not a power of 2\n");
		}

		//get number of channels in the SDL surface
		nofcolors=bg->format->BytesPerPixel;

		//contains an alpha channel
		if(nofcolors==4)
		{
			if(bg->format->Rmask==0x000000ff)
				texture_format=GL_RGBA;
			else
				texture_format=GL_BGRA;
		}
		else if(nofcolors==3) //no alpha channel
		{
			if(bg->format->Rmask==0x000000ff)
				texture_format=GL_RGB;
			else
				texture_format=GL_BGR;
		}
		else
		{
			printf("warning: the image is not truecolor…this will break ");
		}

		// Have OpenGL generate a texture object handle for us
		glGenTextures(1, &background);
		// Bind the texture object
		glBindTexture(GL_TEXTURE_2D, background);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		// Set the texture’s stretching properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, nofcolors, bg->w, bg->h, 0, texture_format, GL_UNSIGNED_BYTE, bg->pixels);
	}
	else {
		printf("SDL could not load image.bmp: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// Free the SDL_Surface only if it was successfully created
	if (bg) {
		SDL_FreeSurface(bg);
	}

	return 0;
}

