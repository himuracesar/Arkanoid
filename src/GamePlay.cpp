#include "GamePlay.h"

int GamePlay::level2[ROWS][COLS] =
			{
				{0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0},
				{0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0},
				{0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 0},
				{0, 2, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 2, 0},
				{0, 2, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 2, 0},
				{0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 0},
				{0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0},
				{0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0}
			};

int GamePlay::level1[ROWS][COLS] =
			{
				{1, 0, 1, 0, 2, 2, 2, 0, 3, 0, 0, 3, 0, 4, 4, 4},
				{1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 4, 0, 4},
				{1, 0, 1, 0, 2, 0, 2, 0, 3, 3, 0, 3, 0, 4, 0, 4},
				{1, 1, 1, 0, 2, 0, 2, 0, 3, 0, 3, 3, 0, 4, 0, 4},
				{1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 4, 0, 4},
				{1, 0, 1, 0, 2, 2, 2, 0, 3, 0, 0, 3, 0, 4, 4, 4},
				{1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 4, 0, 4},
				{1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 4, 0, 4}
			};

int GamePlay::level4[ROWS][COLS] =
			{
				{0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 3, 4, 1, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 3, 4, 1, 2, 3, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 0, 0, 0, 0},
				{0, 0, 0, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 0, 0, 0},
				{0, 0, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 0, 0},
				{0, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 0},
				{1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4}
			};

/*int GamePlay::level1[ROWS][COLS] =
			{
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};*/

int GamePlay::level3[ROWS][COLS] =
			{
				{1, 0, 2, 0, 3, 0, 4, 0, 1, 0, 2, 0, 3, 0, 4, 0},
				{0, 1, 0, 2, 0, 3, 0, 4, 0, 1, 0, 2, 0, 3, 0, 4},
				{2, 0, 1, 0, 2, 0, 3, 0, 4, 0, 1, 0, 2, 0, 3, 0},
				{0, 2, 0, 1, 0, 2, 0, 3, 0, 4, 0, 1, 0, 2, 0, 3},
				{3, 0, 2, 0, 1, 0, 2, 0, 3, 0, 4, 0, 1, 0, 2, 0},
				{0, 3, 0, 2, 0, 1, 0, 2, 0, 3, 0, 4, 0, 1, 0, 2},
				{4, 0, 3, 0, 2, 0, 1, 0, 2, 0, 3, 0, 4, 0, 1, 0},
				{0, 4, 0, 3, 0, 2, 0, 1, 0, 2, 0, 3, 0, 4, 0, 1}
			};

