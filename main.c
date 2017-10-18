// Arup Guha
// 8/17/2015
// Scaffold to fill in for COP 3223 Common Lab - Marketing (2D arrays)

// Modified by Sarah Angell
// 10/08/2015
// Modified to remove issues for compilers without C99 enabled

#include <stdio.h>

#define ROWS 20
#define COLS 5

int main() {
    // Open the input file and read in the number of cases to process.
    FILE *ifp = fopen("marketing.txt", "r");
    int loop, numCases, best, cur;
    int grid[ROWS][COLS], i, j;
    fscanf(ifp, "%d", &numCases);
    printf("numcases: %d\n", numCases);
    // Go through each input case.
    for (loop = 0; loop < numCases; loop++) {

        // Get this input grid.
        for (i = 0; i < ROWS; i++)
            for (j = 0; j < COLS; j++)
                fscanf(ifp, "%d", &grid[i][j]);

        // Will store best value for row or column.
        best = 0;

        /*** FILL IN CODE HERE, TO UPDATE BEST, AS NEEDED. ***/
        int best_values[6] = {0, 0, 0, 0, 0, 0};

        int col_tot = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                col_tot += grid[i][j];
            }

            if (col_tot > best_values[0]) {
                printf("col_tot: %d\n", col_tot);
                best_values[0] = col_tot;
            }

            col_tot = 0;

            best_values[1] += grid[i][0];
            best_values[2] += grid[i][1];
            best_values[3] += grid[i][2];
            best_values[4] += grid[i][3];
            best_values[5] += grid[i][4];
        }

        best = best_values[0];
        //printf("value in array: %d\n", best_values[0]);
        best_values[0] = 0;
        for (int k = 1; k < 6; k++) {
            //printf("value in array: %d\n", best_values[1]);
            if (best_values[k] > best) {
                best = best_values[k];
            }
            best_values[k] = 0;
        }

        // Output result.
        //printf("%d\n", best);
    }

    fclose(ifp);
    return 0;
}