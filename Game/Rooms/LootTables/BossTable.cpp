/*
 * BossTable.cpp
 *
 *  Created on: May 10, 2021
 *      Author: patrick
 */

#include "BossTable.h"

LootComponent * BossTable(int level)
{
    int up = level+5;
    int lower = level-2;
    lower = lower < 1 ? 1 : lower;
	EquipmentFactory *Sword1 = new EquipmentFactory(DMG, common, "Sword", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Bow1 = new EquipmentFactory(DMG, common, "Bow", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Staff1 = new EquipmentFactory(DMG, common, "Staff", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shield1= new EquipmentFactory(ARMOR, common, "Shield", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Helmet1 = new EquipmentFactory(ARMOR, common, "Helmet", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Chest1 = new EquipmentFactory(ARMOR, common, "Belt", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Pants1= new EquipmentFactory(ARMOR, common, "Pants", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shoes1 = new EquipmentFactory(ARMOR, common, "Shoes", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));

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

	EquipmentFactory *Sword2 = new EquipmentFactory(DMG, legendary, "Sword", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Bow2 = new EquipmentFactory(DMG, legendary, "Bow", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Staff2 = new EquipmentFactory(DMG, legendary, "Staff", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shield2= new EquipmentFactory(ARMOR, legendary, "Shield", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Helmet2 = new EquipmentFactory(ARMOR, legendary, "Helmet", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
    EquipmentFactory *Chest2 = new EquipmentFactory(ARMOR, legendary, "Belt", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Pants2= new EquipmentFactory(ARMOR, legendary, "Pants", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));
	EquipmentFactory *Shoes2 = new EquipmentFactory(ARMOR, legendary, "Shoes", RANDOM_INT(1,30), 1, RANDOM_INT(lower,up));

	LootComponent *legendaryTable = new LootTable(10,"Legendary Table");

	LootComponent *LSword = new Loot(1, Sword2);
    legendaryTable->add(LSword);
	LootComponent *LBow = new Loot(1, Bow2);
    legendaryTable->add(LBow);
	LootComponent * LStaff = new Loot(1, Staff2);
    legendaryTable->add(LStaff);
	LootComponent * LShield = new Loot(1, Shield2);
    legendaryTable->add(LShield);
	LootComponent * LHelmet = new Loot(3, Helmet2);
    legendaryTable->add(LHelmet);
	LootComponent * LChest = new Loot(3, Chest2);
    legendaryTable->add(LChest);
	LootComponent * LPants = new Loot(3, Pants2);
    legendaryTable->add(LPants);
	LootComponent * LShoes = new Loot(3, Shoes2);
    legendaryTable->add(LShoes);

	LootComponent *emptyTable = new LootTable(5, "Loser table!");
	legendaryTable->add(emptyTable);

    commonTable->add(legendaryTable);

    return commonTable;

	//std::cout << "done" << std::endl;
}