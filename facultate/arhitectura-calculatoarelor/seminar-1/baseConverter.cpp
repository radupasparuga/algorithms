#include <iostream>

using namespace std;

// conversii

int decToBin(int x);
int binToDec(int x);
int decToHex(int x);
int hexToDec(int x);
int binToHex(int x);
int hexToBin(int x);

// HUB de conversii
void chooseConversion();
void nextStep();

// citiri/afisari
int citireDec();

int main() {
    chooseConversion();
    return 0;
}

int citireDec() {
    int x;
    printf("Introdu numarul in baza 10: ");
    scanf("%d", &x);
    return x;
}

void chooseConversion() {
    int choice, dec;

    printf("Introdu codul specific conversiei pe care vrei sa o faci \n");
    printf("Legenda: \n - 1: decimal -> binar \n - 2: binar -> decimal \n - 3: decimal -> hexadecimal \n - 4: hexadecimal -> decimal \n - 5: binar -> hexadecimal \n - 6: hexadecimal -> binar \n - 0: Iesi din program \n");
   
    cin >> choice;

    switch(choice) {
        case 0:
            return;
            break;
        case 1:
            dec = citireDec();
            cout << dec << "\n";
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