int GamePlay::level5[ROWS][COLS] =
			{
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
				{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
				{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
				{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
				{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
			};

/**
* Constructor del GamePlay
*/
GamePlay::GamePlay()
{
	player = new Sprite("images/rect_gray.png");

    ball = new Ball("images/ball.png");

	font = new Font("fonts/BlackCastleMF.ttf", 100);
	fontOptions = new Font("fonts/BlackCastleMF.ttf", 40);

	init();
}

/**
* Destructor del GamePlay
*/
GamePlay::~GamePlay()
{
	delete player;
	delete ball;
	delete font;
	delete fontOptions;

	ExplosionManager::reset();

	glDeleteTextures(1, &block_red);
    glDeleteTextures(1, &block_blue);
    glDeleteTextures(1, &block_green);
    glDeleteTextures(1, &block_yellow);
	glDeleteTextures(1, &ball_texture);
	glDeleteTextures(1, &life_texture);
}

/**
* Inicializa todos los recursos necesarios
*/
void GamePlay::init()
{
	setGameState(Game::GAME_PLAY);
	setGameStateOld(Game::GAME_PLAY);

	gameState = GamePlay::GAME_PLAY;

    texture_format = NULL;

    loadTexture(&block_red, "images/rect_red.png");
    loadTexture(&block_blue, "images/rect_blue.png");
    loadTexture(&block_green, "images/rect_green.png");
    loadTexture(&block_yellow, "images/rect_yellow.png");
    loadTexture(&ball_texture, "images/ball.png");

    lifes = 4;
	level = 1;
	option = 0;
	VX_PLAYER = 2;

	DOWN_OLD = DOWN = false;
	UP_OLD = UP = false;
	ENTER_OLD = ENTER = false;
	LEFT = RIGHT = false;
	SPACE = false;

    GeneraBloque();
    GenerateIconLife();

    srand(time(0));

	ResetGamePlay(true);
}

/**
* Actualiza la logica del juego, decidiendo que estado interno debe ser actualizado
* @param event Es el evento que recibe desde el teclado (input)
*/
void GamePlay::update(SDL_Event event)
{
    switch(gameState)
    {
        case GAME_PLAY:
            updateGamePlay(event);
        break;

        case GAME_OVER:
            updateGameOver(event);
        break;

        case CHANGE_LEVEL:
            updateChangeLevel(event);
        break;

        case GAME_FINISH:
            updateGameFinish(event);
        break;
    }
}

/**
* Actualiza la logica del juego (game state interno = GAME_PLAY)
* @param event Es el evento que recibe desde el teclado (input)
*/
void GamePlay::updateGamePlay(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_LEFT:
                LEFT = true;
            break;
            case SDLK_RIGHT:
                RIGHT = true;
            break;
            case SDLK_SPACE:
                SPACE = true;
            break;
            default:
            break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_LEFT:
                LEFT = false;
            break;
            case SDLK_RIGHT:
                RIGHT = false;
            break;
            case SDLK_SPACE:
                SPACE = false;
            break;
            default:
            break;
        }
    }

    if(SPACE)
    {
        SPACE = false;

        if(ball->getVx() == 0 && ball->getVy() == 0)
            ball->updateSpeed();
    }

    if(LEFT == true)
    {
        if(player->getX() - player->getWidth()/2 - VX_PLAYER > 0)
        {
            player->setX(player->getX() - VX_PLAYER);

            if(ball->getVx() == 0 && ball->getVy() == 0)
                ball->setX(ball->getX() - VX_PLAYER);
        }
    }
    else
        if(RIGHT == true)
        {
            if(player->getX() + player->getWidth()/2 + VX_PLAYER < WIDTH_SCREEN)
            {
                player->setX(player->getX() + VX_PLAYER);

                if(ball->getVx() == 0 && ball->getVy() == 0)
                    ball->setX(ball->getX() + VX_PLAYER);
            }
        }

    bool collision = false;

    player->update();
    ball->update();

    //*** La pelota colisiona con el player ***
    if(ball->getVx() != 0 && ball->getVy() != 0)
    {
        //*** La pelota colisiona con el player ***
        if((ball->getY()+ball->getHeight()/2) >= (player->getY()-player->getHeight()/2) &&
            ball->getY()-ball->getHeight()/2 < player->getY()+player->getHeight()/2 &&
           (ball->getX()+ball->getWidth()/4 >= (player->getX()-player->getWidth()/2) &&
           (ball->getX()-ball->getWidth()/4 <= (player->getX()+player->getWidth()/2) &&
           ball->getVx() != 0 && ball->getVy() != 0)))
        {
           ball->playBounce();
           ball->setY(player->getY() - player->getHeight()/2 - ball->getHeight()/2);

           if(RIGHT)
                ball->setAngleDirection(-ball->getAngleDirection() + rand() % Ball::SPEED_ANGLE);
           else
               if(LEFT)
                    ball->setAngleDirection(-ball->getAngleDirection() - rand() % Ball::SPEED_ANGLE);
                else
                    ball->setAngleDirection(-ball->getAngleDirection());

           ball->updateSpeed();
        }
        else
        {
            //**** La pelota choca contra el player por la derecha ****
            if((ball->getX()-ball->getWidth()/2) <= (player->getX()+player->getWidth()/2) &&
               ball->getX()-ball->getWidth()/2 > player->getX() &&
               (ball->getY()+ball->getHeight()/2) >= (player->getY()-player->getHeight()/2) &&
               ball->getVx() != 0 && ball->getVy() != 0)
            {
                ball->playBounce();
                ball->setX(player->getX() + player->getWidth()/2 + ball->getWidth()/2);
                ball->setAngleDirection(180-ball->getAngleDirection());
                ball->updateSpeed();

                if(RIGHT)
                    ball->setVx(ball->getVx()*VX_PLAYER+VX_PLAYER);
            }
            else
            {
                //**** La pelota choca contra el player por la izquierda ****
                if((ball->getX()+ball->getWidth()/2) >= (player->getX()-player->getWidth()/2) &&
                   ball->getX()+ball->getWidth()/2 < player->getX() &&
                   (ball->getY()+ball->getHeight()/2) >= (player->getY()-player->getHeight()/2) &&
                   ball->getVx() != 0 && ball->getVy() != 0)
                {
                    ball->playBounce();
                    ball->setX(player->getX() - player->getWidth()/2 - ball->getWidth()/2);
                    ball->setAngleDirection(180-ball->getAngleDirection());
                    ball->updateSpeed();

                    if(LEFT)
                        ball->setVx(ball->getVx()*VX_PLAYER-VX_PLAYER);
                }
            }
        }
    }//if ball Vx y Vy != 0

    //***** Revisa si el gamer ha perdido alguna vida *****
    if((ball->getY()-ball->getHeight()/2)-10 > HEIGHT_SCREEN)
    {
        lifes -= 1;
        ball->setVx(0);
        ball->setVy(0);

        if(lifes >= 0)
            ResetGamePlay(false);
    }

    //*** La pelota colisiona con la pared ***//
    //*** La pelota colision por abajo ***
    if(((ball->getY()-ball->getHeight()/2) >= 100 && (ball->getY()-ball->getHeight()/2) <= ROWS*HEIGHT_BLOCK+100) ||
       ((ball->getY()+ball->getHeight()/2) >= 100 && (ball->getY()+ball->getHeight()/2) <= ROWS*HEIGHT_BLOCK+100))
    {
        collision = true;
    }

    if(collision)
    {
        rowWall = ((ball->getY()-ball->getHeight()/2)-100)/HEIGHT_BLOCK;
        colWall = ball->getX()/WIDTH_BLOCK;

        if(!isBreakBlock())
        {
            //********* CHOCA PARTE DE ABAJO ***********
            rowWall = ((ball->getY()+ball->getHeight()/2)-100)/HEIGHT_BLOCK;

            if(isBreakBlock())
                ball->playBounce();
        }
        else
        {
            ball->playBounce();
        }

        collision = false;

        /*int point = 1;

        while(point <= POINTS_COLLISION)
        {
            switch(point)
            {
                case 1:
                    rowWall = ((ball->getY()-ball->getHeight()/2)-100)/HEIGHT_BLOCK;
                    colWall = ball->getX()/WIDTH_BLOCK;
                break;
                case 2:
                    rowWall = (ball->getY()-100)/HEIGHT_BLOCK;
                    colWall = (ball->getX()+ball->getWidth()/2)/WIDTH_BLOCK;
                break;
                case 3:
                    rowWall = ((ball->getY()+ball->getHeight()/2)-100)/HEIGHT_BLOCK;
                    colWall = ball->getX()/WIDTH_BLOCK;
                break;
                case 4:
                    rowWall = (ball->getY()-100)/HEIGHT_BLOCK;
                    colWall = (ball->getX()-ball->getWidth()/2)/WIDTH_BLOCK;
                break;
                default:
                break;
            }

            if(isBreakBlock())
                break;
            else
                ball->playBounce();

            point++;
        }*///while

        collision = false;
    }

    if(isFinishLevel())
    {
        option = 0;
        if(level == LEVELS)
        {
            if(ExplosionManager::isAllDead())
                gameState = GAME_FINISH;
        }
        else
        {
            if(ExplosionManager::isAllDead())
                gameState = CHANGE_LEVEL;
        }
    }

    if(lifes == -1)
    {
        gameState = GAME_OVER;
    }

    ExplosionManager::update();
}

/**
* Actualiza la logica del Game Over
* @param event Es el evento que recibe desde el teclado (input)
*/
void GamePlay::updateGameOver(SDL_Event event)
{
    updateGameFinish(event);
}

/**
* Actualiza la logica del cambio de nivel
* @param event Es el evento que recibe desde el teclado (input)
*/
void GamePlay::updateChangeLevel(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
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
    }
    else if(event.type == SDL_KEYUP)
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
        option = (option == 0) ? 2 : option - 1;
        UP_OLD = false;
    }
    else
        if(!DOWN && DOWN_OLD)
        {
            option = (option == 2) ? 0 : option + 1;
            DOWN_OLD = false;
        }

    if(ENTER && !ENTER_OLD)
	{
	    ENTER = false;

		switch(option)
		{
			case 0:
				level++;
				VX_PLAYER++;
				ball->increaseSpeed();;
                gameState = GAME_PLAY;
				ResetGamePlay(true);
			break;
			case 1:
				setGameState(Game::MENU);
			break;
			case 2:
				setGameState(Game::EXIT);
			break;
			default:
			break;
		}
	}
}

