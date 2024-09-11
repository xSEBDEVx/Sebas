/**
*@file Arbol binario de busqueda
*@author Juan Sebastian Vallejo <jusevallejo@unicauca.edu.co>
*@copyright MIT License
*/
#ifndef BINARIO_H
#define BINARIO_H
using std::cout;
using std::endl;
namespace arbol{
	template <class T>    //Tipo generico
	/**
	*@brief Arbol Binario de Busqueda
	*/
	class binario{
	private:
		/**
		*@brief Nodo Binario 
		*/
		struct nodo {
			T dato;    // Dato Almacenado
			nodo * izq;		//Ref. al hijo izquierdo
			nodo * der;		//Ref. al hijo derecho
			nodo(T dato):dato(dato),izq(nullptr),der(nullptr){
			}
			bool es_hoja(){
				return (izq == nullptr && der == nullptr);
			}
			
			bool contiene(T dato){
				return this->dato == dato;
			}
		};
		/**
		*@brief Nodo raiz
		*/
		//Inicializamos el nodo raiz, null por defecto
		nodo * raiz = nullptr;
		/**
		*@brief Buscar el mayor de los valores a la derecha
		*@param nodo*raiz subArbol dónde buscará el nodo mayor, generalmente es el de la izquierda
		*/
		//Funcion mayor de los menores
		int maxValor(nodo*raiz){
			if(raiz -> der == nullptr) return raiz->dato;
			else return maxValor(raiz->der);
		}
		/**
		*@brief Buscar el mayor de los valores a la derecha
		*@param nodo*raiz subArbol dónde buscará el nodo mayor, generalmente es el de la izquierda
		*/
		//Función menor de los mayores
		int minValor(nodo*raiz){
			if(raiz->izq == nullptr) return raiz->dato;
			else return minValor(raiz->izq);
		}
		//Función de ordenamiento preOrden
		void preorden(nodo * n){
			//verificamos si el nodo actual es nulo, si es así la función termina
			if(n == nullptr){
				return;
			}
			cout << " " << n -> dato;
			//Invocar recursivamente
			preorden(n->izq);
			preorden(n->der);
		}
		void inorden(nodo * n){
			if(n == nullptr){
				return;
			}
			inorden(n->izq);
			cout << " " << n -> dato;
			//Invocar recursivamente
			inorden(n->der);
		}
		void posorden(nodo * n){
			if(n == nullptr){
				return;
			}
			//Invocar recursivamente
			posorden(n->izq);
			posorden(n->der);
			cout << " " << n -> dato;
			
				}
			/**
			@brief intenta insertar un nuevo nodo a partir del padre
			*@param padre Potencial del padre del nodo
			*@param n nuevo nodo
			*@return true si n pudo ser insertado
			*/
		bool insertar(nodo * padre, nodo * n){
			//Verificación nodo igual a padre, no se inserta
			if(padre->dato == n->dato){
				//El dato ya está en el arbol
				return false;
			}
			//Tratar de insertar en los hijos, a la izquierda si es menor o a la derecha si es mayor
			if(padre -> dato > n-> dato){
				//insertar a la izquierda
				//el hijo izquierdo es nulo? Si lo es inserta n a la izquierda del padre actual
				if(padre -> izq == nullptr){
					padre -> izq = n;
					return true;
					
				}else{
				//si el hijo izquierdo no es nulo, hacemos llamado recursivo al metodo insertar pero esta vez con respecto al nodo izquiero del nodo padre
				return insertar(padre -> izq, n);
				}
			}
			else{
				//Insertar a la derecha
				if(padre ->der == nullptr){
					padre->der = n;
					return true;
				}else{
				//si el hijo derecho no es nulo, hacemos llamado recursivo al metodo insertar pero esta vez con respecto al nodo derecho del nodo padre
					
					return insertar(padre -> der, n);
				}
			}
			return false;
		}
		nodo* eliminar(nodo * padre, T dato){
			if (padre == nullptr)
				return padre;
			
			if (dato < padre->dato)
			{
				padre->izq = eliminar(padre->izq, dato);
			}
			else if (dato > padre->dato)
			{
				padre->der = eliminar(padre->der, dato);
			}
			else
			{
				// Caso en que se encuentra el nodo a eliminar
				if (padre->izq == nullptr)
					return padre->der;
				else if (padre->der == nullptr)
					return padre->izq;
				
				padre->dato = minValor(padre->der);
				padre->der = eliminar(padre->der, padre->dato);
			}
			return padre;
		}
	public:
		/**
		*@brief Permite verificar si el arbol está vacio
		*@return true si el arbol está vacio
		*/
		bool es_vacio(){
			return (raiz == nullptr);
		};
		/**
		*@brief Insertar un nuevo dato en el arbol Binario 
		*@param T dato nuevo dato a insertar
		*/
		void insertar(T dato){
			cout << "Insertar " << dato << endl;
			//Creación del nodo a insertar
			nodo*n = new nodo(dato);
			//Verificación, si el arbol está vacío el nodo a insertar se convierte en la raiz
			if(es_vacio()){
				raiz = n;
				
			}else{
				//lIBERAR LA MEMORIA DEL NODO si el dato se pudo insertar
				if(!insertar(raiz,n)){
					delete n;
				}
			}
		}
		//Eliminar un dato del arbol
			
		void eliminar (T dato){
			eliminar(raiz, dato);
		}
		/**
		*@brief imprime el recorrido del arbol en preorden
		*/
		void preorden(){
			preorden(raiz);
		}
		/**
		*@brief imprime el recorrido del arbol en Inorden
		*/
		void inorden(){
			inorden(raiz);
		}
		/**
		*@brief imprime el recorrido del arbol en posorden
		*/
		void posorden(){
			posorden(raiz);
		}
		
		
	};
};
	




#endif
