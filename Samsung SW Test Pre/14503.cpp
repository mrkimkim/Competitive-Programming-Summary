#include <iostream>
#define MAX 51
#define forall(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

int N, M;
int Map[MAX][MAX];
int x, y, d;
int v[4] = { 3, 0, 1, 2 };
int del[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main() {
	// get input
	cin >> N >> M;
	cin >> x >> y >> d;

	forall(i, 0, N) {
		forall(j, 0, M) cin >> Map[i][j];
	}

	int ret = 0;
	bool flag;

	while (true) {
		flag = false;

		// clean the current position
		if (Map[x][y] == 0) ++ret, Map[x][y] = -1;

		// change direction
		forall(i, 0, 4) {
			d = v[d];
			int new_x = x + del[d][0];
			int new_y = y + del[d][1];
			
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && Map[new_x][new_y] == 0) {
				x = new_x;
				y = new_y;
				flag = true;
				break;
			}
		}

		// go backward
		if (!flag) {
			int new_x = x - del[d][0];
			int new_y = y - del[d][1];

			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && Map[new_x][new_y] != 1) {
				x = new_x;
				y = new_y;
			}
			else {
				break;
			}
		}
	}
	cout << ret << endl;
}