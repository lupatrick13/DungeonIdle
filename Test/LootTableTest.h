
#include "../Loot/LootTable.h"
#include "../Loot/Loot.h"

using namespace std;
void testLootTable()
{
	LootComponent *rareTable = new LootTable(1,"Rare Table");
	LootComponent *commonTable = new LootTable(35,"Common Table");

	LootComponent *Sword = new Loot(5, "sword");
	LootComponent *Dagger = new Loot(13, "Dagger");
	LootComponent *Staff = new Loot(2, "Staff");
	commonTable->add(Dagger);
	commonTable->add(Sword);
	commonTable->add(Staff);

	LootComponent *LSword = new Loot(5, "Legendary sword");
	LootComponent *LDagger = new Loot(13, "Twin Dragons");
	LootComponent *LStaff = new Loot(2, "Molten Burn");
	rareTable->add(LSword);
	rareTable->add(LDagger);
	rareTable->add(LStaff);
	commonTable->add(rareTable);
	LootComponent *emptyTable = new LootTable(2, "Aw man table!");
	commonTable->add(emptyTable);

	for(int i = 0; i< 100; i++)
	{
		LootComponent *result = commonTable->roll();
		if(result == nullptr) std::cout << "Nothing";
		else result->print();
		std::cout << "\nNext drop!\n";
		std::cout << i << std::endl;

	}
}
