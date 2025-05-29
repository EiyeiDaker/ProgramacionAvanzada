#include <iostream>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace::std;


struct Empleado
{
	int codigo;
	string nombre;
	int sueldo;
	
	Empleado *debajo;
}*primero, *ultimo, *nueva, *busca1, *busca2;


struct Oficina
{
	int codigo;
	string nombre;
	
	Oficina *izq;
	Oficina *der;
	Empleado *abajo; 
	
}*cab, *cola, *nuevo, *bus1, *bus2;


void menu(void);
void menuDependencias(void);
void menuEmpleados(void);
void menuEspecial(void);

void crearDependencia(void);
void modificarDependencia(void);
void borrarDependencia(void);
void listarCola(void);
void listarPila(void);

void crearEmpleado(void);
void modificarEmpleado(void);
void borrarEmpleado(void);
void listar(void);

void dependencias10Empleados(void);
void EmpleadosVariasOficinas(void);



/*  ------------------------------------------  CODIGO DE LOS MENUS  ---------------------------------------------*/

main()
{
	menu();
}


void menu(void){
	
	int opc;
	opc = 2;
	
	while(opc!=0)
	{
		
		system("cls");
		
		cout<< "MENU GENERAL" << endl;
		cout<< " 1. Dependencias" << endl;
		cout<< " 2. Empleados"<< endl;
		cout<< " 3. Menu especial" << endl;
		cin>>opc;
		
		
     switch(opc)
     {
       case 1: 
	   	menuDependencias();
     	break;
       case 2:
       	menuEmpleados();
       	break;
       case 3: 
        menuEspecial();
        break;
        
        default:
        cout<< endl << "Opcion no valida" << endl;
        break;
     	
     	
     	
	 }
		
		cout << endl << "Oprima una tecla para continuar." << endl;
		getch();
			
	}
	
}


void menuDependencias(void)
{
	int opc;
	opc = 2;
	
	while(opc!=0)
	{
		
		system("cls");
		
		cout<< "    MENU DEPENDENCIAS   " << endl;
		cout<< " 1. Crear Dependencia" << endl;
		cout<< " 2. Modificar Dependencia"<< endl;
		cout<< " 3. Borrar Dependencia" << endl;
		cout<< " 4. Listar por Cola" << endl;
		cout<< " 5. Listar por Pila" << endl;
		cout<< " 6. Regresar" << endl;
		cin>>opc;
		
		 switch(opc)
       {
        	case 1: 
	   		crearDependencia();
     		break;
       		case 2:
       		modificarDependencia();
       		break;
       		case 3: 
       		borrarDependencia();
        	break;
        	case 4: 
       		listarCola();
        	break;
        	case 5: 
       		 listarPila();
        	break;
        	case 6:
        	menu();
        	break;
        	default:
        	cout<< endl << "Opcion no valida" << endl;
       		 break;
     	
     	}
		
		cout << endl << "Oprima una tecla para continuar." << endl;
		getch();
		
     }
	
	

}


void menuEmpleados(void)
{
	int opc;
	opc = 2;
	
	while(opc!=0)
	{
		
		system("cls");
		
		cout<< "    MENU EMPLEADOS   " << endl;
		cout<< " 1. Crear Empleado" << endl;
		cout<< " 2. Modificar Empleado"<< endl;
		cout<< " 3. Borrar Empleado" << endl;
		cout<< " 4. Listar" << endl;
		cout<< " 5. Regresar" << endl;
		cin>>opc;
		
		
		 switch(opc)
       {
        	case 1: 
	   		crearEmpleado();
     		break;
       		case 2:
       		modificarEmpleado();
       		break;
       		case 3: 
       		 borrarEmpleado();
        	break;
        	case 4: 
       		 listar();
        	break;
        	case 5:
        	menu();
        	break;
        	default:
        	cout<< endl << "Opcion no valida" << endl;
       		 break;
     	
     	}
		
		cout << endl << "Oprima una tecla para continuar." << endl;
		getch();
		
     }
	
	

}

