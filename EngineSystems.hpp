/**
 * \file EngineSystems.hpp
 */
#include "game_object.hpp"
#include "liquid_systems.hpp"

class PetrolEngine : public GameObject
{
	LiquidSupply* fuel_supply;
	double fuel_consuption;
	bool running;

	public:
		PetrolEngine(LiquidSupply* fuel_supply, double fuel_consumption);
		bool Start(void);
		bool Stop(void);
		bool IsRunning(void);
		void update(void);
};
