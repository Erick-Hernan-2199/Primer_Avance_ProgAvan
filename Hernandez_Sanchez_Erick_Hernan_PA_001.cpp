#include<iostream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<string>
#include<stdio.h>

using namespace std;

struct usuario 
{
	char NombreCompletoEmpleado[50]=".";
	char NombreUsuario[50] = ".";
	char Contra[50] = ".";
	char TipoUsua1[14] = "Administrador";
	char TipoUsua2[7] = "cajero";
	char Sucursal[50] = ".";
	usuario* sig;
};
struct clientes 
{
	char NombreCliente[50] = ".";
	int Telefono=0;
	char Correo[50] = ".";
	char Sucursales[50] = ".";
	int PuntosInic=0;
	clientes* sig;
};
struct Promociones
{
	char NombrePromocion[50] = ".";
	int PuntosRequerido=0;
	float Descuento=0;
	char Estatus1 [4] = "Act";
	char Estatus2 [5] = "Inac";
	Promociones* sig;
};
struct Sucursales
{
	char NombreSucursal[50] = ".";
	char Estado[50] = ".";
	char Municipio[50] = ".";
	char Calle[50] = ".";
	int NumeroExt=0;
	int NumeroInt=0;
	Sucursales* sig;
};

usuario* inicio1, * aux1 = nullptr;
clientes* inicio2, * aux2 = nullptr;
Promociones* inicio3, * aux3 = nullptr;
Sucursales* inicio4, * aux4 = nullptr;

void RegistraUsua(usuario*nuevo);
void RegistraClien(clientes*nuevo);
void RegistraPromo(Promociones*nuevo);
void RegistraSucur(Sucursales*nuevo);

void MostrarListasUsuario();
void MostrarListasCliente();
void MostrarListasPromociones();
void MostrarListasSucursales();

void leerbinario1();
void escribirbinario1();

void leerbinario2();
void escribirbinario2();

void leerbinario3();
void escribirbinario3();

void leerbinario4();
void escribirbinario4();

