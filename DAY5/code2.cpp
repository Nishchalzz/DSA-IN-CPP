#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value n: ";
    while(true){
        cout<<"Enter the value n: ";
        cin>>n;
        if(n%10==0)
            continue;
        cout<<n<<endl;
    }
    return 0;
}

