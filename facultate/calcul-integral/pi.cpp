#include <iostream>
#include <cmath>

using namespace std;

void pi(int n) {
	float sum = 0;
	for (int k = 1; k <= n; ++k) {
		float aux = float(k / float(n));
		sum += sqrt(1 - pow(aux, 2.0));
	}
	sum = float(sum / float(n));
	printf("pi: %.32f", sum);
}

int main() {
	int n;
	printf("Introdu un numar: ");
	scanf("%d", &n);
	pi(n);

	return 0;
}