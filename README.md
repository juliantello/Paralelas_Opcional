Opcional Paralelas
para ejecutar cada codigo se debe ejecutar cada uno de los siguientes comandos
para la version secuencial:
gcc secuencial.c -o secuencial
time ./secuencial
para la version pthread:
gcc pthreads.c -pthread -o pthreads
time ./pthreads
para la version omp static:
gcc ompstatic.c -fopenmp -o ompstatic
time ./ompstatic
para la version omp dynamic:
gcc ompdynamic.c -fopenmp -o ompdynamic
time ./ompdynamic

Ademas se debe tener en cuenta que para cambiar el numero de hilos se debe modificar la siguiente linea:
#define NUM_THREADS 8
donde 8 es el numero de hilos que vamos a usar al ejecutar el programa
