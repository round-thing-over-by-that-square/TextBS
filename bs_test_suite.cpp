#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../bs/class.hpp"
#include <utility>
using std::make_pair;

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1)*number;
}

TEST_CASE("return the correct ship length", "[s.getLen]") {
	Ship s = Ship(4, make_pair(1, 2), 'N'); 
	s.gencoords();
	std::vector<std::pair<int, int>> v = { make_pair(1,2), make_pair(1,3), make_pair(1,4), make_pair(1,5) };
	REQUIRE(s.getLen() == 4);
}

TEST_CASE("return the correct vector of coords", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(1, 2), 'N');
	s.gencoords();
	std::vector<std::pair<int, int>> v = { make_pair(1,2), make_pair(1,3), make_pair(1,4), make_pair(1,5) };
	REQUIRE(s.getCoords() == v);
}
