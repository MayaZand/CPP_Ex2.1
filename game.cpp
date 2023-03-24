#include "sources/game.hpp"
using namespace std;

namespace ariel 
{

    Game::Game (Player p1, Player p2) //constructor of Player class
    {
        this->p1 = p1;
        this->p2 = p2;
    }
    void ariel::Game::playTurn(){}
    
    void ariel::Game::printLastTurn (){}
    
    void ariel::Game::playAll(){} //playes the game untill the end
   
    void ariel::Game::printWiner(){} // prints the name of the winning player
   
    void ariel::Game::printLog(){}  // prints all the turns played one line per turn
  
    void ariel::Game:: printStats(){} // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
}
