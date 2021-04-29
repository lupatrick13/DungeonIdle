#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>

using namespace std;

class entity
{	
private:
	int HP;
	int ARMOR;
	int DMG;
	int SPEED;
	int DODGE;
	int STR;
	int MAGIC;
	int AGILITY;
	int DEX;

public:
	entity();
	void getStats();
	void setStats();
	virtual void combat();

};

#endif /* ENTITY_H_ */