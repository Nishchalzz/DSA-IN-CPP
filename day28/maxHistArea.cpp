#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

void printArr(vector<int> ans){
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
    cout<<endl;
}

void maxArea(vector<int> height, vector<int> ans){
    int n = height.size();
    stack<int> s;
    vector<int> nsr(n);
    vector<int> nsl(n);

    //nsl
    s.push(0);
    nsl[0] = -1;
    for(int i=1;i<height.size();i++){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);     //check stack
    }
    // printArr(nsl);

    while(!s.empty()){
        s.pop();
    }

    //nsr
    // int n = height.size();
    nsr[n-1] = n;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }

        s.push(i);
    }
    // printArr(nsr);
    int maxArea = 0;
    for(int i=0;i<n;i++){
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        maxArea = max(ht*width, maxArea);
    }
    cout<<"Max Area: "<<maxArea<<endl;
}


int main(){
    vector<int> height = {2,1,5,6,2,3};
    vector<int> ans = {0,0,0,0,0,0};
    maxArea(height, ans);
    return 0;
}