#include <stdio.h>

#define QUANTIDADE_LOOP 10

int main() {
    for (int i = 1; i <= QUANTIDADE_LOOP; i++) {
        
        if (i % 2 == 0) {
            
            printf("%d", i);
        
            if (i < QUANTIDADE_LOOP) {
            printf(", ");
            } else {
                printf(".");
            }
        }
        
        
    }

    printf("\n"); // só pq tenho toque

    return 0;
}