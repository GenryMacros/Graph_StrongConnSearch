#include "Graph.h"


void Graph::rebuildConnections() {
	PaintToNormal();
	int chance = 5;
	for (int x = 0; x < winWidth; x++) {
		for (int y = 0; y < winHeight; y++) {
			int curIndex = x * winHeight + y;
			int wallNum = rand() % 10;
			//Стрелка влево
			AdjactMatrix[curIndex][0] = 0;
			if (x - 1 > 0 && wallNum > chance) AdjactMatrix[curIndex][0] = 1;
			wallNum = rand() % 10;
			//Стрелка вправо
			AdjactMatrix[curIndex][1] = 0;
			if (x < winWidth - 1 && wallNum > chance) AdjactMatrix[curIndex][1] = 1;
			wallNum = rand() % 10;
			//Стрелка вверх
			AdjactMatrix[curIndex][2] = 0;
			if (y - 1 > 0 && wallNum > chance) AdjactMatrix[curIndex][2] = 1;
			wallNum = rand() % 10;
			//Стрелка вниз
			AdjactMatrix[curIndex][3] = 0;
			if (y  < winHeight - 1 && wallNum> chance) AdjactMatrix[curIndex][3] = 1;

		}

	}
}
void Graph::PaintToNormal() {
	for (int x = 0; x < winWidth; x++) {
		for (int y = 0; y < winHeight; y++) {
			graph[x][y].picture.setFillColor(baseColor);
		}
	
	}
}

