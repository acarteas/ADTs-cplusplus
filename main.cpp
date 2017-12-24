#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"
#include "ADTs\StringGraph.h"

using namespace std;

int main(void)
{
    /*//maintains full collection of all vertices
    unordered_map<string, StringGraphNode*> graph{};

    //add vertices to graph
    graph["A"] = new StringGraphNode{ "A" };
    graph["B"] = new StringGraphNode{ "B" };
    graph["C"] = new StringGraphNode{ "C" };
    graph["D"] = new StringGraphNode{ "D" };
    graph["E"] = new StringGraphNode{ "E" };
    graph["F"] = new StringGraphNode{ "F" };

    //A is connected to B and F
    graph["A"]->addEdge(graph["B"]);
    graph["A"]->addEdge(graph["F"]);

    //B is connected to A, C, and E
    graph["B"]->addEdge(graph["A"]);
    graph["B"]->addEdge(graph["C"]);
    graph["B"]->addEdge(graph["F"]);*/

	unordered_map<string, vector<string>> edges{};
	unordered_map<string, StringGraphNode*> cur_graph{};
	vector<string> vertices;
	StringGraph Test_Graph;

	vertices = { "A", "B", "C", "D", "E", "F" };
	edges["A"] = { "B", "F" };
	edges["B"] = { "A", "C", "F" };

	Test_Graph.BulidGraph(vertices, edges);

	cur_graph = Test_Graph.getGraph();

	for (auto vertice : cur_graph) {
		StringGraphNode* cur_node = vertice.second;
		cur_node->getEdges();
		cur_node

		cout << vertice.first << " has edges: ";
	}

	system("Pause");

	

    return 0;
}