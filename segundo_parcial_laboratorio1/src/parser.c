/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : Ezequiel Unía
 Version     :
 Copyright   : Copyright
 Description : Segundo parcial Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Client.h"
#include "Sales.h"
#include "parser.h"

/** \brief Parser employee data from data.csv file (text mode).
 *
 *  \param FILE* pFile, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int parser_clientFromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;
	char bufferId[1024];
	char bufferName[1024];
	char bufferLastName[1024];
	char bufferCuit[1024];
	Client* bufferClient;
	if(pFile != NULL && pArrayList != NULL)
	{
		ll_clear(pArrayList);
		do
		{
			if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferName, bufferLastName, bufferCuit)==4)
			{
				strupr(bufferName);
				strupr(bufferLastName);
				bufferClient = client_newParameters(bufferId, bufferName, bufferLastName, bufferCuit);
				ll_add(pArrayList, bufferClient);
				retorno = 0;
			}
		}while(feof(pFile)==0);
	}
    return retorno;
}

/** \brief Parser employee data from data.csv file (text mode).
 *
 *  \param FILE* pFile, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int parser_salesFromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;
	char idSales[1024];
	char idClient[1024];
	char quantityPosters[1024];
    char fileName[1024];
    char zone[1024];
    char status[1024];
	Sales* bufferSales;
	if(pFile != NULL && pArrayList != NULL)
	{
		ll_clear(pArrayList);
		do
		{
			if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idSales, idClient, quantityPosters, fileName, zone, status)==6)
			{
				bufferSales = sales_newParameters(idSales, idClient, quantityPosters, fileName, zone, status);
				ll_add(pArrayList, bufferSales);
				retorno = 0;
			}
		}while(feof(pFile)==0);
	}
    return retorno;
}

/** \brief Parser ID data from data.csv file (text mode).
 *
 * \param FILE* pFile, File path
 * \return int (-1) if ERROR (0) if OK
 *
 */
int parser_clientId(FILE* pFile)
{
	int retorno = -1;
	char bufferId[55];
	do
	{
		if (fscanf(pFile,"%[^\n]\n",bufferId)==1)
		{
			retorno = atoi(bufferId);
		}
	}while(feof(pFile)==0);
    return retorno;
}

/** \brief Parser ID data from data.csv file (text mode).
 *
 * \param FILE* pFile, File path
 * \return int (-1) if ERROR (0) if OK
 *
 */
int parser_salesId(FILE* pFile)
{
	int retorno = -1;
	char bufferId[55];
	do
	{
		if (fscanf(pFile,"%[^\n]\n",bufferId)==1)
		{
			retorno = atoi(bufferId);
		}
	}while(feof(pFile)==0);
    return retorno;
}
