//Practica 1: Pasa la calculadora!

/*
 * Azahara Fernández Notario
 * Juan Luis Güell Cruz
 * Fundamentos de Programacion Grupo F
 * Laboratorio 1
 */

/*Hemos incluido como funciones de la version 4:
 -Que el programa admita lectura de caracteres sin dar error en ejecucion.
 -Inteligencia Artificial del automata
 - Hay veces que tarda un poco en pensar hay que dejar que responda (Sobre todo cuando no gana o le cuesta mucho no perder)
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

//------------------------ Declaracion de constantes -----------------------------//

const int META = 31;  //Indica cual es el maximo que debe sumar el juego
const string nombreArch = "versionPC.txt";
const string nombreArch2 = "informePC.txt";


//----------------------- Declaracion tipo enumerado -----------------------------//

typedef enum
{
    Nadie, Automata, Persona
}tJugador;


/*
 Nadie = 0;
 Automata = 1;
 Persona = 2;
 */


//----------------------------- DECLARACION DE FUNCIONES -----------------------//

// Funciones Version 1
tJugador pasaCalculadora(int nivDif); // Para la hemos a–adido el parametro nivDif (que indica el nivel de difivultad que lleva el juego) V4
//Guia las el juego llamando al resto de funciones necesarias para ello
tJugador quienEmpieza(); // decide quien empieza aleatoriamente (Persona o Automata)
bool mismaFila( int ultimo, int nuevo );// Comprueba si el nuevo numero introducido esta en la misma fila que el anterior
bool mismaColumna( int ultimo, int nuevo );// Comprueba si el nuevo numero introducido esta en la misma columna que el anterior
bool digitoValido( int ultimo, int nuevo );// Comprueba que el digito nuevo sea valido (misma fila o columna y distinto del anterior)
int digitoAleatorio();// Genera un numero aleatorio del 1-9 (se usa en la primera vuelta del boucle ya que de esta forma no depende de un numero anterior)
int digitoAutomata(int ultimo, int suma, int nivDif);  // Hemos a–adido el parametro suma y nivDif de cara a la IA (v4).
// Segun el nivel de dificultad devuelve el nuevo digito ya validado del automata
int digitoPersona();// Pide un numero al la persona y comprueba que este entre 0-9 ya que no depende de un anterior
int digitoPersona( int ultimo );// Pide un digito al jugador y comprueba que sea valido
// Los dos digitoPesona llevan una mejora que ademas permite que el programa no se bloquee si introduces una letra

// Funciones propias Version 1
void mostrarQuienEmpieza ( tJugador jugador );// Muestra por pantalla el mensaje de quien empieza (Persona o Automata)
void mostrarCalculadora ();// Muestra "El teclado de la calculadora" por pantalla
int primerIntento(tJugador jugador );// Llama a las funciones encargadas de la primera jugada de la partida
tJugador definirFinal(tJugador jugador, int nuevo);// Devuelve quien gana
tJugador cambioDeJugador(tJugador jugador); // Pasa de turno

//Funciones Version 2
bool mostrar(string nombArch); // Muestra el contenido de VersionPC.txt
int menu();// Muestra el menu y sus opciones (A las cuales hemos a–adido modificar la dificultad del juego

//Funciones propias Version 2
bool comprobarOpcionMenu(int opcion); // Comprueba que la opcion introducida sea un parametro valido
void leerOpcionmenu(); // Ejecuta lo opcion que escojamos

//Funciones Version 3
bool actInforme(int jugadas, int ganadas, int abandonos); // Lleva el informe de lo que pasa en las partidas

