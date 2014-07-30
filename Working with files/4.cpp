/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
int main(){
	int n;
	float v,i,r;
	printf ("Elija la forma de la ley de ohm: \n	1:V=I*R\n	2:I=V/R\n	3:R=V/I\n opcion?:");
	scanf ("%i",&n);
	if (n==1) {
		printf("\nV=I*R\nDame R: "); scanf("%f",&r);
		printf("\nDame I: "); scanf("%f",&i);
		printf("\nV=%f\n",i*r);
		}
	else if(n==2){
		printf("\nI=V/R\nDame R: "); scanf("%f",&r);
		printf("\nDame V: "); scanf("%f",&v);
		printf("\nV=%f\n",v/r);
		}
	else if (n==3){
		printf("\nR=V/I\nDame V: "); scanf("%f",&v);
		printf("\nDame I: "); scanf("%f",&i);
		printf("\nV=%f\n",i*r);
		}
	else {
		puts("\nOpcion no encontrada");
		}
	return 0;
}