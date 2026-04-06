#include <iostream>
using namespace std;

int main() {
    int opcion;
    int numeros[100];
    int contador = 0;
    int suma = 0;

    do {
        cout << "1. Registrar numeros\n";
        cout << "2. Mostrar estadisticas\n";
        cout << "3. Clasificar numeros\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {
                int num;
                char continuar;

                do {
                    cout << "Ingrese un numero: ";
                    cin >> num;

                    if (num < 0) {
                        cout << "Error: No se permiten numeros negativos\n";
                        continue;
                    }

                    numeros[contador] = num;
                    contador++;
                    suma += num;

                    cout << "Desea ingresar otro numero? (s/n): ";
                    cin >> continuar;

                } while(continuar == 's' || continuar == 'S'); // uso de ||

                break;
            }

            case 2:
                if (contador == 0) {
                    cout << "No hay datos disponibles.\n";
                } else {
                    cout << "Total de numeros ingresados: " << contador << endl;
                    cout << "Suma total: " << suma << endl;
                    cout << "Promedio: " << static_cast<float>(suma) / contador << endl;
                }
                break;

            case 3:
                if (contador == 0) {
                    cout << "No hay datos para clasificar.\n";
                } else {
                    int pares = 0, impares = 0;

                    for (int i = 0; i < contador; i++) {

                        // Uso de && y ||
                        if (numeros[i] % 2 == 0 && numeros[i] >= 0) {
                            pares++;
                        }
                        else if (numeros[i] % 2 != 0 || numeros[i] == 1) {
                            impares++;
                        }
                    }

                    cout << "Cantidad de numeros pares: " << pares << endl;
                    cout << "Cantidad de numeros impares: " << impares << endl;
                }
                break;

            case 4:
                cout << "Gracias por usar el sistema. ¡Hasta luego!\n";
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while(opcion != 4);

    return 0;
}
