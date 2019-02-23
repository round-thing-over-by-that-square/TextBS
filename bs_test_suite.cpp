#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../bs/class.hpp"
#include <utility>
using std::make_pair;


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

TEST_CASE("player.ships[i].getLen()", "[p.player.ships[i].getLen]") {
	Player p = Player();
	REQUIRE(p.getShips()[0].getLen() == 5);
	REQUIRE(p.getShips()[1].getLen() == 4);
	REQUIRE(p.getShips()[2].getLen() == 3);
	REQUIRE(p.getShips()[3].getLen() == 3);
	REQUIRE(p.getShips()[4].getLen() == 2);
}

TEST_CASE("Player.setTurn()", "[p.player.setTurn]") {
	Player p = Player();
	Player p1 = Player();
	p.setTurn(0);
	p1.setTurn(1);
	REQUIRE(p.getTurn() == 0);
	REQUIRE(p1.getTurn() == 1);
}
