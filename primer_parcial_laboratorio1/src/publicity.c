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
#include <limits.h>
#include "publicity.h"

/** \brief New ID.
 * Generates a new identity number.
 * \param (void)
 * \return int Return (ID), NewID.
 *
 */
int publicity_newId(void)
{
	static int id = 4999;
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
int publicity_initPublicity(Publicity* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<=len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].idPublicity = 0;
			list[i].areaNumber = 0;
			list[i].isActive = FALSE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief New Publicity.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_add(Publicity* list, int len, int idClient)
{
	int retorno = -1;
	int index;
	Publicity bufferArrray;

	if (publicity_serchIndexEmpty(list, len) >= 0 && utn_getInt(&bufferArrray.areaNumber, len, 2, MSG_AREA, MSG_ERROR, LONG_MAX, 0)==0 && utn_getString(bufferArrray.textPublicity, LONG_TEXT, MSG_TEXT, MSG_ERROR, 2)==0)
	{
		strupr(bufferArrray.textPublicity);
		index = publicity_serchIndexEmpty(list, LONG_PUBLICITY);
		list[index].idPublicity = publicity_newId();
		list[index].idClient = idClient;
		list[index].isEmpty = FALSE;
		list[index].isActive = TRUE;
		list[index].areaNumber = bufferArrray.areaNumber;
		strncpy(list[index].textPublicity, bufferArrray.textPublicity, LONG_TEXT);

		printf(MSG_IDPUBLICITY_NEW, list[index].idPublicity);
		retorno = 0;

	}else if(publicity_serchIndexEmpty(list, len) == -1){
			printf(MSG_NOMORESPACE_PUBLICITY);
			retorno = -2;
	}
	return retorno;
}

/** \brief Active-Publicity print
 * This function prints the list of active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_print(Publicity* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf(MSG_PRINT_PUBLICITY);
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].isActive==TRUE)
			{
				printf(MSG_PRINTINDEX_PUBLICITY, list[i].idPublicity, list[i].textPublicity,list[i].idClient);
			}
		}
		printf(MSG_PRINT_PUBLICITYOUT);
		retorno = 0;
	}
	return retorno;
}

/** \brief Paused-Publicity print
 * This function prints the list of active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_printPaused(Publicity* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf(MSG_PRINT_PUBLICITY);
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].isActive==FALSE)
			{
				printf(MSG_PRINTINDEX_PUBLICITY, list[i].idPublicity, list[i].textPublicity,list[i].idClient);
			}
		}
		printf(MSG_PRINT_PUBLICITYOUT);
		retorno = 0;
	}
	return retorno;
}

/** \brief Empty Publicity list
 * This function searches the structure for active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_ArrayIsPaused (Publicity* list, int len)
{
	int i;
	int retorno = 0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].isActive==FALSE)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Empty Publicity list
 * This function searches the structure for active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_ArrayIsActive (Publicity* list, int len)
{
	int i;
	int retorno = 0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isActive==FALSE)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Empty Publicity list
 * This function searches the structure for active Publicity.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (0) if False - (1) if True
 *
 */
int publicity_ArrayIsEmpty (Publicity* list, int len)
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

/*
int publicity_printIdClient(Publicity* list, int len, int idClient)
{
	int retorno = -1;

	printf(MSG_PRINTREMOVE_PUBLICITY);
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == FALSE && list[i].isActive == TRUE && list[i].idClient == idClient)
		{
			printf(MSG_PRINTACTIVEREMOVE_PUBLICITY, list[i].idPublicity, list[i].textPublicity,list[i].idClient);
		}
		if(list[i].isEmpty == FALSE && list[i].isActive == FALSE && list[i].idClient == idClient)
		{
			printf(MSG_PRINTPAUSEDREMOVE_PUBLICITY, list[i].idPublicity, list[i].textPublicity,list[i].idClient);
		}
	}
	printf(MSG_PRINTREMOVE_PUBLICITYOUT);
	retorno = 0;
	return retorno;
}
*/

/** \brief Publicity print by ID Client.
 * This function prints the list of active Publicity.
 * \param list Employee* Pointer to array of Publicity
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_printIdClient(Publicity* list, int len, int idClient)
{
	int retorno = -1;

	if(publicity_counterByIdClient(list, len, idClient)>0)
	{
		printf(MSG_PRINT_PUBLICITY);
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].isActive == TRUE && list[i].idClient == idClient)
			{
				printf(MSG_PRINTINDEX_PUBLICITY, list[i].idPublicity, list[i].textPublicity,list[i].idClient);
			}
		}
		printf(MSG_PRINT_PUBLICITYOUT);
		retorno = 0;
	}else
	{
		printf(MSG_NOMORE_PUBLICITY);
	}

	return retorno;
}

/** \brief Publicity remove by idClient.
 * This function prints the list of active Publicity.
 * \param list Employee* Pointer to array of Publicity
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_removeByIdClient(Publicity* list, int len, int idClient)
{
	int retorno = -1;

	if(publicity_counterByIdClient(list, len, idClient)>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].isActive == TRUE && list[i].idClient == idClient)
			{
				list[i].isEmpty = TRUE;
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Search for an empty index.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Publicity* Pointer to array of Publicity
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_serchIndexEmpty(Publicity* list, int len)
{
	int retornar = -1;
	if(list != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE && list[i].idPublicity == 0)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}

/** \brief find an Client by Id en returns the index position in array.
 *
 * \param Publicity* list, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number Publicity.
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int publicity_findById(Publicity* list, int len,int id)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(list[i].idPublicity == id && list[i].isEmpty == FALSE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

/** \brief find an Client by Id en returns the index position in array.
 *
 * \param Publicity* list, Pointer to array of Publicity.
 * \param int len, Array length.
 * \param int id, Identity number Publicity.
 * \return Return Publicity index position or (-1) if [Invalid length or NULL
pointer received or Publicity not found]
 *
 */
int publicity_counterByIdClient(Publicity* list, int len,int id)
{
	int retorno = -1;
	int counterPublicity = 0;
	for(int i=0;i<len;i++)
	{
		if(list[i].idClient == id && list[i].isEmpty == FALSE)
		{
			counterPublicity++;
		}
		retorno = counterPublicity;
	}
	return retorno;
}

/** \brief find an Client by Id en returns the index position in array.
 *
 * \param Publicity* list, Pointer to array of Publicity.
 * \param int len, Array length.
 * \param int id, Identity number Publicity.
 * \return Return Publicity index position or (-1) if [Invalid length or NULL
pointer received or Publicity not found]
 *
 */
int publicity_counterByIdClientPaused(Publicity* list, int len,int id)
{
	int retorno = -1;
	int counterPublicity = 0;
	for(int i=0;i<len;i++)
	{
		if(list[i].idClient == id && list[i].isEmpty == FALSE && list[i].isActive == FALSE)
		{
			counterPublicity++;
		}
		retorno = counterPublicity;
	}
	return retorno;
}

/** \brief find an Client by Id en returns the index position in array.
 *
 * \param Publicity* list, Pointer to array of Publicity.
 * \param int len, Array length.
 * \param int id, Identity number Publicity.
 * \return Return Publicity index position or (-1) if [Invalid length or NULL
pointer received or Publicity not found]
 *
 */
int publicity_counterByIdClientActive(Publicity* list, int len,int id)
{
	int retorno = -1;
	int counterPublicity = 0;
	for(int i=0;i<len;i++)
	{
		if(list[i].idClient == id && list[i].isEmpty == FALSE && list[i].isActive == TRUE)
		{
			counterPublicity++;
		}
		retorno = counterPublicity;
	}
	return retorno;
}

/** \brief Paused posts counter.
 *
 * \param Publicity* list, Pointer to array of Publicity.
 * \param int len, Array length.
 * \return Return Publicity index position or (-1) if [Invalid length or NULL
pointer received or Publicity not found]
 *
 */
int publicity_counterPaused(Publicity* list, int len)
{
	int retorno = -1;
	int counterPublicityPaused = 0;
	for(int i=0;i<len;i++)
	{
		if(list[i].isActive == FALSE && list[i].isEmpty == FALSE)
		{
			counterPublicityPaused++;
		}
		retorno = counterPublicityPaused;
	}
	return retorno;
}

/** \brief Get maximum publicity.
 *
 * \param Publicity* list, Pointer to array of employees.
 * \param int len, Array length.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_areaNumberMax(Publicity* list, int len)
{
    Publicity bufferList;
    int retorno =-1;
    int counterPublicity =0;
    int bufferCounterPublicity;
    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty == FALSE && publicity_counterByAreaNumber(list,len,list[i].areaNumber, &counterPublicity)==0)
            {
                if(i==0 || counterPublicity > bufferCounterPublicity)
                {
                	bufferCounterPublicity = counterPublicity;
                    bufferList = list[i];
                    retorno=0;
                }
            }
        }
        printf(MSG_AREANUMBER, bufferList.areaNumber);
    }
    return retorno;
}

/** \brief Area posts counter.
 *
 * \param Publicity* list, Pointer to array of employees.
 * \param int len, Array length.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicity_counterByAreaNumber(Publicity* list, int len, int areaNumber, int *pCounter)
{
    int retorno =-1;
    int counterPublicity = 0;
    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty == FALSE && list[i].areaNumber == areaNumber)
            {
            	counterPublicity++;
                retorno=0;
            }
        }
        *pCounter = counterPublicity;
    }
    return retorno;
}
