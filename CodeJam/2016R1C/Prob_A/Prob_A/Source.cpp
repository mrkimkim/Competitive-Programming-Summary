#include <iostream>
#include <fstream>
#define MAX 27
using namespace std;


int T, tt;
int N;
int P[MAX];

int Max_i() {
	int Max_i;
	Max_i = 0;

	for (int i = 0; i < N; ++i) {
		if (P[i] > P[Max_i]) Max_i = i;
	}

	return (P[Max_i] > 0) ? Max_i : -1;
}

bool isBalanceBroken() {
	int sum = 0;
	for (int i = 0; i < N; ++i) sum += P[i];
	for (int i = 0; i < N; ++i) if (P[i] * 2 > sum) return true;
	return false;
}

int main() {
	ifstream in("A-large-practice.in");
	ofstream out("output.txt");
	in >> T;

	int p;

	for (tt = 1; tt <= T; ++tt) {
		in >> N;
		for (int i = 0; i < N; ++i) in >> P[i];
		out << "Case #" << tt << ": ";
		while (true) {
			p = Max_i();
			if (p == -1) break;
			out << char(p + 65);
			P[p] -= 1;

			if (isBalanceBroken()) {
				p = Max_i();
				if (p == -1) break;
				out << char(p + 65);
				P[p] -= 1;
			}

			out << " ";
		}
		out << endl;
	}

	in.close();
	out.close();
}