#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second>p2.second;
}

int getprofit(vector<pair<int, int>> job){

    sort(job.begin(), job.end(), compare);

    int safedeadline = 2;

    int profit = job[0].second;
    
    for(int i=1;i<job.size();i++){
        if(job[i].first >= safedeadline){
           profit += job[i].second;
           safedeadline++; 
        }
    }
    return profit;

}

int main(){
    int n=4;
    vector<pair<int, int>> job(n, make_pair(0,0));
    job[0]=make_pair(4,20);
    job[1]=make_pair(1,10);
    job[2]=make_pair(1,40);
    job[3]=make_pair(1,30);
   
    cout<<getprofit(job);

    return 0;
}