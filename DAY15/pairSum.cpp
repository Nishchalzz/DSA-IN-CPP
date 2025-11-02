#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> vec, int target){
    int st=0, end = vec.size()-1;
    vector<int> ans;
    while(st<end){

        int currsum = vec[st]+vec[end];
        if(currsum == target){
            cout<<"("<<st<<", "<<end<<")";
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if(currsum>target)
            end--;
        else
            st++;
    }
    cout<<"Not foound a  pair";
    return ans;

}


int main(){

    vector<int> vec = {2,7,11,15};
    vector<int> ans = pairSum(vec,26);
    return 0;
}