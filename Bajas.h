#include <stdio.h>
#include <stdlib.h>

void Bajas1(struct Persona **ptr){
    struct Persona *ptraux;
    ptraux=*ptr;
    if(ptraux==NULL){
        printf("No existe registro\n");
    }else{
        ptraux=ptraux->ptrSig;
        if(ptraux->ptrAlum!=NULL){
            free(ptraux->ptrAlum);
        }
        free(ptraux->nombre);
        free(ptraux);
    }
}
