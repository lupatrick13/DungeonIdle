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
	void setHealPrice();
	void getHealPrice();
	void buyHeal();
	void buyBoost();
	void setBoostPrice();
	void getBoostPrice();
	void buyEquip();
};

