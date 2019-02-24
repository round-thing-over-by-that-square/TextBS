
//#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#ifndef FILE_CLASS_HPP
#define FILE_CLASS_HPP

///////////////////
//  SHIP CLASS   // 
///////////////////

class Ship
{
public:
	Ship(int length, std::pair<int, int> start, char d, const std::string &name) : _length{ length }, _startcoord{ start }, _direction{ d }, _name{ name }{};
	

	//generate coordinates for newly placed ship based on _direction and _startcoord
	//Does not allow a ship to hang over the edge of the board, but doesn't handle placing a ship on top of another
	std::vector<std::pair<int, int>> gencoords(std::pair<int, int> startCoord, char dir, int length) const {
		std::vector<std::pair<int, int>> coords;
		if (startCoord.first != -1) {
			switch (dir) {
			case 'N':
				for (auto i = 0; i < length; ++i) {
					coords.push_back(std::make_pair(startCoord.first, startCoord.second - i));
				}
				break;
			case 'S':
				for (auto i = 0; i < length; ++i) {
					coords.push_back(std::make_pair(startCoord.first, startCoord.second + i));
				}
				break;
			case 'E':
				for (auto i = 0; i < length; ++i) {
					coords.push_back(std::make_pair(startCoord.first + i, startCoord.second));
				}
				break;
			case 'W':
				for (auto i = 0; i < length; ++i) {
					coords.push_back(std::make_pair(startCoord.first - i, startCoord.second));
				}
				break;
			}
		}
		return coords;
	}

	//Start setters and getters
	int getLen() const {
		return _length;
	}

	std::pair<int, int> getStartCoord() const {
		return _startcoord;
	}

	void setStartCoord(const std::pair<int, int> &coord) {
		_startcoord = coord;
		
	}

	char getDirection() const {
		return _direction;
	}

	void setDirection(char dir) {
		_direction = dir;
	}

	std::vector<std::pair<int, int>> getCoords() {
		return _coords;
	}

	void setCoords(const std::vector<std::pair<int, int>> &coords) {
		_coords = coords;
	}

	std::string getName() {
		return _name;
	}
	//end setters and getters

private:
	std::string _name;
	char _direction;
	int _length;
	std::pair <int, int> _startcoord;
	std::vector<std::pair<int, int>> _coords = { _startcoord };
	//sf::Sprite sprite

};

/////////////////////
//  PLAYER CLASS   // 
/////////////////////

class Player
{
public:
	Player(bool turn) :_turn{ turn }{}

	//Start getters and setters
	std::vector<Ship> getShips() {
		return _ships;
	}

	int getTurn() {
		return _turn;
	}

	void setTurn(bool turn) {
		_turn = turn;
	}

	////takes the index of the ship whose coords you are setting from _ships
	void setShipCoords(int ship, const std::vector<std::pair<int, int>> &coords) {
		_ships[ship].setCoords(coords);
	}

	void setStartCoord(int ship, const std::pair<int, int> &coord) {
		_ships[ship].setStartCoord(coord);
	}
	
	int getScore() {
		return _score;
	}
	//this is a setter, setScore() with a Battleshipy name 
	void directHit() {
		_score = _score + 1;
	}
	//end setters and getterss

	//Lob a bomb.
	void go() {
		// need to write
	}

