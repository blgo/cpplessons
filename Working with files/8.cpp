/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include <stdio.h>
#define MAXi 5
#define MAXj 5
void leermatriz(float M[][MAXj],int&,int&);
void escribirmatriz(float M[][MAXj],int,int);
void suma(float M[][MAXj],float M2[][MAXj],float M3[][MAXj],int,int);
void multiplicacion(float M[][MAXj],float M2[][MAXj],float M3[][MAXj],int,int,int);

int main(){
	int ni,nj,ni2,nj2;
	float M[MAXi][MAXj],M2[MAXi][MAXj],M3[MAXi][MAXj];
	leermatriz(M,ni,nj);
	escribirmatriz(M,ni,nj);
	printf ("\nMATRIZ *M2*\n");
	leermatriz(M2,ni2,nj2);
	if ((ni==ni2)&&(nj==nj2)) suma(M,M2,M3,ni,nj);
	else printf ("\nERROR!! \nTienen diferente rango, no se pueden sumar");
	printf ("\nMATRIZ SUMA *M3*\n");
	escribirmatriz(M3,ni,nj);
	if (nj==ni2) multiplicacion(M,M2,M3,ni,nj,nj2);
	else printf ("\nERROR!! \nNo se cumple la condicion *columnas de M1 = filas M2*");
	printf ("\nMATRIZ MULTIPLICACION *M3*\n");
	escribirmatriz(M3,ni,nj2);
	return 0;
}

//primero introduciremos los valores de la matriz usando bucles anidados
//i son filas, j son columnas
void leermatriz(float M[MAXi][MAXj],int &ni,int &nj){
	int i,j;
	printf ("\nNo de filas: "); 
	scanf("%i",&ni); 
	printf ("No de columnas: ");
	scanf("%i",&nj);
	for (i=0;i!=ni;i++){
		for(j=0;j!=nj;j++){
			printf ("\n%ix%i:  ",i+1,j+1);
			scanf ("%f",&M[i][j]);
		}
	}
}


void escribirmatriz(float M[MAXi][MAXj],int ni,int nj){
	int i,j;
	for (i=0;i!=ni;i++){
		printf ("|");
		for(j=0;j!=nj;j++){
			printf("%.2f ",M[i][j]);
		}
		printf ("|\n");
	}
}

void suma(float M1[MAXi][MAXj],float M2[MAXi][MAXj],float M3[MAXi][MAXj],int ni,int nj){
	int i,j;
	for (i=0;i!=ni;i++){
		for(j=0;j!=nj;j++){
			M3[i][j]=M1[i][j]+M2[i][j];
		}
	}
}

void multiplicacion(float M[MAXi][MAXj],float M2[MAXi][MAXj],float M3[MAXi][MAXj],int ni,int nj,int nj2){
	int i,j,k;
	for (i=0;i!=ni;i++){
		for(j=0;j!=nj2;j++){
			M3[i][j]=0;
			for(k=0;k!=nj;k++){
				M3[i][j]=M3[i][j]+M[i][k]*M2[k][j];
			}
		}
	}
}