/**
* Actualiza la logica del GamePlay
* @param event Es el evento que recibe desde el teclado (input)
*/
void GamePlay::updateGameFinish(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
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
				ENTER = false;
			break;
            default:
            break;
        }
    }
    else if(event.type == SDL_KEYUP)
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
                ENTER = true;
                ENTER_OLD = false;
            break;
            default:
            break;
        }
    }

    if(!UP && UP_OLD)
    {
        option = (option == 0) ? 1 : option - 1;
        UP_OLD = false;
    }
    else
        if(!DOWN && DOWN_OLD)
        {
            option = (option == 1) ? 0 : option + 1;
            DOWN_OLD = false;
        }

    if(ENTER && !ENTER_OLD)
	{
	    ENTER = false;

		switch(option)
		{
			case 0:
				setGameState(Game::MENU);
			break;
			case 1:
				setGameState(Game::EXIT);
			break;
			default:
			break;
		}
	}
}

/**
* Gestiona que game state interno (el de la clase GamePlay) se debe renderear
*/
void GamePlay::render()
{
	switch(gameState)
	{
		case GAME_PLAY:
			renderGamePlay();
		break;

		case GAME_OVER:
			renderGameOver();
		break;

		case CHANGE_LEVEL:
			renderChangeLevel();
		break;

		case GAME_FINISH:
            renderGameFinish();
        break;
	}
}

