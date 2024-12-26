

#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>


int	f_sum(int a, int b);

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int f_sum(int a, int b);

int main(void) {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    int a;
    int b;
    int sum;

    a = 4;
    b = 5;

    // Introduce a memory leak by allocating memory and not freeing it
    int *leaked_memory = (int *)malloc(sizeof(int));
    *leaked_memory = 42; // Example use of the memory

    sum = f_sum(a, b);
    printf("The sum is %i\n", sum);

    // Memory leak happens because we don't free 'leaked_memory'
    return 0; // Memory leaks will be reported here
}

int f_sum(int a, int b) {
    return (a + b);
}

/*
int	main(void) {
	// Allocate memory for an integer array
	int *leak = (int *)malloc(10 * sizeof(int));

	// Intentionally not freeing the memory
	// free(leak);  // This should be called to prevent a memory leak

	printf("Memory allocated but not freed.\n");

	return (0);
}
*/