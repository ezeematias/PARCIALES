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
#include "parser.h"
#include "utn.h"


Client* client_new()
{
	return (Client*)malloc(sizeof(Client));
}

void client_delete(Client* this)
{
	free(this);
}

int client_getIdClient(Client* this, int* idClient)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*idClient = this->idClient;
		retorno = 0;
	}
	return retorno;
}
int client_getNameClient(Client* this, char* nameClient)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(nameClient,this->nameClient);
		retorno = 0;
	}
	return retorno;
}
int client_getLastNameClient(Client* this, char* lastNameClient)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(lastNameClient,this->lastNameClient);
		retorno = 0;
	}
	return retorno;
}
int client_getCuitClient(Client* this, char* cuitClient)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(cuitClient,this->cuitClient);
		retorno = 0;
	}
	return retorno;
}
int client_getPaidSales(Client* this, int* paidSales)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*paidSales = this->paidSales;
		retorno = 0;
	}
	return retorno;
}
int client_getUnpaidSales(Client* this, int* unpaidSales)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*unpaidSales = this->unpaidSales;
		retorno = 0;
	}
	return retorno;
}
int isValidIdClient(int idClient)
{
	int retorno = 1;
	return retorno;
}
int isValidNameClient(char* nameClient)
{
	int retorno = 1;
	int i;
	if(nameClient)
	{
		for (i = 0;nameClient[i] != '\0';i++)
		{
			if ((nameClient[i] < 'a' || nameClient[i] > 'z') && (nameClient[i] < 'A' || nameClient[i] > 'Z') && (nameClient[i] != ' ') && (nameClient[i] != '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int isValidCuitClient(char* cuitClient)
{
	int retorno;
	int i = 0;
	int counterDash = 0;
	if(cuitClient[2] == '-' && cuitClient[11] == '-' && cuitClient[12] != '\0')
	{
		retorno = 1;
		for( ; cuitClient[i] != '\0' ; i++)
		{
			if(cuitClient[i] == '-')
			{
				counterDash++;
			}
			if((counterDash > 2) || ((cuitClient[i] > '9' || cuitClient[i] < '0') && cuitClient[i] != '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int isValidPaidSales(int paidSales)
{
	return 1;
}
int isValidUnpaidSales(int unpaidSales)
{
	return 1;
}
int client_setIdClient(Client* this, int idClient)
{
	int retorno = -1;
	if(this != NULL && isValidIdClient(idClient) == 1)
	{
		this->idClient = idClient;
		retorno = 0;
	}
	return retorno;
}
int client_setNameClient(Client* this, char* nameClient)
{
	int retorno = -1;
	if(this != NULL && isValidNameClient(nameClient) == 1)
	{
		strncpy(this->nameClient,nameClient,(int) sizeof(this->nameClient));
		retorno = 0;
	}
	return retorno;
}
int client_setLastNameClient(Client* this, char* lastNameClient)
{
	int retorno = -1;
	if(this != NULL && isValidNameClient(lastNameClient) == 1)
	{
		strncpy(this->lastNameClient,lastNameClient,(int) sizeof(this->lastNameClient));
		retorno = 0;
	}
	return retorno;
}
int client_setCuitClient(Client* this, char* cuitClient)
{
	int retorno = -1;
	if(this != NULL && isValidCuitClient(cuitClient) == 1)
	{
		strncpy(this->cuitClient,cuitClient,(int) sizeof(this->cuitClient));
		retorno = 0;
	}
	return retorno;
}
int client_setPaidSales(Client* this, int paidSales)
{
	int retorno = -1;
	if(this != NULL && isValidPaidSales(paidSales) == 1)
	{
		this->paidSales = paidSales;
		retorno = 0;
	}
	return retorno;
}
int client_setUnpaidSales(Client* this, int unpaidSales)
{
	int retorno = -1;
	if(this != NULL && isValidUnpaidSales(unpaidSales) == 1)
	{
		this->unpaidSales = unpaidSales;
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
Client* client_newParameters(char* idClient,char* nameClient,char* lastNameClient,char* cuitClient)
{
	Client* this = client_new();
	if (!client_setIdClient(this, atoi(idClient)) && !client_setNameClient(this, nameClient) && !client_setLastNameClient(this, lastNameClient) && !client_setCuitClient(this, cuitClient))
	{
		return this;
	}
	client_delete(this);
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
Client* client_newWithParameters(int idClient,char* nameClient,char* lastNameClient,char* cuitClient)
{
	Client* this = client_new();
	if(this != NULL)
	{
		if( !client_setIdClient(this, idClient) && !client_setNameClient(this, nameClient) && !client_setLastNameClient(this, lastNameClient) && !client_setCuitClient(this, cuitClient))
		{
			return this;
		}
	}
	client_delete(this);
	return NULL;
}

/** \brief New Employee. This function looks for a space in the structure which is empty to be able to data.
 *
 * \param list Employee* Pointer to array of employees
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Client* client_add(void)
{
	Client bufferArrray;
	Client* bufferClient;
	int attempts = 2;
	if ( !utn_getName(bufferArrray.nameClient, LONG_NAME, MSG_NAME, MSG_OPTION_ERROR, attempts) &&
		 !utn_getName(bufferArrray.lastNameClient, LONG_NAME, MSG_LASTNAME, MSG_OPTION_ERROR, attempts) &&
		 !utn_getCuit(bufferArrray.cuitClient, LONG_CUIT, MSG_CUIT, MSG_OPTION_ERROR, attempts))
	{
		strupr(bufferArrray.nameClient);
		strupr(bufferArrray.lastNameClient);
		bufferArrray.idClient = client_newId(PATH_ID_CLIENT);
		bufferClient = client_newWithParameters(bufferArrray.idClient, bufferArrray.nameClient, bufferArrray.lastNameClient, bufferArrray.cuitClient);
	}
	return bufferClient;
}

/** \brief New ID. Read the ID from a text file
 *
 * \param char* path, File path
 * \return int Return (ID+1), NewID.
 *
 */
int client_newId(char* path)
{
	FILE* pFile;
	int id;
	if(path != NULL)
	{
		pFile = fopen(path,"r");
		if (pFile != NULL)
		{
			id = parser_clientId(pFile);
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
int client_saveId(char* path, int id)
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
int client_print(Client* this)
{
    int retorno=-1;
    char nameClient[LONG_NAME];
    char lastNameClient[LONG_NAME];
    char cuitClient[LONG_CUIT];
    int idClient;
    if(this!=NULL)
    {
        if( !client_getIdClient(this, &idClient) &&
        		!client_getNameClient(this, nameClient) &&
				!client_getLastNameClient(this, lastNameClient) &&
				!client_getCuitClient(this, cuitClient))
        {
            printf(MSG_PRINT, idClient, nameClient, lastNameClient, cuitClient);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief find an Client by CUIT.
 *
 * \param void* this, Pointer to array of client.
 * \param char* cuit, Cuit cliet.
 * \return Return [0] Client exists - [-1] No exists
 */
int client_findByCuit(void* this, void* cuit)
{
	int retorno = -1;
	char cuitClient[LONG_CUIT];
	if(this != NULL && !client_getCuitClient((Client*)this, cuitClient))
	{
		if(strncmp(cuitClient, (char*)cuit, sizeof(cuitClient)) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief find an Client by ID.
 *
 * \param void* this, Pointer to array of client.
 * \param char* cuit, Cuit cliet.
 * \return Return [0] Client exists - [-1] No exists
 */
int client_findByIdClient(void* this, void* idClient)
{
	int retorno = -1;
	int idClientSales;
	int bufferId= *((int*)(idClient));
	if(this != NULL && !client_getIdClient((Client*)this, &idClientSales))
	{
		if(idClientSales == bufferId)
		{
			retorno = 0;
		}
	}
	return retorno;
}
