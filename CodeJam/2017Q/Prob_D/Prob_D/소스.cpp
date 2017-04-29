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
		
		// STEP 0 - �ʱ�ȭ
		int point = 0;
		int cnt = 0;

		replaces.clear();
		for (int i = 0; i < MAX; ++i) {
			// ���� ���� �ʱ�ȭ
			R[i] = 1;
			C[i] = 1;

			// �밢�� �ʱ�ȭ
			V_A[i] = 1;
			V_B[i] = 1;

			// �� �ʱ�ȭ
			for (int j = 0; j < MAX; ++j) Map[i][j] = '.';
		}
		
		



		for (int i = 0; i < M; ++i) {
			in >> s >> r >> c;
			if (s == '+') {
				Map[r][c] = '+';
				// �밢�� ���� ��ȭ
				V_A[(N - 1) + (c - r)] = 0;
				V_B[r + c - 2] = 0;
			}

			else if (s == 'x') {
				Map[r][c] = 'x';
				// ���� ���� ���� ��ȭ
				R[r] = 0;
				C[c] = 0;
			}

			else if (s == 'o') {
				Map[r][c] = 'o';
				// ���� ���� ���� ��ȭ
				R[r] = 0;
				C[c] = 0;

				// �밢�� ���� ��ȭ
				V_A[(N - 1) + (c - r)] = 0;
				V_B[r + c - 2] = 0;
			}
		}

		

		// STEP 1 - o�� ���� ä���.
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				// �ش� ������ '.'�̰� 
				if (Map[i][j] == '.' && R[i] == 1 && C[j] == 1 && V_A[(N - 1) + (j - i)] == 1 && V_B[i + j - 2] == 1) {
					Map[i][j] = 'o';
					cnt += 1;
					replaces.push_back(replace{ 'o', i, j });

					R[i] = 0;
					C[j] = 0;
					V_A[(N - 1) + (j - i)] = 0;
					V_B[i + j - 2] = 0;
				}

				// �ش� ������ '+'�̰� ���� �������� �����ο�� 'o'�� ��ȯ ����
				else if (Map[i][j] == '+' && R[i] == 1 && C[j] == 1) {
					Map[i][j] = 'o';
					cnt += 1;
					replaces.push_back(replace{ 'o', i, j });

					R[i] = 0;
					C[j] = 0;
				}

				// �ش� ������ 'x'�̰� �밡�� �������� �����ο�� 'o'�� ��ȯ ����
				else if (Map[i][j] == 'x' && V_A[(N - 1) + (j - i)] == 1 && V_B[i + j - 2] == 1) {
					Map[i][j] = 'o';
					cnt += 1;
					replaces.push_back(replace{ 'o', i, j });

					V_A[(N - 1) + (j - i)] = 0;
					V_B[i + j - 2] = 0;
				}
			}
		}

		// STEP 2 - 'x'�� ä���.
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

		// STEP 3 - '+'�� ä���.
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

		// STEP 4 - Point ����
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