#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Ball.h"
#include "ExplosionManager.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include <stdio.h>
#include <ctime>
#include <cstdlib>

#define WIDTH_ICON_LIFE 20
#define HEIGHT_ICON_LIFE 20

#define ROWS 8
#define COLS 16
#define WIDTH_BLOCK 50
#define HEIGHT_BLOCK 25
#define RED 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4
#define WIDTH_ICON_LIFE 20
#define HEIGHT_ICON_LIFE 20
#define POINTS_COLLISION 4

#define DegreeToRad(n) n*0.017453292519943295769236907684886
#define RadToDegree(n) n*57.295779513082320876798154814105

/**
* Clase del GamePlay, en ella esta contenida el juego
* @author Cesar Himura
*/
class GamePlay : public Game
{
	private:
		bool LEFT;
		bool RIGHT;
		bool UP, UP_OLD;
		bool DOWN, DOWN_OLD;
		bool ENTER, ENTER_OLD;
		bool SPACE, SPACE_OLD;
		bool P, P_OLD;
		int optionPause;
		int gameState;
		int colWall, rowWall;
		int lifes;
		int level;
		int option;
		int wall[ROWS][COLS];
		int VX_PLAYER;
        static int level1[ROWS][COLS];
        static int level2[ROWS][COLS];
        static int level3[ROWS][COLS];
        static int level4[ROWS][COLS];
        static int level5[ROWS][COLS];
		static const int LEVELS = 5;
		Sprite *player;
		Ball *ball;
		Font *font;
		Font *fontOptions;
		GLuint iconLife;
		GLuint life_texture;
		GLuint block_red;
		GLuint block_yellow;
		GLuint block_blue;
		GLuint block_green;
		GLuint block;
		GLuint ball_texture;
		GLuint texture_format;
		GLuint nofcolors;

		const static int GAME_PLAY = 0;
		const static int GAME_OVER = 1;
		const static int PAUSE = 2;
		const static int PAUSE_MENU = 1;
		const static int PAUSE_CONTINUE = 0;
		const static int CHANGE_LEVEL = 3;
		const static int GAME_FINISH = 4;

		/*** FUNCIONES ***/
		void initPlayer();
		void updateGamePlay(SDL_Event event);
		void updatePause(SDL_Event event);
		void updateChangeLevel(SDL_Event event);
		void updateGameOver(SDL_Event event);
		void updateGameFinish(SDL_Event event);
		void renderGamePlay();
		void renderPause();
		void renderGameOver();
		void renderChangeLevel();
		void renderGameFinish();
		void GeneraBloque();
		void GenerateIconLife();
		void loadTexture(GLuint *texture, const char *file);
		void ResetGamePlay(const bool sl);
		void selectLevel(int level[ROWS][COLS]);
		bool isBreakBlock();
		bool isFinishLevel();

	public:
		GamePlay();
		~GamePlay();
		virtual void init();
		virtual void update(SDL_Event event);
		virtual void render();
};
