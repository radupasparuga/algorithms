#include <iostream>

using namespace std;

long long code[1000][12], aux, gammaCounter[1000], epsilonCounter[1000];
int main() {
	int gamma[12], epsilon[12];
	int oneCount = 0, zeroCount = 0;
	for (int i = 0; i < 1000; ++i) {
		cin >> aux;
		for (int j = 11; j >= 0; --j) {
			code[i][j] = aux % 10;
			aux = aux / 10;
		}
		aux = 0;
	}
	for (int j = 0; j < 12; ++j) {
		oneCount = 0, zeroCount = 0;
		for (int i = 0; i < 1000; ++i) {
			if (gammaCounter[i] != 1) {
				if (code[i][j] == 1) oneCount++;
				else zeroCount++;
			}
		}
		if (oneCount >= zeroCount) {
			gamma[j] = 1;
			for (int i = 0; i < 1000; ++i) {
				if (code[i][j] == 0) gammaCounter[i] = 1;
			}
		}
		else {
			gamma[j] = 0;
			for (int i = 0; i < 1000; ++i) {
				if (code[i][j] == 1) gammaCounter[i] = 1;
			}
		}
		cout << endl;
	}
	for (int j = 0; j < 12; ++j) {
		oneCount = 0, zeroCount = 0;
		for (int i = 0; i < 1000; ++i) {
			if (epsilonCounter[i] != 1) {
				if (code[i][j] == 1) oneCount++;
				else zeroCount++;
			}
		}
		//cout << oneCount << ' ' << zeroCount << endl;
		//for (int i = 0; i < 12; ++i) {
		//	cout << epsilon[i] << ' ';
		//}
		//cout << endl;
		if (oneCount != 0 && zeroCount != 0) {
			if (oneCount < zeroCount) {
				epsilon[j] = 1;
				for (int i = 0; i < 1000; ++i) {
					if (code[i][j] == 0) epsilonCounter[i] = 1;
				}
			}
			else {
				epsilon[j] = 0;
				for (int i = 0; i < 1000; ++i) {
					if (code[i][j] == 1) epsilonCounter[i] = 1;
				}
			}
		}
		else {
			for (int i = 0; i < 1000; ++i) {
				if (epsilonCounter[i] != 1) {
					epsilon[j] = code[i][j];
				}
			}
		}
	}
	for (int i = 0; i < 12; ++i) {
		cout << gamma[i];
	}
	cout << endl;
	for (int i = 0; i < 12; ++i) {
		cout << epsilon[i];
	}
	return 0;
}

// gama:    000000010110
// epsilon: 111111101001

// 010100010100
// 101011101011

// phase 2
// 010100101111 -> 1327
// 110101100000 -> 3424