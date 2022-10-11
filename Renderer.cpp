#include "Renderer.h"


void Renderer::outputState(World &world)
{
	/*
	Handles the output and the visualization of the world state

	input:
		world (World) : the world object that contains the grid the be rendered
	output:

	*/

	if (world._iterations != 0) { //we check if there is still a world state to be rendered
		for (int i = 0; i < world._height; i++) {
			for (int j = 0; j < world._width; j++) {
				if ((*world._nextGrid)[i][j] == 1) { //we check if cell of the grid whose coordinates are (i, j) is alive
					cout << "O ";
				}
				else { //if the current cell is dead
					cout << "- ";
				}
			}
			cout << endl;
		}
		world._iterations--; //after visualizing the world state that have been computed, 
						     //we update the numbers of generations of the world left to be computed and rendered
	}
	
}
