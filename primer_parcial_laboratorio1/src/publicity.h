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

#endif /* PUBLICITY_H_ */
