/*
* Program to evaluate polynomial expressions
** Author       Dept.      Date         Notes ***************************
* Scotty Bauer  Comp. Sci  April 3 2020  Initial Version
* Scotty Bauer  Comp. Sci  April 5 2020  Modified addPolyTerm to add the new node in the correct position
* Scotty Bauer  Comp. Sci  April 8 2020  Added error handling in addPolyTerm, and handled what to do if exponents are equal
* Scotty Bauer  Comp. Sci  April 9 2020  Fixed Merging coefficients error when the merge occurs at the head of the list
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
struct PolyTerm {
int coeff ;
int expo ;
struct PolyTerm *next ;
};
struct PolyTerm *head;

//helper method createNode to improve readability of the code
struct PolyTerm* createNode(int coef, int ex){
	struct PolyTerm *create = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
//checks to see if malloc returns null, indicating an out of memory error
	if(create == NULL){
		puts("Out of memory error, unable to add term");
		exit -1;
	}
	create->next=NULL;
	create->coeff=coef;
	create->expo=ex;
	return create;
}
int addPolyTerm(int x, int n){
	int count = 0;
	int temp = 0;
	struct PolyTerm *new = createNode(x,n);
//sets new as head if list is empty or the current head as a larger exponent
	if(head==NULL || head->expo > new->expo){
		new->next = head;
              	head = new;
		return 0;
        }
	struct PolyTerm *track  = head;
//traverses list to find position of the new term to assure proper ordering
	while(track != NULL){             
		if(track->expo > n){
			break;
		}
// else if to handle merging term with equal exponents
		else if(track->expo == n) {
			int merge = track->coeff;
			temp = merge + x;
			track->coeff = temp;
			return 0;
		}
		else{	count++;
			track = track->next;
		}
	}
	struct PolyTerm *track2 = head;
	int pos = 1;
//use dummy term to traverse again to set track2 as the term directly before where the new term needs to be added
	while (pos !=  count && track2->next != NULL){
		track2=track2->next;
		pos++;
	}
	new->next = track2->next;
	track2->next = new;
	return 0;

}
//prints head term, then traverses list printing a + if coeff is positive
void displayPolynomial(){
	int count =0;
	printf("%dx%d", head->coeff, head->expo);
	struct PolyTerm *ptr = head->next;
	while(ptr != NULL){
		if(ptr->coeff >= 0){
			printf("%c",'+');
		}
	printf("%dx%d", ptr->coeff, ptr->expo);
	ptr= ptr->next;
	

}
puts("");
}
int evaluatePolynomial(int z){
	struct PolyTerm *ptr = head;
	int result = 0;
//uses powi during traversal to evaluate polynomial
	while(ptr != NULL){
		result += powi(z, ptr->expo)* ptr->coeff;
		ptr = ptr->next;
	}
	return (result);
}
