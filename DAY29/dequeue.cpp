#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> d;
    d.push_front(2);
    d.push_front(1);

    d.push_back(3);
    d.push_back(4);

    d.pop_front();
    d.pop_back();

    cout<<d.front();
    cout<<d.back();

    return 0;
}