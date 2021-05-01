#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"


using namespace std;

class Player: public Entity
{
private:
	int exp;
	int level;
	int levelUp;
	int statPoints;
	pair<Equipment*, Equipment*> set;

public:
	Player();
	virtual ~Player() {}
	int getEXP() {
		return exp;
	};
	void setEXP(int e);
	int getLevel() {
		return level;
	};
	int combatDMG() {
		int playerDMG = 0;
		
		return 5;
	}

	//Equipment* combat(entity* opponent);

};


#endif /* PLAYER_H_ */
