#include<iostream>
using namespace std;

int tiling(int n){
    if(n==0 || n==1)
        return 1;

    //horizontal
    int ans1 = tiling(n-2);
    //vertical
    int ans2=tiling(n-1);

    return ans1+ans2;
}

int main(){
    cout<<tiling(4);
    return 0;
}