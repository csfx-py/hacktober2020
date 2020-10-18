#include<iostream>
#include <limits.h>
#include <list>
#define NIL -1
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	void APUtil(int v, bool visited[], int disc[], int low[],int parent[], bool ap[]);
    void DFSUtil(int v, bool visited[]);
    bool isCyclicUtil(int v, bool visited[],int parent);
public:
	Graph(int V);
	void addEdge(int v, int w);
    void DFS(int v);
    void AP();
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}
void Graph::DFSUtil(int v, bool visited[])
{   //mark the current node as visited and print it
    visited[v]=true;
    cout << v << " ";
    //recur for all the vertices adjacent to this vertex
    list<int >:: iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
        DFSUtil(*i,visited);
}
void Graph::DFS(int v)
{
    bool *visited=new bool[V];
    for(int i=0;i< V;i++)
        visited[i]=false;
    //call the recursive helper function to print DFS traversal
    DFSUtil(v,visited);
}

void Graph::APUtil(int u, bool visited[], int disc[],int low[], int parent[], bool ap[])
{

	static int time = 0;
    int children = 0;// Count of children in DFS Tree
	visited[u] = true;// Mark the current node as visited
    disc[u] = low[u] = ++time;// Initialize discovery time and low value
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u
        if (!visited[v])
		{
			children++;
			parent[v] = u;
			APUtil(v, visited, disc, low, parent, ap);
            low[u] = min(low[u], low[v]);
            // u is an articulation point in following cases
			// (1) u is root of DFS tree and has two or more children.
			if (parent[u] == NIL && children > 1)
			ap[u] = true;
			// (2) If u is not root and low value of one of its child is more
			// than discovery value of u.
			if (parent[u] != NIL && low[v] >= disc[u])
			ap[u] = true;
			}	// Update low value of u for parent function calls.
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V]; // To store articulation points

	// Initialize parent and visited, and ap(articulation point) arrays
	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}
	// Call the recursive helper function to find articulation points
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			APUtil(i, visited, disc, low, parent, ap);

	// Now ap[] contains articulation points, print them
	for (int i = 0; i < V; i++)
		if (ap[i] == true)
			cout << i << " ";
}
// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }

        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}

// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))
             return true;

    return false;
}


// Driver program to test above function
int main()
{
	// Create graphs given in above diagrams
	cout << "\nArticulation points in first graph \n";
	Graph g(8);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(3, 6);
	g.addEdge(3, 7);
	g.addEdge(6, 7);
	g.addEdge(1, 0);
	g.addEdge(2, 1);
	g.addEdge(4, 1);
	g.addEdge(5, 1);
	g.addEdge(5, 2);
	g.addEdge(5, 4);
	g.addEdge(2, 0);
	g.addEdge(3, 0);
	g.addEdge(6, 3);
	g.addEdge(7, 3);
	g.addEdge(7, 6);
	g.AP();
	cout << "\nDFS traversal(starting from vertex 0)\n";
	g.DFS(0);
    g.isCyclic()?cout <<"\nGraph contains cycle\n":cout <<"\nGraph doesn't contain cycle\n";


	return 0;
}

