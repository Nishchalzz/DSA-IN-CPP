#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Student{
public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
    }


};


int main(){

    priority_queue<Student> pq;

    pq.push(Student("arun", 99));
    pq.push(Student("rohan", 80));
    pq.push(Student("sushant", 45));

    while(!pq.empty()){
        cout<<pq.top().name<<"  "<<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}