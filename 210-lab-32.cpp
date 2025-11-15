// COMSC-210 | Lab 32 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

// Constant for initial number of cars in the queue
const int SIZE = 2;

int main(){
    srand(time(0));

    // Create a deque with SIZE cars (initial queue)
    deque<Car> list(SIZE);
    // Track simulation
    int count = 1; 

    // Outputs the initial queue
    cout << "Initial queue:" << endl;
    for(int i = 0; i < list.size(); ++i){
        cout << "    ";
        list.at(i).print();
    }

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

        count++;

    }
    

    return 0;
}
