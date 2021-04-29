#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "entity.h"
#include "mob.h"


using namespace std;

class player 
{
private:
	int exp;
	int level;
	int levelUp;
	int statPoints;
	int bossRoomCounter;

public:
	player();
	void getStats();
	void setStats();
	void getEXP();
	void setEXP(int e);
	int getLevel();
	void setLevel();
	void combat();

};


#endif /* PLAYER_H_ */
