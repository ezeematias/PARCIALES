/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
*/

#ifndef LOGIC_H_
#define LOGIC_H_
#include "client.h"
#include "publicity.h"
#include "utn.h"

#define MSG_START "-----------------------------------\nXXXXXXX| INICIANDO PROGRAMA |XXXXXXX\n-----------------------------------\n"
#define MSG_OFF  "------------------------------------\nXXXXXXX| APAGANDO PROGRAMA |XXXXXXX\n------------------------------------\n"
#define MSG_OPTION_MENU "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> AGREGAR NUEVO CLIENTE\n[2] -> MODIFICAR CLIENTE\n[3] -> BAJA DE CLIENTE\n[4] -> NUEVA PUBLICACIÓN\n[5] -> PAUSAR PUBLICACIÓN\n[6] -> RENADUAR PUBLICACIÓN\n[7] -> IMPRIMIR CLIENTES\n[8] -> INFORMES\n\n[0] -> SALIR\n\n[OPCIÓN SELECCIONADA]"
#define MSG_REPORT_MENU "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> CLIENTE CON MÁS PUBLICACIONES\n[2] -> CANTIDAD DE PUBLICACIONES PAUSADAS\n[3] -> RUBRO CON MÁS PUBLICACIONES\n\n[0] -> SALIR\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_ISACTIVE "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> CONFIRMAR CAMBIO\n[0] -> ATRAS\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_ERROR "------------ ERROR ------------"
#define MSG_CLIENT_FAIL    "------------------------------------\nX [DEBE INGRESAR CLIENTES PRIMERO] X\n------------------------------------\n"
#define MSG_PUBLICITY_FAIL "------------------------------------\nX [NO HAY PUBLICIDADES INGRESADAS] X\n------------------------------------\n"
#define MSG_ACTIVE_FAIL "\n-----------------------------------\nXX| NO HAY PUBLICIDADES ACTIVAS |XX\n-----------------------------------\n"
#define MSG_PAUSED_FAIL "\n-----------------------------------\nXX| NO HAY PUBLICIDADES PAUSADAS |XX\n-----------------------------------\n"
#define MSG_ADD_OK "\n----- [CARGADO CORRECTAEMTNE] -----\n"
#define MSG_ADD_FAIL 	"\n------ [NO SE CARGÓ CLIENTE] ------\n"
#define MSG_MODIFY_OK   "\n---- [MODIFICADO CORRECTAMENTE] ---\n"
#define MSG_MODIFY_FAIL "\n----- [NO SE MODIFICÓ CLIENTE] ----\n"
#define MSG_REMOVE_OK   "\n---- [ELIMINADO CORRECTAMENTE] ----\n"
#define MSG_REMOVE_FAIL "\n----- [NO SE ELIMINÓ CLIENTE] -----\n"
#define MSG_ADD_PUBLICITY_OK  "\n----- [CREADO CORRECTAMENTE] -----\n"
#define MSG_ADD_PUBLICITY_FAIL   "\n---- [NO SE CARGÓ PUBLICIDAD] ----\n"
#define MSG_PAUSED_PUBLICITY_OK  "\n----- PUBLICIDADES PAUSADAS ------\n> %d"
#define MSG_PAUSED_PUBLICITY_FAIL "\n- [NO HAY PUBLICACIONES PAUSADAS]-\n"

int logic_menu (void);
int logic_addPublicity (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_isActivePublicity (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_removeClient (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_print(Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_report(Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_isPausedPublicity (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity);

#endif /* LOGIC_H_ */
