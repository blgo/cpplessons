/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
int main(){
	float v,R,P;
	printf ("\nDame el valor del voltaje: ");
	scanf ("%f",&v);
	if (v>=100){
	printf ("\nDame el valor de la resistencia: ");
	scanf ("%f",&R);
	P=(v*v)/R;
	printf("\n\nLa potencia disipada es %0.2f\n",P);
	}
	else printf("\n\nV es menor a 100 voltios\n");
	return 0;
}
