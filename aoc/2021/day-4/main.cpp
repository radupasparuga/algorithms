#include <iostream>
#include <vector>
using namespace std;

/*
7 4 9 5 11 17 23 2 0 14 21 24 10 16 13 6 15 25 12 22 18 20 8 19 3 26 1

22 13 17 11  0
 8  2 23  4 24
21  9 14 16  7
 6 10  3 18  5
 1 12 20 15 19

 3 15  0  2 22
 9 18 13 17  5
19  8  7 25 23
20 11 10 24  4
14 21 16 12  6

14 21 17 24  4
10 16 15  9 19
18  8 23 26 20
22 11 13  6  5
 2  0 12  3  7
*/

int main() {
	vector<vector<vector<int>>> tables(100, vector< vector<int> >(5, vector<int>(5)));
	int bingoNumbers[100], bigCheck = 0, checkSolved[100];

	for (int i = 0; i < 100; ++i) {
		cin >> bingoNumbers[i];
	}
	for (int m = 0; m < 100; ++m) // based O(N)^3 loop to read input
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				cin >> tables[m][i][j];

	for (int k = 0; k < 100; ++k) { // even more based O(N)^4 loop to solve 0_0
		for (int m = 0; m < 100; ++m) {
			if (checkSolved[m] != 1) {
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 5; ++j)
						if (tables[m][i][j] == bingoNumbers[k]) {
							tables[m][i][j] = 100; // mark 
						}
				}
				if (k > 4) {
					int smallCheck = 0;
					for (int i = 0; i < 5; ++i) {
						int check = 1;
						for (int j = 0; j < 5; ++j)
							if (tables[m][i][j] != 100) {
								check = 0;
								break;
							}
						if (check) {
							smallCheck = 1;
							break;
						}
					}
					if (!smallCheck) {
						for (int i = 0; i < 5; ++i) {
							int check = 1;
							for (int j = 0; j < 5; ++j)
								if (tables[m][j][i] != 100) {
									check = 0;
									break;
								}
							if (check) {
								smallCheck = 1;
								break;
							}
						}
					}
					if (smallCheck) {
						int sum = 0;
						for (int i = 0; i < 5; ++i) {
							for (int j = 0; j < 5; ++j)
								if (tables[m][i][j] != 100) {
									sum += tables[m][i][j];
								}
						}
						cout << sum << ' ' << bingoNumbers[k] << ' ' << sum * bingoNumbers[k] << endl;
						checkSolved[m] = 1;
						bigCheck = 1;
					}
				}
			}
		}
	}
	return 0;
}