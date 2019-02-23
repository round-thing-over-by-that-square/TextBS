#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../bs/class.hpp"
#include <utility>
using std::make_pair;

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1)*number;
}
//Ship(int length, std::pair<int, int> start, char d) : _length{ length }, _startcoord{ start }, _direction{ d }{};
TEST_CASE("return the correct ship length", "[s.getLen]") {
	Ship s = Ship(4, make_pair(1, 2), 'N'); 
	//s.gencoords();
	//std::vector<std::pair<int, int>> v = { make_pair(1,2), make_pair(1,3), make_pair(1,4), make_pair(1,5) };
	REQUIRE(s.getLen() == 4);
	//REQUIRE(s.getCoords() == v);
	
}
