 #pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime> 
#include <stack>
#include "Smart_MultiDimAr.h"
#include "List.h"
#include <time.h> 
#include <iostream>
class node {
public:
	node() = default;
	node(float Radius, sf::Vector2f pos, sf::Color col, int hIndex, int vIndex);
	int thisX;
	int thisY;
	sf::CircleShape picture;
	int pre=0;
};

class Graph {
public:
	Graph() = default;
	Graph(unsigned int WinHeight, unsigned int WinWidth, sf::RenderWindow& win, sf::Color col = sf::Color::Blue);
	void Draw(sf::RenderWindow& win);
	void rebuildConnections();
	sf::Color GetBaseColor() { return baseColor; }
	sf::Color GetWallColor() { return baseWallColor; }
	double GetExecutionTime() { return LastAlgoExucutionTime; }
	void PaintToNormal();
	void Tarjan();
	void deepSearch(sf::RenderWindow& win);
	void deepSearchDFS(int** Adjact, sMatrix<bool>& checked, std::stack<node>& stc, node& current , bool withstack, sf::RenderWindow& win, sf::Color col, double& time);
	void deepSearchDFS(sMatrix<int>& counters, sMatrix<bool>& checked, std::stack<node>& stc, std::stack<node>& S, std::stack<node>& P, node& current,  sf::Color& col, int& counter);
	sMatrix<int> TranspoGraph();
	int winHeight;
	int winWidth;
	node** graph;
	int** AdjactMatrix;
	double lastTime = 0;
private:
	double LastAlgoExucutionTime = 0;
	void (Graph::* currentAlgoritm)(int thisX, int thisY, int startX, int startY, sf::RenderWindow& win) = nullptr;
	int wallsCount = 350;
	int wallsInARow = 12;
	int unitCurrentX = 0;
	int unitCurrentY = 0;
	sf::Color baseColor;
	sf::Color baseWallColor = sf::Color::Red;
	sf::VertexArray path;

};


