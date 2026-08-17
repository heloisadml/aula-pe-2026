#include <stdio.h>

int main() {
    int num;

    printf("Type a number: ");
    scanf("%d", &num);

    if (num >= 0) {
        printf("This number is positive.\n");
    } else {
        printf("This number is negative.\n");
    }
    return 0;
}
