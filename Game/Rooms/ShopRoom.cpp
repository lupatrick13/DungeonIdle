#include "ShopRoom.h"
#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

play_state ShopRoom::play(int choice)
{
	if(choice == -1)
	{
		std::cout << "1. Heal " << heal.first << " : " << heal.second << "g"<< std::endl;
		std::cout << "2. Boost " << boost.first << " : " << boost.second << "g"<< std::endl;
		buyable["Heal"] = to_string(heal.first) + " life " + to_string(heal.second) + "g";
		buyable["Boost"] =to_string(boost.first) + " zooms " + to_string(boost.second) + "g";
		return play_state::OFFER;
	}
	else if(choice == 1)
		std::cout << "Bought heal" << std::endl;
	else if(choice == 2)
		std::cout << "Bought boost" << std::endl;

	if(choice != -1)
		return play_state::DONE;
	return play_state::CONTINUE;
}

map<string, string> ShopRoom::get_loot()
{
	return buyable;
}
