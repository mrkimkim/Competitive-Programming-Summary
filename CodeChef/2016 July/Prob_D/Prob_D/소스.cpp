#include <iostream>
#include <queue>
#define MAX 999999
using namespace std;

int T;
int N, M, K1, K2;
int x, y;
int Ret;
bool Map[100][100];
int Dist_1[100][100];
int Dist_2[100][100];
int v[4][2] = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };

queue <pair<int, int>> q;
pair<int, int> p;

bool isbound(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

void getDist(pair<int, int> start, int (*Dist)[100], int K) {
	
	Map[start.first][start.second] = true;
	q.push(make_pair(start.first, start.second));

	while (q.empty() != true) {
		p = q.front();
		q.pop();

		x = p.first;
		y = p.second;

		for (int i = 0; i <= K; ++i) {
			for (int j = 0; j <= K - i; ++j) {
				for (int idx = 0; idx < 4; ++idx) {
					int new_x = x + i * v[idx][0];
					int new_y = y + j * v[idx][1];

					if (isbound(new_x, new_y) == true && Map[new_x][new_y] == false && Dist[new_x][new_y] > Dist[x][y] + 1) {
						q.push(make_pair(new_x, new_y));
						Dist[new_x][new_y] = Dist[x][y] + 1;
					}
				}
			}
		}
	}


	Map[start.first][start.second] = false;
}

int main() {
	cin >> T;
	while (T > 0) {
		cin >> N >> M >> K1 >> K2;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> Map[i][j];
				Dist_1[i][j] = MAX;
				Dist_2[i][j] = MAX;
			}
		}
		
		Dist_1[0][0] = 0, Dist_2[0][M-1] = 0;
		getDist(make_pair(0, 0), Dist_1, K1);
		getDist(make_pair(0, M-1), Dist_2, K2);

		Ret = MAX;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				Ret = min(Ret, max(Dist_1[i][j], Dist_2[i][j]));
			}
		}

		if (Ret == MAX) cout << -1 << endl;
		else cout << Ret << endl;
		--T;
	}
}