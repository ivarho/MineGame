#include <iostream>
#include "game_object.hpp"

using namespace std;

class LiquidSupply : public GameObject
{
	LiquidSupply* source;
	LiquidSupply* destination;
	protected:
	double contains;
	public:
	void setSource(LiquidSupply* source);
	void setDestination(LiquidSupply* dest);
	LiquidSupply(LiquidSupply* source, LiquidSupply* dest);
	LiquidSupply(void);
	virtual double consume(double liter);
	double fill(double liter);
};

LiquidSupply::LiquidSupply(LiquidSupply* source, LiquidSupply* dest): GameObject(100)
{
	this->source = source;
	this->destination = dest;
}

LiquidSupply::LiquidSupply(void) : GameObject(100)
{
	this->source = NULL;
	this->destination = NULL;
}

double LiquidSupply::consume(double liter)
{
	if (this->source != NULL) {
		return this->source->consume(liter);
	}
}

class Tank : public LiquidSupply
{
	double capacity;
	//double contents;
	public:
	Tank(double capacity);
	void fill(double liter);
	double consume(double liter);
};

Tank::Tank(double capacity) : LiquidSupply(this, NULL)
{
	this->capacity = capacity;
	this->contains = capacity;
}

double Tank::consume(double liter)
{
	double return_val;

	if ((this->contains - liter) >= 0) {
		this->contains -= liter;
		return_val = liter;
	} else {
		return_val = this->contains;
		this->contains = 0;
	}

	cout << "Contents left in tank: " << this->contains << endl;
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

class ElectricalGenerator : public GameObject
{
	Engine *engine;
	LiquidSupply *fuel_tank;
	public:
	ElectricalGenerator(void);
	void consume_fuel();
	void connect_external_fuel_source(LiquidSupply* supply);
};

ElectricalGenerator::ElectricalGenerator(void) : GameObject(100)
{
	this->fuel_tank = new LiquidSupply(new Tank(25.0), NULL);
	this->engine = new Engine((Tank*)fuel_tank);
}

void ElectricalGenerator::connect_external_fuel_source(LiquidSupply* supply)
{
	this->fuel_tank = supply;
}

void ElectricalGenerator::consume_fuel()
{
	this->fuel_tank->consume(0.1);
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

	Tank* large_fuel_tank = new Tank(1000);

	// Create a fuel pipe used to connect between the large fuel tank
	// and the electrical generator
	LiquidSupply* pipe = new LiquidSupply(large_fuel_tank, NULL);

	ElectricalGenerator* generator = new ElectricalGenerator();
	// Consume fuel from the generator internal fuel tank
	generator->consume_fuel();

	// Connect an external tank and consume fuel from there instead
	generator->connect_external_fuel_source(pipe);
	generator->consume_fuel();


	if (!ny_digger->dig()) {
		cout << "No connected mine!" << endl;
	}

	ny_digger->set_mine(ny_mine);

	if (!ny_digger->dig()) {
		cout << "No connected mine!" << endl;
	}

	return 0;
}
