#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 300010
using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");
vector <int> edge[MAX];
int N;
int W[MAX];
int D[MAX], DA[MAX];
int P[MAX];
long long ans = 0;

void FindMaxSubtree(int node, int prev) {
	int child;
	D[node] = W[node];
	DA[node] = 0;
	int A = 0, B = 0;

	for (int i = 0; i < edge[node].size(); ++i) {
		child = edge[node][i];
		if (child != prev) {
			FindMaxSubtree(child, node);
			if (D[child] > 0) D[node] += D[child];
			DA[node] = max(DA[node], DA[child]);

			if (B < DA[child]) {
				B = DA[child];
				if (B > A) {
					int temp;
					temp = B;
					B = A;
					A = temp;
				}
			}
		}
	}
	ans = max(ans, 1ll * A * B);
	D[node] = max(D[node], 0);
	DA[node] = max(D[node], DA[node]);
}

void FindMaxPartition(int node, int prev) {
	int child;
	ans = max(ans, 1ll * DA[node] * P[node]);

	for (int i = 0; i < edge[node].size(); ++i) {
		child = edge[node][i];
		if (child != prev) {
			P[child] = max(0, P[node] + D[node] - D[child]);
			FindMaxPartition(child, node);
		}
	}
}


int main() {
	int u, v;

	// Input
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> W[i];
	for (int i = 1; i < N; ++i) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}



	// Process
	FindMaxSubtree(1, 1);
	FindMaxPartition(1, 1);

	for (int i = 1; i <= N; ++i) {
		D[i] = DA[i] = P[i] = 0;
		W[i] *= -1;
	}
	FindMaxSubtree(1, 1);
	FindMaxPartition(1, 1);

	// Print
	cout << ans << endl;

	//in.close();
	//out.close();
}