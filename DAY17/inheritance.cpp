#include<iostream>
#include<string>
using namespace std;


class Animal{
public: 
    string col="black";

    void eat(){
        cout<<"I eat";
    }

    void breath(){
        cout<<"I breath";
    }
};

class Fish : public Animal{
public: 
    string fin;

    void swims(){
        cout<<"I swim";
    }

};

class Teacher{
public:
    float salary;
    string name;
};

class Student{
public:
    float cgpa;
    int id;
};

class TA: public Teacher, public Student{
public:
    TA(){
        salary=19000;
        name="hari";
        cgpa=9.8;
        id=9;
    }

};



int main(){
    // Fish f;
    // cout<<f.col;

    TA ta;
    cout<<ta.salary<<endl<<ta.cgpa<<endl<<ta.name;
    return 0;
}