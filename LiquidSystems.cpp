
#include <iostream>
#include "LiquidSystems.hpp"

using namespace std;

LiquidSupply::LiquidSupply(LiquidSupply* source)
{
	this->source = source;
}

LiquidSupply::LiquidSupply(void)
{
	this->source = NULL;
}

double LiquidSupply::consume(double liter)
{
	if (this->source != NULL) {
		return this->source->consume(liter);
	}
}

void LiquidSupply::setSource(LiquidSupply* source)
{
	this->source = source;
}

Tank::Tank(double capacity) : LiquidSupply(this)
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

double Tank::fill(double liter)
{
	if (this->source != NULL) {
		double amount;
		if (liter > (this->capacity - this->contains)) {
			liter = (this->capacity - this->contains);
		}

		amount = this->source->consume(liter);
		this->contains += amount;
	} else {
		return 0.0;
	}
}
