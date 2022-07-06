
#include <bits/stdc++.h>
struct Edge {
	int src, dest, weight;
};

struct Graph {

	int U, F;

	struct Edge* edge;
};

struct Graph* createGraph(int U, int F)
{
	struct Graph* graph = new Graph;
	graph->U = U;
	graph->F = F;
	graph->edge = new Edge[F];
	return graph;
}

void printArr(int dist[], int n)
{
	printf("Vertex Distance from Source Will be\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph* graph, int src)
{
	int U = graph->U;
	int F = graph->F;
	int dist[U];


	for (int i = 0; i < U; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= U - 1; i++) {
		for (int j = 0; j < F; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX
				&& dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	
	for (int i = 0; i < F; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX
			&& dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return;
		}
	}

	printArr(dist, U);

	return;
}

int main()
{
	
	int U = 5; 
	int F = 8; 
	struct Graph* graph = createGraph(U, F);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -2;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 5;

	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 6;

	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 1;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 2;

	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = 2;

	BellmanFord(graph, 0);

	return 0;
}
