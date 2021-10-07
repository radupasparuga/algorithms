#include <iostream>
#include <cmath>

using namespace std;

/*
 * 14.  Scrieti functii pentru implementarea operatiilor specifice pe vectori din R2:
 *      citirea de la tastatura a celor doua componente ale unui vector, afisarea componentelor
 *      vectorului sub forma unei perechi de elemente, suma, diferenta si produsul scalar al doi vectori,
 *      produsul dintre un vector si un scalar real, opusul si norma euclidiana a unui vector.
 *
 * 15.  Scrieti functii pentru implementarea operatiilor specifice pe vectori din Rn:  citirea de la tastatura
 *      a celor n componente ale unui vector, afisarea componentelor vectorului sub forma unui n-uplu de elemente,
 *      suma, diferenta si  produsul  scalar  al  doi  vectori,  produsul  dintre  un  vector si  un  scalar  real,
 *      opusul si  norma euclidiana a unui vector.  Se vor folosi tablouri unidimensionale alocate static.
 */

void citireVector(float *vec, int n);
void citireScalar(float* scalar, int n);
void afisareVector(float *vec, int n);
void sumaVector(float *vec1, float *vec2, int n);
void diferentaVector(float *vec1, float *vec2, int n);
void produsScalar(float *vec1, float *vec2, int n);
void produsVectorScalar(float *vec1, float scalar, int n);
void opusVector(float *vec, int n);
void normaEuclidiana(float *vec, int n);

int main() {
    int n;
    cout << "Introdu numarul de dimensiuni: ";
    cin >> n;
    float vec1[n], vec2[n], scalar;
    citireVector(vec1, n);
    citireVector(vec2, n);
    citireScalar(&scalar, n);

    cout << scalar << endl;
    afisareVector(vec1, n);
    afisareVector(vec2, n);

    sumaVector(vec1, vec2, n);
    diferentaVector(vec1, vec2, n);
    produsScalar(vec1, vec2, n);
    produsVectorScalar(vec1, scalar, n);

    opusVector(vec1, n);
    normaEuclidiana(vec1, n);
    return 0;
}

void citireVector(float *vec, int n) {
    cout << "Introdu elementele vectorului (separate cu spatiu): ";
    for (int i = 0; i < n; ++i) cin >> *(vec + i);
}

void citireScalar(float* scalar, int n) {
    cout << "Introdu scalar: ";
    cin >> *scalar;
}

void afisareVector(float *vec, int n) {
    cout << '(';
    for (int i = 0; i < n; ++i) cout << *(vec+i) << ' ';
    cout << ')' << endl;
}

void sumaVector(float *vec1, float *vec2, int n) {
    float rezultat[n];
    for (int i = 0; i < n; ++i) rezultat[i] = *(vec1+i) + *(vec2+i);
    afisareVector(rezultat, n);
}

void diferentaVector(float *vec1, float *vec2, int n) {
    float rezultat[n];
    for (int i = 0; i < n; ++i) rezultat[i] = *(vec1+i) - *(vec2+i);
    afisareVector(rezultat, n);
}

void produsScalar(float *vec1, float *vec2, int n) {
    float rezultat = 0;
    for (int i = 0; i < n; ++i) rezultat += *(vec1+i) * *(vec2+i);
    printf("Produs scalar: %.2f\n", rezultat);
}

void produsVectorScalar(float *vec1, float scalar, int n) {
    float rezultat[n];
    for (int i = 0; i < n; ++i) rezultat[i] = *(vec1+i) * scalar;
    cout << "Produs intre vector si scalar: ";
    afisareVector(rezultat, n);
}

void opusVector(float *vec, int n) {
    float rezultat[n];
    for (int i = 0; i < n; ++i) rezultat[i] = *(vec+i) * -1;
    cout << "Opus vector: ";
    afisareVector(rezultat, n);
}

void normaEuclidiana(float *vec, int n) {
    float rezultat, subRadical = 0;
    for (int i = 0; i < n; ++i) subRadical += pow(*(vec+i), 2.0);
    rezultat = sqrt(subRadical);
    printf("Norma euclidiana: %.2f\n", rezultat);
}