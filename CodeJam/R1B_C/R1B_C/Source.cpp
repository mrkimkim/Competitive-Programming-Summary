// STEP 1. Verify Node
// STEP 2. Build Graph
// STEP 3. Ford-Fulkerson
// STEP 4. Print

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MAX 1080
#define INF 1 << 30;
using namespace std;

int max_cap[MAX * 2][MAX * 2];
int cap[MAX * 2][MAX * 2];
int flow[MAX * 2][MAX * 2];
int Prev[MAX * 3];
vector <int> adj[MAX * 2];

int T, N;
int L, R;
int MIN_FLOW;
bool isVisited[MAX * 2];
string s1[MAX], s2[MAX];

map <string, int> v1, v2;

int dfs(int s) {
	isVisited[s] = true;
	if (s == L + R) return INF;
	
	//cout << s << " ";
	for (int i = 0; i < adj[s].size(); ++i) {
		
		if (!isVisited[adj[s][i]] && cap[s][adj[s][i]] > 0 && flow[s][adj[s][i]] < max_cap[s][adj[s][i]]) {
			int tmp = dfs(adj[s][i]);
			if (tmp > 0) { 
				Prev[adj[s][i]] = s;
				MIN_FLOW = min(cap[s][adj[s][i]], tmp);
				return MIN_FLOW;
			}
		}
	}
	
	isVisited[s] = false;
	return -1;
}

int MaxFlow() {
	int MAX_FLOW = 0;

	MIN_FLOW = INF;
	fill(Prev, Prev + MAX * 2, -1);
	fill(isVisited, isVisited + MAX * 2, false);

	while (dfs(0) > 0) {
		int i = L + R;
		//cout << MAX_FLOW << endl;
		while (i != 0) {
			//cout << MIN_FLOW << endl;
			cap[Prev[i]][i] -= MIN_FLOW;
			cap[i][Prev[i]] += MIN_FLOW;

			flow[Prev[i]][i] += MIN_FLOW;
			i = Prev[i];
		}

		MAX_FLOW += MIN_FLOW;

		MIN_FLOW = INF;
		fill(Prev, Prev + MAX * 2, -1);
		fill(isVisited, isVisited + MAX * 2, false);
	}
	return MAX_FLOW;
}

int main() {
	
	ifstream in("C-large-practice.in");
	ofstream out("output.txt");
	in >> T;

	for (int tt = 0; tt < T; ++tt) {
		// STEP 0. Initialize
		for (int i = 0; i < MAX * 2; ++i) adj[i].clear();
		v1.clear();
		v2.clear();

		// STEP 1. Verify Node
		in >> N;
		for (int i = 0; i < N; ++i) {
			in >> s1[i] >> s2[i];
			v1[s1[i]] = 0;
			v2[s2[i]] = 0;
		}

		map <string, int>::iterator v;
		L = 1;
		R = 0;
		for (v = v1.begin(); v != v1.end(); v++) v->second = L++;
		for (v = v2.begin(); v != v2.end(); v++) v->second = L + R, R++;

		// *** STEP 2. Build Graph
		
		// ** Start to Left
		for (v = v1.begin(); v != v1.end(); ++v) {
			max_cap[0][v->second] = 1;
			max_cap[v->second][0] = 1;

			flow[0][v->second] = 0;
			flow[v->second][0] = 0;

			cap[0][v->second] = 1;
			cap[v->second][0] = 0;

			adj[0].push_back(v->second);
			adj[v->second].push_back(0);
		}

		// ** Left to Right
		for (int i = 0; i < N; ++i) {
			max_cap[v1[s1[i]]][v2[s2[i]]] = 1;
			max_cap[v2[s2[i]]][v1[s1[i]]] = 1;

			flow[v1[s1[i]]][v2[s2[i]]] = 0;
			flow[v2[s2[i]]][v1[s1[i]]] = 0;

			cap[v1[s1[i]]][v2[s2[i]]] = 1;
			cap[v2[s2[i]]][v1[s1[i]]] = 0;

			adj[v1[s1[i]]].push_back(v2[s2[i]]);
			adj[v2[s2[i]]].push_back(v1[s1[i]]);
		}

		// ** Right to Sink
		for (v = v2.begin(); v != v2.end(); ++v) {
			max_cap[v->second][L + R] = 1;
			max_cap[L + R][v->second] = 1;

			flow[v->second][L + R] = 0;
			flow[L + R][v->second] = 0;

			cap[v->second][L + R] = 1;
			cap[L + R][v->second] = 0;

			adj[v->second].push_back(L + R);
			adj[L + R].push_back(v->second);
		}

		// STEP 3. Ford-Fulkerson
		int m = MaxFlow();

		// STEP 4. PRINT
		cout << m << endl;
		cout << "Case #" << tt + 1 << ": " <<  N - m - (L + R - 2 * m - 1) << endl;
		out << "Case #" << tt + 1 << ": " << N - m - (L + R - 2 * m - 1) << endl;
	}
	out.close();
	in.close();
	while (1);
}