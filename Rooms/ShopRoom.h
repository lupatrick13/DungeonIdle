#pragma once

#include "Room.h"
class ShopRoom: public Room
{
private:
	int HealPrice;
	int HealPerc;
	int BoostPrice;
	int Boost;
	int EquipPrice;
	//Equipment ShopEquip;
public:
	ShopRoom();
<<<<<<< Updated upstream
	virtual ~ShopRoom();
	void setHealPrice();
	void getHealPrice();
=======
	Room *next_room(){
		//send player back to previous room
	};
	void *generate_loot(){
		
	};
>>>>>>> Stashed changes
	void buyHeal();
	void buyBoost();
	void buyEquip();
};

