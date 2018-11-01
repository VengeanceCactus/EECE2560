/* Written by Andrew Ricci */

#include "grid.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Grid::Grid(){}

void Grid::storeGrid(string filename1){
    //loads text file
    ifstream file(filename1);
    string line;
    //gets first line
    getline(file, line);
    string delimiter = " ";
    //splits line at space
    string str = line.substr(0, line.find(delimiter));
    //uses first value to set grid size
    size = stoi (str);
    matrix.resize(size, vector<char>(size));

    char c;
    //iterates through only letters in file
    if(c != ' ' && c != '\n'){
        //for every row and column in file, takes character and sets matrix value to it
        for(int row = 0; row < size; row++){
            for(int col = 0; col < size; col++){
                file >> c;
                matrix[row][col] = c;
            }
        }
    }
}

void Grid::printMatrix(){
    //iterates through each row and column and outputs character value
    for(int i=0; i<=size-1; i++) {
        for(int j=0; j<=size-1; j++){
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
