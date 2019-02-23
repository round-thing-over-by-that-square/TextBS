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

TEST_CASE("return the correct vector of coords, North", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(1, 2), 'N');
	s.gencoords();
	std::vector<std::pair<int, int>> v = { make_pair(1,2), make_pair(1,3), make_pair(1,4), make_pair(1,5) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("return the correct vector of coords, South", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(1, 10), 'S');
	s.gencoords();
	std::vector<std::pair<int, int>> v = { make_pair(1,10), make_pair(1,9), make_pair(1,8), make_pair(1,7) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("return the correct vector of coords, East", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(1, 2), 'E');
	s.gencoords();
	std::vector<std::pair<int, int>> v = { make_pair(1,2), make_pair(2,2), make_pair(3,2), make_pair(4,2) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("return the correct vector of coords, West", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(10, 2), 'W');
	s.gencoords();
	std::vector<std::pair<int, int>> v = { make_pair(10,2), make_pair(9,2), make_pair(8,2), make_pair(7,2) };
	REQUIRE(s.getCoords() == v);
}
