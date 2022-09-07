#ifndef EXPLOSIONMANAGER_H
	#define EXPLOSIONMANAGER_H

#include "Explosion.h"

/**
* Clase que gestiona las explosiones
* @author Cesar Himura
*/
class ExplosionManager
{
	private:
		static const int MAX_EXPLOSIONS = 15;
		static const int MATRESS = 2;
		static Explosion *explosions[MAX_EXPLOSIONS + MATRESS];

	public:
		static void addExplosion(Explosion* explosion);
		static void update();
		static void render();
		static void reset();
		static int getSpaces();
		static bool isAllDead();
};

#endif
