#include <iostream>
#include <string>
#define N 1000

using namespace std;

int main() {
	int horizontal = 0, depth = 0, aim = 0;
	string instructions[N];
	int values[N];
	
	for (int i = 0; i < N; ++i) {
		cin >> instructions[i] >> values[i];
	}

	for (int i = 0; i < N; ++i) {
		if (instructions[i] == "forward") {
			horizontal += values[i];
			depth += (aim * values[i]);
		}
		else if (instructions[i] == "down") {
			aim += values[i];
		}
		else if (instructions[i] == "up") {
			aim -= values[i];
		}
	}
	cout << horizontal << ' ' << depth << ' ' << horizontal * depth;
	return 0;
}