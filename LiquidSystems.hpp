#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include "GameObject.hpp"

class LiquidSupply : public GameObject
{
	protected:
	LiquidSupply* source;
	//protected:
	//double contains;
	public:
	void setSource(LiquidSupply* source);
	LiquidSupply(LiquidSupply* source);
	LiquidSupply(void);
	virtual double consume(double liter);
	double fill(double liter);
};

class Tank : public LiquidSupply
{
	double capacity;
	double contains;
	public:
	Tank(double capacity);
	double fill(double liter);

	double consume(double liter);
};


#endif // _GAMEOBJECT_HPP_
