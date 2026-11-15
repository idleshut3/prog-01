#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// A program which generates Pascal's triangle. The size is based on the user provided arg when executing the program.
// The main purpose of this exercise was to explore double pointers and dynamic memory allocation.
// The input validation section was an afterthought, so don't rely on it. 

int r, n;

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("You must enter the number of rows in Pascal's triangle to print. Try again...\n");
        return 1;
    }
    
	// Declare the number of rows you want to calculate
    size_t rows = 0;
    if (atoi(argv[1]) < SIZE_MAX && atoi(argv[1]) > 0) {
	    rows = atoi(argv[1]);
    } else {
        return 1;
    }

	// pointer to an 'array' of pointers, which becomes our first index
	size_t **pnums = malloc(rows * sizeof(size_t *));


	// for each pointer in the 'array' of pointers, allocate memory based on its index + 1. This becomes our second index
	for(r = 0; r < rows; r++) {
		pnums[r] = malloc((r + 1) * sizeof(size_t));

		// now we calculate the int(s) that will go in each row
        int seed_val = 1;
		for(n = 0; n <= r; n++) {
            pnums[r][n] = seed_val;
            seed_val = seed_val * (r - n) / (n + 1);
		}
	}

    // Print the output
	for(r = 0; r < rows; r++) {
		for(n = 0; n <= r; n++) {
			printf(" %zu ", pnums[r][n]);
        }
    printf("\n");
	}

	// free each row's memory
	for(r = 0; r < rows; r++) {
		free(pnums[r]);
	}

	// free the top level double pointer
	free(pnums);

	return 0;
}
