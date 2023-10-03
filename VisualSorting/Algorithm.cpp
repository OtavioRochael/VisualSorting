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

	if (sorted) {
		DiplayAlgorithm(i, -1, -1);
	}
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
			aux = v[menor];
			v[menor] = v[i];
			v[i] = aux;
		}
	}
	sorted = true;

	if (sorted) {
		DiplayAlgorithm(i, -1, -1);
	}
}

void Algorithm::insertionSort()
{
	int i, j, aux;
	for (i = 1; i < size; i++) {//vai da segunda posição em diante
		aux = v[i];
		j = i;
		while (j > 0 && v[j - 1] > aux)//enqto existe alguém maior
		{ //que aux, faz o deslocamento para direita
			v[j] = v[j - 1];
			j--;//duplicando esse elemento
			sf::sleep(sf::milliseconds(40));
			DiplayAlgorithm(i, j, aux);
		}
		v[j] = aux;//local correto em que posso substituir
	}
	sorted = true;

	if (sorted) {
		DiplayAlgorithm(i, -1, -1);
	}
}

void Algorithm::mergeSort(int in, int fim)
{
	int meio;
	if (in < fim)
	{
		meio = (in + fim) / 2;
		mergeSort(in, meio);//metade da esquerda
		mergeSort(meio + 1, fim);//metade da direita
		//intercala as duas metades ordenadas
		merge(v, in, meio, fim);
	}
}

void Algorithm::merge(std::vector<int>& v, int in, int meio, int fim)
{
	std::vector<int> aux;
	int p1, p2, tam, i, j, k, f1, f2;
	f1 = 0;
	f2 = 0;
	tam = fim - in + 1;
	p1 = in;
	p2 = meio + 1;
	for (i = 0; i < tam; i++)
	{
		if (f1 == 0 && f2 == 0)//nenhum dos subvetores acabou
		{
			if (v[p1] < v[p2])
			{
				aux[i] = v[p1]; p1++;
			}
			else
			{
				aux[i] = v[p2]; p2++;
			}
			if (p1 > meio) f1 = 1;//vetor acabou?
			if (p2 > fim) f2 = 1;
		}
		else//qual subvetor acabou?
		{
			if (f1 == 1)
			{
				aux[i] = v[p2]; p2++;
			}
			else
			{
				aux[i] = v[p1]; p1++;
			}
		}
	}
	//fim for

	for (j = 0; j < tam; j++) {
		k = in;
		k++;
		v[k] = aux[j];
		DiplayAlgorithm(i, j, k);
	}
	
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

int Algorithm::GetSize() const
{
	return size;
}
