#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

int menu(void){
    int opcion;
    printf("\n1.- Crear dato\n");
    printf("2.- Funciones\n");
    printf("3.- Mostrar datos\n");
    printf("4.- Eliminar ultimo dato\n");
    printf("5.- Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuFunciones(void){
    int opcion;
    printf("\n--- Funciones ---\n" );
    printf("1.- Buscar\n");
    printf("2.- Contar\n");
    printf("3.- Regresar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void funciones(struct Dato *ptr);
void crearDato(struct Dato **ptr);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
void Salir(struct Dato **ptr);

int main (void){
    struct Dato *ptr = NULL;
    int opcion;

    do{
        opcion = menu();
        switch(opcion){
            case 1:
                crearDato(&ptr);
                break;
            case 2:
                menuFunciones(ptr);
                break;
            case 3:
                mostrarDato(&ptr);
                break;
            case 4:
                liberarDato(&ptr);
            case 5:
                Salir(&ptr);
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 4);

    return 0;
}

// Crear nodo 
void crearDato(struct Dato **ptr) {
    struct Dato *nuevo = (struct Dato *)malloc(sizeof(struct Dato));
    struct Dato *ptraux;

    if (nuevo == NULL) {
        printf("Error de memoria\n");
        return;
    }

    printf("Ingresa un numero: ");
    scanf("%d", &(nuevo->d));

    nuevo->ptrSig = NULL;

    if (*ptr == NULL) {
        *ptr = nuevo;
    } else {
        ptraux = *ptr;
        while (ptraux->ptrSig != NULL) {
            ptraux = ptraux->ptrSig;
        }
        ptraux->ptrSig = nuevo;
    }
}

void funciones(struct Dato *ptr){
    int op;
    int valor, contador
    struct Dato *ptraux;
    do{
        op=menuFunciones();

        switch (op){
        case 1: //Buscar
            printf("ingresa el valor a buscar");
            
            break;
        case 2://Contar
            contador = 0;
            ptraux = ptr;
            while(ptraux !=NULL){
                contador ++;
                ptraux = ptraux-> ptrsig;
            }
            printf("El total de nodos existentes es de: %d", contador);
            break;
            case 3:
                printf("Regresando ....\n");
        default:
            printf("Opcion ivalida wey >:(");
            break;
        }
    }while(op !=3);
}

void mostrarDato(struct Dato *ptr){ 
    struct Dato *ptraux;

    if(ptr == NULL){
        printf("Lista vacia\n");
        return;
    }

    ptraux = ptr;
    
    while(ptraux != NULL){
        printf("%d -> ", ptraux->d);
        ptraux = ptraux->ptrSig;
    }
    printf("NULL\n");
}


void liberarDato(struct Dato **ptr) {
    struct Dato *ptraux;
    struct Dato *anterior;

    if (*ptr == NULL) {
        printf("Lista vacia\n");
        return;
    }

    if ((*ptr)->ptrSig == NULL) {
        free(*ptr);
        *ptr = NULL;
        printf("Se elimino el unico nodo\n");
        return;
    }

    ptraux = *ptr;

    while (ptraux->ptrSig != NULL) {
        anterior = ptraux;
        ptraux = ptraux->ptrSig;
    }

    anterior->ptrSig = NULL;
    free(ptraux);

    printf("Se elimino el ultimo nodo\n");
}

// Liberar toda la lista
void Salir(struct Dato **ptr){
    struct Dato *ptraux;

    while(*ptr != NULL){
        ptraux = *ptr;
        *ptr = (*ptr)->ptrSig;
        free(ptraux);
    }

    printf("Lista liberada\n");
}