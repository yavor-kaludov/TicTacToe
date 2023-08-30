#include <stdio.h>
#include <unistd.h>

void print_processing_animation() { // prints 3 dots in succession

    printf("Processing");
    fflush(stdout);  // Flush the output buffer
    printf(".");
    fflush(stdout);  // Flush the output buffer
    usleep(800000);
    printf(".");
    fflush(stdout);  // Flush the output buffer
    usleep(800000);
    printf(".\n");
    fflush(stdout);  // Flush the output buffer
    usleep(800000);
    
}