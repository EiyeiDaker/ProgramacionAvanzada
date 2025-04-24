#include <iostream>

using namespace:: std;


struct  nodo
{
    int dato;
    nodo* siguiente;

}*primero, *ultimo;

void insertarNodo();
void desplegarLista();
void modificarNodo();
void eliminarNodo();
void buscarNodo();

int main()
{
    int opcion_menu = 0;
    do
    {
      cout << endl << "|--------------------------------------------|";
      cout << endl << "|              LISTA CIRCULAR SIMPLE         |";
      cout << endl << "|---------------------|----------------------|";
      cout << endl << "|  1. Insertar        |  4. Eliminar         |";
      cout << endl << "|  2. Buscar          |  5. Desplegar        |";
      cout << endl << "|  3. Modificar       |  6. Salir            |";
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
           cout << endl << endl << "DESPLEGAR LISTA: " << endl << endl;
           desplegarLista();
           break;

       case 6: 
           cout << endl << endl << "Programa finalizado..." << endl << endl;
           break;
           break;

       default: 
           cout << endl << endl << "Opcion no valida " << endl << endl;         
       
      }


    } while (opcion_menu != 6 );
    return 0;
}




void insertarNodo(){

    nodo* nuevo = new nodo();

    cout<<"Ingresa el valor del nodo: " << endl;
    cin>> nuevo->dato;


    if(primero==NULL){

        primero=nuevo;
        primero->siguiente=primero;
        ultimo=primero;
        

    }else{
        
        ultimo->siguiente=nuevo;
        nuevo->siguiente=primero;
        ultimo=nuevo;

    }




}

void buscarNodo(){

    nodo* actual = new nodo();
    actual=primero;
    bool encontrado=false;
    int nodoBuscado=0;


    cout<<" Ingrese el valor del nodo que quiere buscar" << endl;
    cin>>nodoBuscado;
  
    if(primero!=NULL){
    
        do{
            
            if (actual->dato==nodoBuscado)
            {
               cout<< "nodo encontrado :  " << actual->dato<< endl << endl;
               encontrado=true;

            }
            
        

         actual=actual->siguiente;

        }while(actual!=primero && encontrado==false);

        if (!encontrado)
        {
            cout<< "Nodo no encontrado.";
        }
        
    
      }else{
    
        cout<<"La lista se encuentra vacia. " << endl;
    
      }
    

}

void modificarNodo(){

    nodo* actual = new nodo();
    actual=primero;
    bool encontrado=false;
    int nodoModificar=0;


    cout<<" Ingrese el valor del nodo que quiere modificar" << endl;
    cin>>nodoModificar;
  
    if(primero!=NULL){
    
        do{
            
            if (actual->dato==nodoModificar)
            {
               cout<< "Nodo encontrado " << actual->dato << endl<< endl;
               cout<< "Ingrese el nuevo valor del nodo:  " << endl;
               cin>> actual->dato;
               cout<<" Nodo modificado. " << endl<< endl;
               encontrado=true;

            }

         actual=actual->siguiente;

        }while(actual!=primero && encontrado==false);

        if (!encontrado)
        {
            cout<< "Nodo no encontrado.";
        }
        
    
      }else{
    
        cout<<"La lista se encuentra vacia. " << endl;
    
      }





}

void eliminarNodo(){

    nodo* actual = new nodo();
    nodo* anterior = new nodo();
    actual=primero;
    anterior=ultimo;
    bool encontrado=false;
    int nodoEliminar=0;


    cout<<" Ingrese el valor del nodo que quiere eliminar" << endl;
    cin>>nodoEliminar;
  
    if(primero!=NULL){
    
        do{
            
            if (actual->dato==nodoEliminar)
            {
               cout<< "nodo encontrado :  " << actual->dato<< endl << endl;

               if(actual==primero){

                primero=primero->siguiente;
                ultimo->siguiente=primero;
                anterior->siguiente=primero;

               }else if(actual==ultimo){

                anterior->siguiente=primero;
                ultimo=anterior;
                
                

               }else{

                anterior->siguiente=actual->siguiente;


               }


               encontrado=true;
               cout<< "Nodo eliminado"<< endl;

            }
            
        
         anterior=actual;
         actual=actual->siguiente;

        }while(actual!=primero && encontrado==false);

        if (!encontrado)
        {
            cout<< "Nodo no encontrado.";
        }
        
    
      }else{
    
        cout<<"La lista se encuentra vacia. " << endl;
    
      }
    









}


void desplegarLista(){

  nodo* actual = new nodo();
  actual=primero;

  if(primero!=NULL){

    do{
        cout<< "  "<< actual->dato;
        actual=actual->siguiente;

    }
    while(actual!=primero);


  }else{

    cout<<"La lista se encuentra vacia. " << endl;

  }



}