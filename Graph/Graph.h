#include <iostream>
#include <cstdlib>
using namespace std;
#define GRAPH_SIZE 20
const char NONE = '.';
void Error(string s) { cerr << s; exit(-1); }

class Graph {
protected:
	char label[GRAPH_SIZE];
	bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
	int degree[GRAPH_SIZE];
	bool visited[GRAPH_SIZE];
	int graphSize;
	void CheckIndex(int n) 
	{
		if (n < 0 || n >= GRAPH_SIZE)
			Error("Illegal index");
	}
	void VisitVertex(int n) 
	{
		visited[n] = true;
		cout << label[n] << " ";
	}
	void DepthFirstSearchRecursion(int n) {
		if (visited[n]) return;
		VisitVertex(n);
		for (int i = 0; i < GRAPH_SIZE; i++) {
			if (adjacent[n][i])
				DepthFirstSearchRecursion(i);
		}
	}
public:
	Graph()
	{
		graphSize = 0;
		for (int i = 0; i < GRAPH_SIZE; i++) {
			label[i] = NONE;
			degree[i] = 0;
			visited[i] = false;
			for (int j = 0; j < GRAPH_SIZE; j++) {
				adjacent[i][j] = false;
			}
		}
	}

	void InsertVertex(int n, char c) {
		CheckIndex(n);
		if (label[n] != NONE) Error("Occupied");
		label[n] = c; graphSize++;
	}

	void InsertEdge(int n, int m) {
		CheckIndex(n); CheckIndex(m);
		adjacent[n][m] = adjacent[m][n] = true;
		degree[n]++; degree[m]++;
	}

	void DeleteVertex(int n)
	{
		CheckIndex(n);
		if (label[n] == NONE)
			Error("No vertex to delete");
		for (int i = 0; i < GRAPH_SIZE; i++) {
			if (adjacent[n][i] || adjacent[i][n]) {
				cout << "Delete edges first" << endl;
				return;
			}
		}
		label[n] = NONE; graphSize--;
	}
	void DeleteEdge(int n, int m) {
		CheckIndex(n); CheckIndex(m);
		adjacent[n][m] = adjacent[m][n] = false;
		degree[n]--; degree[m]--;
	}

	void PrintGraph() {
		for (int n = 0; n < GRAPH_SIZE; n++) {
			if (label[n] == NONE) continue;
			cout << "Vertex " << label[n] << " has neighbor";
			for (int i = 0; i < GRAPH_SIZE; i++) {
				if (adjacent[n][i]) cout << label[i] << " ";
			}
			cout << endl;
		}
	}
	void DepthFirstSearch(int n)
	{
		ResetVisited();
		DepthFirstSearchRecursion(n);
	}

	void BreadthFirstSearch(int n);
	void CheckConnected() {
		cout << "Depth First Search: ";
		DepthFirstSearch(0); cout << endl;
		bool isConnected = true;
		for (int i = 0; i < GRAPH_SIZE; i++) {
			if (label[i] != NONE && visited[i] == false)
				isConnected = false;
		}
		if (isConnected)
			cout << "Connected Graph" << endl;
		else
			cout << "Unconnected Graph" << endl;
	}
	void ResetVisited() {
		for (int i = 0; i < GRAPH_SIZE; i++) {
			visited[i] = false;
		}
	}
};