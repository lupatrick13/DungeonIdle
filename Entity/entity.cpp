#include "entity.h"


Entity::Entity() {
	stats[StatType::MAG] = 0;
	stats[StatType::ARMOR] = 0;
	stats[StatType::DEX] = 0;
	stats[StatType::STR] = 0;
	stats[StatType::AGI] = 0;
	stats[StatType::DMG] = 0;
	HP.first = 1;
	HP.second = 1;
	SPEED = 0;
	DODGE = 0;
}

map<int, int> Entity::getStats() {
	return stats;
}