int main()
{
	leerbinario1();
	leerbinario2();
	leerbinario3();
	leerbinario4();
	usuario* RegisUsua = new usuario;
	clientes* RegisClien = new clientes;
	Promociones * RegisPromo = new Promociones;
	Sucursales* RegisSucur = new Sucursales;
	int TipoEstat=0;
	int Tipousa=0;
	int opciones=0;

	do
	{
		system("color 0B");
		system("cls");

		cout << "\t ***Menu***" << endl;
		cout << " 1) Registrar usuarios " << endl;
		cout << " 2) Registrar Clientes " << endl;
		cout << " 3) Registrar Promociones " << endl;
		cout << " 4) Registrar Sucursales " << endl;
		cout << " 5) Mostrar Lista de Usurio" << endl;
		cout << " 6) Mostrar Lista de Clientes" << endl;
		cout << " 7) Mostrar Lista de Promociones" << endl;
		cout << " 8) Mostrar Lista de Sucursales" << endl;
		cout << " 9) Salir del Programa " << endl;
		cout << "" << endl;

		cin >> opciones;
		cin.ignore();

		if (opciones == 1)
		{
			cout << " Ingresa el Nombre Completo del Empleado" << endl;
			cin.getline(RegisUsua->NombreCompletoEmpleado, 50);
			cout << " Ingresa el Nombre de Usuario" << endl;
			cin.getline(RegisUsua->NombreUsuario, 50);
			cout << "Ingresa una contrase" << endl;
			cin.getline(RegisUsua->Contra, 50);
			cout << " Marque que tipo de usuario es: \n 1.- Administrador \n 2.- Cajero " << endl;
			cin >> Tipousa;
			if (Tipousa == 1)
			{
				/*cin.getline*/(RegisUsua->TipoUsua1, 14);
				cin.getline(RegisUsua->TipoUsua2, 7);
			}
			else
			{
				cin.getline(RegisUsua->TipoUsua1, 14);
				/*cin.getline*/(RegisUsua->TipoUsua2, 7);
			}
			cout << " Ingresa el Nombre de la Sucursal" << endl;
			cin.getline(RegisUsua->Sucursal, 50);

			RegisUsua->sig = nullptr;

			RegistraUsua(RegisUsua);
			opciones = 0;
		}
		else if (opciones == 2) 
		{
			cout << " Ingrese el Nombre del Cliente" << endl;
			cin.getline(RegisClien->NombreCliente, 50);
			cout << " Ingrese el Numero de Telefono ( Solo numeros ) " << endl;
			scanf_s("%d", &RegisClien->Telefono);
			/* cin >> RegisClien->Telefono; */  /* solo almacena 9 numero si pones uno mas se crashea */
			cin.ignore();
			cout << " Ingrese el Correo " << endl;
			cin.getline(RegisClien->Correo, 50);
			cout << " Ingrese el Sucursales " << endl;
			cin.getline(RegisClien->Sucursales, 50);
			cout << "\n Estos son los puntos que Tienes: " << RegisClien->PuntosInic << endl; 
		
			RegisClien->sig = nullptr;
			RegistraClien(RegisClien);
			opciones = 0;
		}
		else if (opciones == 3)
		{
			cout << " Ingresa el Nombre de la Promocion" << endl;
			cin.getline(RegisPromo->NombrePromocion, 50);
			cout << " Ingresa los Puntos que Requerira esta Promocion" << endl;
			cin >> RegisPromo->PuntosRequerido;
			cout << " Ingresa el Descuento que se le Otorgara a esta Promocion " << endl;
			cin >> RegisPromo->Descuento;
			cout << " Marca el Estatus \n 1) Activado \n 2) Inactivo " << endl;
			cin >> TipoEstat;
			if ( TipoEstat== 1)
			{
				(RegisPromo->Estatus1,4);
				cin.getline(RegisPromo->Estatus2, 5);
			}
			else
			{
				cin.getline(RegisPromo->Estatus1, 4);
				(RegisPromo->Estatus2,5);
			}

			RegisPromo->sig = nullptr;
			RegistraPromo(RegisPromo);
			opciones = 0;
		}
		else if (opciones == 4) 
		{
			cout << " Ingresa el Nombre de la Sucursal" << endl;
			cin.getline(RegisSucur->NombreSucursal, 50);
			cout << " Ingresa el Nombre del Estado" << endl;
			cin.getline(RegisSucur->Estado, 50);
			cout << " Ingresa el Nombre del Municipio" << endl;
			cin.getline(RegisSucur->Municipio, 50);
			cout << " Ingresa el Nombre de la Calle" << endl;
			cin.getline(RegisSucur->Calle, 50);
			cout << " Ingresa el Numero Exterior" << endl;
			cin >> (RegisSucur->NumeroExt);
			cout << " Ingresa el Numero Interior ( En Caso De No Tener Ingresar Cero )" << endl;
			cin >> (RegisSucur->NumeroInt);

			RegisSucur->sig = nullptr;
			RegistraSucur(RegisSucur);
			opciones = 0;
		}
		else if (opciones == 5)
		{
			MostrarListasUsuario();
			cin.ignore();
			opciones = 0;
		}
		else if (opciones == 6)
		{
			MostrarListasCliente();
			cin.ignore();
			opciones = 0;
		}
		else if (opciones == 7)
		{
		    MostrarListasPromociones();
			cin.ignore();
			opciones = 0;
		}
		else if (opciones == 8)
		{
		    MostrarListasSucursales();
		    cin.ignore();
		    opciones = 0;
		}
	} while (opciones < 1 || opciones > 9);
	
	escribirbinario1();
	escribirbinario2();
	escribirbinario3();
	escribirbinario4();
	return 0;
}

