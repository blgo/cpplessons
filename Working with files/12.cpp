/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct contacto{
	int ntelefono;
	char nombre[MAX],dir[MAX];
};

void aentrada(struct contacto a[],int);
void bentrada();
void edato(struct contacto a[]);
void mdato(struct contacto a[]);
void volcarmemoria(struct contacto a[],int);
void B2(int&,int);


int main(){
	FILE *fichero;
	struct contacto a[MAX];
	int i=1,j=0;
	char opcion;
	do{
		printf ("//[[[[[[[[[[[[[[[MENU]]]]]]]]]]]]]]] ");
		printf ("\n[[- 1.Agregar entrada nueva        ]]");
        printf ("\n[[- 2.Consultar entrada            ]]");
        printf ("\n[[- 3.Modificar dato               ]]");
        printf ("\n[[- 4.Borrar entrada               ]]");
        printf ("\n[[- 0.Salir                        ]]");
        printf ("\n [[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]//");
        fflush (stdin);
        printf ("\n\nElija una opcion y pulse 'enter': "); scanf("%c",&opcion);
		switch (opcion){
			case '1': aentrada(a,j); j++; break;
			case '2': bentrada(); break;
			case '3': mdato(a); break;
			case '4': edato(a); break;
			case '0': printf("CERRAR\n"); i=0; break;
			default: printf("opcion incorrecta!\n"); 
                     system ("pause");
                     system ("cls"); 
                     break; 
		}

	}while(i!=0);
	return 0;
}

void aentrada(struct contacto a[MAX], int j){
	FILE *fichero;
	do{
		fflush(stdin);
		printf ("Telefono: "); scanf("%i",&a[j].ntelefono);
		if(0>a[j].ntelefono || a[j].ntelefono>999999999) printf("Numero incorrecto;\nEl numero debe escribirse de la forma AAABBBCCC");
	}while(0>a[j].ntelefono || a[j].ntelefono>999999999);
	fflush(stdin);
	printf ("Nombre:"); gets(a[j].nombre);
	printf ("Direccion:"); gets(a[j].dir);
	fichero=fopen("listin.txt","at");
	fprintf(fichero,"%i\n%s\n%s\n",a[j].ntelefono,a[j].nombre,a[j].dir);
	fclose(fichero);
	system("cls");
}

void bentrada(){
	FILE *fichero;
	int telefono,telefono2=0,k;
	char aux[MAX],aux2[MAX];
	fflush(stdin);
	printf("Dame el telefono para realizar la busqueda: "); scanf("%i",&telefono);
	fflush(stdin);
	fichero=fopen("listin.txt","rt");
	for(k=0;telefono2!=telefono && feof(fichero)==0;k++){
		fscanf(fichero,"%i",&telefono2);
		fgets(aux,MAX,fichero);
		fgets(aux,MAX,fichero);
		fgets(aux2,MAX,fichero);
		if(telefono2==telefono){
			printf("\n*************ENCONTRADO*************");
			printf("\nTelefono: %i",telefono2);
			printf("\nNombre: %s",aux);
			printf("Direccion: %s",aux2);
			printf("************************************\n");
		}
		else printf(".");
	}
	system ("pause");
	fclose(fichero);
	system("cls");
}

void edato(struct contacto a[]){
	FILE *fichero;
	int telefono,k,R;
	char aux[MAX];
	fflush(stdin);
	printf("Dame el telefono para realizar la busqueda: "); scanf("%i",&telefono);
	fflush(stdin);
	fichero=fopen("listin.txt","rt");
	for(k=0;feof(fichero)==0;k++){
		fscanf(fichero,"%i",&a[k].ntelefono);
		fgets(aux,MAX,fichero);
		fgets(a[k].nombre,MAX,fichero);
		fgets(a[k].dir,MAX,fichero);
		if(a[k].ntelefono==telefono) k--;
		else printf(".");
	}
	printf("\nTodos los datos menos el elegido han sido escritos en la estructura\n");
	fclose(fichero);
	B2(R,telefono);
	if (R==1) volcarmemoria(a,k);
	else {
		printf ("\nNUMERO NO ENCONTRADO, no se ha modificado el archivo\n");
		system("pause");
	}
	system("cls");
}

void mdato(struct contacto a[]){
	FILE *fichero;
	int telefono,telefono2=1,k,R;
	char aux[MAX],aux2[MAX];
	fflush(stdin);
	printf("Dame el telefono para realizar la busqueda: "); scanf("%i",&telefono);
	fflush(stdin);
	fichero=fopen("listin.txt","rt");
	for(k=0;feof(fichero)==0;k++){
		fscanf(fichero,"%i",&telefono2);
		fgets(aux,MAX,fichero);
		fgets(aux,MAX,fichero);
		fgets(aux2,MAX,fichero);
		if(telefono2==telefono){
			printf("\nMODIFICANDO LA ENTRADA\n-%i\n-%s-%s\n",telefono2,aux,aux2);
			fflush(stdin);
			printf("\nNuevo numero: "); scanf("%i",&a[k].ntelefono);
			fflush(stdin);
			printf("Nuevo nombre: "); gets(a[k].nombre); strcat(a[k].nombre,"\n");
			printf("Nueva direccion: "); gets(a[k].dir); strcat(a[k].dir,"\n");
			fflush(stdin);
		}
		else {
			a[k].ntelefono=telefono2;
			strcpy(a[k].nombre,aux);
			strcpy(a[k].dir,aux2);
			printf(".");
		}
		
	}
	printf("\nTodos los datos, incluyendo el modificado, han sido escritos en la estructura\n");
	fclose(fichero);
	B2(R,telefono);
	if (R==1) volcarmemoria(a,k);
	else {
		printf ("\nNUMERO NO ENCONTRADO, no se ha modificado el archivo\n");
		system("pause");
	}
	system("cls");
}
void volcarmemoria(struct contacto a[], int k){
	FILE *fichero;
	int i;
	fichero=fopen("auxiliar.txt","wt");
	for(i=0;i!=k-1;i++){
		fprintf(fichero,"%i\n%s%s",a[i].ntelefono,a[i].nombre,a[i].dir);
	}
	fclose(fichero);
	remove("listin.txt");
	rename("auxiliar.txt","listin.txt");
	printf("\nlistin modificado!!\n");
	system ("pause");
}

void B2(int& i,int telefono){
	i=0;
	FILE *fichero;
	int telefono2=0,k;
	char aux[MAX],aux2[MAX];
	fflush(stdin);
	fichero=fopen("listin.txt","rt");
	for(k=0;telefono2!=telefono && feof(fichero)==0;k++){
		fscanf(fichero,"%i",&telefono2);
		fgets(aux,MAX,fichero);
		fgets(aux,MAX,fichero);
		fgets(aux2,MAX,fichero);
		if(telefono2==telefono) i=1;
	}
	fclose(fichero);
}