//Funciones reconocimiento de caracteres, Version 4
bool comprobarNumero(char letra); // Comprueba que aquello introducido por teclado sea un numero
int charAInt(char caracter); // Pasa de caracter a numero
int cogerNumero(char c, bool negativo);//Lee de la pantalla la secuencia de caracteres que compone un numero hasta que encuentre algo distinto de numero. Devuelve el numero leido.
int entradaTecladoJugada();//Pide un numero por pantalla para relaizar jugada. Si el usuario no introduce un numero sigue pidiendo una jugada.
int entradaTecladoMenu();//Este programa realiza la entrada de teclado para que llegue al menu
int nivelDificultad();// Permite al jugador escoger entre los distintos niveles de dificultad

//Funciones IA del Automata, Version 4
int IA(int ultimo, int suma, int nivDif);
int movPosibles(int mov, int buscador);
int noPerder(int ultimo, int suma);
int ganarPartida(int ultimo, int suma);
//Funciones genericas:
int noPerder (int ultimo, int suma, int nivDificultad);
int ganarPartida (int ultimo, int suma, int nivDificultad);

/////---------------- PROGRAMA ------------- //////

int main()
{
    string nombreJugador;
    srand(time(NULL));
    
    cout << "Bienvenido a pasa la calculadora!!" << endl;
    cout << "Como te llamas?: ";
    getline (cin, nombreJugador);
    cout << endl << "Hola " << nombreJugador << endl;
    
    leerOpcionmenu(); // Para V2
    
    cout << "Hasta la proxima " << nombreJugador << endl;
    
    system("pause");
    return 0;
}

// ------------------ FUNCIONES OBLIGATORIAS VERSION 1  ------------------- //

tJugador pasaCalculadora(int nivDif)
{
    tJugador jugador;
    int ultimo = 0,  nuevo, suma = 0;
    
    //Inicio
    cout << "El nivel de dificultad de la partida esta establecido en: " << nivDif << endl;
    
    jugador = quienEmpieza();
    mostrarQuienEmpieza(jugador);
    
    nuevo = primerIntento(jugador);
    
    jugador = cambioDeJugador(jugador);
    
    if (nuevo != 0)
    {
        suma = nuevo;
        cout << "Suma: " << suma << endl;
    }
    
    
    //Nudo
    while(nuevo != 0 && suma < META)
    {
        ultimo = nuevo;
        if(jugador == Persona)
        {
            nuevo = digitoPersona(ultimo);
            jugador = Automata;
        }
        else
        {
            nuevo = digitoAutomata(ultimo, suma, nivDif);
            cout << "Yo pulso " << nuevo << endl;
            jugador = Persona;
        }
        
        if( nuevo != 0)
        {
            suma += nuevo;
            cout << "Suma: " << suma << endl;
        }
    }
    return definirFinal(jugador, nuevo);
}

// Decide quien empieza la partida
tJugador quienEmpieza()
{
    return tJugador(rand() % 2 + 1); // + 1 porque no queremos que genere "Nadie"
}

//Comprueba que este en la misma fila
bool mismaFila( int ultimo, int nuevo )
{
    int filaNuevo, filaUltimo;
    
    filaNuevo = (nuevo - 1) / 3; // Calcula las filas de nuevo y ultimo y comprueba que sean iguales
    filaUltimo = (ultimo - 1) / 3;
    
    return ( filaNuevo == filaUltimo );
}

//Mismo metodo que mismaFila
bool mismaColumna( int ultimo, int nuevo )
{
    int colNuevo, colUltimo;
    
    colNuevo = (nuevo - 1) % 3;
    colUltimo = (ultimo - 1) % 3;
    
    return ( colNuevo == colUltimo );
}

//Comprueba que este en la misma fila o la misma columna y que a su vez ultimo sea distinto de nuevo
bool digitoValido( int ultimo, int nuevo )
{
    return ( ( mismaColumna(ultimo, nuevo ) || mismaFila( ultimo, nuevo ) ) && ( ultimo != nuevo ) );
}

//Genera un numero del 1 al 9
int digitoAleatorio()
{
    return (rand() % 9 + 1);
}

