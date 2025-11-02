#include<iostream>
#include<string>
using namespace std;

class Parent{
public:
    virtual void show(){
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

    Parent *ptr;
    ptr= &c1;

    ptr->show();
    
    return 0;
}