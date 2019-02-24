#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../bs/class.hpp"
#include <utility>
using std::make_pair;


TEST_CASE("return the correct ship length", "[s.getLen]") {
	Ship s = Ship(4, make_pair(1, 2), 'N', "Battleship"); 
	auto coords = s.gencoords(s.getStartCoord(), s.getDirection(), s.getLen());
	s.setCoords(coords);
	std::vector<std::pair<int, int>> v = { make_pair(1,2), make_pair(1,3), make_pair(1,4), make_pair(1,5) };
	REQUIRE(s.getLen() == 4);
}

TEST_CASE("return the correct vector of coords, North", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(5, 5), 'N', "Battleship");
	auto coords = s.gencoords(s.getStartCoord(), s.getDirection(), s.getLen());
	s.setCoords(coords);
	std::vector<std::pair<int, int>> v = { make_pair(5,5), make_pair(5,4), make_pair(5,3), make_pair(5,2) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("return the correct vector of coords, South", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(5, 5), 'S', "Battleship");
	auto coords = s.gencoords(s.getStartCoord(), s.getDirection(), s.getLen());
	s.setCoords(coords);
	std::vector<std::pair<int, int>> v = { make_pair(5, 5), make_pair(5, 6), make_pair(5, 7), make_pair(5, 8) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("return the correct vector of coords, East", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(5, 5), 'E', "Battleship");
	auto coords = s.gencoords(s.getStartCoord(), s.getDirection(), s.getLen());
	s.setCoords(coords);
	std::vector<std::pair<int, int>> v = { make_pair(5, 5), make_pair(6, 5), make_pair(7, 5), make_pair(8, 5) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("return the correct vector of coords, West", "[s.getcoords]") {
	Ship s = Ship(4, make_pair(5, 5), 'W', "Carrier");
	auto coords = s.gencoords(s.getStartCoord(), s.getDirection(), s.getLen());
	s.setCoords(coords);
	std::vector<std::pair<int, int>> v = { make_pair(5, 5), make_pair(4, 5), make_pair(3, 5), make_pair(2, 5) };
	REQUIRE(s.getCoords() == v);
}

TEST_CASE("player.ships[i].getLen()", "[p.player.ships[i].getLen]") {
	Player p = Player(true);
	REQUIRE(p.getShips()[0].getLen() == 5);
	REQUIRE(p.getShips()[1].getLen() == 4);
	REQUIRE(p.getShips()[2].getLen() == 3);
	REQUIRE(p.getShips()[3].getLen() == 3);
	REQUIRE(p.getShips()[4].getLen() == 2);
}

TEST_CASE("Player.setTurn()", "[p.player.setTurn]") {
	Player p1 = Player(true);
	Player p2 = Player(false);
	p1.setTurn(false);
	p2.setTurn(true);
	REQUIRE(p1.getTurn() == false);
	REQUIRE(p2.getTurn() == true);
}

TEST_CASE("confirm Player.changeTurn() changes the player1 and player2 ._turn", "[Player.changeTurn]") {
	Environment e = Environment();
	e.changeTurn();
	REQUIRE(e.getPlayer1()->getTurn() == false);
	REQUIRE(e.getPlayer2()->getTurn() == true);

}

TEST_CASE("confirm Player.directHit() changes the player1 and player2 ._score, and test win()", "[Player.directHit]") {
	Environment e = Environment();
	REQUIRE(e.getPlayer1()->getScore() == 0);
	e.directHit(1);						
	REQUIRE(e.getPlayer1()->getScore() == 1);
	for (auto i = 0; i < 16; ++i) {
		e.directHit(1);
	}
	REQUIRE(e.win() == 2);

}

TEST_CASE("test Ship.setCoords()", "[Ship.setCoords]") {
	std::vector<std::pair<int, int>> c{ std::make_pair(2, 2), std::make_pair(2, 3), std::make_pair(2, 4) };
	Environment e = Environment();
	e.getPlayer1()->getShips()[2].setCoords(c);
	REQUIRE(e.getPlayer1()->getShips()[2].getCoords() == c);
}
//
//TEST_CASE("test noOverlap()", "[Player.noOverlap]") {
//	Player p = Player(true);
//	auto ships = p.getShips();
//	p.getShips()[2].setStartCoord(std::make_pair(2, 2));
//	p.getShips()[2].setCoords({ std::make_pair(2,2), std::make_pair(2,3), std::make_pair(2,4) });
//	REQUIRE(p.noOverlap(std::make_pair(2, 5), 'N', ships[3]) == false);
//}



//need to write test for placeShips() but not sure how you deal with cin input in catch... 