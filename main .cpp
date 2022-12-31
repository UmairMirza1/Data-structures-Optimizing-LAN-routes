
#include "Graph.h"
#include "Minheap.h"
#include<iostream>
#include<fstream>
#include <limits>

using namespace std;
Graph InputGraph(string file) {
	ifstream lis;
	lis.open(file);
	while (!lis.eof()) {
		if (lis.is_open())
		{

			int vert = 0;
			lis >> vert;
			Graph g;
			char temp;
			for (int i = 0; i < vert; i++) {
				//char temp;
				lis.get(temp);
				//int a = temp;
				lis.ignore();
				string  n;
				getline(lis, n);
				g.AddNode(n, i);


			}
			lis >> vert;
			int NumOfEdge = vert;
			for (int i = 0; i < NumOfEdge; i++)
			{
				int start = 0, end = 0, weight = 0;
				lis >> start;
				lis.ignore();
				lis >> end;
				lis.ignore();
				lis >> weight;
				g.AddEdge(start -1, end-1, weight);
				lis.ignore();

			}
			return g;

		}


	}

}

void AddVertex(Graph a, string n, int b) {
	a.AddNode(n, b);

}
void AddEdge(Graph a, int s, int e, int w) {
	a.AddEdge(s, e, w);
}
void PrintSetofEdges() {

}

void mst() {
	Graph g = InputGraph("graph.txt");

	struct heapNode {
		int weight;
		int parent;
		int node;

		heapNode() {}

		heapNode(int w, int p, int n): weight(w), parent(p), node(n) {}

		bool operator<(const heapNode& other) {
			return weight < other.weight;
		}

		bool operator>(const heapNode& other) 
		{
			return weight > other.weight;
		}
	};

	Minheap<int, heapNode> heap(g.size());

	heap.insert(0, heapNode(0, -1, 0)); //set weight of first node as 0

	for (int i = 0; i < g.size(); i++) {
		heap.insert(i, heapNode(std::numeric_limits<int>::max(), -1, i));
	}

	std::vector<bool> visited(g.size(), false);

	while (!heap.isEmpty()) {
		heapNode n = heap.getMinValue();
		heap.extractmin();
		visited[n.node] = true;

		if (n.weight != std::numeric_limits<int>::max()) {

			if (n.parent != -1) 
				cout << g.getNode( n.parent) << " <--> " << g.getNode(n.node) << "\n";

			list<Graph::edge> edges = g.getEdges(n.node);

			for (auto i = edges.begin(); i != edges.end(); ++i) {
				heapNode temp(0, n.node, 0);
				heap.search(i->EndVertex, temp);
				if (n.weight + i->Weight < temp.weight && !visited[i->EndVertex]) {
					temp.parent = n.node;
					temp.weight = n.weight + i->Weight;
					heap.update(temp.node, temp);
				}
			}
		}
	}

}

int main() {

	mst();
	system("pause");
}