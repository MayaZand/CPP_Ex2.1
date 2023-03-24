#include "doctest.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;
using namespace std;



TEST_CASE ("befor the game starts")
{
    Player p1 ("Alice");
    Player p2 ("Bob");
    Game game (p1, p2);
    
    CHECK (p1.stacksize() == 26); //At the beginning of the game, each player should have 26 cards
    CHECK (p2.stacksize() == 26); //At the beginning of the game, each player should have 26 cards
    CHECK (p1.cardesTaken() == 0); //At the beginning of the game, none of the players won a card
    CHECK (p2.cardesTaken() == 0); //At the beginning of the game, none of the players won a card
    


}

// TEST_CASE ("after one turn")
// {

//     CHECK ()




// }
