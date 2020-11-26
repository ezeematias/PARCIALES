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

/** \brief Search and create a memory space
 *
 *  \return pointer to dynamic memory.
 */
Sales* sales_new()
{
	return (Sales*)malloc(sizeof(Sales));
}

/** \brief Delete a memory space
 *
 * \param Sales* this: pointer to sales
 *  \return (void)
 */
void sales_delete(Sales* this)
{
	free(this);
}

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Sales* this: pointer to sales
 * \param int* idSales, Get ID.
 * \return int Return (ID) / [-1] if error.
 *
 */
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

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Sales* this: pointer to sales
 * \param int* idClient, Get ID.
 * \return int Return (ID) / [-1] if error.
 *
 */
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

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Sales* this: pointer to sales
 * \param int* quantityPosters, Get quantityPosters.
 * \return int Return (ID) / [-1] if error.
 *
 */
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

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Sales* this: pointer to sales
 * \param char* fileName, Get fileName.
 * \return int Return (ID) / [-1] if error.
 *
 */
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

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Sales* this: pointer to sales
 * \param int* zone, Get zone.
 * \return int Return (ID) / [-1] if error.
 *
 */
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

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Sales* this: pointer to sales
 * \param int* status, Get status.
 * \return int Return (ID) / [-1] if error.
 *
 */
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
	int retorno = 1;
	if(idSales < 0)
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Check if the value is valid
 *
 * \param int quantityPosters, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
