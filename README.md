
# Sistema de Prioridades en xv6

## Funcionamiento y Lógica del Sistema de Prioridades

El sistema de prioridades implementado en xv6 permite que cada proceso sea ejecutado de acuerdo a un valor de prioridad que es ajustado dinámicamente por un campo llamado `boost`. 

- La **prioridad** de un proceso se inicializa en 0, que es la prioridad más alta (un número menor implica mayor prioridad). 
- El **boost** del proceso se inicializa en 1 y determina cómo se ajusta la prioridad de cada proceso.

### Lógica de Actualización:
- Cada vez que un proceso es programado para ser ejecutado, su prioridad se incrementa en función de su boost (`prioridad += boost`).
- Si la prioridad de un proceso alcanza el valor de 9, el boost cambia a -1 para reducir la prioridad.
- Si la prioridad de un proceso llega a 0, el boost vuelve a ser 1, incrementando nuevamente su prioridad en ejecuciones subsecuentes.

De esta manera, el sistema evita que los procesos con alta prioridad se ejecuten continuamente sin darle oportunidad a otros procesos. El boost actúa como un mecanismo para balancear la ejecución de los procesos en función del tiempo que han estado esperando.

## Explicación de las Modificaciones Realizadas

- **Estructura del proceso**: 
  Se agregaron dos nuevos campos en la estructura de proceso de xv6:
  - `int prioridad`: Almacena la prioridad actual del proceso.
  - `int boost`: Controla cómo se incrementa o decrementa la prioridad del proceso.

- **Algoritmo de Programación**:
  Se implementó la lógica que ajusta la prioridad de cada proceso de acuerdo con su boost:
  - Cuando un proceso es ejecutado, su prioridad se actualiza usando la fórmula `prioridad += boost`.
  - Si la prioridad alcanza 9, se invierte el valor del boost a -1 para reducir la prioridad del proceso.
  - Si la prioridad llega a 0, el boost se establece en 1 nuevamente.

- **Ajustes en la Función de Programación**: Se modificaron las funciones de programación de procesos para tener en cuenta el nuevo campo de prioridad y ejecutar los procesos en el orden correcto basado en su prioridad actual.

## Dificultades Encontradas y Soluciones Implementadas

Una de las principales dificultades fue ajustar el sistema de prioridades sin afectar el rendimiento global del sistema. Al modificar la lógica de programación, era importante evitar un comportamiento indeseado en el que algunos procesos quedaran "atrapados" con prioridad baja y nunca llegaran a ejecutarse.

### Soluciones Implementadas:
- **Balanceo Dinámico de Prioridades**: La introducción del campo boost y la lógica que ajusta su valor de acuerdo a la prioridad del proceso permite un balance dinámico que evita el monopolio de la CPU por procesos con baja prioridad.
- **Pruebas Exhaustivas**: Se creó el programa `prioritytest.c` para generar 20 procesos y verificar que el sistema gestiona correctamente la ejecución de procesos en función de sus prioridades, asegurando que todos los procesos sean programados en el orden adecuado y que se observe el comportamiento del boost en la práctica.

## Conclusión

El sistema de prioridades implementado asegura que los procesos con mayor prioridad sean ejecutados antes, mientras que el boost permite un ajuste dinámico para evitar que un proceso monopolice la CPU indefinidamente. El programa de prueba demuestra que el sistema funciona correctamente, y se observaron mejoras en el control del tiempo de ejecución de los procesos.
