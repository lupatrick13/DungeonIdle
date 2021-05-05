#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 
#include <iostream>
#include "RNG.h"
#include "entity.h"

using namespace std;

Room::Room()
{
	roomValue = RANDOM_INT(1,3);
	Player.player();
}