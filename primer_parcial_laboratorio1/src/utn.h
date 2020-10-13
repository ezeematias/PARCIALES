/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_
#define TRUE 1
#define FALSE 0
#define NO_MORE_ATTEMPTS "----- [NO HAY MÁS REINTENTOS] -----\n"

int utn_sortArrayInt(int* pArray, int len);
int utn_printArrayInt(int* pArray, int len);
int utn_getInt(int *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getFloat(float *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getName (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getAddress (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getEmail (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getCuit (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getString (char* pArray, int len, char* msg, char* msgError, int attempts);

#endif /* UTN_H_ */
