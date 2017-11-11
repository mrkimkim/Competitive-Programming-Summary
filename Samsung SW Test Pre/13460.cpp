#include <iostream>
#define MAX 12
using namespace std;

int N, M;
char Arr[MAX][MAX];
int Status[MAX][MAX][MAX][MAX][MAX];
int rx, ry, bx, by;

int Move(int i, int rx, int ry, int bx, int by, int ax, int ay) {
	bool Flag = false;
	bool r = false;

	if (ax * (rx - bx) < 0 || ay * (ry - by) < 0) {
		rx ^= bx, bx ^= rx, rx ^= bx;
		ry ^= by, by ^= ry, ry ^= by;
		Flag = true;
	}

	while (Arr[rx + ax][ry + ay] != '#') {
		if (Arr[rx + ax][ry + ay] == 'O') {
			if (Flag) return 0;
			r = true;
			rx += ax;
			ry += ay;
			break;
		}
		rx += ax;
		ry += ay;
	}

	while (Arr[bx + ax][by + ay] != '#') {
		if (Arr[bx + ax][by + ay] == 'O') {
			if (Flag) {
				r = true;
				break;
			}
			return 0;
		}
		if (rx == bx + ax && ry == by + ay) break;
		bx += ax;
		by += ay;
	}

	// only r reach goal
	if (r) return 1;

	// record status
	if (Flag) {
		rx ^= bx, bx ^= rx, rx ^= bx;
		ry ^= by, by ^= ry, ry ^= by;
	}
	Status[i + 1][rx][ry][bx][by] = 1;

	//cout << "[" << i << "]" << rx << " " << ry << " " << bx << " " << by << "[" << r << "]" << endl;
	return 0;
}


/*
	[!] R과 B에서 최단으로 향하는 경로를 찾는 것은 의미가 없다.
*/

int main() {
	// get input
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> Arr[i];
	
	// find 'R' and 'B'
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (Arr[i][j] == 'R') {
				rx = i, ry = j;
				Arr[i][j] = '.';
			}
			if (Arr[i][j] == 'B') {
				bx = i, by = j;
				Arr[i][j] = '.';
			}
		}
	}

	// init
	Status[0][rx][ry][bx][by] = 1;

	int ret = -1;
	for (int i = 0; i < 10; ++i) {
		for (int rx = 1; rx < N - 1; ++rx) {
			for (int ry = 1; ry < M - 1; ++ry) {
				for (int bx = 1; bx < N - 1; ++bx) {
					for (int by = 1; by < M - 1; ++by) {
						if (Status[i][rx][ry][bx][by] == 1) {
							if (Move(i, rx, ry, bx, by, 1, 0) == 1) {
								ret = i + 1;
								break;
							}
							if (Move(i, rx, ry, bx, by, -1, 0) == 1) {
								ret = i + 1;
								break;
							}
							if (Move(i, rx, ry, bx, by, 0, 1) == 1) {
								ret = i + 1;
								break;
							}
							if (Move(i, rx, ry, bx, by, 0, -1) == 1) {
								ret = i + 1;
								break;
							}
						}
					}
					if (ret != -1) break;
				}
				if (ret != -1) break;
			}
			if (ret != -1) break;
		}
		if (ret != -1) break;
	}
	printf("%d", ret);
}