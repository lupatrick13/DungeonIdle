#pragma once
class Room
{
public:
	Room(){}
	virtual ~Room() {}
	virtual Room *go_next_room() { return nullptr; }
};

