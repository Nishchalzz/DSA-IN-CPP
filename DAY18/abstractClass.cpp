#include<iostream>
#include<string>
using namespace std;
//abstract func
class Shape{
public:
    virtual void draw()=0;//pure virtal func or abstract func
};

class Square:public Shape{
public:
    void draw(){
        cout<<"square draw";
    }
};

class Circle:public Shape{
public:
    void draw(){
        cout<<"circle draw";
    }
};

int main(){
   
    Square s;
    s.draw();
    Circle c;
    c.draw();
    return 0;
}