#include "player.h"
#include <iostream>

Player::Player() {
	exp = 0;
	level = 0;
	levelUp = 0;
	statPoints = 0;
	bossRoomCounter = 0;
<<<<<<< Updated upstream:Entity/player.cpp

}

void player::setEXP(int e) {
=======
	stepsTilNextBoss = 0;
	Entity();
	gold = 0;
}

void Player::setEXP(int e) {
>>>>>>> Stashed changes:Game/Entity/player.cpp
	if (exp < levelUp) {
		exp = exp + e;
	}
	else if (exp >= levelUp) {
		exp = exp + e;
		statPoints = statPoints + 10;
		levelUp = levelUp + 1;
	}
}

<<<<<<< Updated upstream:Entity/player.cpp


/**


Equipment* player::combat(entity* opponent) {
	
	
	LoopComponent* dropped = droptable->roll();
	return dropped->generate();

}

*/


=======

>>>>>>> Stashed changes:Game/Entity/player.cpp
