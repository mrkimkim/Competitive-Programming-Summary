#include <iostream>
#include <fstream>
#include <queue>
#define MAX 7001
using namespace std;

ifstream in("input.txt");

int N;
int k1, k2;
int s1[MAX], s2[MAX];
int DP[MAX][2];
bool isUsed[MAX][2];

struct State {
	int planet;
	int turn;
};

queue <State> Q;

int main() {
	State current;
	int prev;

	// input
	in >> N;
	in >> k1;
	for (int i = 0; i < k1; ++i) in >> s1[i];
	in >> k2;
	for (int i = 0; i < k2; ++i) in >> s2[i];

	// init
	// 0 : Not Determined, 1 : A Win, -1 : B Win
	DP[0][0] = 1;
	DP[0][1] = -1; // perspective of A
	isUsed[0][1] = true;
	isUsed[0][0] = true;
	Q.push(State{ 0, 1 });
	Q.push(State{ 0, 0 });

	while (!Q.empty()) {
		current = Q.front();
		Q.pop();

		// if B can win it's turn all of prev A can win
		if (current.turn == 1 && DP[current.planet][1] == -1) {
			for (int i = 0; i < k1; ++i) {
				prev = (current.planet - s1[i]) % N;
				if (!isUsed[prev][0]) {
					isUsed[prev][0] = true;
					DP[prev][0] = 1;
					Q.push(State{ prev, 0 });
				}
			}
		}

		else if(current.turn == 0 && DP[current.planet][0] == 1) {
			for (int i = 0; i < k2; ++i) {
				prev = (current.planet - s2[i]) % N;
				if (isUsed[prev][1]) {
					isUsed[prev][1] == true;
					DP[prev][1] = -1;
					Q.push(State{ prev, 1 });
				}
			}
		}
	}
}