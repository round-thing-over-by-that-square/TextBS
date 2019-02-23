
//#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>
#include <memory>


#ifndef FILE_CLASS_HPP
#define FILE_CLASS_HPP



///////////////////
//  SHIP CLASS   // 
///////////////////

class Ship
{
public:
	Ship(int length, std::pair<int, int> start, char d) : _length{ length }, _startcoord{ start }, _direction{ d }{};
	

 
	void gencoords() {
		switch (_direction) {
		case 'N':
			for (auto i = 1; i < _length; ++i) {
				_coords.push_back(std::make_pair(_startcoord.first, _startcoord.second + i));
			}
			break;
		case 'S':
			for (auto i = 1; i < _length; ++i) {
				_coords.push_back(std::make_pair(_startcoord.first, _startcoord.second - i));
			}
			break;
		case 'E':
			for (auto i = 1; i < _length; ++i) {
				_coords.push_back(std::make_pair(_startcoord.first + i, _startcoord.second));
			}
			break;
		case 'W':
			for (auto i = 1; i < _length; ++i) {
				_coords.push_back(std::make_pair(_startcoord.first - i, _startcoord.second));
			}
			break;
		}
	}
	
	std::vector<std::pair<int, int>> getCoords() {
		return _coords;
	}

	int getLen() {
		return _length;
	}



private:
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

private:
	int _score = 0;
	bool _turn;

	// ships[0] = Carrier: length 5
	// ships[1] = Battleship: length 4
	// ships[2] = Crusier: length 3
	// ships[3] = Sub: length 3
	// ships[4] = Destroyer: length 2
	//initialize all to _direction = 'Z' and _startcoord = (-1, -1)
	std::vector<Ship> _ships = { Ship(5, std::make_pair(-1, -1), 'Z'),
								Ship(4, std::make_pair(-1, -1), 'Z'),
								Ship(3, std::make_pair(-1, -1), 'Z'),
								Ship(3, std::make_pair(-1, -1), 'Z'),
								Ship(2, std::make_pair(-1, -1), 'Z') };

};

//////////////////////////
//  ENVIRONMENT CLASS   // 
//////////////////////////

class Environment
{
public:
	
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