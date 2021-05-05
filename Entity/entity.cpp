#include "entity.h"


<<<<<<< Updated upstream:Entity/entity.cpp
entity::entity() {
	HP = 100;
	ARMOR = 0;
	DMG = 0;
=======
Entity::Entity() {
	stats[StatType::MAG] = 0;
	stats[StatType::ARMOR] = 0;
	stats[StatType::DEX] = 0;
	stats[StatType::STR] = 0;
	stats[StatType::AGI] = 0;
	stats[StatType::DMG] = 0;
	HP.first = 1;
	HP.second = 1;
>>>>>>> Stashed changes:Game/Entity/entity.cpp
	SPEED = 0;
	DODGE = 0;
}

<<<<<<< Updated upstream:Entity/entity.cpp
void entity::getStats() {
	cout << HP, ARMOR, DMG, SPEED, DODGE, STR, MAGIC, AGILITY, DEX << endl;
=======
map<int, int> Entity::getStats() {
	return stats;
>>>>>>> Stashed changes:Game/Entity/entity.cpp
}



