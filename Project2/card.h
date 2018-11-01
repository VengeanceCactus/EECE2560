/*Card Header
Written by Andrew Ricci and Julian Perez*/

#include <iostream>

using namespace std;

class Card{
private:
    int cv;
    char st;
public:
    Card();
    Card(int cv1, char st1);

    void setValue(int cv1);
    void setSuit(char st1);
    int getValue();
    char getSuit();

    friend ostream& operator<<(ostream& print, Card& Card1);

};


