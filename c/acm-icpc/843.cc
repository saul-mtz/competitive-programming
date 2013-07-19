/**********************************************************
	Program:	Crypt Kicker
	Author:		Saúl Martínez Vidals
	Date:		09/24/07	
***********************************************************
		@JUDGE_ID: 63787VV 843 C++ "Data Structures"
**********************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct campo
{
    short longitud;
    string palabra;
};

/* prototipos de funciones */
int comparar(const void *, const void *);
int busqueda_binaria(int, int, campo []);
string descifra(string, campo[], int);

/* función principal */
int main()
{
    campo diccionario[1000];
    int i, n;
    char c;
    string s, mensaje;

    cin >> n;
    /* lee las palabras del diccionario */
    for(i = 0; i < n; i++)
    {
        cin >> s;
        diccionario[i].longitud = (short)s.size();
        diccionario[i].palabra = s;        
    }
    
    /* ordena las palabras del diccionario de acuerdo a su longitud */
    qsort(diccionario, n, sizeof(campo), comparar);
    
    /* lee lo mensajes encriptados */
    while(getline(cin, mensaje))
    {
        /* descifra el mensaje leído */
        if(mensaje != "")
        {
            mensaje = descifra(mensaje, diccionario, n);
            /* despliega el resultado */
            cout << mensaje << endl;
            mensaje = "";
        }
    }
    
    return 0;
}

/* función usada por qsort para ordenar las palabras del diccionario */
int comparar(const void *a, const void *b)
{
    campo p1 = *(campo *)a;
    campo p2 = *(campo *)b;
    
    if((short)p1.longitud > (short)p2.longitud)
        return 1;
    else if((short)p1.longitud == (short)p2.longitud)
        return 0;
    return -1;
}

/* función que descifra el mensaje */
string descifra(string mensaje, campo diccionario[], int n)
{
    istringstream buffer(mensaje);
    int i, k, l;
    string cadena, mensaje_des;
    short tamano, solucion = 1;
    
    while(buffer >> cadena)
    {
        tamano = cadena.size();
        cout << "$" << cadena << endl;
        l = busqueda_binaria(tamano, n, diccionario);
        for(k; diccionario[k].longitud == l; k ++)
        {
            cout << cadena << ";" << endl;
        }
    }
    
    if(solucion == 0)
    {
        for(i = 0; i < mensaje.size(); i ++)
        {
            if(mensaje.at(i) != ' ')
                mensaje_des += '*';
            else
                mensaje_des += ' ';
        }
    }
    
    return mensaje_des;
}


/* búsqueda binaria */
int busqueda_binaria(int a, int n, campo datos[])
{
	int i = 0, j = n, m;
	
    cout << "$" << a << endl;
	while(i < j)
	{
		m = (i + j)/2;
		if(a > datos[m].longitud)
			i = m+1;
		else
			j = m;
	}
	if(a == datos[i].longitud)
		return i;
	else
		return -1;
}

