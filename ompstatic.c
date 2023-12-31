//version omp
#include <stdio.h>
#include <omp.h>
#include <time.h>

#define VECTOR_SIZE 16
#define NUM_THREADS 8

int V[] = {10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13};
int VR[VECTOR_SIZE];

int func(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return func(m - 1, 1);
    } else {
        return func(m - 1, func(m, n - 1));
    }
}

int main() {
    int i;

    #pragma omp parallel num_threads(NUM_THREADS) shared(V, VR) private(i)
    {
        #pragma omp for schedule(static)
        for (i = 0; i < VECTOR_SIZE; i++) {
            int result = func(3, V[i]);
            VR[i] = result;
        }
    }

    printf("VR: [ ");
    for (i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", VR[i]);
    }
    printf("]\n");
    
    printf("Version OpenMP con %d Hilos usando scheduling estático", NUM_THREADS);
    return 0;
}