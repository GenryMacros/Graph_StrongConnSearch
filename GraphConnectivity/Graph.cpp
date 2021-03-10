#include "Graph.h"

Graph::Graph(unsigned int WinHeight, unsigned int WinWidth, sf::RenderWindow& win, sf::Color col) {
	srand(static_cast<unsigned int>(time(0)));
	int multiplier = 20;
	winHeight = WinHeight / multiplier;
	winWidth = (130 + WinWidth) / multiplier;
	std::cout << "ElemsCount:" << winHeight * winWidth << std::endl;
	AdjactMatrix = new int* [winWidth * winHeight];
	for (int i = 0; i <(winWidth * winHeight); i++) {
		AdjactMatrix[i] = new int[4];	
		for (int j = 0; j < 4; j++) {
			AdjactMatrix[i][j] = 0;
		}
	}
	graph = new node * [winWidth];
	baseColor = col;
	float curX = 0.5;
	float curY = 0.5;
	float Xstep =  2*multiplier;
	float Ystep =  2*multiplier;
	int chance = 5;
	for (int x = 0; x < winWidth; x++) {
		graph[x] = new node[winHeight];
		for (int y = 0; y < winHeight; y++) {
			graph[x][y] = node(12, sf::Vector2f(curX, curY), col, x, y);
			curY += Ystep;
			int wallNum = rand() % 10;
			//Стрелка влево
			if (x - 1 > 0 && wallNum > chance) AdjactMatrix[x * winHeight + y][0] = 1;
			wallNum = rand() % 10;
			//Стрелка вправо
			if (x < winWidth-1 && wallNum > chance) AdjactMatrix[x * winHeight + y][1] = 1;
			wallNum = rand() % 10;
			//Стрелка вверх
			if (y - 1 > 0 && wallNum> chance) AdjactMatrix[x * winHeight + y][2] = 1;
			wallNum = rand() % 10;
			//Стрелка вниз
			if (y  < winHeight-1 && wallNum> chance) AdjactMatrix[x * winHeight + y][3] = 1;
				
		}
		curX += Xstep;
		curY = 0.5;
	}
	
}
void Graph::Draw(sf::RenderWindow& win) {

	for (int i = 0; i < winWidth; i++) {
		for (int j = 0; j < winHeight; j++) {
			if (AdjactMatrix[i * winHeight + j][0] == 1) {
				sf::Vector2f centerPos(graph[i][j].picture.getPosition().x + graph[i][j].picture.getRadius(),graph[i][j].picture.getPosition().y + graph[i][j].picture.getRadius());
				sf::Vertex dot1(centerPos);
				centerPos = sf::Vector2f(graph[i - 1][j].picture.getPosition().x + graph[i - 1][j].picture.getRadius(), graph[i - 1][j].picture.getPosition().y + graph[i-1][j].picture.getRadius());
				sf::Vertex dot2(centerPos);
				sf::VertexArray ver0;
				centerPos = sf::Vector2f(graph[i - 1][j].picture.getPosition().x + 2.5*graph[i - 1][j].picture.getRadius(), graph[i - 1][j].picture.getPosition().y + graph[i - 1][j].picture.getRadius()/1.6);
				sf::Vertex dot3(centerPos);
				centerPos = sf::Vector2f(graph[i - 1][j].picture.getPosition().x + 2.5*graph[i - 1][j].picture.getRadius(), graph[i - 1][j].picture.getPosition().y + graph[i - 1][j].picture.getRadius() + graph[i - 1][j].picture.getRadius() / 2 );
				sf::Vertex dot4(centerPos);
				centerPos = sf::Vector2f(dot2.position.x + graph[i-1][j].picture.getRadius(), dot2.position.y );
				sf::Vertex dot5(centerPos);
				ver0.append(dot3);
				ver0.append(dot5);
				ver0.append(dot4);
				ver0.setPrimitiveType(sf::PrimitiveType::LineStrip);
				sf::VertexArray ver;
				ver.append(dot1);
				ver.append(dot2);
				ver.setPrimitiveType(sf::PrimitiveType::Lines);
				win.draw(ver);
				win.draw(ver0);
			}
			if (AdjactMatrix[i * winHeight + j][1] == 1) {
				sf::Vector2f centerPos(graph[i][j].picture.getPosition().x + graph[i][j].picture.getRadius(), graph[i][j].picture.getPosition().y + graph[i][j].picture.getRadius());
				sf::Vertex dot1(centerPos);
				centerPos = sf::Vector2f(graph[i + 1][j].picture.getPosition().x + graph[i + 1][j].picture.getRadius(), graph[i + 1][j].picture.getPosition().y + graph[i + 1][j].picture.getRadius());
				sf::Vertex dot2(centerPos);
				sf::VertexArray ver0;
				centerPos = sf::Vector2f(graph[i + 1][j].picture.getPosition().x - graph[i + 1][j].picture.getRadius()/2, graph[i + 1][j].picture.getPosition().y + graph[i + 1][j].picture.getRadius() / 1.6);
				sf::Vertex dot3(centerPos);
				centerPos = sf::Vector2f(graph[i + 1][j].picture.getPosition().x - graph[i + 1][j].picture.getRadius()/2, graph[i + 1][j].picture.getPosition().y + graph[i + 1][j].picture.getRadius() + graph[i + 1][j].picture.getRadius() / 2);
				sf::Vertex dot4(centerPos);
				centerPos = sf::Vector2f(dot2.position.x - graph[i+1][j].picture.getRadius(), dot2.position.y);
				sf::Vertex dot5(centerPos);
				ver0.append(dot3);
				ver0.append(dot5);
				ver0.append(dot4);
				ver0.setPrimitiveType(sf::PrimitiveType::LineStrip);
				sf::VertexArray ver;
				ver.append(dot1);
				ver.append(dot2);
				ver.setPrimitiveType(sf::PrimitiveType::Lines);
				win.draw(ver);
				win.draw(ver0);


			}
			if (AdjactMatrix[i * winHeight + j][2] == 1) {
				sf::Vector2f centerPos(graph[i][j].picture.getPosition().x + graph[i][j].picture.getRadius(), graph[i][j].picture.getPosition().y + graph[i][j].picture.getRadius());
				sf::Vertex dot1(centerPos);
				centerPos = sf::Vector2f(graph[i][j-1].picture.getPosition().x + graph[i][j-1].picture.getRadius(), graph[i][j-1].picture.getPosition().y + graph[i][j-1].picture.getRadius());
				sf::Vertex dot2(centerPos);
				sf::VertexArray ver0;
				centerPos = sf::Vector2f(graph[i][j-1].picture.getPosition().x + graph[i][j-1].picture.getRadius() / 1.6, graph[i][j - 1].picture.getPosition().y + 2.5*graph[i][j - 1].picture.getRadius());
				sf::Vertex dot3(centerPos);
				centerPos = sf::Vector2f(graph[i][j - 1].picture.getPosition().x + graph[i][j-1].picture.getRadius() + graph[i][j-1].picture.getRadius() / 2, graph[i][j - 1].picture.getPosition().y + 2.5 * graph[i][j - 1].picture.getRadius());
				sf::Vertex dot4(centerPos);
				centerPos = sf::Vector2f(dot2.position.x, dot2.position.y + graph[i][j - 1].picture.getRadius());
				sf::Vertex dot5(centerPos);
				ver0.append(dot3);
				ver0.append(dot5);
				ver0.append(dot4);
				ver0.setPrimitiveType(sf::PrimitiveType::LineStrip);
				sf::VertexArray ver;
				ver.append(dot1);
				ver.append(dot2);
				ver.setPrimitiveType(sf::PrimitiveType::Lines);
				win.draw(ver);
				win.draw(ver0);
			}
			if (AdjactMatrix[i * winHeight + j][3] == 1) {
				sf::Vector2f centerPos(graph[i][j].picture.getPosition().x + graph[i][j].picture.getRadius(), graph[i][j].picture.getPosition().y + graph[i][j].picture.getRadius());
				sf::Vertex dot1(centerPos);
				centerPos = sf::Vector2f(graph[i][j+1].picture.getPosition().x + graph[i][j+1].picture.getRadius(), graph[i][j+1].picture.getPosition().y + graph[i][j+1].picture.getRadius());
				sf::Vertex dot2(centerPos);
				sf::VertexArray ver0;
				centerPos = sf::Vector2f(graph[i][j + 1].picture.getPosition().x + graph[i][j + 1].picture.getRadius() / 1.6, graph[i][j + 1].picture.getPosition().y - 0.5 * graph[i][j + 1].picture.getRadius());
				sf::Vertex dot3(centerPos);
				centerPos = sf::Vector2f(graph[i][j + 1].picture.getPosition().x + graph[i][j + 1].picture.getRadius() + graph[i][j + 1].picture.getRadius() / 2, graph[i][j + 1].picture.getPosition().y - 0.5 * graph[i][j + 1].picture.getRadius());
				sf::Vertex dot4(centerPos);
				centerPos = sf::Vector2f(dot2.position.x, dot2.position.y - graph[i][j + 1].picture.getRadius());
				sf::Vertex dot5(centerPos);
				ver0.append(dot3);
				ver0.append(dot5);
				ver0.append(dot4);
				ver0.setPrimitiveType(sf::PrimitiveType::LineStrip);
				sf::VertexArray ver;
				ver.append(dot1);
				ver.append(dot2);
				ver.setPrimitiveType(sf::PrimitiveType::Lines);
				win.draw(ver);
				win.draw(ver0);
			}
		}
	}
	for (int i = 0; i < winWidth; i++) {
		for (int j = 0; j < winHeight; j++) {
			win.draw(graph[i][j].picture);
		}
	}

}

node::node(float Radius, sf::Vector2f pos, sf::Color col, int x, int y) {
	picture.setRadius(Radius);
	picture.setFillColor(col);
	picture.setPosition(pos);
	thisX = x;
	thisY = y;
}