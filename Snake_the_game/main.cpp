#include "Map.h"
#include "Draw_config.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

std::vector<std::unique_ptr<StaticObject>> generateLevel1(unsigned width, unsigned height) {
	std::vector<std::unique_ptr<StaticObject>> mo;
	
	for (int x = 0; x < width; ++x) {
		mo.push_back(std::unique_ptr<Wall>(new Wall(Point(x, 0))));
		mo.push_back(std::unique_ptr<Wall>(new Wall(Point(x, height - 1))));
	}
	
	for (int y = 0; y < height; ++y) {
		mo.push_back(std::unique_ptr<Wall>(new Wall(Point(0, y))));
		mo.push_back(std::unique_ptr<Wall>(new Wall(Point(width - 1, y))));
	}
	
	std::unique_ptr<Portal> p1(new Portal(Point(5, 5)));
	std::unique_ptr<Portal> p2(new Portal(Point(width-5, height-5)));
	
	p1->connectWith(*p2);
	mo.push_back(std::move(p1));
	mo.push_back(std::move(p2));

	Point mapCenter = Point((width - 2) / 2, (height - 2) / 2);
		
	for (int x = mapCenter.x() - 8; x <= mapCenter.x() + 8; ++x) {
		mo.push_back(std::unique_ptr<Wall>(new Wall(Point(x, mapCenter.y()))));
	}
	
	for (int y = mapCenter.y() - 4; y <= mapCenter.y() + 4; ++y) {
		mo.push_back(std::unique_ptr<Wall>(new Wall(Point(mapCenter.x(), y))));
	}

	return mo;
}

std::vector<std::unique_ptr<DynamicObject>> generateDynObjectsLevel1() {
	std::vector<std::unique_ptr<DynamicObject>> ret;

	ret.push_back(std::unique_ptr<CircularSaw>(new CircularSaw(Point(15, 1), Point(15, 6), sf::milliseconds(150))));
	ret.push_back(std::unique_ptr<CircularSaw>(new CircularSaw(Point(15, 15), Point(15, 22), sf::milliseconds(125))));
	ret.push_back(std::unique_ptr<CircularSaw>(new CircularSaw(Point(1, 11), Point(6, 11), sf::milliseconds(100))));
	ret.push_back(std::unique_ptr<CircularSaw>(new CircularSaw(Point(24, 11), Point(30, 11), sf::milliseconds(200))));

	return ret;
}
int main() {
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "Snake game", sf::Style::Close);
	Map game(window, 32, 24, generateLevel1(32, 24), generateDynObjectsLevel1());

	sf::Clock clock;

	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {
		sf::Event event;
		sf::Time dt = clock.restart();

		game.update(std::move(dt));

		while (window.pollEvent(event)) {
			
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed) {
				game.catchInput(event.key.code);
			}
		}

		window.clear(DrawConfig::BACKGROUND_COLOR);
		game.draw();
		window.display();
	}

	return 0;
}