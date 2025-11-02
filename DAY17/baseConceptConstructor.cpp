#include<iostream>
#include<string>
using namespace std;

class Student{
    string name="harish";
    float cgpa=9.3;
public:
    void getperc(){
        cout<<cgpa*100;
    }
    //setter
    void setCgpa(float val){
        cgpa = val;
    }
    //getter
    float getcgpa(){
        return cgpa;
    }
};

class Car{
    string name;
    string col;
    
public:
    int *mileage;
    Car(){
        cout<<"without para";
    }
    Car(string name, string col){
        cout<<"with para\n";
        this->name = name;
        this->col = col;
        mileage = new int;
        *mileage = 12;
    }
    //shallow copy, dynamic allocate is pointing same
    // Car(Car &Original){
    //     cout<<"copy constructor, copying to new\n";
    //     this->name = Original.name;
    //     this->col = Original.col;
    //     mileage = Original.mileage;
    // }
    //deep copy, dynamic allocated is pointing different
    Car(Car &Original){
        cout<<"copy constructor, copying to new\n";
        this->name = Original.name;
        this->col = Original.col;
        mileage = new int;
        *mileage = *Original.mileage;
    }
    //getter
    string getName(){
        return name;
    }
    string getCol(){
        return col;
    }

    ~Car(){
        cout<<"Deleting obj\n";
        if(mileage != NULL){
            delete mileage;
            mileage = NULL;
        }
    }

};

int main(){

    // Student s1;
    // s1.setCgpa(10);
    // cout<<s1.getcgpa();
    Car c1("maruti", "white");
    Car c2(c1);
    cout<<c2.getCol()<<endl;
    cout<<c2.getName()<<endl;
    cout<<*c2.mileage<<endl;
    // *c2.mileage=9;
    // cout<<*c1.mileage<<endl;
    // cout<<*c2.mileage;
    return 0;
}