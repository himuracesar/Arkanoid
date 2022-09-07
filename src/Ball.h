#include "Sprite.h"
#include "SDL_mixer.h"

/**
* Clase que gestion la logica de la pelota
* @author Cesar Himura
*/
class Ball : public Sprite
{
	private:
		int SPEED;

    public:
		Ball(const char *file);
		~Ball();
		Mix_Chunk *bounce;
		void virtual update();
		void updateSpeed();
		void generateAngle();
		void playBounce();
		void increaseSpeed(){SPEED++;};

        static const int SPEED_ANGLE = 10;
};
