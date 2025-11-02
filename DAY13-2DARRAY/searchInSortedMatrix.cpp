#include<iostream>
using namespace std;

bool stairCaseSearch(int mat[][4],int key, int n, int m){
    int row = 0, col = m-1;
    while(row<n && col>=0){
        if(mat[row][col]==key){
            cout<<"found at ("<<row<<","<<col<<")";
            return true;
        }
        else if(mat[row][col]<key){
            row++;
        }else
            col--;
    }
    cout<<"not found";
    return false;
}

int main(){
    int mat[4][4]={{10,20,30,40},
    {15,25,35,45},
    {27,29,37,48},
    {32,33,39,50}};
    stairCaseSearch(mat, 51,4,4);
    return 0;
}