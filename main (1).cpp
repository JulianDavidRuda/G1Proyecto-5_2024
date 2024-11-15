

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
        cout << "5. Consultar el porcentaje de disponibilidad\n"; // Nueva opción
        cout << "6. Consultar vehículos ingresados\n";
        cout << "7. Consultar ingresos totales\n";
        cout << "8. Salir\n";
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
              
                   bool fechaValida = false;
do{
    cout << "Ingrese la fecha de entrada (formato DD/MM/AAAA): ";
                cin >> vehiculo.fechaEntrada;
    // Verificar que el formato sea DD/MM/AAAA con separadores en las posiciones 2 y 5
    if (vehiculo.fechaEntrada[2] == '/' && vehiculo.fechaEntrada[5] == '/' &&
        vehiculo.fechaEntrada[0] >= '0' && vehiculo.fechaEntrada[0] <= '9' &&
        vehiculo.fechaEntrada[1] >= '0' && vehiculo.fechaEntrada[1] <= '9' &&
        vehiculo.fechaEntrada[3] >= '0' && vehiculo.fechaEntrada[3] <= '9' &&
        vehiculo.fechaEntrada[4] >= '0' && vehiculo.fechaEntrada[4] <= '9' &&
        vehiculo.fechaEntrada[6] >= '0' && vehiculo.fechaEntrada[6] <= '9' &&
        vehiculo.fechaEntrada[7] >= '0' && vehiculo.fechaEntrada[7] <= '9' &&
        vehiculo.fechaEntrada[8] >= '0' && vehiculo.fechaEntrada[8] <= '9' &&
        vehiculo.fechaEntrada[9] >= '0' && vehiculo.fechaEntrada[9] <= '9') {

        // Convertir día, mes y año a enteros
        int dia = (vehiculo.fechaEntrada[0] - '0') * 10 + (vehiculo.fechaEntrada[1] - '0');
        int mes = (vehiculo.fechaEntrada[3] - '0') * 10 + (vehiculo.fechaEntrada[4] - '0');
        int anio = (vehiculo.fechaEntrada[6] - '0') * 1000 + (vehiculo.fechaEntrada[7] - '0') * 100 +
                   (vehiculo.fechaEntrada[8] - '0') * 10 + (vehiculo.fechaEntrada[9] - '0');

        // Validar rango de año, mes y día
        if (anio == 2024) {
            if (mes >= 1 && mes <= 12) {
                // Días máximos por mes
                int diasMaximos = 31;
                if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                    diasMaximos = 30;
                } else if (mes == 2) {
                    // Febrero, considerar años bisiestos
                    diasMaximos = 29; // 2024 es bisiesto
                }

                if (dia >= 1 && dia <= diasMaximos) {
                    fechaValida = true;
                } else {
                    cout << "Día inválido para el mes especificado. Máximo: " << diasMaximos << " días.\n";
                }
            } else {
                cout << "Mes inválido. Debe estar entre 1 y 12.\n";
            }
        } else {
            cout << "Año inválido. Debe ser 2024.\n";
        }
    } else {
        cout << "Formato de fecha inválido. Use el formato DD/MM/AAAA.\n";
    }

    if (fechaValida) {
        cout << "Fecha válida: " << vehiculo.fechaEntrada << endl;
    } else {
        cout << "Fecha no válida.\n";
    }

}while(!fechaValida);

                
                      bool horaValida = false;
    do{            
      cout << "Ingrese la hora de entrada (formato HH:MM AM/PM): ";
                cin >> vehiculo.horaEntrada;      

    // Validar el formato HH:MM (5 caracteres y un '\0' al final)
    if (vehiculo.horaEntrada[2] == ':' &&
        vehiculo.horaEntrada[0] >= '0' && vehiculo.horaEntrada[0] <= '2' && // Primer dígito de la hora (0-2)
        vehiculo.horaEntrada[1] >= '0' && vehiculo.horaEntrada[1] <= '9' && // Segundo dígito de la hora (0-9)
        vehiculo.horaEntrada[3] >= '0' && vehiculo.horaEntrada[3] <= '5' && // Primer dígito de los minutos (0-5)
        vehiculo.horaEntrada[4] >= '0' && vehiculo.horaEntrada[4] <= '9' && // Segundo dígito de los minutos (0-9)
        vehiculo.horaEntrada[5] == '\0') { // Verificar que no haya caracteres extra

        // Convertir horas y minutos a enteros
        int horas = (vehiculo.horaEntrada[0] - '0') * 10 + (vehiculo.horaEntrada[1] - '0');
        int minutos = (vehiculo.horaEntrada[3] - '0') * 10 + (vehiculo.horaEntrada[4] - '0');

        // Validar rango de horas y minutos
        if (horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59) {
            // Restricción del parqueadero: 6:00 a 21:00
            if ((horas > 6 || (horas == 6 && minutos >= 0)) && 
                (horas < 21 || (horas == 21 && minutos == 0))) {
                horaValida = true;
            } else {
                cout << "Horario fuera de servicio. El parqueadero opera de 06:00 a 21:00.\n";
            }
        } else {
            cout << "Hora inválida. Debe estar entre 00:00 y 23:59.\n";
        }
    } else {
        cout << "Formato de hora inválido. Use el formato HH:MM.\n";
    }

    if (horaValida) {
        cout << "Hora válida: " << vehiculo.horaEntrada << endl;
    } else {
        cout << "Hora no válida.\n";
    }

    }while(!horaValida);

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

        } else if (opcion == '5') {  // Nueva lógica para consultar porcentaje de disponibilidad
            int disponibles = 0;
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (!parqueadero[i].ocupado) {
                    disponibles++;
                }
            }
            int ocupados = TOTAL_PUESTOS - disponibles;
            int porcentajeDisponibles = (double)disponibles / TOTAL_PUESTOS * 100;
            int porcentajeOcupados = (double)ocupados / TOTAL_PUESTOS * 100;

            cout << "Hay " << disponibles << " puestos disponibles (" << porcentajeDisponibles << "%)\n";
            cout << "Hay " << ocupados << " puestos ocupados (" << porcentajeOcupados << "%)\n";

        } else if (opcion == '6') {
            for (int i = 0; i < TOTAL_PUESTOS; i++) {
                if (parqueadero[i].ocupado) {
                    cout << "Puesto " << parqueadero[i].numero << ": "
                         << parqueadero[i].vehiculo.tipoVehiculo << " con placa "
                         << parqueadero[i].vehiculo.placa << endl;
                }
            }

        } else if (opcion == '7') {
            cout << "Los ingresos totales del parqueadero son: $" << ingresosTotales << endl;

        }

    } while (opcion != '8');

    return 0;
}

