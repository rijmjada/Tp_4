#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Persona.h"
#include "parser.h"
#include "Genericas.h"
#include "Menu.h"



/** \brief Alta Entidad
 *
 * \param 'genericList' LinkedList* Puntero a la estructura LinkedList.
 * \return int [-1] Si la lista es NULL , y si los datos son mal cargados.
 *             [ 1] Si esta todo OK
 */
int controller_add(LinkedList* genericList)
{
    int ret = ERROR;

    if( genericList != NULL )
    {
        char auxNombre[40];
        char auxSexo;
        float auxAltura;

// Creo una entidad vacia y guardo el puntero en NodoAux
        Persona* NodoAux = persona_crearNodo();

        system("cls");
// Tomo datos para la nueva entidad
        if(NodoAux != NULL
                && getNombreOApellido(auxNombre,"\nIngrese nombre [3/28 min.max]:\n","Error.\n",3,28,5)
                && getSexo(&auxSexo,"\nIngrese sexo [f/m]: \n","Error.\n",5)
                && getFloat(&auxAltura,"\nIngrese altura [1.40/1.99] :\n","\nError.\n",1.4,1.99,5)){

// Si los datos fueron validados los asigno a mi Nodo auxiliar con el uso de los Setters
            persona_setId(NodoAux,-1);
            persona_setNombre(NodoAux,auxNombre);
            convertirMayuscula(&auxSexo);
            persona_setSexo(NodoAux,auxSexo);
            persona_setAltura(NodoAux,auxAltura);

// LLamo a ll_add para agregar el NodoAux a la lista
            if(!ll_add(genericList,NodoAux))
            {
                printf("Alta exitosa!.\n");
                ret = ALLOK;
            }
// Si hubo un error Informo al usuario
            else
            {
                printf("Hubo un error en el alta!.\n");
            }
        }
    }
    return ret;
}


/** \brief Modificacion Entidad
 *
 * \param 'genericList' LinkedList* Puntero a la estructura LinkedList.
 * \return int [-1] Si la lista es NULL
 *             [ 1] Si esta todo OK
 */
int controller_edit(LinkedList* genericList)
{
    int retorno = ERROR;
    int idBuffer;
    Persona* NodoAux;
    int tam = ll_len(genericList);

    system("cls");
    printf("**Modificar datos.**\n");

    if( genericList != NULL )
    {
// Pido id al usuario para luego buscarlo en la LinkedList
        getInt(&idBuffer,"\n**Ingrese ID a modificar:\n","Error.\n",1,1500,2);

        for(int i=0; i<tam; i++)
        {
// Recorro el LinkedList y en cada posicion guardo el nodo correspondiente en mi NodoAux
            NodoAux = (Persona*)ll_get(genericList,i);

// En cada iteracion pregunto si hay coincidencia entre el campo id de NodoAux con el id ingresado por el usuario
            if(NodoAux->id == idBuffer)
            {
// Si hay coincidencia muestro al cliente los datos antes de modificar
                system("cls");
                printf("| Id | \tNombre | \tSexo| \tAltura |\n");
                printf("---------------------------------------\n");
                mostrarPorReferencia(NodoAux);
                printf("---------------------------------------\n\n");

                switch(menuModificacion())
                {
                case 1:
                    if(getNombreOApellido(NodoAux->nombre,"\nIngrese nuevo nombre:\n","Error.\n",3,40,5) != -1)
                    {
                        retorno = ALLOK;
                        printf("\nCambios en nombre guardados.\n");
                    }
                    break;

                case 2:
                    if(getSexo(&NodoAux->sexo,"\nIngrese sexo [f/m]: \n","Error.\n",5) != -1)
                    {
                        retorno = ALLOK;
                        printf("\nCambios en horas guardados.\n");
                    }
                    break;

                case 3:
                    if( getFloat(&NodoAux->altura,"\nIngrese altura [1.40/1.99] :\n","\nError.\n",1.44,1.99,5) != -1)
                    {
                        retorno = ALLOK;
                        printf("\nCambios en sueldo guardados.\n");
                    }
                    break;

                case 4:
                    exit(1);
                    break;

                default:
                    printf("\nNo ingreso una opcion valida!.\n");
                }
            }
        }
    }
    if(retorno == -1)
    {
        printf("\nERROR!.\n");
    }

    return retorno;
}

/** \brief Baja Entidad
 *
 * \param 'genericList' LinkedList* Puntero a la estructura LinkedList.
 * \return int [-1] Si la lista es NULL
 *             [ 1] Si esta todo OK
 *
 */
int controller_remove(LinkedList* genericList)
{
    int retorno = ERROR;
    int idBuffer;
    int idNotFound = 1;
    Persona* NodoAux;
    int tam = ll_len(genericList);
    char confirma;

    system("cls");
    printf("**Baja .**\n");

    if( genericList != NULL)
    {
        getInt(&idBuffer,"\n**Ingrese ID : ","Error.\n",1,1500,5);

        for(int i=0; i<tam; i++)
        {
            NodoAux = (Persona*)ll_get(genericList,i);

            if(NodoAux->id == idBuffer)
            {
                idNotFound = -1;
                system("cls");
                printf("| Id | \tNombre | \tSexo| \tAltura |\n");
                printf("---------------------------------------\n");
                mostrarPorReferencia(NodoAux);
                printf("---------------------------------------\n\n");

                printf("\n**confirma baja? (s/n): ");
                fflush(stdin);
                scanf("%c",&confirma);
                confirma = tolower(confirma);
                printf("\n");

                if(confirma == 's')
                {
                    if(!ll_remove(genericList,i))
                    {
                        printf("**Baja exitosa!.\n");
                        retorno = ALLOK;
                        break;
                    }
                    else
                    {
                        printf("\n**Error en la baja!.\n");
                        retorno = ALLOK;
                        //break;
                    }
                }
                else if(confirma == 'n')
                {
                    printf("\n**Bajar cancelada por el usuario\n");
                    break;
                }
                else
                {
                    printf("\n**No ingreso una opcion valida!.\n");
                    retorno = ALLOK;
                }
            }
        }
    }
    if(idNotFound == 1)
    {
        printf("\n**No ingreso un id Valido!.\n");
    }

    return retorno;
}

