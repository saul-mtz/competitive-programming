/* Implementación de graficas */

#include <iostream>
#include <cstdio>
#include <list>
#include <map>

#define MAX 200

using namespace std;

typedef short vertice;
typedef list< vertice > lista_vertices;
typedef lista_vertices lista_adyacencias[MAX];

class Grafica
{
	vertice num_vertices;					/* número de vertices de la grafica */
	vertice num_aristas;					/* número de aristas de la gráfica */
	char representacion;					/* nos dice si el modo de representación es-
											mediante una lista o una matriz de adyacen--
											cias */
	char modo;								/* informa si la gráfica es dirigida o no --
											dirigida */
	bool visitados[MAX];					/* informa que vértices han sido visitados*/
	vertice trayectoria[MAX];
	vertice it;
	vertice i;								/* contador generico */

	public:
	lista_adyacencias lista_a;				/* lista de adyacencias para la gráfica */
	
	Grafica(vertice, vertice, char);		/* constructor de la clase */
	
	/* métodos */
	void dfs_lista(vertice, lista_adyacencias);
	void inicializa();
	void imprime_grafica_la();
	void llena_lista();
	void llena_matriz();
	void recorrido_finalizado(vertice);
	void recorrido_intermedio(vertice);
};

/* función principal */
int main()
{
	vertice n, l;
	
	cin >> n >> l;
	
	while(n != 0)
	{
		Grafica g(n, l, 'l');
		
		g.imprime_grafica_la();
		for(vertice i = 0; i < 1; i++)
		{
			g.inicializa();
			g.dfs_lista(i, g.lista_a);
		}
		cin >> n >> l;
	}

	return 0;
}


/* C O N S T R U C T O R E S    D E L    G R A F O */
/* Constructor usado en el problema Bicoloring */
Grafica :: Grafica(vertice nv, vertice na, char r)
{
	cout << "constructor ...\n";
	
	num_vertices = nv;						/* asigana el número de vertices */
	num_aristas = na;						/* asigan el número de aristas */
	representacion = r;
	if(r == 'l')							/* grafica representada usando una lista -*/
		llena_lista();						/* de adyacencias */
	else									/* usando una matriz de adyacencias */
		llena_matriz();
}


/* Depth First Search: Búsqueda en profundidad */
void Grafica :: dfs_lista(vertice v, lista_adyacencias g)
{
	vertice n, i, s;
	
	if(visitados[v])
	{
		recorrido_finalizado(s);
	}
	else
	{
		lista_vertices l = g[v];
		visitados[v] = true;
		n = l.size();
		
		for(i = 0; i < n; i++)
		{
			s = l.front();
			recorrido_intermedio(s);
			dfs_lista(s, g);
			l.pop_front();
		}
	}
}


/* iniciliza lo necesario para hacer un recorrido */
void Grafica :: inicializa()
{
	it = 0;
	for(i = 0; i < num_vertices; i ++)
		visitados[i] = false;
}


/* imprime la gŕafica representada como una lista de adyacencias */
void Grafica :: imprime_grafica_la()
{
	cout << "\nNúmero de vertices:\t" << num_vertices << endl;
	cout << "Número de aristas:\t" << num_aristas << endl;

	for(i = 0; i < num_vertices; i++)
	{
		lista_vertices l = lista_a[i];

		cout << i << ": ";
		while(!l.empty())
		{
			cout << l.front() << " ";
			l.pop_front();
		}
		cout << endl;
	}
	cout << endl;
}


/* llena la lista de adyacencias con las n aristas leídas de entrada estándar */
void Grafica :: llena_lista()
{
	vertice a, b;
	
	cout << "llenando gráfica ...\n";
	for(i = 0; i < num_aristas; i++)	
	{
		cin >> a >> b;
		lista_a[a].push_back(b);
		lista_a[b].push_back(a);
	}
}


/* llena la matriz de adyacencias */
void Grafica :: llena_matriz()
{
	;
}

/* cuando el recorrido dfs o bfs han concluido */
void Grafica :: recorrido_finalizado(vertice v)
{
	cout << trayectoria[0];
	for(vertice k = 1; k < it; i++)
		cout << " " << trayectoria[k];
	cout << endl;
}


/* cuando el recorrido dfs o bfs esta en transcurso */
void Grafica :: recorrido_intermedio(vertice v)
{
	trayectoria[it++] = v;
}

