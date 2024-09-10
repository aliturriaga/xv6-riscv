# Informe de Implementación de la Llamada al Sistema `getppid()` en xv6

## Funcionamiento de la Llamada al Sistema

### `getppid()`

**Descripción**: La llamada al sistema `getppid()` permite a un proceso obtener el ID del proceso padre que lo creó. Esta funcionalidad es útil para la gestión de procesos y para que los procesos puedan identificar su jerarquía.

**Implementación**:
- **Archivo**: `kernel/sysproc.c`
- **Función**:
  uint64 sys_getppid(void)
  {
      return myproc()->parent->pid;
  }
Uso en el Programa de Prueba:

En el programa de prueba yosoytupadre.c, se llama a getppid() para obtener y mostrar el ID del proceso padre.
Explicación de las Modificaciones Realizadas
Modificación de sysproc.c:

Se implementó la función sys_getppid() para que retorne el ID del proceso padre del proceso actual.
La implementación accede al proceso actual mediante myproc() y retorna el PID del proceso padre.
Modificación de syscall.h:

Se agregó la declaración de la nueva llamada al sistema:

uint64 sys_getppid(void);
Modificación de syscall.c:

Se añadió la llamada al sistema en la tabla syscalls:

[SYS_getppid] sys_getppid,
Modificación de user.h:

Se agregó la declaración de la llamada al sistema para su uso en el espacio de usuario:

int getppid(void);
Creación del Programa de Prueba:

Se creó yosoytupadre.c en la carpeta user para probar la llamada al sistema getppid().
Contenido de yosoytupadre.c:


#include "types.h"
#include "user.h"

int main(void)
{
    int ppid;
    
    ppid = getppid();
    printf(1, "PPID: %d\n", ppid);
    exit();
}
Dificultades Encontradas y Cómo se Resolvían
Errores de Tipos en la Declaración y Definición:

Problema: Hubo errores debido a tipos incompatibles en la declaración y definición de la función sys_getppid().
Solución: Se aseguró que la declaración y la definición coincidieran en el tipo de retorno y los parámetros, utilizando uint64 en ambos lugares.
Errores de Inclusión en el Programa de Prueba:

Problema: El programa de prueba yosoytupadre.c no encontraba la definición de getppid().
Solución: Se verificó que la función getppid() estuviera correctamente declarada en user.h y se incluyeron los encabezados necesarios en el programa de prueba.
