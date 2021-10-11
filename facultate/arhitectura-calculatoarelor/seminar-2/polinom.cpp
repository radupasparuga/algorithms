#include <iostream>

#define grad(P)(sizeof(P)/sizeof(*P))

using namespace std;

// metoda prin care se pastreaza valoarea lui P prin functie
template<typename T, size_t N>
int calculPolinom(int x, T (&p)[N]) {
    int rezultat = p[0];
    for (int i = 1; i < grad(p); ++i) {
        rezultat = rezultat * x + p[i];
    }
    return rezultat;
}

int main() {
    int p[] = {1, 1, 1, 1, 1};
    int res = calculPolinom(10, p);
    printf("Calcul polinom: %i", res);
    return 0;
}
