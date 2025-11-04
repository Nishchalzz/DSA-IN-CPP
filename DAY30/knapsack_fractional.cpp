#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2 ){
    return p1.first>p2.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w){
    
    int ans = 0;
    double ratio;
    vector<pair<double, int>> help(val.size(), make_pair(0.0,0));
    for(int i=0;i<val.size();i++){
        ratio = val[i]/(double)wt[i];
        help[i] = make_pair(ratio, i);
    }

   

    sort(help.begin(), help.end(), compare);

  
    for(int i = 0; i<val.size();i++){
        int idx = help[i].second;
        if(wt[idx] < w){
            ans += val[idx];
            w -= wt[idx];
        }else{
            ans += help[i].first*w;
            w = 0;
            break;
        }
    }

    return ans;


}


int main(){

    vector<int> val = {60, 100, 120}; 
    vector<int> wt = {10, 20, 30};
    int w =50;

    cout<<fractionalKnapsack(val, wt, w);

    return 0;
}