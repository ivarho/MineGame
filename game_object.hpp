
class GameObject {
	int hp;
	int hp_init;

	public:
	GameObject(int);
	void set_hp(int);
	int get_hp(void);
	void update(void);
	int increase_hp(int hp);
	int decrease_hp(int);
};

class Mine: public GameObject {
	double size;
	public:
	Mine(int, double);
	void increase_size(double);
};

