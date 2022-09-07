#ifndef MENU_H
    #define MENU_H

#include "Game.h"
#include "Font.h"

#include "SDL.h"

/**
* Clase que pinta el menu del juego
* @author Cesar Himura
*/
class Menu : public Game
{
	private:
		Font *fontOptions;
		int option;
		const static int NUM_OPTIONS = 3;
		bool UP, DOWN, UP_OLD, DOWN_OLD, ENTER, ENTER_OLD;

	public:
		Menu(bool regulateKey);
		~Menu();
		virtual void init();
		virtual void update(SDL_Event event);
		virtual void render();
};

#endif
