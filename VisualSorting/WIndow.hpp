#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window(const std::string& title, const sf::Vector2u& size);

	void BeginDraw();
	void EndDraw();

	void Update();

	bool IsDone();

	sf::Vector2u& GetWindowSize();

	sf::RenderWindow* GetRenderWindow();
private:
	void Setup(const std::string& title, const sf::Vector2u& size);
	void Create();
	void Destroy();

	sf::RenderWindow window;
	sf::Vector2u windowSize;
	std::string windowTitle;

	bool isDone{ false };
};