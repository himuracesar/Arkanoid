#include "Instructions.h"

/**
* Constructor de la clase Instructions
*/
Instructions::Instructions()
{
    fontTitle = new Font("fonts/BlackCastleMF.ttf", 50);
    font = new Font("fonts/BlackCastleMF.ttf", 35);

    init();
}

/**
* Destructor de la clase Instructions
*/
Instructions::~Instructions()
{
    delete font;
    delete fontTitle;
}

/**
* Iniciliaza los recursos de la clase Instructions
*/
void Instructions::init()
{
    setGameState(Game::INSTRUCTIONS);
	setGameStateOld(Game::INSTRUCTIONS);

    ENTER = ENTER_OLD = true;
}

/**
* Actualiza la logica de la clase Instructions
*/
void Instructions::update(SDL_Event event)
{
    Game::update(event);

	if(event.type == SDL_KEYDOWN)
	{
		//Adjust the velocity
		switch(event.key.keysym.sym)
		{
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
				case SDLK_RETURN:
					ENTER = false;
					ENTER_OLD = false;
				break;

				default:
				break;
			}
		}

    if(ENTER && !ENTER_OLD)
	{
	    ENTER_OLD = false;
	    setGameState(Game::MENU);
	}
}

/**
* Rederiza todos los objetos de la clase Instructions
*/
void Instructions::render()
{
    Game::render();

    fontTitle->drawString("I N S T R U C T I O N S", Font::CENTER, 1, Font::ORANGE);
    font->drawString("You will must destroy all the blocks with a ball.", Font::LEFT, 100, Font::WHITE);
    font->drawString("SPACE_BAR: The ball begins to move.", Font::LEFT, 170, Font::WHITE);
    font->drawString("ARROW_LEFT: Move the bar to the left.", Font::LEFT, 220, Font::WHITE);
    font->drawString("If the ball bounces on the bar, the angle is open to the left.", Font::LEFT, 260, Font::WHITE);
    font->drawString("ARROW_RIGHT: Move the bar to the right.", Font::LEFT, 320, Font::WHITE);
    font->drawString("If the ball bounces on the bar, the angle is open to the right.", Font::LEFT, 360, Font::WHITE);
    font->drawString("Menu", Font::CENTER, 460, Font::ORANGE);
}
