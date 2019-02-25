//#include <SFML/Graphics.hpp>
#include "class.hpp"

#include <utility>
using std::pair;
using std::make_pair;
#include <string>
using std::string;
#include <vector>
using std::vector;
//#include "catch.hpp"
#include <iostream>



int main(){
    //Create environment object, which owns 2 players who, in turn, own their fleets of ships
    Environment e = Environment();

    //Place each player's ships
    e.placePlayerShips(1);
    e.placePlayerShips(2);

    //start game loop
    while(true){

        // if someone wins
        if (e.win() == 1 || e.win() == 2) {
            break;
        }


        // if player1 turn
        if (e.getPlayer1()->getTurn()) {
            e.go(1); //hit or miss message delivered in Player.checkHit(), scores updated in Player.directHit()
            std::cout << "Press any key when you are ready to pass the computer." << std::endl;
            std::cin;
            std::cin.clear();
            //*************swap screens here ***************
        }

            //else player2 turn
        else {
            e.go(2); //hit or miss message delivered in Player.hit()
            std::cout << "Press any key when you are ready to pass the computer." << std::endl;
            std::cin;
            std::cin.clear();
            //*************swap screens here ***************
        }

        //Turn Swap
        //e.changeTurn();
    }
    //end game loop

    if (e.win() == 1) {
        std::cout << "Player 1 wins!" << std::endl;
    }
    else {
        std::cout << "Player 2 wins!" << std::endl;
    }

    return 0;
}

