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

	cout << "Object: " << this->getObjectID() << " has decreased HP by " << hp << endl;

	return this->hp;
}

int GameObject::increase_hp(int hp)
{
	this->hp += hp;
	return this->hp;
}

uint16_t GameObject::getObjectID(void)
{
	return this->id;
}

void GameObject::setObjectID(uint16_t id)
{
	this->id = id;
}

void GameObject::update(void)
{
	this->decrease_hp(1);
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

uint16_t GameObjectContainer::AddGameObject(GameObject *object)
{
	this->objects[this->pointer] = object;

	object->setObjectID(pointer++);

	return object->getObjectID();
}

void GameObjectContainer::RemoveGameObject(uint16_t id)
{
	this->objects[id] = NULL;
}

void GameObjectContainer::UpdateAll(void)
{
	uint16_t local_pointer = pointer;

	while (local_pointer--) {
		if (objects[local_pointer] != NULL) {
			this->objects[local_pointer]->update();
		}
	}
}

GameObjectContainer::GameObjectContainer()
{
	this->pointer = 0;
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

