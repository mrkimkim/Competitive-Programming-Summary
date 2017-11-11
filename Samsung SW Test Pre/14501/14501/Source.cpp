#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int N, M;
int D[MAX][MAX];

/*

OO를 기준으로 붙을 수 있는 모든 블록들

*/

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> D[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// 4-len
			if (i + 3 < N) ret = max(ret, D[i][j] + D[i + 1][j] + D[i + 2][j] + D[i + 3][j]);
			if (j + 3 < M) ret = max(ret, D[i][j] + D[i][j + 1] + D[i][j + 2] + D[i][j + 3]);

			// 3-len
			// horizontal
			if (j + 2 < M) {
				int horizon = D[i][j] + D[i][j + 1] + D[i][j + 2];
				if (i > 0) ret = max(ret, horizon + max(max(D[i - 1][j], D[i - 1][j + 1]), D[i - 1][j + 2]));
				if (i + 1 < N) ret = max(ret, horizon + max(max(D[i + 1][j], D[i + 1][j + 1]), D[i + 1][j + 2]));
			}
			// vertical
			if (i + 2 < N) {
				int vertical = D[i][j] + D[i + 1][j] + D[i + 2][j];
				if (j > 0) ret = max(ret, vertical + max(max(D[i][j - 1], D[i + 1][j - 1]), D[i + 2][j - 1]));
				if (j + 1 < M) ret = max(ret, vertical + max(max(D[i][j + 1], D[i + 1][j + 1]), D[i + 2][j + 1]));
			}

			// 2-len
			// horizontal
			if (i > 0 && j + 1 < M) {
				int horizon = D[i][j] + D[i][j + 1];
				if (j > 0) ret = max(ret, horizon + D[i - 1][j - 1] + D[i - 1][j]);
				ret = max(ret, horizon + D[i - 1][j] + D[i - 1][j + 1]);
				if (j + 2 < M) ret = max(ret, horizon + D[i - 1][j + 1] + D[i - 1][j + 2]);
			}
			// vertical
			if (i + 1 < N && j + 1 < M) {
				int vertical = D[i][j] + D[i + 1][j];
				if (i > 0) ret = max(ret, vertical + D[i - 1][j + 1] + D[i][j + 1]);
				ret = max(ret, vertical + D[i][j + 1] + D[i + 1][j + 1]);
				if (i + 2 < N) ret = max(ret, vertical + D[i + 1][j + 1] + D[i + 2][j + 1]);
			}
		}
	}
	cout << ret << endl;
}