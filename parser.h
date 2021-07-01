#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


int parser_FromText(FILE* pFile , LinkedList* genericList);
int parser_FromBinary(FILE* pFile , LinkedList* genericList);


#endif // PARSER_H_INCLUDED
