#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int SIZE = 2;

int main(){
    srand(time(0));

    deque<Car> list(SIZE);
    int count = 1;

    cout << "Initial queue:" << endl;
    for(int i = 0; i < list.size(); ++i){
        cout << "    ";
        list.at(i).print();
    }

    while(!(list.empty())){
        cout << "Time: " << count << " Operation: ";
        int random = rand()% 100 + 1;
        if(random <= 55){
            cout << "Car paid: ";
            list.front().print();
            list.pop_front();
        }
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
