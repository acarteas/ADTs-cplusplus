#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include "StringGraphNode.h"
using namespace std;

class StringGraph {
protected:
	unordered_map<string, StringGraphNode*> graph{};

public:

	void BulidGraph(vector<string> keys, unordered_map<string, vector<string>> edges) {
		for (int i = 0; i < keys.size(); i++) {
			addVertice(keys.at(i));
		}

		for (auto key : edges) {
			for (int i = 0; i < key.second.size(); i++) {
				addEdge(key.first, key.second.at(i));
			}
		}
	}

	unordered_map<string, StringGraphNode*> getGraph() {
		return graph;
	}

	void addEdge(string key, string value) {
		graph[key]->addEdge[graph[value]];
	}

	void addVertice(string key) {
		graph[key] = new StringGraphNode{ key };
	}

	void printGraph() {
		for (auto vertice : graph) {
			StringGraphNode* cur_node = vertice.second;
			vector < GraphNode<string, string>*> cur_edge = cur_node->getEdges();
			cout << vertice.first << " has edges: ";
			for (int i = 0; i < cur_edge.size(); i++) {
				cout << cur_edge.at(i)->getValue() << ", " ;
			}
			cout << endl;
		}
	}

	
};


#endif // !GRAPH_H