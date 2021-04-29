#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"


using namespace std;

class player: public entity
{
private:
	int exp;
	int level;
	int levelUp;
	int statPoints;
	int bossRoomCounter;
	LootComponent* droptable;
	Equipment* equipment;

public:
	player();
	virtual ~player() {}
	int getEXP() {
		return exp;
	};
	void setEXP(int e);
	int getLevel() {
		return level;
	};
	int combatDMG() {
		int playerDMG = 0;
		
		playerDMG = (DMG *   )
	}

	//Equipment* combat(entity* opponent);

};


#endif /* PLAYER_H_ */
