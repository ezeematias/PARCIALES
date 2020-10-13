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
#include "logic.h"

int logic_menu (void)
{
	Client listClient[LONG_CLIENT];
	Publicity listPublicity[LONG_PUBLICITY];

	int retorno = -1;
	int option;
	int flagContinue = TRUE;
	int attempts = 2;

	printf(MSG_START);
	client_initClient(listClient, LONG_CLIENT);
	publicity_initPublicity(listPublicity, LONG_PUBLICITY);

	// ----------------Harcodeo Manual------------------------
	listClient[0].idClient = client_newId();
	strncpy(listClient[0].name, "EZEQUIEL", LONG_NAME);
	strncpy(listClient[0].lastName, "UNIA", LONG_LASTNAME);
	strncpy(listClient[0].cuit, "20-35019857-2", LONG_CUIT);
	listClient[0].isEmpty = FALSE;

	listClient[1].idClient = client_newId();
	strncpy(listClient[1].name, "MATIAS", LONG_NAME);
	strncpy(listClient[1].lastName, "UNIA", LONG_LASTNAME);
	strncpy(listClient[1].cuit, "20-35019857-3", LONG_CUIT);
	listClient[1].isEmpty = FALSE;

	listClient[2].idClient = client_newId();
	strncpy(listClient[2].name, "PEDRO", LONG_NAME);
	strncpy(listClient[2].lastName, "GARCIA", LONG_LASTNAME);
	strncpy(listClient[2].cuit, "20-40019857-2", LONG_CUIT);
	listClient[2].isEmpty = FALSE;

	listClient[3].idClient = client_newId();
	strncpy(listClient[3].name, "JORGE", LONG_NAME);
	strncpy(listClient[3].lastName, "MARCON", LONG_LASTNAME);
	strncpy(listClient[3].cuit, "20-10119850-5", LONG_CUIT);
	listClient[3].isEmpty = FALSE;
	// ------------------------------------------------------

	do
	{
		utn_getInt(&option, 3, attempts, MSG_OPTION_MENU,MSG_OPTION_ERROR, 8, 0);
		switch(option)
		{
		case 0:
			flagContinue = FALSE;
			printf(MSG_OFF);
			break;
		case 1:
			//Alta Cliente
			if (client_add(listClient, LONG_CLIENT)==0)
			{
				printf(MSG_ADD_OK);
			}else
			{
				printf(MSG_ADD_FAIL);
			}
			break;
		case 2:
			//Modificar Cliente
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				if(client_modify(listClient, LONG_CLIENT)==0)
				{
					printf(MSG_MODIFY_OK);
				}else
				{
					printf(MSG_MODIFY_FAIL);
				}
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;
		case 3:
			//Baja Cliente
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				if(logic_removeClient(listClient,LONG_CLIENT,listPublicity,LONG_PUBLICITY)==0)
				{
					printf(MSG_REMOVE_OK);
				}else
				{
					printf(MSG_REMOVE_FAIL);
				}
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;
		case 4:
			//Alta Publicación
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				if(logic_addPublicity(listClient,LONG_CLIENT,listPublicity,LONG_PUBLICITY)==0)
				{
					printf(MSG_ADD_PUBLICITY_OK);
				}else
				{
					printf(MSG_ADD_PUBLICITY_FAIL);
				}
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;
		case 5:
			//Pausar Publicación
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				if(publicity_ArrayIsEmpty(listPublicity, LONG_PUBLICITY)==0)
				{
					logic_isActivePublicity(listClient, LONG_CLIENT, listPublicity, LONG_PUBLICITY);
				}else
				{
					printf(MSG_PUBLICITY_FAIL);
				}
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;
		case 6:
			//Renaduar Publicación
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				if(publicity_ArrayIsEmpty(listPublicity, LONG_PUBLICITY)==0)
				{
					logic_isPausedPublicity(listClient, LONG_CLIENT, listPublicity, LONG_PUBLICITY);
				}else
				{
					printf(MSG_PUBLICITY_FAIL);
				}
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;

		case 7:
			//Imprimir Clientes
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				logic_print(listClient, LONG_CLIENT, listPublicity, LONG_PUBLICITY);
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;
		case 8:
			//Informar - Reportes
			if(client_ArrayIsEmpty(listClient, LONG_CLIENT)==0)
			{
				if(publicity_ArrayIsEmpty(listPublicity, LONG_PUBLICITY)==0)
				{
					logic_report(listClient, LONG_CLIENT, listPublicity, LONG_PUBLICITY);
				}else
				{
					printf(MSG_PUBLICITY_FAIL);
				}
			}else
			{
				printf(MSG_CLIENT_FAIL);
			}
			break;
		}
	}while(flagContinue == TRUE);
	return retorno;
}

