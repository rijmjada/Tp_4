
#define ERROR -1
#define ALLOK 1

//Listas
int controller_loadFromText(char* path , LinkedList* genericList);
int controller_saveAsText(char* path , LinkedList* genericList);
int controller_add(LinkedList* genericList);
int controller_edit(LinkedList* genericList);
int controller_remove(LinkedList* genericList);
int controller_List(LinkedList* genericList);

//Faltan
int controller_sort(LinkedList* genericList);
int controller_saveAsBinary(char* path , LinkedList* genericList);
int controller_loadFromBinary(char* path , LinkedList* genericList);

