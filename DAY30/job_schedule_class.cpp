#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job{
public:

    int idx;
    int deadline;
    int profit;


    Job(int idx, int deadline,int profit){
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};


int getprofit(vector<pair<int, int>> job){
    vector<Job> jobs;
    int n = job.size();

    for(int i=0;i<n;i++){
        jobs.emplace_back(i, job[i].first, job[i].second);
    }
    
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.profit>b.profit;
    });

    int safedeadline = 2;
    int profit = jobs[0].profit;
    cout<<"SELECTING JOB "<<jobs[0].idx<<endl;

    for(int i=1;i<n;i++){
        if(jobs[i].deadline >= safedeadline){
            cout<<"SELECTING JOB "<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
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