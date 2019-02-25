
//#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#ifndef FILE_CLASS_HPP
#define FILE_CLASS_HPP

///////////////////
//  SHIP CLASS   //
///////////////////

class Ship
{
public:

    Ship(int length, std::pair<int, int> start, char d, const std::string &name) : _length{ length }, _startcoord{ start }, _direction{ d }, _name{ name }{};


    //generate coordinates for newly placed ship based on _direction and _startcoord
    std::vector<std::pair<int, int>> gencoords(std::pair<int, int> startCoord, char dir, int length) const {
        std::vector<std::pair<int, int>> coords;
        if (startCoord.first != -1) {
            switch (dir) {
                case 'N':
                    for (auto i = 0; i < length; ++i) {
                        if (startCoord.second - length + 1 > -1) {
                            coords.push_back(std::make_pair(startCoord.first, startCoord.second - i));
                        }
                        else {
                            return { std::make_pair(-1, -1) };
                        }
                    }
                    break;
                case 'S':
                    for (auto i = 0; i < length; ++i) {
                        if (startCoord.second + length - 1 < 9) {
                            coords.push_back(std::make_pair(startCoord.first, startCoord.second + i));
                        }
                        else {
                            return { std::make_pair(-1, -1) };
                        }
                    }
                    break;
                case 'E':
                    for (auto i = 0; i < length; ++i) {
                        if (startCoord.first + length - 1 < 9) {
                            coords.push_back(std::make_pair(startCoord.first + i, startCoord.second));
                        }
                        else {
                            return { std::make_pair(-1, -1) };
                        }
                    }
                    break;
                case 'W':
                    for (auto i = 0; i < length; ++i) {
                        if (startCoord.first - length + 1 > -1) {
                            coords.push_back(std::make_pair(startCoord.first - i, startCoord.first));
                        }
                        else {
                            return { std::make_pair(-1, -1) };
                        }
                    }
                    break;

            }
        }
        return coords;
    }


    //Start setters and getters
    int getLen() const {
        return _length;
    }

    std::pair<int, int> getStartCoord() const {
        return _startcoord;
    }

    void setStartCoord(const std::pair<int, int> &coord) {
        _startcoord = coord;

    }

    char getDirection() const {
        return _direction;
    }

    void setDirection(char dir) {
        _direction = dir;
    }

    std::vector<std::pair<int, int>> getCoords() {
        return _coords;
    }

    void setCoords(const std::vector<std::pair<int, int>> &coords) {
        _coords = coords;
    }

    std::string getName() {
        return _name;
    }
    //end setters and getters

private:
    std::string _name;
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

    Player(bool turn, int name) :_turn{ turn }, _name{ name }{
        for(int i = 0; i < 10; ++i){
            std::vector<char> newvec;
            for(int j = 0; j < 10; ++j){
                newvec.push_back('.');
            }
            _playerboard.push_back(newvec);
        }
    }

    void addshipboard(Ship i) {          //Adds the ships to the board
        char dir = i.getDirection();
        std::cout<<"TEST"<<dir<<std::endl;
        std::pair<int, int> start = i.getStartCoord();
        switch (dir) {
            case 'N':
                _playerboard[std::get<1>(start)][std::get<0>(start)] = 'V';
                for (int j = 1; j < i.getLen(); ++j) {
                    _playerboard[std::get<1>(start) - j][std::get<0>(start)] = '|';
                }
                _playerboard[std::get<1>(start) - i.getLen()][std::get<0>(start)] = 'A';
                break;
            case 'S':
                _playerboard[std::get<1>(start)][std::get<0>(start)] = 'A';
                for (int j = 1; j < i.getLen(); ++j) {
                    _playerboard[std::get<1>(start) + j][std::get<0>(start)] = '|';
                }
                _playerboard[std::get<1>(start) + i.getLen()][std::get<0>(start)] = 'V';
                break;
            case 'E':
                _playerboard[std::get<1>(start)][std::get<0>(start)] = '<';
                for (int j = 1; j < i.getLen(); ++j) {
                    _playerboard[std::get<1>(start)][std::get<0>(start) + j] = '|';
                }
                _playerboard[std::get<1>(start)][std::get<0>(start) + i.getLen()] = '>';
                break;
            case 'W':
                _playerboard[std::get<1>(start)][std::get<0>(start)] = '}';
                for (int j = 1; j < i.getLen(); ++j) {
                    _playerboard[std::get<1>(start)][std::get<0>(start) - j] = '|';
                }
                _playerboard[std::get<1>(start)][std::get<0>(start) - i.getLen()] = '{';
                break;
        }
    }
    void printboard(){          //prints out the board's current state
        for (const auto &i : _playerboard){
            for (auto j: i){
                std::cout<<j<<" ";
            }
            std::cout<<std::endl;
        }
    }