int isValidQuantityPosters(int quantityPosters)
{
	int retorno = 1;
	if(quantityPosters < 0)
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Verify that the array is only letters.
 *
 * \param char* fileName, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
int isValidFileName(char* fileName)
{
	int retorno = 1;
	int i;

	if(fileName != NULL)
	{
		for (i = 0;fileName[i] != '\0';i++)
		{
			if ((fileName[i] < 'a' || fileName[i] > 'z') && (fileName[i] != '-') && (fileName[i] > '9' || fileName[i] < '0') && (fileName[i] != '_') && (fileName[i] != '@') && (fileName[i] != '.'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Check if the value is valid
 *
 * \param int zone, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
int isValidZone(int zone)
{
	int retorno = 1;
	if(zone < 1 || zone > 3)
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Check if the value is valid
 *
 * \param int status, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
int isValidStatus(int status)
{
	int retorno = 1;
	if(status < 0 || status > 1)
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Check if the value is valid
 *
 * \param int idClient, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
int isValidIdClientSales(int idClient)
{
	int retorno = 1;
	if(idClient < 0)
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Load the name in the sales field and validate that the data is correct
 *
 * \param Sales* this: pointer to client
 * \param int* idSales: pointer of the idSales to be set to an client
 * \return [-1] if error / [0] if ok
 */
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

/** \brief Load the name in the client field and validate that the data is correct
 *
 * \param Sales* this: pointer to sales
 * \param int* idClient: pointer of the idClient to be set to an client
 * \return [-1] if error / [0] if ok
 */
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

/** \brief Load the name in the sales field and validate that the data is correct
 *
 * \param Sales* this: pointer to client
 * \param int quantityPosters: pointer of the quantityPosters to be set to an client
 * \return [-1] if error / [0] if ok
 */
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

/** \brief Load the name in the sales field and validate that the data is correct
 *
 * \param Sales* this: pointer to client
 * \param char* fileName: pointer of the fileName to be set to an client
 * \return [-1] if error / [0] if ok
 */
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

/** \brief Load the name in the sales field and validate that the data is correct
 *
 * \param Sales* this: pointer to client
 * \param int zone: pointer of the zone to be set to an client
 * \return [-1] if error / [0] if ok
 */
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

/** \brief Load the name in the sales field and validate that the data is correct
 *
 * \param Sales* this: pointer to client
 * \param int status: pointer of the status to be set to an client
 * \return [-1] if error / [0] if ok
 */
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

/** \brief New Sales whith parameters text.
 *
 * \param char* idSales, Get ID
 * \param char* idClient, Get ID
 * \param char* quantityPosters, Get quantityPosters
 * \param char* fileName, Get fileName.
 * \param char* zone, Get zone.
 * \param char* status, Get status.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Sales*) if Ok
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

/** \brief New Sales whith parameters text.
 *
 * \param int idSales, Get ID
 * \param int idClient, Get ID
 * \param int quantityPosters, Get quantityPosters
 * \param char* fileName, Get fileName.
 * \param int zone, Get zone.
 * \param int status, Get status.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Sales*) if Ok
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

/** \brief New Sales. This function looks for a space in the structure which is empty to be able to data.
 *
 * \param int idClient, IdClient for Sales.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Sales*) if Ok
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

/** \brief Modify the selected field of sale
 *
 * \param Sales* this: pointer to client
 * \return [-1] if error / [0] if ok
 */
int sales_modify(Sales* this)
{
	int retorno = -1;
	int option;
	int attempts = 2;
	Sales bufferArrray;
	if(this != NULL)
	{
		printf(MSG_SALES_ID);
		printf(MSG_PRINT_SALES);
		sales_print(this);
		printf(MSG_PRINT_OUT_S);
		do
		{
			if (!utn_getInt(&option, 3, attempts, MSG_SALES_MODIFY, MSG_OPTION_ERROR, 3, 0))
			{
				switch(option)
				{
					case 1:
						if(!utn_getInt(&bufferArrray.quantityPosters, 100, attempts, MSG_QTY_POSTERS, MSG_OPTION_ERROR, LONG_MAX, 1))
						{
							sales_setQuantityPosters(this, bufferArrray.quantityPosters);
						}
						break;
					case 2:
						if(!utn_getString(bufferArrray.fileName, LONG_FILE, MSG_FILE, MSG_OPTION_ERROR, attempts))
						{
							sales_setFileName(this, bufferArrray.fileName);
						}
						break;
					case 3:
						if(!utn_getInt(&bufferArrray.zone, 100, attempts, MSG_ZONE, MSG_OPTION_ERROR, 3, 1))
						{
							sales_setZone(this, bufferArrray.zone);
						}
						break;
					case 0:
						retorno = 0;
						break;
				}
			}
		}while(option!=0);
	}
	return retorno;
}

/** \brief Change status the Sales.
 *
 * \param Sales* this: pointer to client
 * \return [-1] if error / [0] if ok
 */
int sales_charged(Sales* this)
{
	int retorno = -1;
	int option;
	int attempts = 2;
	int status = 1;
	if(this != NULL)
	{
		printf(MSG_SALES_ID);
		printf(MSG_PRINT_SALES);
		sales_print(this);
		printf(MSG_PRINT_OUT_S);
		if (!utn_getInt(&option, 3, attempts, MSG_SALES_CHARGED, MSG_OPTION_ERROR, 1, 0))
		{
			sales_setStatus(this, status);
			retorno = 0;
		}
	}
	return retorno;
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

/* \brief prints sales data
 *
 * \param Sales* this: pointer to employee
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

/** \brief find an Sales by STATUS.
 *
 * \param void* this, Pointer to array of client.
 * \param void* status, status sales.
 * \return Return [0] Client exists - [-1] No exists
 */
int sales_typeStatus(void* this, void* status)
{
	int retorno = -1;
	int salesStatus;
	int bufferStatus= *((int*)(status));
	if(this != NULL && !sales_getStatus((Sales*)this, &salesStatus))
	{
		if(salesStatus == bufferStatus)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief find an Sales by ID.
 *
 * \param void* this, Pointer to array of client.
 * \param void* idSales, idSales .
 * \return Return [0] Client exists - [-1] No exists
 */
int sales_findByIdSales(void* this, void* idSales)
{
	int retorno = -1;
	int bufferIdSales;
	int bufferId= *((int*)(idSales));
	if(this != NULL && !sales_getIdSales((Sales*)this, &bufferIdSales))
	{
		if(bufferIdSales == bufferId)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief find an Sales by ID.
 *
 * \param void* this, Pointer to array of client.
 * \param void* idSales, idSales.
 * \return Return [0] Client exists - [-1] No exists
 */
int sales_findByIdClientInSales(void* this, void* idSales)
{
	int retorno = -1;
	int bufferIdSales;
	int bufferId= *((int*)(idSales));
	if(this != NULL && !sales_getIdClient((Sales*)this, &bufferIdSales))
	{
		if(bufferIdSales == bufferId)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Check the status isCharged.
 *
 * \param void* this, Pointer to array of client.
 * \param void* idClient, idClient cliet.
 * \return Return [0] Client exists - [-1] No exists
 */
int sales_isCharged(void* this, void* idClient)
{
	int retorno = 0;
	int bufferIdClientSales;
	int bufferStatus;
	int bufferId= *((int*)(idClient));
	if(this != NULL && !sales_getIdClient((Sales*)this, &bufferIdClientSales) && !sales_getStatus((Sales*)this, &bufferStatus))
	{
		if(bufferIdClientSales == bufferId && bufferStatus == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Check the status toCharged .
 *
 * \param void* this, Pointer to array of client.
 * \param char* cuit, Cuit cliet.
 * \return Return [0] Client exists - [-1] No exists
 */
int sales_toCharged(void* this, void* idClient)
{
	int retorno = 0;
	int bufferIdClientSales;
	int bufferStatus;
	int bufferId= *((int*)(idClient));
	if(this != NULL && !sales_getIdClient((Sales*)this, &bufferIdClientSales) && !sales_getStatus((Sales*)this, &bufferStatus))
	{
		if(bufferIdClientSales == bufferId && bufferStatus == 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Number of posters for sale
 *
 * \param void* this, Pointer to array of client.
 * \param void* idClient, idClient cliet.
 * \return Return bufferPosters,
 */
int sales_quantityPostersposters(void* this, void* idClient)
{
	int retorno = 0;
	int bufferIdClientSales;
	int bufferPosters;
	int bufferStatus;
	int bufferId= *((int*)(idClient));
	if(this != NULL && !sales_getIdClient((Sales*)this, &bufferIdClientSales) && !sales_getQuantityPosters((Sales*)this, &bufferPosters) && !sales_getStatus((Sales*)this, &bufferStatus))
	{
		if(bufferIdClientSales == bufferId && bufferStatus == 1)
		{
			retorno = bufferPosters;
		}
	}
	return retorno;
}
