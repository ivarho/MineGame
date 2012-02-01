#include <iostream>
#include "game_object.hpp"

using namespace std;

class Mine: public GameObject {
	double size;
	public:
	Mine(int, double);
	void increase_size(double);
};

Mine::Mine(int hp, double size): GameObject(hp)
{
	this->size = size;
}

void Mine::increase_size(double size)
{
	this->size += size;
	cout << "Size of mine increased to: " << this->size << " m3" << endl;
}

class Digger : public GameObject
{
	double capacity;
	Mine *mine;
	public:
	Digger(double);
	void update(void);
	void set_mine(Mine*);
};

Digger::Digger(double capacity): GameObject(100)
{
	this->capacity = capacity;
}

void Digger::set_mine(Mine *mine)
{
	this->mine = mine;
}

void Digger::update(void)
{
	this->mine->increase_size(this->capacity);
}


int main(void)
{
	cout << "Game started!" << endl;

	GameObject* house = new GameObject(10);

	house->set_hp(200);

	cout << "House object HP: " << house->get_hp() << endl;
	Mine ny_mine(100, 0);
	Digger ny_digger(2.2);
	ny_digger.set_mine(&ny_mine);
	ny_digger.update();
	ny_digger.update();

	return 0;
}
