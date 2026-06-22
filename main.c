#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "altas.h"

struct Persona{
    char *nombre;
    int edad;
    char genero;
    char fn[9];
    struct alumno *ptrAlum;
    struct Persona *ptrSig;
};

struct alumno{
    char matricula[8];
    char carrera[5];
    int semestre;
    char correo[23];
    float calif[5][5];
    
};

int main(){
    int op;
    struct Persona *ptr;

    do{
        op=menuPrincipal();
        switch (op)
        {
        case 1:
            Altas(&ptr);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }while (op !=5);
    
    
}
