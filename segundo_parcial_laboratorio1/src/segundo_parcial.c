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
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
    LinkedList* listClient = ll_newLinkedList();
    LinkedList* listSales = ll_newLinkedList();
    int option;
    int attempts = 2;

	if(!controller_loadFromText(listClient) && !controller_loadFromTextSales(listSales))
	{
		printf(MSG_LOAD_OK);
	}else
	{
		printf(MSG_LOAD_FAIL);
	}

    printf(MSG_START);
    do{
    	utn_getInt(&option, 3, attempts, MSG_OPTION_MENU,MSG_OPTION_ERROR, 10, 0);
        switch(option)
        {
            case 1:
            	if(!controller_addClient(listClient) && !controller_saveAsText(listClient))
            	{
            		printf(MSG_ADD_OK);
            	}else
            	{
            		printf(MSG_ADD_FAIL);
            	}
                break;
            case 2:
            	if(!controller_addSales(listSales,listClient) && !controller_saveAsTextSales(listSales))
            	{
            		printf(MSG_ADDSALES_OK);
                }else
                {
                	printf(MSG_ADDSALES_FAIL);
                }
                break;
            case 3:
            	if(!controller_editSales(listSales, listClient, 1) && !controller_saveAsTextSales(listSales))
            	{
            		printf(MSG_MODIFYSALES_OK);
                }else
                {
                	printf(MSG_MODIFYSALES_FAIL);
                }
                break;
            case 4:
            	if(!controller_editSales(listSales, listClient, 2) && !controller_saveAsTextSales(listSales))
            	{
            		printf(MSG_MODIFYSALES_OK);
                }else
                {
                	printf(MSG_MODIFYSALES_FAIL);
                }
                break;
            case 5:
            	if(!controller_isChargedReport(listSales, listClient))
            	{
            		printf(MSG_IS_CHARGED_OK);
                }else
                {
                	printf(MSG_IS_CHARGED_FAIL);
                }
            	break;
            case 6:
            	if(!controller_toChargedReport(listSales, listClient))
            	{
            		printf(MSG_TO_CHARGED_OK);
                }else
                {
                	printf(MSG_TO_CHARGED_FAIL);
                }
            	break;
            case 7:
            	if(!controller_generalStatistics(listSales, listClient))
                {
                	printf(MSG_GENERAL_OK);
                }else
                {
                	printf(MSG_GENERAL_FAIL);
                }
            	break;
            case 8:
            	if(!controller_ListClient(listClient))
                {
                	printf(MSG_LIST_OK);
                }else
                {
                	printf(MSG_LIST_FAIL);
                }
            	break;
            case 9:
            	if(!controller_ListSales(listSales))
                {
                	printf(MSG_LISTSALES_OK);
                }else
                {
                	printf(MSG_LISTSALES_FAIL);
                }
            	break;
            case 0:
            	option = 10;
                break;
        }
    }while(option != 10);
	printf(MSG_OFF);
	ll_deleteLinkedList(listClient);
	ll_deleteLinkedList(listSales);
	return EXIT_SUCCESS;
}