//Genera aleatorios hasta que uno sea valido
int digitoAutomata(int ultimo, int suma,  int nivDif)
{
    int nuevo;
    //Si no tiene nivel de dificultad las salidas seran aleatorias(como en V3).
    if(nivDif == 0)
    {
        do
        {
            nuevo = digitoAleatorio();
        }while ( !digitoValido( ultimo, nuevo ) ); //Se repetira hasta que el digito sea valido
    }
    else
    {
        nuevo = IA(ultimo, suma, nivDif); // Siempre devuelve uno valido
    }
    
    return nuevo;
}

//Pide un numero al jugador hasta que introduzca uno valido () entre 0-9. Devuelve el numero entre 0 y 9.
int digitoPersona()
{
    int nuevo;
    
    mostrarCalculadora();
    
    //La llamada a entradaTeclado() es para que admitir caracteres, aunque luego no sean opciones válidas
    // (es para que el programa no dé error en tiempo de ejecución).
    nuevo = entradaTecladoJugada();
    
    while( nuevo < 0 || nuevo > 9)
    {
        cout << "Error: tiene que estar entre 0 - 9 " << endl;
        
        nuevo = entradaTecladoJugada();
        cout << endl;
    }
    
    return nuevo;
}

//Pide un digito hasta que este cumpla las normas del juego. Devuelve el dígito válido.
int digitoPersona( int ultimo )
{
    int nuevo;
    
    nuevo = digitoPersona();
    
    while( !digitoValido( ultimo, nuevo ) && nuevo != 0 )
    {
        cout << "Error: tiene que ser distinto de " << ultimo << " y estar en la misma fila o columna. " << endl;
        //mostrarCalculadora(); //No tenemos claro si es necesario mostrar la calculadora tras el error.
        
        nuevo = digitoPersona();
    }
    
    return nuevo;
}

// -------------- FUNCIONES PROPIAS VERSION 1 ------------ //

//Dado un jugador muestra el mensaje de quien empieza
void mostrarQuienEmpieza ( tJugador jugador )
{
    switch (jugador)
    {
        case Automata:
            cout << "Empiezo yo" << endl;
            break;
        case Persona:
            cout << "Empiezas tu" << endl;
            break;
    }
}

// Muestra el teclado ordenado
void mostrarCalculadora ()
{
    cout << setw(5) << "7" << setw(5) << "8" << setw(5) << "9" << endl;
    cout << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << endl;
    cout << setw(5) << "1" << setw(5) << "2" << setw(5) << "3" << endl;
}

// Ejecuta la primera interaccion del juego ya que esta no depende de un ultimo anterior
int primerIntento(tJugador jugador)
{
    int nuevo;
    
    if(jugador == Persona)
    {
        nuevo = digitoPersona();
    }
    else
    {
        nuevo = digitoAleatorio();
        cout << "Yo pulso " << nuevo << endl;
    }
    return nuevo;
}

//Muestra por pantalla el mensaje ganador correspondiente a Automata o Persona y devuelve el enumerado del ganador (Nadie si se abandona).
tJugador definirFinal(tJugador jugador, int nuevo)
{
    tJugador ganador;
    
    if ( nuevo != 0 )
    {
        if ( jugador == Automata )
        {
            cout << "Lo siento, has perdido! " << endl;
        }
        else
        {
            cout << "Enhorabuena!! Has ganado!!" << endl;
        }
        ganador = jugador;
    }
    else
    {
        ganador = Nadie;
    }
    return ganador;
}

//Recibe el enumerado del último jugador y devuelve el del siguiente.
tJugador cambioDeJugador(tJugador jugador)
{
    if (jugador == Automata)
    {
        jugador = Persona;
    }
    else
    {
        jugador = Automata;
    }
    return jugador;
}


/// -------------------- FUNCIONES VERSION 2 -------------------- ///

