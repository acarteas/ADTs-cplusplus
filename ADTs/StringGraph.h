	#ifndef GRAPH_H
	#define GRAPH_H

	#include <unordered_map>
	#include <vector>
	#include "GraphNode.h"
	#include "StringGraphNode.h"
	#include <stack>
	using namespace std;

	class StringGraph {
	protected:
		//Stored Strings in Graph
		unordered_map<string, StringGraphNode*> graph{};
		//number of Vertices in graph
		int V;
		//number of Edges
		int E;
		

	public:

		StringGraph(){
			unordered_map<string, StringGraphNode*> graph{};
			V = 0;
			E = 0;
		}

		void BulidGraph(vector<string> keys, unordered_map<string, vector<string>> edges) {
			for (int i = 0; i < keys.size(); i++) {
				addVertice(keys.at(i));
				V++;
			}

			for (auto key : edges) {
				for (int i = 0; i < key.second.size(); i++) {
					addEdge(key.first, key.second.at(i));
					E++;
				}
			}
		}

		unordered_map<string, StringGraphNode*> getGraph() {
			return graph;
		}

		void addEdge(string key, string value) {
			graph[key]->addEdge(graph[value]);
			E++;
		}

		void addVertice(string key) {
			graph[key] = new StringGraphNode{ key };
			V++;
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

		void depthfirstSearch(string key) {
			// Mark all the vertices as not visited
			unordered_map<string, bool> visited{};
			for (auto node : graph) {
				visited[node.first] = false;
			}
			// Call the recursive helper function
			// to print DFS traversal
			dfsAction(graph.at(key), visited);
		}

		void dfsAction(StringGraphNode* cur_node, unordered_map<string, bool> &visited) {
			//Mark first node as visited and print
			visited[cur_node->getValue()] = true;
			cout << cur_node->getValue() << " ";
			//recur for all adjacent vertices to this vertex
			vector < GraphNode<string, string>*> cur_edges = cur_node->getEdges();
			for (int i = 0; i < cur_edges.size(); i++) {
				string cur_value = cur_edges.at(i)->getValue();
				if (visited[cur_value] == false) {
					dfsAction(graph[cur_value], visited);
				}
			}
		}

		void iterativedepthfirstSearch(string key) {
			//unordered map for marking visited nodes as true or false
			unordered_map<string, bool> visited{};
			for (auto node : graph) {
				visited[node.first] = false;
			}
			stack<string> stack;

			stack.push(key);

			while (!stack.empty()) {
				//Pop vertex from stack and print it
				key = stack.top();
				stack.pop();

				//stack may contain same vertex twice.
				//printe popped item only if it is not visited
				if (visited[key] == false) {
					cout << key << " ";
					visited[key] = true;
				}

				vector < GraphNode<string, string>*> cur_edges = graph[key]->getEdges();
				for (int i = 0; i < cur_edges.size(); i++) {
					string cur_value = cur_edges.at(i)->getValue();
					if (visited[cur_value] == false) {
						stack.push(cur_value);
					}
				}
			}
			
		}

		void findBridges() {
				//get every edge to iterate on
				//will be stored in vector below
			unordered_map<string, vector<string>> edges{};
			vector<string> bridges{};
			for (auto vertice : graph) {
				StringGraphNode* cur_node = vertice.second;
				vector < GraphNode<string, string>*> cur_edges = cur_node->getEdges();
				for (int i = 0; i < cur_edges.size(); i++) {
					edges[cur_node->getValue()].push_back(cur_edges.at(i)->getValue());
				}
			}
			findBridgesUtil(bridges, edges);
		}

		void findBridgesUtil(vector<string> bridges, unordered_map<string, vector<string>> edges) {
			//remove edge from graph
			//traverse graph and see if it remains connected	
			//add edge back to graph							
		}
	};


	#endif // !GRAPH_H