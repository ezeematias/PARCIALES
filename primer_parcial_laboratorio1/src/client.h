/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "utn.h"
#define LONG_NAME 51
#define LONG_LASTNAME 51
#define LONG_CUIT 14
#define LONG_CLIENT 100
#define MSG_NAME "\n--------- INGRESE NOMBRE ----------"
#define MSG_LASTNAME "\n-------- INGRESE APELLIDO ---------"
#define MSG_CUIT "\n---------- INGRESE CUIT -----------"
#define MSG_IDCLIENT "\n----------- ID CLIENTE ------------\n> %d"
#define MSG_ID "\n------- INGRESE ID CLIENTE --------\n"
#define MSG_ID_FAIL "\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\n-----------------------------------\n"
#define MSG_ID_PAUSED "\n-----------------------------------\nX| YA ESTÁ PAUSADA ESA PUBLICACIÓN |X\n-----------------------------------\n"
#define MSG_ID_ACTIVE "\n-----------------------------------\nX| YA ESTÁ ACTIVA ESTA PUBLICACIÓN |X\n-----------------------------------\n"
#define MSG_ID_FAILATTE "\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\nXXX|    NO HAY MÁS INTENTOS    |XXX\n-----------------------------------"
#define MSG_NAME_OK "\n-----------------------------------\nXXXXXXXX| NOMBRE CARGADO |XXXXXXXXX\n-----------------------------------\n"
#define MSG_NAME_FAIL "\n-----------------------------------\nXXXXX| NO SE CARGÓ EL NOMBRE |XXXXX\n-----------------------------------\n"
#define MSG_LASTNAME_OK 	"\n-----------------------------------\nXXXXXXX| APELLIDO CARGADO |XXXXXXXX\n-----------------------------------\n"
#define MSG_LASTNAME_FAIL   "\n-----------------------------------\nXXXX| NO SE CARGÓ EL APELLIDO |XXXX\n-----------------------------------\n"
#define MSG_CUIT_OK "\n-----------------------------------\nXXXXXXXXX| CUIT CARGADO |XXXXXXXXXX\n-----------------------------------\n"
#define MSG_CUIT_FAIL "\n-----------------------------------\nXXXXXX| NO SE CARGÓ EL CUIT |XXXXXX\n-----------------------------------\n"
#define MSG_OPTION_MODIFY "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> MODIFICAR NOMBRE\n[2] -> MODIFICAR APELLIDO\n[3] -> MODIFICAR CUIT\n[0] -> ATRAS\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_REMOVE "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> CONFIRMAR ELIMINACIÓN\n[0] -> ATRAS\n\n[OPCIÓN SELECCIONADA]"
#define MSG_ERROR "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n"
#define MSG_NOMORESPACE "-----------------------------------\nXXXXXX| NO HAY ESPACIO PARA |XXXXXX\nXXXXXX|   NUEVOS CLIENTES   |XXXXXX\n-----------------------------------\n\n"
#define MSG_CUIT_DUPLICATED "\n-- [EL CUIT INGRESADO YA EXISTE] --"
#define MSG_INFOCLIENT "\n------ CLIENTE A MODIFICAR -------\n\n[ID] -------> %d\n[NOMBRE] ---> %s\n[APELLIDO] -> %s\n[CUIT] -----> %s\n[INDEX] ----> %d\n"
#define MSG_PRINT_CLIENTINDEX "\n-----------------------------------------------------------------------------------\n|| --[ID]-- || ------[NOMBRE]------ || -----[APELLIDO]----- || -----[CUIT]------ ||\n-----------------------------------------------------------------------------------"
#define MSG_PRINT_INDEX "\n|| > %d   || %-20s || %-20s || %17s ||"
#define MSG_PRINT_INDEX_OUT "\n-----------------------------------------------------------------------------------\n"

struct
{
	int idClient;
	char name[LONG_NAME];
	char lastName[LONG_LASTNAME];
	char cuit[LONG_CUIT];
	int isEmpty;

}typedef Client;

int client_newId(void);
int client_add(Client* list, int len);
int client_serchIndexEmpty(Client* list, int len);
int client_initClient(Client* list, int len);
int client_print(Client* list, int len);
int client_modify(Client* list, int len);
int client_findById(Client* list, int len,int id);
int client_sort(Client* list, int len, int order);
int client_findByCuit(Client* list, int len,char* cuit);
int client_remove(Client* list, int len);
int client_printIdex(Client* list, int index);
int client_ArrayIsEmpty (Client* list, int len);

#endif /* CLIENT_H_ */
