/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

const int TOTAL_PUESTOS = 40; 
double tarifaPorHora = 5.0;   
double ingresosTotales = 0.0; 


struct Propietario {
    string nombre;
    int cedula;
    int telefono;
    string correo;
};


struct Vehiculo {
    string placa;
    string tipoVehiculo;
    string color;
    string fechaEntrada; 
    string horaEntrada;
    string horaSalida;
};


struct Puesto {
    int numero;
    bool ocupado = false;
    Propietario propietario;
    Vehiculo vehiculo;
};

int main() {
    Propietario propietario;
    Vehiculo vehiculo;
  
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
        cout << "6. Consultar ingresos totales\n";
        cout << "7. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == '1') {
            Vehiculo vehiculo;
            Propietario propietario;

            cout << "Ingrese el tipo de vehículo (carro/moto): ";
            cin >> vehiculo.tipoVehiculo;

            if (vehiculo.tipoVehiculo == "carro") {
                bool formato_valido = false;
                while (!formato_valido) {
                    cout << "Ingrese la placa del carro (formato ABC123): ";
                    cin >> vehiculo.placa;

                    if (
                        ((vehiculo.placa[0] >= 'A' && vehiculo.placa[0] <= 'Z')) &&
                        ((vehiculo.placa[1] >= 'A' && vehiculo.placa[1] <= 'Z')) &&
                        ((vehiculo.placa[2] >= 'A' && vehiculo.placa[2] <= 'Z')) &&
                        (vehiculo.placa[3] >= '0' && vehiculo.placa[3] <= '9') &&
                        (vehiculo.placa[4] >= '0' && vehiculo.placa[4] <= '9') &&
                        (vehiculo.placa[5] >= '0' && vehiculo.placa[5] <= '9')) {
                        formato_valido = true;
                    } else {
                        cout << "Placa inválida. Debe tener 3 letras seguidas de 3 números.\n";
                    }
                }
            } else if (vehiculo.tipoVehiculo == "moto") {
                bool formato_valido = false;
                while (!formato_valido) {
                    cout << "Ingrese la placa de la moto (formato ABC12D): ";
                    cin >> vehiculo.placa;

                    if (
                        ((vehiculo.placa[0] >= 'A' && vehiculo.placa[0] <= 'Z')) &&
                        ((vehiculo.placa[1] >= 'A' && vehiculo.placa[1] <= 'Z')) &&
                        ((vehiculo.placa[2] >= 'A' && vehiculo.placa[2] <= 'Z')) &&
                        (vehiculo.placa[3] >= '0' && vehiculo.placa[3] <= '9') &&
                        (vehiculo.placa[4] >= '0' && vehiculo.placa[4] <= '9') &&
                        ((vehiculo.placa[5] >= 'A' && vehiculo.placa[5] <= 'Z'))) {
                        formato_valido = true;
                    } else {
                        cout << "Placa inválida. Debe tener 3 letras, seguidas de 2 números y 1 letra.\n";
                    }
                }
            } else {
                cout << "Tipo de vehículo no válido.\n";
            }

            if (vehiculo.tipoVehiculo == "carro" || vehiculo.tipoVehiculo == "moto") {
                cout << "Ingrese la fecha de entrada (formato DD/MM/AAAA): ";
                cin >> vehiculo.fechaEntrada;
                cout << "Ingrese la hora de entrada (formato HH:MM AM/PM): ";
                cin >> vehiculo.horaEntrada;
                cout << "Ingrese el nombre del propietario: ";
                cin >> propietario.nombre;

                do {
                    cout << "Ingrese la cédula del propietario (solo números, entre 8 y 10 dígitos): ";
                    cin >> propietario.cedula;
                } while (propietario.cedula < 10000000 || propietario.cedula > 9999999999);

                do {
                    cout << "Ingrese el teléfono del propietario (10 dígitos): ";
                    cin >> propietario.telefono;
                } while (propietario.telefono < 1000000000 || propietario.telefono > 9999999999);

                cout << "Ingrese el correo electrónico del propietario: ";
                cin >> propietario.correo;
                cout << "Ingrese el color del vehículo: ";
                cin >> vehiculo.color;

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
            }
        } else if (opcion == '2') {
            string placa, horaSalida;
            int dias;
            cout << "Ingrese la placa del vehículo a dar salida: ";
            cin >> placa;
            cout << "Ingrese la cantidad de días que el vehículo estuvo en el parqueadero: ";
            cin >> dias;
            cout << "Ingrese la hora de salida (formato HH:MM AM/PM): ";
            cin >> horaSalida;

            bool carroEncontrado = false;
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (parqueadero[i].ocupado && parqueadero[i].vehiculo.placa == placa) {
                    parqueadero[i].vehiculo.horaSalida = horaSalida;
                    parqueadero[i].ocupado = false;

                    // Calculo del total de horas adicionales
                    int horasExtras = 0, minutosExtras = 0; 
                    // Aquí deberíamos convertir horaEntrada y horaSalida a minutos y calcular el tiempo adicional.
                    // Agregue la lógica de conversión de horas a minutos para hacer la comparación y calcular horasExtras y minutosExtras.

                    double totalPagar = (dias * 24 + horasExtras + (minutosExtras > 0 ? 1 : 0)) * tarifaPorHora;
                    ingresosTotales += totalPagar;

                    cout << "Vehículo con placa " << parqueadero[i].vehiculo.placa << " ha salido del puesto "
                         << parqueadero[i].numero << "." << endl;
                    cout << "Fecha de entrada: " << parqueadero[i].vehiculo.fechaEntrada << endl;
                    cout << "Hora de entrada: " << parqueadero[i].vehiculo.horaEntrada << endl;
                    cout << "Hora de salida: " << horaSalida << endl;
                    cout << "Tiempo total en el parqueadero: " << dias << " días, " 
                         << horasExtras << " horas y " << minutosExtras << " minutos.\n";
                    cout << "Total a pagar: $" << totalPagar << endl;
                    carroEncontrado = true;
                    break;
                }
            }

            if (!carroEncontrado) {
                cout << "No se encontró un vehículo con esa placa.\n";
            }

        } else if (opcion == '3') {
            int puestosDisponibles = 0;
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (!parqueadero[i].ocupado) {
                    puestosDisponibles++;
                }
            }
            cout << "Hay " << puestosDisponibles << " puestos disponibles en el parqueadero.\n";

        } else if (opcion == '4') {
            cout << "Ingrese la nueva tarifa por hora: ";
            cin >> tarifaPorHora;
            cout << "La tarifa por hora ha sido actualizada a $" << tarifaPorHora << endl;

        } else if (opcion == '5') {
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (parqueadero[i].ocupado) {
                    cout << "Puesto " << parqueadero[i].numero << ": "
                         << parqueadero[i].vehiculo.tipoVehiculo << " con placa "
                         << parqueadero[i].vehiculo.placa << endl;
                }
            }

        } else if (opcion == '6') {
            cout << "Los ingresos totales del parqueadero son: $" << ingresosTotales << endl;

        }

    } while (opcion != '7');

    return 0;
}
