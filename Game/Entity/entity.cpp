#include "entity.h"


Entity::Entity(int level, string name) : name(name), level(level) {
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
	exp = 0;
	gold = 0;
}

map<int, int> Entity::getStats() {
	return stats;
}

float Entity::getArmorReduc()
{

	float armorreduc;
	int armor = stats[StatType::ARMOR];
	armorreduc = log1p(armor) / 20;

	armorreduc = armorreduc < 0 ? 1 : 1-armorreduc;

	return armorreduc;
}


