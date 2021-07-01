#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Persona.h"
#include "Genericas.h"

//--------------------------------------------------------[Alta/Baja/Modificacion]-----------------------------------------------------------------//

Persona* persona_crearNodo()
{
    Persona* nuevoNodo = (Persona*) malloc(sizeof(Persona));

    if(nuevoNodo != NULL)
    {
        persona_setId(nuevoNodo,0);
        persona_setNombre(nuevoNodo," ");
        persona_setSexo(nuevoNodo,' ');
        persona_setAltura(nuevoNodo,0);
    }
    return nuevoNodo;
}

Persona* persona_newParametros(char* idStr,char* nombreStr,char* sexoStr,char* alturaStr)
{
    Persona* personaAux = persona_crearNodo();

    if(personaAux!=NULL)
    {
        //if()
        if(     persona_setId(personaAux,atoi(idStr))
                &&persona_setNombre(personaAux,nombreStr)
                &&persona_setSexo(personaAux,*sexoStr)
                &&persona_setAltura(personaAux,atof(alturaStr)) == 0)
        {
            persona_delete(personaAux);
        }
    }
    return personaAux;
}


void persona_delete(Persona* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

//--------------------------------------------------------------[Setters]-------------------------------------------------------------------------//

int persona_setId(Persona* this,int idValue)
{
    int todoOk = 0;
    static int IdMaximo = -1;

    if(this != NULL)
    {
        if(idValue < 0)
        {
            IdMaximo++;
            this->id = IdMaximo;
        }
        else
        {
            if(idValue>IdMaximo)
            {
                this->id = idValue;
                IdMaximo = idValue;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int persona_setNombre(Persona* this,char* pNombre)
{
    int todoOk = 0;
    if(this!=NULL && pNombre !=NULL && strlen(pNombre)>=2)
    {
        strcpy(this->nombre,pNombre);
        todoOk = 1;
    }
    return todoOk;
}

int persona_setSexo(Persona* this,char pSexo)
{
    int retorno = ERROR;
    if(this != NULL)
    {
        this->sexo = pSexo;
        retorno = ALLOK;
    }
    return retorno;
}

int persona_setAltura(Persona* this,float alturaValue)
{
    int retorno = ERROR;
    if(this != NULL)
    {
        this->altura = alturaValue;
        retorno = ALLOK;
    }
    return retorno;
}

//--------------------------------------------------------------[Getters]--------------------------------------------------------------------------//

int persona_getId(Persona* this,int* pId)
{
    int retorno = ERROR;
    if(this != NULL && pId != NULL)
    {
        *pId = this->id;
        retorno = ALLOK;
    }
    return retorno;
}

int persona_getNombre(Persona* this,char* pNombre)
{
    int retorno = ERROR;
    if(this != NULL && pNombre != NULL)
    {
        strcpy(pNombre,this->nombre);
        retorno = ALLOK;
    }
    return retorno;
}

int persona_getSexo(Persona* this,char* pSexo)
{
    int retorno = ERROR;
    if(this != NULL && pSexo != NULL)
    {
        *pSexo = this->sexo;
        retorno = ALLOK;
    }
    return retorno;
}

int persona_getAltura(Persona* this,float* pAltura)
{
    int retorno = ERROR;

    if( this != NULL && pAltura != NULL )
    {
        *pAltura = this->altura;
    }
    return retorno;
}

//------------------------------------------------------------[Imprimir por pantalla]------------------------------------------------------------------------------------//

int mostrarPorReferencia(Persona* lista)
{
    int retorno = ERROR;

    int idScope;
    char nombreScope[20];
    char sexoScope;
    float alturaScope;

    if(lista != NULL
            && persona_getId(lista,&idScope)
            &&persona_getNombre(lista,nombreScope)
            &&persona_getSexo(lista,&sexoScope)
            &&persona_getAltura(lista,&alturaScope))
    {
        printf("| %d | \t%s | \t%c | \t%.2f |\n"
               ,idScope
               ,nombreScope
               ,sexoScope
               ,alturaScope);

        retorno = ALLOK;
    }

    return retorno;
}

int mostrarUnaPersona(Persona* auxPersona)
{
    int todoOk = 0;
    if(auxPersona!=NULL)
    {
        printf(" | %5d | %15s | %c | %.2f |\n",auxPersona->id,auxPersona->nombre,auxPersona->sexo,auxPersona->altura);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPersonas(Persona** lista,int tam)
{
    int retorno = ERROR;
    if(lista != NULL && tam >=0)
    {
        printf("\nId \tNombre \tSexo  \tAltura");
        for(int i=0; i<tam; i++)
        {
            mostrarPorReferencia (*(lista + i));
        }
        printf("\n\n");
        retorno = ALLOK;
    }
    if(!retorno)
    {
        printf("No se pudo mostar la lista!\n");
    }
    return retorno;
}

//---------------------------------------------------------[Ordenamiento/Comparacion]-----------------------------------------------------------------------//


/** \brief Ordenamiento por ID.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int persona_compararId(void* param1,void* param2)
{
    int retorno;

    //debo castear cada employee, debido a que es un puntero a void.
    Persona* NodoAux1 = (Persona*) param1;
    Persona* NodoAux2 = (Persona*) param2;

    if(NodoAux1->id > NodoAux2->id)
    {
        retorno = -1; //si el primero es mayor al segundo.
    }
    else if(NodoAux1->id < NodoAux2->id)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0; // Si son iguales
    }

    return retorno;
}

/** \brief Ordenamiento por nombre.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int persona_compararNombre(void* param1,void* param2)
{
    int retorno;

    Persona* NodoAux1 = (Persona*) param1;
    Persona* NodoAux2 = (Persona*) param2;

    if(strcmp(NodoAux1->nombre,NodoAux2->nombre) >0 )//Si uso strcmpi aparece un warning por implicit declaration...
    {
        retorno = -1;
    }
    else if(strcmp(NodoAux1->nombre,NodoAux2->nombre) <0 )
    {
        retorno = 1;
    }
    else
    {
        retorno = 0; // Si son iguales
    }
    return retorno;
}

/** \brief Ordenamiento por nombre.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int persona_compararSexo(void* param1,void* param2)
{
    int retorno;

    if(param1 != NULL && param2 != NULL)
    {
        Persona* NodoAux1 = (Persona*) param1;
        Persona* NodoAux2 = (Persona*) param2;

        if(NodoAux1->sexo > NodoAux2->sexo)
        {
            retorno = -1;
        }
        else if(NodoAux1->sexo < NodoAux2->sexo)
        {
            retorno = 1;
        }
        else // Si son iguales
        {
            retorno = 0;
        }
    }
    return retorno;
}

int persona_compararAltura(void* param1,void* param2)
{
    int retorno;

    if(param1 != NULL && param2 != NULL)
    {
        Persona* NodoAux1 = (Persona*) param1;
        Persona* NodoAux2 = (Persona*) param2;

        if(NodoAux1->altura > NodoAux2->altura)
        {
            retorno = -1;
        }
        else if(NodoAux1->altura < NodoAux2->altura)
        {
            retorno = 1;
        }
        else // Si son iguales
        {
            retorno = 0;
        }
    }
    return retorno;

}


