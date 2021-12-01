#include <iostream>
#define N 2000

using namespace std;

int main() {
	int count1 = 0, count2 = 0;
	int arr[N];

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N - 1; ++i) {
		if (arr[i] < arr[i + 1]) {
			count1++;
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		if (arr[i] + arr[i + 1] + arr[i + 2] < arr[i + 1] + arr[i + 2] + arr[i + 3]) {
			count2++;
		}
	}
	cout << count1 << endl << count2;
	return 0;
}