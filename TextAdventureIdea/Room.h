#pragma once
class Room
{
private:
	//string vector listing items in room?
	//progression item (i.e. chest, locked door) + bool status (locked/unlocked)
	//boundary locations (i.e. wall to north, opening to east)
	//location (string) on map grid (i.e. A4, D2) -> letters on Y, numbers on X
public:
	Room();
	~Room();
};

