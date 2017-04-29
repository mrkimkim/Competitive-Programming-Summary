/**
* Competition : Codeground 2015 R2
* Prob_URL : https://www.codeground.org/practice/practiceProbView.do?probId=18#
* Category : math (GCD)
* Solver : HyeonGyuJang
* Blog : godkad.blog.me
*/

#include <iostream>
#include <cmath>
#define max(X,Y) ((X) > (Y) ? (X) : (Y))
#define min(X,Y) ((X) > (Y) ? (Y) : (X))
#define MAX 100000000
using namespace std;


int DP[101][101][11];
int Altitude[101][101];
bool isWater[101][101];
int T, N, M, K;

int main() {
	int val, up;
	int tt = 1;

	cin >> T;
	while (tt <= T) {

		// get input
		cin >> M >> N >> K;
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= M; ++j) {
				cin >> val;
				if (val < 0) isWater[i][j] = true;
				else isWater[i][j] = false;
				Altitude[i][j] = abs(val);
			}
		}

		// init DP table
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= M; ++j) {
				for (int k = 0; k < 11; ++k) {
					DP[i][j][k] = MAX;
				}
			}
		}

		// init start point
		if (isWater[0][0]) DP[0][0][1] = 0;
		else DP[0][0][0] = 0;

		
		// process
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= M; ++j) {
				// isWater
				if (isWater[i][j]) up = 1;
				else up = 0;

				for (int k = 0; k < 11; ++k) {
					if (i > 0) {
						DP[i][j][min(k + up, 10)] = min(DP[i][j][min(k + up, 10)], DP[i - 1][j][k] + abs(Altitude[i][j] - Altitude[i - 1][j]));
					}
					if (j > 0) {
						DP[i][j][min(k + up, 10)] = min(DP[i][j][min(k + up, 10)], DP[i][j - 1][k] + abs(Altitude[i][j] - Altitude[i][j - 1]));
					}
				}
			}
		}


		// print
		cout << "Case #" << tt << endl;
		int ret = MAX;
		for (int i = K; i < 11; ++i) {
			ret = min(ret, DP[N][M][i]);
		}
		cout << ret << endl;
		++tt;
	}
}