void RegistraUsua(usuario* nuevo) 
{
	if (inicio1 == nullptr)
	{
		inicio1 = new usuario;

		strcpy_s(inicio1->NombreCompletoEmpleado, nuevo->NombreCompletoEmpleado);
		strcpy_s(inicio1->NombreUsuario, nuevo->NombreUsuario);
		strcpy_s(inicio1->Contra, nuevo->Contra);
		strcpy_s(inicio1->TipoUsua1, nuevo->TipoUsua1);
		strcpy_s(inicio1->TipoUsua2, nuevo->TipoUsua2);
		strcpy_s(inicio1->Sucursal, nuevo->Sucursal);

		inicio1->sig = nullptr;
	}
	else
	{
		if (aux1 == nullptr)
		{
			aux1 = inicio1;
		}
		while (aux1->sig != nullptr)
		{
			aux1 = aux1->sig;
		}
		aux1->sig = new usuario;
		aux1 = aux1->sig;
		
		strcpy_s(aux1->NombreCompletoEmpleado, nuevo->NombreCompletoEmpleado);
		strcpy_s(aux1->NombreUsuario, nuevo->NombreUsuario);
		strcpy_s(aux1->Contra, nuevo->Contra);
		strcpy_s(aux1->TipoUsua1, nuevo->TipoUsua1);
		strcpy_s(aux1->TipoUsua2, nuevo->TipoUsua2);
		strcpy_s(aux1->Sucursal, nuevo->Sucursal);

		aux1->sig = nullptr;
	
	}
}
void RegistraClien(clientes* nuevo)
{
	if (inicio2 == nullptr)
	{
		inicio2 = new clientes;

		strcpy_s(inicio2->NombreCliente, nuevo->NombreCliente);
		inicio2->Telefono = nuevo->Telefono;
		strcpy_s(inicio2->Correo, nuevo->Correo);
		strcpy_s(inicio2-> Sucursales , nuevo->Sucursales);
		inicio2-> PuntosInic= nuevo->PuntosInic;

		inicio2->sig = nullptr;
	}
	else 
	{
		if(aux2==nullptr) 
		{
			aux2 = inicio2;		
		}
		
		while(aux2->sig!=nullptr)
		{
			aux2 = aux2->sig;
		}
		aux2->sig = new clientes;
		aux2 = aux2->sig;

		strcpy_s(aux2->NombreCliente, nuevo->NombreCliente);
		aux2->Telefono = nuevo->Telefono;
		strcpy_s(aux2->Correo, nuevo->Correo);
		strcpy_s(aux2->Sucursales, nuevo->Sucursales);
		aux2->PuntosInic = nuevo->PuntosInic;
		
		aux2->sig = nullptr;
	}

}
void RegistraPromo(Promociones* nuevo)
{
	if (inicio3 == nullptr)
	{
		inicio3 = new Promociones;

		strcpy_s(inicio3->NombrePromocion, nuevo->NombrePromocion);
		inicio3->PuntosRequerido = nuevo->PuntosRequerido;
		inicio3->Descuento = nuevo->Descuento;
		strcpy_s(inicio3->Estatus1, nuevo->Estatus1);
		strcpy_s(inicio3->Estatus2, nuevo->Estatus2);

		inicio3->sig = nullptr;
	}
	else 
	{
		if (aux3 == nullptr)
		{
			aux3 = inicio3;
		}
		while (aux3->sig != nullptr) 
		{
			aux3 = aux3->sig;
		}
		aux3->sig = new Promociones;
		aux3 = aux3->sig;

		strcpy_s(aux3->NombrePromocion, nuevo->NombrePromocion);
		aux3->PuntosRequerido = nuevo->PuntosRequerido;
		aux3->Descuento = nuevo-> Descuento;
		strcpy_s(aux3->Estatus1, nuevo->Estatus1);
		strcpy_s(aux3->Estatus2, nuevo->Estatus2);

		aux3->sig = nullptr;
	}
}
void RegistraSucur(Sucursales* nuevo) 
{
	if (inicio4 == nullptr)
	{
		inicio4 = new Sucursales;
	
		strcpy_s(inicio4->NombreSucursal, nuevo->NombreSucursal);
		strcpy_s(inicio4->Estado, nuevo->Estado);
		strcpy_s(inicio4->Municipio, nuevo->Municipio);
		strcpy_s(inicio4->Calle, nuevo->Calle);
		inicio4->NumeroExt, nuevo->NumeroExt;
		inicio4->NumeroInt, nuevo->NumeroInt;

		inicio4->sig = nullptr;
	}
	else
	{
		if (aux4==nullptr)
		{
			aux4 = inicio4;
		}
		
		while (aux4->sig != nullptr)
		{
			aux4 = aux4->sig;
		}

		aux4->sig = new Sucursales;
		aux4 = aux4->sig;

		strcpy_s(aux4->NombreSucursal, nuevo->NombreSucursal);
		strcpy_s(aux4->Estado, nuevo->Estado);
		strcpy_s(aux4->Municipio, nuevo->Municipio);
		strcpy_s(aux4->Calle, nuevo->Calle);
		aux4->NumeroExt, nuevo->NumeroExt;
		aux4->NumeroInt, nuevo->NumeroInt;

		aux4->sig = nullptr;
	}
}

