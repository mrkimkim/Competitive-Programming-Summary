#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int N, L;
int D[MAX][MAX];
int T[MAX];
int ret = 0;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> D[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		// 가로방향 탐색
		for (int j = 0; j < N; ++j) T[j] = 0;
		for (int j = 0; j < N; ++j) {
			if (j == N - 1) {
				++ret;
				break;
			}
			// Exception 1. 인접 블록의 차이가 1 이상
			if (abs(D[i][j] - D[i][j + 1]) > 1) break;

			// Case 1. 현재 블록이 높을 경우
			if (D[i][j] == D[i][j + 1] + 1) {
				
				// L개의 연속한 블록을 놓을 수 있는가
				bool isequal = true;
				if (j + L >= N) break;
				
				for (int k = 1; k <= L; ++k) {
					if (D[i][j + 1] != D[i][j + k] || T[j + k] != 0) {
						isequal = false;
						break;
					}
				}
				
				if (isequal) for (int k = 1; k <= L; ++k) T[j + k] = 1;
				else break;
			}
			// Case 2. 현재 블록이 낮은 경우
			else if (D[i][j] == D[i][j + 1] - 1) {
				if (j + 1 < L) break;
				
				bool isequal = true;
				for (int k = 0; k < L; ++k) {
					if (D[i][j - k] != D[i][j] || T[j - k] != 0) {
						isequal = false;
						break;
					}
				}
				if (isequal) for (int k = 0; k < L; ++k) T[j - k] = 1;
				else break;
			}
		}


		// 세로방향 탐색
		for (int j = 0; j < N; ++j) T[j] = 0;
		for (int j = 0; j < N; ++j) {
			if (j == N - 1) {
				++ret;
				break;
			}
			// Exception 1. 인접 블록의 차이가 1 이상
			if (abs(D[j][i] - D[j + 1][i]) > 1) break;

			// Case 1. 현재 블록이 높을 경우
			if (D[j][i] == D[j + 1][i] + 1) {
				// L개의 연속한 블록을 놓을 수 있는가
				bool isequal = true;
				if (j + L >= N) break;
				
				for (int k = 1; k <= L; ++k) {
					if (D[j + 1][i] != D[j + k][i] || T[j + k] != 0) {
						isequal = false;
						break;
					}
				}

				if (isequal) for (int k = 1; k <= L; ++k) T[j + k] = 1;
				else break;
			}
			// Case 2. 현재 블록이 낮은 경우
			else if (D[j][i] == D[j + 1][i] - 1) {
				if (j + 1 < L) break;

				bool isequal = true;
				for (int k = 0; k < L; ++k) {
					if (D[j - k][i] != D[j][i] || T[j - k] != 0) {
						isequal = false;
						break;
					}
				}
				if (isequal) for (int k = 0; k < L; ++k) T[j - k] = 1;
				else break;
			}
		}
		
	}
	cout << ret << endl;
}
