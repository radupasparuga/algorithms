#include <iostream>

#define grad(P)(sizeof(P)/sizeof(*P))

using namespace std;

int calculPolinom(int x, int p[]) {
    int rezultat = p[0];
    cout << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << endl;
    cout << grad(p) << endl;
    for (int i = 1; i < grad(p); ++i) {
        rezultat = rezultat * x + p[i];
    }
    return rezultat;
}

int main() {
    int p[] = {1, 1, 1, 1};
    cout << grad(p) << endl;
    int res = calculPolinom(10, p);
    cout << res;
    return 0;
}
