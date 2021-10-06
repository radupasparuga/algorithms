#include <iostream>
#include <cmath>

using namespace std;

/*
 * 14.  Scrieti functii pentru implementarea operatiilor specifice pe vectori dinR2:
 *      citirea de la tastatura a celor doua componente ale unui vector, afisarea componentelor
 *      vectorului sub forma unei perechi de elemente, suma, diferenta si produsul scalar al doi vectori,
 *      produsul dintre un vector si un scalar real, opusul si norma euclidiana a unui vector.
 */

void citireVector(float *vec);
void citireScalar(float* scalar);
void afisareVector(float *vec);
void sumaVector(float *vec1, float *vec2);
void diferentaVector(float *vec1, float *vec2);
void produsScalar(float *vec1, float *vec2);
void produsVectorScalar(float *vec1, float scalar);
void opusVector(float *vec);
void normaEuclidiana(float *vec);

int main() {
    float vec1[2], vec2[2], scalar;
    citireVector(vec1);
    citireVector(vec2);
    citireScalar(&scalar);

    cout << scalar << endl;
    afisareVector(vec1);
    afisareVector(vec2);

    sumaVector(vec1, vec2);
    diferentaVector(vec1, vec2);
    produsScalar(vec1, vec2);
    produsVectorScalar(vec1, scalar);

    opusVector(vec1);
    normaEuclidiana(vec1);
    return 0;
}

void citireVector(float *vec) {
    cout << "Introdu elementele vectorului (separate cu spatiu): ";
    cin >> *vec >> *(vec+1);
}

void citireScalar(float* scalar) {
    cout << "Introdu scalar: ";
    cin >> *scalar;
}

void afisareVector(float *vec) {
    printf("(%.2f, %.2f)\n", *vec, *(vec+1));
}

void sumaVector(float *vec1, float *vec2) {
    float rezultat[2];
    rezultat[0] = *vec1 + *vec2;
    rezultat[1] = *(vec1+1) + *(vec2+1);
    afisareVector(rezultat);
}

void diferentaVector(float *vec1, float *vec2) {
    float rezultat[2];
    rezultat[0] = *vec1 - *vec2;
    rezultat[1] = *(vec1+1) - *(vec2+1);
    afisareVector(rezultat);
}

void produsScalar(float *vec1, float *vec2) {
    float rezultat;
    rezultat = *vec1 * *vec2 + *(vec1+1) * *(vec2+1);
    printf("Produs scalar: %.2f\n", rezultat);
}

void produsVectorScalar(float *vec1, float scalar) {
    float rezultat[2];
    rezultat[0] = *vec1 * scalar;
    rezultat[1] = *(vec1+1) * scalar;
    cout << "Produs intre vector si scalar: ";
    afisareVector(rezultat);
}

void opusVector(float *vec) {
    float rezultat[2];
    rezultat[0] = *vec * -1;
    rezultat[1] = *(vec+1) * -1;
    cout << "Opus vector: ";
    afisareVector(rezultat);
}

void normaEuclidiana(float *vec) {
    float rezultat;
    rezultat = sqrt(pow(*vec, 2.0) + pow(*(vec+1), 2.0));
    printf("Norma euclidiana: %.2f\n", rezultat);
}