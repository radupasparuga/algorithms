/* Laborator 2. Problema 11 */
#include<iostream>
#include<cmath>

using namespace std;

/*
 *  Scrieti functii pentru implementarea operatiilor specifice pe matrice de numere reale cu m linii si n coloane:
 *  citirea de la tastatur a componentelor unei matrice, afisarea componentelor matricei, suma, diferenţa si produsul
 *  al doua matrice, produsul dintre o matrice si un scalar real, transpusa si opusa unei matrice, norme matriceale
 *  specifice. Pentru cazul particular al unei matrice patratice de ordin n, sa se testeze daca aceasta satisface
 *  criteriul de dominanta pe linii sau pe coloane. Se vor folosi tablouri bidimensionale alocate dinamic.
 * */

void error(char const msg[]) {
    cout << msg << endl;
    cout << "Programul se opreste." << endl;
    system("pause");
    exit(1);
}

double** alocare(int m, int n) {
    double **mat = new (nothrow) double*[m];
    if (mat == nullptr)
        error("Eroare la alocarea liniilor.");
    for (int i = 0; i < m; ++i) {
        mat[i] = new(nothrow) double[n];
        if (mat[i] == nullptr)
            error("Eroare la alocarea coloanelor");
    }
    return mat;
}

void dealocare(double** mat, int m) {
    for (int i = 0; i < m; ++i)
        delete []mat[i];
    delete []mat;
}

void citire(int m, int n, double **mat) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "[" << i << "," << j << "] : ";
            cin >> mat[i][j];
        }
}

void afisare(int m, int n, double **mat) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

double** suma(double **mat1, double **mat2, int m, int n) {
    double** res = alocare(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = mat1[i][j] + mat2[i][j];
    return res;
}

double** diferenta(double** mat1, double** mat2, int m, int n) {
    double** res = alocare(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = mat1[i][j] - mat2[i][j];
    return res;
}

double** produsMatrice(double **mat1, double **mat2, int m, int n) {
    double** res = alocare(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
                res[i][j] = res[i][j] + mat1[i][k] * mat2[k][j];
        }
    return res;
}
double** produsMatriceScalar(double **mat1, double scalar, int m, int n) {
    double** res = alocare(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            res[i][j] = scalar * mat1[i][j];
    }
    return res;
}

double** transpusaMatrice(double** mat1, int m, int n) {
    double** res = alocare(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            res[j][i] = mat1[i][j];
        cout << endl;
    }
    return res;
}

double** opusMatrice(double **mat1, int m, int n) {
    double** res = alocare(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            res[i][j] = (-1) * mat1[i][j];
    }
    return res;

}
double norma1(double** mat1, int m, int n) {
    double arr[100], res;
    for (int j = 0; j < n; j++) {
        arr[j] = 0;
        for (int i = 0; i < m; i++)
            arr[j] = arr[j] + abs(mat1[i][j]);
    }
    res = arr[0];
    for (int j = 1; j < n; j++) if (arr[j] > res) res = arr[j];
    return res;
}

double normaInfinita(double** mat1, int m, int n) {
    double arr[100], res;
    for (int i = 0; i < m; i++) {
        arr[i] = 0;
        for (int j = 0; j < n; j++)
            arr[i] = arr[i] + abs(mat1[i][j]);
    }
    res = arr[0];
    for (int i = 1; i < m;i++) if (arr[i] > res) res = arr[i];
    return res;
}

double normaEuclidiana(double** mat1, int m, int n) {
    double res = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res = res + pow(mat1[i][j], 2);
    return sqrt(res);
}

int main()
{
    int m, n;
    cout << "Numarul de linii: ";
    cin >> m;
    cout << "Numarul de coloane: ";
    cin >> n;

    double **mat1 = alocare(m, n);
    double **mat2 = alocare(m, n);
    double **res = 0;

    cout << "Matrice1: " << endl;
    citire(m, n, mat1);
    cout << "Prima matrice:" << endl;
    afisare(m, n, mat1);
    cout << "Matrice2: " << endl;
    citire(m, n, mat2);
    cout << "A doua matrice:" << endl;
    afisare(m, n, mat2);

    unsigned raspuns;
    do {
        cout << "Alegeti operatia (conform numarului de ordine): " << endl;
        cout << "1 - Suma a doua matrice." << endl
             << "2 - Diferenta a doua matrice." <<endl
             << "3 - Produsul al doua matrice" << endl
             << "4 - Produsul dintre o matrice si un scalar real" << endl
             << "5 - Transpusa unei matrice" << endl
             << "6 - Opusa unei matrice" << endl
             << "7 - Norme matriceale" << endl
             << "8 - Terminare program." << endl;
        cin >> raspuns;
        switch (raspuns) {
            case 1:
                res = suma(mat1, mat2, m, n);
                cout << "Matricea rezultata: " << endl;
                afisare(m, n, res);
                break;
            case 2:
                res = diferenta(mat1, mat2, m, n);
                cout << "Matricea rezultata: " << endl;
                afisare(m, n, res);
                break;
            case 3:
                res = produsMatrice(mat1, mat2, m, n);
                cout << "Produs matrice: " << endl;
                afisare(m, n, res);
                break;
            case 4:
                int scalar;
                cout << "Scalarul: ";
                cin >> scalar;
                res = produsMatriceScalar(mat1, scalar, m, n);
                cout << "Matricea rezultata" << endl;
                afisare(m, n, res);
                break;
            case 5:
                res = transpusaMatrice(mat1, m, n);
                cout << "Transpusa matricei: " << endl;
                afisare(n, m, res);
                break;
            case 6:
                res = opusMatrice(mat1, m, n);
                cout << "Opusa matricei: " << endl;
                afisare(m, n, res);
                break;
            case 7:
                cout << "Norma 1: " << norma1(mat1, m, n) << endl
                    << "Norma infinita: " << normaInfinita(mat1, m, n) << endl
                    << "Norma euclidiana: " << normaEuclidiana(mat1, m, n) << endl;
                break;
            case 8:
                break;
            default:
                cout << "Tasteaza un numar de la 1 la 8!" << endl;
        }
    }while(raspuns != 8);

    dealocare(mat1, m);
    dealocare(mat2, m);
    system("pause");
    return 0;
}