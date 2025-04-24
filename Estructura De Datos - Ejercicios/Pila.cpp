#include<iostream>
#include<conio.h>

using namespace::std;

struct nodo
{
   int dato;
   nodo *siguiente;
    
} *primero;



void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarPila();


int main(){
     int opcion_menu = 0;
     do
     {
       cout << endl << "|------------------------------------------|";
       cout << endl << "|                   PILA                   |";
       cout << endl << "|---------------------|--------------------|";
       cout << endl << "|  1. Insertar        |  4. Eliminar       |";
       cout << endl << "|  2. Buscar          |  5. Desplegar      |";
       cout << endl << "|  3. Modificar       |  6. Salir          |";
       cout << endl << "|---------------------|--------------------|";

       cout<< endl << "Escoja una opcion: ";
       cin >> opcion_menu;

       switch (opcion_menu){

        case 1: 
            cout << endl << endl << "INSERTAR UN NODO EN LA PILA: " << endl << endl;
            insertarNodo();
            break;

        case 2: 
            cout << endl << endl << "BUSCAR UN NODO EN LA PILA: " << endl << endl;
            buscarNodo();
            break;

        case 3: 
            cout << endl << endl << "MODIFICAR UN NODO EN LA PILA: " << endl << endl;
            modificarNodo();
            break;
        
        case 4: 
            cout << endl << endl << "ELIMINAR UN NODO EN LA PILA: " << endl << endl;
            eliminarNodo();
            break;

        case 5: 
            cout << endl << endl << "DESPLEGAR UN NODO EN LA PILA: " << endl << endl;
            desplegarPila();
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
    cout<< "Ingrese el dato que quiere guardar en el nodo: ";
    cin>> nuevo->dato;

    nuevo->siguiente = primero;
    primero = nuevo;


}


void buscarNodo(){

    nodo * actual = new nodo();
    actual = primero;
    int nodoBuscado = 0;
    bool encontrado = false;

    cout << "Ingrese el valor del nodo que quiere buscar: ";
    cin>> nodoBuscado;

    if(primero != NULL){

        while(actual != NULL && encontrado != true){
            
            if(actual->dato == nodoBuscado){

                cout << endl << "Nodo encontrado: " << actual->dato;

                encontrado = true;
            }
            
            actual = actual->siguiente;
        }
        if(encontrado == false){
            cout<< endl << "Nodo no encontrado " << endl << endl;


        }

    } else {
        
        cout<< "La pila se encuntra vacia.";
        
    }
 

}

void modificarNodo(){
 
    nodo * actual = new nodo();
    actual = primero;
    int nodoQueQuiereModificar = 0;
    bool encontrado = false;

    cout << "Ingrese el valor del nodo que quiere Modificar: ";
    cin>> nodoQueQuiereModificar;

    if(primero != NULL){

        while(actual != NULL && encontrado != true){
            
            if(actual->dato == nodoQueQuiereModificar){

                cout << endl << "Nodo encontrado: " << actual->dato;
                cout << endl << "Ingrese el valor del nodo que quiere poner: ";
                cin >> actual->dato;
                cout << endl << endl << "Nodo Modificado " << endl << endl;

                encontrado = true;
            }
            
            actual = actual->siguiente;
        }
        if(encontrado == false){
            cout<< endl << "Nodo no encontrado " << endl << endl;


        }

    } else {
        
        cout<< "La pila se encuntra vacia.";
        
    }

}

void eliminarNodo(){

    nodo * actual = new nodo();
    actual = primero;
    nodo * izq = new nodo();
    izq = NULL;
    int nodoQueQuiereEliminar = 0;
    bool encontrado = false;

    cout << "Ingrese el valor del nodo que quiere Eliminar: ";
    cin>> nodoQueQuiereEliminar;

    if(primero != NULL){

        while(actual != NULL && encontrado != true){
         
            if(actual->dato == nodoQueQuiereEliminar){

                
                cout << endl << "Nodo encontrado: " << actual->dato;     
                
                if( actual == primero){
                    primero= primero->siguiente;

                }  else{
                     izq->siguiente = actual->siguiente;


                }
                cout << endl << endl << "Nodo Eliminado " << endl << endl;
                encontrado = true;
            }


            izq= actual;
            actual = actual->siguiente;
           
            
            
        }
        if(encontrado == false){
            cout<< endl << "Nodo no encontrado " << endl << endl;


        }

    } else {
        
        cout<< "La pila se encuntra vacia.";
        
    }


}




void desplegarPila(){
    nodo * actual = new nodo();

    actual = primero;

    if(primero != NULL){

        while(actual != NULL){
            cout<< endl << "  " << actual->dato;
            actual = actual->siguiente;
            
        }
        cout <<"\n\n Oprima una tecla para continuar";
		getch();


    } else {
        
        cout<< "La pila se encuntra vacia.";
        
    }
 
    

}