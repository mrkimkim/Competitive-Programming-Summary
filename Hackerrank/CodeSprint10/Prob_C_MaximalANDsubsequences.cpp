#include <iostream>
#include <string>
#define MAX 100001
#define MAX_LEN 61
using namespace std;

int N, K;
long long Num[MAX];
bool Marked[MAX];
long long Divider = 1LL << 60;
long long Sum = 0;
long long Mod = 1000000007;

long long gcd(long long r2) {
	long long r, r1 = Mod;
	long long s, s1 = 1, s2 = 0;
	long long t, t1 = 0, t2 = 1;
	long long q;

	while (r2) {
		q = r1 / r2;
		r = r1 % r2;
		s = s1 - q * s2;
		t = t1 - q * t2;

		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}

	if (t1 < 0) t1 += Mod;
	return t1;
}

int main() {
	int Cnt = 0;
	// get input and store as string
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> Num[i];
	for (int i = 0; i < N; ++i) Marked[i] = true;

	for (int i = 0; i < MAX_LEN; ++i) {
		Cnt = 0;

		// Count valid bit
		for (int j = 0; j < N; ++j) {
			// if valid number
			if (Marked[j]) {
				if ((Num[j] / Divider) % 2 == 1) ++Cnt;
			}
		}

		if (Cnt >= K) {
			Sum += Divider;
			for (int j = 0; j < N; ++j) {
				if (Marked[j] && (Num[j] / Divider) % 2 == 0) Marked[j] = false;
			}
		}
		Divider = Divider >> 1;
	}

	Cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (Marked[i]) Cnt++;
	}
	N = Cnt;
	cout << Sum << endl;
	long long Counter = 1;
	for (int i = K + 1; i <= Cnt; ++i) Counter = (Counter * i) % Mod;
	for (int i = 1; i <= Cnt - K; ++i) Counter = (Counter * gcd(i)) % Mod;
	cout << Counter;
}