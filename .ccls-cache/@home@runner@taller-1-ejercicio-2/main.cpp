/*
autor: edwin sebastian pardo salamanca
problema: se necesita capturar los datos mde los clientes para ser impreso en un
fichero.

1. crear la estructura de datos
2. hacer un menu para llenar los datos del cliente y para imprimir el fichero
3. se crea la funcion para llenar los datos.
4. se crea la funcion de imprimir fichero, se hace usando ofstream
5. se ponen las funciones en el menu.
*/

#include <fstream>
#include <iostream> //se usa esta bibliotecaria para archivos

using namespace std;

struct datos { // creo la estructura de datos, se almacena la informacion del
               // cliente en un array
  string nombre[10];
  int edad[10];
  int cedula[10];
};
datos usuario;
void llenar_dato(int n); // declaro las funciones
void imprimir(int n);

int main() { // funcion principal

  int opcion,
      n; // creo la variable opcion pára saber que desea es usuario y la
         // variable n para saber la cantidad de clientes que desea ingresar.

  do { // se crea un bucle porque no se sabe cuantas veces va a ingresar un
       // usuario.
    cout << "1. desea llenar los datos del cliente"
         << endl; // estas son las opciones que tiene el usuario.
    cout << "2. imprimir datos de cliente" << endl;
    cout << "3. salir" << endl;
    cout << "digite opcion: ";
    cin >> opcion;
    cout << endl;
    switch (opcion) { // se crea el menu
    case 1:
      cout << "cuantos clientes va a ingresar ";
      cin >> n;
      cout << endl;
      llenar_dato(n); // se llama la funcion
      break;

    case 2:

      imprimir(n); // se llama la funcion.

      break;

    default:
      cout << "esta opcion no existe"
           << endl; // esta opcion existe en el caso que el cliente digite una
                    // opcion que no existe.
      break;
    }

  } while (opcion != 3); // el bucle se hace hasta que escoja la opcion  3, esta
                         // opcion significa el que termino el programa.
  return 0;
}

void llenar_dato(int n) { // creo la funcion para llenar los datos

  for (int i = 0; i < n;
       i++) { // un for para llenar el array con los datos de cada cliente.

    // lleno los datos.
    cout << "digite nombre: ";
    cin >> usuario.nombre[i];
    cout << endl;
    cout << "digite edad: ";
    cin >> usuario.edad[i];
    cout << endl;
    cout << "digite cedula: ";
    cin >> usuario.cedula[i];
    cout << endl;
  }
}

void imprimir(
    int n) { // se crea la funcion para imprimir la informacion en un fichero.

  int *puntero_edad, *puntero_cedula; // se crea un apuntador para cada
                                      // variable.
  string *puntero_nombre;
  ofstream fichero; // se crea el archivo.
  for (int i = 0; i < n; i++) {

    // la dirrecion nos ayuda a saber donde apuntar y encontrar el dato que
    // necesitamos.
    puntero_edad = &usuario.edad[i];
    puntero_nombre = &usuario.nombre[i];
    puntero_cedula = &usuario.cedula[i];

    fichero.open(
        "archivo_fichero.txt",
        ios::app); // se abre el archivo con el nombre de archivo_fichero.txt,
                   // el ios::app es para no borrar el contenido que ya existia.

    // se imprimen los datos en el archivo
    fichero << "nombre: " << *puntero_nombre << endl;
    fichero << "edad: " << *puntero_edad << endl;
    fichero << "cedula: " << *puntero_cedula << endl;
    fichero << endl;
  }
  fichero.close(); // se cierra el archivo.
}