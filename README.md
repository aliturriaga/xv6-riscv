# Protección de Memoria en xv6

## Objetivo

Implementar un sistema de protección de memoria en xv6 que permita marcar regiones de memoria como solo lectura mediante la función `mprotect` y revertir esa protección con `munprotect`. Este sistema permite controlar los permisos de memoria en regiones específicas para impedir o permitir la escritura en ellas.

## Funcionamiento de `mprotect` y `munprotect`

- **`mprotect(void *addr, int len)`**:
  - Marca una región de memoria, comenzando en `addr` y con longitud `len` en páginas, como solo lectura.
  - Modifica el bit de escritura (`PTE_W`) en la tabla de páginas, deshabilitándolo para cada página en el rango, lo cual bloquea la escritura.

- **`munprotect(void *addr, int len)`**:
  - Rehabilita el permiso de escritura para una región de memoria previamente protegida.
  - Activa el bit de escritura (`PTE_W`) para permitir tanto lectura como escritura en la región de memoria especificada.

Ambas funciones verifican que las direcciones de memoria sean válidas y que las páginas estén presentes en la tabla de páginas del proceso.

## Modificaciones Realizadas

1. **Implementación en `vm.c`**:
   - Se añadieron `mprotect` y `munprotect`, que recorren cada página en el rango especificado y ajustan el bit de escritura en la tabla de páginas utilizando `walk`.

2. **Definición de Syscalls**:
   - Se asignaron números de syscall en `syscall.h` como `#define SYS_mprotect 22` y `#define SYS_munprotect 23`.
   - En `syscall.c`, se registraron `sys_mprotect` y `sys_munprotect` en el arreglo de syscalls.

3. **Declaraciones en `user.h` y Entradas en `usys.pl`**:
   - Se declararon `mprotect` y `munprotect` en `user.h` para el uso en programas de usuario.
   - En `usys.pl`, se añadieron `entry("mprotect")` y `entry("munprotect")`.

4. **Definición de las Funciones en `sysproc.c`**:
   - Se añadieron `sys_mprotect` y `sys_munprotect` para redirigir las llamadas del usuario a las funciones definidas en `vm.c`.

5. **Modificación en el `Makefile`**:
   - Se añadió `memprotecttest` a la lista de programas de usuario `UPROGS` en el `Makefile` para que esté disponible para pruebas.

6. **Programa de Prueba `memprotecttest.c`**:
   - Se creó `memprotecttest.c` para validar la funcionalidad:
     - Reserva una página de memoria.
     - Llama a `mprotect` para protegerla y luego intenta escribir en ella.
     - Llama a `munprotect` para desproteger la página y vuelve a escribir en ella, verificando que los permisos se restauraron.

Estas modificaciones permiten un mayor control sobre los permisos de memoria en xv6, mejorando la seguridad en el manejo de memoria de los procesos.
