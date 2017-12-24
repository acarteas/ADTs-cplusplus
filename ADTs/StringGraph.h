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
			string cur_key = keys.at(i);
			graph[cur_key] = new StringGraphNode{ cur_key };
		}

		for (auto key : edges) {
			for (int i = 0; i < key.second.size(); i++) {
				graph[key.first]->addEdge(graph[key.second.at(i)]);
			}
		}
	}

	unordered_map<string, StringGraphNode*> getGraph() {
		return graph;
	}


};


#endif // !GRAPH_H