#include "Algorithm.h"
#include <iostream>
#include <chrono>
#include <thread>

Algorithm::Algorithm(std::vector<int>& v, int size,int columWidth, sf::RenderWindow& window) : v(v), size(size), columWidth(columWidth), window(window)
{
}

void Algorithm::bubbleSort()
{
	int i, aux, fim, troca;
	fim = size;
	do {
		troca = -1;
		for (i = 0; i < fim - 1; i++)
		{ //troca sempre que o elemento da esquerda for maior
			if (v[i] > v[i + 1])//realiza a troca
			{
				//sf::sleep(sf::milliseconds(25));
				DiplayAlgorithm(i, -1, i+1);

				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				troca = i;//marca se houve a troca
			}
		}

		fim--;
	} while (troca != -1);//enquanto tiver acontecido troca

	sorted = true;
}

void Algorithm::selectionSort()
{
	int i, j, menor, aux;
	for (i = 0; i < size - 1; i++)
	{
		menor = i;
		for (j = i + 1; j < size; j++)//procurando se tem menor à direita
		{ //atualiza a posição do novo menor
			//sf::sleep(sf::milliseconds(100));
			if (v[j] < v[menor]) menor = j;
			DiplayAlgorithm(i, j,menor);
		}
		if (i != menor)//encontrou um elemento menor à direita
		{//realiza a troca
			aux = v[menor]; v[menor] = v[i]; v[i] = aux;
		}
	}
	sorted = true;
}

void Algorithm::DiplayAlgorithm(int i, int j, int menor)
{
	window.clear();

	for (int k = 0; k < size; k++) {
		auto shape = sf::RectangleShape(sf::Vector2f(columWidth, v[k]));
		shape.setPosition(k * columWidth, window.getSize().y - v[k]);
		shape.setOutlineColor(sf::Color(211, 211, 211));
		shape.setOutlineThickness(0.2f);

		if (k == i) {
			shape.setFillColor(sf::Color::Green);
		}
		else if (k == j) {
			shape.setFillColor(sf::Color::Blue);
		}
		else if (k == menor) {
			shape.setFillColor(sf::Color::Yellow);
		}
		else{
			shape.setFillColor(sf::Color::White);
		}
		window.draw(shape);
	}

	window.display();
}

bool Algorithm::GetSorted() const
{
	return sorted;
}
