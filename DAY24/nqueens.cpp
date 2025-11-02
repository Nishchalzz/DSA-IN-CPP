#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();

    //row check
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    //col check
    for(int j=0;j<=row;j++){
        if(board[j][col]=='Q'){
            return false;
        }
    }
    //left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //right diagonal
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void printArray(vector<vector<char>> board){
    for(int i=0;i<board.size();i++){
        
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------------"<<endl;
}

int nqueens(vector<vector<char>> board, int row){
    int n = board.size();
    if(row == n){
        printArray(board);
        return 1;
    }
    int count = 0;
    for(int j=0;j<n;j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            count += nqueens(board, row+1);
            board[row][j]='.';
        }
    }
    return count;
}

int main(){
    vector<vector<char>> board ;
    int n = 5;

    for(int i=0;i<n;i++){
        vector<char>  newrow;
        for(int j=0;j<n;j++){
            newrow.push_back('.');
        }
        board.push_back(newrow);
    }


    int count = nqueens(board, 0);
    cout<<"Count: "<<count;
    return 0;
}