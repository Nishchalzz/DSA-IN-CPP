#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}

int maxChainLen(vector<pair<int, int>> activity){

    sort(activity.begin(), activity.end(), compare);

    int currEndTime = activity[0].second;
    int count = 1;
    
    for(int i=1;i<activity.size();i++){
        if(currEndTime<activity[i].first){
            count++;
            currEndTime = activity[i].second;
        }
    }

    return count;

}

int main(){
    vector<pair<int, int>> activity(5, make_pair(0,0));
    activity[0] = make_pair(5,24);
    activity[1] = make_pair(39,60);
    activity[2] = make_pair(5,28);
    activity[3] = make_pair(27,40);
    activity[4] = make_pair(50,90);


    cout<<maxChainLen(activity);

    return 0;
}