
//#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>


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
	Player() {}

	std::vector<Ship> getShips() {
		return _ships;
	}

	int getTurn() {
		return _turn;
	}

	void setTurn(int turn) {
		_turn = turn;
	}
	
	int getScore() {
		return _score;
	}
private:
	int _score = 0;
	int _turn = -1;

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



	int win() {
		if (_player1.getScore() == 17){
			return 1;
		}
		else if (_player2.getScore() == 17) {
			return 2;
		}
	}
		

private:
	Player _player1 = Player();
	Player _player2 = Player();
};

#endif FILE_CLASS_HPP