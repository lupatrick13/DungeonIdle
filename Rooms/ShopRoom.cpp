#include "ShopRoom.h"
#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

ShopRoom::ShopRoom()
{
	HealPrice = rand() % 20 + 10;
	HealPerc = rand() % 25 + 51;
	BoostPrice = rand() % 20 + 15;
	Boost = rand() % 10 + 1;
	EquipPrice = rand() % 20 + 20;
}

void ShopRoom::buyHeal()
{
	//if(player.money >= HealPrice){
	//player.money = player.money-HealPrice;
	//int healpercent = rand() % 25 + 51
	//player.health = player.health +  (( healpercentage / 100 )* player.health)
	//}
	//else cout << player does not have enough money
}

void ShopRoom::buyBoost()
{
	//if(player.money >= BoostPrice){
	//player.money = player.money-BoostPrice;
	//player.stats = player.stat +  boost)
	//}
	//else cout << player does not have enough money
}

void ShopRoom::buyEquip()
{
	//if(player.money >= EquipPrice){
	//player.money = player.money-EquipPrice;
	//type = ShopEquip.type;		
	//if(player.equipmentSlot.type =/ "null"){
	//prompt player with equipment change
	// }
	// 	   else player.EquipmentSlot.type = ShopEquip;
	//}
	//else cout << player does not have enough money
}
