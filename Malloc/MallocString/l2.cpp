/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#include <stdlib.h>
#include "l2.h"
#include <string.h>
namespace N{
	void menu(){
		printf("_________________________________________________");
		printf("\nº\t                MENU                  \tº");
		printf("\nº_______________________________________________º");
		printf("\nº\t1-Introducir archivo a la cola        \tº");
		printf("\nº\t2-Introducir archivo urgente        \tº");
		printf("\nº\t3-Mostrar archivos en cola            \tº");
		printf("\nº\t4-Realizar impresion                  \tº");
		printf("\nº\t5-Numero de trabajos con igual IP     \tº");
		printf("\nº\t6-Cambiar categoria de una impresion  \tº");
		printf("\nº\t7-Borrar archivo en cola              \tº");
		printf("\nº\t8-Incrementar/Decramentar No de copias\tº");
		printf("\nº\t9-Eliminar toda la cola de impresion  \tº");
		printf("\nº\t0-cerrar                              \tº");
		printf("\nº_______________________________________________º");
		printf("\n\nElija una opcion: ");
		}

	void crearimp(LISTA& lista){
		LISTA ptr,nodo;
		ptr=lista;

		///////////////////////////Escribiendo el NODO////////////////////////////////////////////////////////
		nodo = (TipoNodo *)malloc(sizeof(TipoNodo));
		printf("\nDame el nombre del archivo: ");  gets(nodo->nombre); fflush(stdin);
		do{
			fflush(stdin);
			printf("\nDame el nivel de prioridad: Pulse (3) para ayuda "); scanf("%i",&nodo->prior);
			if(nodo->prior==3) printf("2// para maxima prioridad\n1// para prioridad normal\n0// para prioridad baja\n");
			if(nodo->prior<0 && nodo->prior>2) printf("Opcion incorrecta");
		}while(nodo->prior!=0 && nodo->prior!=1 && nodo->prior!=2);
		do{
			printf("\nDame la IP (xxx.xxx.xxx.xxx): "); scanf("%s",nodo->ip); fflush(stdin);
			nodo->ip[15]='\0';
			if(nodo->ip[3]!='.' || nodo->ip[7]!='.' || nodo->ip[11]!='.') printf ("\n IP mal introducida\n");
		}while(nodo->ip[3]!='.' || nodo->ip[7]!='.' || nodo->ip[11]!='.');
		do{
			printf("\nDame el numero de copias: "); scanf("%i",&nodo->num_c); fflush(stdin); 
			if (nodo->num_c<=0) printf("\n No de copias incorrecto\n");
		}while(nodo->num_c<=0);
		nodo->enlace=NULL;
		//////////////////////////////////////////////////////////////////////////////////////////////////////

		if(ptr == NULL || ptr->prior < nodo->prior){
            nodo->enlace = lista;
			lista=nodo;
		}
		else {
			while(ptr->enlace!=NULL && ptr->enlace->prior >= nodo->prior) ptr=ptr->enlace;
			nodo->enlace=ptr->enlace;
			ptr->enlace=nodo;
		}
	}
	void mostrar(LISTA lista){
		LISTA ptr;
		ptr=lista;
		int i;
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else {
			while(ptr!=NULL){
				printf("\n__________________________________________________");
				printf("\nº    Nombre: %s",ptr->nombre);for (i=0;i!=(49-(strlen(ptr->nombre)+13));i++) printf(" "); printf("º");
				printf("\nº    IP: %s",ptr->ip);for (i=0;i!=(30-14+9);i++) printf(" "); printf("º");
				printf("\nº    Numero de copias: %i",ptr->num_c); for(i=0;i!=(49-24);i++)  printf(" "); printf("º");
				printf("\nº    Prioridad: %i",ptr->prior);for (i=0;i!=(49-17);i++) printf(" "); printf("º");
				printf("\nº________________________________________________º\n");
				printf("%i\n",ptr);
				ptr=ptr->enlace;
			}
		}	
	} 

