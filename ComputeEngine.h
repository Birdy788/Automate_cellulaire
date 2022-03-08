#pragma once
#include "World.h"

class ComputeEngine
{
public:
	ComputeEngine() {};
	void nextIteration(World &world);
	void UpdateWorld(World& world);
};

