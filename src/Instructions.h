#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "SDL.h"

#include "Game.h"
#include "Font.h"

/**
* Clase Instruction, muestra las instrucciones en pantalla
* @author Cesar Himura
*/
class Instructions : public Game
{
    private:
		Font *fontTitle;
		Font *font;
		bool ENTER, ENTER_OLD;

    public:
		Instructions();
		~Instructions();
		virtual void init();
		virtual void update(SDL_Event event);
		virtual void render();
};

#endif // INSTRUCTIONS
