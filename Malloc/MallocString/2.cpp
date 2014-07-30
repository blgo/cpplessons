/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad 2008/2009*/
#include <stdio.h>
#include <stdlib.h>
#include "l2.h"
#include <string.h>
using namespace N;
int main (){
	LISTA lista=NULL;
	int opcion;
	do{
		printf("Autor: Jose Blas Gomez Fuentes.\n");
		printf("Descripcion: Este programa admistra una cola de archivos que queremos imprimir.\n");
		menu();
		scanf("%i",&opcion);
		fflush(stdin);
		switch(opcion){
			case 1: crearimp(lista); system("cls"); break;
			case 2: urgente(lista); system("cls"); break;
			case 3: mostrar(lista); system ("pause"); system("cls"); break;
			case 4: eliminar(lista); printf("\nTrabajo imprimido correctamente :-)\n"); system ("pause"); system("cls"); break;
			case 5: num_trabajos(lista); system ("pause"); system("cls"); break;
			case 6: cambiarcategoria(lista); system ("pause"); system("cls"); break;
			case 7: borrar_a(lista);  system ("pause"); system("cls"); break;
			case 8: cambiarnum_c(lista); system ("pause"); system("cls"); break;
			case 9: liberar(lista);system("pause"); system("cls"); break;
			case 0: return 0;
		}
	}while(opcion!=0);
}