void menuEspecial(void){

	int opc;
	opc = 2;
	
	while(opc!=0)
	{
		
		system("cls");
		
		cout<< "MENU ESPECIAL" << endl;
		cout<< " 1. Dependencias con mas de 10 empleados" << endl;
		cout<< " 2. Empleados pertenecientes a varias oficinas" << endl;
		cout<< " 3. Regresar" << endl;
		cin>>opc;
		
		
     switch(opc)
     {
       case 1: 
	   	dependencias10Empleados();
     	break;
       case 2:
       	EmpleadosVariasOficinas();
       	break;
       case 3: 
        menu();
        break;
        default:
        cout<< endl << "Opcion no valida" << endl;
        break;
     	
     	
     	
	 }
		
		cout << endl << "Oprima una tecla para continuar." << endl;
		getch();
			
	}
	
}





/*  ------------------------------------------  CODIGO DE LAS DEPENDENCIAS  ---------------------------------------------*/

void crearDependencia(void){
    int existe;
	nuevo = new(Oficina);


	cout <<"\n Ingrese el Codigo de la dependencia: ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
    cout<<"Ingrese el nombre : ";
    getline(cin,nuevo->nombre);
    cout<<"\n\n";
    fflush(stdin);
	
	nuevo->der = NULL;
	nuevo->izq = NULL;
	nuevo->abajo = NULL; 
		
	if ( !cab )	
	{
		cab = new(Oficina);
		cola = new(Oficina);
		cab = nuevo;
		cola = nuevo;
		
	}
	else
	{
		if ( nuevo->codigo >= cola->codigo )
		{
			if(nuevo->codigo > cola->codigo){
			nuevo->izq = cola;
			cola->der  = nuevo;
			cola       = nuevo;
			cola->der = cab; 
			cab->izq = cola; 
			}else{	
			cout<<"\n\n Codigo ya existe\n\n";
			} 
		}
		else
		{
			if ( nuevo->codigo <= cab->codigo )
			{
				if(nuevo->codigo < cab->codigo){
				nuevo->der = cab;
				cab->izq   = nuevo;
				cab        = nuevo;
				cab->izq = cola; 
				cola->der = cab;
				}else{	
				
				cout<<"\n\n Codigo ya existe\n\n";
				} 
			}
			else
			{
				bus1 = new(Oficina);
				bus2 = new(Oficina);
				bus1 = cab;
			 	bus2 = bus1->der;
			 	existe = 0;
			 	while ( existe == 0 )
			 	{
			 		if ( nuevo->codigo < bus2->codigo )
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
				if( nuevo->codigo == bus2->codigo){

						cout<<"\n\n Codigo ya existe\n\n"; 
					}	
			}			
		}		
	}
}


void modificarDependencia(void){

    
    Oficina* actual = new Oficina();
    actual=cab;
    bool encontrado=false;
    int nodoModificar=0;
    int codigoTemp;
    int codigoBuscar;


    if(cab!=NULL){

        cout<< "Ingrese el codigo de la oficina que quiere buscar para modificar:" << endl;
        cin >> codigoBuscar;
    
        do{
            
            if (actual->codigo==codigoBuscar)
            {
               cout<< endl<< endl <<  "Nodo encontrado: " <<endl;
               cout<< "Codigo: " <<  actual->codigo << endl;
               cout<< "Nombre: " <<  actual->nombre << endl;

                cout<< endl << endl << "Ingrese el nuevo codigo de la oficina:  " << endl;
                cin >> codigoTemp;
                fflush(stdin);

                Oficina* temp = new Oficina();
                 temp = cab;

                if (cab != NULL) {
                   do {
                       if (temp->codigo == codigoTemp) {
                         cout << endl << "La oficina ya existe." << endl;
                          return;
                         }
                      temp = temp->der;
                  } while (temp != cab);
                }
               
               actual->codigo = codigoTemp;
               cout<< "Codigo modificado. " << endl<< endl;

               cout<< "Ingrese el nuevo nombre de la oficina:  " << endl;
               cin>> actual->nombre;
               cout<< "Nombre modificado. " << endl<< endl;

               encontrado=true;

            }

         actual=actual->der;

        }while(actual!=cab && encontrado==false);

        if (!encontrado)
        {
            cout<< "Nodo no encontrado.";
        }
        
    
      }else{
    
        cout<<"La lista se encuentra vacia. " << endl;
    
      }





}



void borrarDependencia(void){

	int existe; 
	int codigo_borrar; 
	cout<<"Ingrese el codigo de la dependencia que desea eliminar: "; 
	cin>> codigo_borrar; 

    
	if(codigo_borrar <= cab->codigo)
	{
		if(codigo_borrar == cab->codigo)
		{

		nuevo = new(Oficina); 
		nuevo = cab; 
	
        if(nuevo->abajo==NULL) {
        cab = cab->der; 
		cab->izq = cola;
		delete(nuevo); 
		cout<< endl << "Elemento eliminado"; 
        }else{
            cout<< "La dependencia tiene empleados, no se puede eliminar. " << endl;
        }

		}
		else
		{
			cout<<"Codigo no encontrado"; 
		}

	}
	else
	{
		if(codigo_borrar >= cola->codigo)
		{
			if(codigo_borrar == cola->codigo)
			{
				nuevo = new(Oficina); 
				nuevo = cola; 
				
				if(nuevo->abajo==NULL) {
                    cola = cola->izq; 
				    cola->der = cab; 
		            delete(nuevo); 
		            cout<<"Elemento eliminado"; 
                }else{
                    cout<< "La dependencia tiene empleados, no se puede eliminar. " << endl;
                     }
			}
			else
			{
				cout<<"Codigo no encontrado"; 
			}
		}
		else
		{
			bus1 = new(Oficina); 
			bus2 = new(Oficina); 
			bus1 = cab; 
			bus2 = cab->der; 
			existe = 0; 
			while(existe == 0)
			{
				if(codigo_borrar <= bus2->codigo)
				{
					if(codigo_borrar == bus2->codigo)
					{
					nuevo = new(Oficina); 
					nuevo = bus2; 
					
                    if(nuevo->abajo==NULL) {
                        bus1->der = bus2->der; 
					    bus2->der->izq = bus1; 
		                delete(nuevo); 
		                cout<<"Elemento eliminado"; 
                        existe = 1;
                     }else{
                         cout<< "La dependencia tiene empleados, no se puede eliminar. " << endl;
                    }
				
					}
					else
					{
						cout<<"Codigo no encontrado"; 
					}
				}
				else
				{
					bus1 = bus2; 
					bus2 = bus2->der; 
				}
			}
		}
	}
}


void listarCola(void){
	if(cab != NULL){
		nuevo = new(Oficina); 	
		nuevo = cab; 
		do{
			cout<<"\nCodigo: "<< nuevo->codigo<<endl; 
			cout<<"Nombre :"<< nuevo->nombre<<endl; 
			nuevo = nuevo->der; 

		}while(nuevo != cab); 

	}else{
		cout<<"Lista vacia"; 
	}
}


void listarPila(void){
	if(cab != NULL){
		nuevo = new(Oficina); 
			
		nuevo = cola; 
		do{
			cout<<"\nCodigo: "<< nuevo->codigo<<endl; 
			cout<<"Nombre :"<< nuevo->nombre<<endl; 
			nuevo = nuevo->izq; 

		}while(nuevo != cola); 

	}else{
		cout<<"Lista vacia"; 
	}
}




/*  ------------------------------------------  CODIGO DE LOS EMPLEADOS  ---------------------------------------------*/
 void crearEmpleado(void) {
    int existe;
    int existe_oficina = 0; 
    int oficina_buscar;
    int codigo_empleado;

    nueva = new Empleado(); 

    cout << "\nIngrese el codigo de la Oficina a la que pertenece el empleado: "; 
    cin >> oficina_buscar; 

    Oficina* oficina = cab;

    if (!cab) {
        cout << "\nNo existen oficinas ";
        return;
    } 

    do {
        if (oficina_buscar == oficina->codigo) {
            existe_oficina = 1; 
            break;
        } else {
            oficina = oficina->der; 
        }
    } while (oficina != cab); 

    if (!existe_oficina) {
        cout << "No existe la oficina"; 
        return;
    }

    cout << "\n Ingrese el Codigo del empleado: ";
    cin >> codigo_empleado;
    fflush(stdin);

    Empleado* actual = oficina->abajo; 
    while (actual != NULL) {
        if (actual->codigo == codigo_empleado) {
            cout << "\n\nCodigo de empleado ya existe en esta oficina\n\n";
            return;
        }
        actual = actual->debajo;
    }

    nueva->codigo = codigo_empleado; 
    cout << "Ingrese el nombre : ";
    getline(cin, nueva->nombre);
    fflush(stdin);
    cout << "Ingrese el Sueldo del empleado: ";
    cin >> nueva->sueldo;
    fflush(stdin);
    nueva->debajo = NULL;

   
    Empleado* primero = oficina->abajo;
    Empleado* busca1 = NULL;
    Empleado* busca2 = NULL;

    if (!primero) {
        oficina->abajo = nueva;
    } else if (nueva->codigo < primero->codigo) {
        nueva->debajo = primero;
        oficina->abajo = nueva;
    } else {
        busca1 = primero;
        busca2 = primero->debajo;

        while (busca2 && nueva->codigo > busca2->codigo) {
            busca1 = busca2;
            busca2 = busca2->debajo;
        }

        busca1->debajo = nueva;
        nueva->debajo = busca2;
    }
}



void modificarEmpleado(void) {
    int codigoBuscar;
    int codigoTemp;
    int oficina_buscar;
    bool encontrado = false;

    cout << "\nIngrese el codigo de la Oficina: ";
    cin >> oficina_buscar;

    if (!cab) {
        cout << "\nNo existen oficinas.";
        return;
    }

    Oficina* oficina = cab;
    bool existe_oficina = false;

    do {
        if (oficina->codigo == oficina_buscar) {
            existe_oficina = true;
            break;
        }
        oficina = oficina->der;
    } while (oficina != cab);

    if (!existe_oficina) {
        cout << "\nNo existe la oficina.";
        return;
    }

    Empleado* actual = oficina->abajo;

    if (!actual) {
        cout << "\nNo hay empleados en esta oficina.\n";
        return;
    }

    cout << "\nIngrese el codigo del empleado que quiere buscar para modificar: ";
    cin >> codigoBuscar;

    while (actual != NULL && !encontrado) {
        if (actual->codigo == codigoBuscar) {
            cout << "\n\n-------- NODO ENCONTRADO --------" << endl;
            cout << "Codigo: " << actual->codigo << endl;
            cout << "Nombre: " << actual->nombre << endl;

            cout << "\nIngrese el nuevo codigo del empleado: ";
            cin >> codigoTemp;
            fflush(stdin);

            
            Empleado* temp = oficina->abajo;
            while (temp != NULL) {
                if (temp->codigo == codigoTemp) {
                    cout << "\nEl empleado con ese codigo ya existe en esta oficina.\n";
                    return;
                }
                temp = temp->debajo;
            }

            actual->codigo = codigoTemp;
            cout << "Codigo modificado.\n";

            cout << "Ingrese el nuevo nombre del empleado: ";
            cin >> actual->nombre;
            cout << "Nombre modificado.\n";

            encontrado = true;
        }
        actual = actual->debajo;
    }

    if (!encontrado) {
        cout << "\nEmpleado no encontrado en esta oficina.\n";
    }
}

void borrarEmpleado(void){
	 int codigo_oficina;
    int codigo_empleado;
    bool oficina_encontrada = false;

    cout << "Ingrese el codigo de la Oficina a la que pertenece el empleado: ";
    cin >> codigo_oficina;

    if (!cab) {
        cout << "\nNo existen oficinas";
        return;
    }

    Oficina* oficina = cab;
    do {
        if (oficina->codigo == codigo_oficina) {
            oficina_encontrada = true;
            if (!oficina->abajo) {
                cout << "Esta oficina no tiene empleados.\n";
                return;
            }

            cout << "Ingrese el codigo del empleado que desea eliminar: ";
            cin >> codigo_empleado;

            Empleado* actual = oficina->abajo;
            Empleado* anterior = NULL;

            while (actual) {
                if (actual->codigo == codigo_empleado) {
                    if (anterior == NULL) {
                        oficina->abajo = actual->debajo;
                    } else {
                        anterior->debajo = actual->debajo;
                    }
                    delete actual;
                    cout << "Empleado eliminado\n";
                    return;
                }
                anterior = actual;
                actual = actual->debajo;
            }

            cout << "Empleado no encontrado\n";
            return;
        }
        oficina = oficina->der;
    } while (oficina != cab);

    if (!oficina_encontrada) {
        cout << "No existe la oficina\n";
    }

}


void listar(void){
	nueva = new(Empleado); 
	nuevo = new(Oficina); 
	nuevo = cab; 
	do{
		if(nuevo->abajo != NULL){
		cout<<"Nombre oficina: "<<nuevo->nombre<<endl;
		nueva = nuevo->abajo; 
		while(nueva != NULL){
	
		
		cout<<"\nCodigo empleado: "<<nueva->codigo<<endl; 
		cout<<"Nombre empleado: "<<nueva->nombre<<endl;
		cout<<"Sueldo empleado: "<<nueva->sueldo<<endl<<endl;
		nueva = nueva->debajo; 
	} 
	}
	nuevo = nuevo->der; 
	}while(nuevo != cab); 
	
}


/*-------------------------------------------- CODIGO DEL MENU ESPECIAL ------------------------------------------------*/


void dependencias10Empleados(void){

	int contador = 0;
	nueva = new(Empleado); 
	nuevo = new(Oficina); 
	nuevo = cab; 
	bool NoExiste = false;





	do{
		if(nuevo->abajo != NULL){

		nueva = nuevo->abajo;
		
		while(nueva != NULL){

		contador++;
		nueva = nueva->debajo; 
	} 
	}

	 if(contador>10){

		cout<<endl<< "------ OFICINAS CON MAS DE 10 EMPLEADOS -------"<< endl << endl;
		cout<<"Nombre oficina: "<<nuevo->nombre<<endl;	 
		contador = 0;
		NoExiste=true;
		
		
	 }else {
		contador = 0;
	 }

	nuevo = nuevo->der; 

	}while(nuevo != cab); 
	
	if(NoExiste == false){

		cout << endl <<  "Ninguna oficina tiene mas de 10 empleados." << endl;
	}
	


}




void EmpleadosVariasOficinas() {
    if (!cab) {
        cout << "No hay oficinas registradas.\n";
        return;
    }

    Oficina* ofi1 = cab;

    do {
        Empleado* emp1 = ofi1->abajo;

        while (emp1 != NULL) {
            int codigo_actual = emp1->codigo;
            string nombre_actual = emp1->nombre;
			int sueldo = emp1->sueldo;

            Oficina* ofi2 = cab;
            int conteo = 0;

        
            do {
                Empleado* emp2 = ofi2->abajo;
                while (emp2 != NULL) {
                    if (emp2->codigo == codigo_actual) {
                        conteo++;
                        break; 
                    }
                    emp2 = emp2->debajo;
                }
                ofi2 = ofi2->der;
            } while (ofi2 != cab);

            if (conteo > 1) {
                cout << endl << "Empleado con codigo " << codigo_actual; 
				cout << endl << "Nombre: " << nombre_actual;
				cout << endl << "Sueldo: " << sueldo;
				cout << endl << "Pertenece a " << conteo << " oficinas:" << endl;
				

                
                Oficina* ofi3 = cab;
                do {
                    Empleado* emp3 = ofi3->abajo;
                    bool esta = false;

                    while (emp3 != NULL) {
                        if (emp3->codigo == codigo_actual) {
                            esta = true;
                            break;
                        }
                        emp3 = emp3->debajo;
                    }

                    if (esta) {
                        cout << "- Oficina: " << ofi3->nombre;
						cout << "- codigo: " << ofi3->codigo << endl;
			 
                    }

                    ofi3 = ofi3->der;
                } while (ofi3 != cab);
            }

            emp1 = emp1->debajo;
        }

        ofi1 = ofi1->der;
    } while (ofi1 != cab);
}