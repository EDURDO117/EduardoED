#ifndef ALTAS_H
#define ALTAS_H

#include <stdio.h>
#include <stdlib.h>

struct Persona *nuevaPersona();
struct alumno *nuevoAlumno();

void altas(struct Persona **ptr){

    struct Persona *p = NULL;
    struct alumno *a = NULL;

    p = nuevaPersona();

    if(p == NULL){
        printf("Error al crear persona\n");
        return;
    }

    a = nuevoAlumno();

    if(a == NULL){
        printf("Error al crear alumno\n");
        free(p->nombre);
        free(p);
        return;
    }

    p->ptrAlum = a;
    p->ptrSig = NULL;

    if(*ptr == NULL){
        *ptr = p;
    }
    else{
        struct Persona *aux = *ptr;

        while(aux->ptrSig != NULL){
            aux = aux->ptrSig;
        }

        aux->ptrSig = p;
    }

    printf("\nRegistro agregado correctamente\n");
}

struct Persona *nuevaPersona(){

    struct Persona *p;

    p = (struct Persona *)malloc(sizeof(struct Persona));

    if(p != NULL){

        p->nombre = (char *)malloc(50*sizeof(char));

        if(p->nombre == NULL){
            free(p);
            return NULL;
        }

        printf("Nombre: ");
        scanf(" %[^\n]", p->nombre);

        printf("Edad: ");
        scanf("%d", &p->edad);

        printf("Genero (M/F): ");
        scanf(" %c", &p->genero);

        printf("Fecha de nacimiento: ");
        scanf("%8s", p->fn);

        p->ptrAlum = NULL;
        p->ptrSig = NULL;
    }

    return p;
}

struct alumno *nuevoAlumno(){

    struct alumno *a;

    a = (struct alumno *)malloc(sizeof(struct alumno));

    if(a != NULL){

        printf("Matricula: ");
        scanf("%7s", a->matricula);

        printf("Carrera: ");
        scanf("%4s", a->carrera);

        printf("Semestre: ");
        scanf("%d", &a->semestre);

        printf("Correo: ");
        scanf("%22s", a->correo);

        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){

                printf("Calificacion [%d][%d]: ", i+1, j+1);
                scanf("%f", &a->calif[i][j]);
            }
        }
    }

    return a;
}

#endif
