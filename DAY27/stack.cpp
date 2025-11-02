#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class Stack{
    vector<T> vec;
public:
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return;
        }
        vec.pop_back();
    }
    T top(){
        // if(isEmpty()){
        //     cout<<"Stack is empty";
        //     return -1;
        // }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size()==0;
    }
    void print(){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<"\t";
        }
    }
};

int main(){
    Stack<string> s;
    s.push("hello");
    s.push("hi");
    s.push("how are you");
    s.print();
    s.pop();
    s.print();
    cout<<endl<<s.top()<<endl;
    cout<<s.isEmpty();
    return 0;
}