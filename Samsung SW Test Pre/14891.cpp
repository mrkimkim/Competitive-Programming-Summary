#include <iostream>
#include <queue>
using namespace std;

char s[5][9];
int K;
int u, v;

struct op {
	int num;
	int direction;
	int rotation;
};

int main() {
	for (int i = 1; i <= 4; ++i) cin >> s[i];
	cin >> K;

	// left = 2
	// right = 6
	while (K > 0) {
		// decrease count
		--K;
		
		// get num & rotate direction
		cin >> u >> v;

		// init queue
		queue <op> q;
		q.push(op{ u, 0, v });

		while (!q.empty()) {
			op o = q.front();
			q.pop();

			// rotation propagate
			// left
			if (o.num > 1 && o.direction != 2) {
				if (s[o.num][6] != s[o.num - 1][2]) q.push(op{ o.num - 1, 1, ~o.rotation + 1 });
			}
			// right
			if (o.num < 4 && o.direction != 1) {
				if (s[o.num][2] != s[o.num + 1][6]) q.push(op{ o.num + 1, 2, ~o.rotation + 1});
			}

			// rotate raw tooth
			// clockwise
			if (o.rotation == 1) {
				char temp = s[o.num][7];
				for (int j = 7; j > 0; --j) s[o.num][j] = s[o.num][j - 1];
				s[o.num][0] = temp;
			}
			// counter-clockwise
			else {
				char temp = s[o.num][0];
				for (int j = 0; j < 7; ++j) s[o.num][j] = s[o.num][j + 1];
				s[o.num][7] = temp;
			}
		}		
	}

	int ret = 0;
	if (s[1][0] == '1') ret += 1;
	if (s[2][0] == '1') ret += 2;
	if (s[3][0] == '1') ret += 4;
	if (s[4][0] == '1') ret += 8;
	cout << ret << endl;
}