	#ifndef GRAPH_H
	#define GRAPH_H

	#include <unordered_map>
	#include <vector>
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
			graph[key]->addEdge(graph[value]);
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