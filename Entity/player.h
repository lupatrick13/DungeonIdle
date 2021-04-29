#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"


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
	virtual ~player() {}
	void getEXP();
	void setEXP(int e);
	int getLevel();
	void setLevel();

};


#endif /* PLAYER_H_ */
