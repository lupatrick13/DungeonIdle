
#include "../Game/Loot/LootTable.h"
#include "../Game/Loot/Loot.h"
#include "../Game/Entity/mob.h"
#include "DungeonTable.h"

using namespace std;
Equipment * BossTable(int level)
{
    int up = level+3;
    int lower = level-3;
	EquipmentFactory *Sword1 = new EquipmentFactory(DMG, common, "Basic Sword", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Bow1 = new EquipmentFactory(DMG, common, "Basic Bow", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Staff1 = new EquipmentFactory(DMG, common, "Basic Staff", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shield1= new EquipmentFactory(ARMOR, common, "Basic Shield", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Helmet1 = new EquipmentFactory(ARMOR, common, "Basic Helmet", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Chest1 = new EquipmentFactory(ARMOR, common, "Basic Bow", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Pants1= new EquipmentFactory(ARMOR, common, "Basic Pants", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shoes1 = new EquipmentFactory(ARMOR, common, "Basic Shoes", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));

	LootComponent *commonTable = new LootTable(35,"Common Table");

	LootComponent *Sword = new Loot(1, Sword1);
    commonTable->add(Sword);
	LootComponent *Bow = new Loot(1, Bow1);
    commonTable->add(Bow);
	LootComponent *Staff = new Loot(1, Staff1);
    commonTable->add(Staff);
	LootComponent *Shield = new Loot(1, Shield1);
    commonTable->add(Shield);
	LootComponent *Helmet = new Loot(3, Helmet1);
    commonTable->add(Helmet);
	LootComponent *Chest = new Loot(3, Chest1);
    commonTable->add(Chest);
	LootComponent *Pants = new Loot(3, Pants1);
    commonTable->add(Pants);
	LootComponent *Shoes = new Loot(3, Shoes1);
    commonTable->add(Shoes);

	EquipmentFactory *Sword2 = new EquipmentFactory(DMG, legendary, "Legendary Sword", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Bow2 = new EquipmentFactory(DMG, legendary, "Legendary Bow", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Staff2 = new EquipmentFactory(DMG, legendary, "Legendary Staff", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shield2= new EquipmentFactory(ARMOR, legendary, "Legendary Shield", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Helmet2 = new EquipmentFactory(ARMOR, legendary, "Legendary Helmet", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Chest2 = new EquipmentFactory(ARMOR, legendary, "Legendary Bow", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Pants2= new EquipmentFactory(ARMOR, legendary, "Legendary Pants", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shoes2 = new EquipmentFactory(ARMOR, legendary, "Legendary Shoes", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));

	//LootComponent *rareTable = new LootTable(1,"Rare Table");
	LootComponent *legendaryTable = new LootTable(10,"Legendary Table");

	LootComponent *Sword = new Loot(1, Sword2);
    legendaryTable->add(Sword);
	LootComponent *Bow = new Loot(1, Bow2);
    legendaryTable->add(Bow);
	LootComponent *Staff = new Loot(1, Staff2);
    legendaryTable->add(Staff);
	LootComponent *Shield = new Loot(1, Shield2);
    legendaryTable->add(Shield);
	LootComponent *Helmet = new Loot(3, Helmet2);
    legendaryTable->add(Helmet);
	LootComponent *Chest = new Loot(3, Chest2);
    legendaryTable->add(Chest);
	LootComponent *Pants = new Loot(3, Pants2);
    legendaryTable->add(Pants);
	LootComponent *Shoes = new Loot(3, Shoes2);
    legendaryTable->add(Shoes);

	LootComponent *emptyTable = new LootTable(5, "Loser table!");
	legendaryTable->add(emptyTable);

    commonTable->add(legendaryTable);

	LootComponent *patrick = commonTable->roll();
	Equipment *nathan = patrick->generate();

    return nathan;

	//std::cout << "done" << std::endl;
}