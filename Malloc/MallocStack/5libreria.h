/*Jose Blas Gomez Fuentes 76631979g 2ºA electricidad*/
#ifndef _11_h_
#define _11_h_
namespace N{
	typedef int TipoElemento; /*que podra ser cualquier tipo de dato, se debe crear un tipo de dato igual en la funcion main, el cual sera constantemente modificado segun se quiera acceder a él desde la pila o modificarlo para introducirlo en la pila*/
	typedef struct nodo{
		TipoElemento dato;
		struct nodo *enlace;
	}TipoNodo;
	typedef TipoNodo *TipoPuntero;
	typedef TipoPuntero TipoPila; 

	TipoPila crear(int& i);
	int pilavacia(TipoPila pila);
	int pilallena(TipoPila pila);
	void sacar(TipoPila& pila,TipoElemento& elem);
	void insertar(TipoPila& pila,TipoElemento elem);
	void menu();
	void mostrar(TipoPila pila);
}
#endif
