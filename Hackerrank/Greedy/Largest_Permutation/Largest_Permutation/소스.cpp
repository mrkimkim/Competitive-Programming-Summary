/**
* Prob_URL : https://www.hackerrank.com/challenges/largest-permutation
* Category : Greedy
* Solver : HyeonGyuJang
* Blog : godkad.blog.me 
*/

#include <iostream>
#define MAX 100001
using namespace std;

int Arr[MAX];
int idx[MAX];
int N, K;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> Arr[i];
		idx[Arr[i]] = i;
	}

	for (int i = N; i >= 1 && K > 0; --i) {
		if (idx[i] != N - i + 1) {
			int Temp = Arr[N - i + 1];
			
			// swap value
			Arr[N - i + 1] = Arr[idx[i]];
			Arr[idx[i]] = Temp;

			// swap index
			idx[i] ^= idx[Temp];
			idx[Temp] ^= idx[i];
			idx[i] ^= idx[Temp];
			
			--K;
		}
	}

	for (int i = 1; i <= N; ++i) cout << Arr[i] << " ";
}