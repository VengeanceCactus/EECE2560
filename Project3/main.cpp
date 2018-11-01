/*Written by Andrew Ricci */

#include "dictionary.h"
#include "grid.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void findMatches(Dictionary dict1, Grid grid1);
void search(int sortChoice);

int main(){
    int sortChoice;
    cout << "Please choose sorting algorithm."<<endl;
    cout << "1 for Selection, 2 for Heap, 3 for Quick."<<endl;
    cin >> sortChoice;
    search(sortChoice);
}

void findMatches(Dictionary dict1, Grid grid1){
    //declares arrays for all 8 directions words can be
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    //iterates through all words in ordered dictionary
    for (vector<string>::iterator it = dict1.dict.begin(); it != dict1.dict.end(); ++it){
        //iterates through all rows and columns of grid
        for(int i = 0; i <grid1.size; i++){
            for(int j = 0; j < grid1.size; j++){
                //checks if current letter is equal to first letter of word
                if(grid1.matrix[i][j] == it[0][0]){
                    //takes length of word and checks if 5 or greater
                    int len = it[0].size();
                    if(len < 5){
                        break;
                    }
                    //if first letter is equal, tests for word in all directions
                    for(int dir = 0; dir < 8; dir++){
                        //new variables for parsing grid
                        int k, rd = i + x[dir], cd = j + y[dir];
                        //iterates until word length
                        for(k = 1; k < len; k++){
                            //breaks if out of bounds
                            if(rd >= grid1.size || rd < 0 || cd >= grid1.size || cd < 0){
                                break;
                            }
                            //breaks if letters do not match
                            if(grid1.matrix[rd][cd] != it[0][k]){
                                break;
                            }
                            //iterates otherwise
                            rd += x[dir], cd += y[dir];
                        }
                        //if iterator matches word length, word is in grid
                        if(k == len){
                            cout <<"Word "<<*it<<" found in grid."<<endl;
                        }
                    }
                }
            }
        }
    }
}

void search(int sortChoice){
    string filename;
    cout <<"Please enter the text file you wish to input the grid from:"<<endl;
    cin >> filename;
    //constructs and sorts dictionary
    Dictionary dict1;
    dict1.readDict();
    //selects selection, heap, or quick sort algorithms
    if(sortChoice == 1){
        dict1.selectionSort();
    }
    else if(sortChoice == 2){
        dict1.heapSort();
    }
    else{
        dict1.quickSort();
    }
    //constructs, stores, and prints grid
    Grid grid1;
    grid1.storeGrid(filename);
    grid1.printMatrix();
    //runs findmatches to see if words are in grid
    findMatches(dict1, grid1);
}
