#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "Gui\Gui.h"
#include "Gui\TextLabel.h"

#include "MainScene.h"
#include "GameManager.h"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode(640, 480), "Snake game", sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);
	
	Gui gui(window);
	auto scoreText = gui.addElem<TextLabel>("./res/fonts/arial.ttf", "Scores: ", 32);
	if (scoreText) {
		scoreText->setPosition(10.0f, 10.0f);
	}

	_GameManager.pushModule(std::make_unique<MainScene>(window, sf::Vector2u(1000, 1000)));
	
	sf::Clock gameClock;
	while (window.isOpen()) {
		sf::Event event;
		auto gameTime = gameClock.restart();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed){
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				_GameManager.processInput(event.key.code);
			}
			gui.captureEvent(event);
		}

		//TICK TO DO
		_GameManager.run(gameTime);
		_GameManager.updatePhysics();
		//END

		window.clear(sf::Color::Green);
		_GameManager.draw(window, sf::RenderStates::Default);
		gui.draw();
		window.display();
	}

	return 0;
}