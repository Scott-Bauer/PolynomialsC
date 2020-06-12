#ifndef POLY_H
# define POLY_H
// helper file to assure proper interaction in main
int evaluatePolynomial(int);
void displayPolynomial();
int addPolyTerm(int,int);
struct PolyTerm {
int coeff ;
int expo ;
struct PolyTerm *next ;
};

#endif
