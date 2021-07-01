#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Persona.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* genericList)
{
    int retorno = ERROR;
    char buffer[4][30];
    int cant = 0;//cantidad de variables que nos pudo retornar.
    Persona* NodoAux;

    // Esta linea se debe modificar segun el criterio
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {
        // Esta linea se debe modificar segun el criterio
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant < 4)  // Esta linea se debe modificar segun el criterio
        {
            break;
        }
        else
        {
            /***  // Esta linea se debe modificar segun el criterio
            buffer[0] id;
            buffer[1] nombre;
            buffer[2] sexo;
            buffer[3] altura;
            ***/
            NodoAux = persona_newParametros((buffer[0]),buffer[1],(buffer[2]),(buffer[3]));// Esta linea se debe modificar segun el criterio

            if( NodoAux != NULL )
            {

                ll_add(genericList,NodoAux);//agrego un puntero al final del linkedlist.

                retorno = ALLOK;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param pFile FILE* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int parser_FromBinary(FILE* pFile, LinkedList* genericList)
{
    int retorno = ERROR;
    Persona* auxPersona = NULL;
    int cant = 0;

    while(!feof(pFile))
    {
        auxPersona = persona_crearNodo();

        if(auxPersona == NULL)
        {
            break;
        }

        cant = fread(auxPersona,sizeof(Persona),1,pFile);
        persona_setId(auxPersona,auxPersona->id);

        if(cant<1)//significa que estaria todo mal
        {
            break;
        }

        else
        {
            ll_add(genericList,auxPersona);
            retorno = ALLOK;
        }
    }

    return retorno;
}

