#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#define M_PI 3.14159265358979323846
#define ll long long
#define pii pair <int, int>
#define pll pair <long, long>
#define pil pair <int, long>
#define pli pair <long, int>
#define pdd pair <double, double>
#define MAX 1000
using namespace std;

ifstream in("A-large.in");
ofstream out("output.txt");

vector <pdd> cake;
double R, H;
double DP[MAX][MAX];
int T;
int N, K;

double getCylinder(double R, double H) {
	return R * R * M_PI + H * M_PI * R * 2.0;
}

double getSide(double R, double H) {
	return H * 2.0 * M_PI * R;
}

int main() {
	in >> T;
	for (int tt = 1; tt <= T; ++tt) {
		in >> N >> K;

		// 0. 기존 테이블 초기화
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < K; ++j) DP[i][j] = 0.0;
		}
		cake.clear();



		// 1. 데이터 입력
		for (int i = 0; i < N; ++i) {
			in >> R >> H;
			cake.push_back(make_pair(R, H));
		}
		sort(cake.begin(), cake.end(), std::greater<std::pair<double, double>>());



		// 2. 데이터 처리
		for (int i = 0; i < N; ++i) {
			pdd one = cake.at(i);
			for (int j = 0; j <= i && j < K; ++j) {
				// 가장 아래 판에 대해서
				if (j == 0) {
					if (i == 0) {
						DP[i][0] = getCylinder(one.first, one.second);
					}
					else {
						DP[i][0] = max(DP[i - 1][0], getCylinder(one.first, one.second));
					}
				}

				else {
					DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1] + getSide(one.first, one.second));
				}
			}
		}

		// 3. 데이터 출력
		out << "Case #" << tt << ": ";
		out.precision(9);
		out << fixed << DP[N - 1][K - 1] << endl;
	}

	in.close();
	out.close();
}