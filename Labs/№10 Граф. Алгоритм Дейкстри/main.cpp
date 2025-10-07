#include<iostream>
using namespace std;
class Graph
{
private:
	int vertex;
	int** edges;
	void BadRange(int u, int v)
	{
		if (u < 0 || u >= vertex || v < 0 || v >= vertex) {
			throw ("Vertex out of bounds!");
		}
	}
public:
	Graph(int vert = 0)
	{
		vertex = vert;
		edges = new int* [vertex] {};
		for (size_t i = 0; i < vertex; ++i)
		{
			edges[i] = new int[vertex];
			for (size_t j = 0; j < vertex; ++j)
			{
				edges[i][j] = 0;
		  }
		}
	}
	~Graph()
	{
		for (size_t i = 0; i < vertex; ++i)
		{
			delete[] edges[i];
		}
		delete[] edges;
    }
	void addEdge(int u, int v, int weigh)
	{
		BadRange(u,v);
		edges[u][v] = weigh;

		edges[v][u] = weigh;
	}
	void removeEdge(int u, int v)
	{
		BadRange(u, v);
		edges[u][v] = 0;
		edges[v][u] = 0;
	}
	void clear()
	{
		for (size_t i = 0; i < vertex; ++i)
		{
			for (size_t j = 0; j < vertex; ++j)
			{
				edges[i][j] = 0;
			}
		}
	}
	int getWeight(int u, int v)
	{
		BadRange(u, v);
		return edges[u][v];
	}
	int minDistance(int* distance, bool* visited)
	{
		int min = INT_MAX;
		size_t min_index;
		for (size_t i = 0; i < vertex; ++i)
		{
			if (visited[i] == false && distance[i] <= min) {
				min = distance[i];
				min_index = i;
			}
		}
		return (int)min_index;
	}
	int* dejkstra(int start) {
		int* distance = new int[vertex];
		bool* visited = new bool[vertex];

		for (size_t i = 0; i < vertex; ++i) {
			distance[i] = INT_MAX;
			visited[i] = false;
		}
		distance[start] = 0;
			for (size_t count = 0; count < vertex - 1; ++count) {
				int u = minDistance(distance, visited);
				visited[u] = true;

				for (size_t v = 0; v < vertex; ++v) {
					if (!visited[v] && edges[u][v] && distance[u] != INT_MAX && distance[u] + edges[u][v] < distance[v]) {
						distance[v] = distance[u] + edges[u][v];
					}
				}
			}

		delete[] visited;
		return distance; 

	}

};
//int main() {
//	Graph g(5);
//	g.addEdge(0, 1, 10);
//	g.addEdge(0, 4, 5);
//	g.addEdge(1, 2, 1);
//	g.addEdge(1, 4, 2);
//	g.addEdge(2, 3, 4);
//	g.addEdge(3, 0, 7);
//	g.addEdge(4, 2, 9);
//	g.addEdge(4, 3, 2);
//
//	int* dist = g.dejkstra(0);
//	for (int i = 0; i < 5; ++i) {
//		cout << "Distance from 0 to " << i << " = " << dist[i] << endl;
//	}
//
//	delete[] dist;
//	return 0;
//}
