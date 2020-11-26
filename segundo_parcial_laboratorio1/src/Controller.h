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
#define PATH_REPORT_IS_CHARGED  "isCharged.txt"
#define PATH_REPORT_TO_CHARGED  "toCharged.txt"
#define MSG_START   "\n-----------------------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| INICIANDO PROGRAMA |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n-----------------------------------------------------------------------------------------\n"
#define MSG_OFF  	    "\n-----------------------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| APAGANDO PROGRAMA |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n-----------------------------------------------------------------------------------------\n"
#define MSG_LOAD_OK 	"-----------------------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| CARGANDO |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n-----------------------------------------------------------------------------------------\n"
#define MSG_LOAD_FAIL   "XXXXXXXXXXXXXXXXXXXXXXXXXXXX| NO SE ENCONTRO BASE DE DATOS |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
#define MSG_ADD_OK	 	"\n---[ CLIENTE CARGADO CORRECTAMENTE ]-----------------------------------------------------\n"
#define MSG_CLIENT_MAXPOSTERS	 	"\n---[ EL MÁXIMO DE AFICHES VENDIDO FUERON DE %d Y LOS COMPRARON ]------------------------------------\n"
#define MSG_CLIENT_MINPOSTERS	 	"\n---[ EL MÍNIMO DE AFICHES VENDIDO FUERON DE %d Y LOS COMPRARON ]------------------------------------\n"
#define MSG_SALES_POSTERS	 		"\n---[ LA VENTA CON MÁS AFICHES VENDIDOS FUERON ]-----------------------------------------------------\n"
#define MSG_ADD_FAIL    "\n---[ ERROR AL CARGAR EL CLIENTE ]--------------------------------------------------------\n"
#define MSG_CLIENT_ERROR    "\n---[ NO HAY AFICHES COBRADOS ]-----------------------------------------------------------\n"
#define MSG_ADDSALES_OK	 	"\n---[ VENTA CARGADA CORRECTAMENTE ]-------------------------------------------------------\n"
#define MSG_ADDSALES_FAIL    "\n---[ ERROR AL CARGAR LA VENTA ]----------------------------------------------------------\n"
#define MSG_MODIFYSALES_OK	 	"\n---[ VENTA MODIFICADA CORRECTAMENTE ]----------------------------------------------------\n"
#define MSG_MODIFYSALES_FAIL    "\n---[ ERROR AL MODIFICAR LA VENTA ]-------------------------------------------------------\n"
#define MSG_IS_CHARGED_OK	 	"\n---[ ARCHIVO DE CLIENTES CON VENTAS COBRADAS CREADO CON ÉXITO ]--------------------------\n"
#define MSG_IS_CHARGED_FAIL     "\n---[ ERROR AL CREAR ARCHIVO DE CLIENTES CON VENTAS COBRADAS ]----------------------------\n"
#define MSG_TO_CHARGED_OK	 	"\n---[ ARCHIVO DE CLIENTES CON VENTAS SIN COBRAR CREADO CON ÉXITO ]------------------------\n"
#define MSG_TO_CHARGED_FAIL     "\n---[ ERROR AL CREAR ARCHIVO DE CLIENTES CON VENTAS SIN COBRAR ]--------------------------\n"
#define MSG_GENERAL_OK	 		"\n---------------------[ FIN DEL LISTADO DE ESTADISTICAS ]---------------------------------\n"
#define MSG_GENERAL_FAIL        "\n---[ ERROR AL CREAR LA ESTADISTICA GENERAL ]---------------------------------------------\n"
#define MSG_ID_CLIENT   "\n---[ INGRESE EL ID DEL CLIENTE ]---------------------------------------------------------\n"
#define MSG_ID_ERROR   	   		"\n---[ EL ID DEL CLIENTE NO EXISTE ]-------------------------------------------------------\n"
#define MSG_ID_SALES   			"\n---[ INGRESE EL ID DE LA VENTA ]---------------------------------------------------------\n"
#define MSG_ID_SALES_ERROR   	"\n---[ EL ID DE LA VENTA NO EXISTE ]-------------------------------------------------------\n"
#define MSG_STATUS_ERROR   		"\n---[ NO HAY VENTAS A COBRAR ]------------------------------------------------------------\n"
#define MSG_ADDSALES_ID    "\n---[ EL ID DE LA VENTA ES ]--------------------------------------------------------------\n> %d\n"
#define MSG_LIST_OK 	  "----------------------[ FIN DEL LISTADO DE CLIENTES ]------------------------------------\n-----------------------------------------------------------------------------------------\n"
#define MSG_LIST_FAIL 	"\n---[ NO SE PUDO MOSTRAR LA LISTA DE CLIENTES ]-------------------------------------------\n"
#define MSG_LISTSALES_OK 	  "-------------------------[ FIN DEL LISTADO DE VENTAS ]-------------------------------------------\n-------------------------------------------------------------------------------------------------\n"
#define MSG_LISTSALES_FAIL 		"\n---[ NO SE PUDO MOSTRAR LA LISTA DE VENTAS ]-----------------------------------------------------\n"
#define MSG_PRINT_SALESCUIT 	"\n---------------------------------------------\n|| --[ID SALES]-- || --------[CUIT]------- ||\n---------------------------------------------"
#define MSG_PRINT_SALESID_CUITCLIENT 	"\n||      %4d      ||  %19s  ||"
#define MSG_PRINT_SALESCUIT_OUT 		"\n---------------------------------------------\n"

int controller_loadFromText(LinkedList* pArrayList);
int controller_addClient(LinkedList* pArrayList);
int controller_saveAsText(LinkedList* pArrayList);
int controller_ListClient(LinkedList* pArrayList);
int controller_loadFromTextSales(LinkedList* pArrayList);
int controller_saveAsTextSales(LinkedList* pArrayList);
int controller_ListSales(LinkedList* pArrayList);
int controller_addSales(LinkedList* pArrayListSales, LinkedList* pArrayListClient);
int controller_editSales(LinkedList* pArrayListSales, LinkedList* pArrayListClient, int option);
int controller_findByIdSaleTheIdClient(LinkedList* pArrayListSales, int id, int* idClient);
int controller_findByIdSales(LinkedList* pArrayListSales, int id, int* index);
int controller_findByIdClient(LinkedList* pArrayListClient, int id, int* index);
int controller_isChargedReport(LinkedList* pArrayListSales, LinkedList* pArrayListClient);
int controller_toChargedReport(LinkedList* pArrayListSales, LinkedList* pArrayListClient);
int controller_generalStatistics(LinkedList* pArrayListSales, LinkedList* pArrayListClient);
int controller_listSalesCuit(LinkedList* pArrayListSales, LinkedList* pArrayListClient);
int controller_maxPosters(LinkedList* pArrayListSales);
#endif /* CONTROLLER_H_ */
