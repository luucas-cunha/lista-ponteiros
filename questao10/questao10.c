#include <stdio.h>

int main() {
    int i;

    //Representando o vetor do tipo char
    char x[4];

    printf("char \n");
    for(i = 0; i < 4; i++) {
        printf("%X ", x+i);
    }
    printf("\n\n");

    //Representando o vetor do tipo int
    int y[4];

    printf("int \n");
    for(i = 0; i < 4; i++) {
        printf("%X ", y+i);
    }
    printf("\n\n");

    //Representando o vetor do tipo float
    float z[4];

    printf("float \n");
    for(i = 0; i < 4; i++) {
        printf("%X ", z+i);
    }
    printf("\n\n");

    //Representando o vetor do tipo double
    double w[4];

    printf("double \n");
    for(i = 0; i < 4; i++) {
        printf("%X ", w+i);
    }
    printf("\n");

    return 0;
}