// Pide la opcion del menu hasta que de una valida. Devuelve dicha opción.
int menu()
{
    int opcion;
    do
    {
        cin.sync();
        cout << "1 - Jugar" << endl;
        cout << "2 - Acerca de" << endl;
        cout << "3 - Nivel de dificultad" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: " << endl;
        //Llamamos a esta función para que no dé error en tiempo de ejecución si el usuario introduce un caracter.
        opcion= entradaTecladoMenu();
    }while(!comprobarOpcionMenu(opcion));
    
    return opcion;
}

// Carga y muestra el archivo "acerca de". Devuelve true si se ha podido cargar el archivo.
bool mostrar(string nombArch)
{
    ifstream archivoCargar;
    string aux;
    
    archivoCargar.open(nombArch);
    
    if(archivoCargar.is_open())
    {
        cout << "--------------------------------------------------------------" << endl;
        while (!archivoCargar.eof())
        {
            getline(archivoCargar, aux);
            cout << aux << endl;
        }
        cout << "--------------------------------------------------------------" << endl;
        
        archivoCargar.close();
    }
    
    return !archivoCargar.fail();
    
}


// ----------------- FUNCIONES PROPIAS VERSIÓN 2 ------------------ //

//Llama a menu() y redirige hacia la opción escogida por el ususario.
void leerOpcionmenu()
{
    bool salir = false;
    tJugador ganador;
    int jugadas = 0, ganadas = 0, abandonos = 0, nivDif = 0;
    
    
    while(!salir)
    {
        switch (menu())
        {
            case 1:
                jugadas++;
                ganador = pasaCalculadora(nivDif);
                
                if(ganador == Automata)
                    ganadas++;
                else if(ganador == Nadie)
                    abandonos++;
                break;
                
            case 2:
                
                if(!mostrar(nombreArch))
                {
                    cout << "Error el archivo 'Acerca de' no cargo correctamente" << endl;
                }
                break;
            case 3:
                nivDif = nivelDificultad();
                break;
                
            case 0:
                salir = true;
                
                break;
        }
    }
    
    //Esto es parte de la versión 3.
    if ( !actInforme(jugadas, ganadas, abandonos))
    {
        cout << " AVISO: Al no encontrar un informe inicial no se han actualizado los datos, sino que se han guardado directamente. " << endl;
    }
}

//Comprueba que la opción introducida por teclado es se adecúa a una de las del menú. Devuelve true si es así.
bool comprobarOpcionMenu(int opcion)
{
    return (opcion == 1 || opcion == 2 || opcion == 3|| opcion == 0);
}


////---------------------  VERSION 3  ---------------------------////


//Abre el archivo de informe, o lo crea de no existir, y actualiza el registro de partidas.
//Devuelve true si se pudo cargar el archivo de informe.
bool actInforme(int jugadas, int ganadas, int abandonos){
    ifstream archivoCarga;
    ofstream archivoGuarda;
    bool carga = true;
    int dato = 0, utilizado;
    
    archivoCarga.open(nombreArch2);
    
    if(archivoCarga.is_open())
    {
        
        archivoCarga >> utilizado;
        archivoCarga >> dato;
        jugadas += dato;
        archivoCarga >> dato;
        ganadas += dato;
        archivoCarga >> dato;
        abandonos += dato;
        
        archivoCarga.close();
        
        archivoGuarda.open(nombreArch2);
        
        archivoGuarda << utilizado + 1 << endl;
        archivoGuarda << jugadas << endl;
        archivoGuarda << ganadas << endl;
        archivoGuarda << abandonos << endl;
        
    }
    else
    {
        carga = false;
        archivoGuarda.open(nombreArch2);
        
        archivoGuarda << 1 << endl;
        archivoGuarda << jugadas << endl;
        archivoGuarda << ganadas << endl;
        archivoGuarda << abandonos << endl;
        
    }
    
    archivoGuarda.close();
    return carga;
}


///---------FUNCIONES VERSIÓN 4 ENTRADA CARACTER POR TECLADO -----------///



