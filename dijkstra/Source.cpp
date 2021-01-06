#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>

using namespace std;

class Node {
public:
	std::string value;
	float priority = INFINITY;
	Node(std::string value, float priority) :priority(priority), value(value) {}
	Node() {}
};


class PriorityQueue {
public:

	std::vector<Node*> values;

	void enqueue(std::string val, float priority) {
		Node* newNode = new Node(val, priority);
		values.emplace_back(newNode);
		bubbleUp();
	}
	void bubbleUp() {
		int idx = values.size() - 1;
		Node* element = values[idx];

		while (idx > 0) {
			int parentIdx = (int)std::floor((idx - 1) / 2);
			Node* parentElement = values[parentIdx];
			if (parentElement->priority <= element->priority) break;
			values[parentIdx] = element;
			values[idx] = parentElement;
			idx = parentIdx;
		}
	}
	Node dequeue() {
		if (values.size() == 0) {
			Node emptyNode("NULL", INFINITY);
			return emptyNode;
		}
		Node* min = values[0];
		Node* end = values[values.size() - 1];
		values.pop_back();
		if (values.size() > 0) {
			values[0] = end;
			sinkDown();
		}
		return *min;
	}
	void sinkDown() {
		int idx = 0;
		const int length = values.size() - 1;
		Node* element = values[0];
		while (true) {
			int leftChildIdx = 2 * idx + 1;
			int rightChildIdx = 2 * idx + 2;
			int swap = NULL;
			Node leftChild;
			Node rightChild;
			if (leftChildIdx < length) {
				leftChild = *values[leftChildIdx];
				if (leftChild.priority < element->priority) {
					swap = leftChildIdx;
				}
			}
			if (rightChildIdx < length) {
				rightChild = *values[rightChildIdx];
				if ((swap == NULL && rightChild.priority < element->priority) || (swap != NULL && rightChild.priority < leftChild.priority)) {
					swap = rightChildIdx;
				}
			}
			if (swap == NULL) break;
			values[idx] = values[swap];
			values[swap] = element;
			idx = swap;
		}
	}
	void print() {
		for (unsigned int i = 0; i < values.size(); i++) {
			std::cout << values[i]->value << ", " << values[i]->priority << "\n";
		}
	}
};

class Vertex {

public:
	string node;
	float weight;
	Vertex(string node, float weight) :node(node), weight(weight) {}
};


class weightedGraph {
	map<string, vector<Vertex>> adjacencyList;

public:
	void addVertex(const string& vertex) {
		if (adjacencyList.count(vertex) == 0) {
			vector<Vertex> newVertex;
			adjacencyList[vertex] = newVertex;
		}
	}
	void addEdge(const string& v1, const string& v2, float weight) {
		Vertex newVertex1(v2, weight);
		adjacencyList[v1].push_back(newVertex1);
		Vertex newVertex2(v1, weight);
		adjacencyList[v2].push_back(newVertex2);
	}

	vector<string> shortestPath(const string& start, const string& end) {
		map<string, string> previous;
		map<string, float> distances;
		PriorityQueue nodes;
		vector<string> path;

		for (const auto& key : adjacencyList) {
			string vertex = key.first;
			if (vertex == start) {
				distances[vertex] = 0;
				nodes.enqueue(vertex, 0);
			}
			else {
				distances[vertex] = INFINITY;
				nodes.enqueue(vertex, INFINITY);
			}
			previous[vertex] = "NULL";
		}

		while (nodes.values.size()) {
			string smallest = nodes.dequeue().value;
			if (smallest == end) {
				while (previous[smallest] != "NULL") {
					path.push_back(smallest);
					smallest = previous[smallest];
				}
				break;
			}
			if ((smallest != "NULL") || (distances[smallest] != INFINITY)) {

				for (const auto& neighbour : adjacencyList[smallest]) {
					string nodeName = neighbour.node;

					float candidate = distances[smallest] + neighbour.weight;

					if (candidate < distances[nodeName]) {
						distances[nodeName] = candidate;
						previous[nodeName] = smallest;
						nodes.enqueue(nodeName, candidate);
					}
				}
			}

		}
		path.push_back(start);
		reverse(path.begin(), path.end());
		return path;
	}
	void print() {
		for (const auto& edge : adjacencyList) {

			cout << "\n" << edge.first << " : [";

			for (unsigned int i = 0; i < edge.second.size(); i++) {
				cout << edge.second[i].node << ", ";
			}

			cout << "]";
		}
	}
};

int main() {
	weightedGraph graph;

	graph.addVertex("A");
	graph.addVertex("B");
	graph.addVertex("C");
	graph.addVertex("D");
	graph.addVertex("E");
	graph.addVertex("F");


	graph.addEdge("A", "B", 4);
	graph.addEdge("A", "C", 2);
	graph.addEdge("B", "E", 3);
	graph.addEdge("C", "D", 2);
	graph.addEdge("C", "F", 4);
	graph.addEdge("D", "E", 3);
	graph.addEdge("D", "F", 1);
	graph.addEdge("E", "F", 1);


	cout << "\nThe graph is now";
	graph.print();

	vector<string> shortestPath = graph.shortestPath("A", "E");

	cout << "\nThe shortest path between A and E is : ";

	for (auto value : shortestPath) {
		cout << value << ", ";
	}

}