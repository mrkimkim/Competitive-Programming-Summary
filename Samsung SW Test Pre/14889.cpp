#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int N;
int D[MAX][MAX];
bool isPicked[MAX];

int ret = 100000000;

void pick(int cnt, int idx) {
	if (cnt == N / 2) {
		int sum_1 = 0;
		int sum_2 = 0;

		for (int i = 0; i < N; ++i) {
			if (isPicked[i]) {
				for (int j = 0; j < N; ++j) {
					if (isPicked[j]) sum_1 += D[i][j];
				}
			}
			else {
				for (int j = 0; j < N; ++j) {
					if (!isPicked[j]) sum_2 += D[i][j];
				}
			}
		}
		ret = min(ret, abs(sum_1 - sum_2));
		return;
	}

	else {
		for (int i = idx; i <= N / 2 + cnt; ++i) {
			isPicked[i] = true;
			pick(cnt + 1, i + 1);
			isPicked[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> D[i][j];
	}
	pick(0, 0);
	cout << ret << endl;
}