#include <time.h>
#include <chrono>
#include <thread>
#include "World.h"
#include "Renderer.h"
#include "ComputeEngine.h"

/*
How this program works, step by step :
1 - The user types the parameters of the simulation;
2 - The program start computing the world states and rendering them;
3 - If the program finds that two consecutive computed world states are the same then the simulation stops. 
If not, we continues computing for the numbers of times specified by the user;
4 - After the simulation ends, the user has the ability to restart it or to terminate the program.
*/

using namespace std;

//(Responce to the Bonus question of the test can be found at the end)

int main()
{
    cout << "+----------------------------------------------------------------------------------------+" << endl;
    cout << "+                                                                                        +" << endl;
    cout << "+ A cellular automaton (with fixed borders) simulation program, done by : Anouar Walziki +" << endl;
    cout << "+                                                                                        +" << endl;
    cout << "+----------------------------------------------------------------------------------------+" << endl;
    this_thread::sleep_for(std::chrono::milliseconds(2000));

    int height = 0;
    int width = 0;
    int iterations = 0;

    World* world = new World(); //the world object that will holds the cells grid
    ComputeEngine* computeEngine = new ComputeEngine(); //the engine that will compute each new generation of the world state
    Renderer* renderer = new Renderer(); //will handle the output and the visualization of the world states

    char choice = 'Y'; //to give the ability to restart the program after the simulation ends

    while (choice == 'Y')
    {
        cout << "\033c"; //cleans and resets the cursor if using a Windows OS
        srand(time(0)); //ensure that rand() fonction which will be used later will generate new pseudo-random numbers
                        //each time we run the program

        cout << "Welcome !" << endl;
        cout << endl;

        cout << "To start the simulation , please enter the following parameters : (/!/ please type only integer values)  " << endl;
        cout << "World's height : ";
        cin >> height;
        cout << "World's width: ";
        cin >> width;
        cout << "World generations count (how many times the world state will be updated) : ";
        cin >> iterations; //This option gives the ability to safely test the code for a limited amount of generation of the current world.
                           // By removing this option, the only way to do this will be to force stop the program. 
                           // This will lead to memory leak as the pointers that will be used will not be deleted

        world->setWorldParameters(height, width, iterations);

        world->generateWorld(); 

        int currentIter = 0; //the number of the current generation of the world

        while (world->getIterationsCount() > 0) {//we check if there is still world states to be computed
            cout << "Iteration number : " << ++currentIter << endl;
            cout << endl;
            if (currentIter == 1) { 
                //shows the first world state before starting the computing engine
                renderer->outputState(*world);
                cout << "\033c";
            }
            else {
                computeEngine->nextIteration(*world);
                computeEngine->UpdateWorld(*world);
                renderer->outputState(*world);
                this_thread::sleep_for(std::chrono::milliseconds(200));
                if (world->getIterationsCount() != 0) {//we check if it's the last world state computed.
                                                       //If it's the case, we don't clear the console so that the final world state
                                                       //will still be visible to the user at the end of the simulation

                    cout << "\033c"; //it's not the final visualization of the world state, so we clear the console
                }
            }
        }

        if (currentIter == iterations) {//if true, it means that we did compute all world states as many as the user wanted
            cout << "\nSimulation ended ! The number of world states to be visualized have all been rendered !" << endl;
        }
        else {//here, the world did converge to a stable state
            cout << "The world have converged to a stable state ! Simulation ended ! (further generation of the current world are the same)" << endl;
        }
        
        //below, after the simulation ends, the user is given the option to restart the program
        cout << "\nDo you want to restart the program ? (type <Y> for yes and any other character for no) " << endl;
        cout << "Your choice (/!/ please type only one character) : ";
        cin >> choice;
    }

    //user chosen to terminate the program

    delete world;
    delete computeEngine;
    delete renderer;

    cout << "\033c";
    cout << "Thank you for using this program !" << endl;
    return 0;
}


/*
Bonus question response:

To simulate an infinite grid without an infinite growth of memory, we are first going to create a grid with fixed borders. Then
after, in the computation part, we will consider that each border of the grid is linked to the border in front of it.
Trying to imagine the grid as a paper ,as an example , will make it easier to inderstand this situation.
This way we will not influence on logic of the computation as each cell will have a random state and rondom neighbors.

*/