/**
* Renderiza el GamePlay
*/
void GamePlay::renderGamePlay()
{
    Game::render();

	glEnable(GL_TEXTURE_2D);

	//*** col = 80px
    //*** row = 25px
    for(int col = 0; col < COLS; col++)
    {
        for(int row = 0; row < ROWS; row++)
        {
            glLoadIdentity();
            glTranslatef(col*WIDTH_BLOCK, row*25+100, 0);

            if(wall[row][col] > 0)
            {
                switch(wall[row][col])
                {
                    case RED:
                        glBindTexture(GL_TEXTURE_2D, block_red);
                    break;

                    case BLUE:
                        glBindTexture(GL_TEXTURE_2D, block_blue);
                    break;

                    case GREEN:
                        glBindTexture(GL_TEXTURE_2D, block_green);
                    break;

                    case YELLOW:
                        glBindTexture(GL_TEXTURE_2D, block_yellow);
                    break;
                }

                glCallList(block);
            }
        }//for row
    }//for col

	player->render();
	ball->render();
	ExplosionManager::render();

	//*** Indicadores de Vida ***
    for(int inx = 0; inx < lifes; inx++)
    {
        glLoadIdentity();
        glTranslatef(inx*WIDTH_ICON_LIFE, HEIGHT_SCREEN-HEIGHT_ICON_LIFE, 0);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, ball_texture);
        glCallList(iconLife);
    }

	glDisable(GL_TEXTURE_2D);
}

