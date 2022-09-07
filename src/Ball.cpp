#include "Ball.h"

#include <math.h>
#include <cstdlib>

#define WIDTH_SCREEN 800
#define HEIGHT_SCREEN 600
#define DegreeToRad(n) n*0.017453292519943295769236907684886

/**
* Constructor de la clase Ball, tiene un constructor por default que es
* el del padre
*/
Ball::Ball(const char *file):
	Sprite(file)
{
    this->setVx(0);
    this->setVy(0);
    this->setAngle(0);

    bounce = Mix_LoadWAV("sounds/bounce.wav");

    generateAngle();

	SPEED = 5;
}

/**
* Destructor de la clase Ball
*/
Ball:: ~Ball()
{
    Mix_FreeChunk(bounce);
}

/**
* Actualiza la logica de la pelota
*/
void Ball::update()
{
    this->setX(this->getVx() + this->getX());
    this->setY(this->getVy() + this->getY());

    if(this->getY()-this->getHeight()/2 <= 0)
    {
        playBounce();
        setY(getHeight()/2);
        this->setAngleDirection(-this->getAngleDirection());
        updateSpeed();
    }
    else
        if((this->getX()-this->getWidth()/2) <= 0)
        {
            playBounce();
            setX(getWidth()/2);
            this->setAngleDirection(180-this->getAngleDirection());
            updateSpeed();
        }
        else
            if((this->getX()+this->getWidth()/2) >= WIDTH_SCREEN)
            {
                playBounce();
                setX(WIDTH_SCREEN-getWidth()/2-1);
                this->setAngleDirection(180-this->getAngleDirection());
                updateSpeed();
            }

    Sprite::update();
}

/**
* Actualiza la velocidad de la pelota
*/
void Ball::updateSpeed()
{
    this->setVx(Ball::SPEED * cosf(DegreeToRad(this->getAngleDirection())));
    this->setVy(Ball::SPEED * sinf(DegreeToRad(this->getAngleDirection())));
}

/**
* Genera un angulo de direccion de la pelota
*/
void Ball::generateAngle()
{
    this->setAngleDirection(270);
    this->setAngleDirection(this->getAngleDirection() + rand() % SPEED_ANGLE + 2.0);

    if(rand() % 100 + 1 < 50)
        this->setAngleDirection(-this->getAngleDirection());
}

void Ball::playBounce()
{
    Mix_PlayChannel(-1, bounce, 0);
}
