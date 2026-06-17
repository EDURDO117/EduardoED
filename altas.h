#include <stdio.h>

void altas(struct Persona **ptr);

void altas(struct Persona **ptr){
    struct Persona *p = NULL;
    struct alumno *a = NULL;
    int b=1;

    p = nuevaPersona();
    if(p==NULL){
             b=0;
    }else{
        a = nuevoAlumno();
    }if(a==NULL){
            b=0;
    }


}