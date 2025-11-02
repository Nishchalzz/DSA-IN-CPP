#include<iostream>
#include<string>
using namespace std;

class Print{
public:
    void show(int x){
        cout<<"int: "<<x<<endl;
    }
    void show(string str){
        cout<<"String: "<<str;
    }
};

int main(){
    Print obj;

    obj.show(9);
    obj.show("hello");

    return 0;
}