/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : Ezequiel Unía
 Version     :
 Copyright   : Copyright
 Description : Segundo parcial Laboratorio
 ============================================================================
 */

#ifndef SALES_H_
#define SALES_H_
#define PATH_ID_SALES "salesID.txt"
#define PATH_SALES "sales.txt"
#define LONG_FILE 31
#define MSG_QTY_POSTERS "\n---[ INGRESE LA CANTIDAD DE AFICHES ]----------------------------------------------------\n"
#define MSG_SALES_ID 	"\n---[ LA VENTA A MODIFICAR ES ]-----------------------------------------------------------\n"
#define MSG_FILE 		"\n---[ INGRESE EL NOMBRE DEL ARCHIVO CON SU EXTENSIÓN ]------------------------------------\n"
#define MSG_ZONE 				"\n---[ INGRESE LA ZONA ]-------------------------------------------------------------------\n[1] -> CABA\n[2] -> ZONA SUR\n[3] -> ZONA OESTE\n\n[OPCIÓN SELECCIONADA]"
#define MSG_SALES_MODIFY 		"\n---[ SELECCIONE UNA OPCIÓN A MODIFICAR ]-------------------------------------------------\n[1] -> CANTIDAD DE AFICHES\n[2] -> NOMBRE DEL ARCHIVO\n[3] -> ZONA\n[0] -> ATRAS\n\n[OPCIÓN SELECCIONADA]"
#define MSG_PRINT_SALES "\n-------------------------------------------------------------------------------------------------\n|| -[VENTA]- || -[CLIENTE]- || -[AFICHES]- || -[NOMBRE DEL ARCHIVO]- || -[ZONA]- || -[ESTADO]- ||\n-------------------------------------------------------------------------------------------------"
#define MSG_PRINT_S "\n|| > %4d    || > %5d     ||   %5d    || %-23s ||   %4d   ||   %5d    ||"
#define MSG_PRINT_OUT_S  "\n-------------------------------------------------------------------------------------------------\n"
#define MSG_SALES_CONFIRM  "\n---[ ¿DESEA GUARDAR LOS DATOS MODIFICADOS? ]---------------------------------------------\n[1] -> SI\n[0] -> NO\n\n[OPCIÓN SELECCIONADA]"
#define MSG_SALES_CHARGED  "\n---[ ¿DESEA CAMBIAR EL ESTADO A COBRADO? ]-----------------------------------------------\n[1] -> SI\n[0] -> NO\n\n[OPCIÓN SELECCIONADA]"

typedef struct
{
    int idSales;
    int idClient;
    int quantityPosters;
    char fileName[LONG_FILE];
    int zone;
    int status;
}Sales;

Sales* sales_new();
void sales_delete(Sales* this);
int sales_setIdSales(Sales* this, int idSales);
int sales_getIdSales(Sales* this, int* idSales);
int isValidIdSales(int idSales);
int sales_setIdClient(Sales* this, int idClient);
int sales_getIdClient(Sales* this, int* idClient);
int isValidIdClientSales(int idClient);
int sales_setQuantityPosters(Sales* this, int quantityPosters);
int sales_getQuantityPosters(Sales* this, int* quantityPosters);
int isValidQuantityPosters(int quantityPosters);
int sales_setFileName(Sales* this, char* fileName);
int sales_getFileName(Sales* this, char* fileName);
int isValidFileName(char* fileName);
int sales_setZone(Sales* this, int zone);
int sales_getZone(Sales* this, int* zone);
int isValidZone(int zone);
int sales_setStatus(Sales* this, int status);
int sales_getStatus(Sales* this, int* status);
int isValidStatus(int status);
Sales* sales_newWithParameters(int idSales,int idClient,int quantityPosters,char* fileName,int zone,int status);
Sales* sales_newParameters(char* idSales,char* idClient,char* quantityPosters,char* fileName,char* zone,char* status);
Sales* sales_add(int idClient);
int sales_modify(Sales* this);
int sales_charged(Sales* this);
int sales_newId(char* path);
int sales_saveId(char* path, int id);
int sales_print(Sales* this);
int sales_typeStatus(void* this, void* status);
int sales_findByIdSales(void* this, void* idSales);
int sales_findByIdClientInSales(void* this, void* idSales);
int sales_isCharged(void* this, void* idClient);
int sales_toCharged(void* this, void* idClient);
int sales_quantityPostersposters(void* this, void* idClient);

#endif /* SALES_H_ */
