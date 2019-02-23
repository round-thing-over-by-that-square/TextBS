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








static int WIN_WIDTH = 1000;

int main(){
	//Create environment object, which owns 2 players who, in turn, own their fleets of ships
	Environment environment = Environment();

	//need to add board setup here. Players place ships.

	//start game loop
	while(true){

		// if someone wins
		if (environment.win() == 1 || environment.win() == 2) {
			break;
		}

		// if player1 turn
		if (environment.getPlayer1()->getTurn()) {
			environment.getPlayer1()->go();
		}

		//else player2 turn
		else {
			environment.getPlayer2()->go();
		}

		//Turn Swap
		if (environment.getPlayer1()->getTurn()) {
			environment.getPlayer1()->setTurn(false);
			environment.getPlayer2()->setTurn(true);
		}
		else {
			environment.getPlayer1()->setTurn(true);
			environment.getPlayer2()->setTurn(false);
		}
	}
	if (environment.win() == 1) {
		//announce player1 wins
	}
	else {
		//congrats player2
	}

	return 0;
}