	//Returns true if you are not attempting to place one ship on top of another, else returns false
	bool noOverlap(std::pair<int, int> startCoord, char dir, int ship) {
		//generate potential coords for ship you are placing to cross check against already placed ships' coords
		auto coordsNew = _ships[ship].gencoords(startCoord, dir, _ships[ship].getLen());
		//look at each ship
		for (auto sh : _ships) {
			//if the x value of the start coord is still -1, it hasn't been placed yet, so ignore it.
			if (sh.getStartCoord().first != -1) {
				//if it has been placed, loop through its coords, and compare them to the
				//potential coords of the ship you are placing.
				for (auto coordExisting : sh.getCoords()) {
					for (auto coordNew : coordsNew) {
						if (coordExisting == coordNew) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}

	void placeShips() {
		for (auto ship = 0; ship < _ships.size(); ship++) {
			int x = -1;
			int y = -1;
			char dir = 'Z';
			std::string str;
			while (true) {
				//enter a start x coord
				
				while (!std::cin || x < 0 || x > 9) {
					std::cout << "Please enter the x coordinate at which to place the starting end of your " << _ships[ship].getName() << std::endl;
					std::getline(std::cin, str);
					std::stringstream(str) >> x;
				}
				//enter a start y coord
				while (!std::cin || y < 0 || y > 9) {
					std::cout << "\nPlease enter the y coordinate at which to place the starting end of your " << _ships[ship].getName() << std::endl;
					std::getline(std::cin, str);
					std::stringstream(str) >> y;
				}
				//enter a direction
				while (!std::cin || (dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W')) {
					std::cout << "\nPlease enter the direction in which to extend the ship from your start coordinate." << std::endl;
					std::getline(std::cin, str);
					std::stringstream(str) >> dir;
				}
				std::pair<int, int> startCoord = std::make_pair(x, y);
				//confirm that you aren't placing on top of an existing ship, and place it.
				if (noOverlap(startCoord, dir, ship)) {
					_ships[ship].setStartCoord(startCoord);
					_ships[ship].setCoords(_ships[ship].gencoords(startCoord, dir, _ships[ship].getLen()));
					break;
				}
				//Bad placement. Try again 
				else {
					std::cout << "The placement you requested is invalid. No part of 2 or more ships may occupy the same location." << std::endl;
					std::cout << "Please try again." << std::endl;
					x = -1;
					y = -1;
					dir = 'Z';
				}
			}//end while loop
		}
	}

private:
	int _score = 0;
	bool _turn;

	// ships[0] = Carrier: length 5
	// ships[1] = Battleship: length 4
	// ships[2] = Crusier: length 3
	// ships[3] = Sub: length 3
	// ships[4] = Destroyer: length 2
	//initialize all to _direction = 'Z' and _startcoord = (-1, -1)
	std::vector<Ship> _ships = { Ship(5, std::make_pair(-1, -1), 'Z', "Carrier"),
								Ship(4, std::make_pair(-1, -1), 'Z', "Battleship"),
								Ship(3, std::make_pair(-1, -1), 'Z', "Crusier"),
								Ship(3, std::make_pair(-1, -1), 'Z', "Submarine"),
								Ship(2, std::make_pair(-1, -1), 'Z', "Destroyer") };

};

//////////////////////////
//  ENVIRONMENT CLASS   // 
//////////////////////////

class Environment
{
public:
	
	//takes the index of the ship whose coords you are setting from _ships
	void setShipCoords(int player, int ship, const std::vector<std::pair<int, int>> &coords) {
		if (player == 1) {
			_player1.setShipCoords(ship, coords);
		}
		else if (player == 2) {
			_player2.setShipCoords(ship, coords);
		}
	}

	void setShipStartCoord(int player, int ship, const std::pair<int, int> &coord) {
		if (player == 1) {
			_player1.setStartCoord(ship, coord);
		}
		else if (player == 2) {
			_player2.setStartCoord(ship, coord);
		}
	}

	void setPlayerTurn(int player, bool turn) {
		if (player == 1) {
			_player1.setTurn(turn);
		}
		else if (player == 2) {
			_player2.setTurn(turn);
		}
	}

	bool noOverlap(int player, std::pair<int, int> startCoord, char dir, int ship) {
		if (player == 1) {
			return _player1.noOverlap(startCoord, dir, ship);
		}
		else if (player == 2) {
			return _player2.noOverlap(startCoord, dir, ship);
		}
	}

	//returns a unique_ptr to player1
	std::unique_ptr<Player> getPlayer1() {
		return std::make_unique<Player>(_player1);
	}			
	//returns a unique_ptr to player2
	std::unique_ptr<Player> getPlayer2() { 
		return std::make_unique<Player>(_player2);
	}

	//Swaps turns. Called from main
	void changeTurn() {
		if (_player1.getTurn() == true) {
			_player1.setTurn(false);
			_player2.setTurn(true);
		}
		else {
			_player1.setTurn(true);
			_player2.setTurn(false);
		}
	}

	//Adjusts Player's score when they receive a direct hit.
	// Takes an int, 1 if player1 hit, 2 if player2 hit.
	void directHit(int playerNumber) {
		if (playerNumber == 1) {
			_player1.directHit();
		}
		else if (playerNumber == 2) {
			_player2.directHit();
		}
	}


	//Anyone win yet?
	int win() {
		if (_player1.getScore() >= 17){
			return 2; //player1 looses, all their their ships are sunk
		}
		else if (_player2.getScore() >= 17) {
			return 1; //player2 looses.
		}
		else {
			return 0; //still in play
		}
	}
		

private:
	Player _player1 = Player(true);
	Player _player2 = Player(false);
};

#endif FILE_CLASS_HPP