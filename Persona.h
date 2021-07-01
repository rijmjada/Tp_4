#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define ERROR -1
#define ALLOK 1


typedef struct
{
    int id;
    char nombre[128];
    char sexo;
    float altura;
}Persona;


//--------------------------------------------------------[Alta/Baja/Modificacion]-----------------------------------------------------------------//

Persona* persona_crearNodo();
Persona* persona_newParametros(char* idStr,char* nombreStr,char* sexoStr,char* alturaStr);
void persona_delete(Persona* this);


//--------------------------------------------------------------[Setters]-------------------------------------------------------------------------//

int persona_setId(Persona* this,int idValue);
int persona_setNombre(Persona* this,char* pNombre);
int persona_setSexo(Persona* this,char pSexo);
int persona_setAltura(Persona* this,float alturaValue);


//--------------------------------------------------------------[Getters]--------------------------------------------------------------------------//

int persona_getId(Persona* this,int* pId);
int persona_getNombre(Persona* this,char* pNombre);
int persona_getSexo(Persona* this,char* pSexo);
int persona_getAltura(Persona* this,float* pAltura);

//------------------------------------------------------------[Imprimir por pantalla]------------------------------------------------------------------------------------//

int mostrarPorReferencia(Persona* lista);
int mostrarUnaPersona(Persona* auxPersona);
int mostrarPersonas(Persona** lista,int tam);

//---------------------------------------------------------[Ordenamiento/Comparacion]-----------------------------------------------------------------------//

int persona_compararId(void* param1,void* param2);
int persona_compararNombre(void* param1,void* param2);
int persona_compararSexo(void* param1,void* param2);
int persona_compararAltura(void* param1,void* param2);




#endif // employee_H_INCLUDED
