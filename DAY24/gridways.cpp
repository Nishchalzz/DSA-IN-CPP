#include<iostream>
#include<string>
using namespace std;

int gridways(int r, int c, int n, int m, string ans){
    //base case
    if(r==n-1 &&c==m-1){
        cout<<ans<<endl;
        return 1;
    }

    if(r>=n || c>=m){
        return 0;
    }
    //right
    int val1 = gridways(r,c+1,n,m,ans+"R");
    //down
    int val2 = gridways(r+1, c, n, m, ans+"d");
    //total
    return val1+val2;
}

int main(){

    int n=3, m=3;
    string ans = "";
    cout<<gridways(0,0,n,m,ans);

    return 0;
}