/*Jose Blas Gomez Fuentes 76631979g 2�A electricidad*/
#include <stdio.h>
#include <stdlib.h>
#include "5libreria.h"
#include <string.h>
namespace N{
	void menu(){

		printf("_________________________________________________");
		printf("\n�\t                MENU                  \t�");
		printf("\n�_______________________________________________�");
		printf("\n�\t1-Crear pila                          \t�");
		printf("\n�\t2-Preguntar si la pila esta vacia     \t�");
		printf("\n�\t3-Preguntar si la pila esta llena     \t�");
		printf("\n�\t4-Insertar dato en la pila            \t�");
		printf("\n�\t5-Sacar dato de la pila               \t�");
		printf("\n�\t6-Mostrar la pila                     \t�");
		printf("\n�\t0-cerrar                              \t�");
		printf("\n�_______________________________________________�");
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
		if(pila!=NULL){  /*aqui se pasa a la funcion main toda el dato, toda la estructura con todos las variables...�?*/
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

	void mostrar(TipoPila pila){ /*La funcion mostrar esta dise�ada para mostrar numeros menores de 10000,
								 si introduces un numero mayor se mostrara "descuadrado"*/
		TipoPila ptr;
		ptr=pila;
		if(pila!=NULL){
			printf("\n________",ptr->dato);
			printf("\n�      �",ptr->dato);
			printf("\n� PILA �",ptr->dato);
			printf("\n�______�",ptr->dato);
			printf("\n�      �",ptr->dato);
			while(ptr->enlace!=NULL){
				if((unsigned)ptr->dato<=9) printf("\n�  %i   �",ptr->dato);
					else if((unsigned)ptr->dato>9 && (unsigned)ptr->dato<100) printf("\n�  %i  �",ptr->dato);
						else if((unsigned)ptr->dato>99 && (unsigned)ptr->dato<1000) printf("\n� %i  �",ptr->dato);
							else if((unsigned)ptr->dato>999 && (unsigned)ptr->dato<10000) printf("\n� %i �",ptr->dato);
								else printf("\n�%i �",ptr->dato);
				ptr=ptr->enlace;
			}
			if((unsigned)ptr->dato<=9) printf("\n�  %i   �",ptr->dato);
					else if((unsigned)ptr->dato>9 && (unsigned)ptr->dato<100) printf("\n�  %i  �",ptr->dato);
						else if((unsigned)ptr->dato>99 && (unsigned)ptr->dato<1000) printf("\n� %i  �",ptr->dato);
							else if((unsigned)ptr->dato>999 && (unsigned)ptr->dato>10000) printf("\n� %i �",ptr->dato);
			printf("\n�______�\n",ptr->dato);
		}
	}
}