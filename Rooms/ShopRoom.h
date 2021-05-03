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
	virtual ~ShopRoom();
	void setHealPrice();
	void getHealPrice();
	void buyHeal();
	void buyBoost();
	void setBoostPrice();
	void getBoostPrice();
	void buyEquip();
};