    //Start getters and setters
    std::vector<Ship> getShips() {
        return _ships;
    }

    int getTurn() {
        return _turn;
    }

    void setTurn(int turn) {
        _turn = turn;
    }


    //takes the index of the ship whose coords you are setting from _ships
    void setShipCoords(int ship, const std::vector<std::pair<int, int>> &coords) {
        _ships[ship].setCoords(coords);
    }

    void setStartCoord(int ship, const std::pair<int, int> &coord) {
        _ships[ship].setStartCoord(coord);
    }

    int getScore() {
        return _score;
    }

    //this is a setter, setScore() with a Battleshipy name
    void directHit() {
        _score = _score + 1;

    }
    //end setters and getterss

    //determines if an enemy bomb has hit any of your ships
    //takes a coordinate
    //returns the coordinate of a hit or (-1, -1) if there are none.
    std::pair<int, int> checkHit(std::pair<int, int> coord) {
        for (auto ship : _ships) {
            for (auto c : ship.getCoords()) {
                if (coord == c) {
                    std::cout << "You made a direct hit!" << std::endl;
                    return coord;
                }
            }
        }
        std::cout << "Better luck next time." << std::endl;
        return std::make_pair(-1, -1);

    }

    //Adds the coords of a hit to a player's vector of hit coords
    void addToHitList(const std::pair<int, int> &coord) {
        _hitList.push_back(coord);
    }

