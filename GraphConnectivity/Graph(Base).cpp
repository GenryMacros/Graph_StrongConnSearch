#include "Graph.h"

void Graph::deepSearch(sf::RenderWindow& win) {
	double seconds=0;
	sMatrix<bool> checked(winWidth, winHeight, false);
	std::stack<node> stc;
	node current = graph[0][0];
	checked[0][0] = true;
	stc.push(graph[0][0]);
	bool endWhile = true;
	clock_t start = clock();
	while (endWhile) {

		deepSearchDFS(AdjactMatrix, checked, stc, current, true, win, sf::Color::Cyan, seconds);
		
		for (int i = 0; i < winWidth;i++) {
			bool out = false;
			for (int j = 0; j < winHeight;j++) {
				if (!checked[i][j]) {
					current = graph[i][j];
					checked[i][j] = true;
					stc.push(graph[i][j]);
					out = true;
					break;
				}
			}
			if (out) break;
			if (i + 1 == winWidth) {
			    endWhile = false;
			}
		}

	
		
	}
	sMatrix<int> reversedCon = TranspoGraph();

	checked.ResetValues(false);
	sf::Color componentCol(rand() % 200, rand() % 200, rand() % 200);
	while (!stc.empty()) {
		node current = stc.top();
		if(checked[current.thisX][current.thisY]) {
			stc.pop();
			continue;
		}
	
		deepSearchDFS(reversedCon.matrix, checked, stc, current, false, win, componentCol, seconds);
		stc.pop();
		componentCol = sf::Color(rand() % 230, rand() % 230, rand() % 230);
	}
	clock_t end = clock();
	seconds += (double)(end - start) / CLOCKS_PER_SEC;
	lastTime = seconds*1000;

}
void Graph::deepSearchDFS(int** Adjact,sMatrix<bool>& checked, std::stack<node>& stc, node& current,bool withstack, sf::RenderWindow& win,sf::Color col, double& time) {
	clock_t start = clock();
	graph[current.thisX][current.thisY].picture.setFillColor(col);
	win.clear();
	Draw(win);
	win.display();
	clock_t end = clock();
	double anTime= (double)(end - start) / CLOCKS_PER_SEC;
	time -= anTime;
	//Вниз
	if (current.thisY < winHeight - 1 && checked[current.thisX][current.thisY + 1] == false && Adjact[current.thisX * winHeight + current.thisY][3] == 1) {
		checked[current.thisX][current.thisY + 1] = true;
		if(withstack) stc.push(graph[current.thisX][current.thisY + 1]);
		deepSearchDFS(Adjact,checked, stc, graph[current.thisX][current.thisY + 1], withstack, win, col, time);


	}
	//Вправо
	if (current.thisX < winWidth - 1 && checked[current.thisX + 1][current.thisY] == false && Adjact[current.thisX * winHeight + current.thisY][1] == 1) {
		checked[current.thisX + 1][current.thisY] = true;
		if (withstack) stc.push(graph[current.thisX + 1][current.thisY]);
		deepSearchDFS(Adjact,checked, stc, graph[current.thisX + 1][current.thisY], withstack, win, col, time);

	}
	//Вверх
	if (current.thisY > 0 && checked[current.thisX][current.thisY - 1] == false && Adjact[current.thisX * winHeight + current.thisY][2] == 1) {
		checked[current.thisX][current.thisY - 1] = true;
		if (withstack) stc.push(graph[current.thisX][current.thisY - 1]);
		deepSearchDFS(Adjact,checked, stc, graph[current.thisX][current.thisY - 1], withstack, win, col, time);

	}
	//Налево
	if (current.thisX > 0 && checked[current.thisX - 1][current.thisY] == false && Adjact[current.thisX * winHeight + current.thisY][0] == 1) {
		checked[current.thisX - 1][current.thisY] = true;
		if (withstack) stc.push(graph[current.thisX - 1][current.thisY]);
		deepSearchDFS(Adjact,checked, stc, graph[current.thisX - 1][current.thisY], withstack, win, col, time);

	}
	return;
}

sMatrix<int> Graph::TranspoGraph() {
	int length = winHeight * winWidth;
	sMatrix<int> Transpo(length,4,0);
	sMatrix<bool> checeked(length, 4,false);
	int curY = 0;
	int curX = 0;
	for (int i = 0; i < length; i++) {
		if (AdjactMatrix[i][0] == 1 && curY > 0) {
			if (AdjactMatrix[i - winHeight][1] == 0 && !checeked[i][0] && !checeked[i - winHeight][1] ) {
				Transpo[i][0] = 0;
				Transpo[i - winHeight][1] = 1;
				checeked[i][0] = true;
				checeked[i - winHeight][1] = true;
			}
			else if (AdjactMatrix[i - winHeight][1] == 1 && !checeked[i][0] && !checeked[i - winHeight][1]) {
				Transpo[i][0] = 1;
				Transpo[i - winHeight][1] = 1;
				checeked[i][0] = true;
				checeked[i - winHeight][1] = true;
			}
		}
		if (AdjactMatrix[i][1] == 1 && curY < winHeight - 1) {
			if (AdjactMatrix[i + winHeight][0] == 0 && !checeked[i][1] && !checeked[i + winHeight][0]) {
				Transpo[i][1] = 0;
				Transpo[i + winHeight][0] = 1;
				checeked[i][1] = true;
				checeked[i + winHeight][0] = true;
			}
			else if (AdjactMatrix[i + 1][0] == 1) {
				Transpo[i][1] = 1;
				Transpo[i + winHeight][0] = 1;
				checeked[i][1] = true;
				checeked[i + winHeight][0] = true;
			}
		}
		if (AdjactMatrix[i][2] == 1 && curX > 0) {
			if (AdjactMatrix[i - 1][3] == 0 && !checeked[i][2] && !checeked[i - 1][3]) {
				Transpo[i][2] = 0;
				Transpo[i - 1][3] = 1;
				checeked[i][2] = true;
				checeked[i - 1][3] = true;
			}
			else if (AdjactMatrix[i - 1][3]==1 && !checeked[i][2] && !checeked[i - 1][3]) {
				Transpo[i][2] = 1;
				Transpo[i - 1][3] = 1;
				checeked[i][2] = true;
				checeked[i - 1][3] = true;

			}
		}
		if (AdjactMatrix[i][3] == 1 && curX < winWidth - 1) {
			if (AdjactMatrix[i + 1][2] == 0 && !checeked[i][3] && !checeked[i + 1][2]) {
				Transpo[i][3] = 0;
				Transpo[i + 1][2] = 1;
				checeked[i][3] = true;
				checeked[i + 1][2] = true;
			}
			else if (AdjactMatrix[i + 1][2] == 1 && !checeked[i][3] && !checeked[i + 1][2]) {
				Transpo[i][3] = 1;
				Transpo[i + 1][2] = 1;
				checeked[i][3] = true;
				checeked[i + 1][2] = true;
			}
		}
		curX++;
		if (curX == winWidth) {
			curY++;
			curX = 0;
		}

	}

	return Transpo;
} 