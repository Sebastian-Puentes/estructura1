#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
};

void insertarlista(nodo*&, int);
void buscarLista(nodo*, int);
void mostrarLista(nodo *);
void eliminarNodo(nodo*&, int);
void actualizarNodo(nodo* , int , int );

int main() {
    nodo* lista = NULL;
    char opcion;

    do {
        cout << "MENU:" << endl;
        cout << "1. Insertar un numero" << endl;
        cout << "2. Buscar un numero" << endl;
        cout << "3. Mostrar la lista de numeros" << endl;
		cout << "4. Eliminar un nodo de la lista"<<endl;
		cout << "5. Modificar/ actualizar un nodo"<<endl;
        cout << "6. Salir"<< endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                int dato;
                cout << "Digite un numero: ";
                cin >> dato;
				cout<<"\n";
                insertarlista(lista, dato);
                break;
            }
            case '2': {
                int dato;
                cout << "Digite el numero a buscar: ";
                cin >> dato;
				cout<<"\n";
                buscarLista(lista, dato);
                break;
            }
			case '3' :{
				mostrarLista(lista);
				cout<<"\n";
				break;
			}
			case '4' :{
				int dato;
				cout<<"Ingrese el valor que quiere borrar: ";
				cin>> dato;
				eliminarNodo(lista, dato);
				cout<<"\n";
				break;
			}
			case '5': {
                int dato, nuevoDato;
                cout << "Digite el numero a actualizar: ";
                cin >> dato;
                cout << "Digite el nuevo numero: ";
                cin >> nuevoDato;
                cout << "\n";
                actualizarNodo(lista, dato, nuevoDato);
                break;
            }
            case '6':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != '6');
    return 0;
}
void insertarlista(nodo*& lista, int n) {
    nodo* nuevonodo = new nodo();
    nuevonodo->dato = n;
    nodo* aux1 = lista;
    nodo* aux2 = nullptr;

    while ((aux1 != nullptr) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (aux2 == nullptr) {
        lista = nuevonodo;
    } else {
        aux2->siguiente = nuevonodo;
    }
    nuevonodo->siguiente = aux1;
    cout << "Elemento " << n << " insertado en la lista correctamente" << endl;
}
void buscarLista(nodo* lista, int n) {
    bool band = false;
    nodo* m = lista;
    while ((m != nullptr) && (m->dato <= n)) {
        if (m->dato == n) {
            band = true;
        }
        m = m->siguiente;
    }
    if (band) {
        cout << "Elemento " << n << " ha sido encontrado en la lista" << endl;
    } else {
        cout << "Elemento " << n << " no ha sido encontrado en la lista" << endl;
    }
}
void mostrarLista(nodo * lista){
	nodo * p = new nodo();
    p = lista;
	while(p != NULL){
		cout<<p->dato<<" -> ";
		p= p ->siguiente;
	}
}
void eliminarNodo(nodo *&lista, int n){
    if(lista != NULL){
		nodo* aux_borrar;
		nodo* anterior= NULL;
		aux_borrar= lista;
		while((aux_borrar != NULL) && (aux_borrar->dato !=n)){
			anterior = aux_borrar;
			aux_borrar= aux_borrar -> siguiente;
		}
		cout << "Elemento " << n << " eliminado correctamente" << endl;
		if(aux_borrar == NULL){
			cout<< "El elemento no ha sido encontrado";
		}
		else if(anterior == NULL){
            lista= lista->siguiente;
			delete aux_borrar;
		}
		else{
			anterior->siguiente= aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}
void actualizarNodo(nodo* lista, int n, int nuevoDato) {
    nodo* m = lista;
    while (m != nullptr) {
        if (m->dato == n) {
            m->dato = nuevoDato;
            cout << "Elemento " << n << " actualizado a " << nuevoDato << " correctamente" << endl;
            return;
        }
        m = m->siguiente;
    }
    cout << "Elemento " << n << " no ha sido encontrado en la lista" << endl;
}









