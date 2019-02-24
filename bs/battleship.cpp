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
	e.getPlayer1()->placeShips();
	e.getPlayer2()->placeShips();

	//start game loop
	while(true){

		// if someone wins
		if (e.win() == 1 || e.win() == 2) {
			break;
		}

		// if player1 turn
		if (e.getPlayer1()->getTurn()) {
			e.getPlayer1()->go();
		}

		//else player2 turn
		else {
			e.getPlayer2()->go();
		}

		//Turn Swap
		e.changeTurn();
	}
	//end game loop

	if (e.win() == 1) {
		//announce player1 wins
	}
	else {
		//congrats player2
	}

	return 0;
}

