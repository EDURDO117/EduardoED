#include <stdio.h>

void Mostrar(struct Persona *ptr){
    struct Persona *ptraux;
    ptraux=ptr;
    while(ptraux!=NULL){
        printf("Nombre: %s", ptraux->nombre);
        printf("Edad: %d\n", ptraux->edad);
        printf("Genero: %s\n", ptraux->genero);
        printf("Fecha de nacimiento: %s\n", ptraux->fn);
        if(ptraux->ptrAlum!=NULL){
            printf("Matricula: %s\n", ptraux->ptrAlum->matricula);
            printf("Carrera: %s\n", ptraux->ptrAlum->carrera);
            printf("Semestre: %c\n", ptraux->ptrAlum->semestre);
            printf("Correo: %s\n", ptraux->ptrAlum->correo);
        }
        ptraux=ptraux->ptrSig;
    }
}
#include <stdio.h>

void mostrarCarreras(struct Persona *ptr){

    if(ptr == NULL){
        printf("No hay registros.\n");
        return;
    }

    printf("\nCarreras registradas:\n");

    while(ptr != NULL){

        if(ptr->ptrAlum != NULL){
            printf("%s\n", ptr->ptrAlum->carrera);
        }

        ptr = ptr->ptrSig;
    }
}