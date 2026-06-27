#ifndef STRUCTS_H
#define STRUCTS_H

struct Persona{
    char *nombre;
    int edad;
    char genero;
    char fn[8];
    struct Alumno *ptrAlum;
    struct Persona *ptrSig;
};

struct Alumno{
    char matricula[10];
    char carrera[5];
    char semestre;
    char correo[23];
    float calif [5][5];
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "altas.h"
#include "Bajas.h" 

int main(){
    int op,op2,op3;
    struct Persona *ptr;

    do{
        op=menuPrincipal();                                           
        switch (op){
            case 1:
            do{
                op2=menuAltas();
                switch (op2){
                    case 1:
                        Altas(&ptr);
                        break;
                    case 2:
                        AltasVarias(&ptr);
                        break;
                    case 3:
                        printf("Regresando...........\n");
                        break;
                    default:
                        printf("opcion invalida");
                }
            }while(op2!=3);
                break;

            case 2:
                do{
                    op3=menuBajas();
                    switch (op3){
                        case 1:
                            Bajas1(&ptr);
                            break;
                        /*case 2:
                            BajasVarias(&ptr);
                            break;
                        case 3:
                            BajasTodos(&ptr);
                            break;*/
                        case 4:
                            printf("Regresando...........\n");
                            break;
                        default:
                            printf("opcion invalida");
                    }
                }while(op3!=4);
                break;
            case 3:
            do{
                op3=menuMostrar();
                switch (op3){
                    case 1:
                        Mostrar(ptr);
                        break;
                    case 2:
                        mostrarCarreras(ptr);
                        break;
                   /* case 3:
                        mostrarSemestre(ptr);
                        break;
                    case 4:
                        mostrarCarreraSemestre(ptr);
                        break;*/
                    case 5:
                        printf("Regresando...........\n");
                        break;
                    default:
                        printf("opcion invalida");
                break;
            default:
                printf("opcion invalidad");
                break;
        }

    }while(op!=5);
}
