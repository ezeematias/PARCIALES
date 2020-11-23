/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : Ezequiel Unía
 Version     :
 Copyright   : Copyright
 Description : Segundo parcial Laboratorio
 ============================================================================
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#define MSG_START   "\n-----------------------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| INICIANDO PROGRAMA |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n-----------------------------------------------------------------------------------------\n"
#define MSG_OFF  	    "\n-----------------------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| APAGANDO PROGRAMA |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n-----------------------------------------------------------------------------------------\n"
#define MSG_LOAD_OK 	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| CARGANDO |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
#define MSG_LOAD_FAIL   "XXXXXXXXXXXXXXXXXXXXXXXXXXXX| NO SE ENCONTRO BASE DE DATOS |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
#define MSG_ADD_OK	 	"\n---[ CLIENTE CARGADO CORRECTAMENTE ]-----------------------------------------------------\n"
#define MSG_ADD_FAIL    "\n---[ ERROR AL CARGAR EL CLIENTE ]--------------------------------------------------------\n"
#define MSG_ADDSALES_OK	 	"\n---[ VENTA CARGADA CORRECTAMENTE ]-------------------------------------------------------\n"
#define MSG_ADDSALES_FAIL    "\n---[ ERROR AL CARGAR LA VENTA ]----------------------------------------------------------\n"
#define MSG_ID_CLIENT   "\n---[ INGRESE EL ID DEL CLIENTE ]---------------------------------------------------------\n"
#define MSG_ID_ERROR   	   "\n---[ EL ID DEL CLIENTE NO EXISTE ]-------------------------------------------------------\n"
#define MSG_ADDSALES_ID    "\n---[ EL ID DE LA VENTA ES ]--------------------------------------------------------------\n> %d\n"
#define MSG_LIST_OK 	  "----------------------[ FIN DEL LISTADO DE CLIENTES ]------------------------------------\n-----------------------------------------------------------------------------------------\n"
#define MSG_LIST_FAIL 	"\n---[ NO SE PUDO MOSTRAR LA LISTA DE CLIENTES ]-------------------------------------------\n"
#define MSG_LISTSALES_OK 	  "-------------------------[ FIN DEL LISTADO DE VENTAS ]-------------------------------------------\n-------------------------------------------------------------------------------------------------\n"
#define MSG_LISTSALES_FAIL 	"\n---[ NO SE PUDO MOSTRAR LA LISTA DE VENTAS ]-----------------------------------------------------\n"


int controller_loadFromText(LinkedList* pArrayList);
int controller_addClient(LinkedList* pArrayList);
int controller_saveAsText(LinkedList* pArrayList);
int controller_ListClient(LinkedList* pArrayList);
int controller_loadFromTextSales(LinkedList* pArrayList);
int controller_saveAsTextSales(LinkedList* pArrayList);
int controller_ListSales(LinkedList* pArrayList);
int controller_addSales(LinkedList* pArrayListSales, LinkedList* pArrayListClient);
#endif /* CONTROLLER_H_ */
