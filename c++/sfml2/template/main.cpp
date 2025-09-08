#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

sf::RenderWindow* window;

sf::Font font;
sf::Text text;

sf::Texture texture;
sf::Sprite sprite;



void processEvents(sf::RenderWindow* window) {
	// Event processing https://www.sfml-dev.org/tutorials/2.5/window-events.php
	sf::Event event;
	while (window->pollEvent(event))	{
		switch (event.type) {

			// Joystick events
			case sf::Event::JoystickConnected:
				break;
			case sf::Event::JoystickDisconnected:
				break;
			case sf::Event::JoystickButtonPressed:
				break;
			case sf::Event::JoystickButtonReleased:
				break;
			case sf::Event::JoystickMoved:
				break;

			// Window events
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::Resized:
				break;
			case sf::Event::LostFocus:
				break;
			case sf::Event::GainedFocus:
				break;

			// Keyboard events
			case sf::Event::KeyPressed:
				break;
			case sf::Event::KeyReleased:
				break;

			// Mouse events
			case sf::Event::MouseButtonPressed:
				break;
			case sf::Event::MouseWheelScrolled:
				break;
			case sf::Event::MouseMoved:
				break;

			default:
				std::cout << "Unknown event " << event.type << std::endl;
		}
	}
}

void drawFrame(sf::RenderWindow* window) {
	window->clear();

	window->draw(sprite);
	window->draw(text);

	window->display();
}


void updateState() {
	text.rotate(0.1f);
	sprite.rotate(0.1f);
}

void setup(sf::RenderWindow* window) {
	if (!texture.loadFromFile("sprite.png")) { /* Error */ }
	if (!font.loadFromFile("OCR-A.ttf")){ /* Error */ }
	
	sprite.setTexture(texture);
	
	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24); // in pixels, not points!
	text.setFillColor(sf::Color::Cyan);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.move(window->getSize().x / 2, window->getSize().y/2);
	
	window->setFramerateLimit(60);
	window->setActive();
}

int main(int argc, char* argv[]) {
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "My app");

	setup(window);

	while (window->isOpen()) {
		processEvents(window);
		updateState();
		drawFrame(window);
	}

}
