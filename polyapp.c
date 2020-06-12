/*
* Program to evaluate polynomial expressions
** Author       Dept.      Date         Notes ***************************
* Scotty Bauer	Comp. Sci  April 3 2020  Initial Version
* Scotty Bauer  Comp. Sci  April 8 2020  Added the number array to evaluate polynomial in a loop
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "poly.h"
int main (int argc, char *argv[]){
	FILE *ptr;
	char *text= malloc(50);
	int x;
	int coef;
	ptr = fopen(argv[1], "r");
//loop to replace newline with end of string and call parse and addPolyTerm
	while (fgets(text, 50, ptr) != NULL) {
		if (text[strlen(text)-1] == '\n'){
			text[strlen(text)-1] = '\0';
		}
// pass by reference to parse in utils.c
	parse(text, &x, &coef);
	addPolyTerm(x,coef);
	
	}
	fclose(ptr);
	displayPolynomial();

//for loop through array of required x values to evaluate 
	int numbers[5] = {-2, -1, 0,1,2};
	for (int i = 0; i<5; i++){
		int result = evaluatePolynomial(numbers[i]);
		printf("for x=%d, y=%d \n", numbers[i],result);
	}
return 0;
}
