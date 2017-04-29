#include <iostream>
using namespace std;

int cnt[101];
void main() {
	int x, sum = 0, min = 1000000;
	for (int i = 0; i < 5; ++i) {
		cin >> x;
		sum += x;
		cnt[x]++;
	}
	min = sum;
	for (int i = 1; i <= 100; ++i) {
		if (cnt[i] >= 2) {
			if (cnt[i] >= 3 && min >= sum - i * 3) min = (sum - i * 3);
			else if (min >= sum - i * 2) min = (sum - i * 2);
		}
	}

	cout << min;
}