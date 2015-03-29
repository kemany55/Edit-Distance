/*
 ============================================================================
 Name        : edit.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STRING_X "asdasdgfds"
#define STRING_Y "boqewqte"


int min(int a, int b) {
   return a < b ? a : b;
}
int Minimum(int a, int b, int c){
    return min(min(a, b), c);
}

int main(void) {
	char first_string[]=STRING_X;
	char second_string[]=STRING_Y;
	int edit = 1, keep = 0;
	int len1 = strlen(first_string);
	int len2 = strlen(second_string);
	int l = len1*len2;
	int diff , c, i, o=0, a=0, b=0;

	//printf("length of second_string is %d\n", len2);

	//arrays initialization
	int arrA[3]; arrA[0]=0;arrA[1]=arrA[2]=1;arrA[3]=0;
	int arrB[3]; arrB[0]=0;arrB[1]=arrB[2]=1;arrB[3]=0;
	static int arrC[4];
	//printf("destination of arrA  %d\n ", &arrC);
	//printf("Those are the initial 3 arrays  \n");
	/*for (i=0; i<4; i++){
							printf("%d\t", arrA[i]);
						} printf("\n");
						for (i=0; i<4; i++){
											printf("%d\t", arrB[i]);
										} printf("\n");
										for (i=0; i<len2+2; i++){
															printf("%d\t", arrC[i]);
														} printf("\n\n");*/
	//Each round represent a cell in the 2D matrix and its calculations

	for (c=0; c<l; c++){
		//printf("this is round %d\n", c);

		// string comparison
		if (first_string[a]==second_string[b]){
			diff=keep;
		} else {
			diff=edit;
		} b++; // second string increment

		//printf("the difference between the 2 characters is %d\n", diff);

		if (c<len2){
			//Initializing the first row array: arrB
			if (c==0){
			arrB[3] = Minimum(arrB[0]+diff, arrB[1]+1, arrB[2]+1);
			arrB[0] +=1;
			arrB[2] +=1;
			arrB[1] = arrB[3];
			}

			// first column in the matrix
			arrA[3] = Minimum(arrA[0]+diff, arrA[1]+1, arrA[2]+1);
			arrC[o] = arrA[3]; o++;
			arrA[0] +=1;
		    arrA[1] +=1;
		    arrA[2] = arrA[3];

		    if (c==len2-1){
		    	b=0;a++;
		    }

		} else if (c%len2==0){ // first row in the matrix
			arrB[3] = Minimum(arrB[0]+diff, arrB[1]+1, arrB[2]+1);

			arrB[0] +=1;
			arrB[2] +=1;
		    arrB[1] = arrB[3];
		    arrC[len2]=arrB[3];


		} else if (c == len2+1){ // element to begin the third array
			arrC[len2+1] = Minimum(arrC[0]+diff, arrC[1]+1, arrC[len2]+1);
			for ( i=0; i<len2+1; i++){
										arrC[i] = arrC[i+1];
									}


		} else if ((c+1)%len2==0 && c>len2-1 && c<l-1) { //last row minus first and last elements
			arrC[len2+1] = Minimum(arrC[0]+diff, arrC[1]+1, arrC[len2]+1);
			for ( i=0; i<len2+1; i++){
							arrC[i] = arrC[i+2];
			}

			b=0;a++;
		} else { //rest of the matrix
			arrC[len2+1] = Minimum(arrC[0]+diff, arrC[1]+1, arrC[len2]+1);
			for ( i=0; i<len2+1; i++){
							arrC[i] = arrC[i+1];
						}

		}
		/*if (c<l-1){
		for (i=0; i<4; i++){
								printf("%d\t", arrA[i]);
							} printf("\n");
							for (i=0; i<4; i++){
												printf("%d\t", arrB[i]);
											} printf("\n");
											for (i=0; i<len2+2; i++){
																printf("%d\t", arrC[i]);
															} printf("\n\n");}*/

	}
	char X[] = STRING_X; // vertical
	char Y[] = STRING_Y; // horizontal
	printf("Minimum edits from %s into %s is ", X, Y);

	printf("%d\n\n", arrC[len2+1]);

	return 0;
}


