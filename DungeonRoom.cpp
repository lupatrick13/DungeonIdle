#include "DungeonRoom.h"
#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

DungeonRoom::DungeonRoom()
{
	roomValue = rand() % 3;
	playerChoice = 0;
	//MobEntity Minion random generator thing here;
}

void DungeonRoom::roomChoice(int rv, int pc)
{
	if (rv == pc) {
		shopChance();
		//player.stepsTilBoss = player.stepsTilBoss - 2;
	}
	else //player.stepsTilBoss = player.stepsTilBoss - 1;
}

bool DungeonRoom::shopChance()
{
	int rng = rand() % 100;

	if (rng <= 25) {
		//send player to shop
	}
	else return 0;
}

void DungeonRoom::nextRoom()
{
	//send player to next room
}
