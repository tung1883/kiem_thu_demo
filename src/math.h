#ifndef MATH_H_
#define MATH_H_

#include <stdio.h>

// Basic arithmetic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Mathematical operations
double factorial(int n);
double squareRoot(double x);
double power(double base, double exponent);
double absoluteValue(double x);
double roundToNearestInteger(double x);
double maximum(double a, double b);
double minimum(double a, double b);
double sine(double x);
double cosine(double x);
double tangent(double x);
double exponential(double x);
double naturalLogarithm(double x);
double absoluteDifference(double a, double b);

// Complex number operations
typedef struct
{
    double real;
    double imag;
} Complex;

Complex complex_add(Complex a, Complex b);
Complex complex_subtract(Complex a, Complex b);
Complex complex_multiply(Complex a, Complex b);
Complex complex_divide(Complex a, Complex b);
Complex complex_conjugate(Complex z);
double complex_abs(Complex z);

// Advanced number theory algorithms
int gcd(int a, int b);
void extended_gcd(int a, int b, int *x, int *y);
int modular_exponentiation(int base, int exponent, int modulus);
int modular_inverse(int a, int m);
void prime_factors(int n);
int euler_totient(int n);
int chinese_remainder(int *num, int *rem, int len);

// Function prototypes for common mathematical functions
double square(double x);
double cube(double x);
double sine(double x);
double cosine(double x);
double exponential(double x);

// Function prototypes for integral functions
double integrateSquare(double a, double b, int n);
double integrateCube(double a, double b, int n);
double integrateSine(double a, double b, int n);
double integrateCosine(double a, double b, int n);
double integrateExponential(double a, double b, int n);

#endif /* MATH_H_ */
