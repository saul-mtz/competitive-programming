#bin/bash
#
# script que recibe como párametro el nombre del programa fuente y hace la compilacion -
# creando un programa ejecutable con el mismo nombre, al final ejecuta el programa :)
# ejemplo de ejecucion:
#
# $> bash compilar 100.c
#
# compila el archivo '100.c' y si no hay errores ejecuta el programa 100, opcionalmente
# el programa en ejecución puede leer de un archivo cuyo nombre es también pasado como -
# parámetro; ejemplo:
#
# $> bash compilar 100.c datos
#

FUENTE=$1
ARCHIVO=$2
declare NOMBRE
declare EXTENSION

# si el archivo existe lo compila


if test -f $FUENTE; then
	EXTENSION=`echo $FUENTE | cut -d . -f2`	# obtiene la extensión del archivo
	NOMBRE=`basename $FUENTE .$EXTENSION`		# obtiene el nombre sin extensión
	
	if test -f $NOMBRE; then					# si existía un programa con el mismo --
		rm $NOMBRE								# nombre que el que se va a crear enton-
	fi											# ces es eliminado
	
	echo compilando el archivo $NOMBRE ...
	case $EXTENSION in
		"c")
			echo Programa escrito en lenguaje C
			gcc -o $NOMBRE -ansi -lm -pedantic $FUENTE ;;
		"cpp")
			echo Programa escrito en C++
			g++ -o $NOMBRE -ansi -lm $FUENTE ;;
		"cc")
                        echo Programa escrito en C++
                        g++ -lm -lcrypt -O2 -pipe -DONLINE_JUDGE -o $NOMBRE $FUENTE ;;
		"java")
			echo Programa escrito en Java ;;
		*)
			echo Lenguaje de programación no soportado ;;
	esac
	
	if test -f $NOMBRE; then
		echo cediendo perimisos de ejecucion ...
		chmod u+x $NOMBRE
		echo ejecutando el programa $NOMBRE ...
		if test -n "$ARCHIVO" && test -f $ARCHIVO ; then
			./$NOMBRE < $ARCHIVO
		else
			./$NOMBRE
		fi
	fi
# en caso contrario imprime en pantalla un mensaje
else
	echo El archivo $FUENTE no existe
fi