    //Returns true if you are not attempting to place one ship on top of another, else returns false
    bool noOverlap(std::pair<int, int> startCoord, char dir, int ship) {
        //generate potential coords for ship you are placing to cross check against already placed ships' coords
        auto coordsNew = _ships[ship].gencoords(startCoord, dir, _ships[ship].getLen());
        //look at each ship
        for (auto sh : _ships) {
            //if the x value of the start coord is still -1, it hasn't been placed yet, so ignore it.
            if (sh.getStartCoord().first != -1) {
                //if it has been placed, loop through its coords, and compare them to the
                //potential coords of the ship you are placing.
                for (auto coordExisting : sh.getCoords()) {
                    for (auto coordNew : coordsNew) {
                        if (coordExisting == coordNew) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    //Prints message if you hang a ship off the edge of the board.
    void hangShipMsg() const {
        std::cout << "A ship may not hang off the side of the board." << std::endl;
        std::cout << "Please try again." << std::endl;
    }

    void placeShips() {
        for (auto ship = 0; ship < _ships.size(); ship++) {
            int x = -1;
            int y = -1;
            char dir = 'Z';
            std::string str;
            while (true) {
                //enter a start x coord

                while (!std::cin || x < 0 || x > 9) {
                    std::cout << "Please enter the x coordinate at which to place the starting end of your " << _ships[ship].getName() << std::endl;
                    std::getline(std::cin, str);
                    std::stringstream(str) >> x;
                    std::cin.clear();
                }
                //enter a start y coord
                while (!std::cin || y < 0 || y > 9) {
                    std::cout << "\nPlease enter the y coordinate at which to place the starting end of your " << _ships[ship].getName() << std::endl;
                    std::getline(std::cin, str);
                    std::stringstream(str) >> y;
                    std::cin.clear();
                }
                //enter a direction
                while ((dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W')) {
                    std::cout << "\nPlease enter the direction in which to extend the ship from your start coordinate." << std::endl;
                    std::getline(std::cin, str);
                    std::string r;
                    std::stringstream(str) >> r;
                    dir = r[0];
                    std::cin.clear();
                }

                std::pair<int, int> startCoord = std::make_pair(x, y);
                //confirm that you aren't placing a ship on top of an existing ship.
                if (noOverlap(startCoord, dir, ship)) {
                    _ships[ship].setStartCoord(startCoord);
                    _ships[ship].setCoords(_ships[ship].gencoords(startCoord, dir, _ships[ship].getLen()));
                    if (_ships[ship].getCoords()[0].first == -1) {
                        hangShipMsg();
                        x = -1;
                        y = -1;
                        dir = 'Z';
                        continue;
                    }
                    else {
                        _ships[ship].setDirection(dir);
                        addshipboard(_ships[ship]);
                        printboard();
                        break;
                    }
                }
                    //Bad placement. Try again
                else { //(_ships[ship].getCoords()[0].first != -1) {
                    std::cout << "The placement you requested is invalid. No part of 2 or more ships may occupy the same location." << std::endl;
                    std::cout << "Please try again." << std::endl;
                    x = -1;
                    y = -1;
                    dir = 'Z';
                }

            }//end while loop
        }
    }
private:
    int _score = 0;
    bool _turn;
    int _name;
    std::vector<std::pair<int, int>> _hitList;
    std::vector<std::vector<char>> _playerboard;
    // ships[0] = Carrier: length 5
    // ships[1] = Battleship: length 4
    // ships[2] = Crusier: length 3
    // ships[3] = Sub: length 3
    // ships[4] = Destroyer: length 2
    //initialize all to _direction = 'Z' and _startcoord = (-1, -1)
    std::vector<Ship> _ships = { Ship(5, std::make_pair(-1, -1), 'Z', "Carrier (Length 5)"),
                                 Ship(4, std::make_pair(-1, -1), 'Z', "Battleship (Length 4)"),
                                 Ship(3, std::make_pair(-1, -1), 'Z', "Crusier (Length 3)"),
                                 Ship(3, std::make_pair(-1, -1), 'Z', "Submarine (Length 3)"),
                                 Ship(2, std::make_pair(-1, -1), 'Z', "Destroyer (Length 2)") };

};

//////////////////////////
//  ENVIRONMENT CLASS   //
//////////////////////////

class Environment
{
public:

    //takes the index of the ship whose coords you are setting from _ships
    void setShipCoords(int player, int ship, const std::vector<std::pair<int, int>> &coords) {
        if (player == 1) {
            _player1.setShipCoords(ship, coords);
        }
        else if (player == 2) {
            _player2.setShipCoords(ship, coords);
        }
    }

    //calls _player1 and _player2's setShipStartCoord() functions
    void setShipStartCoord(int player, int ship, const std::pair<int, int> &coord) {
        if (player == 1) {
            _player1.setStartCoord(ship, coord);
        }
        else if (player == 2) {
            _player2.setStartCoord(ship, coord);
        }
    }
    //calls _player1 and _player2's setTurn() functions
    void setPlayerTurn(int player, bool turn) {
        if (player == 1) {
            _player1.setTurn(turn);
        }
        else if (player == 2) {
            _player2.setTurn(turn);
        }
    }

    // calls _player1 and _player2's noOverlap() function,
    // which returns true if you aren't stacking one ship on another.
    bool noOverlap(int player, std::pair<int, int> startCoord, char dir, int ship) {
        if (player == 1) {
            return _player1.noOverlap(startCoord, dir, ship);
        }
        else if (player == 2) {
            return _player2.noOverlap(startCoord, dir, ship);
        }
    }

    void placePlayerShips(int player) {
        if (player == 1) {
            _player1.placeShips();
        }
        else if (player == 2) {
            _player2.placeShips();
        }
    }

    //Lob a bomb.
    void go(int player) {
        std::string str;
        int x;
        int y;
        std::cout << "Enter your targets x coordinate." << std::endl;
        std::getline(std::cin, str);
        std::stringstream(str) >> x;
        std::cout << "Enter your targets y coordinate." << std::endl;
        std::getline(std::cin, str);
        std::stringstream(str) >> y;
        if (player == 1) {
            //Player.hit() returns coords of a hit or (-1, 1)
            if (_player2.checkHit(std::make_pair(x, y)) != std::make_pair(-1, -1)) {
                //  ***********do something to indicate a hit on the ascii board here************
                _player2.directHit();
                _player2.addToHitList(_player2.checkHit(std::make_pair(x, y)));
            }
        }
        else if (player == 2) {
            //Player.hit() returns coords of a hit or (-1, 1)
            if (_player1.checkHit(std::make_pair(x, y)) != std::make_pair(-1, -1)) {
                //  ***********do something to indicate a hit on the ascii board here************
                _player1.directHit();
                _player1.addToHitList(_player1.checkHit(std::make_pair(x, y)));
            }
        }
    }

    //returns a unique_ptr to player1
    std::unique_ptr<Player> getPlayer1() {
        return std::make_unique<Player>(_player1);
    }
    //returns a unique_ptr to player2
    std::unique_ptr<Player> getPlayer2() {
        return std::make_unique<Player>(_player2);
    }



    // We only need this for testing, I think, at least so far. Comment out later. *****************************************
    //Player getPlayer1() {
    //  return _player1;
    //}


    //Anyone win yet?
    int win() {
        if (_player1.getScore() >= 17){
            return 1; //player1 looses, all their their ships are sunk
        }
        else if (_player2.getScore() >= 17) {
            return 2; //player2 looses.
        }
        else {
            return 0; //still in play
        }
    }


private:
    Player _player1 = Player(true, 1);
    Player _player2 = Player(false, 2);
};

#endif FILE_CLASS_HPP
