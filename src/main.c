#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "math.h"

void print_menu()
{
    printf("===================================================================================================================================================================\n");
    printf("| Arithmetic Operations | Trigonometric Functions | Exponential Functions | Numeric Algorithms         | Integral Functions          | Complex Functions          |\n");
    printf("===================================================================================================================================================================\n");
    printf("| 1 . Addition          | 12. Sine                | 15. Exponential       | 17. Absolute Difference    | 24. Integral of Square      | 29. Complex Addition       |\n");
    printf("| 2 . Subtraction       | 13. Cosine              | 16. Logarithm         | 18. GCD                    | 25. Integral of Cube        | 30. Complex Subtraction    |\n");
    printf("| 3 . Multiplication    | 14. Tangent             |                       | 19. Modular Exponentiation | 26. Integral of Sine        | 31. Complex Multiplication |\n");
    printf("| 4 . Division          |                         |                       | 20. Modular Inverse        | 27. Integral of Cosine      | 32. Complex Division       |\n");
    printf("| 5 . Factorial         |                         |                       | 21. Prime Factors          | 28. Integral of Exponential | 33. Complex Conjugate      |\n");
    printf("| 6 . Square Root       |                         |                       | 22. Euler's Totient        |                             | 34. Complex Absolute       |\n");
    printf("| 7 . Power             |                         |                       | 23. Chinese Remainder      |                             | 35. Get Previous History   |\n");
    printf("| 8 . Absolute Value    |                         |                       |                            |                             |                            |\n");
    printf("| 9 . Nearest Integer   |                         |                       |                            |                             |                            |\n");
    printf("| 10. Maximum           |                         |                       |                            |                             |                            |\n");
    printf("| 11. Minimum           |                         |                       |                            |                             |                            |\n");
    printf("===================================================================================================================================================================\n");
}

// void display_cache_file()
// {
//     FILE *file = fopen("./src/cache.txt", "r");
//     if (file == NULL)
//     {
//         fprintf(stderr, "Error opening file: cache.txt\n");
//         return;
//     }

//     char c;
//     while ((c = fgetc(file)) != EOF)
//     {
//         putchar(c);
//     }
// }

