using namespace std;

class Card{
public:
    int cv; //card value
    char st; //suit

    Card(int cv1, char st1); //inits class with cv and st values

    void setValue(int cv1);
    void setSuit(char st1);
    void getValue();
    void getSuit();

    friend ostream& operator<<(ostream &print, Card &Card1){
        stringstream out;
        string a,b;
        if(Card1.getSuit() == 'H'){
            a = "Hearts";
        }
        else if(Card1.getSuit() == 'S'){
            a = "Spades";
        }
        else if (Card1.getSuit() == 'C'){
            a = "Clubs";
        }
        else if (Card1.getSuit() == 'D'){
            a = "Diamonds";
        }
        else{
            a = "Invalid Suit"
        }

        if(Card1.getValue() > 10 || Card1.getValue() < 2){
            if(Card1.getValue() == 11){
                b = "Jack";
            }
            else if (Card1.getValue() == 12){
                b = "Queen";
            }
            else if (Card1.getValue() == 13){
                b = "King";
            }
            else if (Card1.getValue() == 1){
                b = "Ace";
            }
            else
                b = "Invalid Card Value";
        }
        else{
            out << Card1.getValue();
            b = out.str();
        }
        print << b << " of " << a;
        return print;
    }

};
