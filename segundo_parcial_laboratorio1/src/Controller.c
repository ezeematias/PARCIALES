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

/** \brief Loads employee data from client.txt file (text mode).
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

/** \brief Loads employee data from sales.txt file (text mode).
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
 * \param LinkedList* pArrayList, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
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

/** \brief Save employee data in the file client.txt (text mode)
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayList, Pointer to LinkedList
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
            for (int i = 0 ; i < length ; i++)
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

/** \brief Save employee data in the file sales.txtv (text mode)
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayList, Pointer to LinkedList
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
            for (int i = 0 ; i < length ; i++)
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
 * \param LinkedList* pArrayList, Pointer to LinkedList
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
        for(int i=0; i<len;i++)
        {
        	bufferClient = ll_get(pArrayList, i);
            client_print(bufferClient);
            retornar=0;
        }
    	printf(MSG_PRINT_OUT);
    }
    return retornar;
}

/** \brief Prints client's list
 *
 * \param LinkedList* pArrayList, Pointer to LinkedList
 * \param int index, index to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_ListClientForIndex(LinkedList* pArrayList, int index)
{
    int retornar=-1;
    Client* bufferClient;
    if(pArrayList!=NULL && !ll_isEmpty(pArrayList) && index > -1)
    {
    	printf(MSG_PRINT_CLIENT);
		bufferClient = ll_get(pArrayList, index);
		client_print(bufferClient);
		retornar=0;
    	printf(MSG_PRINT_OUT);
    }
    return retornar;
}

/** \brief Prints sales list
 *
 * \param LinkedList* pArrayList, Pointer to LinkedList
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
        for(int i=0; i<len;i++)
        {
        	bufferSales = ll_get(pArrayList, i);
            sales_print(bufferSales);
            retornar=0;
        }
    	printf(MSG_PRINT_OUT_S);
    }
    return retornar;
}

/** \brief Add sales
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
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


/** \brief Prints client's list
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \param int option, option to modify
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_editSales(LinkedList* pArrayListSales, LinkedList* pArrayListClient, int option)
{
	int retorno = -1;
	LinkedList* bufferCharge;
	Sales* bufferSales;
	int bufferIdCLient;
	int status = 0;
	int attempts = 2;
	int bufferIdSales;
	int indexClient;
	int indexSales;
	if(pArrayListSales!=NULL && pArrayListClient!=NULL)
	{
		bufferCharge = ll_filter(pArrayListSales, sales_typeStatus, &status);
		if(bufferCharge != NULL && controller_ListSales(bufferCharge)==0)
		{
			if(!utn_getInt(&bufferIdSales, 10, attempts, MSG_ID_SALES, MSG_OPTION_ERROR, LONG_MAX, 4999) &&
					controller_findByIdSales(pArrayListSales, bufferIdSales, &indexSales)== 0 &&
					controller_findByIdSaleTheIdClient(bufferCharge, bufferIdSales, &bufferIdCLient)==0 &&
					controller_findByIdClient(pArrayListClient, bufferIdCLient, &indexClient)==0 &&
					controller_ListClientForIndex(pArrayListClient, indexClient)==0)
			{
				bufferSales = ll_get(pArrayListSales, indexSales);
				if(option==1 && sales_modify(bufferSales)==0)
				{
					ll_set(pArrayListSales, indexSales, bufferSales);
					retorno = 0;
				}else if (option==2 && sales_charged(bufferSales)==0)
				{
					ll_set(pArrayListSales, indexSales, bufferSales);
					retorno = 0;
				}
			}else
			{
				printf(MSG_ID_SALES_ERROR);
			}
		}else
		{
			printf(MSG_STATUS_ERROR);
		}
	}
	return retorno;
}

/** \brief Search by sales id and returns client id
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param int id, id Sales.
 * \param int* idClient, return the idClient.
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_findByIdSaleTheIdClient(LinkedList* pArrayListSales, int id, int* idClient)
{
	Sales* bufferSales;
	int retorno = -1;
	int bufferId;
	int len = ll_len(pArrayListSales);
    if(pArrayListSales!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		bufferSales = ll_get(pArrayListSales, i);
    		if(bufferSales != NULL && !sales_getIdSales(bufferSales, &bufferId) && bufferId == id)
    		{
    			*idClient = bufferSales->idClient;
    			retorno = 0;
    			break;
    		}
    	}
    }
	return retorno;
}

/** \brief Search by customer id and return the index
 *
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \param int id, id Client.
 * \param int* index, return the index Client.
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_findByIdClient(LinkedList* pArrayListClient, int id, int* index)
{
	Client* bufferClient;
	int retorno = -1;
	int bufferId;
	int len = ll_len(pArrayListClient);
    if(pArrayListClient!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		bufferClient = ll_get(pArrayListClient, i);
    		if(bufferClient != NULL && !client_getIdClient(bufferClient, &bufferId) && bufferId == id)
    		{
    			*index = i;
    			retorno = 0;
    			break;
    		}
    	}
    }
	return retorno;
}

/** \brief Search by customer id and return the index
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param int id, id Sales.
 * \param int* index, return the index Sales.
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_findByIdSales(LinkedList* pArrayListSales, int id, int* index)
{
	Sales* bufferClient;
	int retorno = -1;
	int bufferId;
	int len = ll_len(pArrayListSales);
    if(pArrayListSales!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		bufferClient = ll_get(pArrayListSales, i);
    		if(bufferClient != NULL && !sales_getIdSales(bufferClient, &bufferId) && bufferId == id)
    		{
    			*index = i;
    			retorno = 0;
    			break;
    		}
    	}
    }
	return retorno;
}


/** \brief Saves the data of client with sales is charged in the file
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_isChargedReport(LinkedList* pArrayListSales, LinkedList* pArrayListClient)
{
	int retorno = -1;
	FILE* pFile;
    Client* this;
    int length = ll_len(pArrayListClient);
    int idClient;
    char nameClient[LONG_NAME];
    char lastNameClient[LONG_NAME];
    char cuitClient[LONG_CUIT];
    int chargedSales;
    if(pArrayListSales != NULL && pArrayListClient != NULL)
    {
        pFile = fopen(PATH_REPORT_IS_CHARGED, "w");
        if (pFile != NULL)
        {
            for (int i = 0 ; i < length ; i++)
            {
            	this = ll_get(pArrayListClient, i);
                if( !client_getIdClient(this, &idClient) &&
                		!client_getNameClient(this, nameClient) &&
						!client_getLastNameClient(this, lastNameClient) &&
						!client_getCuitClient(this, cuitClient))
                {
                	chargedSales = ll_reduceInt(pArrayListSales, sales_isCharged, &idClient);
                    fprintf(pFile,"%d,%s,%s,%s,%d\n", idClient, nameClient, lastNameClient, cuitClient, chargedSales);
                    retorno = 0;
                }
            }
        }
    }
    fclose(pFile);
	return retorno;
}

/** \brief Saves the data of Client with sales to Charged in the file
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_toChargedReport(LinkedList* pArrayListSales, LinkedList* pArrayListClient)
{
	int retorno = -1;
	FILE* pFile;
    Client* this;
    int length = ll_len(pArrayListClient);
    int idClient;
    char nameClient[LONG_NAME];
    char lastNameClient[LONG_NAME];
    char cuitClient[LONG_CUIT];
    int chargedSales;
    if(pArrayListSales != NULL && pArrayListClient != NULL)
    {
        pFile = fopen(PATH_REPORT_TO_CHARGED, "w");
        if (pFile != NULL)
        {
            for (int i = 0 ; i < length ; i++)
            {
            	this = ll_get(pArrayListClient, i);
                if( !client_getIdClient(this, &idClient) &&
                		!client_getNameClient(this, nameClient) &&
						!client_getLastNameClient(this, lastNameClient) &&
						!client_getCuitClient(this, cuitClient))
                {
                	chargedSales = ll_reduceInt(pArrayListSales, sales_toCharged, &idClient);
                    fprintf(pFile,"%d,%s,%s,%s,%d\n", idClient, nameClient, lastNameClient, cuitClient, chargedSales);
                    retorno = 0;
                }
            }
        }
    }
    fclose(pFile);
	return retorno;
}

/** \brief Generates all als statistics.
 * a- Client with the most posters sold.
 * b- Client with the least posters sold.
 * c- Sale with the most banners sold.
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_generalStatistics(LinkedList* pArrayListSales, LinkedList* pArrayListClient)
{
	LinkedList* bufferCharge;
	LinkedList* bufferMaxPosters = ll_newLinkedList();
	LinkedList* bufferMinPosters = ll_newLinkedList();
	Client* this;
	int retorno = 0;
	int status = 1;
	int length = ll_len(pArrayListClient);
	int idClient;
	int postersSales = 0;
	int maxPosters;
	int minPosters;
	if(pArrayListClient != NULL && pArrayListSales != NULL)
	{
		bufferCharge = ll_filter(pArrayListSales, sales_typeStatus, &status);
		for (int i = 0 ; i < length ; i++)
		{
			this = ll_get(pArrayListClient, i);
			if(!client_getIdClient(this, &idClient) && !ll_map(bufferCharge, sales_findByIdClientInSales, &idClient))
			{
				postersSales = ll_reduceInt(bufferCharge, sales_quantityPostersposters, &idClient);
				if(i==0 || postersSales > maxPosters)
				{
					maxPosters = postersSales;
					ll_clear(bufferMaxPosters);
					ll_add(bufferMaxPosters, this);
				}else if (postersSales == maxPosters)
				{
					ll_add(bufferMaxPosters, this);
				}
				if ((i==0 || postersSales < minPosters))
				{
					minPosters = postersSales;
					ll_clear(bufferMinPosters);
					ll_add(bufferMinPosters, this);
				}else if (postersSales == minPosters)
				{
					ll_add(bufferMinPosters, this);
				}
			}
		}
		if(postersSales > 0)
		{
			printf(MSG_CLIENT_MAXPOSTERS,maxPosters);
			controller_ListClient(bufferMaxPosters);
			printf(MSG_CLIENT_MINPOSTERS,minPosters);
			controller_ListClient(bufferMinPosters);
			printf(MSG_SALES_POSTERS);
			controller_listSalesCuit(bufferCharge, pArrayListClient);
		}else
		{
			printf(MSG_CLIENT_ERROR);
		}
	}
	return retorno;
}


/** \brief Find the maximum number of posters
 *
 * \param LinkedList* pArrayList, Pointer to LinkedList
 * \return bufferMaxPosters, Maximun number of poster.
 *
 */
