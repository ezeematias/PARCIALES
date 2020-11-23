/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : Ezequiel Unía
 Version     :
 Copyright   : Copyright
 Description : Segundo parcial Laboratorio
 ============================================================================
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#define LONG_NAME 128
#define LONG_CUIT 14
#define PATH_ID_CLIENT 	 "clientID.txt"
#define PATH_CLIENT  "client.txt"
#define MSG_NAME 	 "\n---[ INGRESE NOMBRE ]--------------------------------------------------------------------\n"
#define MSG_LASTNAME "\n---[ INGRESE APELLIDO ]------------------------------------------------------------------\n"
#define MSG_CUIT 	 "\n---[ INGRESE CUIT ]----------------------------------------------------------------------\n"
#define MSG_PRINT_CLIENT "\n-----------------------------------------------------------------------------------------\n|| --[ID]-- || -------[NOMBRE]------- || -----[APELLIDO]----- || --------[CUIT]------- ||\n-----------------------------------------------------------------------------------------"
#define MSG_PRINT "\n|| > %4d   ||    %-16s    ||   %-16s   ||    %15s    ||"
#define MSG_PRINT_OUT  "\n-----------------------------------------------------------------------------------------\n"
#define MSG_CUIT_ERROR "\n---[ EL CUIT YA EXISTE ]-----------------------------------------------------------------\n"


typedef struct
{
    int idClient;
    char nameClient[LONG_NAME];
    char lastNameClient[LONG_NAME];
    char cuitClient[LONG_CUIT];
    int paidSales;
    int unpaidSales;
}Client;

Client* client_new();
void client_delete(Client* this);
int client_setIdClient(Client* this, int idClient);
int client_getIdClient(Client* this, int* idClient);
int isValidIdClient(int idClient);

int client_setNameClient(Client* this, char* nameClient);
int client_getNameClient(Client* this, char* nameClient);
int isValidNameClient(char* nameClient);

int client_setLastNameClient(Client* this, char* lastNameClient);
int client_getLastNameClient(Client* this, char* lastNameClient);
int isValidLastNameClient(char* lastNameClient);

int client_setCuitClient(Client* this, char* cuitClient);
int client_getCuitClient(Client* this, char* cuitClient);
int isValidCuitClient(char* cuitClient);

int client_setPaidSales(Client* this, int paidSales);
int client_getPaidSales(Client* this, int* paidSales);
int isValidPaidSales(int paidSales);

int client_setPaidSales(Client* this, int unpaidSales);
int client_setUnpaidSales(Client* this, int unpaidSales);
int isValidPaidSales(int unpaidSales);

Client* client_add(void);
int client_newId(char* path);
int client_saveId(char* path, int id);
Client* client_newWithParameters(int idClient,char* nameClient,char* lastNameClient,char* cuitClient);
Client* client_newParameters(char* idClient,char* nameClient,char* lastNameClient,char* cuitClient);
int client_print(Client* this);
int client_findByCuit(void* this, void* cuit);
int client_findByIdClient(void* this, void* idClient);

#endif /* CLIENT_H_ */
