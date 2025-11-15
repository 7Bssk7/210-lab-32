#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int SIZE = 2;

bool chance(int );

int main(){

    deque<Car> list(SIZE);

    cout << "Imitial queue:" << endl;
    for(int i = 0; i < list.size(); ++i){
        list.at(i).print();
    }

    /*
    while(!(list.empty())){
        if(chance(55)){

        }
        else if(chance(45)){

        }
    }
    */

    return 0;
}


bool chance(int p){
    int random = rand()% 100 + 1;
    return (random <= p);
}