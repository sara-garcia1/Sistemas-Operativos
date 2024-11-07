CONCURRENCIA EXPLÍCITA:
El programador especifica el comportamiento concurrente.
○ Contienen pasos de procesamiento independientes (a nivel de bloque, sentencia o nivel de expresión) que
pueden ejecutarse en paralelo;
○ Desencadenan operaciones de dispositivos que pueden proceder en paralelo con la ejecución del
programa.
La concurrencia explícita ocurre cuando el programador gestiona y coordina manualmente la ejecución concurrente de tareas, incluyendo 
la sincronización de hilos.
n la concurrencia explícita, el control de la ejecución paralela es responsabilidad del programador, quien decide cómo y cuándo dividir el
trabajo en tareas concurrentes, y se asegura de que las tareas se sincronicen correctamente.

CONCURRENCIA IMPLÍCITA
El sistema o lenguaje maneja la concurrencia automáticamente, sin intervención explícita del programador.

PROPGRAMA CONCURRENTE:
Un programa concurrente define acciones que pueden ser ejecutadas simultáneamente
PROGRAMA PARALELO:
● Un programa paralelo es un programa concurrente que está diseñado para ser ejecutado en hardware
paralelo
PROGRAMA DISTRIBUIDO:
● Un programa distribuido es un programa paralelo diseñado para ser ejecutado sobre una red de
procesadores autónomos que no comparten memoria principal (a nivel hardware).

THREAD:
Vista desde SO
○ Flujo de instrucciones independiente que es planificado y ejecutado por
el SO
● Vista desde el desarrollador de software
○ Un
thread puede ser considerado como un
‘procedimiento’ que se
ejecuta independiente del programa principal.
■ Programa secuencial
● Un único flujo de instrucciones en un programa
■ Programa Multi-
thread
● Un programa con múltiples flujos
● Multiple threads usan multiple cores/CPUs
Técnicamente, un hilo es definido como un flujo de instrucciones
independiente del programa principal, que es planificado y ejecutado por
el sistema operativo. But what does this mean?
● Para el desarrollador de software, el concepto de un "procedimiento" que se ejecuta
independientemente de su programa principal puede describir mejor un hilo.
● Para ir un paso más allá, imagine un programa principal (a.out) que contiene una
cantidad de procedimientos. Luego, imagine que todos estos procedimientos pueden
programarse para que se ejecuten simultáneamente y/o de forma independiente por parte del
sistema operativo. Eso describiría un programa "multihilo".
Existe con los procesos
● Muere si el proceso muere
● Usa los recursos del proceso
● Duplica solo los recursos esenciales para que el SO los
planifique independientemente.
Cada hilo mantiene
■ Pila
■ Registros
■ Propiedades de programación (p. ej., prioridad)
■ Conjunto de señales pendientes y bloqueadas (para permitir que diferentes reaccionen
de manera diferente a las señales)
■ Datos específicos del hilo
En resumen, en un entorno UNIX un thread:
○ Existe dentro de un proceso y usa los recursos del proceso.
○ Tiene su propio flujo de control independiente siempre que exista su proceso padre
y el SO lo soporte.
○ Duplica sólo los recursos esenciales que necesita para ser planificado de forma
independiente.
○ Puede compartir los recursos con otros threads que actúan igualmente
independientes (y dependientes).
○ Muere si el proceso padre muere - o algo similar
○ Es “ligero” porque la mayor parte del overhead ya se ha realizado mediante la
creación del proceso.
● Porque los hilos dentro del mismo proceso comparten recursos:
○ Los cambios realizados por un thread en los recursos compartidos en el sistema
(ejemplo: cierre de un fichero) serán vistos por todos los demás threads.
○ Dos punteros con el mismo valor apuntan a los mismos datos.
○ Es posible leer y escribir en las mismas ubicaciones de memoria y, por lo tanto,
requiere sincronización explícita por parte del programador.
Estado compartido
○ Las variables globales se comparten entre los threads. Cambios
accidentales pueden ser fatales.
● Muchas funciones de la library no son seguras para los threads
○ Funciones de la Library que devuelven punteros a la memoria
interna estática. E.g. gethostbyname()
● Falta de robustez
○ Una falla en un hilo provocará una falla en todo el proceso.

RESUMEN THREADS:
Un thread es la unidad más pequeña de ejecución en un proceso. Todos los hilos de un proceso comparten el mismo espacio de memoria, 
lo que permite que colaboren y compartan datos sin necesidad de mecanismos complejos de comunicación entre procesos.
Los hilos permiten dividir el trabajo de un proceso en partes concurrentes, mejorando la eficiencia y la velocidad de ciertos programas
al aprovechar múltiples núcleos de CPU.

