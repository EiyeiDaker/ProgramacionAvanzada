#include <iostream>

using namespace:: std;


struct  nodo
{
   int dato;
   nodo * siguiente;
   nodo * atras;
} *primero, *ultimo;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarPrimeroUltimo();
void desplegarUltimoPrimero();



int main()
{
    int opcion_menu = 0;
    do
    {
      cout << endl << "|--------------------------------------------|";
      cout << endl << "|                LISTA DOBLE                 |";
      cout << endl << "|---------------------|----------------------|";
      cout << endl << "|  1. Insertar        |  4. Eliminar         |";
      cout << endl << "|  2. Buscar          |  5. DesplegarPU      |";
      cout << endl << "|  3. Modificar       |  6. DesplegarUP      |";
      cout << endl << "|                     |  7. Salir            |";
      cout << endl << "|---------------------|----------------------|";

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
           cout << endl << endl << "DESPLEGAR LISTA DE PRIMERO A ULTIMO: " << endl << endl;
          desplegarPrimeroUltimo();
           break;

       case 6: 
           cout << endl << endl << "DESPLEGAR LISTA DE ULTIMO A PRIMERO: " << endl << endl;
           desplegarUltimoPrimero();
           break;

      case 7: 
           cout << endl << endl << "Programa finalizado..." << endl << endl;
           break;

       default: 
           cout << endl << endl << "Opcion no valida " << endl << endl;         
       
      }


    } while (opcion_menu != 6 );
    return 0;
}


void insertarNodo(){

    nodo* nuevo = new nodo();
    cout<< "Ingrese el valor del nodo: " << endl;
    cin>>nuevo->dato;

    if(primero == NULL){
        
        primero=nuevo;
        primero->siguiente=NULL;
        primero->atras=NULL;
        ultimo = nuevo;

    }else{

        ultimo->siguiente=nuevo;
        nuevo->siguiente=NULL;
        nuevo->atras=ultimo;
        ultimo=nuevo;

    }
    cout<< endl << "Nodo ingresado. " << endl;

}


void buscarNodo(){

    nodo* actual = new nodo();
    actual=primero;
    bool encontrado=false;
    int nodoBuscar = 0;

    if(primero!=NULL){

        cout<<endl<< "Ingrese el valor del nodo que quiere buscar: "<< endl;
        cin>> nodoBuscar;

        while(actual!=NULL && encontrado==false){

           if(nodoBuscar==actual->dato) {
           cout<< "Nodo encontrado: " << actual->dato;
            encontrado = true;

           }

           actual=actual->siguiente;

        }
        if (!encontrado)
        {
            cout<< "Nodo no encontrado: " << endl;
        }
        

    }else {

        cout<< "La lista se encuentra vacia. " << endl;
    }

}


void modificarNodo(){

    nodo* actual = new nodo();
    actual=primero;
    bool encontrado=false;
    int nodoModificar = 0;

    if(primero!=NULL){

        cout<<endl<< "Ingrese el valor del nodo que quiere Modificar: "<< endl;
        cin>> nodoModificar;

        while(actual!=NULL && encontrado==false){

           if(nodoModificar==actual->dato) {

           cout<< "Nodo encontrado: " << actual->dato;
           cout<< endl<< "Ingrese el nuevo valor del nodo: " << endl;
           cin>> actual->dato;
           cout<< endl<< "Nodo modificado.";
            encontrado = true;

           }

           actual=actual->siguiente;

        }
        if (!encontrado)
        {
            cout<< "Nodo no encontrado: " << endl;
        }
        

    }else {

        cout<< "La lista se encuentra vacia. " << endl;
    }



}

void eliminarNodo(){

    nodo* actual = new nodo();
    nodo* anterior = new nodo();
    anterior = NULL;
    actual=primero;
    bool encontrado=false;
    int nodoEliminar= 0;
    

    if(primero!=NULL){

        cout<<endl<< "Ingrese el valor del nodo que quiere Eliminar: "<< endl;
        cin>> nodoEliminar;

        while(actual!=NULL && encontrado==false){

           if(actual->dato==nodoEliminar){

            cout<<"Nodo enocontrado"<< actual->dato << endl;

               if(actual==primero) {
               primero=primero->siguiente;
            

                  }else if(actual== ultimo){

                    ultimo=ultimo->atras;
                    ultimo->siguiente=NULL;


                 }else{

                    anterior->siguiente=actual->siguiente;

                 }
                 encontrado=true;
                 cout<< "Nodo eliminado.";
                  
             }  

             anterior=actual;
             actual=actual->siguiente;
         }
    
        if (!encontrado)
        {
            cout<< "Nodo no encontrado: " << endl;
        }
        

    }else {

        cout<< "La lista se encuentra vacia. " << endl;
    }



}


void desplegarPrimeroUltimo(){

    nodo* actual = new nodo();
    actual=primero;

    if(primero!=NULL){

        while(actual!=NULL){

            cout<< "   " << actual->dato;
            actual=actual->siguiente;

        }


    }else {

        cout<< "La lista se encuentra vacia. " << endl;
    }


}


void desplegarUltimoPrimero(){

    nodo* actual = new nodo();
    actual = ultimo;

    if(primero!=NULL){

        while(actual!=NULL){

            cout<< "  " << actual->dato;
            actual= actual->atras;
        }

    }else{

        cout<< "La lista se encuentra vacia." << endl;

    }

}