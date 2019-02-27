//#include <SFML/Graphics.hpp>
#include "Classes.h"

#include <utility>
using std::pair;
using std::make_pair;
#include <string>
using std::string;
#include <vector>
using std::vector;
//#include "catch.hpp"
#include <iostream>

int flip(int n){
    if(n == 1)
        return 2;
    return 1;
}

int main(){
    //Create environment object, which owns 2 players who, in turn, own their fleets of ships
    Environment e = Environment();

    //Place each player's ships
    e.placePlayerShips(1);
    e.placePlayerShips(2);
    int n = 1;
    //start game loop
    while(true){

        // if someone wins
        if (e.win() == 1 || e.win() == 2) {
            break;
        }

        e.go(n); //hit or miss message delivered in Player.checkHit(), scores updated in Player.directHit()
        std::cout << "Pass the computer! Press Enter when ready" << std::endl;
        std::cin.get();
        std::cin.clear();

        n = flip(n);

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

