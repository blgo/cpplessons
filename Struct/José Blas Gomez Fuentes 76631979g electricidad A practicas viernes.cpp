/*Autor: José Blas Gomez Fuentes*/
/*Especialidad: electricidad*/
/*Grupo: A*/
/*Practicas: viernes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct destino{
       char ciudad[30], pais[30];
       float punt;
};
struct viajero{
       char nombre[30];
       int modo; /*Donde 1:persona viajando sola, 2:familia con hijos pequeños, 
                3:familia con hijos mayores, 4:pareja sin hijos, 5:viajando
                con grupo*/
       struct destino viaje;
};

void escribir(struct viajero a[],int&);
void elopinion(struct viajero a[],char nombre[],char ciudad[],char pais[]);
void mayorpunt(struct viajero a[],char nombre[]);
void evaluar(struct viajero a[],int);
void listarD(struct viajero a[],int);
void listarP(struct viajero a[],char pais[],int);
int NumVisitas(struct viajero a[],char pais[],int,char ciudad[]);
float mediaPunt(struct viajero a[],char pais[],int,char ciudad[],int n);
void ayuda(struct viajero a[]);

/*////////////////////////////////////////////*//*/////////////////////MAIN///////////////////*//*////////////////////////////////////////////*/
int main ()
{
    struct viajero a[MAX];
    int i=0, pos=0;
    char opcion,nombre[30],pais[30],ciudad[30];
    printf ("Descripcion: Este programa registra clientes,\n             y destinos de una agencia de viajes.\nAutor:       Jose Blas Gomez\n\n");
    do{                                                                                                        
       printf (" //[[[[[[[[[[MENU]]]]]]]]]] ");
       printf ("\n[[- 1.Anadir Nueva Opinion]]");
       printf ("\n[[- 2.Eliminar Opinion    ]]");
       printf ("\n[[- 3.Consultar Cliente   ]]");
       printf ("\n[[- 4.Listar Destinos     ]]");
       printf ("\n[[- 5.Listar por Pais     ]]");
       printf ("\n[[- 6.Evaluar datos       ]]");
       printf ("\n[[- 7.Ayuda               ]]");
       printf ("\n[[- 8.Salir               ]]");
       printf ("\n [[[[[[[[[[[[]]]]]]]]]]]]//");
       fflush (stdin);
       printf ("\n\nElija una opcion y pulse 'enter': "); scanf("%c",&opcion);
       switch (opcion)
              {
              case '1': escribir(a,pos); break;
              case '2': printf ("\n***INTRODUCE LOS DATOS DE BUSQUEDA***");
                        fflush (stdin);
                        printf ("\nNombre: "); gets(nombre);
                        fflush (stdin);
                        printf ("Ciudad: "); gets(ciudad);
                        fflush (stdin);
                        printf ("Pais: "); gets(pais);
                        elopinion(a,nombre,ciudad,pais);
                        break;
              case '3': fflush (stdin);
                        printf ("\n***INTRODUCE LOS DATOS DE BUSQUEDA***");
                        printf ("\nNombre: "); gets(nombre); 
                        mayorpunt(a,nombre);
                        break;
              case '4': listarD(a,pos); break;
              case '5': printf ("\n***INTRODUCE LOS DATOS DE BUSQUEDA***");
                        fflush (stdin);
                        printf ("\nPais: "); gets(pais);
                        listarP(a,pais,pos);
                        break;
              case '6': evaluar(a,pos); break;
              case '7': ayuda(a); break;
              case '8': i++; break;
              default: printf("opcion incorrecta!\n"); 
                       system ("pause"); 
                       opcion=0;
                       system ("cls"); 
                       break;
              }
    }while(i!=1);
    return 0;
}
/*////////////////////////////////////////////*//*////////////////////////////////////////////*//*////////////////////////////////////////////*/

