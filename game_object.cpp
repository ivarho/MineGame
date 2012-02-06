#include "game_object.hpp"
#include <iostream>

using namespace std;

void GameObject::set_hp(int hp)
{
	this->hp = hp;
}

int GameObject::get_hp(void)
{
	return this->hp;
}

int GameObject::decrease_hp(int hp)
{
	this->hp -= hp;
	return this->hp;
}

int GameObject::increase_hp(int hp)
{
	this->hp += hp;
	return this->hp;
}

GameObject::GameObject()
{
	this->set_hp(100);
	this->hp_init = 100;
}

GameObject::GameObject(int hp)
{
	this->set_hp(hp);
	this->hp_init = hp;
	cout << "New game object created. HP: " << hp << endl;
}

Mine::Mine(int hp, double size): GameObject(hp)
{
	this->size = size;
}

void Mine::increase_size(double size)
{
	this->size += size;
	cout << "Size of mine increased to: " << this->size << " m3" << endl;
}

