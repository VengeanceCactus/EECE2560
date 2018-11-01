/* Written by Andrew Ricci */

#include <string>
#include <vector>

using namespace std;

class Grid{
public:
    int size;

    Grid();
    void storeGrid(string filename1);
    void printMatrix();
    vector<vector<char>> matrix;
};
