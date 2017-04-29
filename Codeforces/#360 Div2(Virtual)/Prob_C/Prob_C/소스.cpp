#include <iostream>
#include <vector>
#include <queue>
#include <String>
#define MAX 100000
using namespace std;

vector <int> color(MAX, -1);
vector <vector<int>> Edge(MAX);
queue <int> vertex;
queue <int> q;
int N, M;

int cnt1, cnt2;
string ret1, ret2;

int main() {
	int u, v;
	int c, cnt, p;

	cin >> N >> M;

	// Set Vertex
	for (int i = 0; i < N; ++i) vertex.push(i);

	// Make a Graph
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		--u;
		--v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	while (vertex.empty() != true) {
		// get vertex
		c = vertex.front();
		vertex.pop();

		// if it is unexplored
		if (color[c] == -1) {
			
			// unconnected edge
			if (Edge[c].size() == 0) color[c] = -2;
			else {
				cnt = 0;
				q.push(c);
				color[c] = cnt;
				while(q.empty() != true) {
					p = q.front();
					q.pop();

					// Explore Edge's connected with current vertex 'p'
					for (int i = 0; i < Edge[p].size(); ++i) {
						// can't color different num
						if (color[p] == color[Edge[p][i]]) {
							cout << -1;
							return 0;
						}

						// find new vertex
						else if (color[Edge[p][i]] == -1) {
							q.push(Edge[p][i]);
							color[Edge[p][i]] = (color[p] + 1) % 2;
						}
					}
				}
			}
		}
	}

	// First Assignment
	cnt1 = cnt2 = 0;
	for (int i = 0; i < N; ++i) {
		if (color[i] == 0) {
			cnt1++;
			ret1 += to_string(i + 1) + " ";
		}
		else if (color[i] == 1) {
			cnt2++;
			ret2 += to_string(i + 1) + " ";
		}
	}
	cout << cnt1 << endl << ret1 << endl << cnt2 << endl << ret2;
}