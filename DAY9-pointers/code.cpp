#include<iostream>
using namespace std;

int main(){
    int a = 54;
    int *ptr = &a;

    float pi = 3.14;
    float *ptr2 = &pi;

    float **pptr = &ptr2;

    // cout<<&a<<" = "<<ptr<<endl<<&pi<<" = ";
    // cout<<&ptr2<<" = "<<pptr<<endl;
    // *ptr = 19;
    // cout<<ptr<<endl<<*ptr<<endl;
    // cout<<a;

    int *ptr3 = NULL;
    cout<<ptr3;

    return 0;
}