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
            	//Add Client
            	if(!controller_addClient(listClient))
            	{
            		controller_saveAsText(listClient);
            		printf(MSG_ADD_OK);
            	}else
            	{
            		printf(MSG_ADD_FAIL);
            	}
                break;
            case 2:
            	//Venta de Afiches
            	if(!controller_addSales(listSales,listClient))
            	{
            		controller_saveAsTextSales(listSales);
            		printf(MSG_ADDSALES_OK);
                }else
                {
                	printf(MSG_ADDSALES_FAIL);
                }
                break;
            case 3:
            	//Modificar afiche/venta
                break;
            case 4:
            	//Cobrar Ventas (Modificar)
                break;
            case 5:
            	//Generar informe de cobros
            	break;
            case 6:
            	//Generar informe de deudas
            	break;
            case 7:
            	//Generar estadisticas || 1- clientes con más afiches vendidos || 2- Clientes con menos afiches vendidos || 3- Venta con más afiches.
            	break;
            case 8:
            	//Listar Clientes
            	if(!controller_ListClient(listClient))
                {
                	printf(MSG_LIST_OK);
                }else
                {
                	printf(MSG_LIST_FAIL);
                }
            	break;
            case 9:
            	//Listar Clientes
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
