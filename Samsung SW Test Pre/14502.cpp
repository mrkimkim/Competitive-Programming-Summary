#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 8
using namespace std;

int N, M, T;
int Map[MAX][MAX];
int Temp[MAX][MAX];
int ret;
int TotalCnt;

struct p {
	int x;
	int y;
};

vector<p> point;
vector<p> virus;

void Search() {
	queue <p> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			Temp[i][j] = Map[i][j];
		}
	}

	// q บนป็
	for (int i = 0; i < virus.size(); ++i) q.push(virus[i]);

	int cnt = 0;
	while (!q.empty()) {
		p cur = q.front();
		q.pop();
		if (cur.x > 0 && Temp[cur.x - 1][cur.y] == 0) Temp[cur.x - 1][cur.y] = 2, ++cnt, q.push(p{ cur.x - 1, cur.y });
		if (cur.x < N - 1 && Temp[cur.x + 1][cur.y] == 0) Temp[cur.x + 1][cur.y] = 2, ++cnt, q.push(p{ cur.x + 1, cur.y });
		if (cur.y > 0 && Temp[cur.x][cur.y - 1] == 0) Temp[cur.x][cur.y - 1] = 2, ++cnt, q.push(p{ cur.x, cur.y - 1});
		if (cur.y < M - 1 && Temp[cur.x][cur.y + 1] == 0) Temp[cur.x][cur.y + 1] = 2, ++cnt, q.push(p{ cur.x, cur.y + 1});
	}
	ret = max(ret, T - 3 - cnt);
}

void Go(int cnt, int idx) {
	if (cnt == 3) {
		Search();
		return;
	}
	
	for (int i = idx; T - i >= 3 - cnt; ++i) {
		Map[point[i].x][point[i].y] = 1;
		Go(cnt + 1, i + 1);
		Map[point[i].x][point[i].y] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Map[i][j];
			if (Map[i][j] == 0) point.push_back(p{ i,j }), ++T;
			if (Map[i][j] == 2) virus.push_back(p{ i, j });
		}
	}
	Go(0, 0);
	cout << ret << endl;
}