#pragma once
class Room
{
public:
	Room();
	virtual ~Room();
	virtual Room next_room(int choice);
	virtual void generate_loot();
	virtual void generate_room();
private:
	int RoomValue;
};

