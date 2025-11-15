#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

bool chance(int );

int main(){

    deque<Car> list;

    for(int i = 0; i < 5; ++i){
        Car temp_car;
        list.push_back(temp_car);
    }

    for(int i = 0; i < list.size(); ++i){
        list.at(i).print();
    }

    return 0;
}

bool chance(int p){
    int random = rand()% 100 + 1;
    return (random <= p);
}