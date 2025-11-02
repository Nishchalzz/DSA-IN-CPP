#include<iostream>
#include<climits>
using namespace std;

void stockProfit(int *arr, int n){
    int bestBuy[100000]; 
    bestBuy[0]=INT_MAX;
    for(int i=1;i<n;i++){
        bestBuy[i]=min(bestBuy[i-1],arr[i-1]);
    }
    int maxprofit=0;
    for(int i=0;i<n;i++){
        int currprofit = arr[i]-bestBuy[i];
        maxprofit = max(currprofit,maxprofit);
    }
    cout<<"max profit: "<<maxprofit;
}

int main(){
    int arr[6]={7,6,5,4,3,2};
    int n = sizeof(arr)/sizeof(int);

    stockProfit(arr, n);

    return 0;
}