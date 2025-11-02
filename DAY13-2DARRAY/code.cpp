#include<iostream>
using namespace std;

void funcCount(int arr[][3], int n, int m, int key){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){
                count++;
            }
        }
    }
    cout<<count;
}

void sumRow(int arr[][3], int n, int m, int row){
    int sum = 0;
    for(int j=0;j<m;j++){
        sum += arr[row][j];
    }
    cout<<sum<<"  ";
}

void transpose(int arr[][3], int n, int m){
    int transpose[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            transpose[j][i] = arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[2][3] = { {4,7,8}, {8,8,7} };
    int nums[3][3] = { {1,4,9}, {11,4,3}, {2,2,3} };
    int n=3,m=3;
    // funcCount(arr, n, m, 8);
    // sumRow(nums,n,m,2);
    transpose(arr, 2, 3);

    return 0;
}