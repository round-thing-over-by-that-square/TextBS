//#include "class.hpp"
//
//#include <SFML/Graphics.hpp>
//#include <string>
//#include <utility>
//using std::make_pair;
//#include <vector>
//using 
//
//void Ship::gencoords()
//{
//	switch (_direction) {
//	case 'N':
//		for (auto i = 1; i < _length; ++i) {
//			_coords[i] = make_pair(_startcoord.first, _startcoord.second + i);
//		}
//		break;
//	case 'S':
//		for (auto i = 1; i < _length; ++i) {
//			_coords[i] = make_pair(_startcoord.first, _startcoord.second - i);
//		}
//		break;
//	case 'E':
//		for (auto i = 1; i < _length; ++i) {
//			_coords[i] = make_pair(_startcoord.first + i, _startcoord.second);
//		}
//		break;
//	case 'W':
//		for (auto i = 1; i < _length; ++i) {
//			_coords[i] = make_pair(_startcoord.first - i, _startcoord.second);
//		}
//		break;
//	}
//
//	vector<std::pair<int, int>> Ship::getCoords() {
//		return _coords;
//	}
//}