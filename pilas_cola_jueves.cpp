// librerias
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct lista
{ 
	int codigo;
	string nombre;
	lista *der;  // variable derdor enlace
	lista *izq; 
};

// variables de la lista
lista *cola, *cab, *nuevo;

//funciones menu
void menu(void);
void ingresar(void);
void mostrar_cab(void);
void mostrar_cola(void);
void sacar(void);
void sacar_segundo(void);
void modificar(void);

main()
{
	menu();
}

void menu(void)
{
	int y, opc;
	opc = 9;
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar Datos";
		cout<<"\n 2 Sacar Datos";
		cout<<"\n 3 Mostrar Datos cab";
		cout<<"\n 4 Mostrar Datos cola";
		cout<<"\n 5 Modificar Datos";
		cout<<"\n 6 Sacar segundo";
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar();	break;
			case 2:
				sacar();	break;
			case 3:
				mostrar_cola();	break;
			case 4:
				mostrar_cab();	break;
			case 5:
				modificar();	break;
			case 6:
				sacar_segundo(); break;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
		cout <<"\n\n Oprima una tecla para continuar";
		getch();
	}
}

void ingresar(void)
{
	if ( !cab )	
	{
		cab = new(lista);
		cout <<"\n Ingrese un codigo : ";
		cin >>cab->codigo; 
        fflush(stdin);    //esta funcion libera la memoria 
		
		cout<<"Ingresa el nombre : ";
		//cin >> cab->nombre;
		getline(cin,cab->nombre);        //"juan alberto ramires"
              // cin >> nombre           juan alberto ramirez
              //  realmente almacena es  "juan" 
        
        cout<<"\n\n";
        fflush(stdin);
        
		cab->der = NULL;
		cab->izq = NULL;
		
		cola = new(lista);
		cola = cab;
		return;
	}
	nuevo = new(lista);
	cout <<"\n Ingrese un Codigo: ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
    cout<<"Ingresa el nombre : ";
    //cin >> cab->nombre;
    getline(cin,nuevo->nombre);
    cout<<"\n\n";
    fflush(stdin);
      
	nuevo->der = NULL;  /// la estructura Nuevo esta derndo al Final o vacio
	nuevo->izq = NULL;
	//cola->der = nuevo;  /// el ultimo nodo de la lista se une al NUEVO
	
	nuevo->der 	= cab;
	cab->izq	= nuevo;
	cab = nuevo;  /// la variable cab toma la posicion de Nuevo
}


void sacar(void)   // o borrar
{
    if (!cab)
    {
        cout << "\n\n No hay Elementos Para Sacar ";
        return;
    }
    nuevo = new(lista);
    nuevo = cab;  // Apunta a la cabeza actual
    cout << "\n\n Elemento Eliminado: " << nuevo->codigo;
    cout << "\n Nombre : " << nuevo->nombre;

    cab = nuevo->der;  // La nueva cabeza es el siguiente nodo

    delete nuevo;  // Elimina el nodo anterior
}



void mostrar_cab(void)   // o  listar
{   
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Mostrar ";
		return;
	}
	nuevo = new(lista);
	nuevo = cab;
	
	while ( nuevo != NULL  )
	{
	  cout <<"\n\n Elemento : "<<nuevo->codigo;
      cout <<"\n Nombre : "<<nuevo->nombre;
      
	  nuevo = nuevo->der;  // avanzar en la lista 
    }
}

void mostrar_cola(void)   // o  listar
{   
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Mostrar ";
		return;
	}
	nuevo = new(lista);
	nuevo = cola;
	
	while ( nuevo != NULL  )
	{
	  cout <<"\n\n Elemento : "<<nuevo->codigo;
      cout <<"\n Nombre : "<<nuevo->nombre;
      
	  nuevo = nuevo->izq;  // avanzar en la lista 
    }
}
void modificar(void)   
{	int encontro;
	int codigo_buscar;
    encontro = 0;
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Modificar";
		return;
	}
	nuevo = new(lista);
	nuevo = cab;
	cout << "\n Digite un codigo a modificar : ";
	cin >> codigo_buscar;
	while (nuevo != NULL && encontro == 0)
	{
	  if (nuevo->codigo == codigo_buscar)
	  {
	  	cout <<"\n\n Elemento : "<<nuevo->codigo;
      	cout <<"\n Nombre : "<<nuevo->nombre;
	  	cout <<"\n Ingrese un codigo : ";
		cin >>nuevo->codigo; 
        fflush(stdin);  
		cout<<"Ingresa el nombre : ";
		getline(cin,nuevo->nombre); 
		encontro = 1;
	  }
	  else
	  	nuevo = nuevo->der;  // avanzar en la lista 
    }
    if (encontro == 0)
    {
    	cout <<"\n\n No Existe Elementos Para Modificar";
	}

}
void sacar_segundo(void)
{
    if (!cab || !cab->der) // Si la lista está vacía o solo hay un elemento
    {
        cout << "\n\n No hay segundo elemento para eliminar.";
        return;
    }

    lista *segundo = cab->der;  // Apuntar al segundo nodo

    // Enlazar la cabeza con el tercer nodo (si existe)
    cab->der = segundo->der;
    if (segundo->der) {
        segundo->der->izq = cab;
    }
    else {
        // Si el segundo nodo era el último, actualizar cola
        cola = cab;
    }

    cout << "\n\n Elemento Eliminado: " << segundo->codigo;
    cout << "\n Nombre: " << segundo->nombre;

    delete segundo;  // Liberar memoria del nodo eliminado
}


