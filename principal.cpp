/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

const int TOTAL_PUESTOS = 40; // Total de puestos en el parqueadero
double tarifaPorHora = 5.0; // Tarifa por hora

// Estructura para representar al propietario del vehículo
struct Propietario {
    string nombre;
    string cedula;
    string correo;
};

// Estructura para representar los detalles del vehículo
struct Vehiculo {
    string placa;
    string tipoVehiculo;
    string color;
    string horaEntrada;
    string horaSalida; // Hora de salida
};

// Estructura para representar un puesto de parqueadero
struct Puesto {
    int numero;
    bool ocupado = false;
    Propietario propietario;
    Vehiculo vehiculo;
};

// Función para convertir hora a minutos
int convertirHoraEnMinutos(string hora) {
    int horas, minutos;
    char separador;
    string periodo;

    horas = (hora[0] - '0') * 10 + (hora[1] - '0');
    minutos = (hora[3] - '0') * 10 + (hora[4] - '0');
    periodo = hora.substr(6, 2); // Obtener AM/PM

    if (periodo == "PM" && horas != 12) {
        horas += 12; // Convertir a 24 horas
    }
    if (periodo == "AM" && horas == 12) {
        horas = 0; // Medianoche
    }

    return horas * 60 + minutos;
}

// Función para validar cédula
bool validarCedula(string cedula) {
    int longitud = 0;
    for (char c : cedula) {
        if (c < '0' || c > '9') {
            return false;
        }
        longitud++;
    }
    return (longitud >= 8 && longitud <= 10); // Validar longitud
}

// Función para validar placa de carro
bool validarPlacaCarro(string placa) {
    if (placa[0] == 0 || placa[1] == 0 || placa[2] == 0 || placa[3] == 0 || placa[4] == 0 || placa[5] == 0) {
        return false;
    }
    if (placa[0] < 'A' || placa[0] > 'Z' || placa[1] < 'A' || placa[1] > 'Z' || placa[2] < 'A' || placa[2] > 'Z') {
        return false;
    }
    for (int i = 3; i < 6; i++) {
        if (placa[i] < '0' || placa[i] > '9') {
            return false;
        }
    }
    return true;
}

// Función para validar placa de moto
bool validarPlacaMoto(string placa) {
    if (placa[0] == 0 || placa[1] == 0 || placa[2] == 0 || placa[3] == 0 || placa[4] == 0 || placa[5] == 0) {
        return false;
    }
    if (placa[0] < 'A' || placa[0] > 'Z' || placa[1] < 'A' || placa[1] > 'Z' || placa[2] < 'A' || placa[2] > 'Z') {
        return false;
    }
    for (int i = 3; i < 5; i++) {
        if (placa[i] < '0' || placa[i] > '9') {
            return false;
        }
    }
    if (placa[5] < 'A' || placa[5] > 'Z') {
        return false;
    }
    return true;
}

