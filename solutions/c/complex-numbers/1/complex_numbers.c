#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
   complex_t result;
   result.imag = a.imag+b.imag;
   result.real =a.real+b.real;
   return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t result;
   result.imag = a.imag-b.imag;
   result.real =a.real-b.real;
   return result;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t result;
   result.imag = (a.imag*b.real)+(a.real*b.imag);
   result.real =(a.real*b.real)-(a.imag*b.imag);
   return result;
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t result;
   result.imag = ((a.imag*b.real) - (a.real*b.imag)) / (pow(b.real,2) + pow(b.imag,2));
   result.real = ((a.real*b.real) + (a.imag*b.imag)) / (pow(b.real,2) + pow(b.imag,2));
   return result;
}

double c_abs(complex_t x)
{
   double result;
   result = sqrt(pow(x.imag,2)+pow(x.real,2));
   return result;
}

complex_t c_conjugate(complex_t x)
{
   complex_t result;
   result.imag = -x.imag;
   result.real = x.real;
   return result;
}

double c_real(complex_t x)
{
   double result;
   result = x.real;
   return result;
}

double c_imag(complex_t x)
{
   double result;
   result = x.imag;
   return result;
}

complex_t c_exp(complex_t x)
{
   complex_t result;
   result.imag = exp(x.real)*sin(x.imag); 
   result.real = exp(x.real)*cos(x.imag); 

   return result;
}
