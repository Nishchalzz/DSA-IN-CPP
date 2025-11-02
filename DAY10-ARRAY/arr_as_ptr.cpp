#include<iostream>
using namespace std;

void func(int arr[]){ 
    arr[0]=1010;
}
//both are same
void func2(int *ptr){
    ptr[0]=100;
}

int main(){
    int arr[] = {1,2,3};
    
    func(arr); //arr name is passed as ptr
    func2(arr);

    cout<<arr[0];
    return 0;
}
 
