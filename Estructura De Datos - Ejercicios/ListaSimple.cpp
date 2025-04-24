#include <iostream>

using namespace:: std;

struct nodo
{
  int dato;
  nodo *siguiente;
} *primero, *ultimo;


void insertarNodo();
void desplegarLista();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
int main()
{
    int opcion_menu = 0;
    do
    {
      cout << endl << "|------------------------------------------|";
      cout << endl << "|                   COLA                   |";
      cout << endl << "|---------------------|--------------------|";
      cout << endl << "|  1. Insertar        |  4. Eliminar       |";
      cout << endl << "|  2. Buscar          |  5. Desplegar      |";
      cout << endl << "|  3. Modificar       |  6. Salir          |";
      cout << endl << "|---------------------|--------------------|";

      cout<< endl << "Escoja una opcion: ";
      cin >> opcion_menu;

      switch (opcion_menu){

       case 1: 
           cout << endl << endl << "INSERTAR UN NODO EN LA LISTA " << endl << endl;
           insertarNodo();
           break;

       case 2: 
           cout << endl << endl << "BUSCAR UN NODO EN LA LISTA: " << endl << endl;
           buscarNodo();
           break;

       case 3: 
           cout << endl << endl << "MODIFICAR UN NODO EN LA LISTA: " << endl << endl;
           modificarNodo();
           break;
       
       case 4: 
           cout << endl << endl << "ELIMINAR UN NODO EN LA LISTA: " << endl << endl;
           eliminarNodo();
           break;

       case 5: 
           cout << endl << endl << "DESPLEGAR UN NODO EN LA LISTA: " << endl << endl;
         desplegarLista();
           break;

       case 6: 
           cout << endl << endl << "Programa finalizado..." << endl << endl;
           break;

       default: 
           cout << endl << endl << "Opcion no valida " << endl << endl;         
       
      }


    } while (opcion_menu != 6 );
    return 0;
}



void insertarNodo() {

    nodo * nuevo = new nodo();
   
    cout << "Ingrese el dato del nuevo nodo: ";
    cin>> nuevo->dato;

    if (primero == NULL){

        primero= nuevo;     
        primero->siguiente=NULL;
        ultimo = nuevo;

        
    }else {

        ultimo->siguiente = nuevo;
        nuevo->siguiente= NULL;
        ultimo = nuevo;
    }
    cout << "nodo ingresado. ";



}

void buscarNodo(){

    nodo * actual = new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado;


    if (primero != NULL){

        cout<< "Inserte el nodo que quiere buscar: " << endl;
        cin >> nodoBuscado;

        while(actual != NULL && encontrado != true){    

           if(nodoBuscado == actual->dato){
                
                cout << endl << "Nodo encontrado:  " << actual->dato;
                encontrado = true;
           
            }

            actual = actual->siguiente;
          
        } if(!encontrado){

            cout << endl << "No se encontro. " << endl;
        }

    }else{

        cout << "La lista se encuntra vacia. " << endl << endl;
    }
}

void modificarNodo(){

    nodo * actual = new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoModificar;


    if (primero != NULL){

        cout<< "Inserte el nodo que quiere Modificar: " << endl;
        cin >> nodoModificar;

        while(actual != NULL && encontrado != true){    

           if(nodoModificar == actual->dato){
                
                cout << endl << "Nodo encontrado:  " << actual->dato;
                cout<< endl << "Ingrese el nuevo valor del nodo: " << endl;
                cin>>actual->dato;
                encontrado = true;

            }

            actual = actual->siguiente;
          
        } if(!encontrado){

            cout << endl << "No se encontro. "<< endl;
        }

    }else{

        cout << "La lista se encuntra vacia. " << endl << endl;
    }
}

void eliminarNodo(){

    nodo * actual = new nodo();
    nodo * anterior = new nodo();
    anterior = NULL;
    actual = primero;
    bool encontrado = false;
    int nodoEliminar;


    if (primero != NULL){

        cout<< "Inserte el nodo que quiere eliminar: " << endl;
        cin >> nodoEliminar;

        while(actual != NULL && encontrado != true){    

           if(nodoEliminar == actual->dato){
                
                cout << endl << "Nodo encontrado:  " << actual->dato;
                
                if(nodoEliminar == primero->dato){

                    primero = primero->siguiente;

                }else if(nodoEliminar == ultimo->dato){

                    anterior->siguiente=NULL;
                    ultimo=anterior;

                }else{
                    anterior->siguiente=actual->siguiente;
                }
                
                encontrado = true;
                cout<< endl << "Nodo eliminado correctamente. " << endl << endl;
            }
            anterior= actual;
            actual = actual->siguiente;
          
        } if(!encontrado){

            cout << endl << "No se encontro. " << endl;
        }

    }else{

        cout << "La lista se encuntra vacia. " << endl << endl;
    }


}

void desplegarLista(){

    nodo * actual = new nodo;
    actual = primero;

    if (primero != NULL){

        while(actual != NULL){

            cout << endl << "   " << actual->dato;
            actual = actual->siguiente;

        }
 

    }else{

        cout << "La lista se encuntra vacia. " << endl << endl;
    }


}


