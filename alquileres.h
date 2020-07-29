#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
	int id;
	int dni;
	char nombre[20];
	char apellido[20];
	char estado[20];
	int isEmpty;

}eCliente;

typedef struct
{
	int id;
	char nombre[20];
	char apellido[20];

}eOperador;

typedef struct
{
    int idAlquiler;
	int idCliente;
	int idEquipo;
	int tiempoEstimado;
	int tiempoReal;
	int idOperador;
	char estado[20];
	int isEmpty;

}eAlquiler;

typedef struct
{
	int idEquipo;
	char descripcion[20];
}eEquipo;

/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE(1) en todas las posiciones del array.
* \param eCliente clientes[]
* \param int tamC
* \return int
*/
int inicializarClientes(eCliente clientes[], int tamC);

/** \brief Imprime el array de forma encolumnada.
* \param eCliente clientes[]
* \param int tamC
* \return no devuelve nada
*/
int imprimirClientes(eCliente clientes[], int tamC);

/** \brief Imprime una posicion del array
* \param eCliente cliente
* \param int tamC
* \return no devuelve nada
*/
void imprimirCliente(eCliente cliente, int tamC);

/** \brief Agrega un cliente
* \param int idC
* \param eCliente clientes[]
* \param int tamC
* \return 1 en caso de error, 0 en caso de exito
*/
int altaCliente(int idC, eCliente clientes[], int tamC);

/** \brief Busca una posicion libre
* \param eCliente clientes[]
* \param int tamC
* \return devuelve el indice libre o -1 si hay error
*/
int buscarLibreCliente(eCliente clientes[], int tamC);

/** \brief Inhabilita un cliente
* \param eCliente clientes[]
* \param nt tamC
* \return no devuelve nada
*/
int bajaCliente(eCliente clientes[], int tamC);

/** \brief Busca un cliente recibiendo como parámetro de búsqueda su Id.
* \param int id
* \param eCliente clientes[]
* \param int tam
* \return devuelve el indice de la mascota o -1 si hay error
*/
int buscarCliente(int id, eCliente clientes[], int tam);

/** \brief Imprime el menu de modificaciones
 * \return int opcion
 */
int menuModificar();

/** \brief Modifica nombre o apellido de un cliente
* \param eCliente clientes[]
* \param int tamC
* \return int
*/
int modificarCliente(eCliente clientes[], int tamC);

/** \brief Busca una posicion libre
* \param eAlquiler alquileres[]
* \param int tamA
* \return devuelve el indice libre o -1 si hay error
*/
int buscarLibreAlquiler(eAlquiler alquileres[], int tamA);

/** \brief Agrega un alquiler
* \param int idA
* \param eCliente clientes[]
* \param int tamC
* \param eAlquiler alquileres[]
* \param int tamA
* \param eEquipo equipos[]
* \param int tamE
* \param eOperador operadores[]
* \param int tamO
* \return 1 en caso de error, 0 en caso de exito
*/
int altaAlquiler(int idA, eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA, eEquipo equipos[], int tamE, eOperador operadores[], int tamO);

/** \brief Imprime el array de equipos de forma encolumnada.
* \param eEquipo equipos[]
* \param int tamt
* \return no devuelve nada
*/
void listarEquipos(eEquipo equipos[], int tamt);

/** \brief Imprime el array de operadores de forma encolumnada.
* \param eOperador operadores[]
* \param int tamO
* \return no devuelve nada
*/
void listarOperadores(eOperador operadores[], int tamO);

/** \brief Imprime el array de forma encolumnada.
* \param eAlquiler alquileres[]
* \param int tamE int tamA
* \param eEquipo equipos[]
* \param int tamE
* \return no devuelve nada
*/
int imprimirAlquileres(eAlquiler alquileres[], int tamA, eEquipo equipos[], int tamE);

/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE(1) en todas las posiciones del array.
* \param eAlquiler alquileres[]
* \param int tamA
* \return int
*/
int inicializarAlquileres(eAlquiler alquileres[], int tamA);

/** \brief Imprime una posicion del array
* \param eAlquiler alquiler
* \param int tamA
* \param eEquipo equipos[]
* \param int tamE
* \return no devuelve nada
*/
void imprimirAlquiler(eAlquiler alquiler, int tamA, eEquipo equipos[], int tamE);

/** \brief Carga la descripcion del tipo de equipo
* \param char descripcion[]
* \param int idEquipo
* \param eEquipo equipos[]
* \param int tamE
* \return 1 en caso de error, 0 en caso de exito
*/
int cargarDescripcionEquipo(char descripcion[], int idEquipo, eEquipo equipos[], int tamE);

/** \brief Busca un alquiler recibiendo como parámetro de búsqueda su Id.
* \param int id
* \param eAlquiler alquileres[]
* \param int tam
* \return devuelve el indice de la mascota o -1 si hay error
*/
int buscarAlquiler(int idAlquiler, eAlquiler alquileres[], int tam);

/** \brief Finaliza un alquiler
* \param eCliente clientes[]
* \param int tamC
* \param eAlquiler alquileres[]
* \param int tamA
* \param eEquipo equipos[]
* \param int tamE
* \param eOperador operadores[]
* \param int tamO
* \return int
*/
int finalizarAlquiler(eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA, eEquipo equipos[], int tamE, eOperador operadores[], int tamO);

/** \brief Imprime el menu de informes
 * \return int opcion
 */
int menuInformes();

/** \brief Informa el equipo mas alquilado
 * \param eAlquiler alquileres[]
 * \param int tamA
 * \param eEquipo equipos[]
 * \param int tamE
 * \return void
 */
void informarEquipoMasAlquilado(eAlquiler alquileres[], int tamA, eEquipo equipos[], int tamE);

/** \brief Informa el promedio de tiempo real del equipo elegido
 * \param eEquipo equipos[]
 * \param int tamE
 * \param eAlquiler alquileres[]
 * \param int tamA
 * \return void
 */
void informarTiempoEquipos(eEquipo equipos[], int tamE, eAlquiler alquileres[], int tamA);

/** \brief Imprime todos los clientes con todos sus alquieres
 * \param eCliente clientes[]
 * \param int tamC
 * \param eAlquiler alquileres[]
 * \param int tamA
 * \param eEquipo equipos[]
 * \param int tamE
 * \return int
 */
int imprimirClientesAlquileres(eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA, eEquipo equipos[], int tamE);

/** \brief Informa el cliente con mas equipos alquilados
 * \param eCliente clientes[]
 * \param int tamC
 * \param eAlquiler alquileres[]
 * \param int tamA
 * \return void
 */
void informarClienteMasAlquilados(eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA);

#endif // ALQUILERES_H_INCLUDED
