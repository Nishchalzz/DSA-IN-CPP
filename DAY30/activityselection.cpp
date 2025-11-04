#include<iostream>
#include<vector>
using namespace std;

int actSelect(vector<int> s, vector<int> e){
    int currEnd = e[0];
    int count = 1;
    cout<<"Selected activity0\n";
    for(int i=1;i<s.size();i++){
        if(s[i]>=currEnd){
            cout<<"Selected activity"<<i<<endl;
            count++;
            currEnd = e[i];
        }
    }
    return count;
}

int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout<<actSelect(start, end);
    return 0;
}