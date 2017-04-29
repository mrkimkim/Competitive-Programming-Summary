// STEP 1. Build Segment Tree
// STEP 2. Make Edge
// STEP 3. Dijkstra
// STEP 4. Print

#include <iostream>
#include <queue>
#include <vector>
#define MAX 101000
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, long long> pil;
const long long INF = 1LL << 60;

int ver[2][4 * MAX];
long long dist[MAX * 9];
bool Visited[MAX * 9];

struct cmp {
	bool operator()(pil const &a, pil const &b) const {
		return a.second > b.second;
	}
};

vector <pii> adj[MAX * 9];
priority_queue < pil, vector<pil>, cmp > pq;

int n, q, s, node_idx;
int t, v, u, l, r, w;

void build_segmentTree(int type, int idx = 1, int l = 0, int r = n) {
	ver[type][idx] = node_idx++;
	
	// Leaf
	if (r - l < 2) {
		if (!type) {
			adj[ver[type][idx]].push_back({ l, 0 });
		}
		else {
			adj[l].push_back( {ver[type][idx], 0});
		}
		return;
	}

	// Non-Leaf
	else {
		int mid = (l + r) >> 1;
		build_segmentTree(type, (idx << 1), l, mid);
		build_segmentTree(type, 1 + (idx << 1), mid, r);

		if (!type) {
			adj[ver[type][idx]].push_back({ ver[type][(idx << 1)], 0 });
			adj[ver[type][idx]].push_back({ ver[type][1 + (idx << 1)], 0 });
		}

		else {
			adj[ver[type][(idx << 1)]].push_back({ ver[type][idx], 0 });
			adj[ver[type][1 + (idx << 1)]].push_back({ ver[type][idx], 0 });
		}
	}
}

void add_edge(int type, int v, int w, int start, int end, int idx = 1, int l = 0, int r = n) {
	// Check if [l, r) and [start, end) share same interval
	if (start >= r || end <= l) return;

	// if [start, end) contain area of given idx
	if (start <= l && r <= end) {
		if (!type) {
			adj[v].push_back({ ver[type][idx], w });
		}
		else {
			adj[ver[type][idx]].push_back({ v, w });
		}
		return;
	}

	int mid = (l + r) >> 1;
	add_edge(type, v, w, start, end, (idx << 1), l, mid);
	add_edge(type, v, w, start, end, 1 + (idx << 1), mid, r);

}

int main() {
	cin >> n >> q >> s;
	node_idx = n;

	// STEP 1. Build Segment Tree
	build_segmentTree(0), build_segmentTree(1);

	// STEP 2. Add Edge
	for (int i = 0; i < q; ++i) {
		cin >> t;
		t -= 2;
		if (t == -1) {
			cin >> v >> u >> w;
			--v, --u;
			adj[v].push_back({ u, w });
		}
		else {
			cin >> v >> l >> r >> w;
			--v, --l;
			add_edge(t, v, w, l, r);
		}
	}

	// STEP 3. Dijkstra
	--s;
	fill(dist, dist + MAX * 5, INF);
	dist[s] = 0LL;
	pq.push({ s, dist[s] });

	while (!pq.empty()) {
		pil node = pq.top();
		pq.pop();
		
		v = node.first;
		if (Visited[v]) continue;
		Visited[v] = 1;

		for (int i = 0; i < adj[v].size(); ++i) {
			u = adj[v][i].first;
			w = adj[v][i].second;
			if (dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				pq.push({ u, dist[u] });
			}
		}
	}

	// STEP 4. PRINT
	for (int i = 0; i < n; ++i) cout << ((dist[i] == INF) ? -1 : dist[i]) << " ";
	cout << endl;
}