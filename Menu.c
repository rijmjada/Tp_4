
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Genericas.h"

int menuPrincipal()
{
    int usuario  = -1;

    system("cls");
    printf("**Menu Principal**\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Dar alta alumno.\n");
    printf("4. Modificar datos alumno.\n");
    printf("5. Dar baja alumno.\n");
    printf("6. Listado de alumnos.\n");
    printf("7. Generar orden de alumnos.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n");

    fflush(stdin);
    scanf("%d",&usuario);

    return usuario;
}

int menuOrdenar()
{
    int option;
    system("cls");
    printf("1)Ordenar por id.\n");
    printf("2)Ordenar por nombre.\n");
    printf("3)Ordenar por sexo.\n");
    printf("4)Ordenar por altura.\n");
    printf("5)Salir.\n");
    getInt(&option,"Elija opcion: ","Error.\n",1,5,5);

    return option;
}

int menuTipoOrden()
{
    int option;
    system("cls");
    fflush(stdin);
    printf("\n\n");
    printf("1)Ascendente.\n");
    printf("2)Descendente.\n");
    getInt(&option,"Elija opcion: ","Error.\n",1,2,5);

    return option;
}

int menuModificacion()
{
    int usuario;
    system("cls");
    fflush(stdin);
    printf("\n\n");
    printf("**Menu Modificacion**\n\n");

    printf("1)Modificar nombre.\n");
    printf("2)Modificar sexo.\n");
    printf("3)Modificar altura.\n");
    getInt(&usuario,"Elija opcion <1/3>: ","Error. Reingrese\n",1,3,3);

    return usuario;
}
