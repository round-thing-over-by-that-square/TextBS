
//#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>


#ifndef FILE_SHIP_HPP
#define FILE_SHIP_HPP
class Ship
{
public:
	Ship(int length, std::pair<int, int> start, char d) : _length{ length }, _startcoord{ start }, _direction{ d }{};
	

 
	void gencoords() {
		switch (_direction) {
		case 'N':
			for (auto i = 1; i < _length; ++i) {
				_coords[i] = std::make_pair(_startcoord.first, _startcoord.second + i);
			}
			break;
		case 'S':
			for (auto i = 1; i < _length; ++i) {
				_coords[i] = std::make_pair(_startcoord.first, _startcoord.second - i);
			}
			break;
		case 'E':
			for (auto i = 1; i < _length; ++i) {
				_coords[i] = std::make_pair(_startcoord.first + i, _startcoord.second);
			}
			break;
		case 'W':
			for (auto i = 1; i < _length; ++i) {
				_coords[i] = std::make_pair(_startcoord.first - i, _startcoord.second);
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

#endif FILE_SHIP_HPP