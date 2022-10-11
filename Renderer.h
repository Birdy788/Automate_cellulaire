#pragma once
#include "World.h"
#include <chrono>
#include <thread>

class Renderer
{
public :
	Renderer() {};
	void outputState(World &world);
};

