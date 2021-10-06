#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};


Nodo* insertarOrdenado(Nodo* inicio, Nodo* nuevo){
    if (inicio == nullptr || nuevo->dato < inicio->dato){
        nuevo->siguiente=inicio;
        inicio=nuevo;
    }
    else{
        Nodo* aux=inicio;
        while (aux->siguiente!=nullptr && aux->siguiente->dato < nuevo->dato){
            aux=aux->siguiente;
        }
        if (aux->siguiente!=nullptr){
            nuevo->siguiente=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
    return inicio;
}

Nodo* cargarNumeros(Nodo* inicio){
    Nodo* nuevo;
    int n;
    cout << "Ingrese numero (0 finaliza): " ;
    cin >> n;
    while (n != 0){
        nuevo = new Nodo;
        nuevo->dato=n;
        nuevo->siguiente=nullptr;
        inicio=insertarOrdenado(inicio, nuevo);
        cout << "Ingrese numero (0 finaliza): " ;
        cin >> n;
    }
    return inicio;
}

void imprimir(Nodo* inicio){
    for (Nodo* p = inicio; p!=nullptr; p=p->siguiente){
        cout << p->dato << " ";
    }
    cout << endl;
}

int main()
{
    Nodo* lista=nullptr;
    lista=cargarNumeros(lista);

    cout << "Lista :" << endl;
    imprimir(lista);

    return 0;
}