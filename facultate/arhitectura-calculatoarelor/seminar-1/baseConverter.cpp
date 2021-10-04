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
int *citireHex();
void afisareHex(int *hex);

// conversii
int *decToBin(int x);
int binToDec(int *bin);
int *binToHex(int *bin);
int *hexToBin(int *hex);

int main() {
    chooseConversion();
    return 0;
}

// Functii meniu
void chooseConversion() {
    int choice, dec, *bin, *hex;

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
            printf("Afisare in baza 10: %d\n", dec);
            nextStep();
            break;
        case 3: // dec to hex
            dec = citireDec();
            bin = decToBin(dec);
            hex = binToHex(bin);
            afisareHex(hex);
            nextStep();
            break;
        case 4: // hex to dec
            hex = citireHex();
            bin = hexToBin(hex);
            dec = binToDec(bin);
            printf("Afisare in baza 10: %d\n", dec);
            nextStep();
            break;
        case 5: // bin to hex
            bin = citireBin();
            hex = binToHex(bin);
            afisareHex(hex);
            nextStep();
            break;
        case 6: // hex to bin
            hex = citireHex();
            bin = hexToBin(hex);
            afisareBin(bin);
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

int *citireHex() {
    static int hex[8];
    int m = 0;
    string input;

    cout << "Introdu numarul in format hexadecimal: (litere cu majuscule si fara spatii!) ";
    cin.ignore();
    getline(cin, input);

    for (char const &c: input) {
        if ((int)c >= 65 && (int)c <= 70) {
            switch((int)c) {
                case 65:
                    hex[m++] = 10;
                    break;
                case 66:
                    hex[m++] = 11;
                    break;
                case 67:
                    hex[m++] = 12;
                    break;
                case 68:
                    hex[m++] = 13;
                    break;
                case 69:
                    hex[m++] = 14;
                    break;
                case 70:
                    hex[m++] = 15;
                    break;
                default:
                    printf("Input invalid, incearca din nou.\n");
                    nextStep();
                    break;
            }
        } else if((int)c >= 48 && (int)c <= 57) {
            hex[m++] = c - '0';
        } else {
            printf("Input invalid, incearca din nou. \n");
            nextStep();
        }
    }

    return hex;
}

void afisareHex(int *hex) {
    printf("Afisare hex: ");
    for (int i = 7; i >= 0; --i) {
        if ((i+1) % 2 == 0) printf(" ");
        if (hex[i] > 9) {
            switch(hex[i]) {
                case 10:
                    printf("%s", "A");
                    break;
                case 11:
                    printf("%s", "B");
                    break;
                case 12:
                    printf("%s", "C");
                    break;
                case 13:
                    printf("%s", "D");
                    break;
                case 14:
                    printf("%s", "E");
                    break;
                case 15:
                    printf("%s", "F");
                    break;
                default:
                    printf("%d", hex[i]);
            }
        } else {
            printf("%d", hex[i]);
        }
    }
    printf("\n");
}

// conversii
int *decToBin(int x) {
    static int bin[32] = {0};
    int i = 0;
    while (x > 0) {
        bin[i] = x % 2;
        x = x / 2;
        i++;
    }
    return bin;
}

int binToDec(int *bin) {
    int result = 0;
    for (int i = 31; i >= 0; --i) {
        result += *(bin+i) * pow(2, i);
    }
    return result;
}

int *binToHex(int *bin) {
    static int hex[8];
    int binGroup[32] = {0}, m = 7;
    for (int i = 31; i >= 0; i -= 4) {
        int dec;
        binGroup[3] = *(bin+i);
        binGroup[2] = *(bin+i-1);
        binGroup[1] = *(bin+i-2);
        binGroup[0] = *(bin+i-3);
        dec = binToDec(binGroup);
        hex[m--] = dec;
    }
    return hex;
}

int *hexToBin(int *hex) {
    static int bin[32];
    int m = 31;
    for (int i = 0; i < 8; ++i) {
        if (*(hex+i) != 0) {
            int *auxBin = decToBin(*(hex+i));
            cout << *(hex+i) << ' ' << *(auxBin+3) << *(auxBin+2) << *(auxBin+1) << *(auxBin) << endl;
            bin[m--] = *(auxBin+3);
            bin[m--] = *(auxBin+2);
            bin[m--] = *(auxBin+1);
            bin[m--] = *(auxBin);
        } else {
            break;
        }
    }
    return bin;
}
