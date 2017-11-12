#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1010
using namespace std;

char change;
long long L, N;
long long v[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; // up, left, down, right
long long turn[4][2] = { {1, 3}, {2, 0}, {3, 1}, {0, 2} };
long long move_time[MAX];
long long direction = 3;
long long new_x = 0, new_y = 0;
long long x = 0, y = 0;
long long ret = 0;

struct l {
	long long sx, sy;
	long long ex, ey;
};

vector<l> line;

int main() {
	cin >> L;
	cin >> N;

	// add boundary
	line.push_back({ L + 1, -L - 1, L + 1, L + 1 });
	line.push_back({ L + 1, L + 1, -L - 1, L + 1 });
	line.push_back({ -L - 1, L + 1, -L - 1, -L - 1 });
	line.push_back({ -L - 1, -L - 1, L + 1, -L - 1 });
	
	for (int i = 0; i < N; ++i) {
		//cout << direction << " " << new_x << " " << new_y << endl;
		// change direction
		cin >> move_time[i + 4] >> change;

		// make new line
		new_x = x + v[direction][0] * (move_time[i + 4]);
		new_y = y + v[direction][1] * (move_time[i + 4]);
		line.push_back(l{ x, y, new_x, new_y });

		x = new_x;
		y = new_y;
		if (change == 'L') direction = turn[direction][0];
		else direction = turn[direction][1];
	}

	//cout << direction << " " << new_x << " " << new_y << endl;

	// add last line
	if (direction == 0) new_x = x, new_y = L + 1;
	else if (direction == 1) new_x = -L - 1, new_y = y;
	else if (direction == 2) new_x = x, new_y = -L - 1;
	else if (direction == 3) new_x = L + 1, new_y = y;
	line.push_back(l{x, y, new_x, new_y});

	
	for (int i = 4; i < N + 5; ++i) {
		long long col_time = 400000000;
		// collide with prev line
		for (int j = 0; j < i - 1; ++j) {
			// overlap
			if (line[i].sx == line[i].ex && line[j].sx == line[j].ex && line[i].sx == line[j].sx) {
				if (max(line[i].sy, line[i].ey) >= min(line[j].sy, line[j].ey) && min(line[i].sy, line[i].ey) <= max(line[j].sy, line[j].ey)) {
					col_time = min(col_time, min(abs(line[j].sy - line[i].sy), abs(line[j].ey - line[i].sy)));
					//cout << i << " ! " << j << endl;
				}
			}
			else if (line[i].sy == line[i].ey && line[j].sy == line[j].ey && line[i].sy == line[j].sy) {
				if (max(line[i].sx, line[i].ex) >= min(line[j].sx, line[j].ex) && min(line[i].sx, line[i].ex) <= max(line[j].sx, line[j].ex)) {
					col_time = min(col_time, min(abs(line[j].sx - line[i].sx), abs(line[j].ex - line[i].sx)));
					//cout << i << " @ " << j << endl;
				}
			}

			// just cross
			else if (line[i].sx == line[i].ex && line[j].sy == line[j].ey) {
				if (line[j].sy >= min(line[i].sy, line[i].ey) && line[j].sy <= max(line[i].sy, line[i].ey) &&
					line[i].sx >= min(line[j].sx, line[j].ex) && line[i].sx <= max(line[j].sx, line[j].ex)) {
					col_time = min(col_time, abs(line[i].sy - line[j].sy));
					//cout << i << " # " << j << endl;
				}
			}
			else if (line[i].sy == line[i].ey && line[j].sx == line[j].ex) {
				if (line[i].sy >= min(line[j].sy, line[j].ey) && line[i].sy <= max(line[j].sy, line[j].ey) &&
					line[j].sx >= min(line[i].sx, line[i].ex) && line[j].sx <= max(line[i].sx, line[i].ex)) {
					col_time = min(col_time, abs(line[i].sx - line[j].sx));
					//cout << i << " ~ " << j << endl;
				}
			}
		}
	
		// over the boundary
		if (col_time != 400000000) {
			ret += col_time;
			break;
		}
		else ret += move_time[i];
	}
	cout << ret << endl;
}