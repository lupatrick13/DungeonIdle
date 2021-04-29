
#include "../Loot/LootTable.h"
#include "../Loot/Loot.h"
#include "../Entity/mob.h"

using namespace std;
void testLootTable()
{
	EquipmentFactory*AmazingSword = new EquipmentFactory(DMG, legendary, "Excalibur", 1000, 200, 999);
	EquipmentFactory *AmazingShield = new EquipmentFactory(ARMOR, legendary, "Aegis", 1000, 200, 999);
	EquipmentFactory *AmazingHelmet = new EquipmentFactory(ARMOR, legendary, "Bucket", 1000, 200, 999);

	EquipmentFactory *Sword1 = new EquipmentFactory(DMG, common, "Poker", 30, 1, 10);
	EquipmentFactory *Shield1= new EquipmentFactory(ARMOR, common, "Plank", 30, 1, 10);
	EquipmentFactory *Helmet1 = new EquipmentFactory(ARMOR, common, "CanTeen", 30, 1, 10);

	LootComponent *rareTable = new LootTable(1,"Rare Table");
	LootComponent *commonTable = new LootTable(35,"Common Table");

	LootComponent *Sword = new Loot(5, Sword1);
	LootComponent *Dagger = new Loot(13, Shield1);
	LootComponent *Staff = new Loot(2, Helmet1);
	commonTable->add(Dagger);
	commonTable->add(Sword);
	commonTable->add(Staff);

	LootComponent *LSword = new Loot(5, AmazingSword);
	LootComponent *LDagger = new Loot(13, AmazingShield);
	LootComponent *LStaff = new Loot(2, AmazingHelmet);
	rareTable->add(LSword);
	rareTable->add(LDagger);
	rareTable->add(LStaff);
	commonTable->add(rareTable);
	LootComponent *emptyTable = new LootTable(2, "Aw man table!");
	commonTable->add(emptyTable);

	entity *monstertest = new mob(REG, "Goblin", commonTable);

	Equipment *lootdropped = monstertest->combat(monstertest);
	lootdropped->print();
}
