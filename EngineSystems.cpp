/**
 * \file EngineSystems.cpp
 */

#include "EngineSystems.hpp"

PetrolEngine::PetrolEngine(LiquidSupply* fuel_supply, double fuel_consumption = 0.5)
{
	this->fuel_supply = fuel_supply;
	this->fuel_consuption = fuel_consumption;
	this->running = false;
}

bool PetrolEngine::Start()
{
	this->running = true;
	return true;
}

void PetrolEngine::update()
{
	if (this->IsRunning()) {
		this->fuel_supply->consume(this->fuel_consuption);
	}
}

bool PetrolEngine::IsRunning()
{
	return this->running;
}