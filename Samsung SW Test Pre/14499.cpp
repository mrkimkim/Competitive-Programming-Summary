#include <iostream>
#define MAX 21
using namespace std;

int Map[MAX][MAX];
int N, M, x, y, K;
int dx, dy;

int Dice[7];
int Temp[7];
int main() {
	// get variable
	cin >> N >> M >> x >> y >> K;

	// get map
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> dx;
			Map[i][j] = dx;
		}
	}

	bool flag = false;
	// get order
	for (int k = 0; k < K; ++k) {
		cin >> dx;
		if (dx == 1 && y < M - 1) {
			Temp[4] = Dice[1];
			Temp[2] = Dice[2];
			Temp[5] = Dice[5];
			Temp[1] = Dice[3];
			Temp[3] = Dice[6];
			Temp[6] = Dice[4];
			flag = true;
			++y;
		}
		else if (dx == 2 && y > 0) {
			Temp[1] = Dice[4];
			Temp[4] = Dice[6];
			Temp[6] = Dice[3];
			Temp[3] = Dice[1];
			Temp[5] = Dice[5];
			Temp[2] = Dice[2];
			flag = true;
			--y;
		}
		else if (dx == 3 && x > 0) {
			Temp[1] = Dice[2];
			Temp[2] = Dice[6];
			Temp[5] = Dice[1];
			Temp[6] = Dice[5];
			Temp[4] = Dice[4];
			Temp[3] = Dice[3];
			flag = true;
			--x;
		}
		else if (dx == 4 && x < N - 1) {
			Temp[2] = Dice[1];
			Temp[6] = Dice[2];
			Temp[1] = Dice[5];
			Temp[5] = Dice[6];
			Temp[4] = Dice[4];
			Temp[3] = Dice[3];
			flag = true;
			++x;
		}

		if (flag) {
			for (int i = 1; i < 7; ++i) Dice[i] = Temp[i];

			if (Map[x][y] == 0) Map[x][y] = Dice[1];
			else {
				Dice[1] = Map[x][y];
				Map[x][y] = 0;
			}

			cout << Dice[6] << endl;
		}

		flag = false;
	}
}