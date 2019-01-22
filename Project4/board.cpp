/*Project 4b board class written by Andrew Ricci */

#include "board.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Board::Board(string filename1){
    //opens file and sets sudoku size to 9
    ifstream file(filename1);
    size = 9;
    recursionCount = 0;
    //range of integers is from 0-9
    int valRange = 10;
    //sizes sudoku board to board size
    sudokuBoard.resize(size, vector<char>(size));
    //creates arrays to store conflict, avoiding duplicates
    rowConflictValues.resize(valRange, vector<bool>(size));
    colConflictValues.resize(valRange, vector<bool>(size));
    gridConflictValues.resize(valRange, vector<bool>(size));

    char c;
    int row = 0;
    int col = 0;
    //takes text file one char at a time, setting '.' to a blank char
    while(file.get(c) && c != 'Z'){
        if(c != '.'){
            sudokuBoard[row][col] = c;
        }
        else{
            sudokuBoard[row][col] = ' ';
        }
        //iterates through columns and rows
        if(col < size-1){
            col++;
        }
        else if(col == size-1 && row < size-1)
        {
            col = 0;
            row++;
        }
        else{
            break;
        }
    }
    //tests each value in newly created matrix for conflicts
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(checkRules(row, col) == false){
                cout<<"Puzzle is not solvable"<<endl;
                exit(0);
            }
        }
    }
}

bool Board::solveBoard(){
    int row, col;
    //finds an unassigned index, assigns row and col to that index using reference
    //if no unassigned, solving is finished
    if(!findUnassigned(row, col)){
        return true;
    }
    //cycles through all values 1-9
    for(int num = 1; num <= 9; num++){
        //if value has no conflict and the cell is empty
        if(checkConflicts(row, col, num) == 0 && sudokuBoard[row][col] == ' '){
            //sets int to a char because I didn't think this through well enough
            char value = num + '0';
            //assigns that value to the cell
            addValue(value,row,col);
            if(solveBoard()){
                return true;
            }
            //clears value if not in right spot
            clearValue(row,col);
        }
    }
    //triggers recursion
    recursionCount++;
    return false;
}

//adds a custom value to a place in matrix
void Board::addValue(char value, int row1, int col1){
    sudokuBoard[row1][col1] = value;
    checkRules(row1,col1);
}
//finds unassigned index in puzzle and sets it by reference
bool Board::findUnassigned(int &row, int &col){
    for(row = 0; row < size; row++){
        for(col = 0; col < size; col++){
            if(sudokuBoard[row][col] == ' '){
                return true;
            }
        }
    }
    return false;
}

//checks that all values are filled and there are no conflicts
bool Board::checkSolved(){
    bool solved;
    //checks for conflicts and empty cells
    for(int row = 0; row < size; row++){
        for (int col = 0; col <size; col++){
            //if not solved, display message and go to check completed message
            if(sudokuBoard[row][col] == ' '){
                cout<<"Puzzle is not solved"<<endl;
                return false;
            }
            else if(checkRules(row, col) == false){
                cout<<"Puzzle has broken sudoku rules."<<endl;
            }
        }
    }
    cout<<"Puzzle is solved!"<<endl;
    cout<<"Number of recursions: "<<recursionCount<<endl;
    return true;
}
//manually removes a value from the matrix
void Board::clearValue(int row1, int col1){
    sudokuBoard[row1][col1] = ' ';
    checkRules(row1,col1);
}
//prints each cell in matrix
void Board::printBoard(){
    for(int i=0; i<=size-1; i++) {
        for(int j=0; j<=size-1; j++){
            cout<< sudokuBoard[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//checks for row, column, and 3x3 box conflicts
int Board::checkConflicts(int row, int col, int num){
    int conflicts = 0;
    char value = '0' + num;
    //checks each value in row and column against current cell
    for(int i = 0; i < size; i++){
        if(value == sudokuBoard[row][i]){
            conflicts++;
        }
        if(value == sudokuBoard[i][col]){
            conflicts++;
        }
    }
    //starts with smallest corner of cell's 3x3 box
    int rowFirst = row - row % 3;
    int colFirst = col - col % 3;
    //compares each value against the cell's value
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(value == sudokuBoard[rowFirst+i][colFirst+j]){
                conflicts++;
            }
        }
    }
    //returns the number of conflicts found
    return conflicts;
}
//checks cell against row, col, and 3x3 using sudoku rules
bool Board::checkRules(int row, int col){
    if(sudokuBoard[row][col] != ' '){
        for(int i = 0; i < size; i++){
           if(sudokuBoard[row][col] == sudokuBoard[row][i] && i != col){
                cout<<"Conflict of value "<<sudokuBoard[row][col]<<" at row "<<row<<endl;
                return false;
           }
           if(sudokuBoard[row][col] == sudokuBoard[i][col] && i != row){
               cout<<"Conflict of value "<<sudokuBoard[row][col]<<" at col "<<col<<endl;
               return false;
           }
        }
        int rowFirst = row - row % 3;
        int colFirst = col - col % 3;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(sudokuBoard[row][col] == sudokuBoard[rowFirst+i][colFirst+j] && (row != rowFirst+i || col != colFirst+j)){
                    cout<<"Conflict of value "<<sudokuBoard[row][col]<<" in box "<<colFirst<<","<<rowFirst<<endl;
                    return false;
                }
            }
        }
    }
    return true;
}
