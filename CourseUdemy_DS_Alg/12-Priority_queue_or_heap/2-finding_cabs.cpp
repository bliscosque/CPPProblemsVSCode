//given N cartesian points in a 2D plane, each represents the location of the cab.
//You're standing at origin, you want to know the names of nearest k cars.

//distancia euclidiana ---> d = (x^2+y^2)^(1/2)

//input
//N=5, K=3  --> 5 carros, precisa encontrar os 3 mais proximos
//C1 1 1
//C2 2 1
//C3 3 2
//C4 0 1
//C5 2 3

//output
//C4
//C1
//C2

//sol1 -> sort da matriz toda e imprimir n primeiros elementos
//na verdade, nao precisa fazer sort de toda a matriz, ja que precisamos apenas dos k primeiros elementos
//sol2 -> com um heap de todos os carros, podemos fazer apenas pop dos k primeiros elementos

//sol3 -> criar um heap apenas com 3 elementos. Se o elemento for maior, ja remove este elemento (como o heap é menor, sera mais rapido)

#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Car{
public:
    string id;
    int x,y;
    Car(string id, int x, int y) {
        this->id=id;
        this->x=x;
        this->y=y;
    }
    int dist () const{
        return x*x + y*y; //square of the dist
    }

};

class CarCompare{
public:
    bool operator()(Car A, Car B){
        return A.dist() < B.dist(); //max heap comp <
    }
};

bool distCompare(Car A, Car B) {
    return A.dist() < B.dist();
}

void printNearestCars(vector<Car> cars, int k) {
    //create a max heap of cars and insert 3 firt elements to this heap
    priority_queue<Car, vector<Car>, CarCompare> max_heap (cars.begin(),cars.begin()+k);

    for (int i=k;i<cars.size();i++) {
        auto car = cars[i];
        if (car.dist() < (max_heap.top()).dist()) {
            //removes the root node (largest)
            max_heap.pop();
            max_heap.push(car);
        }
    }

    //print all the cars inside heap
    vector<Car> output;
    while(!max_heap.empty()) {
        output.push_back(max_heap.top()); 
        max_heap.pop();
    }

    sort(output.begin(),output.end(), distCompare); //or just reverse the vector 
    for (auto car:output) {
        cout << car.id << endl;
    }

    return;


}

int main() {
    int N=5, k=3;

    vector<Car> cars;

    Car C1("C1",1,1);
    Car C2("C2",2,1);
    Car C3("C3",3,2);
    Car C4("C4",0,1);
    Car C5("C5",2,3);
    cars.push_back(C1);
    cars.push_back(C2);
    cars.push_back(C3);
    cars.push_back(C4);
    cars.push_back(C5);
    printNearestCars(cars,k);

    return 0;
}