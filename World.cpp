#include "World.h"

World::World()
{
	/*
	Initialize the world's parameters

		input:

		output:
	*/

	_height = 0;
	_width = 0;
	_iterations = 0;


	_currentGrid = new vector<vector<int>>; //we create the 2D vector of integer values that will
											//represent the world grid
	_nextGrid = new vector<vector<int>>; //we create the 2D vector of integer values for the grid copy
}

World::~World()
{
	/*
	Clears the memory used to store the world's grid data

		input:

		output:

	*/

	delete _currentGrid;
	delete _nextGrid;
}

void World::setWorldParameters(int height, int width, int iterations)
{
	/*
	Updates the world's parameters
		
	input:
		hight (int) : the desired world's hight	
		width (int) : the desired world's width
		iterations (int) : the desired number of the world updates
	output:

	*/

	_height = height;
	_width = width;
	_iterations = iterations;
}



void World::generateWorld()
{
	/*
		Initialize the world's grid with random state

		input:

		output:

	*/

	//the two lines below are useful when we try to regenerate the world an other time after the it's first initialization
	_currentGrid->clear();
	_nextGrid->clear();

	vector<int> tmp; 

	//with this loop, we are going to go through all the world grid and set the state of each cell
	// 
	//the approach that is going to be used to do so is to edit the grid line by line
	for (int i = 0; i < _height; i++) {//the integer i is going to represent the index of the line we will be working on
		tmp.clear();
		for (int j = 0; j < _width; j++) { //the integer j will represent the index of the column we are working on
			tmp.push_back(rand() % 2); //with this expression we set the state of the cell(i, j) (whose coordinates are 
									   //(i, j) later in the world grid) by assigning it randomly the value 0 or 1
									   //
									   //a cell having a 0 value means it's dead, and when it's 1 it means it's alive.
		}
		_currentGrid->push_back(tmp);//we put the line that have been generated in the world grid
		_nextGrid->push_back(tmp);//we put the line that have been generated in the copy of the world grid
	}
}

int World::getIterationsCount()
{
	/*
		Returns the number of times the world grid state will be updated

		input:

		output:
			_iterations (int) : private member of the World class

	*/

	return _iterations;
}
