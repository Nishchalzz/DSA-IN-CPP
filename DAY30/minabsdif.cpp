#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

    vector<int> a = {4,1,8,7};
    vector<int> b = {2,3,6,5};

    int count = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0;i<a.size();i++){
        count += abs(a[i]-b[i]);
    }

    cout<<count;


    return 0;
}