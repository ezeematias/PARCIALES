/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
 */

#ifndef PUBLICITY_H_
#define PUBLICITY_H_
#include "utn.h"
#define LONG_TEXT 65
#define LONG_PUBLICITY 1000
#define MSG_AREA "\n---------- INGRESE AREA -----------"
#define MSG_TEXT "\n---- INGRESE TEXTO PUBLICITARIO ---"
#define MSG_ERROR "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n"
#define MSG_IDPUBLICITY "\n---------- ID PUBLICITY -----------\n"
#define MSG_IDPUBLICITY_NEW "\n---------- ID PUBLICITY -----------\n> %d"
#define MSG_NOMORESPACE_PUBLICITY "-----------------------------------\nXXXXXX| NO HAY ESPACIO PARA |XXXXXX\nXXXXXX|  MÁS PUBLICACIONES  |XXXXXX\n-----------------------------------\n\n"
#define MSG_PRINT_PUBLICITY "\n--------------------------------------------------------------------------------------------------------\n|| --[ID]-- || -----------------------[MENSAJE PUBLICITARIO]----------------------- || -[CLIENTE ID]- ||\n--------------------------------------------------------------------------------------------------------"
//#define MSG_PRINT_COUNTER "\n------------------------------------------------------------------------------------------------------------------\n|| -[ID PUBLICACIÓN]- || -----------------------[MENSAJE PUBLICITARIO]----------------------- || -[CLIENTE ID]- ||\n------------------------------------------------------------------------------------------------------------------"
#define MSG_PRINT_PUBLICITYOUT "\n--------------------------------------------------------------------------------------------------------"
#define MSG_PRINTINDEX_PUBLICITY "\n|| > %d   ||   %-64s   || %14d ||"
#define MSG_NOMORE_PUBLICITY "\n------- [NO HAY PUBLICACIONES] --------\n"
#define MSG_AREANUMBER "\n-----[RUBRO CON MÁS PUBLICACIONES] ----\n> %d\n"
#define MSG_PRINTREMOVE_PUBLICITY "\n--------------------------------------------------------------------------------------------------------------------\n|| --[ID]-- || -----------------------[MENSAJE PUBLICITARIO]----------------------- || -[CLIENTE ID]- || -[ESTADO]- ||\n--------------------------------------------------------------------------------------------------------------------"
#define MSG_PRINTACTIVEREMOVE_PUBLICITY "\n|| > %d   ||   %-64s   || %14d ||   ACTIVO   ||"
#define MSG_PRINTPAUSEDREMOVE_PUBLICITY "\n|| > %d   ||   %-64s   || %14d ||   PAUSADO  ||"
#define MSG_PRINTREMOVE_PUBLICITYOUT "\n--------------------------------------------------------------------------------------------------------------------"

struct
{
	int idPublicity;
	int idClient;
	int areaNumber;
	char textPublicity[LONG_TEXT];
	int isActive;
	int isEmpty;

}typedef Publicity;

int publicity_newId(void);
int publicity_initPublicity(Publicity* list, int len);
int publicity_add(Publicity* list, int len, int idClient);
int publicity_print(Publicity* list, int len);
int publicity_serchIndexEmpty(Publicity* list, int len);
int publicity_findById(Publicity* list, int len,int id);
int publicity_printIdClient(Publicity* list, int len, int idClient);
int publicity_counterByIdClient(Publicity* list, int len,int id);
int publicity_counterPaused(Publicity* list, int len);
int publicity_areaNumberMax(Publicity* list, int len);
int publicity_counterByAreaNumber(Publicity* list, int len, int areaNumber, int *pCounter);
int publicity_removeByIdClient(Publicity* list, int len, int idClient);
int publicity_ArrayIsEmpty (Publicity* list, int len);
int publicity_printPaused(Publicity* list, int len);
int publicity_ArrayIsActive (Publicity* list, int len);
int publicity_ArrayIsPaused (Publicity* list, int len);
int publicity_counterByIdClientActive(Publicity* list, int len,int id);
int publicity_counterByIdClientPaused(Publicity* list, int len,int id);

#endif /* PUBLICITY_H_ */
