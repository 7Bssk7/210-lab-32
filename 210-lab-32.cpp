// COMSC-210 | Lab 32 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

// Constant for initial number of cars in the queue
const int ARR_SIZE = 4, LINE_SIZE = 2, SIMULATION = 20;
const int CHANCE_1 = 46, CHANCE_2 = 39;

int main(){
    srand(time(0));

    // Create a deque with SIZE cars (initial queue)
    deque<Car> lines[ARR_SIZE] = {deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE)};
    
    // Track simulation
    int count = 1; 

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

    for(int i = 0; i < SIMULATION; ++i){
        cout << "Time " << i+1 << endl;

        for(int j = 0; j < ARR_SIZE; ++j){
            int random = rand()% 100 + 1;
            cout << "Lane: " << j+1;
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
            else{
                if(random <= CHANCE_1){
                    cout << " Paid: ";
                    lines[j].front().print();
                    lines[j].pop_front();
                }
                else if( random <= CHANCE_1 + CHANCE_2){
                    Car join_car;
                    cout << " Joined: ";
                    join_car.print();
                    lines[j].push_back(join_car);
                }
                else{
                    int randomShift = rand() % 4;
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
