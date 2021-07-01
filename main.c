#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Persona.h"
#include "Genericas.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

    LinkedList* genericList = ll_newLinkedList();
    int flag = 0;

    do
    {
        switch(menuPrincipal())
        {

        case 1:
            if(controller_loadFromText("data.csv",genericList)==1)
            {
                printf("\nArchivo 'data.csv' cargado correctamente.\n");
                flag = 1;
            }
            else
            {
                printf("\nNo se pudo cargar el archivo 'data.csv'.\n");
            }
            break;

        case 2:
            if(controller_loadFromBinary("data.bin",genericList)==1)
            {
                printf("\nArchivo 'data.bin' cargado correctamente.\n");
                flag = 1;
            }
            else
            {
                printf("\nNo se pudo cargar el archivo 'data.bin'.\n");
            }
            break;

        case 3:
            if(flag)
            {
                controller_add(genericList);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 4:
            if(flag)
            {
                controller_edit(genericList);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 5:
            if(flag)
            {
                controller_remove(genericList);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 6:
            if(flag)
            {
                controller_List(genericList);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 7:
            if(flag)
            {
                controller_sort(genericList);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;


        case 8:
            if(flag)
            {
                if(controller_saveAsText("data.csv",genericList) == 1)
                {
                    printf("\nArchivo 'data.csv' actualizado!.\n");
                }
                else
                {
                    printf("\nError al intentar salvar 'data.csv'!.\n");
                }
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 9:

            if(flag)
            {
                if(controller_saveAsBinary("data.bin",genericList) == 1)
                {
                    printf("\nArchivo 'data.csv' guardado!.\n");
                }
                else
                {
                    printf("\nError al intentar guardar 'data.bin'!.\n");
                }
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }

            break;

        case 10:
            exit(1);
            break;
        default:
            system("cls");
            printf("\nNo ingreso una opcion valida.\n\n");
            break;
        }
        system ("pause");
    }
    while(1);


    return 0;
}

