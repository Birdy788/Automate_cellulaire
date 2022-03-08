#include "ComputeEngine.h"

void ComputeEngine::nextIteration(World& world)
{
	/*
	Returns the World class private member "_iterations"

	input:
		world (World) : the world object that contains the grid the be computed
	output:

    */

	//in this loop, where are going to go through all the cells of the grid to check if they will survive or become alive
	// 
	//we will consider for cells at the borders of the grid, that their neighbors outside are all dead
	for (int i = 0; i < world._height; i++) {
		for (int j = 0; j < world._width; j++) {

			//checking for survivors in the 8 nearby cells to the cell(i, j)
			int aliveCells_n = 0; //will hold the number of alive cells around the cell(i,j)
			for (int k = i - 1; k < i + 2; k++) {
				if (k >= 0 && k < world._height) { //when the cell(i, j) is located in the borders of the world grid, this condition
												  //prevent the program to try accessing a zone that is not inside the grid 
					for (int m = j - 1; m < j + 2; m++) {
						if (m >= 0 && m < world._width) {//when the cell(i, j) is located in the borders of the world grid, this condition
														 //prevent the program to try accessing a zone that is not inside the grid 
							if ((*world._currentGrid)[k][m] == 1 && !(k==i && m==j)) {//the second part of this test
																					  //is used to not include the state of
																					  //cell(i, j)
								aliveCells_n++;
							} 
						}
					}
				}
			}
			
			if ((*world._currentGrid)[i][j] == 1){ //check if current cell is alive
				if (aliveCells_n < 2) { 
					(*world._nextGrid)[i][j] = 0; //changing cell state to "dead" due to under-population
				}
				else if (aliveCells_n > 3) {
					(*world._nextGrid)[i][j] = 0; //changing cell state to "dead" due to over-population
				}
			}
			else {
				if (aliveCells_n == 3) {
					(*world._nextGrid)[i][j] = 1; //changing cell state to "alive" to simulate reproduction
				}
			}
		}

	}

	if (*world._currentGrid == *world._nextGrid) { //we check if the previous and the future world states are the same
		world._iterations = 1; //one state was left to render, it's the world's final stable state
	}
}

void ComputeEngine::UpdateWorld(World& world)
{
	/*
	Copies the engine computation result to the world's grid to be rendered

	input:
		world (World) : the world object that contains the grid the be computed
	output:

	*/

	for (int i = 0; i < world._height; i++) {

		for (int j = 0; j < world._width; j++) {
			(*world._currentGrid)[i][j] = (*world._nextGrid)[i][j];
		}

	}
}
