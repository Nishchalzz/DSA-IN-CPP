#include<iostream>
using namespace std;


int main(){
    int rows, cols;
    cout<<"Enter rows and cols: ";
    cin>>rows>>cols;

    int* *mat = new int*[rows];
    for(int i=0;i<rows;i++){
        mat[i] = new int[cols];
    }
    int x=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            mat[i][j]=x++;
            cout<<mat[i][j];
        }
        cout<<endl;
    }

    cout<<mat[2][2]<<endl<<*(*(mat+2)+2);

    return 0;
}