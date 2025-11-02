#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreater(vector<int> arr, vector<int> ans){
    stack<int> s;
    int idx = arr.size()-1;
    s.push(arr[idx]);
    ans[idx]=-1;

    for(int i=idx-1;i>=0;i--){
        int curr = arr[i];
        while(!s.empty() && curr>=s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }

        s.push(arr[i]);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
}

int main(){
    vector<int> arr={6,8,0,1,3};
    vector<int> ans={0,0,0,0,0};

    nextGreater(arr, ans);

    return 0;
}