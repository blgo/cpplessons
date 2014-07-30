/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#include "1.1.h"
#include <stdio.h>
namespace N{
	int menor(int x,int y,int z){
		if(x<y){ 
			if(x<z) return x;
		}
		if(y<z) return y;
		return z;
	}
	int valorabsoluto(int x){
		if(x<0) return -x;
		else return x;
	}
	int factorial(int x){
		int i,k=1;
		for(i=1;i!=x+1;i++){
			k=k*i;
		}
		return k;
	}
	int fibo(int n){
		int i,x=0,y=1,z=0;
		for(i=2;i!=n+1;i++){
			z=y;
			y=x+y;
			x=z;
		}
		return y;
	}
	int primo(int n){
		int i;
		if (n==1) return 1;
		if (n==2) return 1;
		if (n==3) return 1;
		for (i=2;i!=n/2+1;i++){
		      if(n%i==0) return 0;
		}
 		return 1;
	}
	void primerosprimos(int n){
		int i,k;
		printf("\nPrimeros primos: ");
		for(i=1,k=0;k!=n+1;i++){
			if(primo(i)==1) {
			printf("%i ",i);
			k++;
			}
		}
	}
}