#include <iostream>
#include <fstream>
#include <string>
#define MAX 1001
using namespace std;

ifstream in("A-large.in");
ofstream out("output.txt");

int T, tt;
string Cake;
bool State[MAX];
int S;

int main() {
	in >> T;
	for (tt = 1; tt <= T; ++tt) {
		in >> Cake >> S;

		// Converter
		for (int i = 0; i < Cake.length(); ++i) {
			if (Cake.at(i) == '+') State[i] = 1;
			else State[i] = 0;
		}

		int ret = 0;
		// Process
		for (int i = 0; i <= Cake.length() - S; ++i) {
			if (State[i] == 0) {
				ret++;
				for (int j = 0; j < S; ++j) {
					State[i + j] = !State[i + j];
				}
			}
		}
		
		// Verify
		bool Flag = true;
		for (int i = 0; i < Cake.length(); ++i) {
			if (State[i] == 0) {
				Flag = false;
				break;
			}
		}

		// Print
		out << "Case #" << tt << ": ";
		if (Flag) out << ret;
		else out << "IMPOSSIBLE";
		out << endl;
	}

	in.close();
	out.close();
}