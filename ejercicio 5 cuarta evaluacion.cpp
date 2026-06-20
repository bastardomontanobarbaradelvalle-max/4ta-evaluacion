// realice un programa que permita al usuario ingresar un numero entre 1 y 9999,y este graficado en pantalla. Use la funcion gotoxy para construir los digitos



// 


#include<iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int digitos[10][5][3] = {
    { {1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1} },
    { {0,1,0}, {1,1,0}, {0,1,0}, {0,1,0}, {1,1,1} },
    { {1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1} },
    { {1,1,1}, {0,0,1}, {1,1,1}, {0,0,1}, {1,1,1} },
    { {1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} },
    { {1,1,1}, {1,0,0}, {1,1,1}, {0,0,1}, {1,1,1} },
    { {1,1,1}, {1,0,0}, {1,1,1}, {1,0,1}, {1,1,1} },
    { {1,1,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1} },
    { {1,1,1}, {1,0,1}, {1,1,1}, {1,0,1}, {1,1,1} },
    { {1,1,1}, {1,0,1}, {1,1,1}, {0,0,1}, {1,1,1} }
};

void dibujarDigito(int num, int ox, int oy) {
    int f, c;
    for (f = 0; f < 5; f++) {
        for (c = 0; c < 3; c++) {
            if (digitos[num][f][c] == 1) {
                gotoxy(ox + c, oy + f);
                cout << '*';
            }
        }
    }
}

int main() {
    int numero;
    char seguir;
    int d[4];
    int cantidad;
    int i;

    do {
        system("cls");
        gotoxy(0, 0);
        cout << "Ingrese un numero entre 1 y 9999: ";
        cin >> numero;

        if (numero < 1 || numero > 9999) {
            cout << "Numero fuera de rango." << endl;
        } else {
            system("cls");

            if (numero >= 1000) {
                cantidad = 4;
                d[0] = numero / 1000;
                d[1] = (numero / 100) % 10;
                d[2] = (numero / 10) % 10;
                d[3] = numero % 10;
            } else if (numero >= 100) {
                cantidad = 3;
                d[0] = numero / 100;
                d[1] = (numero / 10) % 10;
                d[2] = numero % 10;
            } else if (numero >= 10) {
                cantidad = 2;
                d[0] = numero / 10;
                d[1] = numero % 10;
            } else {
                cantidad = 1;
                d[0] = numero;
            }

            for (i = 0; i < cantidad; i++) {
                dibujarDigito(d[i], 5 + i * 4, 3);
            }

            gotoxy(0, 10);
            cout << "Numero: " << numero << endl;
        }

        gotoxy(0, 12);
        cout << "Ingresar otro numero? (s/n): ";
        seguir = getch();

    } while (seguir == 's' || seguir == 'S');

    system("cls");
    cout << "Programa terminado." << endl;
    return 0;
}

