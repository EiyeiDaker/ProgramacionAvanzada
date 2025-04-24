#include <iostream>

using namespace::std;

struct  nodo
{
   int dato;
   nodo * siguiente;
} *primero, *ultimo;

void insertarNodo();
void buscarNodo();
void desplegarCola();
void modificarNodo();
void eliminarNodo();

int main(){

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
            cout << endl << endl << "INSERTAR UN NODO EN LA COLA: " << endl << endl;
            insertarNodo();
            break;

        case 2: 
            cout << endl << endl << "BUSCAR UN NODO EN LA COLA: " << endl << endl;
            buscarNodo();
            break;

        case 3: 
            cout << endl << endl << "MODIFICAR UN NODO EN LA COLA: " << endl << endl;
            modificarNodo();
            break;
        
        case 4: 
            cout << endl << endl << "ELIMINAR UN NODO EN LA COLA: " << endl << endl;
            eliminarNodo();
            break;

        case 5: 
            cout << endl << endl << "DESPLEGAR UN NODO EN LA COLA: " << endl << endl;
          desplegarCola();
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



void insertarNodo(){

    nodo * nuevo = new nodo();

    cout<< "Ingrese el dato del nuevo Nodo: ";
    cin>> nuevo->dato;

        if(primero==NULL){
            primero=nuevo;
            primero->siguiente = NULL;
            ultimo=primero;

        }   else{
                    ultimo->siguiente= nuevo;
                    nuevo->siguiente = NULL;
                    ultimo = nuevo;


         }
    cout << endl << "Nodo ingresado. " << endl << endl;
}


void buscarNodo(){

    nodo * actual = new nodo();
    actual = primero;
    int nodoBuscado = 0;
    bool encontrado = false;


    cout << endl<<  "Ingrese el valor del nodo que quiere buscar:  " << endl;
    cin>> nodoBuscado;


    if(primero != NULL){


        while(actual!= NULL && encontrado == false){

            if(actual->dato == nodoBuscado){

                cout << endl << "Nodo encontrado: " << actual->dato;
                encontrado = true;
            }
            actual = actual -> siguiente;
        }


    }else {

        cout << endl << " La lista esta vacia. ";

    }


}

void modificarNodo(){

    nodo * actual = new nodo();
    actual = primero;
    int nodoModificar = 0;
    bool encontrado = false;


    cout << endl<<  "Ingrese el valor del nodo que quiere Modificar:  " << endl;
    cin>> nodoModificar;


    if(primero != NULL){


        while(actual!= NULL && encontrado == false ){

            if(actual->dato == nodoModificar){

                cout << endl << "Nodo encontrado: " << actual->dato;
                cout << endl << "Ingrese el nuevo valor del nodo: " << endl;
                cin >> actual->dato;
                encontrado = true;
            }
            actual = actual -> siguiente;
        }


    }else {

        cout << endl << " La lista esta vacia. ";

    }



}

//primero = NULL        ultimo = NULL    nuevo = 45     45, 6 , 7, 12

//COLA          45

void eliminarNodo(){

    nodo * actual = new nodo();
    nodo * anterior = new nodo();
    anterior = NULL;
    actual = primero;
    int nodoParaElminar = 0;
    bool encontrado = false;


    cout << endl<<  "Ingrese el valor del nodo que quiere eliminar:  " << endl;
    cin>> nodoParaElminar;


    if(primero != NULL){


        while(actual!= NULL && encontrado == false){

            if(actual->dato == nodoParaElminar){

                cout << endl << "Nodo encontrado: " << actual->dato;

                if(actual== primero){

                  primero=primero->siguiente;    

               }else if(actual == ultimo){

                    anterior->siguiente = NULL;
                    ultimo= anterior;

                }else {
                
                anterior->siguiente = actual->siguiente;
                
                }
                encontrado = true;
                cout << endl << "Nodo eliminado. " << endl; 

            }
            anterior = actual;
            actual = actual -> siguiente;
        }
        

    }else {

        cout << endl << " La lista esta vacia. ";

    }



}

void desplegarCola(){

    nodo * actual = new nodo();

    actual = primero;

    if(primero != NULL){
        
        while(actual != NULL){

            cout<< endl << "  " << actual->dato;
            actual=actual->siguiente;

        }

    }else{
        cout << endl << "La lista esta vacia. " << endl << endl;

    }



}





