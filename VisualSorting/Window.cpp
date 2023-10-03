#include "WIndow.hpp"

Window::Window(const std::string& title, const sf::Vector2u& size)
{
	Setup(title, size);
}

void Window::BeginDraw()
{
	window.clear();
}

void Window::EndDraw()
{
	window.display();
}

void Window::Update()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			isDone = true;
		}
	}
}

bool Window::IsDone()
{
	return isDone;
}

sf::Vector2u& Window::GetWindowSize()
{
	return windowSize;
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return &window;
}

void Window::Setup(const std::string& title, const sf::Vector2u& size)
{
	windowTitle = title;
	windowSize = size;
	isDone = false;
	Create();
}

void Window::Create()
{
	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle);
}

void Window::Destroy()
{
	if (!isDone)
		window.close();
}
