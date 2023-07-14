#include "Graph.h"

class DirectedGraph : public Graph {
	int inDegree[GRAPH_SIZE];
	int outDegree[GRAPH_SIZE];
public:
	DirectedGraph() {
		for (int i = 0; i < GRAPH_SIZE; i++)
		{
			outDegree[i] = inDegree[i] = 0;
		}
	}
	void InsertEdge(int n, int m)
	{
		CheckIndex(n); CheckIndex(m);
		adjacent[n][m] = true;
		outDegree[n]++; inDegree[m]++;
	}

	void CheckStronglyConnected(int n)
	{
		cout << "Depth First Search from " << label[n] << "->";
		DepthFirstSearch(n); cout << endl;
		bool isConnected = true;
		for (int i = 0; i < GRAPH_SIZE; i++)
		{
			if (label[i] != NONE && visited[i] == false)
				isConnected = false;
		}
		if (isConnected) cout << "Connected";
		else cout << "Unconnected";
		cout << " from " << label[n] << endl;
	}

	void DeleteEdge(int n, int m)
	{
		CheckIndex(n); CheckIndex(m);
		adjacent[n][m] = false;
		outDegree[n]--; inDegree[m];
	}
	void TopologicalSort(int n)
	{
		VisitVertex(n);
		for (int i = 0; i < GRAPH_SIZE; i++)
		{
			if (adjacent[n][i] && --inDegree[i] == 0)
				TopologicalSort(i);
		}
	}
};