PTHREADS:
Pthreads se definen como un conjunto de tipos de programación
y llamadas a procedimientos en lenguaje C, implementados con
la interfaz #include <pthread.h> a una
library de
threads.
Comunicaciones eficientes/intercambio de datos:
○ La motivación principal para considerar el uso de pthreads en un entorno de HPC es
lograr un rendimiento óptimo. En particular, si una aplicación está usando MPI para
comunicaciones en el nodo, existe la posibilidad de que el rendimiento pueda ser
mejorado usando pthreads en su lugar.
○ Las bibliotecas MPI suelen implementar la comunicación de tareas en el nodo a
través de la memoria compartida, lo que implica al menos una operación de copia en
memoria (proceso a proceso).
○ En el caso de los pthreads no se requiere una copia de memoria intermedia porque
los hilos comparten el mismo espacio de direcciones dentro de un solo proceso. No
hay transferencia de datos en sí. Puede ser tan eficiente como simplemente pasar
un puntero.
○ En el peor de los casos, las comunicaciones de los pthreads se convierten más en un
problema de ancho de banda de caché a CPU o de memoria a CPU. Estas
velocidades son mucho más altas que las comunicaciones de memoria compartida
MPI.
Las aplicaciones que usen pthreads ofrecen mayor ganancia de rendimiento y ventajas
prácticas sobre las aplicaciones sin pthreads:
○ Trabajo solapado CPU con E/S
■ Ej.: un programa puede tener secciones en las que realiza operaciones de E/S
prolongadas. Mientras un pthread espera la completitud de la llamada E/S, los
demás pthreads hacen uso del CPU.
○ Prioridad/Planificación en tiempo real
■ Las tareas más importantes pueden ser planificadas para sustituir o interrumpir
las tareas con menor prioridad.
○ Manejo de eventos asincrónicos:
■ Las tareas que dan servicio a eventos de frecuencia y duración indeterminadas
pueden ser intercaladas. Ej.: un servidor web puede transferir datos de peticiones
anteriores, en tanto gestiona la llegada de nuevas peticiones.
■ Ejemplo perfecto es un navegador web: múltiples tareas intercaladas pueden
estar ejecutándose al mismo tiempo, cada tarea puede variar en prioridad.
Gestión de pthreads: Rutinas que trabajan directamente en los hilos: crear, separar,
unir, etc. También incluyen funciones para establecer/consultar los atributos de los
hilos (unirse, programar, etc.)
● Mutexes: Rutinas que se ocupan de la sincronización, denominadas "mutex", que es
una abreviatura de "exclusión mutua". Las funciones mutex permiten crear, destruir,
bloquear y desbloquear los mutex. Éstas se complementan con funciones de
atributo mutex que establecen o modifican los atributos asociados a los mutex.
● Variables de condición: Rutinas que dirigen las comunicaciones entre los hilos que
comparten un mutex. Basadas en condiciones especificadas por el programador.
Este grupo incluye funciones para crear, destruir, esperar y señalar basadas en
valores de variables especificadas. También se incluyen funciones para
establecer/consultar los atributos de las variables de condición.
● Sincronización: Rutinas que gestionan los bloqueos y barreras de lectura/escritura.
RESUMEN PTHREADS:
Pthreads es una biblioteca de hilos basada en el estándar POSIX
Esta biblioteca define una API estándar en C para manejar hilos. Puedes crear, sincronizar y finalizar hilos usando funciones específicas de pthreads, 
como pthread_create, pthread_join, pthread_mutex_lock, entre otras.
requiere una gestión manual cuidadosa para evitar problemas.

REQUERIMIENTOS PARA ESCOGER SISTEMA DE CÓMPUTO:
-RAM: permite cargar más datos en memoria, mejorando el rendimiento, la capacidad y la latencia.
-CPU: procesa instrucciones rapidamente, aumentando la velocidad.
-CACHE: mejora tamaño y velocidad
  -L1: mejora el rendimiento de tareas que se quieren procesar frecuentemente.
  -L2: procesa datos comunes
  -L3: mejora rendimiento de grandes cantidades de datos.
-GPU: cores

NAMED PIPES:
es un tipo de canal de comunicación en sistemas operativos (especialmente en UNIX y Linux) que permite la comunicación entre procesos, 
pero a diferencia de un pipe regular, se identifica con un nombre en el sistema de archivos. Esto significa que los procesos que necesitan 
comunicarse no tienen que ser relacionados o iniciados al mismo tiempo, ya que el named pipe existe en el sistema de archivos y 
puede ser accedido cuando se necesite.
Puedes ser bidireccionales.
PIPES:
Normalmente son unidireccionales, lo que significa que solo permiten que los datos fluyan en una dirección: de un proceso escritor a un proceso lector. 
Para comunicación bidireccional, suelen requerirse dos pipes.

CLIENTE/SERVIDOR:
Cliente: El cliente es una aplicación o dispositivo que inicia una solicitud para acceder a un recurso o servicio alojado en un servidor.
Los clientes pueden ser computadoras personales, dispositivos móviles, navegadores web, etc. Su papel es solicitar datos o servicios y, 
a menudo, presentar el resultado al usuario final.

Servidor: El servidor es el sistema o programa que almacena y gestiona los recursos o servicios y los proporciona a los clientes que lo soliciten.
Los servidores están siempre disponibles para responder a las solicitudes de los clientes, ejecutando las tareas necesarias y devolviendo los resultados.
