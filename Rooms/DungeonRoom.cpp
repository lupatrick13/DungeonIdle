#include "DungeonRoom.h"
#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h>
#include "RNG.h"

DungeonRoom::DungeonRoom()
{
	//MobEntity Minion random generator thing here;
	
}

#include "DungeonRoom.h"
#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h>
#include <iostream>
#include "RNG.h"

using namespace std;

DungeonRoom::DungeonRoom()
{
	//MobEntity Minion random generator thing here;
	
}

Room DungeonRoom::next_room(int playerChoice){
		int playersteps = 1;

		if (playersteps == 0){
			//int nextBoss = (player.getBossRoomCounter() * 5) + 20;
			//player.setSteps(nextBoss);
			cout << "To the Boss Room" << endl;
			//send player to boss room
		}
		else{
			int test = RANDOM_INT(1,3);
			//generate 3 rooms and giv them values of 1-3

			if(playerChoice == test){
				int rng = RANDOM_INT(1,100);
				if (rng <= 99) {
					//playerSteps = player.getSteps - 2;
					//player.setSteps();
				//send player to shop
				cout << "To the shop" << endl;

				Room generate_room();
				}
				else 
					//playerSteps = player.getSteps - 1;
					//player.setSteps(_)
					//send player to next room
					cout << "to next dungeon room" << endl;
			}
			cout << "to next dungeon room 2" << endl;
		} 
}