#include <iostream>
#include <ctime>   // Para time
#include <cstdlib> // Para rand y srand
using namespace std;



// Función para mostrar el puntaje máximo y el nombre del jugador con el puntaje máximo
void PuntajeMaximo(string jugadorMaxPuntaje, int puntajeMaximo)
{
    system("cls"); // Limpiar la pantalla
    cout << endl;
    cout << "MAXIMO PUNTAJE" << endl;
    cout << "Jugador: " << jugadorMaxPuntaje << endl;
    cout << "Puntaje: " << puntajeMaximo << endl;
    cout << endl;
    cout << endl;
    system("pause"); // Pausa la ejecución hasta que el usuario presione una tecla
    system("cls"); // Limpiar la pantalla nuevamente
}



// Función para actualizar el puntaje máximo si el puntaje actual es mayor
void ActualizarPuntajeMaximo(string nombre, string &jugadorMaxPuntaje, int puntaje, int &puntajeMaximo)
{
    if(puntaje > puntajeMaximo)
    {
        puntajeMaximo = puntaje; // Actualiza el puntaje máximo
        jugadorMaxPuntaje = nombre; // Actualiza el nombre del jugador con el puntaje máximo
    }
}



// Función para el modo simulado donde el usuario ingresa manualmente los valores de los dados
void ModoSimulado(int (&vec)[6])
{
    int valor;

    for(int i=0 ; i<6 ; i++)
    {
        cout << "Ingrese el dado " << i+1 << ": ";
        cin >> valor;

        if(valor < 1 || valor > 6)
        {
            cout << "El valor tiene que estar entre 1 y 6" << endl;
            i = i-1; // Repite la entrada si el valor no está entre 1 y 6
        }
        else
        {
            vec[i] = valor; // Guarda el valor en el vector
        }
    }
}


// Función para sumar los valores de un vector de 6 enteros
int SumarVectorDados(int vec[])
{
    int suma=0;
    for(int i=0; i<6 ; i++)
    {
        suma+= vec[i]; // Suma los valores del vector
    }

    return suma; // Retorna la suma total
}


// Función para verificar combinaciones y actualizar puntajes
int Combinaciones(int suma, int &sumaMaxima, int &puntajeTotal, int &puntajeTotalP2, int &lanza, int &lanzaP2, int vec[6], bool turno, bool &bdEscalera, int cantUno, int cantDos, int cantTres, int cantCuatro, int cantCinco, int cantSeis)
{
    // Verifica si hay un sexteto de 6
    if(cantSeis == 6)
    {
        cout << endl;
        cout << "SEXTETO 6" << endl;
        cout << "Resetea el puntaje total a 0" << endl;
        sumaMaxima = 0;
        suma = 0;
        if(turno == true)
        {
            puntajeTotal = 0;
            lanza = 3; // Resetea los lanzamientos
        }
        else
        {
            puntajeTotalP2 = 0;
            lanzaP2 = 3; // Resetea los lanzamientos
        }
        return suma; // Retorna la suma que ahora es 0
    }
    // Verifica si hay una escalera
    else if(cantUno == 1 && cantDos == 1 && cantTres == 1 && cantCuatro == 1 && cantCinco == 1 && cantSeis == 1)
    {
        cout << endl;
        cout << "ESCALERA! GANASTE LA PARTIDA!" << endl;
        bdEscalera = true;
        suma = 0;

        return suma; // Retorna la suma que ahora es 0
    }





















      // Verifica si hay un sexteto de 1 a 5
      else if(cantUno == 6 || cantDos == 6 || cantTres == 6 || cantCuatro == 6 || cantCinco == 6)
    {
        // Suma de los dados
        suma = SumarVectorDados(vec);
        cout << endl;
        cout << "SEXTETO " << suma/6 << " ";
        suma = (suma/6)*10; // Calcula los puntos del sexteto
        cout << "puntos: " << suma;
        return suma;
    }
    // Si no se cumple ninguna de las condiciones anteriores, suma los dados
   else
    {
        suma = SumarVectorDados(vec);
        cout << endl;
        cout << "SUMA DE DADOS: " << suma << " puntos" << endl;
        return suma; // Retorna la suma total
    }
}

