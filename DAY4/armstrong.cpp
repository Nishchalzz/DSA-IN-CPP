#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"ENter the num: "<<endl;
    cin>>num;
    int sum =0;
    int num2 = num;
    int rem;
    while(num!=0){
        rem = num%10;
        sum = sum + (rem*rem*rem);
        num = num/10;
    }

    if(sum == num2)
        cout<<"it is armstrong";
    else
        cout<<"it is not armstrong";

    return 0;
}