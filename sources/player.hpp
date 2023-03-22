#include <string>


class Player
{
    public:
    string playerName;

    Player (){}; //default constructor
    
    Player (string name)  //constructor of Player class
    {
       playerName = name;
    }
    
    int stacksize () // returns the amount of cards left
    {
        return 1;
    }
   
    int cardesTaken () // returns the amount of cards this player has won
    {
        return 1;
    }

};




