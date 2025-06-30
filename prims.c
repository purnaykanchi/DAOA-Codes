#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
int n=1;
int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
int printMST(int parent[], int graph[n][n]){
    int total_cost = 0;
	printf("Edge \tWeight\n");
	for (int i = 1; i < n; i++){
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
		total_cost = total_cost+graph[i][parent[i]];
	}
	printf("Total Cost = %d",total_cost);
}
void primMST(int graph[n][n]){
	int parent[n];
	int key[n];
	bool mstSet[n];
	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1; 
	for (int count = 0; count < n - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < n; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}
int main(){
    int i, j, total_cost;
  printf("Enter the number of nodes : ");
  scanf("%d",&n);
  int graph[n][n];
  printf("Enter the cost adjacency matrix:\n");
  for(i=0;i<n;i++){
      for(j=0;j<n;j++){
          scanf("%d",&graph[i][j]);
      }
  }
	primMST(graph);
	return 0;
}