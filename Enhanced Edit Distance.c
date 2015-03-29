/*
 ============================================================================
 Name        : Enhanced.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Change these strings to test the program
#define STRING_X "nintendo"
#define STRING_Y "northen"


inline
int min(int a, int b) {
   return a < b ? a : b;
}

// Returns Minimum among a, b, c
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}


int EditDistanceDP(char X[], char Y[])
{
    // Cost of alignment
    int cost = 0, diff;
    int i, j;
    int leftCell, topCell, cornerCell;

    int m = strlen(X)+1;
    int n = strlen(Y)+1;

    // T[m][n]
    int *T = (int *)malloc((m+2) * sizeof(int));

    // Set up base cases
    // T[i][0] = i
    for( i = 0; i < m; i++)
        *(T + i) = i;

    // T[0][j] = j
        *(T + m) = 1;

    // Build the T in top-down fashion
    for( j = 0; j < n-1; j++)
    {
        for( i = 0; i < m-1; i++)
        {
            // T[i-1][j-1]
            cornerCell = *T;

            // T[i][j-1]
            leftCell = *(T + 1); // deletion

            // T[i-1][j]
            topCell = *(T + m); // insertion

            // edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
            diff= (X[i] != Y[j]); // may be replace

            // Minimum cost of current cell
            // Fill in the next cell T[i][j]
            *(T + m+1) = cost = Minimum(leftCell + 1, topCell + 1, cornerCell + diff);
            //Pointer move
            T = (T+1);
        }
        T = (T+1);
        *(T + m) = j+2;
    }

    return cost;
}



int main()
{
    char X[] = STRING_X; // vertical
    char Y[] = STRING_Y; // horizontal

    printf("Minimum edits required to convert %s into %s is %d\n",
           X, Y, EditDistanceDP(X, Y) );

    return 0;
}

