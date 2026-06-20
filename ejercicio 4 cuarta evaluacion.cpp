#include <iostream>
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
    double tasa_dolar_bs = 36.50;
    double tasa_euro_bs  = 39.80;
    char opcion;
    bool salir = false;

    do {
        system("cls");
        gotoxy(0, 0);
        cout << "1. Convertir dolares a bolivares" << endl;
        cout << "2. Convertir bolivares a euros" << endl;
        cout << "3. Calcular tiempo de ahorro" << endl;
        cout << "4. Calcular tiempo para bajar de peso" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        opcion = _getch();

        system("cls");

        switch (opcion) {

            case '1': {
                double monto;
                char seguir;
                do {
                    system("cls");
                    gotoxy(0, 0);
                    cout << "Dolares a bolivares (tasa: " << tasa_dolar_bs << ")" << endl;
                    cout << "Monto en dolares: ";
                    cin >> monto;
                    if (monto <= 0) {
                        cout << "El monto debe ser mayor a 0." << endl;
                    } else {
                        cout << monto << " USD = " << monto * tasa_dolar_bs << " Bs" << endl;
                    }
                    cout << "Convertir otro? (s/n): ";
                    seguir = _getch();
                } while (seguir == 's' || seguir == 'S');
                break;
            }

            case '2': {
                double monto;
                char seguir;
                do {
                    system("cls");
                    gotoxy(0, 0);
                    cout << "Bolivares a euros (tasa: " << tasa_euro_bs << ")" << endl;
                    cout << "Monto en bolivares: ";
                    cin >> monto;
                    if (monto <= 0) {
                        cout << "El monto debe ser mayor a 0." << endl;
                    } else {
                        cout << monto << " Bs = " << monto / tasa_euro_bs << " EUR" << endl;
                    }
                    cout << "Convertir otro? (s/n): ";
                    seguir = _getch();
                } while (seguir == 's' || seguir == 'S');
                break;
            }

            case '3': {
                double salario, gastos, meta;
                char seguir;
                do {
                    system("cls");
                    gotoxy(0, 0);
                    cout << "Calcular tiempo de ahorro" << endl;
                    cout << "Salario mensual: ";
                    cin >> salario;
                    cout << "Gastos fijos mensuales: ";
                    cin >> gastos;
                    cout << "Meta de ahorro: ";
                    cin >> meta;

                    double ahorro = salario - gastos;

                    if (salario <= 0 || meta <= 0) {
                        cout << "Los valores deben ser mayores a 0." << endl;
                    } else if (ahorro <= 0) {
                        cout << "No es posible ahorrar con esos gastos." << endl;
                    } else {
                        double acumulado = 0;
                        int mes = 0;
                        cout << endl;
                        cout << "Mes | Acumulado" << endl;
                        do {
                            mes++;
                            acumulado += ahorro;
                            if (acumulado > meta) acumulado = meta;
                            cout << " " << mes << "  | " << acumulado << endl;
                        } while (acumulado < meta);
                        cout << endl;
                        cout << "Necesitas " << mes << " meses para alcanzar la meta." << endl;
                    }

                    cout << "Calcular otra meta? (s/n): ";
                    seguir = _getch();
                } while (seguir == 's' || seguir == 'S');
                break;
            }
            case '4': {
                double peso_actual, peso_deseado, kg_mes;
                char seguir;
                do {
                    system("cls");
                    gotoxy(0, 0);
                    cout << "Calcular tiempo para bajar de peso" << endl;
                    cout << "Peso actual (kg): ";
                    cin >> peso_actual;
                    cout << "Peso deseado (kg): ";
                    cin >> peso_deseado;
                    cout << "Kg que puede perder por mes: ";
                    cin >> kg_mes;

                    if (peso_actual <= 0  || peso_deseado <= 0  || kg_mes <= 0) {
                        cout << "Los valores deben ser mayores a 0." << endl;
                    } else if (peso_deseado >= peso_actual) {
                        cout << "El peso deseado debe ser menor al actual." << endl;
                    } else {
                        double peso = peso_actual;
                        int mes = 0;
                        cout << endl;
                        cout << "Mes | Peso" << endl;
                        do {
                            mes++;
                            peso -= kg_mes;
                            if (peso < peso_deseado) peso = peso_deseado;
                            cout << " " << mes << "  | " << peso << " kg" << endl;
                        } while (peso > peso_deseado);
                        cout << endl;
                        cout << "Necesitas " << mes << " meses para alcanzar tu peso." << endl;
                    }

                    cout << "Calcular otra meta? (s/n): ";
                    seguir = _getch();
                } while (seguir == 's' || seguir == 'S');
                break;
            }

            case '5':
                salir = true;
                break;

            default:
                gotoxy(0, 0);
                cout << "Opcion no valida." << endl;
                Sleep(800);
                break;
        }

    } while (!salir);

    system("cls");
    cout << "Programa terminado." << endl;
    return 0;
}
            
            
            
            
            
            
            
