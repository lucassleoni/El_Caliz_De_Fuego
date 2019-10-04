#include <stdio.h>
#include <stdbool.h>

const unsigned short EDAD_MIN = 17;
const unsigned short INTELIGENCIA_MIN = 0;
const unsigned short INTELIGENCIA_MAX = 10;
const unsigned short FUERZA_MIN = 0;
const unsigned short FUERZA_MAX = 10;
const char MAGIA_BUENA = 'B';
const char MAGIA_REGULAR = 'R';
const char MAGIA_MALA = 'M';

/* 
	Pre-Condiciones:
	- El/los participante/s debe/n tener 17 años como mínimo para ser validado por el Cáliz.
	- Toda escritura durante la ejecución del programa debe ser en mayúsculas,
	  exceptuando cuando se quiere realizar otro ingreso (en ese caso, no es estrictamente necesario).
	- Tanto la Inteligencia como la Fuerza, se representa con valores enteros dentro del intervalo cerrado [0 ; 10].

	Post-Condiciones:
	- Al finalizar el ingreso de el/los participante/s correctamente, se mostarará por pantalla el campeón definitvo
	  (en caso que lo haya), referido por el número de orden en que fue ingresado.
	  De lo contrario, se informará que no lo hay.
*/

// Pre C: La 'Edad' ingresada por el usuario debe ser un número entero, cuyo valor mínimo puede ser 17.
// Post C.: Devuelve 'true' si dicho valor cumple con la Pre-Condición mencionada.
bool edad_valida(unsigned short edad){
	return(edad >= EDAD_MIN);
}

// Pre C: La 'Inteligencia' ingresada por el usuario debe ser un número entero perteneciente al rango cerrado [0 ; 10].
// Post C.: Devuelve 'true' si dicho valor cumple con la Pre-Condición mencionada.
bool inteligencia_valida(unsigned short inteligencia){
	return((inteligencia >= INTELIGENCIA_MIN) && (inteligencia <= INTELIGENCIA_MAX));
}

// Pre C: La 'Fuerza' ingresada por el usuario debe ser un número entero perteneciente al rango cerrado [0 ; 10].
// Post C.: Devuelve 'true' si dicho valor cumple con la Pre-Condición mencionada. 
bool fuerza_valida(unsigned short fuerza){
	return((fuerza >= FUERZA_MIN) && (fuerza <= FUERZA_MAX));
}

// Pre C: La 'Capacidad Mágica' ingresada por el usuario debe ser uno de los caracteres 'B', 'R' o 'M' (en mayúsculas).
// Post C.: Devuelve 'true' si dicho caracter es uno de los mencionados.
bool capacidad_magica_valida (char capacidad_magica){
	return((capacidad_magica == MAGIA_BUENA) || (capacidad_magica == MAGIA_REGULAR) || (capacidad_magica == MAGIA_MALA));
}

// Pre C.: Compara las datos del campeón actual (en caso de haberlo) contra el nuevo participante ingresado para ver si este es campeón.
// Post C.: Si el nuevo participante resulta campeón, la función cambia los datos del campeón anterior por los del nuevo participante.
//			Siendo este el que mejores atributos posea (superándolo, en este orden, por: inteligencia, luego fuerza y, como última instancia, la capacidad mágica).
bool es_campeon(unsigned short inteligencia, unsigned short fuerza, unsigned short valor_capacidad_magica, unsigned short inteligencia_campeon, unsigned short fuerza_campeon, unsigned short valor_capacidad_magica_campeon){
	if(inteligencia_campeon < inteligencia){
		return true;
	}
	else if((fuerza_campeon < fuerza) && (inteligencia_campeon == inteligencia)){
		return true;
	}
	else if((valor_capacidad_magica_campeon < valor_capacidad_magica) && (fuerza_campeon == fuerza) && (inteligencia_campeon == inteligencia)){
		return true;
	}
	else{
		return false;
	}
}

// Pre C: El caracter recibido por la función debe ser uno de los caracteres 'B', 'R' o 'M' (en mayúsculas).
// Post C.: Devuelve por referencia un valor numérico (1-2-3) para cada caracter, según su orden creciente (M < R < B, respectivamente).
void asignar_valores_capacidad_magica(char *capacidad_magica, unsigned short *valor_capacidad_magica){
	if(*capacidad_magica == 'M'){
		(*valor_capacidad_magica) = 1;
	}
	else if(*capacidad_magica == 'R'){
		(*valor_capacidad_magica) = 2;
	}
	else if(*capacidad_magica == 'B'){
		(*valor_capacidad_magica) = 3;
	}
}

