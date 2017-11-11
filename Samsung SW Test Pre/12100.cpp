#include <iostream>
#define forall(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

int State[21][21];
bool isNew[21][21];
int N, ret = 0;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1 };

int findMax() {
	int ret = 0;
	forall(i, 0, N) {
		forall(j, 0, N) {
			if (State[i][j] > ret) ret = State[i][j];
		}
	}
	return ret;
}

void Move(int cnt) {
	int Temp[21][21];

	if (cnt == 5) {
		int temp_ret = findMax();
		if (ret < temp_ret) ret = temp_ret;
		return;
	}

	forall(i, 0, N) {
		forall(j, 0, N) {
			isNew[i][j] = false;
			Temp[i][j] = State[i][j];
		}
	}

	int x = 0;
	int y = 0;

	forall(i, 0, 4) {
		// Up
		if (dx[i] == -1) {
			forall(ty, 0, N) {
				forall(tx, 1, N) {
					x = tx, y = ty;
					if (State[x][y] != 0) {
						while (x > 0 && State[x - 1][y] == 0) State[x - 1][y] = State[x][y], State[x][y] = 0, --x;
						if (x > 0 && State[x][y] == State[x - 1][y] && !isNew[x - 1][y]) {
							State[x][y] = 0;
							State[x - 1][y] *= 2;
							isNew[x - 1][y] = true;
						}
					}
				}
			}
		}

		// Down
		else if (dx[i] == 1) {
			forall(ty, 0, N) {
				for (int tx = N - 2; tx >= 0; --tx) {
					x = tx, y = ty;
					if (State[x][y] != 0) {
						while (x < N - 1 && State[x + 1][y] == 0) State[x + 1][y] = State[x][y], State[x][y] = 0, ++x;
						if (x < N - 1 && State[x][y] == State[x + 1][y] && !isNew[x + 1][y]) {
							State[x][y] = 0;
							State[x + 1][y] *= 2;
							isNew[x + 1][y] = true;
						}
					}
				}
			}
		}
		// Left
		else if (dy[i] == -1) {
			forall(tx, 0, N) {
				forall(ty, 1, N) {
					x = tx, y = ty;
					if (State[x][y] != 0) {
						while (y > 0 && State[x][y - 1] == 0) State[x][y - 1] = State[x][y], State[x][y] = 0, --y;
						if (y > 0 && State[x][y] == State[x][y - 1] && !isNew[x][y - 1]) {
							State[x][y] = 0;
							State[x][y - 1] *= 2;
							isNew[x][y - 1] = true;
						}
					}
				}
			}
		}
		else if (dy[i] == 1) {
			forall(tx, 0, N) {
				for (int ty = N - 2; ty >= 0; --ty) {
					x = tx, y = ty;
					if (State[x][y] != 0) {
						while (y < N - 1 && State[x][y + 1] == 0) State[x][y + 1] = State[x][y], State[x][y] = 0, ++y;
						if (y < N - 1 && State[x][y] == State[x][y + 1] && !isNew[x][y + 1]) {
							State[x][y] = 0;
							State[x][y + 1] *= 2;
							isNew[x][y + 1] = true;
						}
					}
				}
			}
		}

		Move(cnt + 1);

		// recover
		forall(ii, 0, N) {
			forall(j, 0, N) {
				isNew[ii][j] = false;
				State[ii][j] = Temp[ii][j];
			}
		}
	}

}

int main() {
	cin >> N;
	forall(i, 0, N) {
		forall(j, 0, N) {
			cin >> State[i][j];
		}
	}
	Move(0);
	cout << ret << endl;
}