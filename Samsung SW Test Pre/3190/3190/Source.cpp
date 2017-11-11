#include <iostream>
#define MAX 102
#define forall(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

struct p {
	int x;
	int y;
};

struct d {
	int t;
	char direction;
};

int N, K, L;
int M[MAX][MAX];
int M2[MAX][MAX];
int x, y;
int direction;
int v[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // Right, Left, Down, Up
int u[4][2] = { {3, 2}, {2, 3}, {0, 1}, {1, 0} };

p Snake[MAX];
d Change[MAX];

int main() {
	forall(i, 0, MAX) Snake[i].x = -1, Snake[i].y = -1;
	
	cin >> N;
	cin >> K;
	forall(i, 0, K) {
		cin >> x >> y;
		M[x][y] = 1;
	}

	cin >> L;
	forall(i, 0, L) {
		cin >> Change[i].t >> Change[i].direction;
	}
	Change[L].t = 10000000;
	Change[L].direction = -1;

	// init position
	Snake[0].x = 1;
	Snake[0].y = 1;
	direction = 0;
	M2[Snake[0].x][Snake[0].y] = 1;

	int t = 0;
	int i = 0;
	int length = 1;

	// snake start moving
	while (true) {
		if (t == Change[i].t) {
			if (Change[i].direction == 'L') direction = u[direction][0];
			else direction = u[direction][1];
			++i;
		}

		// move snake
		int new_x = Snake[0].x + v[direction][0];
		int new_y = Snake[0].y + v[direction][1];
		// increase time
		++t;

		// if snake isn't on the map
		if (new_x <= 0 || new_x > N || new_y <= 0 || new_y > N) break;
		// if snake hit with itself
		if (M2[new_x][new_y] == 1) break;


		// if snake got apple
		if (M[new_x][new_y] == 1) {
			M[new_x][new_y] = 0;
			for (int j = length; j > 0; --j) Snake[j].x = Snake[j - 1].x, Snake[j].y = Snake[j - 1].y;
			Snake[0].x = new_x;
			Snake[0].y = new_y;
			M2[new_x][new_y] = 1;
			++length;
		}
		// if not
		else {
			M2[Snake[length - 1].x][Snake[length - 1].y] = 0;
			for (int j = length - 1; j > 0; --j) Snake[j].x = Snake[j - 1].x, Snake[j].y = Snake[j - 1].y;
			Snake[0].x = new_x;
			Snake[0].y = new_y;
			M2[new_x][new_y] = 1;
		}
	}
	cout << t << endl;
}