/** \brief Disable Client.
 * This function receives the structure to disable a user by ID number.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int logic_removeClient (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{

	int retorno = -1;
	int bufferId;
	int index;
	int option;
	if((utn_getInt(&bufferId, 50, 2, MSG_ID, MSG_ERROR, 2000, 999)==0))
		{
		index = client_findById(listClient, LONG_CLIENT, bufferId);
		if(index > -1)
		{
			printf(MSG_REMOVE_CLIENT,bufferId, listClient[index].name,listClient[index].lastName,listClient[index].cuit,index);
			publicity_printIdClient(listPublicity, lenPublicity, bufferId);
			if((utn_getInt(&option, 50, 2, MSG_OPTION_REMOVE, MSG_ERROR, 1, 0)==0) && option == 1)
			{
				listClient[index].isEmpty = TRUE;
				publicity_removeByIdClient(listPublicity, lenPublicity, bufferId);
				retorno = 0;
			}else if(option == 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int logic_addPublicity (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{
	int retorno =-1;
	int bufferId;
	client_print(listClient, lenClient);
	if(utn_getInt(&bufferId, 10, 2, MSG_ID, MSG_ERROR, 1100, 999)==0 && client_findById(listClient, lenClient, bufferId)>=0)
	{
		publicity_add(listPublicity, lenPublicity, bufferId);
		retorno = 0;
	}else
	{
		printf(MSG_ID_FAIL);
	}
	return retorno;
}

int logic_isActivePublicity (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{
	int retorno =-1;
	int bufferIdPublicity;
	int indexClient;
	int indexPublicity;
	int option;

	if(publicity_ArrayIsActive(listPublicity, lenPublicity)==1)
	{
		publicity_print(listPublicity, lenPublicity);
		if(utn_getInt(&bufferIdPublicity, 5, 2, MSG_IDPUBLICITY, MSG_ERROR, 6000, 4999)==0 && publicity_findById(listPublicity, lenPublicity, bufferIdPublicity)>= 0)
		{
			indexPublicity = publicity_findById(listPublicity, lenPublicity, bufferIdPublicity);
			indexClient = client_findById(listClient, LONG_CLIENT, listPublicity[indexPublicity].idClient);
			client_printIdex(listClient, indexClient);
			if(utn_getInt(&option, 5, 2, MSG_OPTION_ISACTIVE, MSG_ERROR, 1, 0)==0)
			{

			listPublicity[indexPublicity].isActive = FALSE;
			retorno = 0;
			}
		}else
		{
			printf(MSG_ID_FAIL);
		}
	}else
	{
		printf(MSG_ACTIVE_FAIL);
	}
	return retorno;
}

int logic_isPausedPublicity (Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{
	int retorno =-1;
	int bufferIdPublicity;
	int indexClient;
	int indexPublicity;
	int option;

	if(publicity_ArrayIsActive(listPublicity, lenPublicity)==0)
	{
		publicity_printPaused(listPublicity, lenPublicity);
		if(utn_getInt(&bufferIdPublicity, 5, 2, MSG_IDPUBLICITY, MSG_ERROR, 6000, 4999)==0 && publicity_findById(listPublicity, lenPublicity, bufferIdPublicity)>= 0)
		{
			indexPublicity = publicity_findById(listPublicity, lenPublicity, bufferIdPublicity);
			indexClient = client_findById(listClient, LONG_CLIENT, listPublicity[indexPublicity].idClient);
			client_printIdex(listClient, indexClient);
			if(utn_getInt(&option, 5, 2, MSG_OPTION_ISACTIVE, MSG_ERROR, 1, 0)==0)
			{

			listPublicity[indexPublicity].isActive = TRUE;
			retorno = 0;
			}
		}else
		{
			printf(MSG_ID_FAIL);
		}
	}else
	{
		printf(MSG_PAUSED_FAIL);
	}
	return retorno;
}

int logic_print(Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{
	int retorno = -1;
	int counterPublicity;
	if(listClient != NULL && lenClient > 0)
	{
		printf(MSG_PRINT_CLIENT);
		for(int i=0;i<lenClient;i++)
		{
			counterPublicity = publicity_counterByIdClient(listPublicity, lenPublicity, listClient[i].idClient);
			if(listClient[i].isEmpty == FALSE && counterPublicity > -1)
			{
				printf(MSG_PRINT, listClient[i].idClient, listClient[i].name,listClient[i].lastName,listClient[i].cuit,counterPublicity);
			}
		}
		printf(MSG_PRINT_OUT);
		retorno = 0;
	}
	return retorno;
}


int logic_report(Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{
	int retorno = -1;
	int option;
	int flagContinue = TRUE;

	do
	{
		if(utn_getInt(&option, 3, 2, MSG_REPORT_MENU,MSG_OPTION_ERROR, 3, 0)==0)
		{
			switch (option)
			{
			case 1:
				logic_clientMorePublicity(listClient, lenClient, listPublicity, lenPublicity);
				break;
			case 2:
				if(publicity_counterPaused(listPublicity, lenPublicity)>0)
				{
					printf(MSG_PAUSED_PUBLICITY_OK,publicity_counterPaused(listPublicity, lenPublicity));
				}else
				{
					printf(MSG_PAUSED_PUBLICITY_FAIL);
				}
				break;
			case 3:
				publicity_areaNumberMax(listPublicity, lenPublicity);
				break;
			case 0:
				flagContinue = FALSE;
				break;
			}
		}
	}while(flagContinue == TRUE);
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
int logic_clientMorePublicity(Client* listClient, int lenClient, Publicity* listPublicity, int lenPublicity)
{
	int retorno = -1;
	int i;
	int bufferIndex;
	int counterPublicity;
	int bufferCounterPublicity = 0;

	for (i=0;i<lenClient;i++)
	{
		counterPublicity = publicity_counterByIdClient(listPublicity, lenPublicity, listClient[i].idClient);
		if(i==0 || counterPublicity > bufferCounterPublicity)
		{
			bufferCounterPublicity = counterPublicity;
			bufferIndex = i;
		}
	}
	client_printIdex(listClient, bufferIndex);
	return retorno;
}
