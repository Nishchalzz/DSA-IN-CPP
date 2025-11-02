#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    string name;
    int age;


};

class Student:public Person{
public:
    string studentID;

    Student(string n, int a, string sid){
        name=n;
        age=a;
        studentID=sid;
    }

    void displayStudentInfo( ){
        cout<<name<<endl<<age<<endl<<age<<studentID<<endl;

    }

};

class Parent {
public:
    Parent(int x) { cout << "Parent constructor: " << x << endl; }
};
class Child : public Parent {
public:
    Child(int x) : Parent(x) { 
        cout << "Child constructor\n"<<x;
     } 
};


int main(){
    Student student("Alice", 20, "S12345");
    student.displayStudentInfo();
    Child c(42);

    return 0;
}