void escribir(struct viajero a[],int& pos) /*Esta funcion pide los datos de un cliente y los guarda en memoria*/
{                                          /*La VARIABLE por referencia "pos" sirbe para que la proxima vez que guardes un dato, se guarde en ela siguiente posicion*/
     printf ("\n***INTRODUCE LOS DATOS***\n");
     fflush (stdin);
     printf ("Nombre: "); gets(a[pos].nombre);
     do{
            fflush (stdin);
            printf ("Modo(pulse 6 para ver intrucciones): "); scanf("%i",&a[pos].modo);
                   if (a[pos].modo==6){
                      
                      printf ("(1):persona viajando sola\n(2):familia con hijos pequeños\n(3):familia con hijos mayores\n(4):pareja sin hijos\n(5):viajando con grupo");                  
                      fflush (stdin);
                      printf ("\nModo: "); scanf("%i",&a[pos].modo);
                      }
     }while(a[pos].modo<=0 || a[pos].modo>5);
     fflush (stdin);
     printf ("ciudad: "); gets(a[pos].viaje.ciudad);
     fflush (stdin);
     printf ("pais: "); gets(a[pos].viaje.pais);   
     do{
        fflush (stdin);
        printf ("Puntuacion(1-10): "); scanf("%f",&a[pos].viaje.punt);
     }while(a[pos].viaje.punt<=0 || a[pos].viaje.punt>10);
     pos++;
     system ("cls");
}

void elopinion(struct viajero a[],char nombre[],char ciudad[],char pais[])/*elimina una posicion del array copiando en él un valor nulo*/
{
     int i;
     for (i=0;i<=MAX;i++) {
                          if(strcmp(nombre,a[i].nombre)==0)
                          if(strcmp(pais,a[i].viaje.pais)==0)
                          if(strcmp(ciudad,a[i].viaje.ciudad)==0)
                          {
                          strcpy(a[i].nombre,"");
                          strcpy(a[i].viaje.ciudad,"");
                          strcpy(a[i].viaje.pais,"");
                          a[i].viaje.punt=0;
                          a[i].modo=0;
                          }
     }                    
     system ("cls");                                                                                                                                                                    
}

void mayorpunt(struct viajero a[],char nombre[]) /*dos bucles; uno haya la mayor puntuacion y el segundo escribe la ciudad (o ciudades) a la que corresponde esa puntuacion*/
{
     int i;
     float nmayor=0;
     for (i=0;i<=MAX;i++) if(strcmp(nombre,a[i].nombre)==0) if(a[i].viaje.punt>nmayor) nmayor=a[i].viaje.punt;
     for (i=0;i<=MAX;i++) if(strcmp(nombre,a[i].nombre)==0) if(a[i].viaje.punt==nmayor) printf ("\n\n!!!Destino mejor puntuado para el Sr/Sra %s!!!\nCiudad:%s \nPais:%s\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n",nombre,a[i].viaje.ciudad,a[i].viaje.pais);
system ("pause");
system ("cls");                                                     
}
void evaluar (struct viajero a[],int pos) /*esta funcion la he echo por cuenta propia para comprovar que todos los datos escritos y eliminados se escriben y eliminan realmente*/
{
     int i;
     for (i=0;i<pos;i++){
       printf ("Nombre:%s \nModo:%i \nCiudad:%s \nPais:%s \nPuntuacion:%.2f",a[i].nombre,a[i].modo,a[i].viaje.ciudad,a[i].viaje.pais,a[i].viaje.punt);
       printf ("\n*****************************\n");
       }
       system ("pause");
       system ("cls");
}