int main() {
    Puesto parqueadero[TOTAL_PUESTOS];

    // Inicialización de los puestos
    for (int i = 0; i < TOTAL_PUESTOS; i++) {
        parqueadero[i].numero = i + 1;
    }

    char opcion;
    do {
        cout << "\nBienvenido al sistema de administración de parqueadero\n";
        cout << "1. Ingresar un vehículo al parqueadero\n";
        cout << "2. Dar salida a un vehículo del parqueadero\n";
        cout << "3. Consultar puestos disponibles\n";
        cout << "4. Cambiar la tarifa del parqueadero\n";
        cout << "5. Consultar vehículos ingresados\n";
        cout << "6. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == '1') {
            Vehiculo vehiculo;
            Propietario propietario;

            cout << "Ingrese el tipo de vehículo (carro/moto): ";
            cin >> vehiculo.tipoVehiculo;

            if (vehiculo.tipoVehiculo == "carro") {
                do {
                    cout << "Ingrese la placa del carro (formato ABC123): ";
                    cin >> vehiculo.placa;
                    if (!validarPlacaCarro(vehiculo.placa)) {
                        cout << "Placa inválida. Debe tener 3 letras seguidas de 3 números.\n";
                    }
                } while (!validarPlacaCarro(vehiculo.placa)); // Repetir hasta que la placa sea válida
            } else if (vehiculo.tipoVehiculo == "moto") {
                do {
                    cout << "Ingrese la placa de la moto (formato ABC12D): ";
                    cin >> vehiculo.placa;
                    if (!validarPlacaMoto(vehiculo.placa)) {
                        cout << "Placa inválida. Debe tener 3 letras, seguidas de 2 números y 1 letra.\n";
                    }
                } while (!validarPlacaMoto(vehiculo.placa)); // Repetir hasta que la placa sea válida
            } else {
                cout << "Tipo de vehículo no válido.\n";
                continue; // Volver al menú principal si el tipo de vehículo no es válido
            }

            cout << "Ingrese la hora de entrada (formato HH:MM AM/PM): ";
            cin >> vehiculo.horaEntrada;
            cout << "Ingrese el nombre del propietario: ";
            cin >> propietario.nombre; // Cambiado a cin

            do {
                cout << "Ingrese la cédula del propietario (solo números, entre 8 y 10 dígitos): ";
                cin >> propietario.cedula; // Cambiado a cin
                if (!validarCedula(propietario.cedula)) {
                    cout << "Cédula inválida. Asegúrese de que solo contenga números y tenga entre 8 y 10 dígitos.\n";
                }
            } while (!validarCedula(propietario.cedula));

            cout << "Ingrese el correo electrónico del propietario: ";
            cin >> propietario.correo; // Cambiado a cin
            cout << "Ingrese el color del vehículo: ";
            cin >> vehiculo.color; // Cambiado a cin

            bool puestoEncontrado = false;
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (!parqueadero[i].ocupado) {
                    parqueadero[i].ocupado = true;
                    parqueadero[i].vehiculo = vehiculo;
                    parqueadero[i].propietario = propietario;
                    cout << "Vehículo con placa " << vehiculo.placa << " ha sido ingresado en el puesto "
                         << parqueadero[i].numero << ".\n";
                    cout << "Propietario: " << propietario.nombre << " (Cédula: " << propietario.cedula << ")\n";
                    puestoEncontrado = true;
                    break;
                }
            }

            if (!puestoEncontrado) {
                cout << "No hay puestos disponibles." << endl;
            }

        } else if (opcion == '2') {
            string placa, horaSalida;
            cout << "Ingrese la placa del vehículo a dar salida: ";
            cin >> placa;
            cout << "Ingrese la hora de salida (formato HH:MM AM/PM): ";
            cin >> horaSalida;

            bool carroEncontrado = false;
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (parqueadero[i].ocupado && parqueadero[i].vehiculo.placa == placa) {
                    parqueadero[i].vehiculo.horaSalida = horaSalida;

                    int minutosEntrada = convertirHoraEnMinutos(parqueadero[i].vehiculo.horaEntrada);
                    int minutosSalida = convertirHoraEnMinutos(horaSalida);
                    
                    int duracion = minutosSalida - minutosEntrada;
                    int horas = duracion / 60;
                    int minutos = duracion % 60;

                    parqueadero[i].ocupado = false;

                    cout << "Vehículo con placa " << parqueadero[i].vehiculo.placa << " ha salido del puesto "
                         << parqueadero[i].numero << "." << endl;
                    cout << "Hora de entrada: " << parqueadero[i].vehiculo.horaEntrada << endl;
                    cout << "Hora de salida: " << horaSalida << endl;
                    cout << "Tiempo total en el parqueadero: " << horas << " horas y " << minutos << " minutos.\n";
                    cout << "Total a pagar: $" << (horas + (minutos > 0 ? 1 : 0)) * tarifaPorHora << endl; // Cobrando por hora completa

                    carroEncontrado = true;
                    break;
                }
            }

            if (!carroEncontrado) {
                cout << "No se encontró un vehículo con esa placa." << endl;
            }

        } else if (opcion == '3') {
            int disponibles = 0;
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (!parqueadero[i].ocupado) {
                    disponibles++;
                }
            }
            cout << "Hay " << disponibles << " puestos disponibles." << endl;

        } else if (opcion == '4') {
            cout << "Ingrese la nueva tarifa por hora: ";
            cin >> tarifaPorHora;
            cout << "La nueva tarifa por hora es: $" << tarifaPorHora << endl;

        } else if (opcion == '5') {
            cout << "Vehículos ingresados:\n";
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (parqueadero[i].ocupado) {
                    cout << "Puesto " << parqueadero[i].numero << ": " << parqueadero[i].vehiculo.placa
                         << " (Propietario: " << parqueadero[i].propietario.nombre << ")\n";
                }
            }
        }

    } while (opcion != '6');

    return 0;
}