/**
* Renderiza el Game Over
*/
void GamePlay::renderGameOver()
{
    renderGamePlay();

    glLoadIdentity();
    font->drawString("Game Over", Font::CENTER, 150, Font::WHITE);

    if(option == 0)
		fontOptions->drawString("Menu", Font::CENTER, 250, Font::ORANGE);
	else
		fontOptions->drawString("Menu", Font::CENTER, 250, Font::WHITE);

	if(option == 1)
		fontOptions->drawString("Exit", Font::CENTER, 290, Font::ORANGE);
	else
		fontOptions->drawString("Exit", Font::CENTER, 290, Font::WHITE);
}

/**
* Renderea la pantalla de cambio de nivel
*/
void GamePlay::renderChangeLevel()
{
    renderGamePlay();

    glLoadIdentity();
    font->drawString("Congratulations!!!", Font::CENTER, 150, Font::WHITE);

    if(option == 0)
		fontOptions->drawString("Next Level", Font::CENTER, 250, Font::ORANGE);
	else
		fontOptions->drawString("Next Level", Font::CENTER, 250, Font::WHITE);

	if(option == 1)
		fontOptions->drawString("Menu", Font::CENTER, 290, Font::ORANGE);
	else
		fontOptions->drawString("Menu", Font::CENTER, 290, Font::WHITE);

	if(option == 2)
		fontOptions->drawString("Exit", Font::CENTER, 330, Font::ORANGE);
	else
		fontOptions->drawString("Exit", Font::CENTER, 330, Font::WHITE);
}

/**
* Renderiza el game state interno GAME_FINISH. Es cuando el jugador ha terminado todos los niveles
*/
void GamePlay::renderGameFinish()
{
    renderGamePlay();

    glLoadIdentity();
    font->drawString("Congratulations!!!", Font::CENTER, 150, Font::WHITE);
	fontOptions->drawString("M I S S I O N   C O M P L E T E", Font::CENTER, 250, Font::WHITE);
	fontOptions->drawString("You have finished the game", Font::CENTER, 300, Font::WHITE);

	if(option == 0)
		fontOptions->drawString("Menu", Font::CENTER, 350, Font::ORANGE);
	else
		fontOptions->drawString("Menu", Font::CENTER, 350, Font::WHITE);

	if(option == 1)
		fontOptions->drawString("Exit", Font::CENTER, 390, Font::ORANGE);
	else
		fontOptions->drawString("Exit", Font::CENTER, 390, Font::WHITE);
}

/**
* Genera una lista en OpenGL para generar los indicadores de vida
*/
void GamePlay::GenerateIconLife()
{
	iconLife = glGenLists(1);

	glNewList(iconLife, GL_COMPILE);

	glBegin(GL_QUADS);
        glTexCoord2i(0,0);
        glVertex2i(0, 0);
        glTexCoord2i(0,1);
        glVertex2i(0, HEIGHT_ICON_LIFE);
        glTexCoord2i(1,1);
        glVertex2i(WIDTH_ICON_LIFE,HEIGHT_ICON_LIFE);
        glTexCoord2i(1,0);
        glVertex2i(WIDTH_ICON_LIFE,0);
    glEnd();

	glEndList();
} //GeneraBloque

