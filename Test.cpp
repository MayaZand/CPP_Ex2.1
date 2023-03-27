#include "doctest.h"
#include <stdio.h>
#include "iostream"
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
    Player player1 ("Alice");
    Player player2 ("Bob");
    
    CHECK (player1.stacksize() == 0); //Before the players start play they don't have any cards
    CHECK (player2.stacksize() == 0); //Before the players start play they don't have any cards
    CHECK (player1.cardesTaken() == 0); //At the beginning of the game, none of the players won a card
    CHECK (player2.cardesTaken() == 0); //At the beginning of the game, none of the players won a card
    Game game (player1, player2); //Create new game with Alice and Bob
    
    CHECK (player1.stacksize() == 26); //Before the game starts, each player should have 26 cards
    CHECK (player2.stacksize() == 26); //Before the game starts, each player should have 26 cards
    CHECK (player1.cardesTaken() == 0); //At the beginning of the game, none of the players won a card
    CHECK (player2.cardesTaken() == 0); //At the beginning of the game, none of the players won a card
    CHECK (player1.stacksize() + player2.stacksize() == 52); //The sum of cards of both players should be 52 card
}

TEST_CASE("during the game")
{
    Player player1 ("Alice");
    Player player2 ("Bob");
    Game game (player1, player2);
    game.playTurn();
    bool gameStarts=false;

    CHECK (player1.stacksize() < 26); //After the game starts, both players have less than 26 card
    CHECK (player2.stacksize() < 26); //After the game starts, both players have less than 26 card
    CHECK (player1.stacksize() +player1.cardesTaken() + player2.stacksize() + player2.cardesTaken() == 52); //Total number of cards should be 52
    if (player1.cardesTaken() > 0 || player2.cardesTaken()>0)
    {
        gameStarts = true;
    }
    CHECK (gameStarts==true); //After the game starts, at least one player has at least one card in cardsTaken.
}

TEST_CASE ("end of the game")
{
    Player player1 ("Alice");
    Player player2 ("Bob");
    Game game (player1, player2); //create new game
    game.playAll(); //play the game until the end
    bool winner=false;
    
    
    CHECK (player1.stacksize() == 0); //At the end of the game, each player should have 0 cards
    CHECK (player2.stacksize() == 0); //At the end of the game, each player should have 0 cards
    CHECK (player1.cardesTaken() + player2.cardesTaken() == 52); //Total sum of cards should be 52
    if (player1.cardesTaken() > 0 || player2.cardesTaken()>0)
    {
        winner = true;
    }
    CHECK (winner==true); //At the end of the game, at least one player has at least one card in cardsTaken.
}

TEST_CASE ("after 5 turns")
{
    Player player1 ("Alice");
    Player player2 ("Bob");
    Game game (player1, player2); //create new game
    bool winner;
    for (int i =1; i<=5; i++)
    {
        game.playAll();
    }

    CHECK (player1.stacksize() <=21); //After 5 turns number of cards must be equal or less than 21 cards 
    CHECK (player2.stacksize() <=21); //After 5 turns number of cards must be equal or less than 21 cards 
    if (player1.cardesTaken() > 0 || player2.cardesTaken()>0)
    {
        winner = true;
    }
    CHECK (winner);
}

TEST_CASE ("after 10 turns")
{
    Player player1 ("Alice");
    Player player2 ("Bob");
    Game game (player1, player2); //create new game
    bool winner;
    for (int i =1; i<=10; i++)
    {
        game.playTurn();
    }

    CHECK (26 - player1.stacksize() >=16); //After 5 turns number of cards must be equal or less than 21 cards 
    CHECK (26 - player2.stacksize() >=16); //After 5 turns number of cards must be equal or less than 21 cards 
    if (player1.cardesTaken() > 0 || player2.cardesTaken()>0)
    {
        winner = true;
    }
    CHECK (winner);
}

TEST_CASE ("each game is maximum 26 rounds")
{
    Player player1 ("Alice");
    Player player2 ("Bob");
    Game game (player1, player2); //create new game
    bool max26turns = true;

    game.playAll(); 
    CHECK_THROWS(game.playTurn()); //After max 26 rounds, it is not possible to play another turn
}

TEST_CASE ("An attempt to put the same player into one game")
{
    Player player2 ("Bob");
    Game game (player2, player2); //Create new game with the same player
    CHECK_THROWS(game.playTurn()); //Should throw exception
}

TEST_CASE ("befor calling game.playTurn method")
{
    Player player1 ("Alice");
    Player player2 ("Bob");
    Game game (player1, player2); //create new game
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printWiner());
}











