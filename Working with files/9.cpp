/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
//orden de menor a mayor
#include <stdio.h>
#include <string.h>
#define MAX 20
void ordena(int a[],int);
int main(){
	int a[MAX],max,i;
	printf ("longitud de la cadena:"); 
	scanf ("%i",&max);
	for(i=0;i!=max;i++){
		printf ("introduzca un numero: "); 
		scanf ("%i",&a[i]);
	}
	ordena(a,max);
	for(i=0;i!=max;i++) printf ("%i ",a[i]);
	return 0;
}

void ordena(int a[MAX], int max){
	int i,j,k;
	for(i=0;i!=max;i++){
		for(j=i+1;j!=max;j++){
			if (a[i]<a[j]) k=j;
		}
		a[i]=a[k];
	}
}