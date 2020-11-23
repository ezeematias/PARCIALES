/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : Ezequiel Unía
 Version     :
 Copyright   : Copyright
 Description : Segundo parcial Laboratorio
 ============================================================================
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_
#include "LinkedList.h"

int parser_clientFromText(FILE* pFile , LinkedList* pArrayList);
int parser_salesFromText(FILE* pFile , LinkedList* pArrayList);
int parser_clientId(FILE* pFile);
int parser_salesId(FILE* pFile);

#endif /* SRC_PARSER_H_ */