int main()
{
    int choice;
    double num1, num2, result;
    int num, a, b, modulus;
    char option[3]; // Change option to an array of characters to accommodate two-character inputs
    Complex complex1, complex2, complexResult;
    bool running = true;
    bool listPrinted = false;

    FILE *file = fopen("./src/cache.txt", "a"); // Open file in append mode

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: cache.txt\n");
        return 1;
    }

    while (running)
    {
        if (!listPrinted)
        {
            print_menu();
            listPrinted = true;
        }

        printf("Enter your choice (1-23) or 'q' to quit, 'l' to show the list: ");
        scanf("%2s", option); // Read user's choice as a string with maximum length 2

        if (option[0] == 'q' || option[0] == 'Q')
        {
            printf("Exiting...\n");
            running = false;
        }
        else if (option[0] == 'l' || option[0] == 'L')
        {
            listPrinted = false;
        }
        else
        {
            choice = atoi(option); // Convert the string option to an integer

            switch (choice)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("4.Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = 0;
                
                if (choice == 1)
                    result = add(num1, num2);
                else if (choice == 2)
                    result = subtract(num1, num2);
                else if (choice == 3)
                    result = multiply(num1, num2);
                else if (choice == 4)
                    result = divide(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = factorial(num);
                printf("Result: %.2lf\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 7:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 8:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = absoluteValue(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 9:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = roundToNearestInteger(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 10:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = maximum(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 11:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = minimum(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 12:
                printf("Enter a number (in radians): ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 13:
                printf("Enter a number (in radians): ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 14:
                printf("Enter a number (in radians): ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 15:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = exponential(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 16:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = naturalLogarithm(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 17:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = absoluteDifference(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 18:
                printf("18. Enter two numbers: ");
                scanf("%d %d", &a, &b);
                result = gcd(a, b);
                printf("Result: %.2lf\n", result);

                break;
            case 19:
                printf("Enter base, exponent, and modulus: ");
                scanf("%d %d %d", &a, &b, &modulus);
                result = modular_exponentiation(a, b, modulus);
                printf("Result: %.2lf\n", result);

                break;
            case 20:
                printf("Enter number and modulus: ");
                scanf("%d %d", &a, &modulus);
                result = modular_inverse(a, modulus);
                printf("Result: %.2lf\n", result);

                break;
            case 21:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Prime factors: ");
                prime_factors(num);
                printf("\n");
                break;
            case 22:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = euler_totient(num);
                printf("Result: %.2lf\n", result);

                break;
            case 23:
            {
                printf("Enter the number of congruences: ");
                scanf("%d", &num);
                if (num > 0)
                {
                    int nums[100], rems[100];
                    printf("Enter the modulus and remainders for each congruence:\n");
                    for (int i = 0; i < num; i++)
                    {
                        printf("Modulus and remainder for congruence %d: ", i + 1);
                        scanf("%d %d", &nums[i], &rems[i]);
                    }
                    result = chinese_remainder(nums, rems, num);
                    printf("Result: %.2lf\n", result);
                }
                else
                {
                    printf("Invalid number of congruences\n");
                }
                break;
            }
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
                printf("Enter lower bound, upper bound, and number of intervals: ");
                scanf("%lf %lf %d", &num1, &num2, &num);
                result = 0;
                if (choice == 24)
                    result = integrateSquare(num1, num2, num);
                else if (choice == 25)
                    result = integrateCube(num1, num2, num);
                else if (choice == 26)
                    result = integrateSine(num1, num2, num);
                else if (choice == 27)
                    result = integrateCosine(num1, num2, num);
                else if (choice == 28)
                    result = integrateExponential(num1, num2, num);
                printf("Result: %.2lf\n", result);
                break;
            case 29:
                printf("Enter real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &complex1.real, &complex1.imag);
                printf("Enter real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &complex2.real, &complex2.imag);
                complexResult = complex_add(complex1, complex2);
                printf("Result: %.2lf + %.2lfi\n", complexResult.real, complexResult.imag);
                break;
            case 30:
                printf("Enter real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &complex1.real, &complex1.imag);
                printf("Enter real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &complex2.real, &complex2.imag);
                complexResult = complex_subtract(complex1, complex2);
                printf("Result: %.2lf + %.2lfi\n", complexResult.real, complexResult.imag);
                break;
            case 31:
                printf("Enter real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &complex1.real, &complex1.imag);
                printf("Enter real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &complex2.real, &complex2.imag);
                complexResult = complex_multiply(complex1, complex2);
                printf("Result: %.2lf + %.2lfi\n", complexResult.real, complexResult.imag);
                break;
            case 32:
                printf("Enter real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &complex1.real, &complex1.imag);
                printf("Enter real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &complex2.real, &complex2.imag);
                complexResult = complex_divide(complex1, complex2);
                printf("Result: %.2lf + %.2lfi\n", complexResult.real, complexResult.imag);
                break;
            case 33:
                printf("Enter real and imaginary parts of the complex number: ");
                scanf("%lf %lf", &complex1.real, &complex1.imag);
                complexResult = complex_conjugate(complex1);
                printf("Result: %.2lf + %.2lfi\n", complexResult.real, complexResult.imag);
                break;
            case 34:
                printf("Enter real and imaginary parts of the complex number: ");
                scanf("%lf %lf", &complex1.real, &complex1.imag);
                result = complex_abs(complex1);
                printf("Result: %.2lf\n", result);
                break;
            // case 35:
            //     display_cache_file();
            //     break;
            default:
                printf("Invalid choice\n");
            }

            // if (choice >= 1 && choice <= 34) {
            //     fprintf(file, "Choice: %d\n", choice);
            //     fprintf(file, "Result: %.2lf\n", result);
            //     fprintf(file, "---------------------\n");
            //     fflush(file); // Flush buffer to ensure data is written immediately
            // }
        }
    }

    return 0;
}