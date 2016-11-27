/**********************************************************
	Program:	Packing polygons 
	Author:		Saúl Martínez Vidals
	Date:		20-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 10005 C "Geometry"
***********************************************************
			        RESULETO !!!
**********************************************************/

#include <stdio.h>
#include <math.h>

float distancia(float, float, float, float);
void punto_medio(float, float, float, float, float[]);

int main()
{
	short i, j, n;
	int puntos[100][2];
	float medio[2], r, d, r_min, r_max;
	float a[2], b[2], c[2], e[2], m1, m2, medio_ac[2], medio_bc[2];
	
	scanf("%hd", &n);
	while(n != 0)
	{
		r_min = 0;
		for(i = 0; i < n; i++)
			scanf("%d %d", &puntos[i][0], &puntos[i][1]);
		scanf("%f", &r);
		r *= r;		
		for(i = 0; i < n-1; i++)
		{
			for(j = i+1; j < n; j++)
			{
				d = distancia(puntos[i][0], puntos[i][1], puntos[j][0], puntos[j][1]);
				if(d > r_min)
				{
					a[0] = puntos[i][0];
					a[1] = puntos[i][1];
					b[0] = puntos[j][0];
					b[1] = puntos[j][1];
					r_min = d;
				}
			}
		}
		r_min /= 4;
		if(r < r_min)
			j = 0;
		else
		{
			punto_medio(a[0], a[1], b[0], b[1], medio);
			r_max = 0;
			for(i = 0; i < n; i++)
			{
				d = distancia(medio[0], medio[1], puntos[i][0], puntos[i][1]);
				if(d > r_max)
				{
					c[0] = puntos[i][0];
					c[1] = puntos[i][1];
					r_max = d;
				}
			}
			
			if((r_max == r_min) || (r >= r_max))
				j = 1;
			else
			{
				e[0] = medio[0];
				e[1] = (c[0]*c[0] + c[1]*c[1] - a[0]*c[0] - b[0]*c[0])/(2*c[1]);
				d = distancia(a[0], a[1], e[0], e[1]);
				if(r >= d)
					j = 1;
				else
					j = 0;
			}
		}

		if(j)
			puts("The polygon can be packed in the circle.");
		else
			puts("There is no way of packing that polygon.");
			
		scanf("%hd", &n);
	} 
	return 0;
}

/* función que regresa el cuadrado de la distancia entre dos puntos del plano */
float distancia(float x1, float y1, float x2, float y2)
{
	return (pow(x2-x1, 2) + pow(y2-y1, 2));
}

/* calcula el punto medio entre (a, b) y (c, d), almacena el resultado en m*/
void punto_medio(float a, float b, float c, float d, float m[])
{
	m[0] = (float)(a + c)/2;
	m[1] = (float)(b + d)/2;
}

