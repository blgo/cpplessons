/*Jose Blas Gomez Fuentes 76631979g 2�A electricidad*/
#include <stdio.h>
#include <stdlib.h>
#include "1.1.h"
using namespace N;
int main(){
	int i=0,a,x,y,z;
	do{
	printf("_________________________________");
	printf("\n�\t       MENU      \t�");
	printf("\n�_______________________________�");
	printf("\n�\t1-Menor de 3     \t�");
	printf("\n�\t2-Valor absoluto \t�");
	printf("\n�\t3-factorial      \t�");
	printf("\n�\t4-fibbonaci      \t�");
	printf("\n�\t5-primo          \t�");
	printf("\n�\t6-primeros primos\t�");
	printf("\n�\t0-cerrar         \t�");
	printf("\n�_______________________________�");
	printf("\n\nElija una opcion: ");
	fflush(stdin);
	scanf("%i",&a);
	fflush(stdin);
	switch(a){
		case 1:
			printf ("\n1�: "); scanf("%i",&x);
			fflush(stdin);
			printf ("\n2�: "); scanf("%i",&y);
			fflush(stdin);
			printf ("\n3�: "); scanf("%i",&z);
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