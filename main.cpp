#include <iostream>
#include "game_object.hpp"

using namespace std;

class Tank : public GameObject
{
	double capacity;
	double contents;
	public:
	Tank(double capacity);
	void fill(double liter);
	double consume(double liter);
};

Tank::Tank(double capacity) : GameObject(100)
{
	this->capacity = capacity;
	this->contents = capacity;
}

double Tank::consume(double liter)
{
	double return_val;

	if ((this->contents - liter) >= 0) {
		this->contents -= liter;
		return_val = liter;
	} else {
		return_val = this->contents;
		this->contents = 0;
	}

	cout << "Contents left in tank: " << this->contents << endl;
	return return_val;
}

class Engine : public GameObject
{
	Tank* fuel_tank;

	public:
	Engine(Tank* fuel_tank);
	bool start(void);
	bool stop(void);
	bool is_running(void);
};

Engine::Engine(Tank* fuel_tank) : GameObject(100)
{
	this->fuel_tank = fuel_tank;
}

class Digger : public GameObject
{
	double capacity;
	Mine *mine;
	Tank *fuel_tank;
	Engine *engine;
	public:
	Digger(double);
	void update(void);
	void set_mine(Mine*);
	bool dig(void);
};

Digger::Digger(double capacity): GameObject(100)
{
	this->fuel_tank = new Tank(80.0);
	this->engine = new Engine(fuel_tank);
	this->capacity = capacity;
}

void Digger::set_mine(Mine *mine)
{
	this->mine = mine;
}

void Digger::update(void)
{
	return;
}

bool Digger::dig(void)
{
	if (this->mine != NULL) {
		this->mine->increase_size(this->capacity);
		this->fuel_tank->consume(0.2);
		return true;
	} else {
		return false;
	}
}

int main(void)
{
	cout << "Game started!" << endl;

	GameObject* house = new GameObject(10);

	house->set_hp(200);

	cout << "House object HP: " << house->get_hp() << endl;

	// Create game objects
	Mine* ny_mine = new Mine(100, 0);
	Digger* ny_digger = new Digger(2.2);

	if (!ny_digger->dig()) {
		cout << "No connected mine!" << endl;
	}

	ny_digger->set_mine(ny_mine);

	if (!ny_digger->dig()) {
		cout << "No connected mine!" << endl;
	}

	return 0;
}
