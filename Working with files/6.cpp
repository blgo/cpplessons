/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#define MAX 20
int main(){
	float a[MAX],media,s=0;
	int i,naltos,nbajos;
	for(i=0;i!=MAX;i++){
		printf ("\nIntroduce la %ia estatura: ",i+1);
		scanf("%f",&a[i]);
		s=s+a[i];
	}
	media=s/MAX;
	for(i=0;i!=MAX;i++){
		if (a[i]>media) naltos++;
		else nbajos++;
	}
	printf ("\nHay %i son mas bajos de la media\n%i son mas altos que la media\n%i estan en la media\n",nbajos,naltos,MAX-naltos-nbajos);
	return 0;
}