#include <iostream>
#include <algorithm>
#define forall(i,a,b) for(int i = a; i < b; ++i)
#define MAX 11

int N;
int A[MAX];
int D[MAX][MAX][MAX][MAX][MAX];
int D2[MAX][MAX][MAX][MAX][MAX];
bool isDefined[MAX][MAX][MAX][MAX][MAX];
bool isDefined2[MAX][MAX][MAX][MAX][MAX];
int la, lb, lc, ld;

using namespace std;

int main() {
	cin >> N;
	forall(i, 0, N) cin >> A[i];
	cin >> la >> lb >> lc >> ld;

	D[0][0][0][0][0] = A[0];
	D2[0][0][0][0][0] = A[0];

	forall(i, 0, N - 1) {
		forall(a, 0, min(la,i) + 1) {
			forall(b, 0, min(lb, i - a) + 1) {
				forall(c, 0, min(lc, i - a - b) + 1) {
					forall(d, 0, min(ld, i - a - b - c) + 1) {
						// plus
						if (a < la) {
							if (isDefined[i + 1][a + 1][b][c][d]) D[i + 1][a + 1][b][c][d] = max(D[i][a][b][c][d] + A[i + 1], D[i + 1][a + 1][b][c][d]);
							else { isDefined[i + 1][a + 1][b][c][d] = true, D[i + 1][a + 1][b][c][d] = D[i][a][b][c][d] + A[i + 1]; }

							if (isDefined2[i + 1][a + 1][b][c][d]) D2[i + 1][a + 1][b][c][d] = min(D2[i][a][b][c][d] + A[i + 1], D2[i + 1][a + 1][b][c][d]);
							else { isDefined2[i + 1][a + 1][b][c][d] = true, D2[i + 1][a + 1][b][c][d] = D2[i][a][b][c][d] + A[i + 1]; }
						}
						// minus
						if (b < lb) {
							if (isDefined[i + 1][a][b + 1][c][d]) D[i + 1][a][b + 1][c][d] = max(D[i][a][b][c][d] - A[i + 1], D[i + 1][a][b + 1][c][d]);
							else { isDefined[i + 1][a][b + 1][c][d] = true, D[i + 1][a][b + 1][c][d] = D[i][a][b][c][d] - A[i + 1]; }

							if (isDefined2[i + 1][a][b + 1][c][d]) D2[i + 1][a][b + 1][c][d] = min(D2[i][a][b][c][d] - A[i + 1], D2[i + 1][a][b + 1][c][d]);
							else { isDefined2[i + 1][a][b + 1][c][d] = true, D2[i + 1][a][b + 1][c][d] = D2[i][a][b][c][d] - A[i + 1]; }
						}
						// mul
						if (c < lc) {
							if (isDefined[i + 1][a][b][c + 1][d]) D[i + 1][a][b][c + 1][d] = max(D[i][a][b][c][d] * A[i + 1], D[i + 1][a][b][c + 1][d]);
							else { isDefined[i + 1][a][b][c + 1][d] = true, D[i + 1][a][b][c + 1][d] = D[i][a][b][c][d] * A[i + 1]; }

							if (isDefined2[i + 1][a][b][c + 1][d]) D2[i + 1][a][b][c + 1][d] = min(D2[i][a][b][c][d] * A[i + 1], D2[i + 1][a][b][c + 1][d]);
							else { isDefined2[i + 1][a][b][c + 1][d] = true, D2[i + 1][a][b][c + 1][d] = D2[i][a][b][c][d] * A[i + 1]; }
						}
						// div
						if (d < ld) {
							if (isDefined[i + 1][a][b][c][d + 1]) D[i + 1][a][b][c][d + 1] = max(D[i][a][b][c][d] / A[i + 1], D[i + 1][a][b][c][d + 1]);
							else { isDefined[i + 1][a][b][c][d + 1] = true, D[i + 1][a][b][c][d + 1] = D[i][a][b][c][d] / A[i + 1]; }

							if (isDefined2[i + 1][a][b][c][d + 1]) D2[i + 1][a][b][c][d + 1] = min(D2[i][a][b][c][d] / A[i + 1], D2[i + 1][a][b][c][d + 1]);
							else { isDefined2[i + 1][a][b][c][d + 1] = true, D2[i + 1][a][b][c][d + 1] = D2[i][a][b][c][d] / A[i + 1]; }
						}
					}
				}
			}
		}
	}

	cout << D[N - 1][la][lb][lc][ld] << endl;
	cout << D2[N - 1][la][lb][lc][ld] << endl;
}