//Devuelve true si el caracter recibido es un numero.
bool comprobarNumero (char letra)
{
    return ((letra >= '0') && (letra <= '9'));
}

//Recibe un tipo caracter y devuelve un tipo entero.
int charAInt(char caracter)
{
    int num = caracter - '0';
    return num;
}

//Lee de la pantalla la secuencia de caracteres que compone un numero hasta que encuentre algo
// distinto de numero. Devuelve el numero leido.
int cogerNumero(char c, bool negativo){
    int num = charAInt(c);
    
    cin.get(c);
    
    while(comprobarNumero(c)){
        num = num * 10 + charAInt(c);
        cin.get(c);
    }
    
    if(negativo)
        num = num * (-1);
    
    return num;
}

//Pide un numero por pantalla para relaizar jugada. Si el usuario no introduce un numero sigue pidiendo una jugada.
// Admite que el usuario introduzca primero un número y luego caracteres
// Devuelve el número leído por pantalla.
int entradaTecladoJugada()
{
    char c;
    bool negativo;
    int num;
    
    do{
        negativo = false;
        cin.sync();
        cout << "Introduce un digito (0 para abandonar): ";
        cin >> c;
        if(c == '-'){
            negativo = true;
            cin >> c;
        }
    }while(!comprobarNumero(c));
    
    num = cogerNumero(c, negativo);
    
    return num;
}

//Este programa realiza la entrada de teclado para que llegue al menu.
//Devueve -1 si no se ha introducido un valor numerico, para que asi al recibirlo la funcion menu() ense–e de nuevo las opciones.
int entradaTecladoMenu(){
    char c;
    bool negativo = false;
    int num;
    
    cin >> c;
    if (c == '-'){
        negativo = true;
        cin >> c;
    }
    
    if(!comprobarNumero(c)){
        cout << "Error: no ha introducido un numero" << endl;
        num = -1;
    }
    else
        num = cogerNumero(c, negativo);
    
    return num;
}

/*Permite escoger entre los distintos niveles de dificultad y devuelve el elegido
 Lo hemos limitado a 7 puesto que mas daba lugar a demasiadas combinaciones de juego y hacia que el programa se colapsase(Aunque no sabemos muy bien el por que), aunque se puede subir un poco mas a veces da problemas.*/
int nivelDificultad()
{
    int nivDif = 0;
    
    cout << "Escoja el nivel de dificultad: " << endl;
    cout << "0: La maquina es muy inutil. " << endl;
    cout << "1 - 6: La maquina no pierde a ( 1 - 6 ) turnos vista. " << endl;
    cout << "7 - No pienses en ganar."<< endl;
    
    do
    {
        cin.sync();
        cout << "Introduce tu opcion: ";
        cin >> nivDif;
    }while(nivDif < 0 || nivDif > 7);
    
    return nivDif;
}

//----------------------- FUNCIONES VERSION 4 Inteligencia Artificial   -----------------------------//

//Conduce el proceso del la Inteligencia Artificial del automata.
//Siempre devuelve una jugada posible.
int IA(int ultimo, int suma, int nivDif)
{
    int mov = - 1;
    int cont = 1;
    
    /*Aqui no haria falta este primer bucle, solo mov = ganarPartida (ultimo, suma, nivDif);  ///////////////////////////////////////OJO///////////////////
     pero quiero ver la salida de en cuantas jugadas me va a ganar.*/
    while ( (mov == -1) && (cont <= nivDif) )
    {
        mov = ganarPartida (ultimo, suma, cont);
        cont++;
    }
    //mov = ganarPartida (ultimo, suma, nivDif);  // No muestra exactamente en que movimiento gana.
    
    /*Si no gana el automata intenta no perder en varios turnos vista, en funcion del nivel de dificultad.
     Este bucle sí es necesario, porque el nivel planificación mas alto puede obviar jugadas inmediatas.*/
    if (mov == -1)
    {
        while ( (mov == -1) && (nivDif > 0))
        {
            mov = noPerder (ultimo, suma, nivDif);
            nivDif--;
        }
        if (nivDif > 0)
            cout << "No pierdo en al menos " << nivDif << " turno/s" << endl;
    }
    else
    {
        cout << "Gano como maximo en " << cont - 1 << " turno/s" << endl;
    }
    
    //En caso de haber perdido escoge la menor opcion.
    if (mov == -1)
    {
        mov = movPosibles (ultimo, 1);
    }
    
    return mov;
}


