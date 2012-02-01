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

GameObject::GameObject(int hp)
{
	this->set_hp(hp);
	this->hp_init = hp;
	cout << "New game object created. HP: " << hp << endl;
}