int controller_maxPosters(LinkedList* pArrayListSales)
{
	int len = ll_len(pArrayListSales);
	Sales* this;
	int bufferPosters;
	int bufferMaxPosters;
    if(pArrayListSales!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		this = ll_get(pArrayListSales, i);
    		sales_getQuantityPosters(this, &bufferPosters);
			if(i==0 || bufferPosters > bufferMaxPosters)
			{
				bufferMaxPosters = bufferPosters;
			}
    	}
    }
	return bufferMaxPosters;
}

/** \brief Prints idSales and CuitClient.
 *
 * \param LinkedList* pArrayListSales, Pointer to LinkedList
 * \param LinkedList* pArrayListClient, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_listSalesCuit(LinkedList* pArrayListSales, LinkedList* pArrayListClient)
{
	int retorno = -1;
	int maxPoster;
	int idSales;
	char cuitClient [LONG_CUIT];
	int bufferPoster;
	int bufferIdClient;
	int bufferIndexClient;
	int len = ll_len(pArrayListSales);
	Sales* thisSales;
	Client* thisClient;
	if(pArrayListSales!=NULL && pArrayListClient!=NULL)
	{
		maxPoster = controller_maxPosters(pArrayListSales);
		printf(MSG_PRINT_SALESCUIT);
		for(int i = 0; i < len ; i++)
		{
			thisSales = ll_get(pArrayListSales, i);
			sales_getQuantityPosters(thisSales, &bufferPoster);
			if(bufferPoster == maxPoster)
			{
				sales_getIdClient(thisSales, &bufferIdClient);
				controller_findByIdClient(pArrayListClient, bufferIdClient, &bufferIndexClient);
				thisClient = ll_get(pArrayListClient, bufferIndexClient);
				sales_getIdSales(thisSales, &idSales);
				client_getCuitClient(thisClient, cuitClient);
				printf(MSG_PRINT_SALESID_CUITCLIENT,idSales,cuitClient);
			}
		}
		printf(MSG_PRINT_SALESCUIT_OUT);
	}
	return retorno;
}
