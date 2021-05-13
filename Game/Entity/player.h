#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"


using namespace std;

class Player: public Entity
{
private:

	int levelUp;
	//int bossRoomCounter;
	pair<Equipment*, Equipment*> set; //first is ARMOR, second is WEAPON
	void level_up();


public:
	Player();
	virtual ~Player() {}
	void setEXP(float e);
	// int getBossRoomCounter(){
	// 	return bossRoomCounter;
	// }

	float combatDMG() {
		bool hasweapon = set.second != nullptr;
		float playerDMG, totalDMG = 0;
		playerDMG = stats[StatType::DMG] + stats[StatType::MAG] + stats[StatType::STR];

		float weaponBaseDMG = 0, weaponAddDMG = 0;
		if(hasweapon)
		{
			weaponBaseDMG = (set.second->get_base_stat().second);
			std::map<int, float> addDMG = set.second->get_additional();
			weaponAddDMG = (addDMG[StatType::DMG] + addDMG[StatType::MAG]);
		}

		totalDMG = RANDOM_REAL(0.7,1.1) * playerDMG + RANDOM_REAL(0.9,1.05) * weaponBaseDMG + weaponAddDMG;
		return totalDMG;
	}

	void boostStats(int i){
		stats[StatType::MAG] += i;
		stats[StatType::ARMOR] += i;
		stats[StatType::DEX] += i;
		stats[StatType::STR] += i;
		stats[StatType::AGI] += i;
		stats[StatType::DMG] += i;
		HP.first += i*30;
		HP.second += i*30;
	}

	void setArmor(Equipment* a){
		set.first = a;
	}

	// int getArmor(){
	// 	std::map<int, float> AMR = set.first->get_base_stat();
	// 	std::map<int, float> AMR = set.first->get_additional();
	// 	return set.first + stats[StatType::ARMOR];
	// }

	void setWeapon(Equipment *a){
		set.second = a;
	}

	pair<Equipment*, Equipment*> getSet(){
		return set;
	}

	void setGold(int i){
		gold += i;
		gold = gold < 0 ? 0 : gold;
	}

	int getLevelUpExp(){ return levelUp; }
	//Equipment* combat(entity* opponent);

};


#endif /* PLAYER_H_ */
