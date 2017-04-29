#include <iostream>
using namespace std;
int Arr[1000][2048];
int Sum[1000][2048];
int Heap[2048];

int getHorMax(int i, int x, int y, int head, int tail, int idx) {
	// head와 tail의 범위가 겹쳐지는 경우
}

int main() {
	int N, M, T, Line, Line2;
	cin >> N >> M;

	Line = Line2 = 1;
	while (Line < M) Line *= 2;
	while (Line2 < M) Line *= 2;
	Line -= 1; // Start at 0

	for (int i = 0; i < N; ++i) {
		for (int j = Line; j < Line + M; ++j) {
			cin >> Arr[i][j];
		}
		for (int j = Line + M - 1; j > 0; --j) {
			if (Arr[i][(j - 1) / 2] < Arr[i][j]) Arr[i][(j - 1) / 2] = Arr[i][j];
		}
	}

	cin >> T;
	int x, y;
	while (T > 0) {
		cin >> x >> y;
		
		// Make Sub Sum
		Sum[0][0] = Arr[0][Line];
		for (int i = 1; i < N; ++i) Sum[i][0] = Sum[i - 1][0] + Arr[Line + i][0];
		for (int i = 1; i < M; ++i) Sum[0][i] = Sum[0][i - 1] + Arr[0][Line + i];
		for (int i = 1; i < N; ++i) {
			for (int j = 1; i < M; ++j) {
				Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + Arr[i][Line + j];
			}
		}

		// Make Line Heap
		for (int j = y - 1; j < M; ++j) {
			for (int i = 0; i < N; ++i) {
				Heap[i] = getHorMax(i, j+1-y, j, 0, M, (Line+1)/2, 0);
			}
		}
		--T;
	}
}