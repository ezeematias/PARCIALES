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
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Client.h"
#include "parser.h"
#include "Sales.h"

/** \brief Loads employee data from data.csv file (text mode).
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayList, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_loadFromText(LinkedList* pArrayList)
{
	int retorno = -1;
    if(pArrayList!=NULL)
    {
		FILE* fp = fopen(PATH_CLIENT,"r");
		if (fp != NULL)
		{
			parser_clientFromText(fp, pArrayList);
			retorno = 0;
		}
		fclose(fp);
    }
	return retorno;
}

/** \brief Loads employee data from data.csv file (text mode).
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayList, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_loadFromTextSales(LinkedList* pArrayList)
{
	int retorno = -1;
    if(pArrayList!=NULL)
    {
		FILE* fp = fopen(PATH_SALES,"r");
		if (fp != NULL)
		{
			parser_salesFromText(fp, pArrayList);
			retorno = 0;
		}
		fclose(fp);
    }
	return retorno;
}

/** \brief Add employee
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int
 *
 */
int controller_addClient(LinkedList* pArrayList)
{
	int retorno = -1;
	Client* bufferClient;
    if(pArrayList!=NULL)
    {
    	bufferClient = client_add();
    	if (ll_map(pArrayList, client_findByCuit, bufferClient->cuitClient) != 0)
    	{
    		client_saveId(PATH_ID_CLIENT, bufferClient->idClient);
			ll_add(pArrayList, bufferClient);
			retorno = 0;
    	}else
    	{
    		printf(MSG_CUIT_ERROR);
    	}
    }
	return retorno;
}

/** \brief Save employee data in the file data.csv (text mode)
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_saveAsText(LinkedList* pArrayList)
{
    FILE* pFile;
    Client *this;
    int retorno = -1;
    int length = ll_len(pArrayList);
    int idClient;
    char nameClient[LONG_NAME];
    char lastNameClient[LONG_NAME];
    char cuitClient[LONG_CUIT];

    if(pArrayList != NULL){
        pFile = fopen(PATH_CLIENT, "w");
        if (pFile != NULL)
        {
        	fprintf(pFile,"ID,NAME,LASTNAME,CUIT\n");
            for (int i = 1 ; i < length ; i++)
            {
            	this = ll_get(pArrayList, i);
                if( !client_getIdClient(this, &idClient) &&
                		!client_getNameClient(this, nameClient) &&
						!client_getLastNameClient(this, lastNameClient) &&
						!client_getCuitClient(this, cuitClient))
                {
                    fprintf(pFile,"%d,%s,%s,%s\n", idClient, nameClient, lastNameClient, cuitClient);
                    retorno = 0;
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Save employee data in the file data.csv (text mode)
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_saveAsTextSales(LinkedList* pArrayList)
{
    FILE* pFile;
    Sales *this;
    int retorno = -1;
    int length = ll_len(pArrayList);
    int idSales;
    int idClient;
    int quantityPosters;
    char fileName[LONG_FILE];
    int zone;
    int status;

    if(pArrayList != NULL){
        pFile = fopen(PATH_SALES, "w");
        if (pFile != NULL)
        {
        	fprintf(pFile,"IDSALES,IDCLIENT,QUANTITYPOSTERS,FILENAME,ZONE,STATUS\n");
            for (int i = 1 ; i < length ; i++)
            {
            	this = ll_get(pArrayList, i);
                if(		!sales_getIdSales(this, &idSales) &&
                		!sales_getIdClient(this, &idClient) &&
						!sales_getQuantityPosters(this, &quantityPosters) &&
						!sales_getFileName(this, fileName) &&
						!sales_getZone(this, &zone) &&
						!sales_getStatus(this, &status))
                {
                    fprintf(pFile,"%d,%d,%d,%s,%d,%d\n", idSales, idClient, quantityPosters, fileName, zone, status);
                    retorno = 0;
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Prints employee's list
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_ListClient(LinkedList* pArrayList)
{
    int retornar=-1;
    int len = ll_len(pArrayList);
    Client* bufferClient;
    if(pArrayList!=NULL && !ll_isEmpty(pArrayList))
    {
    	printf(MSG_PRINT_CLIENT);
        for(int i=1; i<len;i++)
        {
        	bufferClient = ll_get(pArrayList, i);
            client_print(bufferClient);
            retornar=0;
        }
    	printf(MSG_PRINT_OUT);
    }
    return retornar;
}

/** \brief Prints employee's list
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_ListSales(LinkedList* pArrayList)
{
    int retornar=-1;
    int len = ll_len(pArrayList);
    Sales* bufferSales;
    if(pArrayList!=NULL && !ll_isEmpty(pArrayList))
    {
    	printf(MSG_PRINT_SALES);
        for(int i=1; i<len;i++)
        {
        	bufferSales = ll_get(pArrayList, i);
            sales_print(bufferSales);
            retornar=0;
        }
    	printf(MSG_PRINT_OUT_S);
    }
    return retornar;
}

/** \brief Add employee
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int
 *
 */
int controller_addSales(LinkedList* pArrayListSales, LinkedList* pArrayListClient)
{
	int retorno = -1;
	Sales* bufferSales;
	int bufferId;
	int attempts = 2;
    if(pArrayListSales!=NULL && pArrayListClient!=NULL)
    {
    	if(!utn_getInt(&bufferId, 10, attempts, MSG_ID_CLIENT, MSG_OPTION_ERROR, LONG_MAX, 999) && (ll_map(pArrayListClient, client_findByIdClient, &bufferId) == 0))
    	{
    		bufferSales = sales_add(bufferId);
    		sales_saveId(PATH_ID_SALES, bufferSales->idSales);
			ll_add(pArrayListSales, bufferSales);
			printf(MSG_ADDSALES_ID,bufferSales->idSales);
			retorno = 0;
    	}else
    	{
    		printf(MSG_ID_ERROR);
    	}
    }
	return retorno;
}
