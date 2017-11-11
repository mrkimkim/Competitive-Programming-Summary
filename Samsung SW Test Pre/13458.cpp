#include <iostream>
#define MAX 1000001
#define forall(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

int A[MAX];
int N, B, C;
long long ret = 0LL;

int main() {
	cin >> N;
	forall(i, 0, N) cin >> A[i];
	cin >> B >> C;

	forall(i, 0, N) {
		ret += 1;
		A[i] -= B;
		if (A[i] > 0) ret += (A[i] + C - 1) / C;
	}

	cout << ret << endl;
}