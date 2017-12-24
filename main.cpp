#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"
#include "ADTs\StringGraph.h"
#include "ADTs\GraphNode.h"

using namespace std;

int main(void)
{
	unordered_map<string, vector<string>> edges{};
	vector<string> vertices;
	StringGraph Test_Graph;

	vertices = { "A", "B", "C", "D", "E", "F" };
	edges["A"] = { "B", "F" };
	edges["B"] = { "A", "C", "F" };

	Test_Graph.BulidGraph(vertices, edges);

	Test_Graph.printGraph();

	system("Pause");
    return 0;
}