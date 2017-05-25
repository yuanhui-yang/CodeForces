// 20C. Dijkstra?
// http://codeforces.com/problemset/problem/20/C

/*
time limit per test1 second
memory limit per test64 megabytes
inputstandard input
outputstandard output
You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of vertices and m is the number of edges. Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), where ai, bi are edge endpoints and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.

Examples
input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
output
1 4 3 5 
input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
output
1 4 3 5 
*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	Graph(int n) {
		g.clear();
		g.resize(n);
	}
	void insert(int a, int b, int w) {
		a--;
		b--;
		g.at(a).push_back(make_pair(b, w));
		g.at(b).push_back(make_pair(a, w));
	}
	vector<int> Dijkstra(int a, int b) {
		a--;
		b--;
		int n = g.size();
		vector<int> parent(n, INT_MAX), dist(n, INT_MAX);
		vector<bool> visited(n, false);
		dist.at(a) = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair(0, a));
		while (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			int id = p.second, w = p.first;
			visited.at(id) = true;
			if (id == b) {
				vector<int> path;
				while (id != a) {
					path.push_back(id + 1);
					id = parent.at(id);
				}
				path.push_back(a + 1);
				reverse(begin(path), end(path));
				return path;
			}
			for (const auto &i : g.at(id)) {
				int nid = i.first, nw = i.second + w;
				if (!visited.at(nid) and nw < dist.at(nid)) {
					parent.at(nid) = id;
					dist.at(nid) = nw;
					pq.push(make_pair(nw, nid));
				}
			}
		}
		return {-1};
	}
private:
	vector<vector<pair<int, int>>> g;
};

/* BEGIN: Memory limit exceeded
	vector<int> Dijkstra(int a, int b) {
		a--;
		b--;
		int n = g.size();
		vector<int> parent(n, INT_MAX), dist(n, INT_MAX);
		set<pair<int, int>> rbtree;
		rbtree.insert(make_pair(0, a));
		dist.at(a) = 0;
		vector<int> path;
		while (!rbtree.empty())  {
			set<pair<int, int>>::iterator pt = begin(rbtree);
			pair<int, int> p = *pt;
			rbtree.erase(pt);
			if (p.second == b) {
				int current = b;
				while (current != a) {
					path.push_back(current + 1);
					current = parent.at(current);
				}
				path.push_back(a + 1);
				reverse(begin(path), end(path));
				return path;
			}
			for (const auto &i : g.at(p.second)) {
				if (i.second + p.first < dist.at(i.first)) {
					if (!rbtree.empty() and rbtree.count(make_pair(dist.at(i.first), i.first))) {
						rbtree.erase(make_pair(dist.at(i.first), i.first));
					}
					dist.at(i.first) = i.second + p.first;
					parent.at(i.first) = p.second;
					rbtree.insert(make_pair(i.second + p.first, i.first));
				}
			}
		}
		return {-1};
	}
END: Memory limit exceeded */

int main(void) {
	int n, m;
	cin >> n >> m;
	Graph graph(n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph.insert(a, b, w);
	}
	vector<int> path = graph.Dijkstra(1, n);
	for (const auto &i : path) {
		cout << i << ' ';
	}
	return 0;
}
