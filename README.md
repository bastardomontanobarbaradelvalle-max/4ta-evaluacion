[Uploading ejercicio 3 cuarta evaluacion.cpp…]()
//Escriba, compile y ejecute un programa que permita al usuario elegir entre tres figuras que muestren en pantalla: un cuadro, un triangulo y un restangulo
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

int main() {
    char opcion;
    bool salir = false;
    int f, c;

    do {
        system("cls");

        gotoxy(0, 0);
        cout << "Elija una figura:" << endl;
        cout << "1. Cuadrado" << endl;
        cout << "2. Triangulo" << endl;
        cout << "3. Rectangulo" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";

        opcion = _getch();

        system("cls");

        switch (opcion) {

            case '1':
                // cuadrado de 10x10 sin relleno
                gotoxy(0, 0);
                cout << "Cuadrado:" << endl;
                for (f = 0; f < 10; f++) {
                    for (c = 0; c < 10; c++) {
                        if (f == 0  || f == 9  || c == 0 || c == 9) {
                            gotoxy(c * 2, f + 2);
                            cout << '*';
                        }
                    }
                }
                break;

            case '2':
                // triangulo isosceles sin relleno
                gotoxy(0, 0);
                cout << "Triangulo:" << endl;
                for (f = 0; f < 10; f++) {
                    for (c = 0; c <= f; c++) {
                        if (c == 0  || c == f  || f == 9) {
                            gotoxy(9 - f + c * 2, f + 2);
                            cout << '*';
                        }
                    }
                }
                break;

            case '3':
                // rectangulo 18 ancho x 8 alto sin relleno
                gotoxy(0, 0);
                cout << "Rectangulo:" << endl;
                for (f = 0; f < 8; f++) {
                    for (c = 0; c < 18; c++) {
                        if (f == 0  || f == 7  || c == 0 || c == 17) {
                            gotoxy(c * 2, f + 2);
                            cout << '*';
                        }
                    }
                }
                break;

            case '4':
                salir = true;
                break;

            default:
                gotoxy(0, 0);
                cout << "Opcion no valida.";
                Sleep(800);
                break;
        }

        if (!salir) {
            gotoxy(0, 14);
            cout << "Presione una tecla para continuar...";
            _getch();
        }

    } while (!salir);

    system("cls");
    cout << "Programa terminado." << endl;
    return 0;
}
