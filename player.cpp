#include "sources/player.hpp"
using namespace std;

namespace ariel 
{

Player::Player (std::string name)  //constructor of Player class
{
    this->playerName = name;
}
int ariel::Player::stacksize () // returns the amount of cards left
{
    return 1;
};
   
int ariel::Player::cardesTaken () // returns the amount of cards this player has won
{
    return 1;
};

}