void MostrarListasUsuario() 
{
	system("cls");
	if (inicio1==nullptr) 
	{
		cout << " Esta Lista Esta vacia, Primero Ingresa Los Datos En El Apartado de Registros De Usuario..." << endl;
	}
	else 
	{
		aux1 = inicio1;

		while(aux1 != nullptr) 
		{
			cout << "Este Es El Nombre Completo: \n" << aux1->NombreCompletoEmpleado << endl;
			cout << "Este Es El Nombre De Usuario: \n" << aux1->NombreUsuario << endl;
			cout << "Esta Es La Contra: "<< aux1->Contra  << endl;
			cout << "Este Es El Tipo de Usuario: \n" << aux1->TipoUsua1<< aux1->TipoUsua2 << endl;
			cout << "Este Es La Sucursal: \n" << aux1->Sucursal << endl;

			aux1 = aux1->sig;
		}
	}	
}
void MostrarListasCliente()
{
	system("cls");
	if (inicio2 == nullptr)
	{
		cout << " Esta Lista Esta vacia, Primero Ingresa Los Datos En El Apartado de Clientes..." << endl;
	}
	else
	{
		aux2 = inicio2;

		while (aux2 != nullptr)
		{
			cout << "Este Es El Nombre Del Cliente: \n" << aux2->NombreCliente << endl;
			cout << "Este Es Numero De Telefono: \n" << aux2->Telefono << endl;
			cout << "Este Es El Correo: \n" << aux2->Correo << endl;
			cout << "Este Es La Sucursal: \n" << aux2->Sucursales << endl;
			cout << "Este Son Los Puntos Iniciales: \n" << aux2->PuntosInic << endl;

			aux2 = aux2->sig;
		}
	}
}
void MostrarListasPromociones()
{
	system("cls");
	if (inicio3 == nullptr)
	{
		cout << " Esta Lista Esta vacia, Primero Ingresa Los Datos En El Apartado de Promociones.." << endl;
	}
	else
	{
		aux3 = inicio3;

		while (aux3 != nullptr)
		{
			cout << "Este Es El Nombre De La Promocion: \n" << aux3->NombrePromocion << endl;
			cout << "Este Son Los Puntos Que Se Requieren: \n" << aux3->PuntosRequerido << endl;
			cout << "Este Es El Descuento Que Tendra:  %\n" << aux3->Descuento << endl;
			cout << "Este Es El Estatus: \n" << aux3->Estatus1 <<aux3->Estatus2 <<endl;

			aux3 = aux3->sig;
		}
	}
}
void MostrarListasSucursales()
{
	system("cls");
	if (inicio4 == nullptr)
	{
		cout << " Esta Lista Esta vacia, Primero Ingresa Los Datos En El apartado de Registros De Sucursales..." << endl;
	}
	else
	{
		aux4 = inicio4;

		while (aux4 != nullptr)
		{
			cout << "Este Es Nombre De La Sucursal: \n" << aux4->NombreSucursal << endl;
			cout << "Este Es El Estado: \n" << aux4->Estado << endl;
			cout << "Este Es El Municipo: \n" << aux4->Municipio << endl;
			cout << "Este Es La Calle: \n" << aux4->Calle << endl;
			cout << "Este Es Numero Ext: \n" << aux4->NumeroExt << endl;
			cout << "Este Es Numero Int: \n" << aux4->NumeroInt << endl;

			aux4 = aux4->sig;
		}
	}
}

void escribirbinario1()
{
	aux1 = inicio1;

	ofstream EscribirUsuario;
	EscribirUsuario.open("EscribeUsuarios.bin", ios::out | ios::binary | ios::trunc);

	if (EscribirUsuario.is_open()) 
	{
		while (aux1 != nullptr) 
		{
			EscribirUsuario.write((char*)aux1,(sizeof usuario));
			aux1 = aux1->sig;
		}
		EscribirUsuario.close();
	}
	else 
	{
		cout<<" No Se Puedo Abrir El Archivo De Usuarios..."<<endl;
		system("Pause");	
	}
}
void leerbinario1() 
{
	ifstream leerUsuario;
	leerUsuario.open("EscribeUsuarios.bin", ios::in | ios::binary);

	if (leerUsuario.is_open())
	{
		usuario* Usuarioleido = new usuario;

		while (!leerUsuario.read((char*)Usuarioleido, sizeof(usuario)).eof());
		{
			if (inicio1 == nullptr)
			{
				inicio1 = Usuarioleido;
				inicio1->sig = nullptr;
				aux1 = inicio1;
			}
			else
			{
				aux1->sig = Usuarioleido;
				aux1 = aux1->sig;
				aux1->sig = nullptr;
			}
			Usuarioleido = new usuario;
		}
		leerUsuario.close();
		delete Usuarioleido;
	}
	else 
	{ 
		cout << "No Se Puedo Abrir El Archivo De Usuarios...." << endl;
		system("pause");
	}
}

