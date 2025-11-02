#include<iostream>
using namespace std;

int main(){
    // int a,b;
    // cout<<"Enter two numbers: "<<endl;
    // cin>>a>>b;
    // if(a>b){
    //     cout<<"A is larger";
    // }else if(b>a){
    //     cout<<"B is larger";
    // }else{
    //     cout<<"Both are same";
    // }
    // int n;
    // cout<<"Enter a number";
    // cin>>n;
    // if(n%2==0)
    //     cout<<"Number is even";
    // else
    //     cout<<"Number is odd";

    // float income;
    // cout<<"Enter the income: in L";
    // cin>>income;

    // if(income<5){
    //     cout<<income;
    // }else if(income<=10){
    //     cout<<(income+income*0.2);
    // }else{
    //     cout<<(income+income*0.3);
    // }

    // int a,b,c;
    // cout<<"Enter a b c"<<endl;
    // cin>>a>>b>>c;

    // if(a>b){
    //     if(a>c){
    //         cout<<a;
    //     }else{
    //         cout<<c;
    //     }
    // }else{
    //     if(b>c){
    //         cout<<b;
    //     }else{
    //         cout<<c;
    //     }
    // }
    int age;
    cout<<"Enter the age: "<<endl;
    cin>>age;
    bool isAdult = (age>=18)?true:false;
    cout<<isAdult;
    return 0;
}