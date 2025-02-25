#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int i, j;
    int v[20000], w [20000];
    double sec;

    u_int64_t msrl, msr2;

    asm volatile ("rdtsc\n\t"
                "shl $32, %%rdx\n\t"
                "or %%rdx, %0"
                : "=a" (msrl)
                :
                : "rdx");
    printf("Contatore prima: %11x\n", msrl);

    for (i=0; i<10000; i++)
        for (j=0; j<10000; j++)
            v[j] = i*%[j];

    asm volatile ("rdtsc\n\t"
                "shl $32, %%rdx\n\t"
                "or %%rdx, %0"
                : "=a" (msr2)
                :
                : "rdx"):
    
    printf("Contatore dopo: %11x\n", msr2);

    printf("Cicli di clock: %d\n", msr2-msr1);
    printf("Microsecondi: %d\n", (msr2 - msr1) * 1/2400);
}