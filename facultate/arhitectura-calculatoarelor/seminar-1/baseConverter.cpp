#include <iostream>
#include <math.h>

using namespace std;

// Functii meniu
void chooseConversion();
void nextStep();

// citiri/afisari
int citireDec();
int *citireBin();
void afisareBin(int *bin);

// conversii
int *decToBin(int x);
int binToDec(int *bin);
int decToHex(int x);
int hexToDec(int x);
int binToHex(int x);
int hexToBin(int x);

int main() {
    chooseConversion();
    return 0;
}

// Functii meniu
void chooseConversion() {
    int choice, dec, *bin;

    printf("Introdu codul specific conversiei pe care vrei sa o faci \n");
    printf("Legenda: \n - 1: decimal -> binar \n - 2: binar -> decimal \n - 3: decimal -> hexadecimal \n - 4: hexadecimal -> decimal \n - 5: binar -> hexadecimal \n - 6: hexadecimal -> binar \n - 0: Iesi din program \n");
   
    cin >> choice;

    switch(choice) {
        case 0:
            return;
            break;
        case 1: // dec to bin
            dec = citireDec();
            bin = decToBin(dec);
            afisareBin(bin);
            nextStep();
            break;
        case 2: // bin to dec
            bin = citireBin();
            dec = binToDec(bin);
            cout << dec << endl;
            nextStep();
            break;
        default:
            printf("Ai introdus un cod gresit, incearca din nou \n");
            chooseConversion();
            break;
    }
}

void nextStep() {
    int choice;
    printf("Ce vrei sa faci in continuare? \n - 0: Iesi din program \n - 1: Incearca alta conversie \n");
    cin >> choice;
    switch(choice) {
        case 0:
            return;
        case 1:
            chooseConversion();
            break;
        default:
            printf("Ai introdus un cod gresit, incearca din nou \n");
            nextStep();
            break;
    }
}

// citiri/afisari
int citireDec() {
    int x;
    printf("Introdu numarul in baza 10: ");
    scanf("%d", &x);
    return x;
}

int *citireBin() {
    static int bin[32], len;
    printf("Introdu numarul de biti (maxim 32): ");
    scanf("%d", &len);
    printf("introdu numarul in baza 2 (cu spatii intre biti): ");
    for (int i = len - 1; i >= 0; --i) scanf("%d", &(*(bin+i)));
    return bin;
}

void afisareBin(int *bin) {
    int start = 31;
    printf("Afisare pe 32 biti:");
    for (int i = 31; i >= 0; --i) {
        if ((i+1) % 8 == 0) printf(" ");
        if (*(bin+i) == 1 && start == 31) start = i;
        printf("%d", *(bin+i));    
    }
    printf("\nAfisare scurta: ");
    for (int i = start; i >= 0; --i) printf("%d", *(bin+i));
    printf("\n");
}

// conversii
int *decToBin(int x) {
    static int bin[32];
    for (int i = 0; x > 0; ++i) {
        bin[i] = x%2;
        x = x/2;
    }
    return bin;
}

int binToDec(int *bin) {
    int result = 0;
    for (int i = 31; i >= 0; --i) {
        result += *(bin+i) *  pow(2, i);
    }
    return result;
}