// Función para mostrar un mensaje con la información de la ronda actual
void CartelRonda(int ronda, int puntaje, string nombre)
{
    cout << "          -------------------------------------------------------------------------------------" << endl;
    cout << "                                            RONDA NRO " << ronda << "                                  " << endl;
    cout << "                                            JUGADOR: " << nombre << "                        " << endl;
    cout << "                                            PUNTAJE: " << puntaje << " PUNTOS" << "       " << endl;
    cout << "          -------------------------------------------------------------------------------------" << endl;
    cout << endl;
    system("pause"); // Pausa la ejecución hasta que el usuario presione una tecla
    system("cls"); // Limpia la pantalla
}



// Función para mostrar un mensaje con la información de la ronda y los puntajes de dos jugadores
void CartelRonda2J(int ronda, int puntajeTotal, int puntajeTotalP2, bool turno, string nombreJ1, string nombreJ2)
{
     string nombre;

     if(turno)
     {
        nombre = nombreJ1; // Determina el nombre del jugador del próximo turno
     }
     else
     {
        nombre = nombreJ2; // Determina el nombre del jugador del próximo turno
     }
     cout << "          -------------------------------------------------------------------------------------" << endl;
     cout << "                                            RONDA NRO " << ronda << "                                  " << endl;
     cout << "                                            PROXIMO TURNO: " << nombre << "                        " << endl;
     cout << "                                            PUNTAJE " << nombreJ1 << " : " << puntajeTotal << " PUNTOS" << endl;
     cout << "                                            PUNTAJE " << nombreJ2 << " : " << puntajeTotalP2 << " PUNTOS" << endl;
     cout << "          -------------------------------------------------------------------------------------" << endl;
     cout << endl;
     system("pause"); // Pausa la ejecución hasta que el usuario presione una tecla
     system("cls"); // Limpia la pantalla
}


// Función para mostrar información detallada del turno actual
void InfoPartida(string nombre, int ronda, int puntajeTotal, int sumaMaxima, int lanzamiento)
{
    cout << "TURNO DE " << nombre << " | RONDA NRO " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << sumaMaxima << endl;
    cout << "LANZAMIENTO NRO " << lanzamiento << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
}


// Función para cargar valores aleatorios (1 a 6) en un vector de 6 elementos
void CargarDadosAleatorio(int (&vec)[6])
{
    srand(time(NULL)); // Inicializa la semilla para los números aleatorios
    for(int i=0 ; i<6 ; i++)
    {
        vec[i] = (rand()%6)+1; // Asigna un valor aleatorio entre 1 y 6 a cada elemento del vector
    }
}



// Función para mostrar los valores del vector de dados
void MostrarVectorDados(int vec[])
{
    cout << endl;
    cout << "Dados: ";
    for (int i = 0; i < 6; i++)
    {
        cout << vec[i] << " "; // Muestra cada valor del vector
    }
}




















// Función para contar cuántas veces un número específico aparece en el vector de dados
int ContarNumerosRepetidos(int vec[], int numero){
    int cant = 0;
    for(int i=0 ; i<6 ; i++)
    {
        if(vec[i] == numero)
            cant++; // Incrementa el contador si el número aparece en el vector
    }
    return cant;
}


