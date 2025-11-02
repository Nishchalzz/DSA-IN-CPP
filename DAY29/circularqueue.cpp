#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int *arr;
    int capacity;
    int current;
    int f,r;
public:

    Queue(int capacity){
        this->capacity = capacity;
        f=0;
        r = -1;
        arr = new int[capacity];
        current = 0;
    }

    void push(int data){
        if(current==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }

        r = (r+1)%capacity;
        arr[r]=data;
        current++;

    }

    void pop(){
        if(empty()){
            cout<<"QUEUE is empty"<<endl;
            return;
        }

        f = (f+1)%capacity;
        current--;
    }

    int front(){
        if(empty()){
            cout<<"QUEUE is empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return current == 0;
    }
    void printRear(){
        cout<<arr[r]<<endl;
    }

};

int main(){
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.push(5);
    cout<<q.front()<<endl;
    q.printRear();
    return 0;
}