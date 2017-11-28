#ifndef STRING_GRAPH_NODE_H
#define STRING_GRAPH_NODE_H

#include "GraphNode.h"
#include <string>
using namespace std;

class StringGraphNode : public GraphNode<string, string>
{
public:

    StringGraphNode(const string &k, const string &v) : GraphNode(k, v) {};
};

#endif // !STRING_GRAPH_NODE_H