// Función para gestionar el juego de un solo jugador
void Juego1J(string &nombreJ1, int &ronda, int &puntajeTotal, int &puntajeTotalP2, int &lanzamiento, int &lanzamientoP2, int &suma, int &sumaMaxima, bool &bdEscalera, bool &bdTurno)
{
    int cantUno = 0, cantDos = 0, cantTres = 0, cantCuatro = 0, cantCinco = 0, cantSeis = 0;
    int vectorDados[6];

    lanzamiento++; // Incrementa el número de lanzamientos


    // Muestra la información del turno actual
    InfoPartida(nombreJ1, ronda, puntajeTotal, sumaMaxima, lanzamiento);
    system("pause");


    // Carga de dados aleatoria
    CargarDadosAleatorio(vectorDados);


    // Carga de dados manual (modo simulado)
    //ModoSimulado(vectorDados);



    // Muestra los dados
    MostrarVectorDados(vectorDados);



    // Cuenta la cantidad de cada número en los dados
    cantUno = ContarNumerosRepetidos(vectorDados, 1);
    cantDos = ContarNumerosRepetidos(vectorDados, 2);
    cantTres = ContarNumerosRepetidos(vectorDados, 3);
    cantCuatro = ContarNumerosRepetidos(vectorDados, 4);
    cantCinco = ContarNumerosRepetidos(vectorDados, 5);
    cantSeis = ContarNumerosRepetidos(vectorDados, 6);



    // Calcula el puntaje según las combinaciones posibles
    suma = Combinaciones(suma, sumaMaxima, puntajeTotal, puntajeTotalP2, lanzamiento, lanzamientoP2, vectorDados, bdTurno, bdEscalera, cantUno, cantDos, cantTres, cantCuatro, cantCinco, cantSeis);


     // Actualiza la suma más alta para el máximo puntaje de la ronda
    if(suma > sumaMaxima)
    {
        sumaMaxima = suma;
    }


    cout << endl;
    system("pause");
    system("cls");



    // Cambio de ronda y cartel entre rondas
    if(lanzamiento == 3 && bdEscalera == false)
    {
        InfoPartida(nombreJ1, ronda, puntajeTotal, sumaMaxima, lanzamiento);
        cout << "FIN DE LA RONDA " << ronda << endl;
        system("pause");
        system("cls");

        puntajeTotal += sumaMaxima;

        // Incrementa la ronda y muestra el cartel si aún no se ha ganado
        if(puntajeTotal < 100 && bdEscalera == false)
        {
            ronda++;
            CartelRonda(ronda, puntajeTotal, nombreJ1);
        }
            lanzamiento = 0;
            sumaMaxima = 0;
    }




 // Reinicio de variables al final del lanzamiento
    cantUno = 0, cantDos = 0, cantTres = 0, cantCuatro = 0, cantCinco = 0, cantSeis = 0;
    suma = 0;
}



// Función para gestionar el juego de dos jugadores
void Juego2J(string &nombreJ1, string &nombreJ2, int &ronda, int &rondaMaxima, int &puntajeTotal, int &puntajeTotalP2, int &puntajeAuxiliar, int &lanzamiento, int &lanzamientoP2, int &lanzaAuxiliar1, int &lanzaAuxiliar2, int &suma, int &sumaMaxima, bool &bdEscalera, bool &bdTurno)
{
    int cantUno = 0, cantDos = 0, cantTres = 0, cantCuatro = 0, cantCinco = 0, cantSeis = 0;
    int vectorDados[6];

    // Muestra la información del turno actual depende del jugador
    if(bdTurno)
    {
        lanzamiento++;
        InfoPartida(nombreJ1, ronda, puntajeTotal, sumaMaxima, lanzamiento);
    }
    else
    {
        lanzamientoP2++;
        InfoPartida(nombreJ2, ronda, puntajeTotalP2, sumaMaxima, lanzamientoP2);
    }
    system("pause");


    // Carga de dados aleatoria
    //CargarDadosAleatorio(vectorDados);



    // Carga de dados manual (modo simulado)
    ModoSimulado(vectorDados);


    // Muestra los dados
    MostrarVectorDados(vectorDados);


    // Cuenta la cantidad de cada número en los dados
    cantUno = ContarNumerosRepetidos(vectorDados, 1);
    cantDos = ContarNumerosRepetidos(vectorDados, 2);
    cantTres = ContarNumerosRepetidos(vectorDados, 3);
    cantCuatro = ContarNumerosRepetidos(vectorDados, 4);
    cantCinco = ContarNumerosRepetidos(vectorDados, 5);
    cantSeis = ContarNumerosRepetidos(vectorDados, 6);


    // Calcula el puntaje según las combinaciones posibles
    suma = Combinaciones(suma, sumaMaxima, puntajeTotal, puntajeTotalP2, lanzamiento, lanzamientoP2, vectorDados, bdTurno, bdEscalera, cantUno, cantDos, cantTres, cantCuatro, cantCinco, cantSeis);


















  // Actualiza la suma más alta para el máximo puntaje de la ronda
    if(suma > sumaMaxima)
    {
        sumaMaxima = suma;

        // Guarda los lanzamientos en la tirada máxima para desempatar
        if(bdTurno == true)
            lanzaAuxiliar1 = lanzamiento;

        if(bdTurno == false)
            lanzaAuxiliar2 = lanzamientoP2;
    }

    cout << endl;
    system("pause");
    system("cls");

    // Cambio de turno de P1 a P2, continúa la ronda y muestra el cartel entre jugadores
    if(lanzamiento == 3 && bdEscalera == false)
    {
        if(bdTurno)
            bdTurno = false;

        InfoPartida(nombreJ1, ronda, puntajeTotal, sumaMaxima, lanzamiento);
        cout << "SIGUE LA RONDA " << ronda << endl;
        system("pause");
        system("cls");

        puntajeTotal += sumaMaxima;
        lanzamiento = 0;
        sumaMaxima = 0;

        CartelRonda2J(ronda, puntajeTotal, puntajeTotalP2, bdTurno, nombreJ1, nombreJ2);

        // Validación, si J1 llega a 100 antes que permita terminar la ronda a J2
        if(puntajeTotal >= 100)
        {
            puntajeAuxiliar = puntajeTotal;
            puntajeTotal = 99;
        }

    }

    // Cambio de turno de P2 a P1, suma ronda y muestra el cartel entre rondas
    if(lanzamientoP2 == 3 && bdEscalera == false)
    {
        if(!bdTurno)
            bdTurno = true;

        InfoPartida(nombreJ2, ronda, puntajeTotalP2, sumaMaxima, lanzamientoP2);
        cout << "FIN DE LA RONDA " << ronda << endl;
        system("pause");
        system("cls");

        ronda++;
        puntajeTotalP2 += sumaMaxima;
        lanzamientoP2 = 0;
        sumaMaxima = 0;

        // Validación, si J1 llega a 100 antes que permita terminar la ronda a J2
        if(puntajeAuxiliar >= 100)
            puntajeTotal = puntajeAuxiliar;

        CartelRonda2J(ronda, puntajeTotal, puntajeTotalP2, bdTurno, nombreJ1, nombreJ2);

    }

    // Reiniciar variables al final del lanzamiento
    cantUno = 0, cantDos = 0, cantTres = 0, cantCinco = 0, cantCinco = 0, cantSeis = 0;
    suma = 0;

}













