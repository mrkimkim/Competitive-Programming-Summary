/**
* Competition : Codeground 2015 R2
* Prob_URL : https://www.codeground.org/practice/practiceProbView.do?probId=16
* Category : math (GCD)
* Solver : HyeonGyuJang
* Blog : godkad.blog.me
*/

#include <iostream>
#include <math.h>
#define MAX 100001
using namespace std;

long delta[MAX];
int T, N;

long gcd(long a, long b) {
	long temp;
	if (a == 0 || b == 0) return 0;
	while (a % b != 0) {
		a %= b;
		temp = a;
		a = b;
		b = temp;
	}
	return b;
}


int getNumofDividor(long N) {
	int Cnt = 0;

	for (int i = 1; i <= int(sqrt(N)); ++i) {
		if (N % i == 0) {
			++Cnt;
			if (N / i != i) ++Cnt;
		}
	}

	return Cnt;
}


int main() {
	int tt = 1;
	cin >> T;

	while (tt <= T) {
		bool isConstant = true;
		long prev, l;
		
		cin >> N;
		cin >> prev;

		// save delta
		for (int i = 1; i < N; ++i) {
			cin >> l;
			delta[i - 1] = l - prev;
			prev = l;
			if (delta[i - 1] != 0) isConstant = false;
		}

		// calc delta's gcd
		prev = delta[0];
		for (int i = 1; i < N - 1; ++i) {
			prev = gcd(prev, delta[i]);
		}

		// calc num of dividor
		cout << "Case #" << tt << endl;
		if (prev == 0) {
			if (isConstant) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else {
			cout << getNumofDividor(prev) << endl;
		}

		++tt;
	}
}