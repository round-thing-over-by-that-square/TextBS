//#include <SFML/Graphics.hpp>
#include "class.hpp"

#include <utility>
using std::pair;
using std::make_pair;
#include <string>
using std::string;
#include <vector>
using std::vector;
//#include "catch.hpp"
#include <iostream>


class Player
{
public:
	Player() {}
private:
	int _score;
};




class Environment
{
public:

private:

};

static int WIN_WIDTH = 1000;

int main()
{
	//Ship(int length, pair<int, int> start, char d) : _length{ length }, _startcoord{ start }, _direction{ d }
	//TEST_CASE("Made Ship with ", "[Ship]") {
	//	REQUIRE(Ship() == 1);


//	//sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, (9 * WIN_WIDTH) / 16), "Battle Sushi!");
//	//sf::CircleShape shape(100.f);
//	//shape.setFillColor(sf::Color::Green);
//
//	//while (window.isOpen())
//	//{
////		sf::Event event;
//	//	while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
	std::cout << "Hello" << std::endl;
	return 0;
}