/**
* Genera una lista en OpenGL para generar un bloque
*/
void GamePlay::GeneraBloque()
{
	block = glGenLists(1);

	glNewList(block, GL_COMPILE);

	glBegin(GL_QUADS);
        glTexCoord2i(0,0);
        glVertex2i(0, 0);
        glTexCoord2i(0,1);
        glVertex2i(0, HEIGHT_BLOCK);
        glTexCoord2i(1,1);
        glVertex2i(WIDTH_BLOCK,HEIGHT_BLOCK);
        glTexCoord2i(1,0);
        glVertex2i(WIDTH_BLOCK,0);
    glEnd();

	glEndList();
} //GeneraBloque

/**
* Carga una textura
* @param texture Es la variable donde almacenara la textura
* @param file Es el archivo de la textura (imagen) a cargar
*/
void GamePlay::loadTexture(GLuint *texture, const char *file)
{
    SDL_Surface *surface = IMG_Load(file); // this surface will tell us the details of the image

    if(surface){
        // Check that the image’s width is a power of 2
        if ( (surface->w & (surface->w - 1)) != 0 ) {
            printf("warning: image.bmp’s width is not a power of 2\n");
        }

        // Also check if the height is a power of 2
        if ( (surface->h & (surface->h - 1)) != 0 ) {
            printf("warning: image.bmp’s height is not a power of 2\n");
        }

        //get number of channels in the SDL surface
        nofcolors = surface->format->BytesPerPixel;

        //contains an alpha channel
        if(nofcolors == 4)
        {
            if(surface->format->Rmask==0x000000ff)
                texture_format = GL_RGBA;
            else
                texture_format = GL_BGRA;
        }
        else if(nofcolors == 3) //no alpha channel
        {
            if(surface->format->Rmask==0x000000ff)
                texture_format = GL_RGB;
            else
                texture_format = GL_BGR;
        }
        else
        {
            printf("warning: the image is not truecolor…this will break ");
        }

        // Have OpenGL generate a texture object handle for us
        glGenTextures(1, texture);

        // Bind the texture object
        glBindTexture(GL_TEXTURE_2D, *texture);

        // Set the texture’s stretching properties
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D( GL_TEXTURE_2D, 0, nofcolors, surface->w, surface->h, 0,
        texture_format, GL_UNSIGNED_BYTE, surface->pixels);

        //glTexEnvf(GL_TEXTURE_2D,GL_TEXTURE_ENV_MODE,GL_DECAL);
    }
    else {
        printf("SDL could not load %s: %s\n", file, SDL_GetError());
        SDL_Quit();
    }

    // Free the SDL_Surface only if it was successfully created
    if(surface) {
        SDL_FreeSurface(surface);
    }
}

/**
* Resetea el GamePlay
* @param sl Indica si debe o no resetear el nivel
*/
void GamePlay::ResetGamePlay(const bool sl)
{
    player->setWidth(100);
    player->setHeight(25);
    player->setY(HEIGHT_SCREEN-50);
    player->setX(WIDTH_SCREEN/2);

    ball->setWidth(22);
    ball->setHeight(22);
    ball->setX(WIDTH_SCREEN/2);
    ball->setY(player->getY()-ball->getHeight()-2);
    ball->generateAngle();
    ball->setVx(0);
    ball->setVy(0);

    DOWN_OLD = DOWN = false;
	UP_OLD = UP = false;
	ENTER_OLD = ENTER = false;
	LEFT = RIGHT = false;
	SPACE = false;

    if(sl)
    {
        switch(level)
        {
            case 1:
                selectLevel(level1);
            break;
            case 2:
                selectLevel(level2);
            break;
            case 3:
                selectLevel(level3);
            break;
            case 4:
                selectLevel(level4);
            break;
            case 5:
                selectLevel(level5);
            break;
            default:
            break;
        }
    }
}

/**
* Selecciona un nivel para mostrarlo
* @param level Es el nivel que debe seleccionar
*/
void GamePlay::selectLevel(int level[ROWS][COLS])
{
    for(int col = 0; col < COLS; col++){
        for(int row = 0; row < ROWS; row++){
            wall[row][col] = level[row][col];
        }
    }
}

