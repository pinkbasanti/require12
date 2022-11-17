#include<iostream>
# define INF 99999
using namespace std;

// structure to represnt a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// function for bellman ford algorithm
void BellmanFord(Edge edges[], int V, int E, int src)
{
    // dist array to store shortest path
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
            cout << "Graph contains negative weight cycle";
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

// main function
int main(){
  
  
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    struct Edge edges[e];
    for(int i = 0; i < e; i++){
        cout << "Enter source, destination and weight of edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    BellmanFord(edges, v,e, src);

    return 0;
}

  /*
        you can try this sample input
        5
        8
        0 1 -1
        0 2 4
        1 2 3
        1 3 2
        1 4 2
        3 2 5
        3 1 1
        4 3 -3
        0
    */