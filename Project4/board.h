/*Project 4b board class written by Andrew Ricci*/

#include <string>
#include <vector>

using namespace std;

class Board{
public:
    Board(string filename1);
    void printBoard();
    void addValue(char value, int row1, int col1);
    void clearValue(int row1, int col1);
    bool checkSolved();
    int checkConflicts(int row, int col, int num);
    bool solveBoard();
    bool findUnassigned(int &row, int &col);
    bool checkRules(int row, int col);

    vector<vector<char>> sudokuBoard;
    vector<vector<bool>> rowConflictValues;
    vector<vector<bool>> colConflictValues;
    vector<vector<bool>> gridConflictValues;
    int size;
    int recursionCount;
};
