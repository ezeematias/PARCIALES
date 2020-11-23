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
#include <limits.h>
#include "Sales.h"
#include "parser.h"
#include "utn.h"

Sales* sales_new()
{
	return (Sales*)malloc(sizeof(Sales));
}

void sales_delete(Sales* this)
{
	free(this);
}

int sales_getIdSales(Sales* this, int* idSales)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*idSales = this->idSales;
		retorno = 0;
	}
	return retorno;
}

int sales_getIdClient(Sales* this, int* idClient)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*idClient = this->idClient;
		retorno = 0;
	}
	return retorno;
}

int sales_getQuantityPosters(Sales* this, int* quantityPosters)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*quantityPosters = this->quantityPosters;
		retorno = 0;
	}
	return retorno;
}

int sales_getFileName(Sales* this, char* fileName)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(fileName,this->fileName);
		retorno = 0;
	}
	return retorno;
}

int sales_getZone(Sales* this, int* zone)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*zone = this->zone;
		retorno = 0;
	}
	return retorno;
}

int sales_getStatus(Sales* this, int* status)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*status = this->status;
		retorno = 0;
	}
	return retorno;
}

int isValidIdSales(int idSales)
{
	return 1;
}

int isValidQuantityPosters(int quantityPosters)
{
	return 1;
}

int isValidFileName(char* fileName)
{
	return 1;
}
int isValidZone(int zone)
{
	return 1;
}

int isValidStatus(int status)
{
	return 1;
}
int isValidIdClientSales(int idClient)
{
	return 1;
}

int sales_setIdSales(Sales* this, int idSales)
{
	int retorno = -1;
	if(this != NULL && isValidIdSales(idSales) == 1)
	{
		this->idSales = idSales;
		retorno = 0;
	}
	return retorno;
}

int sales_setIdClient(Sales* this, int idClient)
{
	int retorno = -1;
	if(this != NULL && isValidIdClientSales(idClient) == 1)
	{
		this->idClient = idClient;
		retorno = 0;
	}
	return retorno;
}

int sales_setQuantityPosters(Sales* this, int quantityPosters)
{
	int retorno = -1;
	if(this != NULL && isValidQuantityPosters(quantityPosters) == 1)
	{
		this->quantityPosters = quantityPosters;
		retorno = 0;
	}
	return retorno;
}

int sales_setFileName(Sales* this, char* fileName)
{
	int retorno = -1;
	if(this != NULL && isValidFileName(fileName) == 1)
	{
		strncpy(this->fileName,fileName,(int) sizeof(this->fileName));
		retorno = 0;
	}
	return retorno;
}

int sales_setZone(Sales* this, int zone)
{
	int retorno = -1;
	if(this != NULL && isValidZone(zone) == 1)
	{
		this->zone = zone;
		retorno = 0;
	}
	return retorno;
}

int sales_setStatus(Sales* this, int status)
{
	int retorno = -1;
	if(this != NULL && isValidStatus(status) == 1)
	{
		this->status = status;
		retorno = 0;
	}
	return retorno;
}

/** \brief New Employee whith parameters text.
 *
 * \param char* idClient, Get ID
 * \param char* nameClient, Get Name
 * \param char* lastNameClient, Get Last Name
 * \param char* cuitClient, Get CUIT.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Sales* sales_newParameters(char* idSales,char* idClient,char* quantityPosters,char* fileName,char* zone,char* status)
{
	Sales* this = sales_new();
	if (!sales_setIdSales(this, atoi(idSales)) && !sales_setIdClient(this, atoi(idClient)) && !sales_setQuantityPosters(this, atoi(quantityPosters)) && !sales_setFileName(this, fileName) && !sales_setZone(this, atoi(zone)) && !sales_setStatus(this, atoi(status)))
	{
		return this;
	}
	sales_delete(this);
	return NULL;
}

/** \brief New Employee whith parameters.
 *
 * \param char* idStr, Get ID
 * \param char* nombreStr, Get Name
 * \param char* horasTrabajadasStr, Get Hours
 * \param char* sueldo, Get Salary.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Sales* sales_newWithParameters(int idSales,int idClient,int quantityPosters,char* fileName,int zone,int status)
{
	Sales* this = sales_new();
	if(this != NULL)
	{
		if(!sales_setIdSales(this, idSales) && !sales_setIdClient(this, idClient) && !sales_setQuantityPosters(this, quantityPosters) && !sales_setFileName(this, fileName) && !sales_setZone(this, zone) && !sales_setStatus(this, status))
		{
			return this;
		}
	}
	sales_delete(this);
	return NULL;
}

/** \brief New Employee. This function looks for a space in the structure which is empty to be able to data.
 *
 * \param list Employee* Pointer to array of employees
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Sales* sales_add(int idClient)
{
	Sales bufferArrray;
	Sales* bufferSales;
	int attempts = 2;
	if ( !utn_getInt(&bufferArrray.quantityPosters, 3, attempts, MSG_QTY_POSTERS, MSG_OPTION_ERROR, LONG_MAX, 1) &&
			!utn_getString(bufferArrray.fileName, LONG_FILE, MSG_FILE, MSG_OPTION_ERROR, attempts) &&
			!utn_getInt(&bufferArrray.zone, 3, attempts, MSG_ZONE, MSG_OPTION_ERROR, 3, 1))
	{
		bufferArrray.idSales = sales_newId(PATH_ID_SALES);
		bufferArrray.idClient = idClient;
		bufferArrray.status = 0;
		bufferSales = sales_newWithParameters(bufferArrray.idSales, bufferArrray.idClient,bufferArrray.quantityPosters, bufferArrray.fileName, bufferArrray.zone,bufferArrray.status);
	}
	return bufferSales;
}

/** \brief New ID. Read the ID from a text file
 *
 * \param char* path, File path
 * \return int Return (ID+1), NewID.
 *
 */
int sales_newId(char* path)
{
	FILE* pFile;
	int id;
	if(path != NULL)
	{
		pFile = fopen(path,"r");
		if (pFile != NULL)
		{
			id = parser_salesId(pFile);
		}
		fclose(pFile);
	}
	return id+1;
}

/** \brief Save ID. Save a new identity number.
 *
 * \param char* path, File path
 * \param char* id, Get ID.
 * \return int Return (ID), NewID.
 *
 */
int sales_saveId(char* path, int id)
{
    FILE* pFile;
    int retorno = -1;

    if(path != NULL && id != -1)
    {
        pFile = fopen(path, "w");
        if (pFile != NULL)
        {
			fprintf(pFile,"%d\n", id);
			retorno = 0;
        }
		fclose(pFile);
    }
    return retorno;
}

/* \brief prints emplyee data
 *
 * \param Employee* this: pointer to employee
 * \return [-1] if error / [0] if ok
 */
int sales_print(Sales* this)
{
    int retorno=-1;
    int idSales;
    int idClient;
    int quantityPosters;
    char fileName[LONG_FILE];
    int zone;
    int status;
    if(this!=NULL)
    {
        if(!sales_getIdSales(this, &idSales) && !sales_getIdClient(this, &idClient) && !sales_getQuantityPosters(this, &quantityPosters) && !sales_getFileName(this, fileName) && !sales_getZone(this, &zone) && !sales_getStatus(this, &status))
        {
            printf(MSG_PRINT_S, idSales, idClient, quantityPosters, fileName, zone, status);
            retorno = 0;
        }
    }
    return retorno;
}


