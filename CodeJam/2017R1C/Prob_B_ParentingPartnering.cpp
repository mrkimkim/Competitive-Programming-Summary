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

ifstream in("B-large.in");
ofstream out("output.txt");

struct Activity {
	int s;
	int e;
	bool who;
};
vector <Activity> acts;

struct cmp {
	bool operator()(const Activity &a, const Activity &b) const {
		return b.s > a.s;
	}
};

int getAddition(int Sum, vector <int> Current) {
	int Count = 0;
	sort(Current.begin(), Current.end(), std::greater<int>());
	for (int i = 0; i < Current.size(); ++i) {
		Sum -= Current[i];
		Count += 2;
		if (Sum <= 720) break;
	}
	return Count;
}

int T;
int Ac, Aj;
int s, e;
int C, J;
int Change;
vector <int> CC;
vector <int> JJ;

int main() {
	in >> T;

	for (int tt = 1; tt <= T; ++tt) {
		in >> Ac >> Aj;
		out << "Case #" << tt << ": ";// << endl;
		
		// 0. 초기화
		acts.clear();
		CC.clear();
		JJ.clear();
		Change = 0;
		C = 0;
		J = 0;

		// 1. 입력
		for (int i = 0; i < Ac; ++i) {
			in >> s >> e;
			acts.push_back(Activity{ s, e, 0 });
		}

		for (int i = 0; i < Aj; ++i) {
			in >> s >> e;
			acts.push_back(Activity{ s, e, 1 });
		}

		sort(acts.begin(), acts.end(), cmp());
		int Min = acts.at(0).s;
		for (int i = 0; i < Ac + Aj; ++i) {
			acts.at(i).s -= Min;
			acts.at(i).e -= Min;
		}
		acts.push_back(Activity{ 1440, 1440, acts.at(0).who });

		// 2. 처리
		Activity Prev = acts.at(0);
		Activity act;
		int Remain = 1440;

		for (int i = 0; i < Ac + Aj; ++i) {
			//out << acts.at(i).s << " " << acts.at(i).e << " " << acts.at(i).who << " " << endl;
		}

		for (int i = 0; i < Ac + Aj + 1; ++i) {
			act = acts.at(i);

			if (act.who != Prev.who) Change++;
			else if(i != 0) {
				if (act.who == 0) {
					CC.push_back(act.s - Prev.e);
				}
				else if (act.who == 1) {
					JJ.push_back(act.s - Prev.e);
				}
				Remain -= (act.s - Prev.e);
			}

			if (act.who == 0) C += act.e - act.s;
			else if (act.who == 1) J += act.e - act.s;
			Remain -= (act.e - act.s);
			Prev = act;
			//out << "Change : " << Change << endl;
		}

		int C_Sum = C;
		int J_Sum = J;

		for (int i = 0; i < CC.size(); ++i) C_Sum += CC.at(i);
		for (int i = 0; i < JJ.size(); ++i) J_Sum += JJ.at(i);

		// 둘 다 별도의 구간 생성 없이 조율 가능
		//out << C_Sum << " " << J_Sum << " " << CC.size() << " " << JJ.size() << endl;
		if (C_Sum <= 720 && J_Sum <= 720) {
			out << Change << endl;
		}

		else {
			if (C_Sum > 720) {
				Change += getAddition(C_Sum, CC);
			}
			else if (J_Sum > 720) {
				Change += getAddition(J_Sum, JJ);
			}
			out << Change << endl;
		}
		
	}

	in.close();
	out.close();
}