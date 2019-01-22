/*Project 4b main program written by Andrew Ricci */

#include "board.h"
#include <iostream>

using namespace std;

int main(){
    int avgRecursions;
    //initializes sudoku board from file
    Board board1("sudoku1.txt");
    //prints unsolved board
    board1.printBoard();
    //runs board solver and checks if end result is correct
    if(board1.solveBoard() == true && board1.checkSolved()== true){
        board1.printBoard();
    }
    else{
        cout<<"Algorithm failure."<<endl;
    }
    Board board2("sudoku2.txt");
    board2.printBoard();
    if(board2.solveBoard() == true && board2.checkSolved()== true){
        board2.printBoard();
    }
    else{
        cout<<"Algorithm failure."<<endl;
    }
    Board board3("sudoku3.txt");
    board3.printBoard();
    if(board3.solveBoard() == true && board3.checkSolved()== true){
        board3.printBoard();
    }
    else{
        cout<<"Algorithm failure."<<endl;
    }
    avgRecursions = (board1.recursionCount + board2.recursionCount + board3.recursionCount) / 3;
    cout<<"Average number of recursions is "<<avgRecursions<<endl;

}
