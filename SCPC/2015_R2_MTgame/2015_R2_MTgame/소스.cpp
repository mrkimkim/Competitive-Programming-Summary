/**
* Competition : Codeground 2015 R2
* Prob_URL : https://www.codeground.org/practice/practiceProbView.do?probId=17
* Category : math
* Solver : HyeonGyuJang
* Blog : godkad.blog.me
*/

#include <iostream>
using namespace std;

long T, N, K;
long a, b, c;

int main() {
	int tt = 1;
	cin >> T;

	while (tt <= T) {
		cin >> a >> b >> c;
		cout << "Case #" << tt << endl;
		for (int i = 0; i < c; ++i) {
			cin >> N >> K;
			if (N % (K * a + K * b) > a && N % (K * a + K * b) <= K * a + b) cout << "a";
			else cout << "b";
		}
		cout << endl;
		++tt;
	}
}