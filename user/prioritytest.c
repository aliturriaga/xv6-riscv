#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    int i;
    for (i = 0; i < 20; i++) {
        if (fork() == 0) {
            sleep(i * 10);  // Espacia la ejecución para evitar solapamientos
            printf("Ejecutando proceso %d\n", i + 1);
            sleep(10);  // Pausa para demostrar la ejecución de cada proceso
            exit(0);    // Salida correcta del proceso hijo
        }
    }
    for (i = 0; i < 20; i++) {
        wait(0);  // Espera a que todos los procesos hijos terminen
    }
    exit(0);      // Salida correcta del proceso padre
}
