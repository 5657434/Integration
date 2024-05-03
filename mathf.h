/*! @file mathf.h
    @brief library of functions for computing integrals
    @author Paolo Gastaldo

    details.
*/

#ifndef MATHF_H
#define MATHF_H

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

double Polynomial(double* coeff, int size, double in);
void Rectangular(double* values, int size, double stepsize, double* integ1, double* integ2);
double Trapezoidal(double* values, int size, double stepsize);

#endif

