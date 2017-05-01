#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#define M_PI 3.14159265358979323846
#define ll long long
#define pii pair <int, int>
#define pll pair <long, long>
#define pil pair <int, long>
#define pli pair <long, int>
#define pdd pair <double, double>
#define MAX 1000
#define Goal 720
using namespace std;

ifstream in("C-small-1-attempt0.in");
ofstream out("output.txt");

struct Activity {
	int s;
	int e;
	bool who;
};
vector <Activity> acts;

int T;
int N, K;
vector <double> Core;
double U;
double C;
double Sum;
int main() {
	in >> T;

	for (int tt = 1; tt <= T; ++tt) {
		out << "Case #" << tt << ": ";
		
		in >> N >> K;
		in >> U;
		Core.clear();

		Sum = 0.0;
		for (int i = 0; i < N; ++i) {
			in >> C;
			Core.push_back(C);
			Sum += C;
		}
		sort(Core.begin(), Core.end(), std::greater<double>());
		

		int j;
		for (int i = 0; i < N; ++i) {
			j = i;
			if (Core.at(i) * double(N - i) <= U + Sum) break;
			Sum -= Core.at(i);
		}
		
		double Portion = (U + Sum) / double(N - j);
		//out << Portion;
		for (int i = j; i < N; ++i) {
			Core.at(i) = Portion;
			//out << Core.at(i) << endl;
		}

		double ret = 1.0;
		for (int i = 0; i < N; ++i) ret *= Core.at(i);
		
		out.precision(6);
		out << fixed << min(1.0, ret) << endl;
	}

	in.close();
	out.close();
}