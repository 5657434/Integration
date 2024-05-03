/*! @file mathf.c
	@brief definition of functions
	@author Paolo Gastaldo

	details.
*/

#include "mathf.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


/*! \brief computes the output value of a polynomial
	\param coeff coefficients of the polynomial (pointer to)
	\param size length of the coeff array
	\param in the input value
	\return the output value

	the polynomial is structured as follows: coeff[0] + coeff[1]*x + ....
*/
double Polynomial(double* coeff, int size, double in) {

	int i; 				/* counter for loops */
	double out = 0.;		/* used as accumulator to compute the value of the function given an input */
	double x = in;		/* to represent the different elements of the polynomial (x, x^2, x^3,...) */

	out = coeff[0];
	for (i = 1; i < size; i++) {
		out += coeff[i] * x;
		x *= in;			/* x^i */
	}

	return out;

}


/*! \brief numerical integration according to the rectangular rule
	\param values points that set the equally spaced intervals (pointer to)
	\param size length of the values array
	\param stepsize the interval between two points
	\param integ1 integral computed using as reference the first point of each interval
	\param integ2 integral computed using as reference the second point of each interval
*/
void Rectangular(double* values, int size, double stepsize, double* integ1, double* integ2) {

	int i; 	/* counter for loops */

	(*integ1) = 0.;
	(*integ2) = 0.;

	(*integ1) += stepsize * values[0];
	for (i = 1; i < (size - 1); i++) {
		(*integ1) += stepsize * values[i];
		(*integ2) += stepsize * values[i];
	}
	(*integ2) += stepsize * values[i];

	return;
}

/*! \brief numerical integration according to the trapezoidal rule
	\param values points that set the equally spaced intervals (pointer to)
	\param size length of the values array
	\param stepsize the interval between two points
	\return the computed integral
*/
double Trapezoidal(double* values, int size, double stepsize) {

	int i; 		/* counter for loops */

	double integ = 0.; 		/* used as accumulator to compute the integral */
	double h = stepsize / 2.;	/* to avoid dividing by 2 at each round of the loop */

	for (i = 0; i < (size - 1); i++)
		integ += h * (values[i + 1] + values[i]);

	return integ;
}