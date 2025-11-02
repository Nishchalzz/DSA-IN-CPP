#include<iostream>
#include<vector>
using namespace std;

// int lastOcc(vector<int> arr, int i, int target){
    
//     if(i==-1)
//         return -1;


//     if(arr[i]==target)
//         return i;

//     return lastOcc(arr, i-1,target);
// }

int lastOcc(vector<int> arr, int target, int i){
    if(i==arr.size())
        return -1;
    
    int idx = lastOcc(arr, target, i+1);
    if(idx==-1 && arr[i]==target)
        return i;
    return idx;

}



int main(){
    vector<int> arr = {1,2,2,3,3,3,4};
    // cout<<lastOcc(arr, arr.size()-1, 3);
    cout<<lastOcc(arr, 2, 0);
    return 0;
}