#include <stdio.h>
#include <time.h>

struct Alumno{
    char nombre[100];
    int calif[5][5];
};

int main(){
    struct Alumno A[5];
    srand(time(NULL));
    
    for(int k = 0; k < 5; k++){
        printf("\nIngrese el nombre del estudiante %d: ", k+1);
        fgets(A[k].nombre, sizeof(A[k].nombre), stdin);

        for(int j = 0; j < 5; j++){
            for(int i = 0; i < 5; i++){
                A[k].calif[j][i] = rand()%5 + 6;
            }
        }
    }

    printf("\nlista de alumnos\n");

    for(int k = 0; k < 5; k++){
        printf("\nAlumno %d: %s", k+1, A[k].nombre);

        printf("Calificaciones:\n");
        for(int j = 0; j < 5; j++){
            for(int i = 0; i < 5; i++){
                printf("%d ", A[k].calif[j][i]);
            }
            printf("\n");
        }
    }

    return 0;
}

  
 