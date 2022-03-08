#pragma once
#include <iostream>
#include <vector>

using namespace std;

class World
{
public:
	World();
	~World(); 
	void setWorldParameters(int height, int width, int iterations);
	void generateWorld();
	int getIterationsCount();
	
private:
	int _height; //the hight of the world's grid
	int _width; //the width of the world's grid
	int _iterations; //how many times the world grid state will be updated

	/*
		So that the world's grid generation will only depend on the previous one, we have to not edit its current state
		while doing the computing part. Results of the computation have to be saved in another grid, which we will call later
		the copy grid. Then after, we can then copy back the results in the original grid

		The grid data will be stored in a vector variable so that it can be resized when needed
	*/
	vector<vector<int>> *_currentGrid; //the grid to be computed
	vector<vector<int>>* _nextGrid; //the grid where we put the generation result. It's the copy grid

	friend class Renderer;//for the Renderer class to access private members of the World class
	friend class ComputeEngine;//for the ComputeEngine class to access private members of the World class
};

