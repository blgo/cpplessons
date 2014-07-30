/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
int main(){
	int n,i,u;
	printf ("\nDame el numero: ");
	scanf("%i",&n);
	for(i=1;i<=n;i++){
		for(u=1;u<=i;u++) printf ("%i",i);
		printf ("\n");
	}
	return 0;
}