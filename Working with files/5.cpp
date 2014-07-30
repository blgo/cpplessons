/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
int main(){
	int i,u=0;
	float a[9];
	for(i=0;i!=9;i++,u++){
		printf ("\nDame el %io numero:",i+1); 
		scanf("%f",&a[i]);
	}
	for(i=8;i>=0;i--) printf ("%.0f-",a[i]);
	for(i=0;i!=9;i++) if(a[i]>a[u]) u=i;
	printf ("\nEL MAYOR NUMERO ES EL %io: %f",u+1,a[u]);
	return 0;
}