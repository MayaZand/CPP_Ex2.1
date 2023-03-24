#pragma once
#include <string>
using namespace std;
namespace ariel
{

class Player
{
    
    std::string playerName; //private by default
    
    public:
    Player(){} //default constructor
    
    Player(std::string name){} //constructor of Player class
    
    int stacksize(){return 1;} //returns the amount of cards left

    int cardesTaken(){return 1;} //returns the amount of cards this player has won
};

}
