#include "math.h"
#include <math.h>

// Basic arithmetic operations
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return 0; // Return 0 on division by zero
    }
    return a / b;
}

// Mathematical operations
double factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

double squareRoot(double x)
{
    if (x < 0)
    {
        printf("Error: Cannot calculate square root of a negative number.\n");
        return -1.0; // Return -1 to indicate error
    }
    else
    {
        return sqrt(x);
    }
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double absoluteValue(double x)
{
    return fabs(x);
}

double roundToNearestInteger(double x)
{
    return round(x);
}

double maximum(double a, double b)
{
    return fmax(a, b);
}

double minimum(double a, double b)
{
    return fmin(a, b);
}

double sine(double x)
{
    return sin(x);
}

double cosine(double x)
{
    return cos(x);
}

double tangent(double x)
{
    return tan(x);
}

double exponential(double x)
{
    return exp(x);
}

double naturalLogarithm(double x)
{
    if (x <= 0)
    {
        printf("Error: Natural logarithm is only defined for positive numbers.\n");
        return -1.0; // Return -1 to indicate error
    }
    else
    {
        return log(x);
    }
}

double absoluteDifference(double a, double b)
{
    return fabs(a - b);
}

// Complex number operations
Complex complex_add(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complex_subtract(Complex a, Complex b)
{
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex complex_multiply(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex complex_divide(Complex a, Complex b)
{
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

Complex complex_conjugate(Complex z)
{
    Complex result;
    result.real = z.real;
    result.imag = -z.imag;
    return result;
}

double complex_abs(Complex z)
{
    return sqrt(z.real * z.real + z.imag * z.imag);
}

// Advanced number theory algorithms
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void extended_gcd(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return;
    }
    int x1, y1;
    extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
}

int modular_exponentiation(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int modular_inverse(int a, int m)
{
    int x, y;
    extended_gcd(a, m, &x, &y);
    return (x % m + m) % m;
}

void prime_factors(int n)
{
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }
    if (n > 2)
        printf("%d ", n);
}

int euler_totient(int n)
{
    int result = n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int chinese_remainder(int *num, int *rem, int len)
{
    int prod = 1;
    for (int i = 0; i < len; ++i)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < len; ++i)
    {
        int pp = prod / num[i];
        result += rem[i] * modular_inverse(pp, num[i]) * pp;
    }
    return result % prod;
}

double integrateSquare(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (pow(a, 2) + pow(b, 2));
    for (int i = 1; i < n; i++)
    {
        sum += pow(a + i * h, 2);
    }
    return h * sum;
}

double integrateCube(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (pow(a, 3) + pow(b, 3));
    for (int i = 1; i < n; i++)
    {
        sum += pow(a + i * h, 3);
    }
    return h * sum;
}

double integrateSine(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (sine(a) + sine(b));
    for (int i = 1; i < n; i++)
    {
        sum += sine(a + i * h);
    }
    return h * sum;
}

double integrateCosine(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (cosine(a) + cosine(b));
    for (int i = 1; i < n; i++)
    {
        sum += cosine(a + i * h);
    }
    return h * sum;
}

double integrateExponential(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (exponential(a) + exponential(b));
    for (int i = 1; i < n; i++)
    {
        sum += exponential(a + i * h);
    }
    return h * sum;
}