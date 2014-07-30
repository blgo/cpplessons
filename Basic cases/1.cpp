/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#include <stdlib.h>
#include "1.1.h"
using namespace N;
int main(){
	int i=0,a,x,y,z;
	do{
	printf("_________________________________");
	printf("\nº\t       MENU      \tº");
	printf("\nº_______________________________º");
	printf("\nº\t1-Menor de 3     \tº");
	printf("\nº\t2-Valor absoluto \tº");
	printf("\nº\t3-factorial      \tº");
	printf("\nº\t4-fibbonaci      \tº");
	printf("\nº\t5-primo          \tº");
	printf("\nº\t6-primeros primos\tº");
	printf("\nº\t0-cerrar         \tº");
	printf("\nº_______________________________º");
	printf("\n\nElija una opcion: ");
	fflush(stdin);
	scanf("%i",&a);
	fflush(stdin);
	switch(a){
		case 1:
			printf ("\n1º: "); scanf("%i",&x);
			fflush(stdin);
			printf ("\n2º: "); scanf("%i",&y);
			fflush(stdin);
			printf ("\n3º: "); scanf("%i",&z);
			printf("\n-Numero Menor: %i",menor(x,y,z));
			system ("pause");
			system ("cls");
			break;	
		case 2:
			printf("Dame 1 numero: "); scanf("%i",&x);
			printf("%i",valorabsoluto(x));
			system ("pause");
			system ("cls");
			break;
		case 3: 
			printf("Dame 1 numero: "); scanf("%i",&x);
			printf("%i",factorial(x)); 
			system ("pause");
			system ("cls");
			break;
		case 4: 
			printf("Dame 1 numero: "); scanf("%i",&x);
			printf("%i",fibo(x)); 
			system ("pause");
			system ("cls");
			break;
		case 5:
			printf("Dame 1 numero: "); scanf("%i",&x);
			printf("%i",primo(x)); 
			system ("pause");
			system ("cls");
			break;
		case 6:
			printf("Dame 1 numero: "); scanf("%i",&x);
			primerosprimos(x); 
			system ("pause");
			system ("cls");
			break;
		default:
			i=1; 
			break;
		}
	}while(i!=1);
	return 0;
}