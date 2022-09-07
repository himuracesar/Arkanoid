#include "Menu.h"

/**
* Constructor de la clase Menu
* @param regulateKey Indica si debe regular el teclazo. Sirve para que un solo teclazo
* sea registrado en lugar de 'n' debido al gameloop.
*/
Menu::Menu(bool regulateKey)
{
	fontOptions = new Font("fonts/BlackCastleMF.ttf", 45);

	option = 0;

	ENTER = regulateKey;
	ENTER_OLD = regulateKey;

	init();
}

/**
* Destructor de la clase Menu
*/
Menu::~Menu()
{
	delete fontOptions;
}

/**
* Inicializa los recursos del Menu
*/
void Menu::init()
{
	Game::init();

	setBackground("images/Portada_Arkanoid.png");

	setGameState(Game::MENU);
	setGameStateOld(Game::MENU);

	UP = false;
	UP_OLD = false;
	DOWN = false;
	DOWN_OLD = false;
}

/**
* Actualiza la logica del Menu
*/
void Menu::update(SDL_Event event)
{
	Game::update(event);

	if(event.type == SDL_KEYDOWN)
	{
		//Adjust the velocity
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
				UP = true;
				UP_OLD = true;
			break;

			case SDLK_DOWN:
				DOWN = true;
				DOWN_OLD = true;
			break;

			case SDLK_RETURN:
				ENTER = true;
			break;

			default:
			break;
		}
	}//if event
	else
		if(event.type == SDL_KEYUP)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
					UP = false;
				break;

				case SDLK_DOWN:
					DOWN = false;
				break;
				case SDLK_RETURN:
					ENTER = false;
					ENTER_OLD = false;
				break;

				default:
				break;
			}
		}

	if(!UP && UP_OLD)
	{
		UP_OLD = false;

		if(option-1 < 0)
			option = NUM_OPTIONS;
		else
			option--;
	}
	else
		if(!DOWN && DOWN_OLD)
		{
			DOWN_OLD = false;

			if(option+1 > NUM_OPTIONS)
				option = 0;
			else
				option++;
		}

	if(ENTER && !ENTER_OLD)
	{
		switch(option)
		{
			case 0:
				setGameState(Game::GAME_PLAY);
			break;
			case 1:
				setGameState(Game::INSTRUCTIONS);
			break;
			case 2:
				setGameState(Game::CREDITS);
			break;
			case 3:
				setGameState(Game::EXIT);
			break;
			default:
			break;
		}
	}

    //**** Regulacion para la ventana Splash *****
	if(ENTER)
	{
        ENTER = false;
        ENTER_OLD = false;
	}
}

/**
* Dibuja en el menu en pantalla
*/
void Menu::render()
{
	Game::render();

	if(option == 0)
		fontOptions->drawString("Play", Font::CENTER, 380, Font::YELLOW);
	else
		fontOptions->drawString("Play", Font::CENTER, 380, Font::WHITE);

	if(option == 1)
		fontOptions->drawString("Instructions", Font::CENTER, 430, Font::YELLOW);
	else
		fontOptions->drawString("Instructions", Font::CENTER, 430, Font::WHITE);

	if(option == 2)
		fontOptions->drawString("Credits", Font::CENTER, 480, Font::YELLOW);
	else
		fontOptions->drawString("Credits", Font::CENTER, 480, Font::WHITE);

	if(option == 3)
		fontOptions->drawString("Exit", Font::CENTER, 530, Font::YELLOW);
	else
		fontOptions->drawString("Exit", Font::CENTER, 530, Font::WHITE);
}