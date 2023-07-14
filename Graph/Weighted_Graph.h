#include "Graph.h"
const int infinity = 1000000;

class WeightedGraph : public Graph {
protected:
	int weight[GRAPH_SIZE][GRAPH_SIZE];
	int distance[GRAPH_SIZE];
	int connect[GRAPH_SIZE];
	int ClosestVertex()
	{
		int closest = 0, minDistance = infinity;
		for (int i = 0; i < GRAPH_SIZE; i++) {
			if (!visited[i] && distance[i] < minDistance) 
				{minDistance = distance[i]; closest = i; }
		}
		if (minDistance == infinity)
			cerr << "Graph is not connected";
		return closest;
	}
	void VisitVertex(int n, bool minSpanningTree) 
	{
		if (connect[n] == n) distance[n] = 0;
		visited[n] = true;
		cout << label[n] << "(connected to " << label[connect[n]]
			<< ", distance = " << distance[n] << ")" << endl;
		if (minSpanningTree) distance[n] = 0;
		for (int i = 0; i < GRAPH_SIZE; i++) {
			int d = distance[n] + weight[n][i];
			if (!visited[i] && d < distance[i]) {
				distance[i] = d; connect[i] = n;
			}
		}

	}
	void PerformAlgorithm(int n, bool mst)
	{
		ResetVisited();
		VisitVertex(n, mst);
		for (int i = 1; i < graphSize; i++) {
			VisitVertex(ClosestVertex(), mst);
		}
	}
public:
	WeightedGraph() 
	{
		ResetVisited();
		for (int i = 0; i < GRAPH_SIZE; i++) {
			for (int j = 0; j < GRAPH_SIZE; j++) {
				weight[i][j] = (i == j) ? 0 : infinity;
			}
		}
	}

	void InsertEdge(int n, int m, int w) {
		Graph::InsertEdge(n, m);
		weight[n][m] = weight[m][n] = w;
	}
	void DeleteEdge(int n, int m) 
	{
		Graph::DeleteEdge(n, m);
		weight[n][m] = weight[m][n] = infinity;
	}
	void PrintGraph()
	{
		for (int n = 0; n < GRAPH_SIZE; n++) {
			if (label[n] == NONE)continue;
			cout << "Vertex " << label[n] << " has neighbor ";
			for (int i = 0; i < GRAPH_SIZE; i++) {
				if (i != n && weight[n][i] < infinity)
					cout << label[i] << "(" << weight[n][i]<<")";
			}
			cout << endl;
		}
		
	}
	
	void MinSpanningTree(int n)
	{
		PerformAlgorithm(n, true);
	}
	void ShortestPath(int n)
	{
		PerformAlgorithm(n, false);
	}
	void ResetVisited() 
	{
		for (int i = 0; i < GRAPH_SIZE; i++) {
			visited[i] = false;
			distance[i] = infinity;
			connect[i] = i;
		}
	}
		
};