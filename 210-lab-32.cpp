#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int SIZE = 2;

bool chance(int );

int main(){

    deque<Car> list(SIZE);
    int count = 1;

    cout << "Imitial queue:" << endl;
    for(int i = 0; i < list.size(); ++i){
        list.at(i).print();
    }

    while(!(list.empty())){
        cout << "Time: " << count << " Operation: ";
        if(chance(55)){
            cout << " Car paid: ";
            list.front().print();
            list.pop_front();
        }
        else if(chance(45)){
            Car temp_car;
            cout << " Joined lane: ";
            temp_car.print();
            list.push_back(temp_car);
            cout << endl;
        }
        else{
            cout << endl;
        }
        cout << "Queue: " << endl;
        if(!(list.empty())){
            for(int i = 0; i < list.size(); ++i){
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


bool chance(int p){
    int random = rand()% 100 + 1;
    return (random <= p);
}