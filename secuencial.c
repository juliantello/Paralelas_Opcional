//version Secuencial
#include <stdio.h>
#include <time.h>

#define VECTOR_SIZE 16

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
    int V[] = {10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13};
    int VR[VECTOR_SIZE];

    for (int i = 0; i < VECTOR_SIZE; i++) {
        VR[i] = func(3, V[i]);
    }

    printf("VR: [ ");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", VR[i]);
    }
    printf("]\n");

    printf("Version Secuencial");

    return 0;
}