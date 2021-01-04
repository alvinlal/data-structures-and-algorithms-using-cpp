#include<iostream>
#include<vector> 
#include<map>
#include<string>
#include<functional>
#include<stack>

using namespace std;

class graph {
	void dfs(const string& vertex, vector<string>& result, map<string, bool>& visited) {
		if (vertex == "") return;
		visited[vertex] = true;
		result.push_back(vertex);

		for (string value : adjacencyList[vertex]) {
			if (!visited.count(value)) {
				dfs(value, result, visited);
			}
		}

	}
public:
	map<string, vector<string>> adjacencyList;

	void addVertex(const string& vertex) {
		if (adjacencyList.count(vertex) == 0) {
			vector<string> newVertex;
			adjacencyList[vertex] = newVertex;
		}

	}
	void addEdge(const string& v1, const string& v2) {
		adjacencyList[v1].push_back(v2);
		adjacencyList[v2].push_back(v1);
	}
	void forEach(vector<string>& a, const function<void(string, unsigned int)>& fn) {
		for (unsigned int i = 0; i < a.size(); i++) {
			fn(a[i], i);
		}
	}
	void removeEdge(const string& v1, const string& v2) {
		if (adjacencyList.count(v1) > 0) {
			int i = 0;
			for (string value : adjacencyList[v1]) {
				if (value == v2) {
					adjacencyList[v1].erase(adjacencyList[v1].begin() + i);
					break;
				}
				else i++;
			}
		}
		if (adjacencyList.count(v2) > 0) {
			int i = 0;
			for (string value : adjacencyList[v2]) {
				if (value == v1) {
					adjacencyList[v2].erase(adjacencyList[v2].begin() + i);
					break;
				}
				else i++;
			}
		}
	}

	void removeVertex(const string& vertex1) {

		if (adjacencyList.count(vertex1) > 0) {
			while (adjacencyList[vertex1].size() > 0) {
				string vertex2 = adjacencyList[vertex1][adjacencyList[vertex1].size() - 1];
				adjacencyList[vertex1].pop_back();
				removeEdge(vertex1, vertex2);
			}
		}
		adjacencyList.erase(vertex1);
	}



	vector<string> DFSR(const string& vertex) {
		//if (!vertex) return;
		vector<string> result;
		map<string, bool> visited;

		dfs(vertex, result, visited);

		return result;
	}
	vector<string> DFSI(const string& start) {
		vector<string> result;
		map<string, bool> visited;
		stack<string> stack;
		stack.push(start);
		visited[start] = true;
		string vertex;
		while (stack.size()) {
			vertex = stack.top();
			stack.pop();
			result.push_back(vertex);
			for (string value : adjacencyList[vertex]) {
				if (!visited.count(value)) {
					visited[value] = true;
					stack.push(value);

				}
			}

		}
		return result;
	}
	vector<string> BFS(const string& start) {
		vector<string> result;
		vector<string> queue;
		queue.emplace_back(start);
		map<string, bool> visited;
		visited[start] = true;
		string vertex;
		while (queue.size()) {
			vertex = queue.front();
			queue.erase(queue.begin());
			result.push_back(vertex);

			for (string value : adjacencyList[vertex]) {
				if (!visited.count(value)) {
					visited[value] = true;
					queue.push_back(value);
				}
			}

		}
		return result;

	}
	void print() {
		for (const auto& edge : adjacencyList) {

			cout << "\n" << edge.first << " : [";

			for (unsigned int i = 0; i < edge.second.size(); i++) {
				cout << edge.second[i] << ", ";
			}

			cout << "]";
		}
	}
};


//test code

int main() {
	graph g;
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	g.addVertex("D");
	g.addVertex("E");
	g.addVertex("F");


	g.addEdge("A", "B");
	g.addEdge("A", "C");
	g.addEdge("B", "D");
	g.addEdge("C", "E");
	g.addEdge("D", "E");
	g.addEdge("D", "F");
	g.addEdge("E", "F");


	cout << "\nThe graph is now";
	g.print();
	//g.removeEdge("A", "B");
	//cout << "\nRemoved edge A <-> B, the graph is now: ";
	//g.removeEdge("E", "F");
	//cout << "\nRemoved edge E <-> F, the graph is now: ";
	//g.print();

	/*g.removeVertex("A");
	cout << "\nRemoved Vertex A from the graph , the graph is now: ";
	g.print();*/
	cout << "\nThe recursive Depth first search of the graph is : ";
	vector<string> DFSR = g.DFSR("A");
	for (unsigned int i = 0; i < DFSR.size(); i++) {
		cout << DFSR[i] << ", ";
	}
	cout << "\nThe iterative Depth first search of the graph is : ";
	vector<string> DFSI = g.DFSI("A");
	for (unsigned int i = 0; i < DFSI.size(); i++) {
		cout << DFSI[i] << ", ";
	}
	cout << "\nThe iterative Breadth first search of the graph is : ";
	vector<string> BFS = g.BFS("A");
	for (unsigned int i = 0; i < BFS.size(); i++) {
		cout << BFS[i] << ", ";
	}


}