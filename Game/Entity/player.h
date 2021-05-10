#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"


using namespace std;

class Player: public Entity
{
private:
	int exp;
	int levelUp;
	//int bossRoomCounter;
	pair<Equipment*, Equipment*> set; //first is ARMOR, second is WEAPON
	int gold;

public:
	Player();
	virtual ~Player() {}
	int getEXP() {
		return exp;
	};
	void setEXP(int e);
	// int getBossRoomCounter(){
	// 	return bossRoomCounter;
	// }

	int combatDMG() {
		int playerDMG, totalDMG = 0;
		playerDMG = stats[StatType::DMG] + stats[StatType::MAG] + stats[StatType::STR];
		int weaponBaseDMG = static_cast<int>(set.second->get_base_stat().second);
		std::map<int, float> addDMG = set.second->get_additional();
		int weaponAddDMG = static_cast<int>(addDMG[StatType::DMG]);

		totalDMG = playerDMG + weaponBaseDMG + weaponAddDMG;
		return totalDMG;
	}

	void boostStats(int i){
		stats[StatType::MAG] += i;
		stats[StatType::ARMOR] += i;
		stats[StatType::DEX] += i;
		stats[StatType::STR] += i;
		stats[StatType::AGI] += i;
		stats[StatType::DMG] += i;
		HP.first += i;
		HP.second += i;
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
	}

	int getGold(){
		return gold;
	}

	



	//Equipment* combat(entity* opponent);

};


#endif /* PLAYER_H_ */
