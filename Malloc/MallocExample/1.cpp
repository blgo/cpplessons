#include <stdio.h>
#include <stdlib.h>

typedef char Tpalabra[20];
typedef struct {
Tpalabra nombre;
int edad;
int *edadh;
int num_hijos;
} Tpersona;
typedef struct {
int num_personas;
Tpersona *personas; // apuntador al vector dinámico de personas
} Tlista;


void main (){
	Tlista mi_lista;
	int k,i,j=0;
	printf ("Escribe el numero de personas del vector\n");
	scanf ("%d",&mi_lista.num_personas);
	// Ahora se el tamaño inicial del vector. Reservo espacio de memoria
	mi_lista.personas = (Tpersona *) malloc (mi_lista.num_personas*sizeof(Tpersona));
	if (mi_lista.personas == NULL)
	printf ("Operacion incorrecta");
	else{
		// cargo el vector con los datos leidos del teclado
		for (i=0; i<mi_lista.num_personas; i++){
			printf ("Escribe el nombre: ");
			scanf ("%s",mi_lista.personas[i].nombre);
			printf ("\nEscribe la edad: ");
			scanf ("%d",&mi_lista.personas[i].edad);
			printf("\nNumero de Hijos?: "); scanf("%i",&mi_lista.personas[i].num_hijos);
			mi_lista.personas[i].edadh = (int *) malloc (mi_lista.personas[i].num_hijos*sizeof(int));
			if (mi_lista.personas[i].edadh == NULL)
				printf ("Operacion incorrecta");
			else{
				for(k=0;k<mi_lista.personas[i].num_hijos;k++){
					printf("\n Edad de uno de los hijos: "); scanf("%i",&mi_lista.personas[i].edadh[k]);
				}
			}
		}
		
		do{
			printf("Anadir nuevo? SI (1) NO (2): "); fflush(stdin); scanf("%i",&j);
			mi_lista.personas = (Tpersona *)realloc(mi_lista.personas,mi_lista.num_personas++*sizeof(Tpersona));
			if(mi_lista.personas==NULL) puts("NO se puede escribir");
			else {
				i++;
				printf ("\nEscribe el nombre: ");
				scanf ("%s",mi_lista.personas[i].nombre);
				printf ("\nEscribe la edad: ");
				scanf ("%d",&mi_lista.personas[i].edad);

				printf("\nNumero de Hijos?: "); scanf("%i",&mi_lista.personas[i].num_hijos);
				mi_lista.personas[i].edadh = (int *) malloc (mi_lista.personas[i].num_hijos*sizeof(int));
				if (mi_lista.personas[i].edadh == NULL)
					printf ("Operacion incorrecta");
				else{
					for(k=0;k<mi_lista.personas[i].num_hijos;k++){
					printf("\n Edad de uno de los hijos: "); scanf("%i",&mi_lista.personas[i].edadh[k]);
					}
				}
			}
	
		}while(j!=2);
		free(mi_lista.personas);
	}
}