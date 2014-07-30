/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#define a 9.78
int main(){
	float s;
	int t,i=1;
	printf ("Dame el tiempo de caida libre: "); 
	scanf("%i",&t);
	while(i<=t){
		s=(1.0/2)*a*i*i;
		printf("Ha recorrido %0.2f metros en el instante t=%i\n",s,i);
		i++;
	}
}
