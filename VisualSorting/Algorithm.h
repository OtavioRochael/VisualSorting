#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "WIndow.hpp"

class Algorithm
{
public:
	Algorithm(std::vector<int>& v, int size, int columWidth, sf::RenderWindow& window);
	void bubbleSort();
	void selectionSort();
	std::vector<int>& v;

	void DiplayAlgorithm(int i, int j, int menor);
	bool GetSorted() const;
private:
	sf::RenderWindow& window;
	int size;
	int first{ 0 };
	int columWidth;
	bool sorted{ false };
};

