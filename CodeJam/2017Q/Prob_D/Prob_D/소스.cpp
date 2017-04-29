#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 1001
using namespace std;

ifstream in("D-small-practice.in");
//ifstream in("sub-13.in");
ofstream out("output.txt");

int T, tt;
int N, M;
int State[MAX];

char s;
char Map[MAX][MAX];

int R[MAX], C[MAX];
int V_A[MAX], V_B[MAX];

struct replace {
	char s;
	int r;
	int c;
};

vector <replace> replaces;

int main() {
	int r, c;
	in >> T;
	for (tt = 1; tt <= T; ++tt) {
		in >> N >> M;
		
		// STEP 0 - 초기화
		int point = 0;
		int cnt = 0;

		replaces.clear();
		for (int i = 0; i < MAX; ++i) {
			// 수직 수평 초기화
			R[i] = 1;
			C[i] = 1;

			// 대각선 초기화
			V_A[i] = 1;
			V_B[i] = 1;

			// 맵 초기화
			for (int j = 0; j < MAX; ++j) Map[i][j] = '.';
		}
		
		



		for (int i = 0; i < M; ++i) {
			in >> s >> r >> c;
			if (s == '+') {
				Map[r][c] = '+';
				// 대각선 상태 변화
				V_A[(N - 1) + (c - r)] = 0;
				V_B[r + c - 2] = 0;
			}

			else if (s == 'x') {
				Map[r][c] = 'x';
				// 수직 수평 상태 변화
				R[r] = 0;
				C[c] = 0;
			}

			else if (s == 'o') {
				Map[r][c] = 'o';
				// 수직 수평 상태 변화
				R[r] = 0;
				C[c] = 0;

				// 대각선 상태 변화
				V_A[(N - 1) + (c - r)] = 0;
				V_B[r + c - 2] = 0;
			}
		}

		

		// STEP 1 - o를 먼저 채운다.
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				// 해당 지점이 '.'이고 
				if (Map[i][j] == '.' && R[i] == 1 && C[j] == 1 && V_A[(N - 1) + (j - i)] == 1 && V_B[i + j - 2] == 1) {
					Map[i][j] = 'o';
					cnt += 1;
					replaces.push_back(replace{ 'o', i, j });

					R[i] = 0;
					C[j] = 0;
					V_A[(N - 1) + (j - i)] = 0;
					V_B[i + j - 2] = 0;
				}

				// 해당 지점이 '+'이고 수직 수평으로 자유로우면 'o'로 변환 가능
				else if (Map[i][j] == '+' && R[i] == 1 && C[j] == 1) {
					Map[i][j] = 'o';
					cnt += 1;
					replaces.push_back(replace{ 'o', i, j });

					R[i] = 0;
					C[j] = 0;
				}

				// 해당 지점이 'x'이고 대가선 방향으로 자유로우면 'o'로 변환 가능
				else if (Map[i][j] == 'x' && V_A[(N - 1) + (j - i)] == 1 && V_B[i + j - 2] == 1) {
					Map[i][j] = 'o';
					cnt += 1;
					replaces.push_back(replace{ 'o', i, j });

					V_A[(N - 1) + (j - i)] = 0;
					V_B[i + j - 2] = 0;
				}
			}
		}

		// STEP 2 - 'x'를 채운다.
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Map[i][j] == '.' && R[i] == 1 && C[j] == 1) {
					Map[i][j] = 'x';
					cnt += 1;
					replaces.push_back(replace{ 'x', i, j });

					R[i] = 0;
					C[j] = 0;
				}
			}
		}

		// STEP 3 - '+'를 채운다.
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Map[i][j] == '.' && V_A[(N - 1) + (j - i)] == 1 && V_B[i + j - 2] == 1) {
					Map[i][j] = '+';
					cnt += 1;
					replaces.push_back(replace{ '+', i, j });

					V_A[(N - 1) + (j - i)] = 0;
					V_B[i + j - 2] = 0;
				}
			}
		}

		// STEP 4 - Point 산정
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Map[i][j] == 'o') point += 2;
				else if (Map[i][j] == '+' || Map[i][j] == 'x') point += 1;
			}
		}

		/*for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				out << Map[i][j];
			}
			out << endl;
		}*/

		out << "Case #" << tt << ": " << point << " " << cnt << endl;
		for (int i = 0; i < replaces.size(); ++i) out << replaces[i].s << " " << replaces[i].r << " " << replaces[i].c << endl;
	}

	in.close();
	out.close();
}