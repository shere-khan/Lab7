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
    // Go through each input case.
    for (loop = 0; loop < numCases; loop++) {

        // Get this input grid.
        for (i = 0; i < ROWS; i++)
            for (j = 0; j < COLS; j++) {
                fscanf(ifp, "%d", &grid[i][j]);
            }

        // Will store best value for row or column.
        best = 0;

        for (j = 0; j < COLS; j++) {
            int col_tot = 0;
            for (i = 0; i < ROWS; i++)
                col_tot += grid[i][j];

            if (col_tot > best)
                best = col_tot;
        }
        for (i = 0; i < ROWS; i++) {
            int row_tot = 0;
            for (j = 0; j < COLS; j++)
                row_tot += grid[i][j];

            if (row_tot > best)
                best = row_tot;
        }

        // Output result.
        printf("%d\n", best);
    }

    fclose(ifp);
    return 0;
}