/*Devuelve uno de los cuatro movimentos posibles a partir de uno recibido (mov).
 Como solo devuelve de uno en uno tambien recibe un contador (buscador) que indica a partir de cual buscar.
 Si no hay mas movimientos posibles devuelve -1.*/
int movPosibles(int mov, int buscador)
{
    bool encontrado = false;
    
    while ((buscador <= 9) && !encontrado)
    {
        if (digitoValido(mov, buscador))
        {
            encontrado = true;
        }
        else
        {
            buscador++;
        }
    }
    if(!encontrado)
        buscador = -1;
    
    return buscador; // Ya que buscador sirve como contador y como numero de prueba (nuevo)
}


/*Esta funcion devuelve un movimiento que implica no perder en este turno. Devuelve -1 si a partir del movimiento recibido solo se puede perder.
 Esta función solo revisa un posible movimiento, el menor posible, por eso cont = 1.*/
int noPerder(int ultimo, int suma)
{
    int cont = 1, nuevo;
    
    nuevo = movPosibles(ultimo, cont);
    
    if ( nuevo + suma >= META)
    {
        nuevo = -1;
    }
    return nuevo;
}

//Devuelve un movimiento que deje sin opciones al jugador del siguiente turno. //Si no existe devuelve -1.
int ganarPartida(int ultimo, int suma)
{
    int cont = 0, mov = 0;
    bool movGanador = false;
    
    while (!movGanador && (cont < 4))
    {
        //Buscamos uno de los cuatro movimientos posibles (por orden)
        mov = movPosibles(ultimo, mov + 1);
        //Si noPerder devuelve -1 es que la suma con el menor numero que puede usar el siguiente jugador es mayor que META,
        //con lo que ese movimiento es gandor.
        if ((suma + mov < META) && (noPerder(mov, suma + mov) == -1))
        {
            movGanador = true;
        }
        else
        {
            cont++;
        }
    }
    if (!movGanador)
        mov = -1;
    
    return mov;
}

//Funcion general que busca movimientos que no hagan perder al autómata a nivDificultad jugadas vista.
int noPerder (int ultimo, int suma, int nivDificultad)
{
    int cont = 0, mov = 0;
    bool jugadaPerdedora = true;
    
    while (jugadaPerdedora  && (cont < 4))
    {
        mov = movPosibles (ultimo, mov + 1);
        
        if ((ganarPartida (mov, suma + mov, nivDificultad - 1) == -1) && (suma + mov < META))
        {
            jugadaPerdedora = false;
        }
        else
        {
            cont++;
        }
    }
    
    if(jugadaPerdedora)
    {
        mov = -1;
    }
    return mov;
}

//Funcion general que busca movimientos que hagan ganar al autómata a nivDificultad jugadas vista.
int ganarPartida (int ultimo, int suma, int nivDificultad)
{
    int cont = 0, mov = 0;
    bool jugadaGanadora = false;
    
    if(nivDificultad > 1)
    {
        while (!jugadaGanadora && (cont < 4))
        {
            mov = movPosibles (ultimo, mov + 1);
            
            if (noPerder (mov, suma + mov, nivDificultad) == -1 && (suma + mov < META) )
            {
                jugadaGanadora = true;
            }
            else
            {
                cont++;
            }
        }
        
        if (!jugadaGanadora)
        {
            mov = -1;
        }
    }
    
    else
    {
        mov = ganarPartida (ultimo, suma);
    }
    
    return mov;
}