/**
* Verifica si un bloque fue destruido
* @return true Si un bloque es destruido, false en caso contrario
*/
bool GamePlay::isBreakBlock()
{
    if(rowWall < ROWS && colWall < COLS)
    {
        //printf("rowWall:: %d, ", rowWall);
        //printf("colWall:: %d, ", colWall);
        //printf("wall:: %d -- ", wall[rowWall][colWall]);
        //printf("x:: %f, y::%f\n", ball->getX()+ball->getWidth()/2, ball->getY());

        if(wall[rowWall][colWall] > 0)
        {
            ExplosionManager::addExplosion(new Explosion(colWall*WIDTH_BLOCK+WIDTH_BLOCK/2,
                                                         rowWall*HEIGHT_BLOCK+100+HEIGHT_BLOCK/2,
                                                         wall[rowWall][colWall]));

            wall[rowWall][colWall] = 0;

            ball->setAngleDirection(-ball->getAngleDirection());
            ball->updateSpeed();

            /*printf(".:AAA:.\n");
            printf("rowWall:: %d, ", rowWall);
            printf("colWall:: %d\n", colWall);*/
            /*printf("rcWall:: %d, ", rcWall);
            printf("ccWall:: %d \n", ccWall);*/
            return true;
        }
        else
        {
            //-*** Choca por la derecha del bloque ***
            colWall = (ball->getX()-ball->getWidth()/2)/WIDTH_BLOCK;

            if(wall[rowWall][colWall] > 0)
            {
                ExplosionManager::addExplosion(new Explosion(colWall * WIDTH_BLOCK + WIDTH_BLOCK/2,
                                                             rowWall * HEIGHT_BLOCK + 100 + HEIGHT_BLOCK/2,
                                                             wall[rowWall][colWall]));

                wall[rowWall][colWall] = 0;

                ball->setX(colWall * WIDTH_BLOCK + ball->getWidth()/2 + WIDTH_BLOCK);
                ball->setAngleDirection(180-ball->getAngleDirection());
                ball->updateSpeed();

                /*printf(".:DER:. x:: %f, y:: %f, Angle:: %f\n", ball->getX(), ball->getY(), ball->getAngleDirection());
                printf("rowWall:: %d, ", rowWall);
                printf("colWall:: %d\n", colWall);*/
                /*printf("rcWall:: %d, ", rcWall);
                printf("ccWall:: %d \n", ccWall);*/
                return true;
            }
            else
            {
                //-*** Choca por la izquierda del bloque ***
                colWall = (ball->getX()+ball->getWidth()/2)/WIDTH_BLOCK;

                if(wall[rowWall][colWall] > 0)
                {
                    ExplosionManager::addExplosion(new Explosion(colWall*WIDTH_BLOCK+WIDTH_BLOCK/2,
                                                         rowWall*HEIGHT_BLOCK+100+HEIGHT_BLOCK/2,
                                                         wall[rowWall][colWall]));

                    wall[rowWall][colWall] = 0;

                    ball->setAngleDirection(180-ball->getAngleDirection());
                    ball->updateSpeed();

                    /*printf(".:IZQ:.\n");
                    printf("rowWall:: %d, ", rowWall);
                    printf("colWall:: %d\n", colWall);*/
                    /*printf("rcWall:: %d, ", rcWall);
                    printf("ccWall:: %d \n", ccWall);*/
                    return true;
                }
            }
        }
    }//if col<colWall && row<rowWall

    return false;
}

/**
* Revisa si se ha terminado un nivel del juego
* @return Regresa true cuando finaliza un nivel
*/
bool GamePlay::isFinishLevel()
{
    for(int col = 0; col < COLS; col++){
        for(int row = 0; row < ROWS; row++){
            if(wall[row][col] != 0)
                return false;
        }
    }

    return true;
}