void listarD(struct viajero a[],int pos) /*Bucles anidados; uno cuenta los diferentes modos de viajar, a los que les corresponde un numero "int"
                                           el otro escribe todos los paises del array que tienen ese modo de viajar */
{
     int i,j;
     printf("\n\n//////VIAJES SEGUN EL MODO DE VIAJAR//////");
     for (j=0;j!=6;j++){
         switch (j){         
         case 1: printf("\n\n   Persona viajando sola:"); break; 
         case 2: printf("\n\n   Familia con hijos pequenos:"); break; 
         case 3: printf("\n\n   Familia con hijos mayores:"); break; 
         case 4: printf("\n\n   Pareja sin hijos:"); break; 
         case 5: printf("\n\n   Viajando con grupo:"); break; 
         }
         for (i=0;i<pos;i++){
             if(a[i].modo==j) printf("\n   - %s, %s",a[i].viaje.ciudad,a[i].viaje.pais);
             }                   
     }
     printf("\n//////////////////////////////////////////\n");
     system ("pause"); 
     system ("cls");
}

void listarP(struct viajero a[],char pais[],int pos)/*Esta funcion busca el pais introducido y utiliza otras dos funciones de paso por valor "int NumVisitas" y "float mediaPunt"*/
{
     int i,n;
     float M;
     printf ("\n**Ciudades de %s visitadas por nuestros clientes**",pais);
     for (i=0;i<pos;i++){
         if(strcmp(pais,a[i].viaje.pais)==0) {
                                             n=NumVisitas(a,pais,pos,a[i].viaje.ciudad);
                                             M=mediaPunt(a,pais,pos,a[i].viaje.ciudad,n);
                                             printf ("\n-%s \nNumero de Visitantes: %i \nLa puntuacion media del destino es:%.2f\n",a[i].viaje.ciudad,n,M);
                                             }
         }
system ("pause"); 
system ("cls");
}

int NumVisitas(struct viajero a[],char pais[],int pos,char ciudad[]) /*Con un bucle "for" y un contador "n" calcula cuantas veces aparece una ciudad en un pais
*/
{
    int i,n=0;
    for (i=0;i<=MAX;i++){
         if(strcmp(pais,a[i].viaje.pais)==0) if(strcmp(ciudad,a[i].viaje.ciudad)==0) n++;
         }
return n;
}

float mediaPunt(struct viajero a[],char pais[],int pos,char ciudad[],int n) /*Utiliza la función "int NumVisitas" u un acomulador "suma" para calcular la media*/
{
    int i;
    float M,suma=0;
    for (i=0;i<=MAX;i++){
         if(strcmp(pais,a[i].viaje.pais)==0) if(strcmp(ciudad,a[i].viaje.ciudad)==0) suma=suma+a[i].viaje.punt;
         }
    M=suma/(n*1.0);     
    return M;
}

void ayuda(struct viajero a[])/*Descripción de las diferentes opciones*/
{

printf("\n\n*******************************Opciones*******************************\n");
printf("1) Anadir Nueva Opinion. En esta opcion se leeran los datos\n");
printf("   de un cliente y su opinion de una ciudad concreta y se \n");
printf("   almacenaran todos esos datos en el array.\n");
printf("2) Eliminar Opinion. En esta opcion se pedira el nombre de un\n");
printf("   cliente, el nombre de una ciudad y el pais (tenga en cuenta\n");
printf("   que varios paises pueden tener una cuidad con el mismo nombre)\n");
printf("   y se eliminara del array los datos.\n");
printf("3) Consultar Cliente. Dado el nombre de un cliente mostrar por \n");
printf("   pantalla el destino (ciudad y país) al que le ha dado mayor \n");
printf("   puntuacion.\n");
printf("4) Listar Destinos. Mostrar un listado de los destinos visitados\n");
printf("   segun el modo de viajar.\n");
printf("5) Listar por Pais. Dado el nombre de un pais, mostrar un listado\n");
printf("   con todas las ciudades que han sido visitadas de ese pais, por\n");
printf("   cuántos clientes ha sido elegida cada una de ellas y la puntuacion\n");
printf("   media obtenida por cada ciudad.\n");
printf("6) Evaluar datos. Muestra en pantalla todos los datos almacenados.\n");
printf("7) Muestra la descripcion de cada opcion del menu.\n");
printf("8) Cierra la Aplicacion (todos los datos almacenados se perderan).\n");
printf("   **********************************************************************\n\n");

system ("pause"); 
system ("cls");
}







