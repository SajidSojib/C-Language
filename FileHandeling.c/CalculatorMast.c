#include <stdio.h>
#include <math.h>

void displayMenu()
{
    printf("\n*** Calculator Menu ***\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus (Integers only)\n");
    printf("6. Power (x^y)\n");
    printf("7. Square Root\n");
    printf("8. Logarithm (Base 10)\n");
    printf("9. Natural Logarithm (ln)\n");
    printf("10. Sine (degrees)\n");
    printf("11. Cosine (degrees)\n");
    printf("12. Tangent (degrees)\n");
    printf("13. Factorial\n");
    printf("0. Exit\n");
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int choice;
    double num1, num2, result;
    int intNum;

    do
    {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Addition
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2: // Subtraction
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3: // Multiplication
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4: // Division
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0)
            {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5: // Modulus
            printf("Enter two integers: ");
            int intNum1, intNum2;
            scanf("%d %d", &intNum1, &intNum2);
            if (intNum2 != 0)
            {
                printf("Result: %d\n", intNum1 % intNum2);
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 6: // Power
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 7: // Square Root
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 >= 0)
            {
                result = sqrt(num1);
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Square root of a negative number is not real.\n");
            }
            break;
        case 8: // Logarithm (Base 10)
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 > 0)
            {
                result = log10(num1);
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Logarithm of non-positive numbers is undefined.\n");
            }
            break;
        case 9: // Natural Logarithm (ln)
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 > 0)
            {
                result = log(num1);
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Logarithm of non-positive numbers is undefined.\n");
            }
            break;
        case 10: // Sine
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180);
            printf("Result: %.2lf\n", result);
            break;
        case 11: // Cosine
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180);
            printf("Result: %.2lf\n", result);
            break;
        case 12: // Tangent
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * M_PI / 180);
            printf("Result: %.2lf\n", result);
            break;
        case 13: // Factorial
            printf("Enter a non-negative integer: ");
            scanf("%d", &intNum);
            if (intNum >= 0)
            {
                printf("Result: %d\n", factorial(intNum));
            }
            else
            {
                printf("Error: Factorial of a negative number is not defined.\n");
            }
            break;
        case 0: // Exit
            printf("Exiting the calculator. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
