#ifndef MOB_H_
#define MOB_H_

#include <string>
#include <vector>
#include "entity.h"
#include "player.h"

using namespace std;

class mob
{
private:
	string mobType;
	string mobName;

public:
	void getStats();
	void setStats();
	void randomLoot();
	void getLoot();
	string getMobType();
	string getMobName();
	void combat();

};



#endif /* MOB_H_ */
