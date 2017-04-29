#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int gcd(int A, int B) {
	while (A % B != 0) {
		A %= B;
		B ^= A;
		A ^= B;
		B ^= A;
	}
	return B;
}

int N, K;
long long PrimeArr[MAX], prime_Cnt = 1;
int C[MAX * 10];

int main() {
	// Get Prime Array
	PrimeArr[0] = 2;

	for(int i = 3; i < 1000; ++i) {
		bool Flag = true;
		for (int j = 0; j < prime_Cnt && PrimeArr[j] * PrimeArr[j] < i; ++j) {
			if (i % PrimeArr[j] == 0) {
				Flag = false;
				break;
			}	
		}
		if (Flag == true) PrimeArr[prime_Cnt++] = i;
	}

	
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> C[i];
	for (int i = 0; i < prime_Cnt && PrimeArr[i] <= K; ++i) {
		int cnt = 0;
		int ret = 1;
		while (K % PrimeArr[i] == 0) {
			cnt++;
			K /= PrimeArr[i];
			ret *= PrimeArr[i];

			bool Flag = false;
			for (int j = 0; j < N; ++j) {
				if (C[j] % ret == 0) {
					Flag = true;
					break;
				}
			}

			if (Flag == false) {
				cout << "No" << endl;
				return 0;
			}
		}

		if (K == 1) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (C[i] % K == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}