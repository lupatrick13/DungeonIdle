#pragma once
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
	void buyHeal();
	void buyBoost();
	void buyEquip();
};

