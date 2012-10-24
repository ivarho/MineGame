#include <iostream>
#include "GameObject.hpp"
#include "LiquidSystems.hpp"
#include "EngineSystems.hpp"

using namespace std;

enum fuse_state {
	STATE_OK,
	FAILED,
};



class ElectricalFuse :public GameObject
{
	int limit;
	enum fuse_state state;
	public:
	ElectricalFuse(int);
	//ElectricalFuse();
	void set_limit(int);
	void test(void);
	void replace_fuse(void);
	enum fuse_state get_state(void);
};

ElectricalFuse::ElectricalFuse(int limit)
{
	this->limit = limit;
	this->state = STATE_OK;
}

void ElectricalFuse::test(void)
{
	this->state = FAILED;
}

void ElectricalFuse::replace_fuse(void)
{
	this->state = STATE_OK;
}

class ElectricalGenerator : public GameObject
{
	PetrolEngine *engine;
	LiquidSupply *fuel_tank;
	public:
		ElectricalGenerator(void);
		void consume_fuel();
		void connect_external_fuel_source(LiquidSupply* supply);
};

ElectricalGenerator::ElectricalGenerator(void)
{
	this->fuel_tank = new Tank(25.0);
	this->engine = new PetrolEngine(fuel_tank);
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
	Mine* mine;
	LiquidSupply* fuel_tank;
	PetrolEngine* engine;
	public:
	Digger(double);
	void update(void);
	void set_mine(Mine*);
	bool dig(void);
};

Digger::Digger(double capacity): GameObject(100)
{
	this->fuel_tank = new LiquidSupply(new Tank(80.0));
	this->engine = new PetrolEngine(fuel_tank);
	this->capacity = capacity;
	this->mine = NULL;
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

GameObjectContainer objects;

int main(void)
{
	cout << "Game started!" << endl;

	GameObject* house = new GameObject(10);

	GameObject* house2 = new GameObject(200);

	objects.AddGameObject(house);
	objects.AddGameObject(house2);

	house2->set_hp(10);

	house->set_hp(200);

	cout << "House object HP: " << house->get_hp() << endl;

	// Create game objects
	Mine* new_mine = new Mine(100, 0);
	objects.AddGameObject(new_mine);

	Digger* new_digger = new Digger(2.2);
	objects.AddGameObject(new_digger);

	Tank* large_fuel_tank = new Tank(1000);
	objects.AddGameObject(large_fuel_tank);

	objects.UpdateAll();

	ElectricalGenerator* generator = new ElectricalGenerator();
	// Consume fuel from the generator internal fuel tank
	generator->consume_fuel();

	// Create a fuel pipe used to connect between the large fuel tank
	// and the electrical generator
	LiquidSupply* pipe = new LiquidSupply(large_fuel_tank);

	// Connect an external tank and consume fuel from there instead
	generator->connect_external_fuel_source(pipe);
	generator->consume_fuel();

	Tank* test = new Tank(5);

	// Attache a tank to use as fill source for the tank
	large_fuel_tank->setSource(test);

	generator->consume_fuel();

	// Fill the tank upto 10 liters from the test tank
	large_fuel_tank->fill(10);

	generator->consume_fuel();

	if (!new_digger->dig()) {
		cout << "No connected mine!" << endl;
	}

	new_digger->set_mine(new_mine);

	if (!new_digger->dig()) {
		cout << "No connected mine!" << endl;
	}

	uint16_t inputdata;

	cout << "Please write the number of objects to create: ";

	cin >> inputdata;

	cout << endl;

	while (inputdata) {
		objects.AddGameObject(new GameObject(10));
		inputdata--;
	}

	return 0;
}
