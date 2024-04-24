    #include <stdio.h>  
    
    #define INF 9999  
    #define MAX 10  
    
    void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start);  
    
    void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) {  
      int cost[MAX][MAX], distance[MAX], visited_nodes[MAX] = {0}, counter, minimum_distance, next_node, i, j;  
    
      for (i = 0; i < size; i++)  
        for (j = 0; j < size; j++)  
          cost[i][j] = Graph[i][j] ? Graph[i][j] : INF;  
    
      for (i = 0; i < size; i++) {  
        distance[i] = cost[start][i];  
        visited_nodes[i] = 0;  
      }  
    
      distance[start] = 0;  
      visited_nodes[start] = 1;  
      counter = 1;  
    
      while (counter < size - 1) {  
        minimum_distance = INF;  
    
        for (i = 0; i < size; i++)  
          if (distance[i] < minimum_distance && !visited_nodes[i]) {  
            minimum_distance = distance[i];  
            next_node = i;  
          }  
    
        visited_nodes[next_node] = 1;  
        for (i = 0; i < size; i++)  
          if (!visited_nodes[i])  
            if (minimum_distance + cost[next_node][i] < distance[i]) {  
              distance[i] = minimum_distance + cost[next_node][i];  
            }  
        counter++;  
      }  
    
      for (i = 0; i < size; i++)  
        if (i != start) {  
          printf("\nDistance from the Source Node to %d: %d", i, distance[i]);  
        }  
    }  
    
    int main() {  
      int Graph[MAX][MAX] = {
        {0, 4, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0},
        {0, 0, 7, 0, 9, 14, 0},
        {0, 0, 0, 9, 0, 10, 2},
        {0, 0, 4, 14, 10, 0, 2},
        {0, 0, 0, 0, 2, 0, 1}
      };
      int size = 7, source = 0;  
    
      DijkstraAlgorithm(Graph, size, source);  
    
      return 0;  
    }  