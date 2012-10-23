#include <stdint.h>

#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

class GameObject {
	int hp;
	int hp_init;
	uint16_t id;

	public:
		GameObject(int);
		GameObject();
		void set_hp(int);
		int get_hp(void);
		void update(void);
		int increase_hp(int hp);
		int decrease_hp(int);
		void setObjectID(uint16_t);
		uint16_t getObjectID(void);
};

class GameObjectContainer {
	GameObject* objects[100];
	uint16_t pointer;

	public:
		GameObjectContainer();
		uint16_t AddGameObject(GameObject*);
		void RemoveGameObject(uint16_t id);
		void UpdateAll(void);
};

class Mine: public GameObject {
	double size;
	public:
		Mine(int, double);
		void increase_size(double);
};

#endif /* GAME_OBJECT_H_INCLUDED */
