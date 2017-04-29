#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;



int T, N, tt = 1;
int q[MAX][2];
vector< vector<int> > interval(MAX, vector<int>(2, 0));

struct cmp {
	bool operator()(const std::vector< int >& a, const std::vector< int >& b) { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); }
}Cmp;

int main() {
	cin >> T;
	while (tt <= T) {
		int ret = 0, q_size = 0;
		cin >> N;
		
		for (int i = 0; i < N; ++i) cin >> interval[i][0] >> interval[i][1];
		partial_sort(interval.begin(), interval.begin() + N, interval.end(), Cmp);

		for (int i = 0; i < N; ++i) {
			while (q_size > 0 && !(interval[i][0] >= q[q_size - 1][0] && interval[i][1] <= q[q_size - 1][1])) {
					--q_size;
			}
			q[q_size][0] = interval[i][0], q[q_size][1] = interval[i][1], ++q_size;
			ret = max(ret, q_size);
		}

		cout << "Case #" << tt << endl;
		cout << ret << endl;
		++tt;
	}
}