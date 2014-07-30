/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#include <stdlib.h>
#include "5libreria.h"
#include <string.h>
namespace N{
	void menu(){

		printf("_________________________________________________");
		printf("\nº\t                MENU                  \tº");
		printf("\nº_______________________________________________º");
		printf("\nº\t1-Crear pila                          \tº");
		printf("\nº\t2-Preguntar si la pila esta vacia     \tº");
		printf("\nº\t3-Preguntar si la pila esta llena     \tº");
		printf("\nº\t4-Insertar dato en la pila            \tº");
		printf("\nº\t5-Sacar dato de la pila               \tº");
		printf("\nº\t6-Mostrar la pila                     \tº");
		printf("\nº\t0-cerrar                              \tº");
		printf("\nº_______________________________________________º");
		printf("\n\nElija una opcion: ");
	}

	TipoPila crear(int& i){
		TipoPila pila;
		pila=NULL;
		i=1;
		return pila;
	}

	int pilavacia(TipoPila pila){
		if(pila==NULL) return 1;
			else return 0;
	}
	int pilallena(TipoPila pila){
		TipoPila aux;
		aux=(TipoNodo *)malloc(sizeof(TipoNodo)); 
		if(aux==NULL)return 1;
		else return 0;
	}
	void sacar(TipoPila& pila,TipoElemento& elem){ /*devuelve por referencia el puntero del dato en la pila y el dato*/
		TipoPila ptr;
		ptr=pila;
		if(pila!=NULL){  /*aqui se pasa a la funcion main toda el dato, toda la estructura con todos las variables...¿?*/
			if(pila->enlace==NULL){
				elem=pila->dato;
				pila=NULL;
			}
			else{ 
				elem=pila->dato;
				pila=pila->enlace;
			}
				free(ptr);
		}
		else elem=NULL;
	}
	void insertar(TipoPila& pila,TipoElemento elem){
		TipoPila ptr;
		ptr=(TipoNodo *)malloc(sizeof(TipoNodo));
		ptr->dato=elem;
		if(pila==NULL){
			ptr->enlace=NULL;
		} 
			else{
			ptr->enlace=pila;
		}
			pila=ptr;
	}

	void mostrar(TipoPila pila){ /*La funcion mostrar esta diseñada para mostrar numeros menores de 10000,
								 si introduces un numero mayor se mostrara "descuadrado"*/
		TipoPila ptr;
		ptr=pila;
		if(pila!=NULL){
			printf("\n________",ptr->dato);
			printf("\nº      º",ptr->dato);
			printf("\nº PILA º",ptr->dato);
			printf("\nº______º",ptr->dato);
			printf("\nº      º",ptr->dato);
			while(ptr->enlace!=NULL){
				if((unsigned)ptr->dato<=9) printf("\nº  %i   º",ptr->dato);
					else if((unsigned)ptr->dato>9 && (unsigned)ptr->dato<100) printf("\nº  %i  º",ptr->dato);
						else if((unsigned)ptr->dato>99 && (unsigned)ptr->dato<1000) printf("\nº %i  º",ptr->dato);
							else if((unsigned)ptr->dato>999 && (unsigned)ptr->dato<10000) printf("\nº %i º",ptr->dato);
								else printf("\nº%i º",ptr->dato);
				ptr=ptr->enlace;
			}
			if((unsigned)ptr->dato<=9) printf("\nº  %i   º",ptr->dato);
					else if((unsigned)ptr->dato>9 && (unsigned)ptr->dato<100) printf("\nº  %i  º",ptr->dato);
						else if((unsigned)ptr->dato>99 && (unsigned)ptr->dato<1000) printf("\nº %i  º",ptr->dato);
							else if((unsigned)ptr->dato>999 && (unsigned)ptr->dato>10000) printf("\nº %i º",ptr->dato);
			printf("\nº______º\n",ptr->dato);
		}
	}
}