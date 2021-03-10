#include "Graph.h"


void Graph::Tarjan() {
	sMatrix<bool> checked(winWidth, winHeight, false);
	sMatrix<int> counters(winWidth, winHeight,0);
	std::stack<node> stc;
    std::stack<node> P;
    std::stack<node> S;
	int counter = 1;
	sf::Color col;
	deepSearchDFS(counters, checked, stc, S, P, graph[0][0], col, counter);

}
void Graph::deepSearchDFS(sMatrix<int>& counters, sMatrix<bool>& checked, std::stack<node>& stc, std::stack<node>& S, std::stack<node>& P, node& current, sf::Color& col,int& counter) {
	counters[current.thisX][current.thisY] = counter;
	checked[current.thisX][current.thisY] = true;
	counter++;
	S.push(current);
	P.push(current);

	//Вниз
	if (current.thisY < winHeight - 1 && checked[current.thisX][current.thisY + 1] == false && AdjactMatrix[current.thisX * winHeight + current.thisY][3] == 1) {
		if (counters[current.thisX][current.thisY + 1] == 0) {
			deepSearchDFS(counters, checked, stc, S, P, graph[current.thisX][current.thisY + 1],  col, counter);
		}
		else if (graph[current.thisX][current.thisY + 1].picture.getFillColor()==baseColor) {
			while (true) {
				node cur = P.top();
				if (counters[current.thisX][current.thisY +1] >= counters[cur.thisX][cur.thisY])break;
				P.pop();
			}
		}
		
	}
	//Вправо
	if (current.thisX < winWidth - 1 && checked[current.thisX + 1][current.thisY] == false && AdjactMatrix[current.thisX * winHeight + current.thisY][1] == 1) {
		if (counters[current.thisX + 1][current.thisY] == 0) {
			deepSearchDFS(counters, checked, stc, S, P, graph[current.thisX + 1][current.thisY],  col, counter);
		}
		else if (graph[current.thisX + 1][current.thisY].picture.getFillColor() == baseColor) {
			while (true) {
				node cur = P.top();
				if (counters[current.thisX + 1][current.thisY] >= counters[cur.thisX][cur.thisY])break;
				P.pop();
			}
		}
	}
	//Вверх
	if (current.thisY > 0 && checked[current.thisX][current.thisY - 1] == false && AdjactMatrix[current.thisX * winHeight + current.thisY][2] == 1) {
		if (counters[current.thisX][current.thisY - 1] == 0) {
			deepSearchDFS(counters, checked, stc, S, P, graph[current.thisX][current.thisY - 1],  col, counter);
		}
		else if (graph[current.thisX][current.thisY - 1].picture.getFillColor() == baseColor) {
			while (true) {
				node cur = P.top();
				if (counters[current.thisX][current.thisY-1] >= counters[cur.thisX][cur.thisY])break;
				P.pop();
			}
		}
	}
	//Налево
	if (current.thisX > 0 && checked[current.thisX - 1][current.thisY] == false && AdjactMatrix[current.thisX * winHeight + current.thisY][0] == 1) {
		if (counters[current.thisX-1][current.thisY] == 0) {
			deepSearchDFS(counters, checked, stc, S, P, graph[current.thisX-1][current.thisY],  col, counter);
		}
		else if (graph[current.thisX - 1][current.thisY].picture.getFillColor() == baseColor) {
			while (true) {
				node cur = P.top();
				if (counters[current.thisX-1][current.thisY] >= counters[cur.thisX][cur.thisY]) break;
				P.pop();
			}
		}
	}
	col = sf::Color(rand()%240, rand() % 240, rand() % 240);
	if (P.top().thisX == current.thisX && P.top().thisY == current.thisY) {
		while (true) {
			node cur = S.top();
			graph[cur.thisX][cur.thisY].picture.setFillColor(col);
			if (current.thisX == cur.thisX && current.thisY == cur.thisY) break;
			S.pop();
		}

	}


}