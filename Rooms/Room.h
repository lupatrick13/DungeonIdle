#pragma once
class Room
{
public:
<<<<<<< Updated upstream
	Room();
	virtual ~Room();
	virtual Room next_room(int choice);
	virtual void generate_loot();
	virtual void generate_room();
private:
	int RoomValue;
=======
	Room(){}
	virtual ~Room() {}
	virtual Room *next_room(){
		cout << "Where do you want to go?" << endl;
	};
	virtual void *generate_loot();
>>>>>>> Stashed changes
};

