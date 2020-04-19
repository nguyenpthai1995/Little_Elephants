#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int SoConVoi, SoKhoi, SoMax;
int Matric[20], Ans = 0, Min = 999999;

bool checkBiBat() {
	for (int i = 0; i <= SoConVoi - SoKhoi; i++) {
		int Max = 0, Count = 0;
		for (int j = i; j < i + SoKhoi; j++) {
			if (Matric[j] > Max)
				Max = Matric[j];
		}
		for (int j = i; j < i + SoKhoi; j++) {
			if (Matric[j] == Max)
				Count++;
		}
		if (Count >= SoMax)
			return false;  // bi bat
	}
	return true;   // khong bi bat
}

void LittleElephants(int vt, int SoThayDoi, int d) {
	if(d > SoThayDoi)
		return;

	if (vt == SoConVoi) {
		if (checkBiBat()) { // khong bi bat
			Min = SoThayDoi;
		}
		return;
	}
	
	for (int i = 0; i <= 1; i++) {
		if (i == 1) {
			Matric[vt]++;
			d++;
		}

		LittleElephants(vt + 1, SoThayDoi, d);

		if (i == 1) {
			Matric[vt]--;
			d--;
		}
	}
}

int main() {
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Ans = 0, Min = 999999;
		cin >> SoConVoi >> SoKhoi >> SoMax;
		for (int i = 0; i < SoConVoi; i++) {
			cin >> Matric[i];
		}
		cout << "#" << tc << " ";
		int Ans = -1;
		for (int i = 0; i <= SoConVoi; i++) {
			Min = 999999;
			LittleElephants(0, i, 0);
			if (Min == i) {
				Ans = i;
				break;
			}
		}
		cout << Ans << endl;
	}
	return 0;
}
/*#1 0 #2 1 #3 1 #4 -1 #5 1 #6 1 #7 1 #8 0 #9 1 #10 1 #11 1 #12 -1 #13 1 #14 -1 #15 1 #16 3 #17 2 #18 1 #19 1 #20 0 #21 0 #22 0 #23 1 
#24 1 #25 1 #26 1 #27 3 #28 1 #29 -1 #30 -1 #31 0 #32 0 #33 2 #34 2 #35 0 #36 1 #37 1 #38 0 #39 1 #40 0 #41 2 #42 2 #43 1 #44 1 #45 0 
#46 0 #47 1 #48 -1 #49 1 #50 1  */