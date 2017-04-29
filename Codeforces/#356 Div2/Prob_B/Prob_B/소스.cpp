#include <iostream>
using namespace std;

void main() {
	int prime[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int square[4] = { 4,9,25,49 };
	int cnt = 0;

	char ans[5] = "";
	while (1) {
		for (int i = 0; i < 15; ++i) {
			cout << prime[i] << endl;
			fflush(stdout);
			cin >> ans;
			if (ans[0] == 'y') cnt++;
		}
		if (cnt == 0) {
			cout << "prime" << endl;
			fflush(stdout);
			break;
		}

		if (cnt == 1) {
			for (int i = 0; i < 4; ++i) {
				cout << square[i] << endl;
				fflush(stdout);
				cin >> ans;
				if (ans[0] == 'y') {
					cnt = 2;
					break;
				}
			}
		}

		if (cnt >= 2) {
			cout << "composite" << endl;
			fflush(stdout);
			break;
		}

		cout << "prime" << endl;
		fflush(stdout);
		break;
	}
}