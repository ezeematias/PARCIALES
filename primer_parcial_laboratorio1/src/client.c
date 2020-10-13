/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

/** \brief New ID.
 * Generates a new identity number.
 * \param (void)
 * \return int Return (ID), NewID.
 *
 */
int client_newId(void)
{
	static int id = 999;
	id = id+1;
	return id;
}

/** \brief To initialize all empty array positions.
 * this function put the flag (isEmpty) in TRUE in all and ID to 0.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_initClient(Client* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<=len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].idClient = 0;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief New Client.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_add(Client* list, int len)
{
	Client bufferArrray;
	int retorno = -1;
	int index;
	strncpy(bufferArrray.cuit, "00-00000000-0", LONG_CUIT);

	if (client_serchIndexEmpty(list, len) >= 0 && utn_getName(bufferArrray.name, LONG_NAME, MSG_NAME, MSG_ERROR, 2)==0 && utn_getName(bufferArrray.lastName, LONG_LASTNAME, MSG_LASTNAME, MSG_ERROR, 2)==0 && utn_getCuit(bufferArrray.cuit, LONG_CUIT, MSG_CUIT, MSG_ERROR, 2)==0 && client_findByCuit(list, len, bufferArrray.cuit)==-1)
	{
		strupr(bufferArrray.name);
		strupr(bufferArrray.lastName);
		index = client_serchIndexEmpty(list, LONG_CLIENT);
		list[index].idClient = client_newId();
		strncpy(list[index].name, bufferArrray.name, LONG_NAME);
		strncpy(list[index].lastName, bufferArrray.lastName, LONG_LASTNAME);
		strncpy(list[index].cuit, bufferArrray.cuit, LONG_CUIT);
		list[index].isEmpty = FALSE;

		printf(MSG_IDCLIENT, list[index].idClient);
		retorno = 0;

	}else if(client_serchIndexEmpty(list, len) == -1)
	{
			printf(MSG_NOMORESPACE);
			retorno = -2;
	}else if (client_findByCuit(list, len, bufferArrray.cuit)==0)
	{
		printf(MSG_CUIT_DUPLICATED);
	}
	return retorno;
}

/** \brief Search for an empty index.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_serchIndexEmpty(Client* list, int len)
{
	int retornar = -1;
	if(list != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE && list[i].idClient == 0)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}

/** \brief Empty employee list
 * This function searches the structure for active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_ArrayIsEmpty (Client* list, int len)
{
	int i;
	int retorno = 1;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/** \brief find an Client by Id en returns the index position in array.
 *
 * \param Employee* list, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number employee.
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int client_findById(Client* list, int len,int id)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(list[i].idClient == id && list[i].isEmpty == FALSE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

/** \brief find an Client by CUIT.
 *
 * \param Employee* list, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number employee.
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int client_findByCuit(Client* list, int len,char* cuit)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(strcmp(cuit,list[i].cuit)==0)
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/** \brief Client print
 * This function prints the list of active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_print(Client* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf(MSG_PRINT_CLIENTINDEX);
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf(MSG_PRINT_INDEX, list[i].idClient, list[i].name,list[i].lastName,list[i].cuit);
			}
		}
		printf(MSG_PRINT_INDEX_OUT);
		retorno = 0;
	}
	return retorno;
}

/** \brief Client print
 * This function prints the list of active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_printIdex(Client* list, int index)
{
	int retorno = -1;

	printf(MSG_PRINT_CLIENTINDEX);
	if(list[index].isEmpty == FALSE)
	{
		printf(MSG_PRINT_INDEX, list[index].idClient, list[index].name,list[index].lastName,list[index].cuit);
	}
	printf(MSG_PRINT_INDEX_OUT);
	retorno = 0;

	return retorno;
}

/** \brief Modify client.
 * This function allows you to modify existing employee data. It has a menu of options.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_modify(Client* list, int len)
{
	int retorno = -1;
	int bufferId;
	int bufferIndex;
	int option;
	int flagContinue = TRUE;
	int attempts = 2;
	char bufferCuit[15];

	client_print(list, len);
	do
	{
		if(utn_getInt(&bufferId, 50, 2, MSG_ID, MSG_ERROR, 2000, 1000)==0)
		{
			bufferIndex = client_findById(list, len, bufferId);
			if(bufferIndex >= 0)
			{
				do
				{
					printf(MSG_INFOCLIENT,list[bufferIndex].idClient,list[bufferIndex].name,list[bufferIndex].lastName,list[bufferIndex].cuit,bufferIndex);
					if(utn_getInt(&option, 2, 2, MSG_OPTION_MODIFY, MSG_ERROR, 3, 0)==0)
					{
						switch (option)
						{
						case 1:
							if (utn_getName(list[bufferIndex].name, LONG_NAME,MSG_NAME, MSG_ERROR, 2)==0)
							{
								strupr(list[bufferIndex].name);
								printf(MSG_NAME_OK);
								retorno = 0;
							}else
							{
								printf(MSG_NAME_FAIL);
							}
							break;
						case 2:
							if (utn_getName(list[bufferIndex].lastName, LONG_LASTNAME, MSG_LASTNAME, MSG_ERROR, 2)==0)
							{
								strupr(list[bufferIndex].lastName);
								printf(MSG_LASTNAME_OK);
								retorno = 0;
							}else
							{
								printf(MSG_LASTNAME_FAIL);
							}
							break;
						case 3:
							if (utn_getCuit(bufferCuit, LONG_CUIT, MSG_CUIT, MSG_ERROR, 2)==0)
							{
								if (client_findByCuit(list, len, bufferCuit)==0)
								{
									printf(MSG_CUIT_DUPLICATED);
								}else
								{
									strncpy(list[bufferIndex].cuit, bufferCuit, LONG_CUIT);
									printf(MSG_CUIT_OK);
								}
								retorno = 0;
							}else
							{
								printf(MSG_CUIT_FAIL);
							}
							break;
						case 0:
							flagContinue = FALSE;
							break;
						}
					}else
					{
						attempts--;
					}
				}while(attempts >= 0 && flagContinue == TRUE && retorno == 0);
			}else
			{
				printf(MSG_ID_FAIL);
				attempts--;
			}
		}else
		{
			printf(MSG_ID_FAILATTE);
			flagContinue = FALSE;
		}
	}while(flagContinue == TRUE && attempts >= 0 && retorno -1);
	return retorno;
}

/** \brief Sort the elements in the array of client,  *
 * This function receives the order of the arguments indicates the order UP or DOWN
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int client_sort(Client* list, int len, int order)
{
	int retorno = -1;
	int index;
	int flagSort = 0;
	Client bufferArrray;

	if(list != NULL && len > 0)
	{
		while(flagSort==0)
		{
		flagSort=1;
			for(index=0 ; index<(len-1)  ; index++)
			{
				if((strcmp(list[index].lastName, list[index+1].lastName) < 0 && order == 0) || ((strcmp(list[index].lastName, list[index+1].lastName) > 0) && order == 1) || ((strcmp(list[index].lastName, list[index+1].lastName) == 0 && strcmp(list[index].name, list[index+1].name) < 0) && order == 0) || ((strcmp(list[index].lastName, list[index+1].lastName) == 0 && strcmp(list[index].name, list[index+1].name) > 0) && order == 1))
				{
					bufferArrray = list[index];
					list[index] = list[index+1];
					list[index+1] = bufferArrray;
					flagSort=0;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}