// Pre C.: Imprime por pantalla los mensajes de bienvenida al usuario y de inicio del programa, solicitando al usuario un caracter para ingresar (o no) un participante.
// Post C.: Devuelve por referencia el caracter ingresado por el usuario a la variable 'ingresar_praticipante'.
void dar_bienvenida(char *ingresar_praticipante){
	printf("\n¡Bienvenido al Cáliz de Fuego!\n");
	printf("\nPara decidirse un campeón, se evaluará (en el siguiente orden) qué participante tiene mejores atributos de: Inteligencia, Fuerza y Capacidad Mágica.\n");
	printf("¿Deseas ingresar algún participante?\n('N' si no quieres, cualquier otra tecla en caso contrario)\n");
	scanf(" %c", ingresar_praticipante);
}

// Pre C.: Se le solicita por pantalla al usuario un caracter para ingresar (o no) un nuevo participante.
// Post C.: Devuelve por referencia el caracter ingresado por el usuario a la variable 'ingresar_praticipante'.
void pedir_mas_ingresos (char *ingresar_praticipante){
	printf("\n¿Deseas ingresar otro participante?\n('N' si no quieres, cualquier otra tecla en caso contrario)\n");
	scanf(" %c", ingresar_praticipante);
}

// Pre C.: Se le solicitan por pantalla al usuario los datos del nuevo participante.
//		   Para ser aceptado, cada dato ingresado debe cumplir con las Pre-Condiciones explicitadas en su respectiva función.
// Post C.: Se devuelven por referencia los datos ingresados en la variable correspondiente a cada uno de ellos.
void pedir_datos(unsigned short *edad, unsigned short *inteligencia, unsigned short *fuerza, char *capacidad_magica){
	printf("\nEdad (17 años o mayor): ");
	scanf("%hi", edad);
	if(!edad_valida(*edad)){
		printf("El participante no tiene la edad suficiente para participar...\n");
	}

	else{
		printf("Inteligencia (entre 0 y 10): ");
		scanf("%hi", inteligencia);
		if(!inteligencia_valida(*inteligencia)){
			do{
			printf("Inteligencia inválida, por favor reingrese el dato: ");
			scanf("%hi", inteligencia);
			}while(!inteligencia_valida(*inteligencia));			
		}

		printf("Fuerza (entre 0 y 10): ");
		scanf("%hi", fuerza);
		if(!fuerza_valida(*fuerza)){
			do{
			printf("Fuerza inválida, por favor reingrese el dato: ");
			scanf("%hi", fuerza);
			}while(!fuerza_valida(*fuerza));			
		}

		printf("Capacidada mágica (Buena = B, Regular = R, Mala = M): ");
		scanf(" %c", capacidad_magica);
		if(!capacidad_magica_valida(*capacidad_magica)){
			do{
				printf("Capacidad mágica inválida, por favor reingrese el dato: ");
				scanf(" %c", capacidad_magica);
			}while(!capacidad_magica_valida(*capacidad_magica));
		}
	}
}

// Pre C.: La función recibe el valor numérico de la cantidad de participantes ingresados, una vez que el usuario decidió no ingresar más.
// Post C.: Si hay un campeón, este se imprime por pantalla, identificado por su número de ingreso. En caso contrario, se imprime que no hay campeón.
void imprimir_campeon(unsigned short contador_campeon){
	if(contador_campeon != 0){
		printf("\nEl campeón es el número %i :)\n\n", contador_campeon);
	}

	else{
		printf("\nNo hay campeón :(\n\n");
	}
}

int main(){
	unsigned short edad = 0;
	unsigned short inteligencia = 0, fuerza = 0, valor_capacidad_magica = 0;
	unsigned short inteligencia_campeon = 0, fuerza_campeon = 0, valor_capacidad_magica_campeon = 0;
	char capacidad_magica;
	char ingresar_praticipante;
	unsigned short contador_participantes = 0;
	unsigned short contador_campeon = 0;
	
	dar_bienvenida(&ingresar_praticipante); //Inicia el programa

	if(ingresar_praticipante != 'N'){
		printf("\n¡Genial! Ahora el Cáliz de Fuego virtual te solicitará los siguientes datos de cada participante...\n");

		do{
			pedir_datos(&edad, &inteligencia, &fuerza, &capacidad_magica); // Se solicitan los datos del participante a ingresar
			asignar_valores_capacidad_magica(&capacidad_magica, &valor_capacidad_magica);
			contador_participantes++; // Por cada ingreso, se suma '1' al contador hasta que finalice el ingreso de participantes.

			if(es_campeon(inteligencia, fuerza, valor_capacidad_magica, inteligencia_campeon, fuerza_campeon, valor_capacidad_magica_campeon)){
				// Si cumple con las condiciones necesarias, se le asigna el atributo de "Campeón" al participante ingresado.
				inteligencia_campeon = inteligencia;
				fuerza_campeon = fuerza;
				valor_capacidad_magica_campeon = valor_capacidad_magica;
				contador_campeon = contador_participantes;
			}
			
			pedir_mas_ingresos(&ingresar_praticipante);

		}while (ingresar_praticipante != 'N');
		imprimir_campeon(contador_campeon); // Finaliza el programa, imprimiendo el campeón o la ausencia del mismo.
	}

	return 0;
}