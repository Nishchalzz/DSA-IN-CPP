#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Car{
public:
    int distSq;
    int idx;

    Car(int distSq, int idx){
        this->distSq = distSq;
        this->idx = idx;
    }

    bool operator < (const Car &obj) const{
        return this->distSq > obj.distSq;      //minheap
    }
};

void kNearByCars(vector<pair<int, int>> pos, int k){
    vector<Car> cars;
    for(int i=0;i<pos.size();i++){
        int distSq = pos[i].first * pos[i].first + pos[i].second *  pos[i].second;
        cars.push_back(Car(distSq, i));
    }

    priority_queue<Car> pq(cars.begin(), cars.end()); //O(n) 

    for(int i=0;i<k;i++){  //o(klogn)
        cout<<"Car: "<< pq.top().idx<<endl;
        pq.pop(); //o(logn)
    }
}

int main(){

    vector<pair<int, int>> pos;

    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    kNearByCars(pos, 2);


    return 0;
}