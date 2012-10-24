/**
 * \file EngineSystems.hpp
 */
#include "GameObject.hpp"
#include "LiquidSystems.hpp"

class PetrolEngine : public GameObject
{
	LiquidSupply* fuel_supply;
	double fuel_consuption;
	bool running;

	public:
		PetrolEngine(LiquidSupply* fuel_supply, double fuel_consumption = 0.5);
		bool Start(void);
		bool Stop(void);
		bool IsRunning(void);
		void update(void);
};
