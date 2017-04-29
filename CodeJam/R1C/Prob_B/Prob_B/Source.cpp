#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 51
using namespace std;

ifstream in("B-large-practice.in");
ofstream out("output.txt");

int T, tt;
long long B, M;
long long k;

bool isUsed[MAX];
bool Map[MAX][MAX];

int main() {
	in >> T;
	for(tt = 1; tt <= T; ++tt) {
		out << "Case #" << tt << ": ";
		in >> B >> M;

		long long Max = 1;
		for (long long i = 0; i < B - 2; ++i) {
			Max *= 2ll;
		}

		if (M > Max) {
			out << "IMPOSSIBLE" << endl;
			continue;
		}

		else {
			M -= 1;
			out << "POSSIBLE" << endl;

			// Init Map
			for (int i = 0; i < B; ++i) {
				for (int j = 0; j < B; ++j) Map[i][j] = 0;
			}

			// Make Map
			for (int i = 1; i < B - 1; ++i) {
				for (int j = i + 1; j < B - 1; ++j) {
					Map[i][j] = 1;
				}
				if (M % 2 == 1) Map[i][B - 1] = 1;
				M /= 2;
			}

			// Print Map
			for (int i = 1; i < B; ++i) Map[0][i] = 1;

			for (int i = 0; i < B; ++i) {
				for (int j = 0; j < B; ++j) out << Map[i][j];
				out << endl;
			}
		}
	}

	in.close();
	out.close();
}