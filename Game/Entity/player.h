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
	int bossRoomCounter;
	int stepsTilNextBoss;
	pair<Equipment*, Equipment*> set;
	int gold;

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
	int getSteps(){
		return stepsTilNextBoss;
	}
	void setSteps(int steps){
		stepsTilNextBoss = steps;
	}
	int getBossRoomCounter(){
		return bossRoomCounter;
	}

	int combatDMG() {
		int playerDMG = 0;
		
		return 5;
	}

	void boostStats(int i){
		stats[StatType::AGI] += i;
		stats[StatType::ARMOR] += i;
		stats[StatType::DEX] += i;
		stats[StatType::STR] += i;
		stats[StatType::AGI] += i;
		stats[StatType::DMG] += i;
		HP.first += i;
		HP.second += i;
		SPEED += i;
		DODGE += i;
	}

	void setArmor(Equipment* a){
		set.first = a;
	}

	void setWeapon(Equipment *a){
		set.second = a;
	}

	void setGold(int i){
		gold += i;
	}

	int getGold(){
		return gold;
	}




	//Equipment* combat(entity* opponent);

};


#endif /* PLAYER_H_ */