	void urgente(LISTA& lista){
		LISTA ptr,nodo;
		ptr=lista;

		///////////////////////////Escribiendo el NODO////////////////////////////////////////////////////////
		nodo = (TipoNodo *)malloc(sizeof(TipoNodo));
		printf("\nDame el nombre del archivo: ");  gets(nodo->nombre); fflush(stdin);
		do{
			fflush(stdin);
			printf("\nDame el nivel de prioridad: Pulse (3) para ayuda "); scanf("%i",&nodo->prior);
			if(nodo->prior==3) printf("2// para maxima prioridad\n1// para prioridad normal\n0// para prioridad baja\n");
			if(nodo->prior<0 && nodo->prior>2) printf("Opcion incorrecta");
		}while(nodo->prior!=0 && nodo->prior!=1 && nodo->prior!=2);
		do{
			printf("\nDame la IP (xxx.xxx.xxx.xxx): "); scanf("%s",nodo->ip); fflush(stdin);
			nodo->ip[15]='\0';
			if(nodo->ip[3]!='.' || nodo->ip[7]!='.' || nodo->ip[11]!='.') printf ("\n IP mal introducida\n");
		}while(nodo->ip[3]!='.' || nodo->ip[7]!='.' || nodo->ip[11]!='.');
		do{
			printf("\nDame el numero de copias: "); scanf("%i",&nodo->num_c); fflush(stdin); 
			if (nodo->num_c<=0) printf("\n No de copias incorrecto\n");
		}while(nodo->num_c<=0);
		nodo->enlace=NULL;
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if(ptr == NULL || ptr->prior <= nodo->prior){
            nodo->enlace = lista;
			lista=nodo;
		}
		else {
			while(ptr->enlace!=NULL && ptr->enlace->prior > nodo->prior) ptr=ptr->enlace;
			nodo->enlace=ptr->enlace;
			ptr->enlace=nodo;
		}

	}

	void eliminar(LISTA& lista){
		LISTA ptr;
		ptr=lista;
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else{
			lista=lista->enlace;
			free(ptr);
			
		}
	}

	void num_trabajos(LISTA lista){
		LISTA ptr;
		ptr=lista;
		int i=0;
		char ip_aux[16];
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else{
			do{
				printf("\nDame la IP (xxx.xxx.xxx.xxx): "); scanf("%s",ip_aux); fflush(stdin);
				ip_aux[15]='\0';
				if(ip_aux[3]!='.' || ip_aux[7]!='.' || ip_aux[11]!='.') printf ("\n IP mal introducida\n");
			}while(ip_aux[3]!='.' || ip_aux[7]!='.' || ip_aux[11]!='.');
			do{
				if(strcmp(ip_aux,ptr->ip)==0) i++;
				ptr=ptr->enlace;
			}while(ptr!=NULL);
		}
	}

	void cambiarcategoria(LISTA& lista){
		//esta funcion tiene 3 partes, lectura, busqueda, eliminacion y por ultimo introduccion en la lista ordenada
		LISTA ptr,nodo,anterior;
		int i=0;
		anterior = lista;
		ptr=lista;
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else{
			nodo = (TipoNodo *)malloc(sizeof(TipoNodo));
			printf("\nDame el nombre: "); fflush(stdin); gets(nodo->nombre); fflush(stdin);
			do{
			printf("\nDame la IP (xxx.xxx.xxx.xxx): "); scanf("%s",nodo->ip); fflush(stdin);
				nodo->ip[15]='\0';
				if(nodo->ip[3]!='.' || nodo->ip[7]!='.' || nodo->ip[11]!='.') printf ("\n IP mal introducida\n");
			}while(nodo->ip[3]!='.' || nodo->ip[7]!='.' || nodo->ip[11]!='.');
			/////////////////////////////////algoritmo de busqueda///////////////////////////////////////////////////////
			while(i!=1 && ptr->enlace!=NULL){
				if(strcmp(nodo->ip,ptr->ip)==0 && strcmp(nodo->nombre,ptr->nombre)==0) i=1;
				else{ 
					anterior=ptr;
					ptr=ptr->enlace;
				}
			}
			nodo->num_c=ptr->num_c;
			printf("\n**%i  %s  %s**\n",ptr->enlace,ptr->nombre,ptr->ip); system("pause");
		
			if(strcmp(ptr->nombre,nodo->nombre)==0 && strcmp(ptr->ip,nodo->ip)==0){
				printf ("\nLo hemos encontrado!!!\n");
				do{
					fflush(stdin);
					printf("\nDame el nivel de prioridad nuevo: Pulse (3) para ayuda "); fflush(stdin); scanf("%i",&nodo->prior);
					if(nodo->prior==3) printf("2// para maxima prioridad\n1// para prioridad normal\n0// para prioridad baja\n");
					if(nodo->prior<0 && nodo->prior>2) printf("\n Opcion incorrecta\n");
					if(nodo->prior==ptr->prior) printf("\n Has introducido la misma prioridad que ya habia!!\n");
				}while(nodo->prior!=0 &&nodo->prior!=1 && nodo->prior!=2 || nodo->prior==ptr->prior);
	
			//////////////////////////algoritmo de eliminacion //////////////////////////////////////////////////////
				if(ptr==lista){
					eliminar(lista);
				}
				else{
					anterior->enlace = ptr->enlace;
					free(ptr);
				}

				ptr=lista; //reiniciamos la lista a su primera posicion
				printf("\nColocando el nodo modificado en su lugar...\n");
			//////////////////////algoritmo de introduccion de un nodo ordenado ////////////////////////////////////
				if(ptr == NULL || ptr->prior < nodo->prior){
				    nodo->enlace = lista;
					lista=nodo;
				}
				else {
					while(ptr->enlace!=NULL && ptr->enlace->prior >= nodo->prior) ptr=ptr->enlace;
				nodo->enlace=ptr->enlace;
				ptr->enlace=nodo;
				}
			printf("\nTrabajo finalizado, cambio de prioridad realizado :-)\n");
			}
		
		
		else printf("\nNo se encontro el fichero buscado :-(\n");//else correspondiente a if(strcmp(ptr->nombre,nodo->nombre)==0 && strcmp(ptr->ip,nodo->nombre)==0)
		}
	}
	

