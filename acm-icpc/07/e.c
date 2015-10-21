#include <stdio.h>
#include <math.h>

int main()
{
   double valor = 6.000000000005, iptr, resultado;

   resultado = modf( valor, &iptr );
   printf( "modf( %f, %f ) = %f\n", valor, iptr, resultado );
   if(resultado == 0)
    puts("entero");
   return 0;
}
