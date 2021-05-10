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
	Player() {
		exp = 0;
		level = 0;
		levelUp = 0;
		statPoints = 0;
		set = make_pair(nullptr, nullptr);
	}
	virtual ~Player() {}
	int getEXP() {
		return exp;
	};
	void setEXP(int e) {}
	int getLevel() {
		return level;
	};

	//Equipment* combat(entity* opponent);

};


#endif /* PLAYER_H_ */