	void borrar_a(LISTA& lista){
		//esta funcion tiene 3 partes, lectura, busqueda y eliminacion
		LISTA ptr,anterior;
		int i=0;
		anterior = lista;
		ptr=lista;
		char ipaux[30],nombreaux[30];
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else{
			printf("\nDame el nombre del archivo: ");  gets(nombreaux); fflush(stdin);
			do{
				printf("\nDame la IP (xxx.xxx.xxx.xxx): "); scanf("%s",ipaux); fflush(stdin);
				ipaux[15]='\0';
				if(ipaux[3]!='.' || ipaux[7]!='.' || ipaux[11]!='.') printf ("\n IP mal introducida\n");
			}while(ipaux[3]!='.' || ipaux[7]!='.' || ipaux[11]!='.');
		///////////////////////////algoritmo de busqueda///////////////////////////////
				while(i!=1 && ptr->enlace!=NULL){
					if(strcmp(ipaux,ptr->ip)==0 && strcmp(nombreaux,ptr->nombre)==0) i=1;
					else{ 
						anterior=ptr;
						ptr=ptr->enlace;
					}
				}
				if(strcmp(ptr->nombre,nombreaux)==0 && strcmp(ptr->ip,ipaux)==0){
					printf ("\nLo hemos encontrado!!!\n");
		///////////////////////////algoritmo de eliminacion////////////////////////////
					if(ptr==lista){
						eliminar(lista);
					}
					else{
						anterior->enlace = ptr->enlace;
						free(ptr);
					}
					printf("\nBorrado completado...\n");
				}
		
			else printf("\nNo se encontro el archivo en la lista\n");
		}
	}
	
	void cambiarnum_c(LISTA& lista){
		LISTA ptr;
		char ipaux[30],nombreaux[30];
		ptr=lista;
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else{
			printf("\nDame el nombre del archivo: ");  gets(nombreaux); fflush(stdin);
			do{
				printf("\nDame la IP (xxx.xxx.xxx.xxx): "); scanf("%s",ipaux); fflush(stdin);
				ipaux[15]='\0';
				if(ipaux[3]!='.' || ipaux[7]!='.' || ipaux[11]!='.') printf ("\n IP mal introducida\n");
			}while(ipaux[3]!='.' || ipaux[7]!='.' || ipaux[11]!='.');

				while( ptr->enlace!= NULL && (strcmp(ptr->enlace->nombre,nombreaux)==0 || strcmp(ptr->enlace->ip,ipaux)==0)){ 
					ptr = ptr->enlace;
				}
				if(strcmp(ptr->nombre,nombreaux)==0 && strcmp(ptr->ip,ipaux)==0){
				printf ("\nLo hemos encontrado!!!\n");
				printf("\nEl numero actual de copias para este archivo es %i",ptr->num_c);
						do{
							printf("\nDame el nuevo numero de copias: "); fflush(stdin); scanf("%i",&ptr->num_c); fflush(stdin); 
							if (ptr->num_c<=0) printf("\n No de copias incorrecto\n");
				}while(ptr->num_c<=0);
				printf("\nModificacion realizada\n");
				}
				else printf("\nNo se encontro el archivo en la lista\n");
		}
	}


	void liberar(LISTA& lista){
		int i,j=0;
		LISTA ptr;
		ptr=lista;
		if(lista==NULL) printf("\n Aun no hay nada en la lista.");
		else{
			while(ptr->enlace!=NULL){
				ptr=ptr->enlace;
				i++;
			}
			for(j=0;j!=i;j++) eliminar(lista); 
			lista=NULL;
			printf("\nToda la lista a sido borrada\n");
		}
	}
}