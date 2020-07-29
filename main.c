#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "validaciones.h"

#define TAMCLIENTE 5
#define TAMALQUILER 30
#define TAMEQUIPO 3
#define TAMOPERADOR 3

int menu();

int main()
{
    int seguir = 0;
    int seguir2 = 0;
	int idClientes = 1;
	int idAlquileres = 1;
	int flag = 0;
	int flag2 = 0;

	eCliente clientes[TAMCLIENTE];
	eAlquiler alquileres[TAMALQUILER];

	eEquipo equipos[TAMEQUIPO] = {{1, "Amoladora"}, {2, "Mezcladora"}, {3, "Taladro"}};
    eOperador operadores[TAMOPERADOR] = {{1, "Juan", "Perez"}, {2, "Aaron", "Costa"}, {3, "Lucia", "Garcia"}};

	inicializarClientes(clientes, TAMCLIENTE);
	inicializarAlquileres(alquileres, TAMALQUILER);

    do
	{
		switch(menu())
		{
		case 1:
            if(!(altaCliente(idClientes, clientes, TAMCLIENTE)))
			{
				idClientes++;
				flag = 1;
			}
			break;

		case 2:
            if(flag)
            {
                modificarCliente(clientes, TAMCLIENTE);
            }
            else
            {
                printf("\n**Debe dar de alta un cliente primero**\n");
            }
			break;

		case 3:
            if(flag)
            {
                bajaCliente(clientes, TAMCLIENTE);
            }
            else
            {
                printf("\n**Debe dar de alta un cliente primero**\n");
            }
			break;

		case 4:
            if(flag)
            {
                if(!altaAlquiler(idAlquileres, clientes, TAMCLIENTE, alquileres, TAMALQUILER, equipos, TAMEQUIPO, operadores, TAMOPERADOR))
                {
                    idAlquileres++;
                    flag2 = 1;
                }
            }
            else
            {
                printf("\n**Debe dar de alta un cliente primero**\n");
            }
			break;

		case 5:
            if(flag2)
            {
                finalizarAlquiler(clientes, TAMCLIENTE, alquileres, TAMALQUILER, equipos, TAMEQUIPO, operadores, TAMOPERADOR);
            }
            else
            {
                printf("\n**Debe dar de alta un alquiler primero**\n");
            }
			break;

		case 6:
		    if(flag2)
            {
                do
                {
                    switch(menuInformes())
                    {
                    case 1:
                        informarClienteMasAlquilados(clientes, TAMCLIENTE, alquileres, TAMALQUILER);
                        break;
                    case 2:
                        informarEquipoMasAlquilado(alquileres, TAMALQUILER, equipos, TAMEQUIPO);
                        break;
                    case 3:
                        informarTiempoEquipos(equipos, TAMEQUIPO, alquileres, TAMALQUILER);
                        break;
                    case 4:
                        imprimirClientesAlquileres(clientes, TAMCLIENTE, alquileres, TAMALQUILER, equipos, TAMEQUIPO);
                        break;
                    case 5:
                        seguir2 = 1;
                        break;
                    }
                    system("pause");
                }while(seguir2 == 0);
            }
            else
            {
                printf("\n**Debe dar de alta un alquiler primero**\n");
            }
			break;

		case 7:
            seguir = 1;
            break;
			}
			system("pause");
		}while(seguir == 0);

    return 0;
}

int menu()
{
	system("cls");
	int opcion;

	printf("--------M E N U--------\n");
	printf("1.Alta cliente\n");
	printf("2.Modificar cliente\n");
	printf("3.Baja cliente\n");
	printf("4.Nuevo alquiler\n");
	printf("5.Fin del alquiler\n");
	printf("6.Informar\n");
	printf("7.Salir\n");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion : ", "\nError.\n", 1, 7);

	return opcion;
}
