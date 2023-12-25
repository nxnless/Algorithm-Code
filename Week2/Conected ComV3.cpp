// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;
	
   public:

  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};
int count = 0;
// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];
  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i]){
    	DFS(*i);
    	count++;
	}
      
}

int main() {
  
 	int m,n;
	cin>>n;
	cin>>m;
	Graph g(n+1);
	int u,v;
	for(int i = 0 ; i<m ; i++){
		cin>>u;
		cin>>v;
		g.addEdge(u,v);
	}
	g.DFS(1);
	cout<<count;
	
}
