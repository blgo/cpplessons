/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad 2008/2009*/
#include <stdio.h>
#include <stdlib.h>
#include "5libreria.h"
#include <string.h>
using namespace N;
int main(){
	TipoPila pila;
	int opcion,i=0,elem;
	do{
		printf("Autor: Jose Blas Gomez Fuentes.\n");
		printf("Descripcion: Este programa implementa las funciones tipicas de una pila dinamica\n");
		menu();
		scanf("%i",&opcion);
		fflush(stdin);
		switch(opcion){
		case 1: if(i==1){
					printf("\n¿Estas seguro que quieres reiniciar la lista?\nPulse 2 para continuar o 1 para cancelar: ");
					scanf("%i",&i);
					fflush(stdin);
					if(i==2) pila=crear(i);
					else if(i==1){
						printf("\nHa cancelado la operacion");
						i=1;
					}
				}
				else pila=crear(i);
				system("cls");
				break;
		case 2: printf("\n%i   \n0//significa no\n1//significa si\n",pilavacia(pila));
				system("pause");
				system("cls");
				break;
		case 3: if(i==0) printf("\nCrea la pila primero\n");
				else printf("\n%i   \n0//significa no\n1//significa si\n",pilallena(pila));
				system("pause");
				system("cls");
				break;
		case 5: if(i==0) printf("\nCrea la pila primero\n");
				else{
					sacar(pila,elem);
					printf("\nSe a sacado el dato %i de la pila\n//Devolver 0 es la forma que tiene la funcion de decirte que no hay datos en la lista\n",elem);
				}
				system("pause");
				system("cls");
				break;
		case 4: if(i==0) printf("\nCrea la pila primero\n");
				else{
					printf("\nIntroduce el numero que quieres insertar: "); scanf("%i",&elem); fflush(stdin);
					insertar(pila,elem);
				}
				system("cls");
				break;
		case 6: if(i==0) printf("\nCrea la pila primero\n");
				else mostrar(pila);
				system("pause");
				system("cls");
				break;
		case 0: return 0;
		default: system("cls");
		}
	}while(opcion!=0);
}