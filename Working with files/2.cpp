/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
int main(){
	int n,tmp;
	printf ("introduce el digito de 4 cifras: ");
	scanf ("%i", &n);
	if(n>9999||n<1000) printf("\nERROR!!!\n");
	else {
		printf("\nPROVINCIA %i",tmp=n/1000);
		printf("\nTIPO DE OPERACION %i",tmp=(n%1000)/100);
		printf("\nPROVINCIA %i\n",tmp=n%100);
	}
}
