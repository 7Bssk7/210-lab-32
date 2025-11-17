// COMSC-210 | Lab 32 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

// Constant for simulation
const int ARR_SIZE = 4, LINE_SIZE = 2, SIMULATION = 20;
const int CHANCE_1 = 46, CHANCE_2 = 39;

int main(){
    srand(time(0));

    // Create 4 lanes, each a deque of Car objects, pre-populated with 2 cars
    deque<Car> lines[ARR_SIZE] = {deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE)};
    
    /*
    //Milesstone 2, test
    for (int i = 0; i <ARR_SIZE; ++i){
        cout << "Line #" << i+1 << " has " << lines[i].size() << " cars in it" << endl;
    }
    */

    // Outputs the initial queue (Milesstone 3)
    cout << "Initial queue:" << endl;
    for(int i = 0; i < ARR_SIZE; ++i){
        cout << "Lane " << i+1 << endl;
        for(int j = 0; j < lines[i].size(); ++j){
            cout << "    ";
            lines[i][j].print();
        }
    }
    cout << endl;

    // Simulation loop (runs 20 times)
    for(int i = 0; i < SIMULATION; ++i){
        cout << "Time " << i+1 << endl;

        // This loop process each lane 
        for(int j = 0; j < ARR_SIZE; ++j){
            // This code generates a random number 1–100
            int random = rand()% 100 + 1;
            cout << "Lane: " << j+1;
            // Checks if the lane is empty and then if so, 50/50 chance of new car joining
            if(lines[j].empty()){
                int randomJoin = rand() % 2;
                if( randomJoin == 1){
                    Car temp_car;
                    cout << " Joined: ";
                    temp_car.print();
                    lines[j].push_back(temp_car);
                }
                else{
                    cout << endl;
                }
            }
            // If lane has cars, apply probability rules
            else{
                // (random 1 - 46) 46% probability that front car paid the toll
                if(random <= CHANCE_1){
                    // Head car pays and leaves
                    cout << " Paid: ";
                    lines[j].front().print();
                    lines[j].pop_front();
                }
                // (random 47-85) 39% probability that the new car joined the lane
                else if( random <= CHANCE_1 + CHANCE_2){
                    // New car joins at rear
                    Car join_car;
                    cout << " Joined: ";
                    join_car.print();
                    lines[j].push_back(join_car);
                }
                // (random 86 - 100) 15% probability that the rear car of the lane switched lanes 
                else{
                    // Rear car switches to a different random lane
                    int randomShift = rand() % 4;
                    // This loop ensures different lane
                    while(randomShift == j){
                        randomShift = rand() % 4;
                    }
                    cout << " Switched: ";
                    lines[j].back().print();
                    lines[randomShift].push_back(lines[j].back());
                    lines[j].pop_back();

                }

            }
        }
        


        // This loop outputs the current state of all lanes(deque)
        for(int n = 0; n < ARR_SIZE; ++n){
            if(lines[n].empty()){
                cout << "Lane " << n+1 << " Queue: empty" << endl;
            }
            else{
                cout << "Lane " << n+1 << " Queue:" << endl;
                for(int k = 0; k < lines[n].size(); ++k){
                    cout << "    ";    
                    lines[n][k].print();

                }
            }
        }

        cout << endl;
    }

    return 0;
}
