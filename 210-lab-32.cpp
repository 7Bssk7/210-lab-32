// COMSC-210 | Lab 32 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

// Constant for initial number of cars in the queue
const int ARR_SIZE = 4, LINE_SIZE = 2;

int main(){
    srand(time(0));

    // Create a deque with SIZE cars (initial queue)
    deque<Car> lines[ARR_SIZE] = {deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE), deque<Car>(LINE_SIZE)};
    
    // Track simulation
    int count = 1; 

    //Milesstone 2, test

    for (int i = 0; i <ARR_SIZE; ++i){
        cout << "Line #" << i+1 << " has " << lines[i].size() << " cars in it" << endl;
    }
    // Outputs the initial queue
    cout << "Initial queue:" << endl;
    for(int i = 0; i < ARR_SIZE; ++i){
        cout << "Lane #" << i+1 << endl;
        for(int j = 0; j < lines[i].size(); ++j){
            cout << "    ";
            lines[i][j].print();
        }
    }

    /*
    // Run simulation until the deque is empty
    while(!(list.empty())){
        cout << "Time: " << count << " Operation: ";
        // Generate a random number to decide the operation
        int random = rand()% 100 + 1;
        // checks if (55% chance): car at front pays and leaves
        if(random <= 55){
            cout << "Car paid: ";
            list.front().print();
            list.pop_front();
        }
        // if random > 55% -> 45%, so checks if (45% chance) new car joins the back of the deque
        else{
            Car temp_car;
            cout << "Joined lane: ";
            temp_car.print();
            list.push_back(temp_car);
        }

        // Outputs the current deque
        cout << "Queue: " << endl;
        if(!(list.empty())){
            for(int i = 0; i < list.size(); ++i){
                cout << "    ";
                list.at(i).print();
            }
        }
        else{
            cout << "    Empty" << endl;
        }

        // Increment counter of operations
        count++;

    }
    */    
    

    return 0;
}