/** \brief Listar Entidad
 *
* \param 'genericList' LinkedList* Puntero a la estructura LinkedList.
 * \return int [-1] Si la lista es NULL
 *             [ 1] Si esta todo OK
 *
 */
int controller_List(LinkedList* genericList)
{
    int ret = ERROR;
    int tam = ll_len(genericList);

    if( genericList != NULL)
    {
        system("cls");
        printf("\n|Id    \t|Nombre  \t|Sexo|Altura");
        printf("\n---------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            mostrarUnaPersona((Persona*)ll_get(genericList,i));
            ret = ALLOK;
        }
    }

    if(ret == ERROR)
    {
        printf("ERROR.\n");
    }

    return ret;
}

/** \brief Listar Entidad
 *
* \param 'genericList' LinkedList* Puntero a la estructura LinkedList.
 * \return int [-1] Si la lista es NULL
 *             [ 1] Si esta todo OK
 *
 */

int controller_sort(LinkedList* genericList)
{
    int retorno = -1;


    if(genericList != NULL)
    {
        switch(menuOrdenar())
        {
        case 1:

            if(menuTipoOrden()==1)
            {
                ll_sort(genericList,persona_compararId,0);
            }
            else
            {
                ll_sort(genericList,persona_compararId,1);
            }

            break;

        case 2:

            if(menuTipoOrden()==1)
            {
                ll_sort(genericList,persona_compararNombre,0);
            }
            else
            {
                ll_sort(genericList,persona_compararNombre,1);
            }

            break;

        case 3:

            if(menuTipoOrden()==1)
            {
                ll_sort(genericList,persona_compararSexo,0);
            }
            else
            {
                ll_sort(genericList,persona_compararSexo,1);
            }
            break;

        case 4:

            if(menuTipoOrden()==1)
            {
                ll_sort(genericList,persona_compararAltura,0);
            }
            else
            {
                ll_sort(genericList,persona_compararAltura,1);
            }
            break;

        case 5:
            break;
        }
    }

    return retorno;
}


//-----------------------------------------------[text/binario]----------------------------------------------//


/** \brief Carga los datos de "la entidad que corresponda" desde el archivo 'data.csv' (modo texto).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param 'genericList' LinkedList* Puntero a la estructura LinkedList.
 * \return int # (-1) Si la lista y/o path retornan NULL o si la funcion 'parser_FromText' da ERROR.
 *             # ( 1) Si funciona
 *
 */
int controller_loadFromText(char* path, LinkedList* genericList)
{
    FILE* f;
    int retorno = ERROR;
    int controlCarga;
    f = fopen(path,"r");

    if(f!=NULL && genericList!=NULL)
    {

        controlCarga = parser_FromText(f,genericList);
        if(controlCarga != -1)
        {
            retorno = ALLOK;
        }
    }

    fclose(f);
    return retorno;

}


/** \brief Guarda los datos de 'genericList' en el archivo 'data.csv' (modo texto).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param genericList LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [ 1] si se cargo correctamente -
 *                      [-1] Si hubo un error.
 *
 */
int controller_saveAsText(char* path, LinkedList* genericList)
{
    int retorno = ERROR;

    FILE* auxFile;
    int tam = ll_len(genericList);
    Persona* NodoAux;

    if( genericList != NULL && tam>0 && path!=NULL)
    {
        auxFile = fopen(path,"w");

        if(auxFile==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return retorno;
        }

        for(int i=0; i<tam; i++)
        {

            NodoAux = (Persona*)ll_get(genericList,i);

            if( NodoAux != NULL )
            {
                fprintf(auxFile,"%d,%s,%c,%f\n",NodoAux->id,NodoAux->nombre,NodoAux->sexo,NodoAux->altura);
                retorno = ALLOK;
            }
        }
        fclose(auxFile);
    }
    return retorno;
}

/** \brief Guarda los datos de la entidad en el archivo 'data.bin' (modo binario).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param genericList LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [ 1] si se cargo correctamente -
 *                     [-1] Si hubo un error.
 */
int controller_saveAsBinary(char* path, LinkedList* genericList)
{
    int retorno = ERROR;
    FILE* auxBin;
    int len = ll_len(genericList);

    if(len>0 && path!=NULL && genericList!=NULL)
    {
        auxBin = fopen(path,"wb");
        if(auxBin!=NULL)
        {
            for(int i=0; i<len; i++)
            {
                fwrite(ll_get(genericList,i),sizeof(Persona),1,auxBin);
            }
        }

        fclose(auxBin);
        retorno = ALLOK;
    }
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param genericList LinkedList* Puntero a la estructura LinkedList.
 *\return int Retorna [ 1] si se cargo correctamente -
 *                    [-1] Si hubo un error.
 */
int controller_loadFromBinary(char* path, LinkedList* genericList)
{
    FILE* f;
    int retorno = ERROR;
    int controlCarga;
    f = fopen(path,"rb");//abro

    if(f!=NULL && genericList!=NULL)
    {
        //parseo
        controlCarga = parser_FromBinary(f,genericList);
        if(controlCarga != -1)
            retorno = ALLOK;
    }
    else
    {
        printf("\nError al cargar archivo 'data.bin'.\n");
    }

    fclose(f);//cierro

    return retorno;
}
