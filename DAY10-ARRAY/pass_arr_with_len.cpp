#include<iostream>
using namespace std;

void func(int arr[],int n){ 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(int);
    func(arr,n); //always pass arr size along with arr bcz arr in func is a pointer it doesnt know the last eleement
    return 0;
}
 