void escribirbinario2()
{
	aux2 = inicio2;

	ofstream EscribirClientes;
	EscribirClientes.open("EscribeClientes.bin", ios::out | ios::binary | ios::trunc);

	if (EscribirClientes.is_open())
	{
		while (aux2 != nullptr)
		{
			EscribirClientes.write((char*)aux2, (sizeof clientes));
			aux2 = aux2->sig;
		}
		EscribirClientes.close();
	}
	else
	{
		cout << " No se Puedo abrir el Archivo de Clientes..." << endl;
		system("Pause");
	}
}
void leerbinario2()
{
	ifstream leerClientes;
	leerClientes.open("EscribeClientes.bin", ios::in | ios::binary);

	if (leerClientes.is_open())
	{
		clientes* Clienteleido = new clientes;

		while (!leerClientes.read((char*)Clienteleido, sizeof(clientes)).eof());
		{
			if (inicio2 == nullptr)
			{
				inicio2 = Clienteleido;
				inicio2->sig = nullptr;
				aux2 = inicio2;
			}
			else
			{
				aux2->sig = Clienteleido;
				aux2 = aux2->sig;
				aux2->sig = nullptr;
			}
			Clienteleido = new clientes;
		}
		leerClientes.close();
		delete Clienteleido;
	}
	else
	{
		cout << "No Se Puedo Abrir El Archivo De Clientes...." << endl;
		system("pause");
	}
}

void escribirbinario3()
{
	aux3 = inicio3;

	ofstream EscribirPromociones;
	EscribirPromociones.open("EscribePromociones.bin", ios::out | ios::binary | ios::trunc);

	if (EscribirPromociones.is_open())
	{
		while (aux3 != nullptr)
		{
			EscribirPromociones.write((char*)aux3, (sizeof Promociones));
			aux3 = aux3->sig;
		}
		EscribirPromociones.close();
	}
	else
	{
		cout << " No se Puedo abrir el Archivo de Promociones..." << endl;
		system("Pause");
	}
}
void leerbinario3()
{
	ifstream leerPromociones;
	leerPromociones.open("EscribePromociones.bin", ios::in | ios::binary);

	if (leerPromociones.is_open())
	{
		Promociones* Promocionesleido = new Promociones;

		while (!leerPromociones.read((char*)Promocionesleido, sizeof(Promociones)).eof());
		{
			if (inicio3 == nullptr)
			{
				inicio3 = Promocionesleido;
				inicio3->sig = nullptr;
				aux3 = inicio3;
			}
			else
			{
				aux3->sig = Promocionesleido;
				aux3 = aux3->sig;
				aux3->sig = nullptr;
			}
			Promocionesleido = new Promociones;
		}
		leerPromociones.close();
		delete Promocionesleido;
	}
	else
	{
		cout << "No Se Puedo Abrir El Archivo De Promociones...." << endl;
		system("pause");
	}
}

void escribirbinario4()
{
	aux4 = inicio4;

	ofstream EscribirSucursales;
	EscribirSucursales.open("EscribeSucursales.bin", ios::out | ios::binary | ios::trunc);

	if (EscribirSucursales.is_open())
	{
		while (aux4 != nullptr)
		{
			EscribirSucursales.write((char*)aux4, (sizeof Sucursales));
			aux4 = aux4->sig;
		}
		EscribirSucursales.close();
	}
	else
	{
		cout << " No se Puedo abrir el Archivo de Sucursales..." << endl;
		system("Pause");
	}
}
void leerbinario4()
{
	ifstream leerSucursales;
	leerSucursales.open("EscribeUsuarios.bin", ios::in | ios::binary);

	if (leerSucursales.is_open())
	{
		Sucursales* Sucursalesleido = new Sucursales;

		while (!leerSucursales.read((char*)Sucursalesleido, sizeof(Sucursales)).eof());
		{
			if (inicio4 == nullptr)
			{
				inicio4 = Sucursalesleido;
				inicio4->sig = nullptr;
				aux4 = inicio4;
			}
			else
			{
				aux4->sig = Sucursalesleido;
				aux4 = aux4->sig;
				aux4->sig = nullptr;
			}
			Sucursalesleido = new Sucursales;
		}
		leerSucursales.close();
		delete Sucursalesleido;
	}
	else
	{
		cout << "No Se Puedo Abrir El Archivo De Sucursales...." << endl;
		system("pause");
	}
}