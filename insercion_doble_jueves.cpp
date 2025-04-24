
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
lista *cola, *cab, *nuevo, *bus1, *bus2;

//funciones menu
void menu(void);
void ingresar(void);
void mostrar_cab(void);
void mostrar_cola(void);
void sacar(void);
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
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
		cout <<"\n\n Oprima una tecla para continuar";
		getch();
	}
}

void ingresar(void)
{   int existe;
	nuevo = new(lista);
	cout <<"\n Ingrese un Codigo: ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
    cout<<"Ingresa el nombre : ";
    //cin >> cab->nombre;
    getline(cin,nuevo->nombre);
    cout<<"\n\n";
    fflush(stdin);
	
	nuevo->der = NULL;
	nuevo->izq = NULL;
		
	if ( !cab )	
	{
		cab = new(lista);
		cola = new(lista);
		cab = nuevo;
		cola = nuevo;
	}
	else
	{
		if ( nuevo->codigo >= cola->codigo )
		{
			nuevo->izq = cola;
			cola->der  = nuevo;
			cola       = nuevo;	
		}
		else
		{
			if ( nuevo->codigo <= cab->codigo )
			{
				nuevo->der = cab;
				cab->izq   = nuevo;
				cab        = nuevo;		
			}
			else
			{
				bus1 = new(lista);
				bus2 = new(lista);
				bus1 = cab;
			 	bus2 = bus1->der;
			 	existe = 0;
			 	while ( existe == 0 )
			 	{
			 		if ( nuevo->codigo <= bus2->codigo )
					{
					    nuevo->izq = bus1;
					    nuevo->der = bus2;
					    bus1->der  = nuevo;
					    bus2->izq  = nuevo;
					    existe = 8;
					} 
					else
					{
						bus1  = bus1->der;
						bus2  = bus2->der;	
					}	
				}
				
			}			
		}		
	}
}

/*void ingresar(void)
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
}*/


void sacar(void)   // o borrar
{
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Sacar ";
		return;
	}
	nuevo = new(lista);
	nuevo = cab;
	cout <<"\n\n Elemento Eliminado: "<<nuevo->codigo;
	cout <<"\n Nombre : "<<nuevo->nombre;
	
	cab = nuevo->der;
	//cab = cab->der;   es igual al cab = nuevo->der
	
	delete(nuevo);
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
{	
	int encontro = 0;
	int codigo_buscar;
	
	if (!cab)
	{
		cout << "\n\n No hay Elementos Para Modificar";
		return;
	}
	
	nuevo = cab;
	cout << "\n Digite un código a modificar: ";
	cin >> codigo_buscar;
	
	while (nuevo != NULL && encontro == 0)
	{
		if (nuevo->codigo == codigo_buscar)
		{
			cout << "\n\n Elemento encontrado:";
			cout << "\n Código: " << nuevo->codigo;
			cout << "\n Nombre: " << nuevo->nombre;

			// Verificar si el nuevo código ya existe en la lista
			int nuevo_codigo;
			string nuevo_nombre;
			bool codigo_repetido = false;
			bool nombre_repetido = false;
			
			cout << "\n Ingrese un nuevo código: ";
			cin >> nuevo_codigo;
			fflush(stdin);
			
			// Recorrer la lista para comprobar si el código ya existe
			lista *temp = cab;
			while (temp != NULL)
			{
				if (temp->codigo == nuevo_codigo && temp != nuevo)
				{
					codigo_repetido = true;
					break;
				}
				temp = temp->der;
			}
			
			if (codigo_repetido)
			{
				cout << "\n Error: El código ingresado ya existe.";
				return;
			}

			cout << "Ingrese un nuevo nombre: ";
			getline(cin, nuevo_nombre);
			fflush(stdin);
			
			// Verificar si el nombre ya existe en la lista
			temp = cab;
			while (temp != NULL)
			{
				if (temp->nombre == nuevo_nombre && temp != nuevo)
				{
					nombre_repetido = true;
					break;
				}
				temp = temp->der;
			}
			
			if (nombre_repetido)
			{
				cout << "\n Error: El nombre ingresado ya existe.";
				return;
			}

			// Si no hay repeticiones, modificar los valores
			nuevo->codigo = nuevo_codigo;
			nuevo->nombre = nuevo_nombre;

			cout << "\n Modificación realizada con éxito.";
			encontro = 1;
		}
		else
		{
			nuevo = nuevo->der;  // avanzar en la lista 
		}
	}

	if (encontro == 0)
	{
		cout << "\n\n No Existe Elemento Para Modificar";
	}
}
