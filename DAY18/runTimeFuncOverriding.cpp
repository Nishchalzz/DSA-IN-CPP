#include<iostream>
#include<string>
using namespace std;

class Parent{
public:
    void show(){
        cout<<"parent";
    }
};

class Child : public Parent{
public:
    void show(){
        cout<<"child";
    }
};

int main(){
    Child c1;
    c1.show();
    return 0;
}