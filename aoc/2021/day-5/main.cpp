#include <iostream>
#include <fstream>
#define INPUT_LENGTH 500
#define TABLE_LENGTH 1000
using namespace std;

long long vents[1000][1000];
long long vents2[1000][1000];

int problemOne() {
	ifstream input("../../../aoc/2021/day-5/input.txt");
	int count = 0;
	for (int i = 0; i < TABLE_LENGTH; ++i)
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			vents[i][j] = 0;
		}
	for (int i = 0; i < INPUT_LENGTH; ++i) {
		int x1, y1, x2, y2;
		input >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			if (y1 < y2) {
				while (y1 <= y2) vents[x1][y1++]++;
			}
			else if (y1 > y2) {
				while (y1 >= y2) vents[x1][y1--]++;
			}
		}
		else if (y1 == y2) {
			if (x1 < x2) {
				while (x1 <= x2) vents[x1++][y1]++;
			}
			else if (x1 > x2) {
				while (x1 >= x2) vents[x1--][y1]++;
			}
		}
	}
	for (int i = 0; i < TABLE_LENGTH; ++i)
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			if (vents[i][j] >= 2) count++;
		}
	return count;
}

int problemTwo() {
	ifstream input("../../../aoc/2021/day-5/input.txt");
	int count = 0;
	for (int i = 0; i < TABLE_LENGTH; ++i)
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			vents2[i][j] = 0;
		}
	for (int i = 0; i < INPUT_LENGTH; ++i) {
		int x1, y1, x2, y2;
		input >> x1 >> y1 >> x2 >> y2;
		vents2[x1][y1]++;
		while (!(x1 == x2 && y1 == y2)) {
			if (x1 != x2) {
				x1 < x2 ? x1++ : x1--;
			}
			if (y1 != y2) {
				y1 < y2 ? y1++ : y1--;
			}
			vents2[x1][y1]++;
		}

	}
	for (int i = 0; i < TABLE_LENGTH; ++i)
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			if (vents2[i][j] >= 2) count++;
		}
	return count;
}

int main() {
	cout << "Part one: " << problemOne() << endl;
	cout << "Part two: " << problemTwo() << endl;
	return 0;
}