int MenuPrincipal()
{
    // Declaración de variables
    int opcion, ronda = 1, puntajeTotal = 0, lanzamiento = 0, suma = 0, sumaMaxima = 0, puntajeMaximo = 0;
    bool bdEscalera = false; // Bandera para verificar si se obtiene una escalera
    string jugadorMaxPuntaje = "N/A"; // Jugador con la puntuación más alta
    string nombreJ1, nombreJ2; // Nombres de los jugadores

    // Variables para el modo de dos jugadores
    int puntajeTotalP2 = 0, lanzamientoP2 = 0, puntajeAuxiliar = 0;
    int lanzaAuxiliar1 = 0, lanzaAuxiliar2 = 0;
    bool bdTurno = true; // Verdadero para un jugador, falso para dos jugadores

    // Variables para el juego personalizado
    bool juegoPersonalizado, bdJuego = true;
    int opcionJuego, rondaMaxima;

    // Bucle infinito para mostrar el menú principal
    while(true)
    {
        // Estructura del menú principal
        cout << "* MENU PRINCIPAL ESCALERA *" << endl;
        cout << endl;
        cout << "1. Juego nuevo para un jugador" << endl;
        cout << "2. Juego nuevo para dos jugadores" << endl;
        cout << "3. Mostrar puntuacion mas alta" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

switch(opcion)
        {
            case 1: // Modo un jugador
                system("cls");
                cout << "* MODO: UN JUGADOR *" << endl;
                cout << endl;
                cout << "Por favor, ingrese su nombre: ";

                // Usamos getline para que acepte nombres con espacios
                cin.ignore(); // Ignorar el carácter de nueva línea previo
                getline(cin, nombreJ1); // Leer el nombre del jugador
                system("cls");

                // Mostrar cartel de la ronda
                CartelRonda(ronda, puntajeTotal, nombreJ1);

                // Comienza el juego
                while(puntajeTotal < 100 && bdEscalera == false)
                {
                    // Función Jugar 1J
                    Juego1J(nombreJ1, ronda, puntajeTotal, puntajeTotalP2, lanzamiento, lanzamientoP2, suma, sumaMaxima, bdEscalera, bdTurno);
                }


                // Cartel de ganador por puntos
                if(puntajeTotal >= 100 && bdEscalera == false)
                {
                    system("cls");
                    cout << endl;
                    cout << "GANASTE " << nombreJ1 << "!" << endl;
                    cout << "CANTIDAD DE RONDAS: " << ronda << endl;
                    cout << "PUNTAJE: " << puntajeTotal << endl;

                    // Actualiza el puntaje máximo
                    ActualizarPuntajeMaximo(nombreJ1, jugadorMaxPuntaje, puntajeTotal, puntajeMaximo);

                    system("pause");
                    system("cls");
                }




                // Reinicio de bandera y variables
                bdEscalera = false;
                ronda = 1, lanzamiento = 0, puntajeTotal = 0, suma = 0, sumaMaxima = 0;
            break;

            case 2: // Modo dos jugadores
                system("cls");
                cout << "* MODO: DOS JUGADORES *" << endl;
                cout << endl;
                cout << "Ingrese el nombre del jugador 1: ";
                cin.ignore();
                getline(cin, nombreJ1);
                cout << endl;
                cout << "Ingrese el nombre del jugador 2: ";
                getline(cin, nombreJ2);
                system("cls");

                // Elegir juego normal o personalizado
                cout << "1. Juego normal" << endl;
                cout << "2. Juego personalizado" << endl;
                cin >> opcionJuego;















              // Validación para elegir opción correcta
                while(bdJuego)
                {
                    if(opcionJuego == 1)
                    {
                        juegoPersonalizado = false;
                        bdJuego = false;
                    }
                    else if(opcionJuego == 2)
                    {
                        juegoPersonalizado = true;
                        bdJuego = false;
                    }
                    else
                    {
                        cout << "Ingrese una opcion correcta" << endl;
                        cin >> opcionJuego;
                    }
                }
                system("cls");



        // Validación para elegir 1 ronda máxima o más
                if(juegoPersonalizado)
                {
                    cout << "Cantidad de rondas maximas (1 o mas): ";
                    cin >> rondaMaxima;
                    if(rondaMaxima <= 0)
                    {
                        cout << "No se puede elegir una ronda menor a 1" << endl;
                        cout << "Se jugara automaticamente 1 ronda" << endl;
                        rondaMaxima = 1;
                        system("pause");
                    }
                    system("cls");
                }
                rondaMaxima = rondaMaxima * 6;

                // Mostrar primer cartel de la ronda con función
                CartelRonda2J(ronda, puntajeTotal, puntajeTotalP2, bdTurno, nombreJ1, nombreJ2);

                // Juego normal de dos jugadores
                while(puntajeTotal < 100 && puntajeTotalP2 < 100 && bdEscalera == false && juegoPersonalizado == false)
                {
                    // Función Jugar 2J
                    Juego2J(nombreJ1, nombreJ2, ronda, rondaMaxima, puntajeTotal, puntajeTotalP2, puntajeAuxiliar, lanzamiento, lanzamientoP2, lanzaAuxiliar1, lanzaAuxiliar2, suma, sumaMaxima, bdEscalera, bdTurno);
                }

                // Juego personalizado de dos jugadores
                if(juegoPersonalizado)
                {
                    for(int i = 1; i <= rondaMaxima && puntajeTotal < 100 && puntajeTotalP2 < 100 && bdEscalera == false; i++)
                    {
                        Juego2J(nombreJ1, nombreJ2, ronda, rondaMaxima, puntajeTotal, puntajeTotalP2, puntajeAuxiliar, lanzamiento, lanzamientoP2, lanzaAuxiliar1, lanzaAuxiliar2, suma, sumaMaxima, bdEscalera, bdTurno);
                    }
                }


           // Cartel de ganador
                if(puntajeTotal >= 100 && puntajeTotalP2 < 100 && bdEscalera == false)
                {
                    // Gana J1
                    system("cls");
                    cout << endl;
                    cout << "GANASTE " << nombreJ1 << "!" << endl;
                    cout << "PUNTAJE: " << puntajeTotal << endl;
                    system("pause");
                    system("cls");

                    ActualizarPuntajeMaximo(nombreJ1, jugadorMaxPuntaje, puntajeTotal, puntajeMaximo);
                }
                else if(puntajeTotalP2 >= 100 && puntajeTotal < 100 && bdEscalera == false)
                {
                    // Gana J2
                    system("cls");
                    cout << endl;
                    cout << "GANASTE " << nombreJ2 << "!" << endl;
                    cout << "PUNTAJE: " << puntajeTotalP2 << endl;
                    system("pause");
                    system("cls");

                    ActualizarPuntajeMaximo(nombreJ2, jugadorMaxPuntaje, puntajeTotalP2, puntajeMaximo);
                }
                else if(puntajeTotal >= 100 && puntajeTotalP2 >= 100 && bdEscalera == false)
                {
                    // Empate
                    if(lanzaAuxiliar1 < lanzaAuxiliar2)
                    {
                        system("cls");
                        cout << endl;
                        cout << "GANASTE " << nombreJ1 << "!" << endl;
                        cout << "PUNTAJE: " << puntajeTotal << endl;
                        system("pause");
                        system("cls");

                        ActualizarPuntajeMaximo(nombreJ1, jugadorMaxPuntaje, puntajeTotal, puntajeMaximo);
                    }
                    else if(lanzaAuxiliar2 < lanzaAuxiliar1)
                    {
                        system("cls");
                        cout << endl;
                        cout << "GANASTE " << nombreJ2 << "!" << endl;
                        cout << "PUNTAJE: " << puntajeTotalP2 << endl;
                        system("pause");
                        system("cls");

                        ActualizarPuntajeMaximo(nombreJ2, jugadorMaxPuntaje, puntajeTotalP2, puntajeMaximo);
                    }
                    else if(lanzaAuxiliar1 == lanzaAuxiliar2)
                    {
                        system("cls");
                        cout << endl;
                        cout << "EMPATE" << endl;
                        system("pause");
                        system("cls");
                    }
                }

























             // Caso si ambos jugadores sacan menos de 100 en personalizado
                else if(puntajeTotal < 100 && puntajeTotalP2 < 100 && bdEscalera == false)
                {
                    if(puntajeTotal > puntajeTotalP2)
                    {
                        // Gana J1
                        system("cls");
                        cout << endl;
                        cout << "GANASTE " << nombreJ1 << "!" << endl;
                        cout << "PUNTAJE: " << puntajeTotal << endl;
                        system("pause");
                        system("cls");

                        ActualizarPuntajeMaximo(nombreJ1, jugadorMaxPuntaje, puntajeTotal, puntajeMaximo);
                    }


                     else if(puntajeTotalP2 > puntajeTotal)
                    {
                        // Gana J2
                        system("cls");
                        cout << endl;
                        cout << "GANASTE " << nombreJ2 << "!" << endl;
                        cout << "PUNTAJE: " << puntajeTotalP2 << endl;
                        system("pause");
                        system("cls");

                        ActualizarPuntajeMaximo(nombreJ2, jugadorMaxPuntaje, puntajeTotalP2, puntajeMaximo);
                    }

                   else
                    {
                        if(lanzaAuxiliar1 < lanzaAuxiliar2)
                        {
                            system("cls");
                            cout << endl;
                            cout << "GANASTE " << nombreJ1 << "!" << endl;
                            cout << "PUNTAJE: " << puntajeTotal << endl;
                            system("pause");
                            system("cls");

                            ActualizarPuntajeMaximo(nombreJ1, jugadorMaxPuntaje, puntajeTotal, puntajeMaximo);
                        }
                        else if(lanzaAuxiliar2 < lanzaAuxiliar1)
                        {
                            system("cls");
                            cout << endl;
                            cout << "GANASTE " << nombreJ2 << "!" << endl;
                            cout << "PUNTAJE: " << puntajeTotalP2 << endl;
                            system("pause");
                            system("cls");

                            ActualizarPuntajeMaximo(nombreJ2, jugadorMaxPuntaje, puntajeTotalP2, puntajeMaximo);
                        }
                        else if(lanzaAuxiliar1 == lanzaAuxiliar2)
                        {
                            system("cls");
                            cout << endl;
                            cout << "EMPATE" << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                }



             // Reinicio de variables para el modo dos jugadores
                bdEscalera = false, bdTurno = true, bdJuego = true;
            // Reinicio de variables si se gana
            ronda = 1, lanzamiento = 0, lanzamientoP2 = 0, lanzaAuxiliar1 = 0, lanzaAuxiliar2 = 0, puntajeTotal = 0, puntajeTotalP2 = 0, puntajeAuxiliar = 0, suma = 0, sumaMaxima = 0;

            break;
        case 3: /// Puntaje maximo
            PuntajeMaximo(jugadorMaxPuntaje, puntajeMaximo);

            break;
        case 0: /// Salir del programa
            cout << endl;
            cout << "Gracias por jugar!" << endl;
            return 0;

            break;
        default:
            cout << endl;
            cout << "Ingrese una opcion correcta" << endl;
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

int main()
{
    MenuPrincipal();
}
