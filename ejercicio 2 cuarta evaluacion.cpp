//realice un programa que muestre en pantalla un restangulo sin relleno, y que dentro del mismo aparezca el natalicio de su nacimiento tambien graficado en gotoxy
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
    { {1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1} }, // 0
    { {0,1,0}, {1,1,0}, {0,1,0}, {0,1,0}, {1,1,1} }, // 1
    { {1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1} }, // 2
    { {1,1,1}, {0,0,1}, {1,1,1}, {0,0,1}, {1,1,1} }, // 3
    { {1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} }, // 4
    { {1,1,1}, {1,0,0}, {1,1,1}, {0,0,1}, {1,1,1} }, // 5
    { {1,1,1}, {1,0,0}, {1,1,1}, {1,0,1}, {1,1,1} }, // 6
    { {1,1,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1} }, // 7
    { {1,1,1}, {1,0,1}, {1,1,1}, {1,0,1}, {1,1,1} }, // 8
    { {1,1,1}, {1,0,1}, {1,1,1}, {0,0,1}, {1,1,1} }  // 9
};

int main() {
    int anio = 2007;
    char opcion;
    bool salir = false;

    do {
        system("cls");

        int rx = 2, ry = 2, ancho = 44, alto = 13;
        int f, c;

        for (f = 0; f < alto; f++) {
            for (c = 0; c < ancho; c++) {
                if (f == 0  || f == alto - 1  || c == 0 || c == ancho - 1) {
                    gotoxy(rx + c, ry + f);
                    cout << '*';
                }
            }
        }

        int d[4];
        d[0] = anio / 1000;
        d[1] = (anio / 100) % 10;
        d[2] = (anio / 10) % 10;
        d[3] = anio % 10;

        int i;
        for (i = 0; i < 4; i++) {
            int ox = 16 + i * 4;
            int oy = 6;
            for (f = 0; f < 5; f++) {
                for (c = 0; c < 3; c++) {
                    if (digitos[d[i]][f][c] == 1) {
                        gotoxy(ox + c, oy + f);
                        cout << '#';
                    }
                }
            }
        }

        // menu
        gotoxy(0, 17);
        cout << "1. Cambiar anio" << endl;
        cout << "2. Salir" << endl;
        cout << "Opcion: ";
        opcion = _getch();

        switch (opcion) {
            case '1':
                gotoxy(0, 20);
                cout << "Ingrese el nuevo anio: ";
                int nuevo;
                cin >> nuevo;
                if (nuevo >= 1000 && nuevo <= 9999) {
                    anio = nuevo;
                } else {
                    gotoxy(0, 21);
                    cout << "Anio no valido.";
                    Sleep(1000);
                }
                break;
            case '2':
                salir = true;
                break;
            default:
                gotoxy(0, 20);
                cout << "Opcion no valida.";
                Sleep(800);
                break;
        }

    } while (!salir);

    system("cls");
    cout << "Programa terminado." << endl;
    return 0;
}
