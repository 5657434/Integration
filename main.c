/** \file main.c
	\brief Numeric integration of a polynomial
	\author Paolo Gastaldo

	first version of this software; all the functions are in this file
*/

/*! \mainpage
 *
 * \section intro_sec Introduction
 *
 * This is a software in C language for calculating numerical integration by adopting different techniques
 *
 * \section install_sec Installation
 *
 *
 *
 * etc...
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "mathf.h"

int main() {

	/* setting all the parameters */
	double fcoeff[4] = { -10.0,1.0,0.0,2.0 };	/* the polynomial */
	double xmin = 0.0; 						/* the integration range */
	double xmax = 5.0;
	int intervals = 100000000; 					/* number of equally spaced intervals */


	double integ1, integ2;

	int i;
	double in = xmin;
	double gap = (xmax - xmin) / (double)intervals;
	double* fvalues = NULL;

	/* this array will store the (steps+1) values of the polynomial that are delimiting the equally spaced intervals*/
	fvalues = (double*)malloc(sizeof(double) * (intervals + 1));
	if (fvalues == NULL) {
		printf("\nERROR: cannot allocate memory\n");
		exit(-1);
	}

	/* to get the value of the polynomial at the different points that are delimiting the intervals */
	for (i = 0; i <= intervals; i++) {
		fvalues[i] = Polynomial(fcoeff, 4, in);
		in += gap;
	}

	integ1 = 0.;
	integ2 = 0.;

	/* to compute the integral according to the rectangular rule */
	Rectangular(fvalues, intervals + 1, gap, &integ1, &integ2);
	printf("\nRectangular rule - The integral between %f and %f is in the interval: [%f,%f]\n", xmin, xmax, integ1, integ2);

	/* to compute the integral according to the trapezoidal rule */
	integ1 = Trapezoidal(fvalues, intervals + 1, gap);
	printf("\nTrapezoidal rule - The integral between %f and %f is : %f\n", xmin, xmax, integ1);

	/* deallocation */
	if (fvalues != NULL)
		free(fvalues);

	return 0;
}