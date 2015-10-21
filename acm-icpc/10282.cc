/**********************************************************
	Program:	Babelfish
	Author:		Saúl Martínez Vidals
	Date:		06/24/07
***********************************************************
		@JUDGE_ID: 63787VV 10282 C++ "Hash table"
**********************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int i;
	char c;
	map<string, string> diccionario;		/* usa un TDA mapa, donde la clave es la -*/
											/* palabra en el idioma foraneo, y el valor-
											asociado a esa clave es la traducción al ---
											inglés */
	string ingles, foraneo, aux;
	
	cin.get(c);								/* lee un caracter de la entrada estandar */
	while(c != '\n')						/* se repite mientras no se encuentre un -*/
	{										/* linea en blanco */
		cin >> aux >> foraneo;				/* lee las dos cadenas de entrada */
		ingles = c + aux;					/* como antes de leer el par de cadenas se -
											había leído un caracter, hay que pegar ambas
											cosas en una misma cadena */
		diccionario[foraneo] = ingles;		/* asigna en el elemento del mapa con clave-
											la palabra en el idioma foraneo su traduc--
											ción al inglés */
		cin.get();							/* ignora un salto de línea */
		cin.get(c);							/* lee nuevamente el primer caracter de la -
											entrada estándar */
	}

	/* una ves leídas las palabras del diccionario, se buscan las traducciones de las --
	palabras leídas de la entrada estándar */	
	while(getline(cin, foraneo))
	{
		/* si la cadena buscada no esta en el diccionario, el resultado es la cadena ---
		vacía, en este caso la traducción es la palabra 'eh' */
		if((aux = diccionario[foraneo]) == "")
			aux = "eh";
		cout << aux << "\n";
	}
		
	return 0;
}

