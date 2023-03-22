
#include "player.hpp"

namespace ariel
{

class Game
{
    Player p1; //private by default
    Player p2; //private by default

    public:
    Game (Player p1, Player p2) //constructor of Player class
    {
        this->p1 = p1;
        this->p2 = p2;
    }

    void playTurn()
    {

    }
    
    void printLastTurn ()
    {

    }
    void playAll() //playes the game untill the end
    {

    }
   
   void printWiner() // prints the name of the winning player
   {

   } 
   void printLog()  // prints all the turns played one line per turn
   {

   }

   void printStats() // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
   {

   }


};







}

















    
}

