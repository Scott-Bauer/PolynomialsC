/*
* Program to assist polyapp.c in evaluating  polynomial expressions
** Author       Dept.      Date         Notes ***************************
* Scotty Bauer  Comp. Sci  April 3 2020  Initial Version
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse (char *string, int *x, int *y){
//set two temps to the integers from the file using sscanf
	int temp1;
	int temp2;
	sscanf(string, "%d %d", &temp1, &temp2);
//dereference x and y and set to temp values
	*x = temp1;
	*y = temp2;

}
int powi (int a, int b){
		int result=1;
		while (b > 0){
			result *= a;
			b--;
		}
		return result;
}
