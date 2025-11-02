#include<iostream>
using namespace std;

void func(int (*mat)[4], int n){
    cout<<mat<<endl;
    cout<<mat+1<<endl;
    cout<<mat+2<<endl<<endl;

    cout<<*mat<<endl;
    cout<<*(mat+1)<<endl;
    cout<<*(mat+2)<<endl;

    cout<<*(*(mat+2)+2)<<endl;
}

int main(){
    int mat[4][4]={{10,20,30,40},
    {15,25,35,45},
    {27,29,37,48},
    {32,33,39,50}};
   func(mat,4);
    return 0;
}