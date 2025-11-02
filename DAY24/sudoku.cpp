#include <iostream>
using namespace std;

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int digit){
    //horizontal
    for(int i=0;i<=8;i++){
        if(sudoku[row][i]==digit){
            return false;
        }
    }

    //vertical
    for(int j=0;j<=8;j++){
        if(sudoku[j][col]==digit){
            return false;
        }
    }


    //3x3 grid
    int sr = (row/3)*3;
    int sc = (col/3)*3;

    for(int i=sr;i<=sr+2;i++){
        for(int j=sc;j<=sc+2;j++){
            if(sudoku[i][j]==digit){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col){
    if(row == 9){
        printSudoku(sudoku);
        return true;
    }

    int nextrow = row;
    int nextcol = col+1;
    if(nextcol==9){
        nextrow =  row + 1;
        nextcol = 0; 
    }

    if(sudoku[row][col]!=0){
        return sudokuSolver(sudoku, nextrow, nextcol);
    }

    for(int digit=1;digit<=9;digit++){
        if(isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextrow, nextcol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };


    sudokuSolver(sudoku, 0, 0);

    return 0;
}
