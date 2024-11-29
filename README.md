# Informe Tarea 4

## Descripción

En esta tarea se implementó un sistema de gestión de permisos para archivos en un sistema operativo basado en xv6. Se añadió un campo de permisos en los inodos, se implementó la llamada al sistema `chmod` para modificar dichos permisos y se realizaron pruebas para asegurar el correcto funcionamiento de estas funcionalidades.

## Implementación

1. **Archivo de Pruebas**
   - Se creó el archivo `perm_test.c` y se agregó al `Makefile` para permitir su compilación y ejecución durante las pruebas.

2. **Modificación de la Estructura de Inodos**
   - Se observó la estructura de inodos en `file.h` y se añadió el campo `permissions` para gestionar los modos asignados a los archivos.

3. **Llamada al Sistema `chmod`**
   - Se implementó la lógica para cambiar los permisos de los archivos a través de la llamada al sistema `chmod`.
   - La lógica se incluyó en `sysfile.c`, donde se gestionan los permisos predeterminados y el comportamiento del sistema según los valores de permisos. Por ejemplo, no se permite escribir en archivos de solo lectura.

4. **Definición de la Llamada al Sistema**
   - En `syscall.h` se definió la llamada `#define SYS_chmod 24`.
   - En `user.h`, se agregó la declaración `int chmod(const char*, int);`, donde el primer argumento es el archivo y el segundo es el modo que se asigna.
   - En `syscall.c`, se definió la función `extern uint64 sys_chmod(void);` y se vinculó con `SYS_chmod`.
   - En `usys.pl`, se añadió la entrada `entry("chmod");` para hacer accesible la llamada al espacio de usuario.

5. **Pruebas**
   - Se añadieron pruebas en `perm_test.c` para validar el comportamiento del sistema con respecto a los permisos. Se verificaron diferentes casos de uso para asegurarse de que las reglas de permisos se respetaran correctamente.

## Dificultades Encontradas y Soluciones Implementadas

1. **Gestión de permisos en inodos**
   - **Dificultad**: La estructura de inodos no incluía un campo para permisos.
   - **Solución**: Se añadió un campo `permissions` en `file.h` y se ajustó la lógica en `sysfile.c` para manejar los permisos.

2. **Restricciones según permisos**
   - **Dificultad**: Impedir operaciones no permitidas según los permisos (como escribir en archivos de solo lectura).
   - **Solución**: Se añadió lógica en `sysfile.c` para verificar permisos antes de realizar operaciones en los archivos.

3. **Implementación de la llamada al sistema `chmod`**
   - **Dificultad**: Definir y vincular correctamente la nueva llamada `chmod`.
   - **Solución**: Se definió la llamada en `syscall.h`, `syscall.c`, y se actualizó `usys.pl` para su uso en el espacio de usuario.

4. **Pruebas y validación**
   - **Dificultad**: Asegurar que las modificaciones no afectaran otras partes del sistema.
   - **Solución**: Se crearon pruebas en `perm_test.c` para verificar que los permisos se asignaran y respetaran correctamente.

---

## Instrucciones de Compilación

1. Para compilar el proyecto, use el comando `make` en la raíz del proyecto.
2. Para ejecutar las pruebas, utilice el comando correspondiente para ejecutar el archivo `perm_test.c`.

---

## Conclusión

La tarea permitió implementar un sistema de gestión de permisos robusto que respeta las reglas definidas en los inodos. Las pruebas realizadas confirmaron que las funcionalidades de `chmod` y las restricciones de permisos funcionan correctamente.
