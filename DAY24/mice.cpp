#include<iostream>
#include<string>
using namespace std;

void micesolve(int maze[4][4], int row, int col, string ans){
    if(row==3 && col==3){
        cout<<ans<<endl;
        return;
    }
    if(row>=4 || col>=4 ){
        return;
    }

    //right
    if(maze[row][col+1]!=0){
        micesolve(maze, row, col+1, ans+"R");
    }
    //down
    if(maze[row+1][col]!=0){
        micesolve(maze, row+1, col, ans+"D");
    }
    // //up
    // if(maze[row-1][col]!=0){
    //     micesolve(maze, row-1, col, ans+"U");
    // }
    // //LEFT
    // if(maze[row][col-1]!=0){
    //     micesolve(maze, row, col-1, ans+"L");
    // }
}

int main(){
    int maze[4][4] = { { 1, 0, 0, 0 },
                        { 1, 1, 0, 1 },
                        { 1, 1, 0, 0 },
                        { 0, 1, 1, 1 } };
    string ans = "";
    micesolve(maze, 0,0,ans);

}