#pragma once
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<queue>
#include <vector>

using  namespace std;
class Graph
{
public:

	struct edge {
	public:
		int startVertex;
		int EndVertex;
		int Weight;
		edge() {
			startVertex = EndVertex = Weight = 0;
		}
		edge(int e, int w) {

			EndVertex = e;
			Weight = w;

		}

	};


	struct Gnode {
		string name;
		list <edge> edges;

		Gnode(string type) {
			name = type;

		}
	};

	int VertexNumber;
	int edges;
	vector <Gnode> vertices;




public:



	Graph() {
		edges = 0;
		VertexNumber = 0;
	}


	Graph(int k) {
		//vertices.capacity= k;
		VertexNumber = k;
	}
	void AddNode(string n, int i) {
		Gnode a(n);
		vertices.push_back(a);
	}

	void AddEdge(int s, int v, int w) {
		edge a(v, w);
		edge b(s, w);
		vertices[s].edges.push_back(a);
		vertices[v].edges.push_back(b);

	}
	void setvertice(int n) {
		VertexNumber = n;

	}

	void setedges(int n) {
		this->edges = n;
	}

	int size() {
		return vertices.size();
	}

	list<edge> getEdges(int node) {
		return vertices[node].edges;
	}

	std::string getNode(int index) {
		return vertices[index].name;
	}

	~Graph() {

	}


};

