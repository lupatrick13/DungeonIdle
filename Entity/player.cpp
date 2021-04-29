#include "player.h"
#include <iostream>

player::player() {
	exp = 0;
	level = 0;
	levelUp = 0;
	statPoints = 0;
	bossRoomCounter = 0;

}

void player::setEXP(int e) {
	if (exp < levelUp) {
		exp = exp + e;
	}
	else if (exp >= levelUp) {
		exp = exp + e;
		statPoints = statPoints + 10;
		levelUp = levelUp + 1;
	}
}



/**


Equipment* player::combat(entity* opponent) {
	
	
	LoopComponent* dropped = droptable->roll();
	return dropped->generate();

}

*/


