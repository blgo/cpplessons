/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#ifndef _11_h_
#define _11_h_
namespace N{
typedef char Tpalabra[30];
typedef struct nodo{
	int prior,num_c;
	Tpalabra nombre,ip;
	struct nodo *enlace;
	} TipoNodo;
typedef TipoNodo *LISTA;
void cambiarnum_c(LISTA& lista);
void borrar_a(LISTA& lista);
void num_trabajos(LISTA lista);
void cambiarcategoria(LISTA& lista);
void eliminar(LISTA& lista);
void urgente(LISTA& lista);
void liberar(LISTA& lista);
void mostrar(LISTA ptr);
void menu();
void crearimp(LISTA& ptr);
}
#endif
