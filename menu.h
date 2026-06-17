#include <stdio.h>

int menuPrincipal(void);

int menuPrincipal(void){
    int opcion;
    printf("\n----Menu----\n");
    printf("1. Ingresar usuario\n");
    printf("2. Buscar usuario\n");
    printf("3. Mostrar usuarios\n");
    printf("4. Eliminar usuario\n");
    printf("Opcion: ");

    scanf("d", &opcion);

    return opcion;
}